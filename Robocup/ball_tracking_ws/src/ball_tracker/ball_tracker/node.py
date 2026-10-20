"""ROS 2 camera-to-YOLO node. It publishes observations, not motor commands."""

import json
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import cv2
import numpy as np
import rclpy
from rclpy.executors import ExternalShutdownException, ShutdownException, SingleThreadedExecutor
from rclpy.node import Node
from rclpy.parameter import Parameter
from std_msgs.msg import String
from ultralytics import YOLO

from ball_tracker_interfaces.msg import BallTarget
from ball_tracker.key_selection import selected_ball_from_keys
from ball_tracker.vision import Detection, ball_class_ids, target_info


# ===== 单独运行节点时的默认值；使用 launch 时请修改 ball_tracking.launch.py =====
TARGET_BALL = "blue"  # LoRa key2=0 选红球，key2=1 选蓝球；key1 控制启停
CAMERA_INDEX = 6      # 4 对应 /dev/video4；例如 0 对应 /dev/video0
CAMERA_DEVICE = ""    # 可选：填写稳定设备路径；非空时优先于 CAMERA_INDEX
# ==============================================

DEFAULT_MODEL = "/home/yezi/yolo/ultralytics-8.3.163/ball.pt"


class BallTrackerNode(Node):
    def __init__(self):
        super().__init__("ball_tracker")
        self.declare_parameter("model_path", DEFAULT_MODEL)
        self.declare_parameter("camera_index", CAMERA_INDEX)
        self.declare_parameter("camera_device", CAMERA_DEVICE)
        self.declare_parameter("camera_mjpg", True)
        self.declare_parameter("target_ball", TARGET_BALL)
        self.declare_parameter("confidence", 0.5)
        self.declare_parameter("preview", True)

        model_path = str(self.get_parameter("model_path").value)
        if not Path(model_path).is_file():
            raise FileNotFoundError(f"YOLO model not found: {model_path}")
        self.model = YOLO(model_path)
        for color in ("red", "blue"):
            ball_class_ids(self.model.names, color)

        self.publisher = self.create_publisher(String, "/ball/target", 10)
        self.target_publisher = self.create_publisher(BallTarget, "/ball/target_msg", 10)
        self.key_subscription = self.create_subscription(
            String, "/lora/keys", self.on_lora_keys, 1
        )
        self.capture = None
        self.current_source = None
        self.last_warning_ns = 0
        self.read_failures = 0
        self.last_frame = None
        self.next_camera_retry_time = 0.0
        self.inference_pool = ThreadPoolExecutor(max_workers=1)
        self.inference_future = None
        self.inference_generation = 0
        self.camera_generation = 0
        self.preview_info = None
        self.preview_target = None
        self.preview_updated = 0.0
        self.get_logger().info(f"Model loaded: {model_path}; classes: {self.model.names}")

    def on_lora_keys(self, message):
        selected = selected_ball_from_keys(message.data)
        if selected is None or selected == self.get_parameter("target_ball").value:
            return
        result = self.set_parameters([Parameter("target_ball", value=selected)])[0]
        if result.successful:
            self.get_logger().info(f"LoRa selected {selected} ball")
        else:
            self.warn_throttled(f"Cannot select {selected} ball: {result.reason}")

    def camera_source(self):
        path = str(self.get_parameter("camera_device").value).strip()
        return path if path else int(self.get_parameter("camera_index").value)

    def target_color(self):
        return str(self.get_parameter("target_ball").value).strip().lower()

    def open_camera(self, source):
        if self.capture is not None:
            self.capture.release()
        self.current_source = source
        self.capture = cv2.VideoCapture(source)
        if self.capture.isOpened():
            if bool(self.get_parameter("camera_mjpg").value):
                self.capture.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*"MJPG"))
            # Some V4L2 drivers honor this, preventing old frames from piling up.
            self.capture.set(cv2.CAP_PROP_BUFFERSIZE, 1)
            self.get_logger().info(f"Camera opened: {source}")
            return True
        self.capture.release()
        self.capture = None
        return False

    def warn_throttled(self, message):
        now_ns = self.get_clock().now().nanoseconds
        if now_ns - self.last_warning_ns >= 5_000_000_000 or self.last_warning_ns == 0:
            self.get_logger().warning(message)
            self.last_warning_ns = now_ns

    def publish_target(self, target_ball, frame_width, frame_height, info, camera_ok):
        payload = {
            "stamp_ns": self.get_clock().now().nanoseconds,
            "camera_ok": camera_ok,
            "detected": info is not None,
            "target_ball": target_ball,
            "image_width": frame_width,
            "image_height": frame_height,
        }
        if info is not None:
            payload.update(info)
        self.publisher.publish(String(data=json.dumps(payload, separators=(",", ":"))))
        target_msg = BallTarget()
        target_msg.stamp_ns = payload["stamp_ns"]
        target_msg.camera_ok = camera_ok
        target_msg.detected = info is not None
        target_msg.target_ball = target_ball
        if info is not None:
            target_msg.error_x_norm = info["error_x_norm"]
            target_msg.error_y_norm = info["error_y_norm"]
            target_msg.area_ratio = info["area_ratio"]
            target_msg.width_norm = info["width_norm"]
            target_msg.height_norm = info["height_norm"]
        self.target_publisher.publish(target_msg)

    def show_preview(self, frame, target_ball, info, camera_ok):
        if not bool(self.get_parameter("preview").value):
            return
        if frame is None:
            frame = self.last_frame
        if frame is None:
            frame = np.zeros((480, 640, 3), dtype=np.uint8)
        frame = frame.copy()
        frame_height, frame_width = frame.shape[:2]
        cv2.line(frame, (frame_width // 2, 0),
                 (frame_width // 2, frame_height), (255, 255, 255), 1)
        if not camera_ok:
            status = "CAMERA OFFLINE - check USB connection"
            details = f"target={target_ball}"
            color = (0, 0, 255)
        elif info is None:
            status = f"{target_ball} NOT FOUND"
            details = "camera OK - searching"
            color = (0, 0, 255)
        else:
            x1, y1, x2, y2 = [int(v) for v in info["bbox_xyxy"]]
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.circle(frame, (int(info["center_x_px"]), int(info["center_y_px"])),
                       4, (0, 255, 0), -1)
            status = f"{target_ball} FOUND  conf={info['confidence']:.2f}"
            details = (f"error_x={info['error_x_norm']:+.2f}  "
                       f"error_y={info['error_y_norm']:+.2f}  "
                       f"area={info['area_ratio']:.3f}")
            color = (0, 255, 0)
        cv2.rectangle(frame, (0, 0), (frame_width, 58), (0, 0, 0), -1)
        cv2.putText(frame, status, (8, 22), cv2.FONT_HERSHEY_SIMPLEX,
                    0.55, color, 2)
        cv2.putText(frame, details, (8, 48), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, color, 1)
        cv2.imshow("ball_tracker", frame)
        cv2.waitKey(1)

    def infer(self, frame, confidence):
        result = self.model.predict(frame, conf=confidence, verbose=False)[0]
        detections = []
        for box in result.boxes:
            x1, y1, x2, y2 = box.xyxy[0].tolist()
            detections.append(Detection(
                class_id=int(box.cls[0]),
                confidence=float(box.conf[0]),
                x1=x1, y1=y1, x2=x2, y2=y2,
            ))
        return detections

    def finish_inference(self):
        future = self.inference_future
        if future is None or not future.done():
            return
        self.inference_future = None
        try:
            detections = future.result()
        except Exception as exc:
            self.warn_throttled(f"YOLO inference failed: {exc}")
            self.preview_info = None
            return
        if self.inference_generation != self.camera_generation or self.capture is None:
            return
        target_ball = self.target_color()
        if target_ball not in ("red", "blue"):
            self.warn_throttled("target_ball must be red or blue")
            info = None
        else:
            allowed_ids = ball_class_ids(self.model.names, target_ball)
            info = target_info(detections, allowed_ids,
                               self.inference_width, self.inference_height)
        self.preview_info = info
        self.preview_target = target_ball
        self.preview_updated = time.monotonic()
        self.publish_target(target_ball, self.inference_width,
                            self.inference_height, info, True)

    def process_frame(self):
        source = self.camera_source()
        if source != self.current_source:
            self.next_camera_retry_time = 0.0
            self.camera_generation += 1
            self.preview_info = None
        self.finish_inference()
        target_ball = self.target_color()
        if target_ball not in ("red", "blue"):
            self.warn_throttled("target_ball must be red or blue")
            self.publish_target(target_ball, 0, 0, None, False)
            self.show_preview(None, target_ball, None, False)
            return
        if self.capture is None or source != self.current_source:
            if time.monotonic() < self.next_camera_retry_time:
                self.publish_target(target_ball, 0, 0, None, False)
                self.show_preview(None, target_ball, None, False)
                return
            if not self.open_camera(source):
                self.next_camera_retry_time = time.monotonic() + 1.0
                self.warn_throttled(f"Cannot open camera {source}; retrying")
                self.publish_target(target_ball, 0, 0, None, False)
                self.show_preview(None, target_ball, None, False)
                return

        ok, frame = self.capture.read()
        if not ok or frame is None:
            if self.read_failures == 0:
                self.camera_generation += 1
                self.preview_info = None
            target_ball = self.target_color()
            self.read_failures += 1
            if self.read_failures == 1:
                self.get_logger().warning(f"Camera {source} frame read failed")
            if self.read_failures >= 3:
                self.get_logger().warning(f"Camera {source} failed 3 reads; reopening")
                self.capture.release()
                self.capture = None
                self.next_camera_retry_time = time.monotonic() + 0.5
            self.publish_target(target_ball, 0, 0, None, False)
            self.show_preview(None, target_ball, None, False)
            return

        if self.read_failures:
            self.get_logger().info(
                f"Camera {source} frames recovered after {self.read_failures} failed read(s)")
            self.read_failures = 0
        self.last_frame = frame
        frame_height, frame_width = frame.shape[:2]
        if self.inference_future is None and target_ball in ("red", "blue"):
            confidence = float(self.get_parameter("confidence").value)
            self.inference_generation = self.camera_generation
            self.inference_width = frame_width
            self.inference_height = frame_height
            self.inference_future = self.inference_pool.submit(self.infer, frame, confidence)
        info = (self.preview_info if self.preview_target == target_ball
                and time.monotonic() - self.preview_updated < 0.5 else None)
        self.show_preview(frame, target_ball, info, True)

    def destroy_node(self):
        self.inference_pool.shutdown(wait=True)
        if self.capture is not None:
            self.capture.release()
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = None
    executor = None
    spin_thread = None
    try:
        node = BallTrackerNode()
        executor = SingleThreadedExecutor()
        executor.add_node(node)

        def spin_callbacks():
            try:
                executor.spin()
            except (ExternalShutdownException, ShutdownException):
                pass

        spin_thread = threading.Thread(target=spin_callbacks, daemon=True)
        spin_thread.start()

        # Keep capture and OpenCV's preview on the main thread. YOLO runs separately,
        # so a slow prediction does not freeze the camera window.
        while rclpy.ok():
            started = time.monotonic()
            node.process_frame()
            remaining = 1.0 / 30.0 - (time.monotonic() - started)
            if remaining > 0:
                time.sleep(remaining)
    except KeyboardInterrupt:
        pass
    finally:
        if executor is not None:
            executor.shutdown()
        if spin_thread is not None:
            spin_thread.join(timeout=2.0)
        if node is not None:
            node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
