import signal

import rclpy
from action_interfaces.action import Patrol
from rclpy.action.client import ClientGoalHandle
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions

class PatrolClient(Node):
    def __init__(self):
        super().__init__('Patrol_Client')
        self.patrol_sever = ActionClient(
            self,Patrol,'patrol'
        )
        self.goal_handle = None
        self.cancel_requested = False
        self.cancel_sent = False
        self.done = False
        self.cancel_timer = self.create_timer(0.1,self.check_cancel_request)

    def send_goal(self,target_name,total_steps):
        self.get_logger().info('等待服务器启动')
        if not self.patrol_sever.wait_for_server(timeout_sec=10):
            self.get_logger().error('未找到服务器')
            self.done = True
            return

        Goal = Patrol.Goal()
        Goal.target_name = target_name
        Goal.total_steps = total_steps

        fu = self.patrol_sever.send_goal_async(Goal,self.feedback_idea)
        fu.add_done_callback(self.server_idea)
        

    def server_idea(self,future):
        self.goal_handle : ClientGoalHandle = future.result()
        if not self.goal_handle.accepted:
            self.get_logger().info('服务端拒绝了任务')
            self.done = True
            return
        else:
            self.get_logger().info('服务器接受了任务')
            
        result_future = self.goal_handle.get_result_async()
        result_future.add_done_callback(self.result_idea)

    def request_cancel(self):
        # SIGINT 回调只设置标志，ROS API 留给定时器回调调用。
        self.cancel_requested = True

    def check_cancel_request(self):
        if not self.cancel_requested or self.cancel_sent:
            return
        if self.goal_handle is None:
            return

        self.cancel_sent = True
        self.get_logger().info('客户端正在发送取消请求')
        cancel_future = self.goal_handle.cancel_goal_async()
        cancel_future.add_done_callback(self.cancel_response)

    def cancel_response(self,future):
        response = future.result()
        if response.goals_canceling:
            self.get_logger().info('服务端接受了取消请求')
        else:
            self.get_logger().warning('服务端拒绝了取消请求')

    def feedback_idea(self,feedback_msg):
       feedback = feedback_msg.feedback
       self.get_logger().info(f'当前任务步数为：{feedback.current_step}')
       self.get_logger().info(f'当前进度为：{feedback.progress}')
       self.get_logger().info(feedback.state)

    def result_idea(self,result_msg):
        result_response = result_msg.result()
        result = result_response.result    # 读取响应对象的属性
        if not result.success:
            self.get_logger().warning(f'任务未成功：{result.message}')
            self.done = True
            return
        self.get_logger().info('任务成功')
        self.get_logger().info(f'信息为:{result.message}')
        self.done = True

def main():
    rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    node = PatrolClient()

    def handle_ctrl_c(signum,frame):
        node.request_cancel()

    old_signal_handler = signal.signal(signal.SIGINT,handle_ctrl_c)

    try:
        node.send_goal('Moon',50)
        while rclpy.ok() and not node.done:
            rclpy.spin_once(node,timeout_sec=0.1)

    finally:
        signal.signal(signal.SIGINT,old_signal_handler)
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

        



        
    



        
    
