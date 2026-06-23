# ROS 2 服务通信入门：简单 Python 版

这份笔记面向刚开始学 ROS 2 服务通信的人。

目标不是写复杂业务，而是把 ROS 2 代码结构看懂：

```text
服务接口 .srv
服务端 server
客户端 client
参数 parameter
参数更新回调
参数事件监听
远程修改参数
```

例子保持简单：

```text
客户端：请机器人去 room_A。
服务端：根据参数决定是否接受任务。
```

服务通信最重要的一句话：

```text
客户端填 Request，服务端填 Response。
```

---

## 1. 服务通信是什么

ROS 2 里常见通信方式有三种：

| 通信方式 | 英文 | 适合场景 | 感觉 |
| --- | --- | --- | --- |
| 话题 | Topic | 一直发数据，例如速度、雷达、图像 | 一直广播 |
| 服务 | Service | 问一次，答一次，例如查询状态、下发简单任务 | 一问一答 |
| 动作 | Action | 长时间任务，例如导航，可以反馈进度 | 下任务，等过程 |

这篇只讲 Service。

服务流程：

```text
客户端创建 request
客户端发送 request
服务端收到 request
服务端填写 response
服务端返回 response
客户端拿到 response
```

---

## 2. 定义服务接口 `PatrolTask.srv`

文件位置：

```text
src/chapt4_interfaces/srv/PatrolTask.srv
```

内容：

```srv
string target_name
---
bool accepted
string message
```

解释：

```text
--- 上面是 Request，客户端发给服务端。
--- 下面是 Response，服务端返回给客户端。
```

逐行看：

```srv
string target_name
```

解释：客户端告诉服务端目标点名字，比如 `room_A`。

```srv
---
```

解释：分隔线，上面是请求，下面是响应。

```srv
bool accepted
```

解释：服务端告诉客户端，任务是否接受。

```srv
string message
```

解释：服务端返回一句说明。

---

## 3. 创建接口包

进入工作空间：

```bash
cd ~/ROS2_Repository/chapt4/chapt4_ws
```

创建接口包：

```bash
cd src
ros2 pkg create chapt4_interfaces --build-type ament_cmake
```

创建 `srv` 目录：

```bash
cd ~/ROS2_Repository/chapt4/chapt4_ws
mkdir -p src/chapt4_interfaces/srv
```

新建文件：

```text
src/chapt4_interfaces/srv/PatrolTask.srv
```

写入：

```srv
string target_name
---
bool accepted
string message
```

---

## 4. 配置接口包 `CMakeLists.txt`

打开：

```text
src/chapt4_interfaces/CMakeLists.txt
```

写成：

```cmake
cmake_minimum_required(VERSION 3.8)
project(chapt4_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/PatrolTask.srv"
)

ament_package()
```

关键是：

```cmake
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/PatrolTask.srv"
)
```

解释：

```text
让 ROS 2 根据 PatrolTask.srv 生成 Python 可用的服务类型。
```

后面 Python 才能写：

```python
from chapt4_interfaces.srv import PatrolTask
```

---

## 5. 配置接口包 `package.xml`

打开：

```text
src/chapt4_interfaces/package.xml
```

确认有：

```xml
<buildtool_depend>ament_cmake</buildtool_depend>

<build_depend>rosidl_default_generators</build_depend>
<exec_depend>rosidl_default_runtime</exec_depend>

<member_of_group>rosidl_interface_packages</member_of_group>
```

解释：

```text
rosidl_default_generators  生成接口代码
rosidl_default_runtime     运行时使用接口
rosidl_interface_packages  告诉 ROS 2：这是接口包
```

---

## 6. 构建并检查接口

回到工作空间：

```bash
cd ~/ROS2_Repository/chapt4/chapt4_ws
colcon build --packages-select chapt4_interfaces
source install/setup.bash
```

查看接口：

```bash
ros2 interface show chapt4_interfaces/srv/PatrolTask
```

应该看到：

```text
string target_name
---
bool accepted
string message
```

---

## 7. 创建 Python 功能包

创建包：

```bash
cd ~/ROS2_Repository/chapt4/chapt4_ws/src
ros2 pkg create patrol_service_demo --build-type ament_python --dependencies rclpy chapt4_interfaces rcl_interfaces
```

本教程写 4 个 Python 文件：

```text
patrol_server.py             服务端
patrol_client.py             客户端
parameter_event_watcher.py   监听参数事件
remote_param_setter.py       远程修改参数
```

