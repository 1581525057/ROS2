# ROS2 + Qt 系统状态显示节点入门到实践：`sys_status_display`

这份笔记是给 ROS2 和 C++ 初学者看的。目标不是只让你把代码复制过去，而是让你知道：

- 这个 Qt 窗口程序在 ROS2 系统里扮演什么角色
- `#include <rclcpp/rclcpp.hpp>`、`#include <status_interfaces/msg/system_status.hpp>` 为什么这样写
- `rclcpp::Node`、订阅者、回调函数、`spin` 分别是什么
- lambda 函数 `[&](...) { ... }` 到底是什么意思
- `std::shared_ptr`、`std::make_shared`、`SharedPtr` 为什么经常出现在 ROS2 C++ 代码里
- Qt 的 `QApplication`、`QLabel` 和 ROS2 的 `rclcpp::spin()` 为什么要放在两个线程里
- `CMakeLists.txt` 为什么必须写 `find_package`、`add_executable`、`target_link_libraries`、`ament_target_dependencies`、`install`
- 遇到 includePath、CMake、链接错误时应该怎么查

当前工作区：

```text
/home/li/ROS2_Repository/CHATP3/topic_practice_ws
```

当前显示节点所在功能包：

```text
src/status_display
```

当前核心源码：

```text
src/status_display/src/sys_status_display.cpp
```

当前程序的作用：

```text
订阅 /sys_status 话题
接收 status_interfaces/msg/SystemStatus 消息
把 CPU、内存、网络等状态显示到 Qt 窗口 QLabel 里
```

---

## 0. 先看总图

你现在已经有一个发布者节点：

```text
status_publisher 包里的 sys_status_pub
```

它负责发布系统状态。

现在这个新节点是订阅者：

```text
status_display 包里的 sys_status_display
```

两个节点之间的关系是：

```text
发布者节点                              话题                              订阅者节点

sys_status_pub  ───────────────>  /sys_status  ───────────────>  sys_status_display
采集电脑状态                       数据通道                         Qt 窗口显示数据
```

再加上消息类型：

```text
发布者节点                              话题                              订阅者节点

sys_status_pub  ───────────────>  /sys_status  ───────────────>  sys_status_display
                                  SystemStatus
```

三个条件必须匹配：

```text
话题名一样：/sys_status
消息类型一样：status_interfaces/msg/SystemStatus
发布者正在运行，订阅者才能收到新数据
```

---

## 1. 当前功能包结构

你的 `status_display` 是一个 C++ 功能包，结构大致是：

```text
src/status_display/
├── CMakeLists.txt
├── package.xml
└── src/
    └── sys_status_display.cpp
```

这三个文件的分工：

| 文件 | 作用 |
| --- | --- |
| `sys_status_display.cpp` | 真正的 C++ 源码，写节点逻辑和 Qt 窗口 |
| `CMakeLists.txt` | 告诉 colcon/CMake 怎么编译、链接、安装这个程序 |
| `package.xml` | 告诉 ROS2 这个包依赖哪些东西 |

初学者要先记住一句话：

```text
C++ 代码写得对，只代表源码对。
CMakeLists.txt 写得对，程序才知道怎么编译。
package.xml 写得对，ROS2 才知道这个包依赖什么。
```

---

## 2. 完整代码先整体看一遍

你的当前代码核心如下：

```cpp
#include <QApplication>
#include <QLabel>
#include <QString>
#include <rclcpp/rclcpp.hpp>
#include <status_interfaces/msg/system_status.hpp>

using SystemStatus = status_interfaces::msg::SystemStatus;

class SysStatusDisplay : public rclcpp::Node {

  private:
    rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
    QLabel *lable_;

  public:
    SysStatusDisplay() : Node("sys_status_display") {
        lable_ = new QLabel();
        subscriber_ = this->create_subscription<SystemStatus>("sys_status", 10, [&](const SystemStatus::SharedPtr msg) -> void {
            lable_->setText(get_qstr_from_msg(msg));
        });
        lable_->setText(get_qstr_from_msg(std::make_shared<SystemStatus>()));
        lable_->show();
    }

    QString get_qstr_from_msg(const SystemStatus::SharedPtr msg) {
        std::stringstream show_str;
        show_str << "新提供状态可视化工具\n"
                 << "数据时间：\t" << msg->stamp.sec << "\ts\n"
                 << "主机名字：\t" << msg->host_name << "\t\n"
                 << "CPU使用率:\t" << msg->cpu_percent << "\t%\n"
                 << "内存使用率：\t" << msg->memory_percent << "\t%\n"
                 << "内存总大小：\t" << msg->memory_total << "\tMB\n"
                 << "剩余有效内存：\t" << msg->memory_available << "\tMB\n"
                 << "网络发送量：\t" << msg->net_sent << "\tMB\n"
                 << "网络接收量：\t" << msg->net_recv << "\tMB\n";
        return QString::fromStdString(show_str.str());
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    QApplication app(argc, argv);
    auto node = std::make_shared<SysStatusDisplay>();
    std::thread spin_thread([&]() -> void {
        rclcpp::spin(node);
    });
    spin_thread.detach();
    app.exec();
    return 0;
}
```

