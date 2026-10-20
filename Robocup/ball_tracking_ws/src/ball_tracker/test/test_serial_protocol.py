import struct
import unittest
from types import SimpleNamespace

from ball_tracker.serial_protocol import encode_target, imu_euler_degrees


class SerialProtocolTests(unittest.TestCase):
    def test_blue_detection_frame_layout(self):
        target = SimpleNamespace(
            camera_ok=True, detected=True, target_ball="blue",
            error_x_norm=-0.25, error_y_norm=0.5,
            area_ratio=0.1, width_norm=0.2, height_norm=0.3,
        )
        frame = encode_target(target, (10.0, -20.0, 30.0), started=True)
        self.assertEqual(len(frame), 38)
        self.assertEqual((frame[0], frame[37]), (0xAA, 0x55))
        version, length, flags, *values = struct.unpack("<BBB8f", frame[1:36])
        self.assertEqual((version, length, flags), (3, 38, 0x1F))
        for actual, expected in zip(values, (-0.25, 0.5, 0.1, 0.2, 0.3, 10.0, -20.0, 30.0)):
            self.assertAlmostEqual(actual, expected)
        self.assertEqual(frame[36], sum(frame[1:36]) & 0xFF)

    def test_lost_camera_clears_detection_and_values(self):
        target = SimpleNamespace(
            camera_ok=False, detected=True, target_ball="red",
            error_x_norm=0.8, error_y_norm=0.4,
            area_ratio=0.3, width_norm=0.5, height_norm=0.5,
        )
        frame = encode_target(target, (1.0, 2.0, 3.0), started=True)
        _, _, flags, *values = struct.unpack("<BBB8f", frame[1:36])
        self.assertEqual(flags, 0x18)
        self.assertEqual(values, [0.0] * 5 + [1.0, 2.0, 3.0])

    def test_unavailable_imu_clears_angle_flag_and_values(self):
        target = SimpleNamespace(
            camera_ok=True, detected=False, target_ball="blue",
            error_x_norm=0.0, error_y_norm=0.0,
            area_ratio=0.0, width_norm=0.0, height_norm=0.0,
        )
        for angles in (None, (1.0, float("nan"), 3.0)):
            _, _, flags, *values = struct.unpack(
                "<BBB8f", encode_target(target, angles, started=True)[1:36]
            )
            self.assertEqual(flags, 0x15)
            self.assertEqual(values[5:], [0.0, 0.0, 0.0])

    def test_stop_clears_detection_but_keeps_valid_angles_and_color(self):
        target = SimpleNamespace(
            camera_ok=True, detected=True, target_ball="blue",
            error_x_norm=0.25, error_y_norm=0.5,
            area_ratio=0.1, width_norm=0.2, height_norm=0.3,
        )
        _, _, flags, *values = struct.unpack(
            "<BBB8f", encode_target(target, (1.0, 2.0, 3.0), started=False)[1:36]
        )
        self.assertEqual(flags, 0x0D)
        self.assertEqual(values, [0.0] * 5 + [1.0, 2.0, 3.0])

    def test_fdilink_euler_angles_are_converted_to_degrees(self):
        imu = SimpleNamespace(
            x=0.0, y=1.5707963267948966, z=-3.141592653589793,
        )
        self.assertEqual(imu_euler_degrees(imu), (0.0, 90.0, -180.0))
        imu.y = float("nan")
        self.assertIsNone(imu_euler_degrees(imu))


if __name__ == "__main__":
    unittest.main()