---

## 8. 服务端代码 `patrol_server.py`

文件位置：

```text
src/patrol_service_demo/patrol_service_demo/patrol_server.py
```

完整代码：

```python
import rclpy
from chapt4_interfaces.srv import PatrolTask
from rcl_interfaces.msg import SetParametersResult
from rclpy.node import Node


class PatrolServer(Node):
    def __init__(self):
        super().__init__('patrol_server')

        self.declare_parameter('robot_name', 'robot_01')
        self.declare_parameter('allow_task', True)

        self.add_on_set_parameters_callback(self.on_parameter_update)

        self.service = self.create_service(
            PatrolTask,
            'patrol_task',
            self.handle_patrol_task,
        )

        self.get_logger().info('patrol_task service is ready')

    def on_parameter_update(self, parameters):
        for parameter in parameters:
            if parameter.name == 'robot_name' and parameter.value == '':
                return SetParametersResult(
                    successful=False,
                    reason='robot_name cannot be empty',
                )

        return SetParametersResult(successful=True)

    def handle_patrol_task(self, request, response):
        robot_name = self.get_parameter('robot_name').value
        allow_task = self.get_parameter('allow_task').value

        if allow_task:
            response.accepted = True
            response.message = robot_name + ' accepted target: ' + request.target_name
        else:
            response.accepted = False
            response.message = robot_name + ' rejected target: ' + request.target_name

        return response


def main(args=None):
    rclpy.init(args=args)
    node = PatrolServer()

    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
```

---

## 9. 服务端逐句解释

```python
import rclpy
```

解释：导入 ROS 2 的 Python 库。

```python
from chapt4_interfaces.srv import PatrolTask
```

解释：导入自己定义的服务类型。

```python
from rcl_interfaces.msg import SetParametersResult
```

解释：参数更新回调要用它返回“成功”或者“失败”。

```python
from rclpy.node import Node
```

解释：导入 ROS 2 节点基类。

```python
class PatrolServer(Node):
```

解释：定义一个服务端节点。

```python
super().__init__('patrol_server')
```

解释：创建节点，节点名是 `patrol_server`。

### 9.1 声明参数

```python
self.declare_parameter('robot_name', 'robot_01')
```

解释：声明参数 `robot_name`，默认值是 `robot_01`。

```python
self.declare_parameter('allow_task', True)
```

解释：声明参数 `allow_task`，默认允许接任务。

参数不是普通变量。

参数可以在运行时用命令查看和修改：

```bash
ros2 param get /patrol_server robot_name
ros2 param set /patrol_server robot_name robot_02
```

### 9.2 注册参数更新回调

```python
self.add_on_set_parameters_callback(self.on_parameter_update)
```

解释：以后有人修改本节点参数时，ROS 2 会先调用 `on_parameter_update()`。

可以这样理解：

```text
有人想改参数
  ↓
先进入 on_parameter_update()
  ↓
返回 successful=True，参数才会真的修改
返回 successful=False，参数修改失败
```

### 9.3 创建服务

```python
self.service = self.create_service(
    PatrolTask,
    'patrol_task',
    self.handle_patrol_task,
)
```

解释：

```text
PatrolTask              服务类型
patrol_task             服务名字
handle_patrol_task      服务回调函数
```

客户端调用 `/patrol_task` 时，ROS 2 自动执行：

```python
handle_patrol_task(request, response)
```

你不用手动调用它。

### 9.4 参数更新回调

```python
def on_parameter_update(self, parameters):
```

解释：定义参数更新回调函数。

```python
for parameter in parameters:
```

解释：一次可能修改多个参数，所以一个一个检查。

```python
if parameter.name == 'robot_name' and parameter.value == '':
```

解释：如果要修改的是 `robot_name`，并且新值是空字符串，就拒绝。

```python
return SetParametersResult(
    successful=False,
    reason='robot_name cannot be empty',
)
```

解释：告诉 ROS 2，这次参数修改失败。

```python
return SetParametersResult(successful=True)
```

解释：检查通过，允许修改参数。

### 9.5 服务回调

```python
def handle_patrol_task(self, request, response):
```

解释：服务回调函数。

三个参数：

```text
self      当前节点对象
request   客户端发来的请求
response  服务端要填写的响应
```

`request` 里有什么？

