import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


class ServiceClient(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("节点已启动：%s!" % name)

        self.declare_parameter('a',1314)
        self.declare_parameter('b',520)

        self.client_ = self.create_client(AddTwoInts,'add_two_ints_srv')

    def result_callback(self,result_future):
        response = result_future.result()
        self.get_logger().info(f"收到结果：{response.sum}")

    def send_request(self):
        while rclpy.ok() and self.client_.wait_for_service(1) == False:
            self.get_logger().info('等待服务')

        request = AddTwoInts.Request()
        a = self.get_parameter('a').value
        b = self.get_parameter('b').value
        request.a = a
        request.b = b
        self.client_.call_async(request).add_done_callback(self.result_callback)


def main(args=None):
    rclpy.init(args=args) # 初始化rclpy
    node = ServiceClient("service_client_02") # 新建一个节点
    node.send_request()
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy