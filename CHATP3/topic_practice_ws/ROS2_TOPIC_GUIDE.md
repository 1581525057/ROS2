# ROS2 话题通信入门到实践：结合 `SystemStatus` 项目

这份笔记是给 ROS2 初学者看的。目标不是只列命令，而是让你真正搞清楚：

- ROS2 里“节点、话题、消息、发布者、订阅者”分别是什么
- 功能包为什么要这样组织
- `ros2 topic list -t`、`ros2 topic echo`、`ros2 node info` 这些命令到底在看什么
- 你现在写的 `SystemStatus` 发布节点在 ROS2 系统里扮演什么角色
- 出错时应该从哪里查

当前工作区：

```text
/home/li/ROS2_Repository/CHATP3/topic_practice_ws
```

当前项目包含两个功能包：

```text
src/status_interfaces
src/status_publisher
```

它们组成了一个很典型的 ROS2 话题通信例子：

```text
status_publisher 包里的 sys_status_pub 节点
每秒采集一次电脑状态
打包成 status_interfaces/msg/SystemStatus 消息
发布到 /sys_status 话题
```

---

## 0. 先记住一张总图

初学 ROS2 话题通信，先把这张图记住：

```text
发布者节点                         话题                         订阅者节点
Publisher Node  ───────────────>  Topic  ───────────────>  Subscriber Node

sys_status_pub                  /sys_status                 以后你可以写的订阅节点
```

这张图里面有三个核心对象：

```text
节点 node
话题 topic
消息 message
```

再细一点：

```text
节点 node 是运行中的程序
话题 topic 是数据通道
消息 message 是通道里传输的数据格式
发布者 publisher 负责往话题里发消息
订阅者 subscriber 负责从话题里收消息
```

你的当前项目对应关系是：

```text
节点名：/sys_status_pub
话题名：/sys_status
消息类型：status_interfaces/msg/SystemStatus
发布者所在包：status_publisher
消息定义所在包：status_interfaces
```

---

## 1. 为什么 ROS2 需要节点和话题

先不要急着背命令。先想一个问题：

如果一个机器人里有很多功能，比如：

- 摄像头采集图像
- 雷达采集距离
- 键盘控制机器人
- 规划路径
- 控制电机
- 监控 CPU 和内存

如果全部写在一个大程序里，会很难维护。

ROS2 的思路是：

```text
把一个大系统拆成很多小程序，每个小程序只做一件事。
```

这些小程序就是节点。

例如：

```text
camera_node        负责发布图像
lidar_node         负责发布雷达
keyboard_node      负责发布键盘控制命令
motor_node         负责订阅控制命令并驱动电机
sys_status_pub     负责发布电脑状态
```

节点之间不直接互相调用函数，而是通过 ROS2 通信机制交换数据。

话题通信就是最常见的一种通信方式。

---

## 2. 发布订阅是什么

发布订阅可以理解成“广播频道”。

发布者像电台：

```text
我持续往 /sys_status 频道里广播系统状态。
```

订阅者像收音机：

```text
我只要订阅 /sys_status，就能收到系统状态。
```

发布者不需要知道有几个订阅者。

订阅者也不需要知道发布者是谁。

它们只要匹配这两件事：

```text
话题名一样
消息类型一样
```

例如你的例子里：

```text
话题名：/sys_status
消息类型：status_interfaces/msg/SystemStatus
```

以后你写订阅者时，也必须订阅这个话题和这个消息类型。

---

## 3. 工作空间 workspace 是什么

工作空间是一个 ROS2 项目的总目录。

你的工作空间是：

```text
topic_practice_ws
```

典型结构如下：

```text
topic_practice_ws/
├── src/
├── build/
├── install/
└── log/
```

各目录作用：

| 目录 | 作用 | 初学者该不该手动改 |
| --- | --- | --- |
| `src/` | 放你写的功能包源码 | 主要改这里 |
| `build/` | 编译中间文件 | 一般不改 |
| `install/` | 编译安装后的结果 | 一般不改 |
| `log/` | 编译日志 | 出错时查看 |

最重要的一点：

> 你平时写代码，主要写 `src/` 里面的内容。