```text
PatrolTask.srv 的上半部分写了 string target_name
所以 request 里有 request.target_name
```

`response` 里有什么？

```text
PatrolTask.srv 的下半部分写了 bool accepted 和 string message
所以 response 里有 response.accepted 和 response.message
```

```python
robot_name = self.get_parameter('robot_name').value
```

解释：读取参数 `robot_name` 的值。

```python
allow_task = self.get_parameter('allow_task').value
```

解释：读取参数 `allow_task` 的值。

```python
if allow_task:
```

解释：如果允许接任务，就进入接受分支。

```python
response.accepted = True
```

解释：告诉客户端，任务被接受。

```python
response.message = robot_name + ' accepted target: ' + request.target_name
```

解释：把返回说明写进 `response.message`。

```python
else:
```

解释：如果不允许接任务，就进入拒绝分支。

```python
response.accepted = False
```

解释：告诉客户端，任务被拒绝。

```python
return response
```

解释：把响应返回给 ROS 2，ROS 2 再发回客户端。

---

## 10. 客户端代码 `patrol_client.py`

文件位置：

```text
src/patrol_service_demo/patrol_service_demo/patrol_client.py
```

完整代码：

```python
import rclpy
from chapt4_interfaces.srv import PatrolTask
from rclpy.node import Node


class PatrolClient(Node):
    def __init__(self):
        super().__init__('patrol_client')

        self.declare_parameter('target_name', 'room_A')

        self.client = self.create_client(PatrolTask, 'patrol_task')

    def send_request(self):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('waiting for patrol_task service...')

        request = PatrolTask.Request()
        request.target_name = self.get_parameter('target_name').value

        future = self.client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        response = future.result()
        self.get_logger().info('accepted: ' + str(response.accepted))
        self.get_logger().info('message: ' + response.message)


def main(args=None):
    rclpy.init(args=args)
    node = PatrolClient()

    try:
        node.send_request()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
```

---

## 11. 客户端逐句解释

```python
class PatrolClient(Node):
```

解释：定义客户端节点。

```python
super().__init__('patrol_client')
```

解释：创建节点，节点名是 `patrol_client`。

```python
self.declare_parameter('target_name', 'room_A')
```

解释：声明客户端参数，默认目标点是 `room_A`。

```python
self.client = self.create_client(PatrolTask, 'patrol_task')
```

解释：创建客户端，用来调用 `patrol_task` 服务。

这里必须和服务端一致：

```text
服务类型：PatrolTask
服务名字：patrol_task
```

```python
while not self.client.wait_for_service(timeout_sec=1.0):
```

解释：等待服务端启动。

```python
request = PatrolTask.Request()
```

解释：创建请求对象。

```python
request.target_name = self.get_parameter('target_name').value
```

解释：把客户端参数 `target_name` 放进请求。

```python
future = self.client.call_async(request)
```

解释：异步发送请求。

先把 `future` 理解成：

```text
服务端以后会返回的结果
```

```python
rclpy.spin_until_future_complete(self, future)
```

解释：等待服务端返回。

```python
response = future.result()
```

解释：取出服务端返回的响应。

---

## 12. 监听参数事件 `parameter_event_watcher.py`

参数事件是什么？

```text
当 ROS 2 节点的参数新增、修改、删除时，系统会发布 /parameter_events 消息。
```

文件位置：

```text
src/patrol_service_demo/patrol_service_demo/parameter_event_watcher.py
```

完整代码：

```python
import rclpy
from rcl_interfaces.msg import ParameterEvent
from rclpy.node import Node
from rclpy.parameter import parameter_value_to_python


class ParameterEventWatcher(Node):
    def __init__(self):
        super().__init__('parameter_event_watcher')

        self.subscription = self.create_subscription(
            ParameterEvent,
            '/parameter_events',
            self.on_parameter_event,
            10,
        )

        self.get_logger().info('watching /parameter_events')

    def on_parameter_event(self, event):
        for parameter in event.new_parameters:
            value = parameter_value_to_python(parameter.value)
            self.get_logger().info(
                'new: node=' + event.node
                + ' name=' + parameter.name
                + ' value=' + str(value)
            )

        for parameter in event.changed_parameters:
            value = parameter_value_to_python(parameter.value)
            self.get_logger().info(
                'changed: node=' + event.node
                + ' name=' + parameter.name
                + ' value=' + str(value)
            )

        for parameter in event.deleted_parameters:
            self.get_logger().info(
                'deleted: node=' + event.node
                + ' name=' + parameter.name
            )


def main(args=None):
    rclpy.init(args=args)
    node = ParameterEventWatcher()

    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
```

