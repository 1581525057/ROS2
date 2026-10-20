"""Decode the six-byte LoRa remote-control frames from a serial byte stream."""

from dataclasses import dataclass


@dataclass(frozen=True)
class RemoteKeys:
    sequence: int
    key1: int
    key2: int


class KeyFrameParser:
    def __init__(self):
        self.buffer = bytearray()

    def clear(self):
        self.buffer.clear()

    def feed(self, data):
        self.buffer.extend(data)
        frames = []

        while len(self.buffer) >= 6:
            frame = self.buffer[:6]
            if (
                frame[0] == 0xA5
                and frame[1] == 0x5A
                and frame[2] == 0x01
                and frame[4] & 0xFC == 0
                and frame[5] == frame[0] ^ frame[1] ^ frame[2] ^ frame[3] ^ frame[4]
            ):
                frames.append(
                    RemoteKeys(
                        sequence=frame[3],
                        key1=frame[4] & 0x01,
                        key2=(frame[4] >> 1) & 0x01,
                    )
                )
                del self.buffer[:6]
            else:
                del self.buffer[0]

        return frames
