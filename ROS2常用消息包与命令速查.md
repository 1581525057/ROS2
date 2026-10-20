# ROS 2 常用消息包与命令速查

> 适合 ROS 2 Humble 的 Python / C++ 初学与复习。命令默认在已经加载 ROS 2 环境的终端中执行。

## 0. 先加载环境

每开一个新终端，都先加载 ROS 2：

```bash
source /opt/ros/humble/setup.bash
```

进入自己的工作空间后，编译成功还要加载本工作空间：

```bash
source install/setup.bash
```

可以把这两行写入 `~/.bashrc`，以后终端会自动加载。

---

## 1. 最常用的消息包

ROS 2 的话题必须指定一种消息类型。导入形式通常是：

```python
from 包名.msg import 消息类型
```

| 消息包 | 常用消息 | 典型用途 |
| --- | --- | --- |
| `std_msgs.msg` | `String`、`Int32`、`Float64`、`Bool` | 文字、数值、开关等基础练习 |
| `geometry_msgs.msg` | `Twist`、`Pose`、`Point`、`Quaternion`、`TransformStamped` | 速度、位姿、坐标系变换 |
| `sensor_msgs.msg` | `Image`、`LaserScan`、`Imu`、`JointState`、`PointCloud2` | 相机、激光雷达、IMU、关节、点云 |
| `nav_msgs.msg` | `Odometry`、`Path`、`OccupancyGrid` | 里程计、规划路径、栅格地图 |
| `visualization_msgs.msg` | `Marker`、`MarkerArray` | 在 RViz 中显示箭头、点、线、文字等 |
| `trajectory_msgs.msg` | `JointTrajectory`、`JointTrajectoryPoint` | 机械臂、关节运动轨迹 |
| `diagnostic_msgs.msg` | `DiagnosticArray`、`DiagnosticStatus` | 硬件和节点健康状态 |
| `builtin_interfaces.msg` | `Time`、`Duration` | 时间戳、时长；常被其他消息内部使用 |

### 最值得优先掌握的消息

#### `std_msgs/msg/String`

```python
from std_msgs.msg import String

msg = String()
msg.data = 'forward'
```

只有一个字段：`data`。

#### `geometry_msgs/msg/Twist`：控制移动机器人

```python
from geometry_msgs.msg import Twist

msg = Twist()
msg.linear.x = 0.2     # 前进 / 后退速度，通常单位 m/s
msg.linear.y = 0.0
msg.linear.z = 0.0
msg.angular.x = 0.0
msg.angular.y = 0.0
msg.angular.z = 0.5    # 左右转向角速度，通常单位 rad/s
```

常见约定：

```text
linear.x   前进为正，后退为负
angular.z  左转为正，右转为负
```

#### `sensor_msgs/msg/LaserScan`：二维激光雷达

```python
from sensor_msgs.msg import LaserScan

def scan_callback(msg):
    front_distance = msg.ranges[0]
    print(front_distance)
```

常用字段：`ranges`（每个方向的测距数组）、`angle_min`、`angle_max`、`angle_increment`。

#### `sensor_msgs/msg/Image`：相机图像

```python
from sensor_msgs.msg import Image
```

图像原始数据在 `msg.data`，实际项目一般结合 `cv_bridge` 转为 OpenCV 图像。

#### `nav_msgs/msg/Odometry`：机器人位置和速度

```python
from nav_msgs.msg import Odometry

def odom_callback(msg):
    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y
    speed = msg.twist.twist.linear.x
```

### 查看任意消息的字段

```bash
ros2 interface show std_msgs/msg/String
ros2 interface show geometry_msgs/msg/Twist
ros2 interface show sensor_msgs/msg/LaserScan
ros2 interface show nav_msgs/msg/Odometry
```

不知道消息名时：

```bash
ros2 interface list
ros2 interface package sensor_msgs
```

---

## 2. 创建工作空间与功能包

ROS 2 里“包（package）”是代码的最小组织单位；一个工作空间可以放多个包。

### 创建工作空间

```bash
mkdir -p ~/ROS2/my_ws/src
cd ~/ROS2/my_ws
colcon build
source install/setup.bash
```

目录结构：

```text
my_ws/
├── src/       # 自己写的功能包放这里
├── build/     # 编译过程中生成
├── install/   # 可运行的安装结果
└── log/       # 编译日志
```

