import rclpy
from service_interfaces.srv import Patrol
from rclpy.node import Node

class PatrolClient(Node):
    def __init__(self):
        super().__init__('Patrol_Client')
        self.declare_parameter('target_name','room-A')
        self.client = self.create_client(Patrol,'partrol_service')

    def send_request(self):
        while not self.client.wait_for_service(1.0):
            self.get_logger().warning('正在等待服务端启动')
        request = Patrol.Request()
        request.target_name = self.get_parameter('target_name').value
        fu = self.client.call_async(request)
        rclpy.spin_until_future_complete(self,fu)
        respose = fu.result()
        self.get_logger().info('accept:'  + str(respose.accept))
        self.get_logger().info('message:' + respose.message)

def main():
    rclpy.init()
    node = PatrolClient()
    try:
        node.send_request()
    finally:
        rclpy.shutdown()


