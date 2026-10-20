import time
import unittest
from types import SimpleNamespace
from unittest.mock import Mock

import rclpy
from ball_tracker.lora_keys_node import LoraKeysNode
from ball_tracker.serial_node import BallSerialNode


class LoraKeysNodeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        rclpy.init()

    @classmethod
    def tearDownClass(cls):
        rclpy.shutdown()

    def setUp(self):
        self.node = LoraKeysNode()
        self.node.connection = Mock()
        self.node.online = True
        self.node.last_valid_at = time.monotonic() - 0.1

    def tearDown(self):
        self.node.destroy_node()

    def test_timeout_keeps_control_until_key_frame_arrives(self):
        self.node.key1 = 1
        self.node.last_valid_at = time.monotonic() - self.node.link_timeout_s - 0.1
        self.node.publish_state()
        self.assertFalse(self.node.online)
        self.assertEqual(self.node.key1, 1)
        self.node.connection.write.assert_not_called()

        self.node.connection.in_waiting = 6
        self.node.connection.read.return_value = bytes.fromhex("A5 5A 01 70 01 8F")
        self.node.poll_serial()
        self.assertTrue(self.node.online)
        self.assertEqual(self.node.sequence, 112)
        self.node.connection.write.assert_not_called()

    def test_offline_state_keeps_last_ball_control(self):
        ball_node = SimpleNamespace(started=True, selected_ball="red", send_frame=Mock())
        BallSerialNode.on_keys(ball_node, SimpleNamespace(data='{"online":0,"key1":1,"key2":0}'))
        self.assertTrue(ball_node.started)
        ball_node.send_frame.assert_not_called()
        BallSerialNode.on_keys(ball_node, SimpleNamespace(data='{"online":1,"key1":0,"key2":0}'))
        self.assertFalse(ball_node.started)
        ball_node.send_frame.assert_called_once_with()


if __name__ == "__main__":
    unittest.main()
