import rclpy
from rclpy.node import Node
from rcl_interfaces.srv import SetParameters
from rclpy.parameter import Parameter


class RemoteParam(Node):
    def __init__(self):
        super().__init__('remote_param')

        # 不以 / 开头：launch 加 namespace 后仍能找到同一命名空间的服务端。
        self.client = self.create_client(SetParameters, 'servzer_node/set_parameters')


    def set_remote_param(self):
        while not self.client.wait_for_service(1.0):
            self.get_logger().info('等待服务端启动')
        request = SetParameters.Request()
        request.parameters = [Parameter('robot_name',Parameter.Type.STRING,'叶子无敌').to_parameter_msg(),
                              Parameter('allow_task',Parameter.Type.BOOL,True).to_parameter_msg()]
        fu = self.client.call_async(request)
        rclpy.spin_until_future_complete(self,fu)

        response = fu.result()
        for result in response.results:
            if result.successful:
                self.get_logger().info('参数修改成功')
            else:
                self.get_logger().info('参数修改失败原因为:'+ result.reason)

def main():
    rclpy.init()
    node = RemoteParam()
    try:
        node.set_remote_param()
    finally:
        node.destroy_node()
        rclpy.shutdown()



