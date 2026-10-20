from collections import deque

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle
from std_srvs.srv import Trigger
from restaurant_interfaces.msg import FoodOrder
from restaurant_interfaces.action import PrepareOrder

class Cashier(Node):
    def __init__(self):
        super().__init__("cashier_node")
        self.get_logger().info('节点cashier_node启动')

        # 保存等待中的订单
        self.order_queue = deque()
        # 厨房当前是否正在处理订单
        self.kitchen_busy = False
        # 当前正在处理的订单
        self.current_order = None

        # 【新增】保存厨房已接受的 Goal，取消时必须通过它发送请求。
        self.current_goal_handle = None
        # 【新增】防止对同一个订单重复发送取消请求。
        self.cancel_requested = False

        self.food_subscriber = self.create_subscription(
            FoodOrder,
            '/new_order',
            self.handle_customer_food,
            10
        )

        # 【修改】这是 Action 客户端，不是 Service，改名后更容易分清通信类型。
        self.kitchen_action_client = ActionClient(
            self,
            PrepareOrder,
            '/prepare_order'
        )

        # 【修改】定时重试发送，避免厨房晚启动时队列中的订单永远卡住。
        self.retry_timer = self.create_timer(0.5, self.send_next_order)

        # 【新增】用 Service 作为“取消当前订单”的外部入口。
        self.cancel_service = self.create_service(
            Trigger,
            '/cashier/cancel_current_order',
            self.cancel_current_order_callback
        )

    def handle_customer_food(self, msg):
        # 把完整订单放到队尾
        self.order_queue.append(msg)

        # 【修改】合并日志文本，让订单号和队列长度在同一条消息中显示。
        self.get_logger().info(
            f'收到订单 {msg.order_id}，'
            f'等待订单数：{len(self.order_queue)}'
        )

        # 尝试发送队首订单
        self.send_next_order()

    def send_next_order(self):
        """厨房空闲时发送下一单。"""
        if self.kitchen_busy:
            return

        # 队列为空
        if not self.order_queue:
            return

        # 【修改】只做非阻塞检查；服务端未启动时由上面的定时器稍后重试。
        if not self.kitchen_action_client.server_is_ready():
            return

        # 从队首取出订单
        self.current_order = self.order_queue.popleft()
        self.kitchen_busy = True

        goal_msg = PrepareOrder.Goal()
        goal_msg.order_id = self.current_order.order_id
        goal_msg.dishes = self.current_order.dishes

        self.get_logger().info(
            f'正在向厨房发送订单 {goal_msg.order_id}'
        )

        # 【修改】通过 Action 客户端异步发送 Goal，同时注册 Feedback 回调。
        self.send_goal_future = self.kitchen_action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self.send_goal_future.add_done_callback(
            self.goal_response_callback
        )

    def goal_response_callback(self, future):
        goal_handle: ClientGoalHandle = future.result()

        if not goal_handle.accepted:
            self.get_logger().info(f'厨房拒绝了这一单，id号：{self.current_order.order_id}')

            # 【修改】被拒绝也要释放“忙碌”状态，否则后续订单永远不会发送。
            self.finish_current_order()
            return

        self.get_logger().info(
            f'厨房接受订单 {self.current_order.order_id}'
        )

        # 【新增】只有厨房接受 Goal 后，才能保存 handle 并对它发出取消请求。
        self.current_goal_handle = goal_handle
        self.cancel_requested = False

        self.result_future = goal_handle.get_result_async()
        self.result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result_response = future.result()
        result = result_response.result

        # 【修改】Logger.info() 只传入一条完整文本，避免多传一个位置参数。
        self.get_logger().info(
            f'制作结果：{result.success}，消息：{result.message}'
        )

        # 【修改】当前订单结束后自动启动队列中的下一单。
        self.finish_current_order()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        # 【修改】current_dish 是“当前菜品”，不是订单号。
        self.get_logger().info(
            f'当前菜品：{feedback.current_dish}，'
            f'已经完成：{feedback.finished_count}，'
            f'总数：{feedback.total_count}'
        )

    # 【新增】终端调用该 Service 时，向当前 Action Goal 发送取消请求。
    def cancel_current_order_callback(self, request, response):
        del request

        if self.current_goal_handle is None:
            response.success = False
            response.message = '当前没有正在制作的订单'
            return response

        if self.cancel_requested:
            response.success = False
            response.message = '已经发送过取消请求，正在等待厨房处理'
            return response

        self.cancel_requested = True
        order_id = self.current_order.order_id

        self.get_logger().info(
            f'正在请求取消订单 {order_id}'
        )

        self.cancel_future = self.current_goal_handle.cancel_goal_async()
        self.cancel_future.add_done_callback(
            self.cancel_response_callback
        )

        # Service 只说明请求已发出，最终是否取消要等 Action 服务端回复。
        response.success = True
        response.message = f'订单 {order_id} 的取消请求已发送'
        return response

    # 【新增】处理厨房对取消请求的回复。
    def cancel_response_callback(self, future):
        cancel_response = future.result()

        if cancel_response.goals_canceling:
            self.get_logger().info('厨房已接受取消请求')
        else:
            self.get_logger().warning('厨房拒绝了取消请求')
            self.cancel_requested = False

    # 【修改】统一收尾：清空当前订单、恢复空闲，再处理下一单。
    def finish_current_order(self):
        self.current_order = None
        # 【新增】订单结束后清理 Goal handle 和取消状态。
        self.current_goal_handle = None
        self.cancel_requested = False
        self.kitchen_busy = False
        self.send_next_order()


def main(args=None):
    rclpy.init(args=args)
    node = Cashier()

    # 【修改】按 Ctrl+C 退出时也会销毁节点并正常关闭 rclpy。
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        # 【修正】Humble 收到 Ctrl+C 时可能已自动 shutdown，避免重复关闭报错。
        if rclpy.ok():
            rclpy.shutdown()

# 【修改】补上程序入口，否则直接运行该文件时 main() 不会执行。
if __name__ == '__main__':
    main()
