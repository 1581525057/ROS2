#!/usr/bin/env python3
"""DM-J4310-style MIT controller for the Gazebo arm (no CAN hardware access).

The command fields follow the MIT position / velocity / Kp / Kd / torque format.
This node computes a joint torque and sends it to Gazebo's ApplyJointForce
system. Motor torque feedback is an estimate of our command, not a sensor.
"""

import math
from pathlib import Path
import xml.etree.ElementTree as ET

from ament_index_python.packages import get_package_share_directory
from four_axis_arm_interfaces.msg import MitCommand, MotorState
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64


JOINT_LIMITS = {
    'joint1': (-math.pi, math.pi),
    'joint2': (-2.8, 0.8),
    'joint3': (-2.6, 2.6),
    'joint4': (-2.8, 2.8),
}
DEFAULT_GAINS = {
    'joint1': (20.0, 1.0),
    'joint2': (50.0, 2.0),
    'joint3': (25.0, 1.5),
    'joint4': (10.0, 0.5),
}

# These protocol ranges must match the real drive's configuration if hardware
# is added later. The manual permits P_MAX, V_MAX and T_MAX to be configured.
P_MAX = 12.5                 # rad, MIT position field (16 bit)
V_MAX = 30.0                 # rad/s, MIT velocity field (12 bit)
T_MAX = 10.0                 # N m, MIT feedforward / feedback field (12 bit)
KP_MAX = 500.0               # MIT Kp field (12 bit)
KD_MAX = 5.0                 # MIT Kd field (12 bit)
PEAK_TORQUE = 7.0            # N m, DM-J4310-2EC output peak
NO_LOAD_SPEED = 200.0 * 2.0 * math.pi / 60.0  # rad/s
CONTROL_PERIOD = 0.005       # 200 Hz
TORQUE_TIME_CONSTANT = 0.015 # simplified motor response, not a datasheet value


def clamp(value, low, high):
    return max(low, min(high, value))


def quantize(value, low, high, bits):
    """Approximate the float -> CAN field -> float mapping of MIT commands."""
    steps = (1 << bits) - 1
    integer = round((clamp(value, low, high) - low) * steps / (high - low))
    return low + integer * (high - low) / steps


def read_zero_offsets():
    urdf = (Path(get_package_share_directory('four_axis_arm_description'))
            / 'urdf' / 'four_axis_arm_gazebo.urdf')
    root = ET.parse(urdf).getroot()
    element = root.find('encoder_zero')
    if element is None:
        raise RuntimeError(f'Missing <encoder_zero> in {urdf}')
    offsets = {name: float(element.attrib[name]) for name in JOINT_LIMITS}
    if not all(math.isfinite(value) for value in offsets.values()):
        raise RuntimeError(f'Invalid encoder zero in {urdf}')
    return offsets


class Motor:
    def __init__(self, kp, kd):
        self.q = None             # Gazebo physical joint position, rad
        self.dq = 0.0             # Gazebo physical joint velocity, rad/s
        self.acceleration = 0.0
        self.last_stamp = None
        self.desired_q = None     # physical target = encoder zero + MIT p_des
        self.desired_dq = 0.0
        self.kp = kp
        self.kd = kd
        self.torque_ff = 0.0
        self.enabled = True
        self.target_torque = 0.0
        self.applied_torque = 0.0
        self.saturated = False


