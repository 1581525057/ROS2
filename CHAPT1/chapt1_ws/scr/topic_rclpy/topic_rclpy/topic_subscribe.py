import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class NodeSubscrible(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info(f'话题订阅者节点{name}创建成功')
        #创建订阅者
       
        self.command_subscribe = self.create_subscription(Twist,'cmd_vel',self.command_callback,10)

    def command_callback(self,msg):
        linear_x = msg.linear.x
        linear_y = msg.linear.y
        angular_z = msg.angular.z
        self.get_logger().info(f'线速度是：x:{linear_x:.3f},y:{linear_y:.3f}')
        self.get_logger().info(f"角速度为：z:{angular_z:.3f}")

def main(arges=None):
    rclpy.init(args=arges) 
    node = NodeSubscrible('Subscirible')
    rclpy.spin(node)
    rclpy.shutdown()