先不用急着全部看懂。可以先用一句话理解：

```text
这个程序启动一个 ROS2 节点，同时启动一个 Qt 窗口。
ROS2 收到 /sys_status 消息后，回调函数把消息转成 QString，再显示到 QLabel 上。
```

---

## 3. `#include` 是什么

C++ 的 `#include` 可以理解成：

```text
我要使用某个库里的类或函数，请把对应声明包含进来。
```

你的代码里有两类 include。

第一类是 Qt：

```cpp
#include <QApplication>
#include <QLabel>
#include <QString>
```

它们分别提供：

| 头文件 | 提供什么 |
| --- | --- |
| `QApplication` | Qt 图形界面程序的入口管理器 |
| `QLabel` | 一个可以显示文字的标签控件 |
| `QString` | Qt 自己的字符串类型 |

第二类是 ROS2：

```cpp
#include <rclcpp/rclcpp.hpp>
#include <status_interfaces/msg/system_status.hpp>
```

它们分别提供：

| 头文件 | 提供什么 |
| --- | --- |
| `rclcpp/rclcpp.hpp` | ROS2 C++ 客户端库，提供节点、发布者、订阅者、spin 等 |
| `status_interfaces/msg/system_status.hpp` | 你自定义的 `SystemStatus` 消息类型 |

### 3.1 为什么是 `system_status.hpp`

你的消息文件叫：

```text
src/status_interfaces/msg/SystemStatus.msg
```

ROS2 生成 C++ 头文件时，会把大驼峰命名转换成小写加下划线：

```text
SystemStatus.msg
```

生成：

```text
system_status.hpp
```

所以 C++ 里这样包含：

```cpp
#include <status_interfaces/msg/system_status.hpp>
```

不要写成：

```cpp
#include <status_interfaces/msg/SystemStatus.hpp>
```

也不要写成：

```cpp
#include <status_interfaces>
```

---

## 4. `using SystemStatus = ...` 是什么

代码：

```cpp
using SystemStatus = status_interfaces::msg::SystemStatus;
```

这叫类型别名。

原始完整类型名很长：

```cpp
status_interfaces::msg::SystemStatus
```

它的含义是：

```text
status_interfaces 包
里面的 msg 命名空间
里面的 SystemStatus 消息类型
```

如果每次都写完整名字，代码会很长：

```cpp
rclcpp::Subscription<status_interfaces::msg::SystemStatus>::SharedPtr subscriber_;
```

所以用 `using` 起一个短名字：

```cpp
using SystemStatus = status_interfaces::msg::SystemStatus;
```

之后就可以写：

```cpp
rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
```

它们是同一个意思。

---

## 5. 类 `SysStatusDisplay` 是什么

代码：

```cpp
class SysStatusDisplay : public rclcpp::Node {
```

这表示：

```text
定义一个 C++ 类，名字叫 SysStatusDisplay。
它继承自 rclcpp::Node。
```

`rclcpp::Node` 是 ROS2 C++ 里的节点基类。

继承它以后，你的类就拥有了创建订阅者、创建发布者、创建定时器等能力。

可以这样理解：

```text
rclcpp::Node 是 ROS2 节点的基础模板。
SysStatusDisplay 是你自己写的具体节点。
```

继承关系：

```text
rclcpp::Node
    ↑
SysStatusDisplay
```

---

## 6. `private` 和 `public`

代码：

```cpp
private:
    rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
    QLabel *lable_;

public:
    SysStatusDisplay() : Node("sys_status_display") {
        ...
    }
```

C++ 类里常见访问权限：

| 关键字 | 含义 |
| --- | --- |
| `private` | 只能在类内部使用 |
| `public` | 类外部也可以调用 |

这里的设计是：

```text
subscriber_ 和 lable_ 是这个节点内部自己用的，所以放 private。
构造函数 SysStatusDisplay() 需要被 main() 调用，所以放 public。
```

变量名后面的 `_` 是一种常见习惯：

```text
subscriber_
lable_
```

表示它们是类的成员变量。

注意：`lable_` 拼写上应该是 `label_`。当前代码能编译是因为变量名只要前后一致就行，但建议以后改成 `label_`，避免看代码时混淆。

---

## 7. 订阅者成员变量

代码：

```cpp
rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
```

拆开看：

```text
rclcpp::Subscription<SystemStatus>
```

表示：

```text
一个订阅 SystemStatus 消息的 ROS2 订阅者类型。
```

后面的：

```text
::SharedPtr
```

表示：

```text
这个订阅者对象用智能指针管理。
```

所以整句意思是：

```text
subscriber_ 是一个智能指针，指向一个订阅 SystemStatus 消息的订阅者。
```

为什么要把订阅者保存成成员变量？

因为如果订阅者只写成局部变量：

```cpp
auto subscriber = this->create_subscription<SystemStatus>(...);
```

构造函数结束后，局部变量可能被销毁，订阅就没了。