---

## 4. 功能包 package 是什么

功能包是 ROS2 管理代码的基本单位。

一个工作空间里可以有多个功能包：

```text
src/
├── status_interfaces/
└── status_publisher/
```

你的两个包分工很清楚：

| 功能包 | 作用 |
| --- | --- |
| `status_interfaces` | 定义自定义消息 `SystemStatus` |
| `status_publisher` | 写发布系统状态的 Python 节点 |

为什么要把消息定义单独放一个包？

因为发布者和订阅者都要知道同一种消息格式。

例如：

```text
status_publisher 需要 SystemStatus，因为它要发布这种消息
以后 status_subscriber 也需要 SystemStatus，因为它要订阅这种消息
```

如果把消息定义单独放在 `status_interfaces`，其他包都可以依赖它。

这是一种常见结构：

```text
xxx_interfaces   放 msg/srv/action
xxx_publisher    放发布节点
xxx_subscriber   放订阅节点
```

---

## 5. Python 功能包结构怎么看

你的 `status_publisher` 是 Python 包，结构大致是：

```text
src/status_publisher/
├── package.xml
├── setup.py
├── setup.cfg
├── resource/
│   └── status_publisher
└── status_publisher/
    ├── __init__.py
    └── sys_status_pub.py
```

重点看三个地方：

### 5.1 `package.xml`

路径：

```text
src/status_publisher/package.xml
```

它描述这个 ROS2 包依赖什么。

你当前有：

```xml
<depend>rclpy</depend>
<depend>status_interfaces</depend>
```

意思是：

```text
这个包需要 rclpy
这个包需要 status_interfaces
```

`rclpy` 是 ROS2 的 Python 客户端库。

`status_interfaces` 是你自己的消息接口包。

### 5.2 `setup.py`

路径：

```text
src/status_publisher/setup.py
```

里面最关键的是：

```python
entry_points={
    'console_scripts': [
        'sys_status_pub = status_publisher.sys_status_pub:main',
    ],
},
```

这句话决定了你能运行：

```bash
ros2 run status_publisher sys_status_pub
```

拆开看：

```text
sys_status_pub
```

这是命令里的可执行名。

```text
status_publisher.sys_status_pub:main
```

意思是：

```text
找到 Python 包 status_publisher
找到里面的 sys_status_pub.py
执行里面的 main 函数
```

所以命令和代码之间的关系是：

```text
ros2 run status_publisher sys_status_pub
         包名             可执行名

可执行名在 setup.py 里映射到：
status_publisher/sys_status_pub.py 里的 main()
```

### 5.3 Python 源码目录

路径：

```text
src/status_publisher/status_publisher/
```

注意这里有两个 `status_publisher`：

```text
src/status_publisher/status_publisher/sys_status_pub.py
    ↑ 包目录          ↑ Python 模块目录
```

第一个是 ROS2 功能包目录。

第二个是 Python 包目录。

初学者容易混淆，但这是正常结构。

---

## 6. 接口功能包结构怎么看

你的 `status_interfaces` 是接口包，结构大致是：

```text
src/status_interfaces/
├── CMakeLists.txt
├── package.xml
└── msg/
    └── SystemStatus.msg
```

它不是用来运行节点的。

它主要负责生成消息代码。

### 6.1 `.msg` 文件

路径：

```text
src/status_interfaces/msg/SystemStatus.msg
```

内容：

```text
builtin_interfaces/Time stamp
string host_name
float32 cpu_percent
float32 memory_percent
float32 memory_total
float32 memory_available
float64 net_sent
float64 net_recv
```

这就是 `SystemStatus` 消息的字段。

可以理解成你定义了一个数据结构：

```text
SystemStatus:
  stamp
  host_name
  cpu_percent
  memory_percent
  memory_total
  memory_available
  net_sent
  net_recv
```

Python 里才能这样写：

```python
msg = SystemStatus()
msg.cpu_percent = 12.5
msg.memory_percent = 40.0
```

如果 `.msg` 里没有某个字段，Python 里就不能给它赋值。

例如之前错误：

```python
msg.cpu_persent = cpu_percent
```

