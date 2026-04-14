# Topic 话题

[[ROS2学习地图]] | [[Publisher发布者]] | [[Subscriber订阅者]]

---

## 概念

话题（Topic）是 ROS2 节点之间的异步通信通道。

- 发布者（Publisher）向话题发消息
- 订阅者（Subscriber）从话题收消息
- 两者不需要知道彼此存在，松耦合

---

## 话题通信模型

```
Publisher  ──► /topic_name ──►  Subscriber
（任意数量）   （话题是中间人）   （任意数量）
```

---

## 本项目的话题

| 话题名 | 消息类型 | 发布者 | 订阅者 |
|---|---|---|---|
| `/turtle1/cmd_vel` | `geometry_msgs/msg/Twist` | `turtle_circle` | `turtlesim_node` |
| `/novel` | `example_interfaces/msg/String` | `novel_pub_node` | `novel_sub_node` |

---

## 调试命令

```bash
ros2 topic list                    # 列出所有话题
ros2 topic info /turtle1/cmd_vel   # 查看话题的发布者和订阅者
ros2 topic echo /novel             # 实时打印话题消息
ros2 topic hz /turtle1/cmd_vel     # 查看话题发布频率
```

---

## 相关笔记

- [[Publisher发布者]]
- [[Subscriber订阅者]]
- [[消息类型]]