逐句看核心：

```python
self.subscription = self.create_subscription(
    ParameterEvent,
    '/parameter_events',
    self.on_parameter_event,
    10,
)
```

解释：

```text
订阅 /parameter_events 这个话题。
只要有参数变化，ROS 2 就调用 on_parameter_event()。
```

```python
def on_parameter_event(self, event):
```

解释：参数事件回调函数。

```python
event.new_parameters
```

解释：新出现的参数。

```python
event.changed_parameters
```

解释：被修改的参数。

```python
event.deleted_parameters
```

解释：被删除的参数。

```python
parameter_value_to_python(parameter.value)
```

解释：把 ROS 2 参数值转换成普通 Python 值，方便打印。

---

## 13. 远程修改参数 `remote_param_setter.py`

远程修改参数是什么意思？

```text
一个节点去修改另一个节点的参数。
```

这里让 `remote_param_setter` 去修改 `/patrol_server` 的参数。

文件位置：

```text
src/patrol_service_demo/patrol_service_demo/remote_param_setter.py
```

完整代码：

```python
import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.parameter_client import AsyncParameterClient


class RemoteParamSetter(Node):
    def __init__(self):
        super().__init__('remote_param_setter')

        self.parameter_client = AsyncParameterClient(self, '/patrol_server')

    def set_remote_parameters(self):
        while not self.parameter_client.wait_for_services(timeout_sec=1.0):
            self.get_logger().info('waiting for patrol_server parameter service...')

        parameters = [
            Parameter('robot_name', Parameter.Type.STRING, 'robot_02'),
            Parameter('allow_task', Parameter.Type.BOOL, False),
        ]

        future = self.parameter_client.set_parameters(parameters)
        rclpy.spin_until_future_complete(self, future)

        results = future.result().results

        for result in results:
            if result.successful:
                self.get_logger().info('set parameter success')
            else:
                self.get_logger().info('set parameter failed: ' + result.reason)


def main(args=None):
    rclpy.init(args=args)
    node = RemoteParamSetter()

    try:
        node.set_remote_parameters()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
```

逐句看核心：

```python
self.parameter_client = AsyncParameterClient(self, '/patrol_server')
```

解释：创建一个参数客户端，目标节点是 `/patrol_server`。

```python
while not self.parameter_client.wait_for_services(timeout_sec=1.0):
```

解释：等待 `/patrol_server` 的参数服务准备好。

每个 ROS 2 节点默认都有参数服务，例如：

```text
/patrol_server/get_parameters
/patrol_server/set_parameters
/patrol_server/list_parameters
```

```python
Parameter('robot_name', Parameter.Type.STRING, 'robot_02')
```

解释：准备把 `robot_name` 改成 `robot_02`。

```python
Parameter('allow_task', Parameter.Type.BOOL, False)
```

解释：准备把 `allow_task` 改成 `False`。

```python
future = self.parameter_client.set_parameters(parameters)
```

解释：发送远程参数修改请求。

```python
results = future.result().results
```

解释：取出参数修改结果。

---

## 14. 参数更新回调和参数事件的区别

服务端里的这句：

```python
self.add_on_set_parameters_callback(self.on_parameter_update)
```

意思是：

```text
参数修改前检查。
可以同意，也可以拒绝。
```

参数事件监听：

```python
self.create_subscription(
    ParameterEvent,
    '/parameter_events',
    self.on_parameter_event,
    10,
)
```

意思是：

```text
参数修改后通知。
只能观察，不能拒绝。
```

一句话记住：

```text
on_parameter_update      修改前检查，可以拒绝
/parameter_events        修改后广播，只能观察
```

---

## 15. 配置 `setup.py`

打开：

```text
src/patrol_service_demo/setup.py
```

找到 `entry_points`，写成：

```python
entry_points={
    'console_scripts': [
        'patrol_server = patrol_service_demo.patrol_server:main',
        'patrol_client = patrol_service_demo.patrol_client:main',
        'parameter_event_watcher = patrol_service_demo.parameter_event_watcher:main',
        'remote_param_setter = patrol_service_demo.remote_param_setter:main',
    ],
},
```

解释：

