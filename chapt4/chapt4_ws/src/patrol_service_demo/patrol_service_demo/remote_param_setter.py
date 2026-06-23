import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.srv import SetParameters

class RemoteParamSetter(Node):
    def __init__(self):
        super().__init__('remote_param_setter')
        self.client = self.create_client(SetParameters,'/patrol_server/set_parameters')

    def set_remote_parameters(self):
        while not self.client.wait_for_service(1.0):
            self.get_logger().info('等待 /patrol_server/set_parameters 服务...')

        request = SetParameters.Request()
        request.parameters = [
            Parameter('robot_name', Parameter.Type.STRING, 'robot_02').to_parameter_msg(),
            Parameter('allow', Parameter.Type.BOOL, False).to_parameter_msg(),
        ]
        future = self.client.call_async(request)
        rclpy.spin_until_future_complete(self,future)

        try:
            response = future.result()
            for result in response.results:
                if result.successful:
                    self.get_logger().info('远程参数修改成功')
                else:
                    self.get_logger().error(
                        f'远程参数修改被拒绝：{result.reason}'
                    )




        except Exception as error:
             self.get_logger().error(f'调用参数服务失败：{error}')

def main():
    rclpy.init()
    node = RemoteParamSetter()

    try:
       node.set_remote_parameters()

    finally:
        node.destroy_node()
        rclpy.shutdown()