保存成成员变量：

```cpp
subscriber_
```

它会跟着整个节点对象一起存在。

这点非常重要：

```text
订阅者对象必须活着，节点才能持续收到消息。
```

---

## 8. Qt 标签指针

代码：

```cpp
QLabel *lable_;
```

`QLabel` 是 Qt 的文字显示控件。

`QLabel *` 表示：

```text
这是一个指针，指向一个 QLabel 对象。
```

在构造函数里：

```cpp
lable_ = new QLabel();
```

意思是：

```text
在内存里创建一个新的 QLabel，并让 lable_ 指向它。
```

然后：

```cpp
lable_->setText(...);
lable_->show();
```

`->` 是通过指针访问对象成员的写法。

如果不是指针，而是普通对象，会写：

```cpp
label.setText(...);
```

如果是指针，就写：

```cpp
label_ptr->setText(...);
```

---

## 9. 构造函数和节点名

代码：

```cpp
SysStatusDisplay() : Node("sys_status_display") {
```

这是构造函数。

构造函数的特点：

```text
函数名和类名一样
创建对象时自动执行
```

`SysStatusDisplay` 对象创建时，这个函数会自动运行。

后面的：

```cpp
: Node("sys_status_display")
```

叫初始化列表。

它的意思是：

```text
先调用父类 rclcpp::Node 的构造函数，并把节点名设置为 sys_status_display。
```

所以 ROS2 里看到的节点名就是：

```text
/sys_status_display
```

你可以运行后查看：

```bash
ros2 node list
```

应该能看到：

```text
/sys_status_display
```

---

## 10. 创建订阅者

核心代码：

```cpp
subscriber_ = this->create_subscription<SystemStatus>(
    "sys_status",
    10,
    [&](const SystemStatus::SharedPtr msg) -> void {
        lable_->setText(get_qstr_from_msg(msg));
    }
);
```

这是整个 ROS2 订阅节点最重要的一段。

它的作用：

```text
创建一个订阅者，订阅 sys_status 话题。
每当收到一条 SystemStatus 消息，就执行回调函数。
```

拆成三部分：

```cpp
this->create_subscription<SystemStatus>(
    "sys_status",       // 话题名
    10,                 // 队列深度
    回调函数             // 收到消息后执行什么
);
```

### 10.1 `this` 是什么

代码：

```cpp
this->create_subscription<SystemStatus>(...)
```

`this` 表示：

```text
当前这个对象自己。
```

当前对象就是：

```text
SysStatusDisplay 节点对象
```

因为 `SysStatusDisplay` 继承了 `rclcpp::Node`，所以它可以调用 `create_subscription`。

### 10.2 `<SystemStatus>` 是什么

代码：

```cpp
create_subscription<SystemStatus>
```

尖括号里的 `SystemStatus` 是模板参数。

它告诉 ROS2：

```text
我要订阅的消息类型是 SystemStatus。
```

这必须和发布者发布的类型一致。

如果发布者发布的是：

```text
status_interfaces/msg/SystemStatus
```

订阅者也必须订阅：

```text
status_interfaces/msg/SystemStatus
```

### 10.3 `"sys_status"` 是什么

代码：

```cpp
"sys_status"
```

这是话题名。

ROS2 里它通常会显示成：

```text
/sys_status
```

发布者和订阅者的话题名必须一致。

你可以查看话题：

```bash
ros2 topic list -t
```

应该能看到类似：

```text
/sys_status [status_interfaces/msg/SystemStatus]
```

### 10.4 `10` 是什么

代码：

```cpp
10
```

这是 QoS 队列深度的简写。

初学者可以先理解成：

```text
如果消息来得太快，订阅者最多先缓存 10 条。
```

如果你的 Qt 显示处理很慢，而发布者一直发，队列可能堆积。

这里系统状态一般 1 秒发布一次，所以 `10` 足够。

---

## 11. lambda 函数是什么

回调函数这段代码：

```cpp
[&](const SystemStatus::SharedPtr msg) -> void {
    lable_->setText(get_qstr_from_msg(msg));
}
```

这就是 C++ 的 lambda 函数。

lambda 可以理解成：

```text
一个临时写在原地的小函数。
```

普通函数可能这样写：

```cpp
void callback(const SystemStatus::SharedPtr msg) {
    lable_->setText(get_qstr_from_msg(msg));
}
```

但是这里的回调只在创建订阅者时用一次，所以直接写成 lambda。

lambda 的基本格式：

```cpp
[捕获列表](参数列表) -> 返回类型 {
    函数体
}
```

对应到你的代码：

```cpp
[&](const SystemStatus::SharedPtr msg) -> void {
    lable_->setText(get_qstr_from_msg(msg));
}
```

逐个解释：

| 部分 | 你的代码 | 含义 |
| --- | --- | --- |
| 捕获列表 | `[&]` | 允许 lambda 使用外部变量，按引用捕获 |
| 参数列表 | `(const SystemStatus::SharedPtr msg)` | 收到的 ROS2 消息 |
| 返回类型 | `-> void` | 这个函数不返回值 |
| 函数体 | `{ lable_->setText(...); }` | 收到消息后更新 Qt 标签 |