因为 `.msg` 里是 `cpu_percent`，不是 `cpu_persent`，所以会报：

```text
AttributeError: 'SystemStatus' object has no attribute 'cpu_persent'
```

### 6.2 `CMakeLists.txt`

路径：

```text
src/status_interfaces/CMakeLists.txt
```

关键配置：

```cmake
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces (${PROJECT_NAME}
  "msg/SystemStatus.msg"
  DEPENDENCIES builtin_interfaces
)
```

这几行告诉 ROS2：

```text
我要生成接口
接口文件是 msg/SystemStatus.msg
这个消息里用到了 builtin_interfaces
```

因为你的 `.msg` 里有：

```text
builtin_interfaces/Time stamp
```

所以这里需要 `DEPENDENCIES builtin_interfaces`。

### 6.3 `package.xml`

路径：

```text
src/status_interfaces/package.xml
```

关键配置：

```xml
<depend>builtin_interfaces</depend>
<build_depend>rosidl_default_generators</build_depend>
<exec_depend>rosidl_default_runtime</exec_depend>
<member_of_group>rosidl_interface_packages</member_of_group>
```

它说明这个包是一个接口包，并且需要 ROS2 的接口生成工具。

---

## 7. 节点 node 深入理解

节点是运行中的程序。

你的节点代码：

```python
class SysStausPub(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
```

这里继承了：

```python
Node
```

`Node` 是 ROS2 Python 里表示节点的类。

这句很重要：

```python
super().__init__(node_name)
```

它的意思是：

```text
初始化 ROS2 节点，并设置节点名。
```

在 `main()` 里：

```python
node = SysStausPub('sys_status_pub')
```

所以运行后节点名是：

```text
/sys_status_pub
```

查看节点：

```bash
ros2 node list
```

你应该看到：

```text
/sys_status_pub
```

查看节点详细信息：

```bash
ros2 node info /sys_status_pub
```

你会看到它发布了哪些话题。

---

## 8. 话题 topic 深入理解

话题是数据通道。

你的代码：

```python
self.status_publisher_ = self.create_publisher(SystemStatus, 'sys_status', 10)
```

这行创建了一个发布者。

三个参数分别是：

```text
SystemStatus   消息类型
'sys_status'   话题名
10             队列深度
```

所以它的意思是：

```text
创建一个发布者，往 /sys_status 话题发布 SystemStatus 类型消息。
```

为什么代码里是 `sys_status`，命令里常看到 `/sys_status`？

因为 ROS2 里话题有命名空间概念。

简单理解：

```text
代码里写 sys_status
ROS2 展示时通常会显示成 /sys_status
```

查看话题：

```bash
ros2 topic list
```

查看话题和类型：

```bash
ros2 topic list -t
```

你应该看到：

```text
/sys_status [status_interfaces/msg/SystemStatus]
```

这句话非常关键。

它说明：

```text
/sys_status 这个话题正在传 status_interfaces/msg/SystemStatus 类型的数据。
```

---

## 9. 消息 message 深入理解

消息类型规定了话题里每条数据的格式。

你的消息类型是：

```text
status_interfaces/msg/SystemStatus
```

完整名字拆开：

```text
status_interfaces / msg / SystemStatus
       包名        接口类型   消息名
```

查看消息结构：

```bash
ros2 interface show status_interfaces/msg/SystemStatus
```

输出应该类似：

```text
builtin_interfaces/Time stamp
string host_name
float32 cpu_percent
float32 memory_percent
float32 memory_total
float32 memory_available
float64 net_sent
float64 net_recv
```

这说明 Python 里可以访问这些字段：

```python
msg.stamp
msg.host_name
msg.cpu_percent
msg.memory_percent
msg.memory_total
msg.memory_available
msg.net_sent
msg.net_recv
```

字段名必须完全一致。

---

## 10. 发布者 publisher 深入理解

发布者负责把消息发送到话题。

你的发布者对象是：

```python
self.status_publisher_
```

创建发布者：

```python
self.status_publisher_ = self.create_publisher(SystemStatus, 'sys_status', 10)
```

真正发布消息：

