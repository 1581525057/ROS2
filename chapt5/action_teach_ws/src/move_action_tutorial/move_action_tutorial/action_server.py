import time

import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

from move_action_interfaces.action import MoveDistance


class MoveActionServer(Node):
    """Simulate a robot moving forward and report progress."""

    def __init__(self) -> None:
        super().__init__('move_action_server')

        self._action_server = ActionServer(
            self,
            MoveDistance,
            'move_distance',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            handle_accepted_callback=self.handle_accepted_callback,
            callback_group=ReentrantCallbackGroup(),
        )
        self.get_logger().info('移动 Action 服务端已启动，等待目标……')

    def goal_callback(self, goal_request: MoveDistance.Goal) -> GoalResponse:
        """Accept only positive distances and speeds."""
        self.get_logger().info(
            f'收到目标：距离={goal_request.target_distance:.2f} m，'
            f'速度={goal_request.speed:.2f} m/s'
        )

        if goal_request.target_distance <= 0.0 or goal_request.speed <= 0.0:
            self.get_logger().warning('距离和速度必须大于 0，拒绝目标')
            return GoalResponse.REJECT

        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle) -> CancelResponse:
        """Allow a client to cancel a running goal."""
        self.get_logger().info('收到取消请求，允许取消')
        return CancelResponse.ACCEPT

    def handle_accepted_callback(self, goal_handle) -> None:
        """Start executing a goal after it has been accepted."""
        self.get_logger().info('目标已接受，开始执行')
        goal_handle.execute()

    def execute_callback(self, goal_handle) -> MoveDistance.Result:
        """Move in small steps, publishing feedback after every step."""
        request = goal_handle.request
        target_distance = float(request.target_distance)
        speed = float(request.speed)

        current_distance = 0.0
        step_time = 0.2
        step_distance = speed * step_time

        feedback = MoveDistance.Feedback()
        result = MoveDistance.Result()

        try:
            while current_distance < target_distance:
                if goal_handle.is_cancel_requested:
                    goal_handle.canceled()
                    result.final_distance = current_distance
                    result.success = False
                    result.message = '目标已由客户端取消'
                    self.get_logger().info(
                        f'任务取消，停止在 {current_distance:.2f} m'
                    )
                    return result

                current_distance = min(
                    current_distance + step_distance,
                    target_distance,
                )
                feedback.current_distance = current_distance
                feedback.progress_percent = (
                    current_distance / target_distance * 100.0
                )
                goal_handle.publish_feedback(feedback)

                self.get_logger().info(
                    f'移动到 {current_distance:.2f} m，'
                    f'进度 {feedback.progress_percent:.0f}%'
                )
                time.sleep(step_time)

            goal_handle.succeed()
            result.final_distance = current_distance
            result.success = True
            result.message = '机器人已到达目标距离'
            self.get_logger().info('目标完成')
            return result
        except Exception as error:  # Defensive cleanup for a tutorial server.
            goal_handle.abort()
            result.final_distance = current_distance
            result.success = False
            result.message = f'执行异常：{error}'
            self.get_logger().error(result.message)
            return result

    def destroy_node(self) -> None:
        self._action_server.destroy()
        super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = MoveActionServer()
    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        if rclpy.ok():
            node.get_logger().info('收到 Ctrl+C，正在关闭服务端')
    finally:
        executor.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
