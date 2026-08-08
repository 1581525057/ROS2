import rclpy
from service_interfaces.srv import Patrol
from rcl_interfaces.msg import SetParametersResult
from rclpy.node import Node

class PatrolServer(Node):
    def __init__(self):
        super().__init__('servzer_node')
        self.declare_parameter('robot_name','robot-01')
        self.declare_parameter('allow_task',True)
        self.add_on_set_parameters_callback(self.on_parameters_update)
        self.service = self.create_service(Patrol,'partrol_service',self.handle_server_task)
        self.get_logger().info('启动服务端')

    def on_parameters_update(self,pars):
        for par in pars:
            if par.name == 'robot_name' and par.value == '':
                return SetParametersResult(successful = False,reason = 'robot_name cannot be empty')
            else :
                return SetParametersResult(successful = True)

    def handle_server_task(self,request,response):
        robot_name = self.get_parameter('robot_name').value
        allow_task = self.get_parameter('allow_task').value
        if allow_task:
            response.accept = True
            response.message = robot_name + '接受任务地点到' + request.target_name
        else:
            response.accept = False
            response.message = '不允许接受任务'
        return response

        
def main():
    rclpy.init()
    node = PatrolServer()
    try:
        rclpy.spin(node)
    finally:
        rclpy.shutdown()

    
