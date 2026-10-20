import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import math
from rcl_interfaces.msg import SetParametersResult
from rclpy.parameter import Parameter

class NodePublsher(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info(f'话题发布者节点{name}创建成功')

        self.num = 0.0
        self.command_publisher = self.create_publisher(Twist,"cmd_vel",10)
        self.declare_parameter('publish_period',0.1)
        publish_period = self.get_parameter('publish_period').value
        self.timer = self.create_timer(publish_period,self.timer_callback)
        self.add_on_set_parameters_callback(
            self.parameter_callback
        )

    def timer_callback(self):
        twist = Twist()
        twist.linear.x = math.sin(self.num)
        twist.linear.y = math.cos(self.num)
        twist.angular.z = twist.linear.x * twist.linear.y
        self.num +=0.1
        self.command_publisher.publish(twist)
        self.get_logger().info('正在发布速度')

    def parameter_callback(self,parameters:list[Parameter]):
        for parameter in parameters:
            if parameter.name == 'publish_period':
                new_period = parameter.value

            if(new_period <= 0.0):
                return SetParametersResult(
                    successful =False,
                    reason = '时间必须大于0'
                )
            self.timer.timer_period_ns = int(
                new_period * 1_000_000_000
            )
            self.timer.reset() # 修改周期后，让定时器从现在开始，按照新周期重新计时。
            self.get_logger().info(
                f'发布周期已修改为 {new_period:.2f} 秒'
            )
        return SetParametersResult(successful=True)





def main(arges=None):
    rclpy.init(args=arges) 
    node = NodePublsher('Pubilsher')
    rclpy.spin(node)
    rclpy.shutdown()

