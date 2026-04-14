# Subscriber 订阅者

[[ROS2学习地图]] | [[Topic话题]] | [[CHAPT3 - Topic通信]]

---

## 概念

订阅者监听某个话题，每当有新消息到来时，自动触发回调函数。

---

## Python 订阅者（含后台线程）

```python
# novel_sub_node.py 完整逻辑
class NovelSubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)

        # 暂存收到但还未朗读的消息
        self.novel_queue_ = Queue()

        # 订阅 novel 话题，回调是 self.novel_callback
        self.novel_sub_ = self.create_subscription(
            String, 'novel', self.novel_callback, 10)

        # 后台朗读线程
        self.speech_thread_ = Thread(target=self.speak_thread)
        self.speech_thread_.daemon = True
        self.speech_thread_.start()

    def novel_callback(self, msg):
        # 只放队列，不直接朗读（避免阻塞回调）
        self.novel_queue_.put(msg.data)

    def speak_thread(self):
        speaker = Speaker()
        speaker.voice = 'zh'
        while rclpy.ok():
            if self.novel_queue_.qsize() > 0:
                text = self.novel_queue_.get()
                speaker.say(text)
                speaker.wait()
            else:
                time.sleep(1)   # 空队列时让出 CPU
```

---

## 关键设计：为什么要用队列 + 后台线程

直接在回调里朗读会阻塞 ROS 事件循环，导致后续消息丢失。
解决方案：

```
novel_callback()  ──put──►  Queue  ──get──►  speak_thread()
（ROS回调，快速返回）        （缓冲区）       （后台线程，慢慢处理）
```

生产者 = `novel_callback`，消费者 = `speak_thread`。
两者通过 `Queue` 解耦，互不阻塞。

---

## 相关笔记

- [[Publisher发布者]]
- [[队列与多线程]]
- [[Timer定时器]]
