"""Convert YOLO detections into camera-relative tracking information."""

from dataclasses import dataclass


@dataclass(frozen=True)
class Detection:
    class_id: int
    confidence: float
    x1: float
    y1: float
    x2: float
    y2: float


def ball_class_ids(names, target_ball):
    """Use the actual model labels, including its 'bule ball' spelling."""
    aliases = {
        "red": {"red ball", "red"},
        "blue": {"blue ball", "bule ball", "blue", "bule"},
    }
    if target_ball not in aliases:
        raise ValueError("target_ball must be 'red' or 'blue'")
    ids = {int(class_id) for class_id, name in names.items()
           if str(name).strip().lower() in aliases[target_ball]}
    if not ids:
        raise ValueError(f"Model has no {target_ball} ball class; classes: {names}")
    return ids


def target_info(detections, allowed_ids, frame_width, frame_height):
    """Choose the largest matching box and report relative position and size."""
    candidates = [d for d in detections if d.class_id in allowed_ids]
    if not candidates:
        return None
    detection = max(candidates, key=lambda d: ((d.x2 - d.x1) * (d.y2 - d.y1), d.confidence))
    x1 = max(0.0, min(float(frame_width), detection.x1))
    y1 = max(0.0, min(float(frame_height), detection.y1))
    x2 = max(0.0, min(float(frame_width), detection.x2))
    y2 = max(0.0, min(float(frame_height), detection.y2))
    center_x = (x1 + x2) / 2.0
    center_y = (y1 + y2) / 2.0
    width = max(0.0, x2 - x1)
    height = max(0.0, y2 - y1)
    return {
        "confidence": round(detection.confidence, 4),
        "center_x_px": round(center_x, 1),
        "center_y_px": round(center_y, 1),
        "center_x_norm": round(center_x / frame_width, 4),
        "center_y_norm": round(center_y / frame_height, 4),
        "error_x_norm": round(2.0 * center_x / frame_width - 1.0, 4),
        "error_y_norm": round(2.0 * center_y / frame_height - 1.0, 4),
        "width_norm": round(width / frame_width, 4),
        "height_norm": round(height / frame_height, 4),
        "area_ratio": round(width * height / (frame_width * frame_height), 4),
        "bbox_xyxy": [round(x1, 1), round(y1, 1), round(x2, 1), round(y2, 1)],
    }
