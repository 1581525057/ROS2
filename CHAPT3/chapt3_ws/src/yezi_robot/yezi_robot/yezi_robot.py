import rclpy
from rclpy.node import Node

class Robot():
    def __init__(self):
        pass

class YeziRobot(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info(f'节点{node_name}启动')

def main(args=None):
    rclpy.init(args=args)
    node = YeziRobot('yezi_robot')
    rclpy.spin(node)
    rclpy.shutdown()
