# CHAPT2 — 节点基础

[[ROS2学习地图]] > CHAPT2

仓库路径：`~/ROS2_Repository/CHAPT2/chapt2_ws/`

---

## 本章学了什么

1. 如何创建一个最简单的 ROS2 节点（C++ 和 Python 两种写法）
2. 如何把节点封装成类（面向对象风格）
3. C++ 前置知识：Lambda 表达式、std::function、std::bind

---

## 包结构

```
chapt2_ws/src/
├── demo_cpp_pkg/       ← C++ 包（ament_cmake）
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── src/
│       ├── cpp_node.cpp          ← 最简 C++ 节点
│       ├── person_node.cpp       ← 面向对象节点
│       ├── learn_lambda.cpp      ← Lambda 练习
│       └── learn_funcational.cpp ← std::function 练习
└── demo_python_pkg/    ← Python 包（ament_python）
    └── demo_python_pkg/
        ├── python_node.py        ← 最简 Python 节点
        └── learn_thread.py       ← 多线程下载练习
```

---

## 笔记链接

- [[Node节点]] — 节点概念与基本写法
- [[ROS2工作空间与包结构]] — 工作空间组织
- [[Lambda表达式]] — C++ Lambda 基础
- [[std_function与回调]] — std::function / std::bind 详解
- [[colcon构建]] — 构建命令

---

## 构建与运行

```bash
cd ~/ROS2_Repository/CHAPT2/chapt2_ws
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash

# 运行各节点
ros2 run demo_cpp_pkg cpp_node
ros2 run demo_cpp_pkg person_node
ros2 run demo_python_pkg python_node
```