```python
self.status_publisher_.publish(msg)
```

这句执行一次，就往 `/sys_status` 话题发一条消息。

你的代码为什么会一直发？

因为你用了定时器：

```python
self.timer_ = self.create_timer(1.0, self.timer_callback)
```

意思是：

```text
每隔 1.0 秒，调用一次 self.timer_callback
```

`timer_callback()` 里会创建并发布一条消息。

所以整体流程是：

```text
程序启动
创建节点
创建发布者
创建定时器
每 1 秒执行一次 timer_callback
采集系统状态
填充 SystemStatus 消息
发布到 /sys_status
```

---

## 11. 订阅者 subscriber 是什么

你现在还没有写订阅者，但你需要理解它。

订阅者负责从话题接收消息。

如果以后你写一个订阅 `/sys_status` 的节点，核心代码会像这样：

```python
self.subscription = self.create_subscription(
    SystemStatus,
    'sys_status',
    self.listener_callback,
    10
)
```

意思是：

```text
订阅 /sys_status
消息类型是 SystemStatus
收到消息后调用 listener_callback
队列深度是 10
```

收到消息后：

```python
def listener_callback(self, msg):
    print(msg.cpu_percent)
```

完整关系：

```text
sys_status_pub 发布 SystemStatus 到 /sys_status
status_subscriber 从 /sys_status 接收 SystemStatus
```

---

## 12. 逐行理解你的发布节点

你的代码：

```python
import rclpy
from status_interfaces.msg import SystemStatus
from rclpy.node import Node
import psutil
import platform
```

逐行解释：

```python
import rclpy
```

导入 ROS2 Python 库。

```python
from status_interfaces.msg import SystemStatus
```

导入你自己定义的消息类型。

如果这一行报错，通常说明：

```text
接口包没编译
没有 source install/setup.bash
package.xml 依赖没写
```

```python
from rclpy.node import Node
```

导入节点基类。

```python
import psutil
```

用于读取 CPU、内存、网络状态。

```python
import platform
```

用于读取主机名。

---

## 13. 节点类逐行理解

```python
class SysStausPub(Node):
```

定义一个节点类。

注意：`SysStausPub` 里 `Staus` 看起来像拼写错误，通常应该是 `SysStatusPub`。不过类名拼错不一定影响运行，只是可读性不好。

```python
def __init__(self, node_name):
```

构造函数，创建对象时自动执行。

```python
super().__init__(node_name)
```

初始化 ROS2 节点。

如果少了这句，`create_publisher`、`create_timer`、`get_logger` 等节点能力就不能正常使用。

```python
self.status_publisher_ = self.create_publisher(SystemStatus, 'sys_status', 10)
```

创建发布者。

```python
self.timer_ = self.create_timer(1.0, self.timer_callback)
```

创建定时器，每秒执行一次 `timer_callback`。

---

## 14. 回调函数逐行理解

```python
def timer_callback(self):
```

这是定时器回调函数。

每秒执行一次。

```python
cpu_percent = psutil.cpu_percent()
```

读取 CPU 使用率。

例如返回：

```text
13.5
```

```python
memory_info = psutil.virtual_memory()
```

读取内存信息。

常用字段：

```text
memory_info.percent
memory_info.total
memory_info.available
```

```python
net_io_counters = psutil.net_io_counters()
```

读取网络收发统计。

常用字段：

```text
net_io_counters.bytes_sent
net_io_counters.bytes_recv
```

---

## 15. 创建并填充消息

```python
msg = SystemStatus()
```

创建一条空消息。

```python
msg.stamp = self.get_clock().now().to_msg()
```

设置当前 ROS2 时间。

```python
msg.host_name = platform.node()
```

设置电脑主机名。

```python
msg.cpu_percent = cpu_percent
```

设置 CPU 使用率。

```python
msg.memory_percent = memory_info.percent
```

设置内存使用率。

```python
msg.memory_total = memory_info.total / 1024 / 1024
```

把内存总量从字节转换成 MB。

```python
msg.memory_available = memory_info.available / 1024 / 1024
```

把可用内存从字节转换成 MB。