### 11.1 `[&]` 是什么

`[&]` 表示：

```text
lambda 里面用到外面的变量时，按引用捕获。
```

在你的 lambda 里用到了：

```cpp
lable_
get_qstr_from_msg(msg)
```

这些属于当前对象。

因为用了 `[&]`，lambda 可以访问它们。

更严谨的写法可以写成：

```cpp
[this](const SystemStatus::SharedPtr msg) {
    lable_->setText(get_qstr_from_msg(msg));
}
```

`[this]` 表示：

```text
我要在 lambda 里使用当前对象的成员变量和成员函数。
```

对这个例子来说，`[this]` 比 `[&]` 更明确，初学时更推荐理解成：

```text
收到消息后，用当前对象的 QLabel 显示当前对象转换出来的字符串。
```

### 11.2 `const SystemStatus::SharedPtr msg` 是什么

这表示回调函数收到一个消息指针。

拆开：

```text
SystemStatus
```

消息类型。

```text
SharedPtr
```

智能指针类型。

```text
msg
```

变量名。

```text
const
```

表示这个指针变量本身不应该被修改。

收到消息后，你可以读字段：

```cpp
msg->cpu_percent
msg->memory_percent
msg->host_name
```

### 11.3 为什么回调里用 `->`

因为 `msg` 是智能指针。

普通对象访问成员：

```cpp
msg.cpu_percent
```

指针访问成员：

```cpp
msg->cpu_percent
```

所以你的代码里：

```cpp
msg->stamp.sec
msg->host_name
msg->cpu_percent
```

---

## 12. 智能指针是什么

ROS2 C++ 里经常看到：

```cpp
std::shared_ptr
SharedPtr
std::make_shared
```

它们都和智能指针有关。

### 12.1 普通指针的问题

普通指针例子：

```cpp
QLabel *label = new QLabel();
```

这里 `new` 创建对象。

问题是：

```text
new 出来的对象需要手动 delete。
如果忘了 delete，就可能内存泄漏。
```

智能指针的目标是：

```text
让 C++ 自动管理对象生命周期。
```

### 12.2 `std::shared_ptr`

`std::shared_ptr<T>` 表示：

```text
一个可以被多个地方共同持有的 T 对象指针。
最后一个持有者消失时，对象自动释放。
```

例如：

```cpp
std::shared_ptr<SysStatusDisplay> node;
```

表示：

```text
node 是一个智能指针，指向 SysStatusDisplay 对象。
```

### 12.3 `std::make_shared`

代码：

```cpp
auto node = std::make_shared<SysStatusDisplay>();
```

意思是：

```text
创建一个 SysStatusDisplay 对象，并用 shared_ptr 管理它。
```

它大致相当于：

```cpp
std::shared_ptr<SysStatusDisplay> node(new SysStatusDisplay());
```

但 `std::make_shared` 更安全、更推荐。

### 12.4 ROS2 里的 `SharedPtr`

代码：

```cpp
rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
```

这里的 `SharedPtr` 是 ROS2 类型里提前定义好的别名。

它本质上可以理解成：

```cpp
std::shared_ptr<rclcpp::Subscription<SystemStatus>>
```

也就是说：

```text
subscriber_ 是一个 shared_ptr，指向一个 ROS2 订阅者对象。
```

ROS2 大量使用智能指针，是因为节点、订阅者、消息、回调之间的生命周期比较复杂。用智能指针可以减少手动释放内存带来的错误。

---

## 13. 默认显示一条空消息

代码：

```cpp
lable_->setText(get_qstr_from_msg(std::make_shared<SystemStatus>()));
```

这句话的作用是：

```text
程序刚启动，还没有收到 /sys_status 消息时，也先显示一份默认内容。
```

`std::make_shared<SystemStatus>()` 会创建一条默认的 `SystemStatus` 消息。

这条消息里的字段大多是默认值：

```text
数字字段一般是 0
字符串字段一般是空字符串
时间字段一般是 0
```

然后传给：

```cpp
get_qstr_from_msg(...)
```

转成 Qt 可以显示的 `QString`。

---

## 14. `get_qstr_from_msg` 是什么

代码：

```cpp
QString get_qstr_from_msg(const SystemStatus::SharedPtr msg) {
    std::stringstream show_str;
    show_str << "新提供状态可视化工具\n"
             << "数据时间：\t" << msg->stamp.sec << "\ts\n"
             << "主机名字：\t" << msg->host_name << "\t\n"
             << "CPU使用率:\t" << msg->cpu_percent << "\t%\n"
             << "内存使用率：\t" << msg->memory_percent << "\t%\n"
             << "内存总大小：\t" << msg->memory_total << "\tMB\n"
             << "剩余有效内存：\t" << msg->memory_available << "\tMB\n"
             << "网络发送量：\t" << msg->net_sent << "\tMB\n"
             << "网络接收量：\t" << msg->net_recv << "\tMB\n";
    return QString::fromStdString(show_str.str());
}
```

