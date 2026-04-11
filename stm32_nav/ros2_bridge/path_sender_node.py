#!/usr/bin/env python3
"""
ROS2 node that sends current pose and target pose to the STM32 over UART.

The node publishes $NAV frames at 50 Hz while a target is active. When the
STM32 replies with $DONE, the next queued waypoint becomes active.
"""

import math
import threading

from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
import rclpy
from rclpy.node import Node
import serial


def yaw_from_quaternion(q) -> float:
    siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
    cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
    return math.atan2(siny_cosp, cosy_cosp)


class PathSenderNode(Node):
    def __init__(self):
        super().__init__("path_sender_node")

        self.declare_parameter("serial_port", "/dev/ttyUSB0")
        self.declare_parameter("baud_rate", 115200)
        self.declare_parameter("send_rate_hz", 50.0)

        port = self.get_parameter("serial_port").get_parameter_value().string_value
        baud = self.get_parameter("baud_rate").get_parameter_value().integer_value
        rate = self.get_parameter("send_rate_hz").get_parameter_value().double_value

        self._current_x = 0.0
        self._current_y = 0.0
        self._current_yaw = 0.0
        self._waypoints: list[tuple[float, float, float]] = []
        self._target: tuple[float, float, float] | None = None
        self._navigating = False
        self._lock = threading.Lock()

        self._ser = serial.Serial(port, baud, timeout=0.1)
        self.get_logger().info(f"Serial opened: {port} @ {baud}")

        self.create_subscription(
            PoseWithCovarianceStamped,
            "/amcl_pose",
            self._pose_callback,
            10,
        )
        self.create_subscription(
            PoseStamped,
            "/nav_goal",
            self._goal_callback,
            10,
        )

        self.create_timer(1.0 / rate, self._send_timer)

        self._read_thread = threading.Thread(target=self._read_serial, daemon=True)
        self._read_thread.start()

    def _pose_callback(self, msg: PoseWithCovarianceStamped):
        with self._lock:
            p = msg.pose.pose.position
            self._current_x = p.x
            self._current_y = p.y
            self._current_yaw = yaw_from_quaternion(msg.pose.pose.orientation)

    def _goal_callback(self, msg: PoseStamped):
        with self._lock:
            x = msg.pose.position.x
            y = msg.pose.position.y
            yaw = yaw_from_quaternion(msg.pose.orientation)
            self._waypoints.append((x, y, yaw))
            self.get_logger().info(f"Queued target: ({x:.3f}, {y:.3f}, {yaw:.3f})")
            if not self._navigating:
                self._start_next_waypoint()

    def _start_next_waypoint(self):
        if self._waypoints:
            self._target = self._waypoints.pop(0)
            self._navigating = True
            self.get_logger().info(
                f"Navigating to: ({self._target[0]:.3f}, {self._target[1]:.3f})"
            )
        else:
            self._target = None
            self._navigating = False

    def _send_timer(self):
        with self._lock:
            if not self._navigating or self._target is None:
                return
            tx, ty, tyaw = self._target
            cx = self._current_x
            cy = self._current_y
            cyaw = self._current_yaw

        frame = f"$NAV,{tx:.3f},{ty:.3f},{tyaw:.3f},{cx:.3f},{cy:.3f},{cyaw:.3f}\r\n"
        try:
            self._ser.write(frame.encode())
        except serial.SerialException as exc:
            self.get_logger().error(f"Serial write failed: {exc}")

    def _read_serial(self):
        buf = b""
        while rclpy.ok():
            try:
                data = self._ser.read(64)
                if not data:
                    continue
                buf += data
                while b"\n" in buf:
                    line, buf = buf.split(b"\n", 1)
                    line = line.strip().decode(errors="ignore")
                    if line == "$DONE":
                        self.get_logger().info("STM32 reached target")
                        with self._lock:
                            self._start_next_waypoint()
                    elif line == "$ERR":
                        self.get_logger().warn("STM32 reported an error")
            except serial.SerialException:
                break

    def destroy_node(self):
        self._ser.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = PathSenderNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
