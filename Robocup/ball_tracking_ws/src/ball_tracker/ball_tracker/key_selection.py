"""Map LoRa key states to tracking enable and ball color."""

import json
from dataclasses import dataclass


@dataclass(frozen=True)
class KeyControl:
    enabled: bool
    target_ball: str


def control_from_keys(message_data):
    """Return online key state, or None for offline/malformed messages."""
    try:
        state = json.loads(message_data)
    except (TypeError, ValueError):
        return None

    if not isinstance(state, dict) or state.get("online") != 1:
        return None
    key1, key2 = state.get("key1"), state.get("key2")
    if key1 not in (0, 1) or key2 not in (0, 1):
        return None
    return KeyControl(enabled=key1 == 1, target_ball="blue" if key2 == 1 else "red")


def selected_ball_from_keys(message_data):
    """Select red for key2=0 or blue for key2=1, regardless of key1."""
    control = control_from_keys(message_data)
    return control.target_ball if control is not None else None
