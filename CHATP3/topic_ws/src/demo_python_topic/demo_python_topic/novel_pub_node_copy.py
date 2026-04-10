import rclpy
from rclpy.node import Node
import requests
from example_interfaces.msg import String
from queue import Queue


class NovelPubNode(Node):
    def __init__(self, node_name):
        super.__init__(node_name)

        self.get_logger().info

