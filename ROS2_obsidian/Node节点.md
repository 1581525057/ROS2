# Node 节点

[[ROS2学习地图]]

---

## 什么是节点

节点（Node）是 ROS2 中最基本的执行单元。
每个节点是一个独立进程（或线程），有自己的名字，通过话题/服务/动作与其他节点通信。

---

## C++ 最简节点

```cpp
// cpp_node.cpp
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("cpp_node");
    RCLCPP_INFO(node->get_logger(), "C++节点");
    rclcpp::spin(node);
    return 0;
}
```

关键步骤：
1. `rclcpp::init(argc, argv)` — 初始化 ROS2
2. `std::make_shared<rclcpp::Node>("名字")` — 创建节点
3. `rclcpp::spin(node)` — 保持运行，处理事件
4. `rclcpp::shutdown()` — 关闭（可选，程序退出时自动执行）

---

## C++ 面向对象节点（推荐写法）

```cpp
// person_node.cpp
class PersonNode : public rclcpp::Node
{
public:
    PersonNode(const std::string &node_name, const std::string &name, int age)
        : Node(node_name)           // ← 调用父类构造，传入节点名
    {
        this->name = name;
        this->age_ = age;
    }

    void eat(const std::string &food) {
        RCLCPP_INFO(get_logger(), "我是%s,%d岁,爱吃%s",
                    name.c_str(), age_, food.c_str());
    }

private:
    std::string name;
    int age_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PersonNode>("person_node", "叶子", 20);
    node->eat("帝王蟹");
    rclcpp::spin(node);
    rclcpp::shutdown();
}
```

继承 `rclcpp::Node` 的好处：
- 在类内部直接调用 `get_logger()`、`create_publisher()`、`create_timer()` 等方法
- 节点资源（发布者、定时器等）随对象生命周期自动管理

---

## Python 最简节点

```python
# python_node.py
import rclpy
from rclpy.node import Node

def main():
    rclpy.init()
    node = Node('python_node')
    node.get_logger().info('Python 节点已启动')
    rclpy.spin(node)
    rclpy.shutdown()
```

---

## 常用命令

```bash
ros2 node list          # 列出所有运行中的节点
ros2 node info /节点名   # 查看节点的话题、服务信息
```

---

## 相关笔记

- [[Publisher发布者]]
- [[Subscriber订阅者]]
- [[Timer定时器]]
- [[ROS2工作空间与包结构]]