这个函数的作用：

```text
把 ROS2 的 SystemStatus 消息转换成 Qt 可以显示的 QString。
```

转换流程：

```text
SystemStatus 消息
    ↓
std::stringstream 拼接成 std::string
    ↓
QString::fromStdString 转成 QString
    ↓
QLabel 显示
```

### 14.1 `std::stringstream`

`std::stringstream` 是 C++ 标准库里的字符串流。

它适合把很多内容拼成一个字符串。

写法类似 `cout`：

```cpp
show_str << "CPU使用率:" << msg->cpu_percent << "%";
```

最后用：

```cpp
show_str.str()
```

得到完整字符串。

### 14.2 `QString::fromStdString`

`show_str.str()` 得到的是 C++ 标准字符串：

```cpp
std::string
```

但 Qt 的 `QLabel::setText()` 更常用：

```cpp
QString
```

所以需要转换：

```cpp
QString::fromStdString(show_str.str())
```

---

## 15. `main()` 函数整体流程

代码：

```cpp
int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    QApplication app(argc, argv);
    auto node = std::make_shared<SysStatusDisplay>();
    std::thread spin_thread([&]() -> void {
        rclcpp::spin(node);
    });
    spin_thread.detach();
    app.exec();
    return 0;
}
```

执行顺序：

```text
1. 初始化 ROS2
2. 初始化 Qt 应用
3. 创建 sys_status_display 节点对象
4. 开一个线程运行 rclcpp::spin(node)
5. 主线程运行 Qt 事件循环 app.exec()
6. Qt 窗口关闭后 main 返回
```

---

## 16. `rclcpp::init(argc, argv)`

代码：

```cpp
rclcpp::init(argc, argv);
```

作用：

```text
初始化 ROS2 C++ 客户端库。
```

所有 ROS2 C++ 程序一般都要先调用它。

它会处理 ROS2 相关参数，例如：

```bash
ros2 run status_display sys_status_display --ros-args -r __node:=my_display
```

如果不初始化 ROS2，就不能正常创建 ROS2 节点。

---

## 17. `QApplication app(argc, argv)`

代码：

```cpp
QApplication app(argc, argv);
```

作用：

```text
初始化 Qt 图形界面程序。
```

只要你写 Qt Widgets 图形界面，一般都需要一个 `QApplication`。

它负责：

```text
窗口事件
鼠标键盘事件
界面刷新
Qt 控件生命周期
```

---

## 18. 为什么要 `rclcpp::spin(node)`

代码：

```cpp
rclcpp::spin(node);
```

`spin` 可以理解成：

```text
让 ROS2 节点开始工作，持续等待并处理回调。
```

如果没有 `spin`：

```text
订阅者虽然创建了，但回调函数不会被持续处理。
```

也就是说，下面这个 lambda 不会正常被调用：

```cpp
[&](const SystemStatus::SharedPtr msg) -> void {
    lable_->setText(get_qstr_from_msg(msg));
}
```

所以订阅节点一定需要某种形式的 `spin`。

常见写法：

```cpp
rclcpp::spin(node);
```

它会阻塞当前线程。

阻塞的意思是：

```text
程序会停在这里持续运行，不会继续往下执行，直到 ROS2 退出。
```

---

## 19. 为什么 Qt 和 ROS2 要用两个线程

你的程序里有两个都需要“持续运行”的循环。

第一个是 ROS2：

```cpp
rclcpp::spin(node);
```

它要持续等待消息。

第二个是 Qt：

```cpp
app.exec();
```

它要持续刷新窗口、处理鼠标键盘事件。

问题是：

```text
rclcpp::spin(node) 会阻塞。
app.exec() 也会阻塞。
```

如果这样写：

```cpp
rclcpp::spin(node);
app.exec();
```

程序会一直卡在 `spin`，Qt 窗口事件循环不会启动。

如果这样写：

```cpp
app.exec();
rclcpp::spin(node);
```

程序会一直卡在 `app.exec()`，ROS2 spin 不会启动。

所以你的代码使用线程：

```cpp
std::thread spin_thread([&]() -> void {
    rclcpp::spin(node);
});
spin_thread.detach();
app.exec();
```

意思是：

```text
新开一个线程专门跑 ROS2 spin。
主线程继续跑 Qt app.exec()。
```

可以理解成：

```text
主线程：负责 Qt 窗口
子线程：负责 ROS2 消息回调
```

---

## 20. `std::thread` 和线程 lambda

代码：

```cpp
std::thread spin_thread([&]() -> void {
    rclcpp::spin(node);
});
```

意思是：

```text
创建一个新线程。
新线程启动后执行 lambda 里的 rclcpp::spin(node)。
```

这里 lambda 没有参数：

```cpp
() -> void
```

表示：

```text
不接收参数，不返回值。
```

它用 `[&]` 捕获外部的 `node`：

```cpp
[&]() -> void {
    rclcpp::spin(node);
}
```

这样 lambda 里面才能使用 `node`。