```python
msg.net_sent = net_io_counters.bytes_sent / 1024 / 1024
```

把网络发送总量从字节转换成 MB。

```python
msg.net_recv = net_io_counters.bytes_recv / 1024 / 1024
```

把网络接收总量从字节转换成 MB。

```python
self.get_logger().info(f"发布：{str(msg)}")
```

在终端打印消息内容，方便观察。

```python
self.status_publisher_.publish(msg)
```

真正发布消息。

---

## 16. `main()` 函数逐行理解

```python
def main():
    rclpy.init()
    node = SysStausPub('sys_status_pub')
    rclpy.spin(node)
    rclpy.shutdown()
```

逐行解释：

```python
rclpy.init()
```

初始化 ROS2 Python 环境。

```python
node = SysStausPub('sys_status_pub')
```

创建节点对象，节点名是 `sys_status_pub`。

```python
rclpy.spin(node)
```

让节点一直运行。

如果没有 `spin`，程序创建完节点后就退出了。

`spin` 会让 ROS2 持续处理：

```text
定时器回调
订阅回调
服务回调
参数事件
```

在你的节点里，`spin` 主要负责让定时器不断触发。

```python
rclpy.shutdown()
```

关闭 ROS2。

---

## 17. 从源码到运行，中间发生了什么

你写的源码在：

```text
src/status_publisher/status_publisher/sys_status_pub.py
```

编译后，ROS2 会把它安装到：

```text
install/status_publisher/lib/python3.10/site-packages/status_publisher/sys_status_pub.py
```

`ros2 run` 运行的是安装后的结果。

所以如果你改了 `src/` 里的源码，但是没有重新编译，运行的可能还是旧代码。

标准流程：

```bash
cd ~/ROS2_Repository/CHATP3/topic_practice_ws
colcon build --packages-select status_interfaces status_publisher
source install/setup.bash
ros2 run status_publisher sys_status_pub
```

如果你用了：

```bash
colcon build --symlink-install
```

Python 文件通常会用软链接方式安装，改 Python 源码后更方便。

但初学阶段先记住：

```text
改了代码后，重新 build，再 source。
改了 .msg 后，一定重新 build，再 source。
```

---

## 18. 创建工作空间

如果从零开始，一个工作空间通常这样创建：

```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws
```

结构：

```text
ros2_ws/
└── src/
```

所有功能包都放在 `src/` 里面。

编译时在工作空间根目录执行：

```bash
colcon build
```

不是在 `src/` 里面执行。

正确：

```bash
cd ~/ros2_ws
colcon build
```

不推荐：

```bash
cd ~/ros2_ws/src
colcon build
```

---

## 19. 创建 Python 功能包

创建普通 Python 功能包：

```bash
cd ~/ros2_ws/src
ros2 pkg create my_py_pkg --build-type ament_python --dependencies rclpy
```

解释：

```text
ros2 pkg create       创建功能包
my_py_pkg             包名
--build-type          构建类型
ament_python          Python 包常用构建类型
--dependencies rclpy  声明依赖 rclpy
```

如果要依赖你的消息包：

```bash
ros2 pkg create status_publisher --build-type ament_python --dependencies rclpy status_interfaces
```

创建后通常会有：

```text
status_publisher/
├── package.xml
├── setup.py
├── setup.cfg
├── resource/
├── status_publisher/
└── test/
```

---

## 20. 创建接口功能包

接口包通常用 `ament_cmake`：

```bash
cd ~/ros2_ws/src
ros2 pkg create status_interfaces --build-type ament_cmake --dependencies builtin_interfaces rosidl_default_generators
```

创建消息目录：

```bash
mkdir -p status_interfaces/msg
```

创建消息文件：

```bash
touch status_interfaces/msg/SystemStatus.msg
```

写入消息字段：

```text
builtin_interfaces/Time stamp
string host_name
float32 cpu_percent
float32 memory_percent
float32 memory_total
float32 memory_available
float64 net_sent
float64 net_recv
```

然后配置 `CMakeLists.txt` 和 `package.xml`。

---

## 21. 编译 colcon build

编译整个工作空间：

```bash
colcon build
```

