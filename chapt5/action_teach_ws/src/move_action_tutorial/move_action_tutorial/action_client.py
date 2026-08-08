import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from move_action_interfaces.action import MoveDistance


class MoveActionClient(Node):
    """Send one move goal and print feedback until the result arrives."""

    def __init__(self) -> None:
        super().__init__('move_action_client')

        self.declare_parameter('target_distance', 5.0)
        self.declare_parameter('speed', 1.0)
        self.declare_parameter('cancel_after', 0.0)

        self._action_client = ActionClient(
            self,
            MoveDistance,
            'move_distance',
        )
        self._goal_handle = None
        self._cancel_timer = None

    def send_goal(self) -> None:
        target_distance = self.get_parameter(
            'target_distance'
        ).get_parameter_value().double_value
        speed = self.get_parameter(
            'speed'
        ).get_parameter_value().double_value
        cancel_after = self.get_parameter(
            'cancel_after'
        ).get_parameter_value().double_value

        self.get_logger().info('等待 /move_distance Action 服务端……')
        while rclpy.ok() and not self._action_client.wait_for_server(
            timeout_sec=1.0
        ):
            self.get_logger().info('服务端尚未启动，继续等待')

        if not rclpy.ok():
            return

        goal = MoveDistance.Goal()
        goal.target_distance = target_distance
        goal.speed = speed

        self.get_logger().info(
            f'发送目标：距离={target_distance:.2f} m，速度={speed:.2f} m/s'
        )
        send_future = self._action_client.send_goal_async(
            goal,
            feedback_callback=self.feedback_callback,
        )
        send_future.add_done_callback(self.goal_response_callback)

        if cancel_after > 0.0:
            self._cancel_timer = self.create_timer(
                cancel_after,
                self.cancel_goal,
            )

    def goal_response_callback(self, future) -> None:
        self._goal_handle = future.result()

        if not self._goal_handle.accepted:
            self.get_logger().warning('目标被服务端拒绝')
            rclpy.shutdown()
            return

        self.get_logger().info('目标已被接受')
        result_future = self._goal_handle.get_result_async()
        result_future.add_done_callback(self.result_callback)

    def feedback_callback(self, feedback_message) -> None:
        feedback = feedback_message.feedback
        self.get_logger().info(
            f'反馈：当前位置={feedback.current_distance:.2f} m，'
            f'进度={feedback.progress_percent:.0f}%'
        )

    def cancel_goal(self) -> None:
        if self._cancel_timer is not None:
            self.destroy_timer(self._cancel_timer)
            self._cancel_timer = None

        if self._goal_handle is None or not self._goal_handle.accepted:
            self.get_logger().warning('目标尚未被接受，暂时无法取消')
            return

        self.get_logger().info('正在请求取消目标……')
        cancel_future = self._goal_handle.cancel_goal_async()
        cancel_future.add_done_callback(self.cancel_response_callback)

    def cancel_response_callback(self, future) -> None:
        response = future.result()
        if len(response.goals_canceling) > 0:
            self.get_logger().info('服务端已接受取消请求')
        else:
            self.get_logger().warning('取消请求未被接受')

    def result_callback(self, future) -> None:
        result = future.result().result
        self.get_logger().info(
            f'结果：success={result.success}，'
            f'final_distance={result.final_distance:.2f} m，'
            f'message="{result.message}"'
        )
        rclpy.shutdown()

    def destroy_node(self) -> None:
        self._action_client.destroy()
        super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = MoveActionClient()

    try:
        node.send_goal()
        rclpy.spin(node)
    except KeyboardInterrupt:
        if rclpy.ok():
            node.get_logger().info('收到 Ctrl+C，正在关闭客户端')
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
