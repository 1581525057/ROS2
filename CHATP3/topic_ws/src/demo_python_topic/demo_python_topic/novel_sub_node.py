from queue import Queue
import espeakng
import rclpy
from example_interfaces.msg import String
from rclpy.node import Node
from threading import Thread
import time

class NovelSubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info(f"{node_name}启动")

        # 这个队列用来暂存“已经收到、但还没来得及朗读”的消息。
        # 可以把它理解成排队区：
        # 1. novel_callback() 负责把新消息放进来
        # 2. speak_thread() 负责从这里一条一条取出来朗读
        self.novel_queue_ = Queue()

        # 订阅 novel 话题。
        # 只要有新消息到达，就会自动调用 self.novel_callback。
        self.novel_sub_ = self.create_subscription(String,'novel',self.novel_callback,10)

        # 创建一条后台线程，入口函数是 self.speak_thread。
        # 这条线程的职责不是接收 ROS 消息，而是专门负责“慢慢朗读”。
        #
        # 为什么要单独开线程：
        # 朗读是耗时操作，如果直接在 novel_callback() 里朗读，
        # 那么回调函数会被阻塞，新的消息处理也会被拖慢。
        # 现在改成：
        # 1. 回调函数只负责收消息并放进队列
        # 2. 后台线程再从队列里取消息并朗读
        # 这样“接收消息”和“朗读消息”就拆开了。
        self.speech_thread_ = Thread(target=self.speak_thread)

        # 启动后台朗读线程。
        # start() 之后，self.speak_thread() 会在另一条线程里一直运行。
        self,self.speech_thread_.start()

    def novel_callback(self,msg):
        # 收到一条小说消息后，不在这里直接朗读，
        # 只把消息放进队列，然后立刻返回。
        # 这样订阅回调就不会被“朗读很慢”这件事卡住。
        self.novel_queue_ .put(msg)

    def speak_thread(self):
        # 真正负责朗读的函数。
        # 注意：这个函数不是由 ROS 回调直接调用的，
        # 而是由上面的 speech_thread_ 在线程里后台执行。
        speaker = espeakng.Speaker()
        speaker.voice = 'zh'

        # 只要 ROS 还在运行，这条线程就一直循环检查队列。
        while rclpy.ok():
            if self.novel_queue_.qsize()>0:
                # 队列里有消息时，取出一条并朗读。
                # 这里和 novel_callback() 形成“生产者-消费者”关系：
                # 1. novel_callback() 负责往队列里放
                # 2. speak_thread() 负责从队列里取
                text = self.novel_queue_.get()
                self.get_logger().info(f'朗读：{text}')
                speaker.say(text)
                speaker.wait()
            else:
                # 队列为空时先睡一会，避免空转占用太多 CPU。
                time.sleep(1)


def main():
    rclpy.init()
    node = NovelSubNode('novel_sub')
    rclpy.spin(node)
    rclpy.shutdown()

 
