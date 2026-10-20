"""Receive LoRa remote-control keys over the LoRa serial port."""

import json
import time

import rclpy
import serial
from rclpy.node import Node
from std_msgs.msg import String

from ball_tracker.lora_protocol import KeyFrameParser


# ===== 单独运行节点时的默认值；使用 launch 时请修改 ball_tracking.launch.py =====
SERIAL_DEVICE = "/dev/ttyUSB0"
BAUD_RATE = 9600
# ========================================================

LINK_TIMEOUT_S = 2.0
RETRY_INTERVAL_S = 1.0


class LoraKeysNode(Node):
    def __init__(self):
        super().__init__("lora_keys")
        self.declare_parameter("serial_device", SERIAL_DEVICE)
        self.declare_parameter("baud_rate", BAUD_RATE)
        self.declare_parameter("link_timeout_s", LINK_TIMEOUT_S)
        self.device = str(self.get_parameter("serial_device").value).strip()
        self.baud_rate = int(self.get_parameter("baud_rate").value)
        self.link_timeout_s = float(self.get_parameter("link_timeout_s").value)
        if not self.device or self.baud_rate <= 0 or self.link_timeout_s <= 0:
            raise ValueError("LoRa device, baud rate, and link timeout must be positive")

        self.publisher = self.create_publisher(String, "/lora/keys", 10)
        self.parser = KeyFrameParser()
        self.connection = None
        self.next_retry_at = 0.0
        self.last_warning_at = 0.0
        self.last_valid_at = None
        self.sequence = None
        self.key1 = 0
        self.key2 = 0
        self.online = False

        self.read_timer = self.create_timer(0.02, self.poll_serial)
        self.publish_timer = self.create_timer(0.2, self.publish_state)

    def warn_throttled(self, message):
        now = time.monotonic()
        if now - self.last_warning_at >= 5.0 or self.last_warning_at == 0.0:
            self.get_logger().warning(message)
            self.last_warning_at = now

    def close_serial(self):
        if self.connection is not None:
            self.connection.close()
            self.connection = None
        self.parser.clear()

    def set_offline(self, warn_timeout=True):
        if self.online and warn_timeout:
            self.get_logger().warning("No valid LoRa key frame before link timeout")
        self.online = False
        self.last_valid_at = None
        self.parser.clear()

    def poll_serial(self):
        now = time.monotonic()
        if self.connection is None:
            if now < self.next_retry_at:
                return
            try:
                self.connection = serial.Serial(
                    port=self.device,
                    baudrate=self.baud_rate,
                    bytesize=serial.EIGHTBITS,
                    parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE,
                    xonxoff=False,
                    rtscts=False,
                    dsrdtr=False,
                    timeout=0,
                    exclusive=True,
                )
                self.parser.clear()
                self.get_logger().info(
                    f"LoRa serial opened: {self.device} at {self.baud_rate} baud"
                )
            except (serial.SerialException, OSError, ValueError) as exc:
                self.next_retry_at = now + RETRY_INTERVAL_S
                self.warn_throttled(f"Cannot open LoRa serial port {self.device}: {exc}")
                return

        try:
            data = self.connection.read(min(max(self.connection.in_waiting, 1), 1024))
            frames = self.parser.feed(data)
            for frame in frames:
                self.sequence = frame.sequence
                self.key1 = frame.key1
                self.key2 = frame.key2
                self.last_valid_at = time.monotonic()
                self.online = True
            if frames:
                self.publish_state()
        except (serial.SerialException, OSError) as exc:
            self.warn_throttled(f"LoRa serial read failed: {exc}")
            self.close_serial()
            self.set_offline(warn_timeout=False)
            self.next_retry_at = time.monotonic() + RETRY_INTERVAL_S

    def publish_state(self):
        if self.online and time.monotonic() - self.last_valid_at >= self.link_timeout_s:
            self.set_offline()

        payload = {
            "online": int(self.online),
            "sequence": self.sequence,
            "key1": self.key1,
            "key2": self.key2,
        }
        self.publisher.publish(String(data=json.dumps(payload, separators=(",", ":"))))

    def destroy_node(self):
        self.close_serial()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = None
    try:
        node = LoraKeysNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node is not None:
            node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