```text
左边是 ros2 run 使用的命令名。
右边是要执行的 Python 文件和 main 函数。
```

例如：

```python
'patrol_server = patrol_service_demo.patrol_server:main'
```

对应：

```bash
ros2 run patrol_service_demo patrol_server
```

---

## 16. 配置 `package.xml`

打开：

```text
src/patrol_service_demo/package.xml
```

确认有：

```xml
<depend>rclpy</depend>
<depend>chapt4_interfaces</depend>
<depend>rcl_interfaces</depend>
```

解释：

```text
rclpy               写 Python ROS 2 节点
chapt4_interfaces   使用 PatrolTask.srv
rcl_interfaces      使用参数事件和参数结果类型
```

---

## 17. 构建

回到工作空间：

```bash
cd ~/ROS2_Repository/chapt4/chapt4_ws
colcon build
source install/setup.bash
```

每开一个新终端，都要执行：

```bash
cd ~/ROS2_Repository/chapt4/chapt4_ws
source install/setup.bash
```

---

## 18. 运行服务端和客户端

终端 1，运行服务端：

```bash
ros2 run patrol_service_demo patrol_server
```

终端 2，运行客户端：

```bash
ros2 run patrol_service_demo patrol_client
```

客户端应该看到类似：

```text
accepted: True
message: robot_01 accepted target: room_A
```

客户端传不同目标：

```bash
ros2 run patrol_service_demo patrol_client --ros-args -p target_name:=room_B
```

---

## 19. 命令行查看和修改参数

查看参数列表：

```bash
ros2 param list /patrol_server
```

查看机器人名字：

```bash
ros2 param get /patrol_server robot_name
```

修改机器人名字：

```bash
ros2 param set /patrol_server robot_name robot_02
```

禁止接任务：

```bash
ros2 param set /patrol_server allow_task false
```

再运行客户端：

```bash
ros2 run patrol_service_demo patrol_client
```

这次客户端应该看到类似：

```text
accepted: False
message: robot_02 rejected target: room_A
```

测试参数更新回调：

```bash
ros2 param set /patrol_server robot_name ""
```

应该会失败，因为服务端不允许 `robot_name` 为空。

---

## 20. 运行参数事件监听

终端 1，运行服务端：

```bash
ros2 run patrol_service_demo patrol_server
```

终端 2，运行参数事件监听节点：

```bash
ros2 run patrol_service_demo parameter_event_watcher
```

终端 3，修改服务端参数：

```bash
ros2 param set /patrol_server robot_name robot_03
```

参数事件监听节点会看到参数变化。

---

## 21. 运行远程修改参数节点

终端 1，运行服务端：

```bash
ros2 run patrol_service_demo patrol_server
```

终端 2，运行参数事件监听节点：

```bash
ros2 run patrol_service_demo parameter_event_watcher
```

终端 3，运行远程修改参数节点：

```bash
ros2 run patrol_service_demo remote_param_setter
```

它会把 `/patrol_server` 的参数改成：

```text
robot_name = robot_02
allow_task = False
```

然后再运行客户端：

```bash
ros2 run patrol_service_demo patrol_client
```

应该看到任务被拒绝。

---

## 22. 最重要的总结

服务端创建服务：

```python
self.service = self.create_service(
    PatrolTask,
    'patrol_task',
    self.handle_patrol_task,
)
```

解释：

```text
服务类型：PatrolTask
服务名字：patrol_task
回调函数：handle_patrol_task
```

服务回调：

```python
def handle_patrol_task(self, request, response):
```

解释：

```text
request 是客户端发来的。
response 是服务端填写的。
它们是 ROS 2 自动传进来的。
```

客户端发送请求：

```python
request = PatrolTask.Request()
request.target_name = 'room_A'
future = self.client.call_async(request)
```

解释：

```text
创建 Request。
填写 Request。
发送 Request。
```

参数修改前检查：

```python
self.add_on_set_parameters_callback(self.on_parameter_update)
```

解释：

```text
别人修改我这个节点参数前，先让我检查。
```

参数事件监听：

```python
'/parameter_events'
```

解释：

```text
系统里参数变化后，会发到这个话题。
```

远程修改参数：

```python
AsyncParameterClient(self, '/patrol_server')
```

解释：

```text
创建一个客户端，专门修改 /patrol_server 的参数。
```

最后只记一句：

```text
服务是 request 和 response；参数是运行时配置；参数事件是观察配置变化。
```