只编译指定包：

```bash
colcon build --packages-select status_interfaces status_publisher
```

常用的 Python 开发方式：

```bash
colcon build --symlink-install
```

只编译一个包：

```bash
colcon build --packages-select status_publisher
```

但是要注意：

如果 `status_publisher` 依赖 `status_interfaces`，而你刚改过 `.msg`，建议一起编：

```bash
colcon build --packages-select status_interfaces status_publisher
```

---

## 22. source 是什么

编译完成后，需要执行：

```bash
source install/setup.bash
```

这一步的作用是告诉当前终端：

```text
这个工作空间里有哪些 ROS2 包
这些包安装在哪里
有哪些消息类型
有哪些可执行节点
```

如果不 source，常见问题：

```text
ros2 run 找不到包
ros2 interface show 找不到消息
Python import 找不到 status_interfaces
ros2 pkg list 看不到自己的包
```

每开一个新终端，都要重新 source：

```bash
cd ~/ROS2_Repository/CHATP3/topic_practice_ws
source install/setup.bash
```

如果想每次打开终端自动 source，可以把它加到 `~/.bashrc`，但初学阶段建议先手动执行，方便理解环境。

---

## 23. 运行节点

运行格式：

```bash
ros2 run 包名 可执行名
```

你的例子：

```bash
ros2 run status_publisher sys_status_pub
```

对应关系：

```text
status_publisher 是 package.xml 里的包名
sys_status_pub 是 setup.py 里 console_scripts 配置的可执行名
```

如果报：

```text
No executable found
```

优先检查：

```bash
ros2 pkg executables status_publisher
```

如果这里没有 `sys_status_pub`，检查 `setup.py` 的 `entry_points`。

---

## 24. 话题命令总览

### 24.1 查看话题列表

```bash
ros2 topic list
```

可能输出：

```text
/parameter_events
/rosout
/sys_status
```

解释：

```text
/sys_status 是你自己发布的
/rosout 是 ROS2 日志相关话题
/parameter_events 是参数事件相关话题
```

### 24.2 查看话题和类型

```bash
ros2 topic list -t
```

可能输出：

```text
/parameter_events [rcl_interfaces/msg/ParameterEvent]
/rosout [rcl_interfaces/msg/Log]
/sys_status [status_interfaces/msg/SystemStatus]
```

重点看：

```text
/sys_status [status_interfaces/msg/SystemStatus]
```

这说明 `/sys_status` 话题的消息类型是 `SystemStatus`。

### 24.3 查看话题详细信息

```bash
ros2 topic info /sys_status
```

可能输出：

```text
Type: status_interfaces/msg/SystemStatus
Publisher count: 1
Subscription count: 0
```

解释：

```text
Type                  话题消息类型
Publisher count       当前有几个发布者
Subscription count    当前有几个订阅者
```

如果你只运行了发布节点，没有运行订阅节点：

```text
Publisher count: 1
Subscription count: 0
```

这很正常。

### 24.4 查看话题数据

```bash
ros2 topic echo /sys_status
```

你会看到持续刷新的数据，例如：

```text
stamp:
  sec: 123
  nanosec: 456
host_name: your-host
cpu_percent: 12.5
memory_percent: 40.1
memory_total: 15900.0
memory_available: 8200.0
net_sent: 100.2
net_recv: 300.4
---
```

这说明发布节点确实在往话题里发数据。

### 24.5 查看发布频率

```bash
ros2 topic hz /sys_status
```

你的定时器是 1 秒一次，所以频率应该接近：

```text
1.0 Hz
```

如果明显不是 1 Hz，再检查定时器：

```python
self.create_timer(1.0, self.timer_callback)
```

### 24.6 查看带宽

```bash
ros2 topic bw /sys_status
```

这个命令看话题数据传输量。

你的消息很小，所以带宽会很低。

---

## 25. 节点命令总览

### 25.1 查看节点列表

```bash
ros2 node list
```

应该看到：

```text
/sys_status_pub
```

### 25.2 查看节点信息

```bash
ros2 node info /sys_status_pub
```

重点看 `Publishers` 区域。

