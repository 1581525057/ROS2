import unittest

from ball_tracker.lora_protocol import KeyFrameParser, RemoteKeys


class KeyFrameParserTests(unittest.TestCase):
    def test_split_and_multiple_frames(self):
        parser = KeyFrameParser()
        self.assertEqual(parser.feed(bytes.fromhex("A5 5A 01")), [])
        self.assertEqual(
            parser.feed(bytes.fromhex("00 01 FF A5 5A 01 01 01 FE")),
            [RemoteKeys(0, 1, 0), RemoteKeys(1, 1, 0)],
        )

    def test_invalid_frames_resynchronize_without_publishing(self):
        parser = KeyFrameParser()
        self.assertEqual(
            parser.feed(
                bytes.fromhex(
                    "00 A5 5A 01 00 04 FA "  # reserved key bits set
                    "A5 5A 01 00 03 00 "  # invalid checksum
                    "A5 5A 01 FF 02 03"  # valid after sequence wrap
                )
            ),
            [RemoteKeys(255, 0, 1)],
        )


if __name__ == "__main__":
    unittest.main()