### 创建 Python 功能包（`ament_python`）

先进入工作空间的 `src`：

```bash
cd ~/ROS2/my_ws/src
ros2 pkg create --build-type ament_python --license Apache-2.0 my_python_pkg
```

创建时顺便生成一个节点骨架：

```bash
ros2 pkg create --build-type ament_python --license Apache-2.0 \
  --node-name talker my_python_pkg
```

### 创建 C++ 功能包（`ament_cmake`）

```bash
cd ~/ROS2/my_ws/src
ros2 pkg create --build-type ament_cmake --license Apache-2.0 my_cpp_pkg
```

创建时声明依赖：

```bash
ros2 pkg create --build-type ament_cmake --license Apache-2.0 \
  --dependencies rclcpp std_msgs geometry_msgs my_cpp_pkg
```

### 编译包

必须回到工作空间根目录（不是 `src`）：

```bash
cd ~/ROS2/my_ws
colcon build
source install/setup.bash
```

只编译一个包：

```bash
colcon build --packages-select my_python_pkg
source install/setup.bash
```

Python 开发时推荐使用软链接安装，修改 Python 文件后通常无需重新复制文件：

```bash
colcon build --symlink-install
source install/setup.bash
```

> 修改 `setup.py`、`package.xml`、新增入口点等安装配置后，仍应重新执行 `colcon build`。

### 运行节点

```bash
ros2 run 包名 可执行文件名
```

示例：

```bash
ros2 run topic_rclpy topic_publisher
ros2 run topic_rclpy topic_subscribe
```

---

## 3. 话题（Topic）常用命令

话题用于持续、异步地传递数据：发布者发布，订阅者接收。

### 查看话题

```bash
ros2 topic list
ros2 topic list -t              # 同时显示消息类型
ros2 topic info /command        # 查看发布者/订阅者数量
ros2 topic info /command -v     # 查看节点名和 QoS 等详细信息
ros2 topic echo /cmd_vel --field linear #只看线速度消息 
```

### 查看话题内容

```bash
ros2 topic echo /command
ros2 topic echo /cmd_vel
```

只查看一条消息后退出：

```bash
ros2 topic echo /command --once
```

### 从终端临时发布消息

发布一次字符串：

```bash
ros2 topic pub --once /command std_msgs/msg/String "{data: 'forward'}"
```

持续以 2 Hz 发布：

```bash
ros2 topic pub -r 2 /command std_msgs/msg/String "{data: 'forward'}"
```

发布停止用的速度：

```bash
ros2 topic pub --once /cmd_vel geometry_msgs/msg/Twist \
  "{linear: {x: 0.0}, angular: {z: 0.0}}"
```

### 查看频率和带宽

```bash
ros2 topic hz /command
ros2 topic bw /camera/image_raw
```

### 图形化查看节点—话题关系

```bash
rqt_graph
```

如果图中没有话题，先确认节点仍在运行，再点击刷新，并取消 `Nodes only` 等隐藏话题的选项。

---

## 4. 节点（Node）常用命令

```bash
ros2 node list
ros2 node info /Pubilsher
ros2 node info /Subscirible
```

`ros2 node info` 可以看到该节点的发布者、订阅者、服务和参数。

---

## 5. 参数（Parameter）常用命令

参数用于在不改代码的情况下配置节点行为，例如速度、话题名、是否启用某功能。

```bash
ros2 param list
ros2 param list /节点名
ros2 param get /节点名 参数名
ros2 param set /节点名 参数名 参数值
ros2 param dump /节点名
```

示例：

```bash
ros2 param list /Pubilsher
```

启动节点时传入参数：

```bash
ros2 run 包名 可执行文件名 --ros-args -p speed:=0.2
```

---

## 6. 服务（Service）与动作（Action）常用命令

### 服务：一次请求，对应一次响应

```bash
ros2 service list
ros2 service list -t
ros2 service type /服务名
ros2 service find example_interfaces/srv/AddTwoInts
ros2 service call /服务名 服务类型 "{字段名: 值}"
```

例：

```bash
ros2 service call /add_two_ints example_interfaces/srv/AddTwoInts "{a: 2, b: 3}"
```

查看服务定义：

