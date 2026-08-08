import time

import rclpy
from action_interfaces.action import Patrol #应用我的自定义文件
from rclpy.action import ActionServer, CancelResponse #导入服务端和取消响应
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node #导入节点
from rclpy.action import GoalResponse 

class PatrolActionServer(Node):
    def __init__(self):
        super().__init__('Patrol_Server')
        self.callback_group = ReentrantCallbackGroup()
        self.patrol_action_server = ActionServer(
            self,Patrol,'patrol',self.handle_patrol_action_server,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            callback_group=self.callback_group
                                                 )
        self.get_logger().info('服务器Server启动')

    def goal_callback(self,goal_request:Patrol.Goal) ->GoalResponse:
        if not goal_request.target_name.strip():
            return GoalResponse.REJECT
        if not 1<= goal_request.total_steps <=100:
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def cancel_callback(self,goal_handle) ->CancelResponse:
        self.get_logger().info('收到取消请求，允许取消任务')
        return CancelResponse.ACCEPT

    def handle_patrol_action_server(self,goal_handle):
        request = goal_handle.request
        feedback = Patrol.Feedback()
    
        for step in range(1,(request.total_steps + 1)):
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                result = Patrol.Result()
                result.success = False
                result.message = '巡逻任务已取消'
                return result

            feedback.current_step = step
            feedback.progress = step / request.total_steps * 1
            feedback.state = f'正在前往目的地{request.target_name}'
            goal_handle.publish_feedback(feedback)
            time.sleep(0.5)

        result = Patrol.Result()
        result.success = True
        result.message = '已经到达目的地'

       
        goal_handle.succeed()
        return result

def main():
    rclpy.init()
    node = PatrolActionServer()
    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(node)

    try:
        executor.spin()

    finally:
        executor.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()




        

           



