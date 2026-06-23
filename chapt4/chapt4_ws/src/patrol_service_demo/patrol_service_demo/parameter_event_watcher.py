import rclpy
from rcl_interfaces.msg import ParameterEvent
from rclpy.node import Node
from rclpy.parameter import parameter_value_to_python


class ParameterEventWatcher(Node):
    def __init__(self):
        super().__init__('parameter_event_watcher')

        self.subscription = self.create_subscription(
            ParameterEvent, '/parameter_events', self.on_parameter_event, 10)

        self.get_logger().info('watching /parameter_events')

    def on_parameter_event(self, event):
        for par in event.new_parameters:
            value = parameter_value_to_python(par.value)
            self.get_logger().info(
                'new: node=' + event.node
                + ' name=' + par.name
                + ' value=' + str(value))

        for parameter in event.changed_parameters:
            value = parameter_value_to_python(parameter.value)
            self.get_logger().info(
                'changed: node=' + event.node
                + ' name=' + parameter.name
                + ' value=' + str(value)
            )

        for parameter in event.deleted_parameters:
            self.get_logger().info(
                'deleted: node=' + event.node
                + ' name=' + parameter.name
            )


def main(args=None):
    rclpy.init()
    node = ParameterEventWatcher()

    try:
        rclpy.spin(node)

    finally:
            rclpy.shutdown()
