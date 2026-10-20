"""A Gazebo torque controller with the command shape of a DM-J4310 MIT motor.

Gazebo supplies joint position and velocity.  The requested MIT torque is applied
through Gazebo's ApplyJointForce system; torque feedback is the quantized applied
motor torque estimate, not a force / torque sensor measurement.
"""

import math
import os
from pathlib import Path
import re
import xml.etree.ElementTree as ET

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64

from four_axis_arm_interfaces.msg import EncoderState, MitCommand, MotorState
from four_axis_arm_interfaces.srv import SetEncoderZero


JOINT_LIMITS = {
    'joint1': (-math.pi, math.pi),
    'joint2': (-2.8, 0.8),
    'joint3': (-2.6, 2.6),
    'joint4': (-2.8, 2.8),
}
START_POSE = {'joint1': 0.0, 'joint2': -0.65, 'joint3': 0.85, 'joint4': 0.30}
URDF_PATH = Path('/home/yezi/ROS2/four_axis_arm.urdf')
GEAR_RATIO = 10.0
P_MAX = 12.5             # DM4310 SDK MIT mapping range, rad
V_MAX = 30.0             # DM4310 SDK MIT mapping range, rad/s
T_MAX = 10.0             # DM4310 SDK MIT mapping range, N m
PEAK_TORQUE = 7.0       # DM-J4310-2EC V1.1 mechanical peak, N m
NO_LOAD_SPEED = 200.0 * 2.0 * math.pi / 60.0  # rpm -> rad/s
UPDATE_PERIOD = 0.005   # 200 Hz
MOTOR_TIME_CONSTANT = 0.015  # approximate torque response, seconds


def clamp(value, low, high):
    return max(low, min(high, value))


def quantize(value, low, high, bits):
    steps = (1 << bits) - 1
    raw = round((clamp(value, low, high) - low) * steps / (high - low))
    return low + raw * (high - low) / steps


def load_zero_offsets():
    try:
        root = ET.fromstring(URDF_PATH.read_text())
        calibration = root.find('encoder_zero')
        if calibration is None:
            raise ValueError('URDF has no encoder_zero element')
        values = {name: float(calibration.attrib[name]) for name in JOINT_LIMITS}
        if not all(math.isfinite(values[name]) and low <= values[name] <= high
                   for name, (low, high) in JOINT_LIMITS.items()):
            raise ValueError('URDF encoder zero is outside joint limits')
        return values
    except (OSError, ValueError, KeyError, ET.ParseError) as exc:
        raise RuntimeError(f'Could not load encoder zero from {URDF_PATH}: {exc}') from exc


def save_zero_offsets(values):
    source = URDF_PATH.read_text()
    replacement = ('<encoder_zero ' + ' '.join(
        f'{name}="{values[name]:.12f}"' for name in JOINT_LIMITS) + '/>')
    updated, count = re.subn(r'<encoder_zero\b[^>]*/>', replacement, source)
    if count != 1:
        raise ValueError(f'Expected one encoder_zero element, found {count}')
    ET.fromstring(updated)
    temporary = URDF_PATH.with_suffix('.urdf.tmp')
    temporary.write_text(updated)
    os.replace(temporary, URDF_PATH)


class Motor:
    def __init__(self):
        self.q = None
        self.dq = 0.0
        self.acceleration = 0.0
        self.last_stamp = None
        self.desired_q = 0.0
        self.desired_dq = 0.0
        self.kp = 50.0
        self.kd = 2.0
        self.tau_ff = 0.0
        self.enabled = True
        self.applied_tau = 0.0
        self.target_tau = 0.0
        self.saturated = False