class MitControl(Node):
    def __init__(self):
        super().__init__('four_axis_arm_mit_control')
        self.declare_parameter('model_name', 'arm_four_model')
        model_name = self.get_parameter('model_name').value
        self.zero_offsets = read_zero_offsets()
        self.motors = {
            name: Motor(*DEFAULT_GAINS[name]) for name in JOINT_LIMITS
        }
        self.raw_header = None
        self.tick_count = 0

        self.torque_pubs = {
            name: self.create_publisher(
                Float64, f'/model/{model_name}/joint/{name}/cmd_force', 20)
            for name in JOINT_LIMITS
        }
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 20)
        self.motor_pub = self.create_publisher(MotorState, '/arm/motor_state', 20)
        self.create_subscription(
            JointState, '/arm/joint_states_raw', self.on_joint_state, 20)
        self.create_subscription(
            MitCommand, '/arm/mit_command', self.on_command, 20)
        self.create_timer(CONTROL_PERIOD, self.step)
        self.get_logger().info(
            f'MIT simulation ready for model {model_name}; '
            'commands: /arm/mit_command, feedback: /arm/motor_state')

    def on_joint_state(self, msg):
        stamp = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        positions = dict(zip(msg.name, msg.position))
        velocities = dict(zip(msg.name, msg.velocity))
        self.raw_header = msg.header
        for name, motor in self.motors.items():
            if name not in positions or name not in velocities:
                continue
            q, dq = positions[name], velocities[name]
            if not math.isfinite(q) or not math.isfinite(dq):
                continue
            if motor.q is None and motor.desired_q is None:
                # Hold the measured startup pose until a command arrives.
                motor.desired_q = q
            if motor.last_stamp is not None:
                dt = stamp - motor.last_stamp
                if 0.0005 <= dt <= 0.1:
                    measured_accel = clamp((dq - motor.dq) / dt, -200.0, 200.0)
                    motor.acceleration = (0.2 * measured_accel
                                          + 0.8 * motor.acceleration)
            motor.q, motor.dq, motor.last_stamp = q, dq, stamp

    def on_command(self, msg):
        motor = self.motors.get(msg.joint_name)
        if motor is None:
            self.get_logger().warn(f'Unknown joint: {msg.joint_name}')
            return
        fields = (msg.position_des, msg.velocity_des, msg.kp,
                  msg.kd, msg.torque_ff)
        if not all(math.isfinite(value) for value in fields):
            self.get_logger().warn('MIT command contains a non-finite value')
            return
        low, high = JOINT_LIMITS[msg.joint_name]
        calibrated_q = quantize(msg.position_des, -P_MAX, P_MAX, 16)
        motor.desired_q = clamp(
            self.zero_offsets[msg.joint_name] + calibrated_q, low, high)
        motor.desired_dq = quantize(msg.velocity_des, -V_MAX, V_MAX, 12)
        motor.kp = quantize(msg.kp, 0.0, KP_MAX, 12)
        motor.kd = quantize(msg.kd, 0.0, KD_MAX, 12)
        motor.torque_ff = quantize(msg.torque_ff, -T_MAX, T_MAX, 12)
        motor.enabled = msg.enable
        self.get_logger().info(
            f'{msg.joint_name}: target={motor.desired_q:.3f} rad physical, '
            f'Kp={motor.kp:.2f}, Kd={motor.kd:.2f}, '
            f'feedforward={motor.torque_ff:.2f} N m, enabled={motor.enabled}')

    def step(self):
        if self.raw_header is None:
            return
        for name, motor in self.motors.items():
            if motor.q is None or motor.desired_q is None:
                continue
            if motor.enabled:
                requested = (motor.kp * (motor.desired_q - motor.q)
                             + motor.kd * (motor.desired_dq - motor.dq)
                             + motor.torque_ff)
                speed_factor = clamp(
                    1.0 - abs(motor.dq) / NO_LOAD_SPEED, 0.0, 1.0)
                limit = PEAK_TORQUE * speed_factor
                motor.target_torque = clamp(requested, -limit, limit)
                motor.saturated = abs(requested) > limit + 1e-9
                response = min(1.0, CONTROL_PERIOD / TORQUE_TIME_CONSTANT)
                motor.applied_torque += response * (
                    motor.target_torque - motor.applied_torque)
            else:
                motor.target_torque = 0.0
                motor.applied_torque = 0.0
                motor.saturated = False
            self.torque_pubs[name].publish(
                Float64(data=motor.applied_torque))

        self.tick_count += 1
        if self.tick_count % 4 == 0:
            self.publish_feedback()

    def publish_feedback(self):
        joints = JointState()
        joints.header = self.raw_header
        for name, motor in self.motors.items():
            if motor.q is None:
                continue
            torque_estimate = (quantize(motor.applied_torque, -T_MAX, T_MAX, 12)
                               if motor.enabled else 0.0)
            joints.name.append(name)
            joints.position.append(motor.q)
            joints.velocity.append(motor.dq)
            joints.effort.append(torque_estimate)

            state = MotorState()
            state.header = self.raw_header
            state.joint_name = name
            state.position = motor.q - self.zero_offsets[name]
            state.velocity = motor.dq
            state.acceleration = motor.acceleration
            state.torque_estimate = torque_estimate
            state.commanded_torque = motor.target_torque
            state.enabled = motor.enabled
            state.saturated = motor.saturated
            self.motor_pub.publish(state)
        self.joint_pub.publish(joints)


def main(args=None):
    rclpy.init(args=args)
    node = MitControl()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            for publisher in node.torque_pubs.values():
                publisher.publish(Float64(data=0.0))
            rclpy.spin_once(node, timeout_sec=0.05)
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
