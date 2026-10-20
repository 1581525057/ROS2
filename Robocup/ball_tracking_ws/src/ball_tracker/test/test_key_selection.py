import unittest

from ball_tracker.key_selection import KeyControl, control_from_keys, selected_ball_from_keys


class KeySelectionTests(unittest.TestCase):
    def test_key1_controls_start_and_key2_selects_color_independently(self):
        for key1, key2, enabled, color in (
            (0, 0, False, "red"),
            (0, 1, False, "blue"),
            (1, 0, True, "red"),
            (1, 1, True, "blue"),
        ):
            data = f'{{"online":1,"key1":{key1},"key2":{key2}}}'
            self.assertEqual(control_from_keys(data), KeyControl(enabled, color))
            self.assertEqual(selected_ball_from_keys(data), color)

    def test_offline_and_invalid_messages_do_not_select(self):
        for data in (
            '{"online":0,"key1":1,"key2":0}',
            '{"online":1,"key1":1,"key2":2}',
            '{"online":1,"key1":2,"key2":0}',
            "not json",
        ):
            self.assertIsNone(control_from_keys(data))
            self.assertIsNone(selected_ball_from_keys(data))


if __name__ == "__main__":
    unittest.main()
