import rclpy
from chapt4_interfaces.srv import PatrolTask
from rcl_interfaces.msg import SetParametersResult
from rclpy.node import Node


class PatrolServer(Node):
    def __init__(self):
        super().__init__('patrol_server')

        self.declare_parameter('robot_name', 'robot-01')
        self.declare_parameter('allow', True)

        self.add_on_set_parameters_callback(self.on_parameter_update)

        self.service = self.create_service(
            PatrolTask, 'patrol_task', self.handle_patrol_task)

        self.get_logger().info('patrol_task service is ready')

    def on_parameter_update(self, pars):
        for par in pars:
            if par.name == 'robot_name' and par.value == '':
                return SetParametersResult(
                    successful=False, reason='robot_name cannot be empty')
        return SetParametersResult(successful=True)

    def handle_patrol_task(self, request, response):
        robot_name = self.get_parameter('robot_name').value
        allow_task = self.get_parameter('allow').value

        if allow_task:
            response.accepted = True
            response.message = robot_name + ' accepted target: ' + request.target_name
        else:
            response.accepted = False
            response.message = robot_name + ' rejected target: ' + request.target_name

        return response


def main(args=None):
    rclpy.init(args=args)
    node = PatrolServer()

    try:
        rclpy.spin(node)

    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