### 20.1 `detach()` 是什么

代码：

```cpp
spin_thread.detach();
```

意思是：

```text
把这个线程分离出去，让它自己独立运行。
```

初学时可以先理解为：

```text
主线程不等待 spin_thread 结束。
```

注意：真实项目里，线程退出和 Qt 关闭时的资源释放要更严谨。学习阶段这样写容易理解，但后续可以改成窗口关闭时调用 `rclcpp::shutdown()`，并用 `join()` 等待线程结束。

---

## 21. Qt 线程安全提醒

你的回调函数在 ROS2 spin 线程里执行：

```cpp
lable_->setText(get_qstr_from_msg(msg));
```

但 `QLabel` 是 Qt 界面对象。

Qt 一般要求：

```text
界面控件最好只在 Qt 主线程里更新。
```

当前学习代码通常可以先这样理解流程，但更标准的 Qt 写法是：

```text
ROS2 回调线程收到消息
通过 Qt signal/slot 或 QMetaObject::invokeMethod
把界面更新操作投递到 Qt 主线程执行
```

这属于进阶内容。初学阶段先重点理解：

```text
ROS2 回调负责拿数据
Qt QLabel 负责显示数据
线程用于让 ROS2 和 Qt 两个循环同时运行
```

---

## 22. CMakeLists.txt 重点讲解

当前 `status_display/CMakeLists.txt` 核心应该是：

```cmake
cmake_minimum_required(VERSION 3.8)
project(status_display)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(status_interfaces REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(sys_status_display src/sys_status_display.cpp)
target_link_libraries(sys_status_display Qt5::Widgets)
ament_target_dependencies(sys_status_display rclcpp status_interfaces)

install(TARGETS sys_status_display
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
```

这部分是重点。C++ ROS2 新手最容易在这里出错。

### 22.1 `cmake_minimum_required`

```cmake
cmake_minimum_required(VERSION 3.8)
```

意思是：

```text
这个工程至少需要 CMake 3.8。
```

### 22.2 `project(status_display)`

```cmake
project(status_display)
```

定义项目名。

在 ROS2 里通常和功能包名一致：

```text
package.xml 里的 <name>status_display</name>
CMakeLists.txt 里的 project(status_display)
```

两者最好保持一致。

### 22.3 编译警告选项

```cmake
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
```

意思是：

```text
如果使用 GCC 或 Clang 编译器，就打开更多警告。
```

这些警告能帮你发现潜在问题。

### 22.4 `find_package(ament_cmake REQUIRED)`

```cmake
find_package(ament_cmake REQUIRED)
```

`ament_cmake` 是 ROS2 C++ 包常用的构建系统支持包。

你写 C++ ROS2 包，一般都需要它。

没有它，后面的：

```cmake
ament_target_dependencies(...)
ament_package()
```

就不能正常使用。

### 22.5 `find_package(rclcpp REQUIRED)`

```cmake
find_package(rclcpp REQUIRED)
```

意思是：

```text
我要使用 ROS2 C++ 客户端库 rclcpp。
```

源码里使用了：

```cpp
#include <rclcpp/rclcpp.hpp>
rclcpp::Node
rclcpp::spin
rclcpp::Subscription
```

所以 CMake 里必须找 `rclcpp`。

只写 `#include <rclcpp/rclcpp.hpp>` 不够。

CMake 还要知道：

```text
rclcpp 的头文件在哪里
rclcpp 的库文件在哪里
编译时要加哪些参数
链接时要链接哪些库
```

### 22.6 `find_package(status_interfaces REQUIRED)`

```cmake
find_package(status_interfaces REQUIRED)
```

意思是：

```text
我要使用自己定义的消息包 status_interfaces。
```

源码里使用了：

```cpp
#include <status_interfaces/msg/system_status.hpp>
status_interfaces::msg::SystemStatus
```

所以 CMake 里必须找 `status_interfaces`。

如果没有这行，可能报：

```text
status_interfaces/msg/system_status.hpp: No such file or directory
```

### 22.7 `find_package(Qt5 REQUIRED COMPONENTS Widgets)`

```cmake
find_package(Qt5 REQUIRED COMPONENTS Widgets)
```

意思是：

```text
我要使用 Qt5，并且需要 Qt Widgets 模块。
```

你的代码用了：

```cpp
QApplication
QLabel
QString
```

其中 `QApplication`、`QLabel` 属于 Qt Widgets 相关内容。

所以需要：

```cmake
Qt5::Widgets
```

### 22.8 `add_executable`

```cmake
add_executable(sys_status_display src/sys_status_display.cpp)
```

意思是：

```text
把 src/sys_status_display.cpp 编译成一个可执行程序。
这个程序名字叫 sys_status_display。
```

这个名字会影响运行命令：

```bash
ros2 run status_display sys_status_display
```

对应关系：

```text
ros2 run status_display sys_status_display
         包名           可执行文件名
```

### 22.9 `target_link_libraries`

```cmake
target_link_libraries(sys_status_display Qt5::Widgets)
```

意思是：

