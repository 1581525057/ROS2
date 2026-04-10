import rclpy
from queue import Queue

import requests
from example_interfaces.msg import String
from rclpy.node import Node


class NovelPubNode(Node):
    def __init__(self, node_name):
        # 调用父类 Node 的构造函数。
        # 这一句执行后，这个 Python 类对象才真正变成一个 ROS 2 节点。
        super().__init__(node_name)

        # 打印一条日志，表示节点启动了。
        self.get_logger().info(f"{node_name}启动")

        # 创建一个队列，用来临时存放“还没发布出去的小说内容”。
        #
        # 可以把队列理解成“排队区”：
        # 1. download() 负责把文本一行一行放进去
        # 2. timer_callback() 负责每次取一行出来发布
        #
        # 为什么要用队列：
        # 因为下载文本是一次性完成的，但发布消息想要慢慢发，
        # 所以需要一个中间容器把“准备好的数据”先存起来。
        self.novels_queue_ = Queue()

        # 创建一个发布者。
        # 含义：
        # 1. 消息类型是 String
        # 2. 话题名是 'novel'
        # 3. 队列深度是 10（ROS 2 通信层自己的缓存长度）
        #
        # 注意：这里的 10 不是上面的 Queue()，两者不是一回事。
        # Queue() 是你自己代码里的 Python 队列；
        # create_publisher(..., 10) 里的 10 是 ROS 2 发布器的缓冲配置。
        self.novel_publisher_ = self.create_publisher(String, "novel", 10)

        # 创建一个定时器，每隔 5 秒自动调用一次 self.timer_callback。
        #
        # 为什么要定时器：
        # 因为这个例子不是想“一下子把整本小说全部发完”，
        # 而是想“每隔几秒发一行”，这样更容易观察话题消息的发布过程。
        self.create_timer(5, self.timer_callback)

    def timer_callback(self):
        # 定时器每 5 秒会进入这个函数一次。
        #
        # 这里先判断：队列里还有没有没发出去的内容。
        if self.novels_queue_.qsize() > 0:
            # 从队列头部取出一行文本。
            # get() 取出来后，这一行就不在队列里了。
            line = self.novels_queue_.get()

            # 创建一个 ROS 2 的字符串消息对象。
            msg = String()

            # 把刚才取出的那一行文本，放到消息的 data 字段里。
            msg.data = line

            # 把消息发布到 'novel' 这个话题上。
            self.novel_publisher_.publish(msg)

            # 打印日志，方便你看到当前发了什么。
            self.get_logger().info(f"发布了:{msg}")

    def download(self, url):
        # requests.get(url) 会向这个地址发起 HTTP 请求，把文本下载下来。
        response = requests.get(url)

        # 告诉 requests 按 utf-8 解码，否则中文可能乱码。
        response.encoding = 'utf-8'

        # response.text 就是下载到的完整文本内容。
        text = response.text

        # 打日志：下载了哪个地址，文本总长度是多少字符。
        self.get_logger().info(f"下载{url},{len(text)}")

        # splitlines() 会把整段文本按“行”拆开。
        # 例如：
        # "aaa\nbbb\nccc"
        # 会变成：
        # ["aaa", "bbb", "ccc"]
        for line in text.splitlines():
            # 把每一行都放进队列。
            #
            # 到这里为止，只是“存起来”，还没有真正发布。
            # 真正发布是在 timer_callback() 里，由定时器慢慢取出来发。
            self.novels_queue_.put(line)


def main():
    # 初始化 rclpy。写 ROS 2 Python 节点时，通常第一步就是它。
    rclpy.init()

    # 创建我们自己写的节点对象。
    node = NovelPubNode("novel_pub")

    # 先把小说文本下载下来，并放入队列。
    # 这一步做完后，队列里已经有很多行文本在排队了。
    node.download("http://127.0.0.1:8000/novel1.txt")

    # 让节点一直运行，持续处理各种回调。
    #
    # 这里最关键的作用是：
    # 让前面创建的定时器真正开始工作。
    # 如果没有 spin()，程序会很快结束，定时器就来不及每 5 秒触发一次。
    #
    # 可以粗暴理解为：
    # “别退出，让这个节点一直活着，并不断处理事件。”
    rclpy.spin(node)

    # 程序结束前关闭 rclpy。
    rclpy.shutdown()
