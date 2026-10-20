from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.action.client import ClientGoalHandle
from my_action_interfaces.action import MoveTo
import rclpy

class MoveActionClient(Node):

    def __init__(self):
        super().__init__('move_action_client')
        self.get_logger().info('move_action_client节点启动')

        self._action_client = ActionClient(self,MoveTo,'move_to')

        self._goal_handle = None
        self._cancel_requested = False

    def send_goal(self):
        goal_msg = MoveTo.Goal()
        goal_msg.target_x = 2.0
        goal_msg.target_y = 3.0
        if not self._action_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('5 秒内没有找到 /move_to 服务端')
            return
        
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback )

    def goal_response_callback(self, future):
        goal_handle:ClientGoalHandle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal 被服务端拒绝')
            rclpy.shutdown() #拒绝后干净退出
            return
        self.get_logger().info('Goal 被服务端接受')

        self._goal_handle = goal_handle

        self._get_result_future = goal_handle.get_result_async()

        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result_response = future.result() #不是MoveTo类型的

        result = result_response.result

        self.get_logger().info(f'最终结果：success={result.success}')

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback

        self.get_logger().info(
            f'收到 Feedback：剩余距离 = {feedback.remaining_distance}'
        )

        # 只在第一次收到反馈时请求取消
        if not self._cancel_requested:
            self._cancel_requested = True

            self.get_logger().info('请求取消任务')

            self._cancel_future = self._goal_handle.cancel_goal_async()
            self._cancel_future.add_done_callback(
                self.cancel_done_callback
            )
    
    def cancel_done_callback(self, future):
        cancel_response = future.result()

        if cancel_response.goals_canceling:
            self.get_logger().info('服务端已接受取消请求')
        else:
            self.get_logger().info('服务端拒绝取消请求')

def main(args=None):
    rclpy.init(args=args)
    action_client = MoveActionClient()
    action_client.send_goal()
    rclpy.spin(action_client)
    rclpy.shutdown()