你应该能看到类似：

```text
Publishers:
  /sys_status: status_interfaces/msg/SystemStatus
  /rosout: rcl_interfaces/msg/Log
```

解释：

```text
这个节点发布 /sys_status
消息类型是 status_interfaces/msg/SystemStatus
```

`/rosout` 是 ROS2 日志系统用的，看到它很正常。

---

## 26. 接口命令总览

### 26.1 查看消息定义

```bash
ros2 interface show status_interfaces/msg/SystemStatus
```

### 26.2 查看所有接口

```bash
ros2 interface list
```

### 26.3 搜索自己的接口

```bash
ros2 interface list | grep SystemStatus
```

如果有输出：

```text
status_interfaces/msg/SystemStatus
```

说明接口已经被 ROS2 找到了。

如果没有输出，通常是：

```text
没有编译接口包
没有 source
CMakeLists.txt 配置错误
package.xml 配置错误
```

---

## 27. 包命令总览

### 27.1 查看所有包

```bash
ros2 pkg list
```

### 27.2 搜索自己的包

```bash
ros2 pkg list | grep status
```

应该看到：

```text
status_interfaces
status_publisher
```

### 27.3 查看包安装位置

```bash
ros2 pkg prefix status_publisher
```

可能输出：

```text
/home/li/ROS2_Repository/CHATP3/topic_practice_ws/install/status_publisher
```

### 27.4 查看包里的可执行程序

```bash
ros2 pkg executables status_publisher
```

应该看到：

```text
status_publisher sys_status_pub
```

---

## 28. 当前项目的推荐运行顺序

终端 1：

```bash
cd ~/ROS2_Repository/CHATP3/topic_practice_ws
colcon build --packages-select status_interfaces status_publisher
source install/setup.bash
ros2 run status_publisher sys_status_pub
```

终端 2：

```bash
cd ~/ROS2_Repository/CHATP3/topic_practice_ws
source install/setup.bash
ros2 topic list -t
```

应该看到：

```text
/sys_status [status_interfaces/msg/SystemStatus]
```

继续：

```bash
ros2 topic info /sys_status
```

再继续：

```bash
ros2 topic echo /sys_status
```

再看频率：

```bash
ros2 topic hz /sys_status
```

---

## 29. 初学者最容易混淆的名字

同一个项目里有很多名字，它们不是一回事。

| 名称类型 | 当前项目里的值 | 在哪里定义 |
| --- | --- | --- |
| 工作空间名 | `topic_practice_ws` | 目录名 |
| 接口包名 | `status_interfaces` | `package.xml` |
| 发布包名 | `status_publisher` | `package.xml` |
| 消息名 | `SystemStatus` | `SystemStatus.msg` |
| 消息完整类型 | `status_interfaces/msg/SystemStatus` | 包名 + msg + 消息名 |
| Python 文件名 | `sys_status_pub.py` | 源码文件 |
| 可执行名 | `sys_status_pub` | `setup.py` 的 `console_scripts` |
| 节点名 | `/sys_status_pub` | `SysStausPub('sys_status_pub')` |
| 话题名 | `/sys_status` | `create_publisher(..., 'sys_status', ...)` |

记住：

```text
包名不是节点名
节点名不是话题名
话题名不是消息类型
Python 文件名也不是可执行名
```

只是初学时我们常常把它们起得很像，方便记忆。

---

## 30. 常见错误和排查

### 30.1 `AttributeError: object has no attribute`

例如：

```text
AttributeError: 'SystemStatus' object has no attribute 'cpu_persent'
```

原因：

```text
Python 代码里的字段名和 .msg 文件里的字段名不一致
```

排查：

```bash
ros2 interface show status_interfaces/msg/SystemStatus
```

确认字段到底叫什么。

修复：

```python
msg.cpu_percent = cpu_percent
```

不要写：

```python
msg.cpu_persent = cpu_percent
```

### 30.2 `ModuleNotFoundError: No module named status_interfaces`

可能原因：

```text
接口包没编译
没有 source install/setup.bash
package.xml 没写依赖
```

排查：

```bash
ros2 pkg list | grep status_interfaces
ros2 interface list | grep SystemStatus
```

