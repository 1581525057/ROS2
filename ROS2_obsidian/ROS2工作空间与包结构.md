# ROS2 工作空间与包结构

[[ROS2学习地图]] | [[colcon构建]]

---

## 工作空间目录结构

```
my_ws/                    ← 工作空间根目录
├── src/                  ← 所有包都放这里
│   ├── my_cpp_pkg/       ← C++ 包（ament_cmake）
│   │   ├── CMakeLists.txt
│   │   ├── package.xml
│   │   └── src/
│   │       └── my_node.cpp
│   └── my_python_pkg/    ← Python 包（ament_python）
│       ├── package.xml
│       ├── setup.py
│       └── my_python_pkg/
│           └── my_node.py
├── build/                ← colcon 构建输出（自动生成）
├── install/              ← 安装目录（自动生成）
└── log/                  ← 构建日志（自动生成）
```

---

## C++ 包关键文件

### package.xml

```xml
<package format="3">
  <name>demo_cpp_topic</name>
  <buildtool_depend>ament_cmake</buildtool_depend>
  <depend>rclcpp</depend>
  <depend>geometry_msgs</depend>
  <export>
    <build_type>ament_cmake</build_type>
  </export>
</package>
```

### CMakeLists.txt

```cmake
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(turtle_circle src/turtle_circle.cpp)
ament_target_dependencies(turtle_circle rclcpp geometry_msgs)

install(TARGETS turtle_circle
        DESTINATION lib/${PROJECT_NAME})
ament_package()
```

---

## Python 包关键文件

### package.xml

```xml
<package format="3">
  <name>demo_python_topic</name>
  <buildtool_depend>ament_python</buildtool_depend>
  <depend>rclpy</depend>
  <export>
    <build_type>ament_python</build_type>
  </export>
</package>
```

---

## 两种包类型对比

| 项目 | C++ 包 | Python 包 |
|---|---|---|
| 构建系统 | ament_cmake | ament_python |
| 编译配置 | CMakeLists.txt | setup.py |
| 节点库 | rclcpp | rclpy |
| 需要编译 | 是 | 否 |

---

## 相关笔记

- [[colcon构建]]
- [[Node节点]]