class MitController(Node):
    def __init__(self):
        super().__init__('dm4310_mit_sim')
        self.zero_offsets = load_zero_offsets()
        self.motors = {name: Motor() for name in JOINT_LIMITS}
        for name, (kp, kd) in {
            'joint1': (20.0, 1.0),
            'joint2': (50.0, 2.0),
            'joint3': (25.0, 1.5),
            'joint4': (10.0, 0.5),
        }.items():
            self.motors[name].kp = kp
            self.motors[name].kd = kd
        self.raw_stamp = None
        self.raw_frame = ''
        self.state_pub = self.create_publisher(MotorState, '/arm/motor_state', 20)
        self.encoder_pub = self.create_publisher(EncoderState, '/arm/encoder_state', 20)
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 20)
        self.calibrated_joint_pub = self.create_publisher(
            JointState, '/arm/joint_states_calibrated', 20)
        self.torque_pubs = {
            name: self.create_publisher(
                Float64, f'/model/four_axis_arm/joint/{name}/cmd_force', 20
            ) for name in JOINT_LIMITS
        }
        self.create_subscription(JointState, '/arm/joint_states_raw', self.on_joint_state, 20)
        self.create_subscription(MitCommand, '/arm/mit_command', self.on_command, 20)
        self.create_service(SetEncoderZero, '/arm/set_encoder_zero', self.on_set_zero)
        self.tick = 0
        self.create_timer(UPDATE_PERIOD, self.step)

    def on_joint_state(self, msg):
        stamp = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        self.raw_stamp = msg.header.stamp
        self.raw_frame = msg.header.frame_id
        positions = dict(zip(msg.name, msg.position))
        velocities = dict(zip(msg.name, msg.velocity))
        for name, motor in self.motors.items():
            if name not in positions or name not in velocities:
                continue
            q = positions[name]
            dq = velocities[name]
            if motor.q is None:
                motor.desired_q = START_POSE[name]
            if motor.last_stamp is not None:
                dt = stamp - motor.last_stamp
                if 0.0005 <= dt <= 0.1:
                    raw_acceleration = clamp((dq - motor.dq) / dt, -200.0, 200.0)
                    motor.acceleration = 0.2 * raw_acceleration + 0.8 * motor.acceleration
            motor.q = q
            motor.dq = dq
            motor.last_stamp = stamp

    def on_set_zero(self, request, response):
        if request.joint_name == 'all' and request.use_current_position:
            names = list(JOINT_LIMITS)
        elif request.joint_name in JOINT_LIMITS:
            names = [request.joint_name]
        else:
            response.message = 'joint_name must be joint1..joint4, or all with use_current_position=true'
            return response
        if request.use_current_position:
            if any(self.motors[name].q is None for name in names):
                response.message = 'Joint state is not ready'
                return response
            positions = {name: self.motors[name].q for name in names}
        else:
            positions = {request.joint_name: request.raw_zero_position}
        if not all(math.isfinite(position) and
                   JOINT_LIMITS[name][0] <= position <= JOINT_LIMITS[name][1]
                   for name, position in positions.items()):
            response.message = 'Raw zero position is outside the joint limits'
            return response
        updated = dict(self.zero_offsets)
        updated.update(positions)
        try:
            save_zero_offsets(updated)
        except (OSError, ValueError, ET.ParseError) as exc:
            response.message = f'Could not save encoder zero in URDF: {exc}'
            self.get_logger().error(response.message)
            return response
        self.zero_offsets = updated
        response.success = True
        response.zero_offset = updated[request.joint_name] if len(names) == 1 else 0.0
        response.message = f'Saved encoder zero for {", ".join(names)} in {URDF_PATH}'
        self.get_logger().info(response.message)
        return response

    def on_command(self, msg):
        motor = self.motors.get(msg.joint_name)
        if motor is None:
            self.get_logger().warn(f'Unknown joint: {msg.joint_name}')
            return
        values = (msg.position_des, msg.velocity_des, msg.kp, msg.kd, msg.torque_ff)
        if not all(math.isfinite(value) for value in values):
            self.get_logger().warn('Ignoring non-finite MIT command')
            return
        low, high = JOINT_LIMITS[msg.joint_name]
        motor.desired_q = clamp(
            self.zero_offsets[msg.joint_name]
            + quantize(msg.position_des, -P_MAX, P_MAX, 16), low, high)
        motor.desired_dq = quantize(msg.velocity_des, -V_MAX, V_MAX, 12)
        motor.kp = quantize(msg.kp, 0.0, 500.0, 12)
        motor.kd = quantize(msg.kd, 0.0, 5.0, 12)
        motor.tau_ff = quantize(msg.torque_ff, -T_MAX, T_MAX, 12)
        motor.enabled = msg.enable

    def step(self):
        if self.raw_stamp is None:
            return
        for name, motor in self.motors.items():
            if motor.q is None:
                continue
            raw_tau = (
                motor.kp * (motor.desired_q - motor.q)
                + motor.kd * (motor.desired_dq - motor.dq)
                + motor.tau_ff
            ) if motor.enabled else 0.0
            # Approximate the reduction in available output torque at high speed.
            speed_factor = clamp(1.0 - abs(motor.dq) / NO_LOAD_SPEED, 0.0, 1.0)
            limit = PEAK_TORQUE * speed_factor
            motor.target_tau = clamp(raw_tau, -limit, limit)
            motor.saturated = abs(raw_tau) > limit + 1e-9
            response = min(1.0, UPDATE_PERIOD / MOTOR_TIME_CONSTANT)
            motor.applied_tau += response * (motor.target_tau - motor.applied_tau)
            self.torque_pubs[name].publish(Float64(data=motor.applied_tau))

        self.tick += 1
        if self.tick % 4 == 0:
            self.publish_feedback()

    def publish_feedback(self):
        joint_state = JointState()
        joint_state.header.stamp = self.raw_stamp
        joint_state.header.frame_id = self.raw_frame
        calibrated_state = JointState()
        calibrated_state.header = joint_state.header
        for name, motor in self.motors.items():
            if motor.q is None:
                continue
            torque_estimate = quantize(motor.applied_tau, -T_MAX, T_MAX, 12)
            joint_state.name.append(name)
            joint_state.position.append(motor.q)
            joint_state.velocity.append(motor.dq)
            joint_state.effort.append(torque_estimate)
            calibrated_angle = motor.q - self.zero_offsets[name]
            calibrated_state.name.append(name)
            calibrated_state.position.append(calibrated_angle)
            calibrated_state.velocity.append(motor.dq)
            calibrated_state.effort.append(torque_estimate)
            state = MotorState()
            state.header = joint_state.header
            state.joint_name = name
            state.position = calibrated_angle
            state.velocity = motor.dq
            state.acceleration = motor.acceleration
            state.torque_estimate = torque_estimate
            state.commanded_torque = motor.target_tau
            state.enabled = motor.enabled
            state.saturated = motor.saturated
            self.state_pub.publish(state)
            encoder = EncoderState()
            encoder.header = joint_state.header
            encoder.joint_name = name
            encoder.motor_encoder_rad = (motor.q * GEAR_RATIO) % (2.0 * math.pi)
            encoder.output_encoder_rad = motor.q % (2.0 * math.pi)
            encoder.zero_offset_rad = self.zero_offsets[name]
            encoder.calibrated_angle_rad = calibrated_angle
            self.encoder_pub.publish(encoder)
        self.joint_pub.publish(joint_state)
        self.calibrated_joint_pub.publish(calibrated_state)


def main():
    rclpy.init()
    node = MitController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            for pub in node.torque_pubs.values():
                pub.publish(Float64(data=0.0))
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