```text
把 sys_status_display 这个可执行程序链接到 Qt5 Widgets 库。
```

为什么要链接？

因为你源码里调用了 Qt 的类和函数：

```cpp
QApplication
QLabel
QString
```

编译器看到头文件后知道这些类长什么样。

但链接器还要知道这些类的具体实现在哪里。

`Qt5::Widgets` 就把 Qt Widgets 相关库链接进来。

### 22.10 `ament_target_dependencies`

```cmake
ament_target_dependencies(sys_status_display rclcpp status_interfaces)
```

这是 ROS2 C++ 包里非常关键的一句。

它的意思是：

```text
sys_status_display 这个目标依赖 rclcpp 和 status_interfaces。
请自动给它加上对应 include 路径、编译参数和链接库。
```

这句解决的问题包括：

```text
#include <rclcpp/rclcpp.hpp> 找不到
#include <status_interfaces/msg/system_status.hpp> 找不到
链接 rclcpp 相关符号失败
```

重要区别：

```cmake
find_package(rclcpp REQUIRED)
```

只是找到包。

```cmake
ament_target_dependencies(sys_status_display rclcpp)
```

才是把这个依赖应用到 `sys_status_display` 目标上。

初学者经常只写 `find_package`，忘了 `ament_target_dependencies`，然后 VS Code 或编译器就找不到头文件。

### 22.11 `install(TARGETS ...)`

```cmake
install(TARGETS sys_status_display
  DESTINATION lib/${PROJECT_NAME}
)
```

意思是：

```text
编译完成后，把 sys_status_display 安装到 install/status_display/lib/status_display/ 下面。
```

ROS2 的 `ros2 run` 会去安装目录找可执行文件。

如果没有 `install`，可能出现：

```text
ros2 run status_display sys_status_display
No executable found
```

所以 C++ 可执行节点一般都要写 `install(TARGETS ...)`。

### 22.12 `ament_package`

```cmake
ament_package()
```

意思是：

```text
声明这是一个 ament CMake ROS2 包，并生成必要的包信息。
```

一般放在 `CMakeLists.txt` 最后。

---

## 23. package.xml 重点讲解

当前 `package.xml` 关键内容：

```xml
<buildtool_depend>ament_cmake</buildtool_depend>

<depend>rclcpp</depend>
<depend>status_interfaces</depend>
<depend>qtbase5-dev</depend>

<test_depend>ament_lint_auto</test_depend>
<test_depend>ament_lint_common</test_depend>

<export>
  <build_type>ament_cmake</build_type>
</export>
```

### 23.1 `<buildtool_depend>ament_cmake</buildtool_depend>`

表示：

```text
这个包使用 ament_cmake 作为构建工具。
```

### 23.2 `<depend>rclcpp</depend>`

表示：

```text
这个包编译和运行都需要 rclcpp。
```

因为你写的是 ROS2 C++ 节点。

### 23.3 `<depend>status_interfaces</depend>`

表示：

```text
这个包需要 status_interfaces 里的 SystemStatus 消息。
```

### 23.4 `<depend>qtbase5-dev</depend>`

表示：

```text
这个包需要 Qt5 基础开发文件。
```

它提供 Qt 头文件、库和 CMake 配置。

如果系统没装 Qt 开发包，可能会报：

```text
Could not find a package configuration file provided by "Qt5"
```

或者：

```text
QApplication: No such file or directory
```

---

## 24. 编译和运行

### 24.1 编译前先 source ROS2

```bash
source /opt/ros/humble/setup.bash
```

作用：

```text
让当前终端知道 ROS2 Humble 安装在哪里。
```

### 24.2 编译工作空间

在工作空间根目录：

```bash
cd /home/li/ROS2_Repository/CHATP3/topic_practice_ws
colcon build --packages-up-to status_display --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

`--packages-up-to status_display` 表示：

```text
编译 status_display，以及它依赖的本工作空间包。
```

这里会先编译：

```text
status_interfaces
```

再编译：

```text
status_display
```

`-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` 表示：

```text
生成 compile_commands.json，方便 VS Code IntelliSense 找 include 路径。
```

### 24.3 source 工作空间

编译完成后：

```bash
source install/setup.bash
```

作用：

```text
让当前终端知道你刚编译出来的 status_display、status_interfaces 在哪里。
```

### 24.4 启动发布者

开一个终端：

```bash
cd /home/li/ROS2_Repository/CHATP3/topic_practice_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run status_publisher sys_status_pub
```

### 24.5 启动 Qt 显示节点

再开一个终端：

```bash
cd /home/li/ROS2_Repository/CHATP3/topic_practice_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run status_display sys_status_display
```

如果图形环境正常，会弹出一个 Qt 窗口显示系统状态。

---

## 25. 常用检查命令

### 25.1 看节点

```bash
ros2 node list
```

可能看到：

```text
/sys_status_pub
/sys_status_display
```

### 25.2 看话题和类型

```bash
ros2 topic list -t
```

可能看到：

```text
/sys_status [status_interfaces/msg/SystemStatus]
```

### 25.3 看话题数据

```bash
ros2 topic echo /sys_status
```

如果发布者正在运行，会看到字段：

```text
stamp:
  sec: ...
