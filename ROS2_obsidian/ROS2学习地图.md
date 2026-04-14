# ROS2 学习地图

> 这是我的 ROS2 学习知识图谱，所有笔记都从这里出发。
> 仓库路径：`~/ROS2_Repository`

---

## 学习路径

```
CHAPT2 — 节点基础
  ├── C++ 节点写法
  ├── Python 节点写法
  └── C++ 前置知识（Lambda / std::function）

CHAPT3 — Topic 通信
  ├── 发布者 Publisher
  ├── 订阅者 Subscriber
  ├── 定时器 Timer
  └── 队列 + 多线程解耦
```

---

## 章节索引

- [[CHAPT2 - 节点基础]]
- [[CHAPT3 - Topic通信]]

## 核心概念索引

- [[ROS2工作空间与包结构]]
- [[Node节点]]
- [[Topic话题]]
- [[Publisher发布者]]
- [[Subscriber订阅者]]
- [[Timer定时器]]
- [[消息类型]]
- [[队列与多线程]]
- [[colcon构建]]

## C++ 前置知识

- [[Lambda表达式]]
- [[std_function与回调]]

---

## 快速命令速查

```bash
# 环境配置
source /opt/ros/humble/setup.bash
source install/setup.bash

# 构建
colcon build
colcon build --packages-select <pkg>

# 运行
ros2 run <pkg> <node>

# 调试
ros2 node list
ros2 topic list
ros2 topic echo /topic_name
ros2 topic info /topic_name
```

---

*每次学新章节后，更新本地图，添加新的笔记链接。*
