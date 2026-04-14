# CHAPT3 — Topic 话题通信

[[ROS2学习地图]] > CHAPT3

仓库路径：`~/ROS2_Repository/CHATP3/topic_ws/`

---

## 本章学了什么

1. ROS2 Topic 的发布-订阅模型
2. C++ Publisher + Timer 控制 turtlesim 小海龟画圆
3. Python Publisher + Subscriber 实现小说文本发布与语音订阅
4. 队列 + 后台线程解耦"接收消息"与"耗时处理"

---

## 通信架构

```
demo_cpp_topic
  turtle_circle ──► /turtle1/cmd_vel (Twist) ──► turtlesim_node

demo_python_topic
  [novel1.txt HTTP服务]
       │
  novel_pub_node ──► /novel (String) ──► novel_sub_node ──► espeak-ng
```

---

## 包结构

```
topic_ws/src/
├── demo_cpp_topic/
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── src/
│       ├── turtle_circle.cpp        ← 标准写法（std::bind）
│       └── tutrtle_circle_yezi.cpp  ← Lambda 写法（练习版）
└── demo_python_topic/
    └── demo_python_topic/
        ├── novel_pub_node.py         ← 发布者 + 队列
        ├── novel_sub_node.py         ← 订阅者 + 后台朗读线程
        └── _espeakng.py              ← 语音引擎封装
```

---

## 笔记链接

- [[Publisher发布者]] — C++ / Python 发布者写法
- [[Subscriber订阅者]] — Python 订阅者写法
- [[Timer定时器]] — 定时触发回调
- [[消息类型]] — Twist / String
- [[队列与多线程]] — Queue + Thread 解耦模式
- [[colcon构建]] — 构建命令

---

## 构建与运行

```bash
cd ~/ROS2_Repository/CHATP3/topic_ws
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash

# 终端1：启动小海龟仿真
ros2 run turtlesim turtlesim_node

# 终端2：让小海龟画圆（标准版）
ros2 run demo_cpp_topic turtle_circle

# 终端2（可选）：叶子练习版，速度更快
ros2 run demo_cpp_topic turtle_circle_yezi

# 小说发布-订阅：
# 终端1：启动文本 HTTP 服务
cd topic_ws && python3 -m http.server 8000

# 终端2：订阅并朗读
ros2 run demo_python_topic novel_sub_node

# 终端3：发布小说
ros2 run demo_python_topic novel_pub_node
```
