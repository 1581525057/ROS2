# Publisher 发布者

[[ROS2学习地图]] | [[Topic话题]] | [[CHAPT3 - Topic通信]]

---

## 概念

发布者向某个话题持续发送消息。
订阅了该话题的节点会自动收到消息。

---

## C++ 发布者（配合 Timer）

```cpp
// turtle_circle.cpp 核心结构
class Turtle_CircleNode : public rclcpp::Node
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

public:
    explicit Turtle_CircleNode(const std::string &node_name)
    : Node(node_name)
    {
        // 创建发布者：消息类型 Twist，话题名，队列深度
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(
            "/turtle1/cmd_vel", 10);

        // 每 1000ms 触发一次回调
        timer_ = this->create_wall_timer(
            1000ms, std::bind(&Turtle_CircleNode::timer_callback, this));
    }

    void timer_callback()
    {
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = 1.0;    // 前进速度
        msg.angular.z = 0.5;   // 旋转速度 → 合成圆周运动
        publisher_->publish(msg);
    }
};
```

Timer 的两种绑定方式：
- `std::bind(&Class::method, this)` — 标准写法（turtle_circle.cpp）
- `[this]() { timer_callback(); }` — Lambda 写法（turtle_circle_yezi.cpp）

---

## Python 发布者（配合 Timer）

```python
# novel_pub_node.py 核心结构
class NovelPubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.novels_queue_ = Queue()

        # 创建发布者：消息类型 String，话题名 'novel'，队列深度 10
        self.novel_publisher_ = self.create_publisher(String, "novel", 10)

        # 每 5 秒触发一次
        self.create_timer(5, self.timer_callback)

    def timer_callback(self):
        if self.novels_queue_.qsize() > 0:
            line = self.novels_queue_.get()
            msg = String()
            msg.data = line
            self.novel_publisher_.publish(msg)
```

---

## 两种发布者对比

| 项目 | C++ | Python |
|---|---|---|
| 创建方法 | `create_publisher<Type>(topic, qos)` | `create_publisher(Type, topic, qos)` |
| 发送方法 | `publisher_->publish(msg)` | `self.publisher_.publish(msg)` |
| 定时器 | `create_wall_timer(duration, callback)` | `create_timer(seconds, callback)` |

---

## 相关笔记

- [[Subscriber订阅者]]
- [[Timer定时器]]
- [[消息类型]]
- [[队列与多线程]]