```bash
ros2 interface show example_interfaces/srv/AddTwoInts
```

### 动作：耗时任务，可持续反馈，也可取消

```bash
ros2 action list
ros2 action list -t
ros2 action info /动作名
ros2 action send_goal /动作名 动作类型 "{字段名: 值}" --feedback
```

查看动作定义：

```bash
ros2 interface show example_interfaces/action/Fibonacci
```

---

## 7. TF 坐标变换常用命令

TF 用来描述两个坐标系之间的位置和朝向。下面以机器人底座 `base_link`（父坐标系）和激光雷达 `base_laser`（子坐标系）为例。每个新终端先执行本文件第 0 节的 `source` 命令。

### 发布固定不变的坐标变换

```bash
ros2 run tf2_ros static_transform_publisher \
  --x 0.1 --y 0.0 --z 0.2 \
  --roll 0.0 --pitch 0.0 --yaw 0.0 \
  --frame-id base_link --child-frame-id base_laser
```

注释：`--x/--y/--z` 表示子坐标系原点在父坐标系中的位置，单位为米；`--roll/--pitch/--yaw` 分别表示绕 X/Y/Z 轴的旋转，单位为弧度。这个例子表示激光雷达相对底座前移 0.1 m、上移 0.2 m，方向不旋转。命令需要保持运行；按 `Ctrl+C` 停止发布。**`0.2` 与 `--roll` 之间必须有空格。**

想练习旋转，可在另一个终端使用不同的子坐标系名，避免与上面的发布者冲突：

```bash
ros2 run tf2_ros static_transform_publisher \
  --x 0.1 --y 0.0 --z 0.2 \
  --roll 0.0 --pitch 0.0 --yaw 0.5 \
  --frame-id base_link --child-frame-id base_laser_rotated
```

注释：`--yaw 0.5` 表示绕 Z 轴旋转 0.5 弧度，约 28.6°；真实传感器的参数应按实际安装位置填写。不要同时为同一个子坐标系发布两组不同的变换。

### 查询与检查变换

```bash
ros2 run tf2_ros tf2_echo base_link base_laser  # 持续查看 base_link 到 base_laser 的平移和旋转；Ctrl+C 退出
ros2 topic echo /tf_static --once              # 查看一条静态变换消息
ros2 topic echo /tf --once                     # 查看一条动态变换消息；没有动态发布者时会等待
ros2 topic list -t                             # 确认 /tf 与 /tf_static 的消息类型
ros2 interface show geometry_msgs/msg/TransformStamped  # 查看变换消息中的父子坐标系、平移和四元数字段
```

注释：固定安装的传感器通常发布到 `/tf_static`；随机器人运动而变化的坐标系发布到 `/tf`。`tf2_echo` 可以输出 RPY 角度与四元数，便于核对旋转方向。

### 查看坐标系关系图与三维坐标轴

```bash
ros2 run tf2_tools view_frames  # 收集当前变换，生成 frames.pdf；需保持 TF 发布者运行
rviz2                          # 打开三维可视化窗口
```

注释：`frames.pdf` 会生成在执行命令时的当前目录。在 RViz2 左侧将 **Fixed Frame** 设为 `base_link`，点击 **Add → TF**；彩色坐标轴就能显示 `base_laser` 的位置和方向。鼠标拖动可旋转视角、滚轮可缩放；如果看不到坐标轴，先检查发布者是否仍在运行，以及父子坐标系名称是否一致。

---

## 8. ROS 2 学习顺序

```text
节点 Node
  ↓
话题 Topic（发布 / 订阅）
  ↓
常用消息：String → Twist → LaserScan / Image / Odometry
  ↓
参数 Parameter 与 QoS
  ↓
服务 Service
  ↓
动作 Action
  ↓
Launch、TF 坐标变换、RViz、Nav2
```

## 9. 遇到“找不到包 / 节点 / 话题”时的检查顺序

```bash
source /opt/ros/humble/setup.bash
source ~/ROS2/my_ws/install/setup.bash
ros2 pkg list | grep 包名
ros2 node list
ros2 topic list -t
```

常见原因：没有在工作空间根目录编译、编译后忘记 `source install/setup.bash`、节点启动后已经报错退出，或者发布端与订阅端的话题名/消息类型不一致。
