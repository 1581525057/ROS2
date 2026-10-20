import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer,GoalResponse,CancelResponse
from my_action_interfaces.action import MoveTo
from rclpy.action.server import ServerGoalHandle
import time

from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

class MoveActionServer(Node):
    def __init__(self):
        super().__init__('move_action_server')
        self.get_logger().info('move_action_server节点启动')
        self.callback_group = ReentrantCallbackGroup() #允许同一个节点进行多个回调

        self.action_server_ = ActionServer(self,MoveTo,'move_to',self.execute_callback,goal_callback=self.goal_callback,cancel_callback=self.cancel_callback,callback_group=self.callback_group)

    #看目标合不合法
    def goal_callback(self, goal_request):
        x = goal_request.target_x
        y = goal_request.target_y
        if x < 0 or x > 10 or y < 0 or y > 10:
            self.get_logger().warn(
                f'拒绝目标：x={x}, y={y} 超出允许范围'
            )
            return GoalResponse.REJECT
        
        self.get_logger().info(f'接受目标：x={x}, y={y}' )
        return GoalResponse.ACCEPT
    
    #取消回调
    def cancel_callback(self, goal_handle):
        self.get_logger().info('收到取消请求，允许取消')
        return CancelResponse.ACCEPT
    
    #处理目标
    def execute_callback(self,goal_handle:ServerGoalHandle):
        if goal_handle.is_cancel_requested:
            self.get_logger().info('任务已取消，停止移动')
            goal_handle.canceled()

        target_x = goal_handle.request.target_x
        target_y = goal_handle.request.target_y
        start_distance = (target_x ** 2 + target_y ** 2) ** 0.5
        self.get_logger().info(f'得到客户端的目标x:{target_x},目标y:{target_y}')

        for step in range(5,-1,-1):
            feedback = MoveTo.Feedback()
            feedback.remaining_distance = start_distance * step / 5
            goal_handle.publish_feedback(feedback)
            self.get_logger().info(
            f'剩余距离：{feedback.remaining_distance:.2f}'
        )
            if step > 0:
                time.sleep(1)
        #标记成功
        goal_handle.succeed()

        result = MoveTo.Result()
        result.success = True
        return result

def main(args=None):
    rclpy.init(args=args)

    node = MoveActionServer()

    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()

