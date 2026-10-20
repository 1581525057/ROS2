import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer,GoalResponse,CancelResponse
from rclpy.action.server import ServerGoalHandle

from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from restaurant_interfaces.action import PrepareOrder
import time

class KitchenServer(Node):
    def __init__(self):
        super().__init__('kitchen_node')
        self.get_logger().info('节点kitchen_node启动')

        self.callback_group = ReentrantCallbackGroup()
        self.kitchen_action_server = ActionServer(self,PrepareOrder,'prepare_order',execute_callback = self.execute_callback,goal_callback = self.goal_callback,callback_group=self.callback_group, cancel_callback = self.cancel_callback)

    def goal_callback(self,goal_request):
        self.get_logger().info(f'收到订单请求：{goal_request.order_id}')

        if not goal_request.dishes:
             self.get_logger().info('没有收到菜品要求')
             return GoalResponse.REJECT

        self.get_logger().info(
            f'接受订单 {goal_request.order_id}'
        )
        return GoalResponse.ACCEPT

    def cancel_callback(self,goal_handle):
        self.get_logger().info(
        f'收到订单 {goal_handle.request.order_id} 的取消请求')
        # 接受取消请求
        return CancelResponse.ACCEPT
            
    def execute_callback(self,goal_handle:ServerGoalHandle):
        order_id = goal_handle.request.order_id
        dishes = goal_handle.request.dishes
        total_count = len(dishes)
        self.get_logger().info(f'正在制作订单：{order_id},'
                               f'共{total_count}道菜')

        # 【修正】接口类型名应为 Feedback；原来的 Feedbcak 是拼写错误。
        feedback = PrepareOrder.Feedback()
        for index, dish in enumerate(dishes):
            if goal_handle.is_cancel_requested:
                return self.cancel_order(goal_handle, order_id)
            
            self.get_logger().info(
                f'正在制作：{dish}'
            ) 
            time.sleep(2)
              # 【新增】制作过程中可能收到取消请求，所以等待后再检查一次
            if goal_handle.is_cancel_requested:
                return self.cancel_order(goal_handle, order_id)
                
            feedback.current_dish = dish
            feedback.finished_count = index + 1
            feedback.total_count = total_count
            goal_handle.publish_feedback(feedback)

        goal_handle.succeed()

        result = PrepareOrder.Result()
        result.success = True
        result.message = f'订单 {order_id} 制作完成'

        self.get_logger().info(result.message)

        return result
    
    def cancel_order(self,goal_handle:ServerGoalHandle, order_id):
        goal_handle.canceled()

        result = PrepareOrder.Result()
        result.success = False
        result.message = f'订单 {order_id} 已取消'

        self.get_logger().warning(result.message)

        return result


def main(args = None):
    rclpy.init(args=args)
    node = KitchenServer()

    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        node.destroy_node()
        # 【修正】Humble 收到 Ctrl+C 时可能已自动 shutdown，避免重复关闭报错。
        if rclpy.ok():
            rclpy.shutdown()


        


