import rclpy
from chapt4_interfaces.srv import PatrolTask
from rclpy.node import Node


class PatrolClient(Node):
    def __init__(self):
        super().__init__('patrol_client')
        self.declare_parameter('target_name', 'room_A')
        self.client = self.create_client(PatrolTask, 'patrol_task')

    def send_reauest(self):
        while not self.client.wait_for_service(1.0):
            self.get_logger().info('waiting for patrol_task service...')
        request = PatrolTask.Request()
        request.target_name = self.get_parameter('target_name').value
        fu = self.client.call_async(request)
        rclpy.spin_until_future_complete(self, fu)
        response = fu.result()
        self.get_logger().info('accepted: ' + str(response.accepted))
        self.get_logger().info('message: ' + response.message)


def main():
    rclpy.init()
    node = PatrolClient()

    try:
        node.send_reauest()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
