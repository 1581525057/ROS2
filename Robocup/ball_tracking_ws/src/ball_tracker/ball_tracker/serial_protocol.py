"""Encode UART frames sent to the ball-tracking microcontroller."""

import math
import struct


HEADER = 0xAA
TAIL = 0x55
VERSION = 3
FRAME_LENGTH = 38
def imu_euler_degrees(message):
    """Convert FDILink roll, pitch and heading from radians to degrees."""
    angles = (message.x, message.y, message.z)
    if not all(map(math.isfinite, angles)):
        return None
    return tuple(map(math.degrees, angles))


def encode_target(message, euler_deg=None, started=False):
    """Encode tracking state, target, and optional Euler angles in degrees."""
    camera_ok = bool(message.camera_ok)
    detected = bool(started) and camera_ok and bool(message.detected)
    values = (
        float(message.error_x_norm),
        float(message.error_y_norm),
        float(message.area_ratio),
        float(message.width_norm),
        float(message.height_norm),
    )
    if not detected or not all(math.isfinite(value) for value in values):
        detected = False
        values = (0.0,) * 5
    else:
        values = (
            max(-1.0, min(1.0, values[0])),
            max(-1.0, min(1.0, values[1])),
            max(0.0, min(1.0, values[2])),
            max(0.0, min(1.0, values[3])),
            max(0.0, min(1.0, values[4])),
        )
    flags = int(camera_ok) | (int(detected) << 1)
    if str(message.target_ball).lower() == "blue":
        flags |= 1 << 2
    if started:
        flags |= 1 << 4
    if euler_deg is not None and len(euler_deg) == 3 and all(
        math.isfinite(float(angle)) for angle in euler_deg
    ):
        flags |= 1 << 3
        angles = tuple(float(angle) for angle in euler_deg)
    else:
        angles = (0.0, 0.0, 0.0)
    payload = struct.pack("<BBB8f", VERSION, FRAME_LENGTH, flags, *values, *angles)
    checksum = sum(payload) & 0xFF
    return bytes((HEADER,)) + payload + bytes((checksum, TAIL))
