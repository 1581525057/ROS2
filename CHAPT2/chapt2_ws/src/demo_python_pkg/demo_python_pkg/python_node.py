import rclpy
from rclpy.node import Node


def main():
    rclpy.init()
    node = Node('python_node')
    node.get_logger().info('Python 节点已启动')
    node.get_logger().warn('这是一条警告日志')
    rclpy.spin(node)
    rclpy.shutdown()
