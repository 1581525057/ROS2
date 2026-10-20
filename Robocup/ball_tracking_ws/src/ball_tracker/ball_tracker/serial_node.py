"""Send ball observations and IMU angles to the microcontroller."""

import time

import rclpy
import serial
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from geometry_msgs.msg import Vector3
from std_msgs.msg import String

from ball_tracker_interfaces.msg import BallTarget
from ball_tracker.key_selection import control_from_keys
from ball_tracker.serial_protocol import encode_target, imu_euler_degrees


# ===== 单独运行节点时的默认值；使用 launch 时请修改 ball_tracking.launch.py =====
SERIAL_DEVICE = "/dev/ttyUSB1"
BAUD_RATE = 115200
SEND_HZ = 100.0
# ========================================================


class BallSerialNode(Node):
    def __init__(self):
        super().__init__("ball_serial")
        self.declare_parameter("serial_device", SERIAL_DEVICE)
        self.declare_parameter("baud_rate", BAUD_RATE)
        self.declare_parameter("send_hz", SEND_HZ)
        self.declare_parameter("stale_timeout", 0.5)
        self.declare_parameter("imu_stale_timeout", 0.5)

        self.create_subscription(BallTarget, "/ball/target_msg", self.on_target, 10)
        self.create_subscription(String, "/lora/keys", self.on_keys, 10)
        self.create_subscription(
            Vector3, "/euler_angles", self.on_imu, qos_profile_sensor_data
        )
        self.latest_target = BallTarget()
        self.latest_received_at = 0.0
        self.started = False
        self.selected_ball = None
        self.latest_euler_deg = None
        self.latest_imu_received_at = 0.0
        self.connection = None
        self.requested_settings = None
        self.next_retry_at = 0.0
        self.last_warning_at = 0.0

        send_hz = float(self.get_parameter("send_hz").value)
        if send_hz < 100.0:
            raise ValueError("send_hz must be at least 100 Hz")
        self.send_interval = 1.0 / send_hz
        self.timer = self.create_timer(self.send_interval, self.send_frame)
        self.get_logger().info(
            "Subscribed to /ball/target_msg and /euler_angles; sending MCU frames"
        )

    def on_target(self, message):
        self.latest_target = message
        self.latest_received_at = time.monotonic()

    def on_keys(self, message):
        control = control_from_keys(message.data)
        if control is None:
            return
        if control.target_ball != self.selected_ball:
            self.latest_target = BallTarget()
            self.latest_received_at = 0.0
        self.selected_ball = control.target_ball
        self.started = control.enabled
        self.send_frame()

    def on_imu(self, message):
        self.latest_euler_deg = imu_euler_degrees(message)
        if self.latest_euler_deg is not None:
            self.latest_imu_received_at = time.monotonic()
        self.send_frame()

    def warn_throttled(self, message):
        now = time.monotonic()
        if now - self.last_warning_at >= 5.0 or self.last_warning_at == 0.0:
            self.get_logger().warning(message)
            self.last_warning_at = now

    def close_serial(self):
        if self.connection is not None:
            self.connection.close()
        self.connection = None

    def send_frame(self):
        device = str(self.get_parameter("serial_device").value).strip()
        baud_rate = int(self.get_parameter("baud_rate").value)
        settings = (device, baud_rate)
        if settings != self.requested_settings:
            self.requested_settings = settings
            self.close_serial()
            self.next_retry_at = 0.0
        if self.connection is None:
            if time.monotonic() < self.next_retry_at:
                return
            try:
                self.connection = serial.Serial(
                    port=device, baudrate=baud_rate,
                    write_timeout=0.2, exclusive=True,
                )
                self.get_logger().info(f"Serial opened: {device} at {baud_rate} baud")
            except (serial.SerialException, OSError, ValueError) as exc:
                self.next_retry_at = time.monotonic() + 1.0
                self.warn_throttled(f"Cannot open serial port {device}: {exc}")
                return

        age = time.monotonic() - self.latest_received_at
        stale_timeout = max(0.0, float(self.get_parameter("stale_timeout").value))
        target = self.latest_target if age <= stale_timeout else BallTarget()
        if self.selected_ball is not None and target.target_ball != self.selected_ball:
            target = BallTarget()
            target.target_ball = self.selected_ball
        imu_age = time.monotonic() - self.latest_imu_received_at
        imu_stale_timeout = max(0.0, float(self.get_parameter("imu_stale_timeout").value))
        euler_deg = (
            self.latest_euler_deg
            if self.latest_euler_deg is not None and imu_age <= imu_stale_timeout
            else None
        )
        try:
            frame = encode_target(target, euler_deg, started=self.started)
            if self.connection.write(frame) != len(frame):
                raise serial.SerialTimeoutException("partial serial write")
        except (serial.SerialException, OSError) as exc:
            self.warn_throttled(f"Serial write failed: {exc}")
            self.close_serial()
            self.next_retry_at = time.monotonic() + 1.0

    def destroy_node(self):
        self.close_serial()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = None
    try:
        node = BallSerialNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node is not None:
            node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