修复：

```bash
colcon build --packages-select status_interfaces status_publisher
source install/setup.bash
```

### 30.3 `ros2 run` 找不到可执行程序

排查：

```bash
ros2 pkg executables status_publisher
```

如果看不到 `sys_status_pub`，检查 `setup.py`：

```python
entry_points={
    'console_scripts': [
        'sys_status_pub = status_publisher.sys_status_pub:main',
    ],
},
```

然后重新编译：

```bash
colcon build --packages-select status_publisher
source install/setup.bash
```

### 30.4 `ros2 topic list -t` 看不到 `/sys_status`

可能原因：

```text
发布节点没有运行
节点启动后崩溃了
source 的不是当前工作空间
ROS_DOMAIN_ID 不一致
```

排查顺序：

```bash
ros2 node list
ros2 topic list -t
ros2 run status_publisher sys_status_pub
```

如果节点运行终端有 traceback，先修 traceback。

### 30.5 改了代码但运行还是旧效果

可能原因：

```text
改了 src 里的代码，但 ros2 run 执行的是 install 里的旧代码
```

修复：

```bash
colcon build --packages-select status_publisher
source install/setup.bash
```

开发 Python 包时建议：

```bash
colcon build --symlink-install
```

---

## 31. 发布者和订阅者的最小练习

为了真正理解，建议你下一步写一个订阅者。

目标：

```text
订阅 /sys_status
打印 CPU 和内存使用率
```

订阅者核心代码长这样：

```python
import rclpy
from rclpy.node import Node
from status_interfaces.msg import SystemStatus


class SysStatusSub(Node):
    def __init__(self):
        super().__init__('sys_status_sub')
        self.subscription = self.create_subscription(
            SystemStatus,
            'sys_status',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        self.get_logger().info(
            f'CPU: {msg.cpu_percent:.1f}%, Memory: {msg.memory_percent:.1f}%'
        )


def main():
    rclpy.init()
    node = SysStatusSub()
    rclpy.spin(node)
    rclpy.shutdown()
```

如果这个订阅者运行起来，通信关系就完整了：

```text
/sys_status_pub  发布  /sys_status
/sys_status_sub  订阅  /sys_status
```

---

## 32. 学习时建议你按这个顺序敲命令

第一步，确认包存在：

```bash
ros2 pkg list | grep status
```

第二步，确认接口存在：

```bash
ros2 interface show status_interfaces/msg/SystemStatus
```

第三步，启动发布节点：

```bash
ros2 run status_publisher sys_status_pub
```

第四步，另开终端看节点：

```bash
ros2 node list
```

第五步，看节点详情：

```bash
ros2 node info /sys_status_pub
```

第六步，看话题：

```bash
ros2 topic list -t
```

第七步，看话题数据：

```bash
ros2 topic echo /sys_status
```

第八步，看频率：

```bash
ros2 topic hz /sys_status
```

这样你会把“包、接口、节点、话题、数据”串起来。

---

## 33. 建议的理解路线

不要一开始就背所有命令。

先理解这三句话：

```text
节点是运行中的程序。
话题是节点之间传数据的通道。
消息是话题里数据的格式。
```

再理解这两句话：

```text
发布者往话题发消息。
订阅者从话题收消息。
```

最后理解工程结构：

```text
功能包 package 用来组织代码。
接口包 interface package 用来定义 msg。
colcon build 把 src 里的包编译安装到 install。
source install/setup.bash 让当前终端认识这些包。
```

---

## 34. 当前项目一句话复盘

你的项目做了这件事：

```text
status_interfaces 定义 SystemStatus 消息格式。
status_publisher 提供 sys_status_pub 节点。
sys_status_pub 每秒读取 CPU、内存、网络信息。
节点把这些信息填入 SystemStatus 消息。
节点把消息发布到 /sys_status 话题。
你可以用 ros2 topic echo /sys_status 查看数据。
```

这就是一个完整的 ROS2 发布者例子。

下一步最适合练习的是：

```text
写一个订阅者节点，订阅 /sys_status，并打印 CPU 和内存。
```