host_name: ...
cpu_percent: ...
memory_percent: ...
```

### 25.4 看节点信息

```bash
ros2 node info /sys_status_display
```

你应该能看到它订阅了：

```text
/sys_status
```

---

## 26. 常见错误 1：找不到 `rclcpp/rclcpp.hpp`

错误：

```text
fatal error: rclcpp/rclcpp.hpp: No such file or directory
```

常见原因：

```text
1. 终端没有 source /opt/ros/humble/setup.bash
2. CMakeLists.txt 没有 find_package(rclcpp REQUIRED)
3. CMakeLists.txt 没有 ament_target_dependencies(sys_status_display rclcpp)
4. VS Code 没有读取 compile_commands.json
```

检查 CMake：

```cmake
find_package(rclcpp REQUIRED)

add_executable(sys_status_display src/sys_status_display.cpp)
ament_target_dependencies(sys_status_display rclcpp status_interfaces)
```

---

## 27. 常见错误 2：找不到 `system_status.hpp`

错误：

```text
fatal error: status_interfaces/msg/system_status.hpp: No such file or directory
```

常见原因：

```text
1. status_interfaces 没有先编译成功
2. 没有 source install/setup.bash
3. status_display 没有依赖 status_interfaces
4. include 名字写错
```

正确 include：

```cpp
#include <status_interfaces/msg/system_status.hpp>
```

正确 CMake：

```cmake
find_package(status_interfaces REQUIRED)
ament_target_dependencies(sys_status_display rclcpp status_interfaces)
```

正确 package.xml：

```xml
<depend>status_interfaces</depend>
```

---

## 28. 常见错误 3：CMake target 名字不一致

错误：

```text
Cannot specify link libraries for target "hello_qt" which is not built by this project
```

原因：

```text
你写了 target_link_libraries(hello_qt ...)
但是没有 add_executable(hello_qt ...)
```

CMake 里的目标名必须前后一致。

错误例子：

```cmake
add_executable(sys_status_display src/sys_status_display.cpp)
target_link_libraries(hello_qt Qt5::Widgets)
```

正确例子：

```cmake
add_executable(sys_status_display src/sys_status_display.cpp)
target_link_libraries(sys_status_display Qt5::Widgets)
```

---

## 29. 常见错误 4：Qt 路径找不到

错误可能是：

```text
QApplication: No such file or directory
```

或者 VS Code 提示：

```text
检测到 #include 错误。请更新 includePath。
```

先确认系统安装了 Qt5 开发包：

```bash
dpkg -l | grep qtbase5-dev
```

如果没有，需要安装：

```bash
sudo apt install qtbase5-dev
```

当前系统 Qt5 头文件通常在：

```text
/usr/include/x86_64-linux-gnu/qt5
```

CMake 里需要：

```cmake
find_package(Qt5 REQUIRED COMPONENTS Widgets)
target_link_libraries(sys_status_display Qt5::Widgets)
```

---

## 30. 对当前代码的几个改进建议

这些不是初学阶段必须马上做的，但你后面可以逐步优化。

### 30.1 补充标准库头文件

当前代码使用了：

```cpp
std::stringstream
std::thread
std::make_shared
```

更规范的 include 应该显式加上：

```cpp
#include <memory>
#include <sstream>
#include <thread>
```

有时它现在能编译，是因为其他头文件间接包含了这些标准库头文件。但真实项目里最好自己用什么就 include 什么。

### 30.2 `lable_` 改成 `label_`

当前变量名：

```cpp
QLabel *lable_;
```

建议改成：

```cpp
QLabel *label_;
```

因为英文单词是 `label`。

### 30.3 退出时调用 `rclcpp::shutdown()`

当前 `main()` 最后：

```cpp
app.exec();
return 0;
```

后面可以改成：

```cpp
int ret = app.exec();
rclcpp::shutdown();
return ret;
```

这样 Qt 窗口关闭后，也通知 ROS2 退出。

### 30.4 Qt 主线程更新界面

当前回调线程直接更新 QLabel：

```cpp
lable_->setText(...)
```

学习阶段可以先理解流程。更标准的 Qt 项目里，建议用 Qt 的 signal/slot 或 `QMetaObject::invokeMethod` 把界面更新切回主线程。

---

## 31. 最后用一句话总结

这个程序的核心逻辑是：

```text
rclcpp::Node 创建 ROS2 订阅节点
create_subscription 订阅 /sys_status
lambda 回调函数接收 SystemStatus 消息
get_qstr_from_msg 把消息转成 QString
QLabel 把 QString 显示到窗口上
std::thread 让 ROS2 spin 和 Qt app.exec 同时运行
CMakeLists.txt 负责把 rclcpp、status_interfaces、Qt5 全部正确编译和链接起来
```

如果你能把这条链路讲清楚，就说明你已经真正理解了这个 ROS2 + Qt 订阅显示节点。
