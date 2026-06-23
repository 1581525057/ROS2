# ROS 2 Learning Repository

![ROS2](https://img.shields.io/badge/ROS2-Humble-22314E?style=flat-square)
![C++](https://img.shields.io/badge/C++-17-00599C?style=flat-square)
![Python](https://img.shields.io/badge/Python-3.x-3776AB?style=flat-square)
![License](https://img.shields.io/badge/License-Apache--2.0-green?style=flat-square)

这是一个按章节组织的 ROS 2 学习仓库，包含 C++ 与 Python 节点、Topic 通信、自定义消息与 Service 接口示例。每个工作空间可独立构建和运行。

## Learning Modules

| Workspace | Packages | Learning focus |
| --- | --- | --- |
| `CHAPT2/chapt2_ws` | `demo_cpp_pkg`, `demo_python_pkg` | ROS 2 C++ / Python 功能包、节点、线程和函数式编程基础 |
| `CHATP3/topic_ws` | `demo_cpp_topic`, `demo_python_topic` | Topic 发布订阅、`turtlesim` 运动控制、文本发布与语音朗读 |
| `CHATP3/topic_practice_ws` | `status_interfaces`, `status_publisher`, `status_display` | 自定义 `SystemStatus` 消息、Python 发布节点与 Qt 状态显示节点 |
| `chapt4/chapt4_ws` | `chapt4_interfaces`, `patrol_service_demo` | 自定义 `PatrolTask` Service、巡逻服务端/客户端与参数事件处理 |

## Prerequisites

推荐环境：Ubuntu 22.04、ROS 2 Humble、Python 3 和 `colcon`。

```bash
sudo apt update
sudo apt install ros-humble-desktop python3-colcon-common-extensions
```

`topic_ws` 的小海龟示例还需要 `turtlesim`；小说朗读示例需要 `espeak-ng`。`topic_practice_ws` 的状态显示节点依赖 Qt5。

```bash
sudo apt install ros-humble-turtlesim espeak-ng qtbase5-dev
```

## Build a Workspace

在需要运行的工作空间中执行以下命令。将 `WORKSPACE` 替换为表中的任意工作空间路径。

```bash
cd WORKSPACE
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```

例如，构建 Topic 示例：

```bash
cd CHATP3/topic_ws
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```

## Run Examples

以下命令必须在对应工作空间完成构建并加载 `install/setup.bash` 后执行。

### Chapter 2: Basic Packages

```bash
ros2 run demo_cpp_pkg cpp_node
ros2 run demo_python_pkg python_node
```

### Chapter 3: Topic Communication

启动小海龟仿真器后，发布速度消息让小海龟画圆：

```bash
ros2 run turtlesim turtlesim_node
ros2 run demo_cpp_topic turtle_circle
```

小说示例使用本地 HTTP 服务提供文本，再运行订阅端和发布端：

```bash
cd CHATP3/topic_ws
python3 -m http.server 8000
```

```bash
ros2 run demo_python_topic novel_sub_node
ros2 run demo_python_topic novel_pub_node
```

自定义状态消息练习：

```bash
ros2 run status_publisher sys_status_pub
ros2 run status_display sys_status_display
```

### Chapter 4: Service and Interfaces

在不同终端启动巡逻服务端和客户端：

```bash
ros2 run patrol_service_demo patrol_server
ros2 run patrol_service_demo patrol_client
```

## Repository Conventions

- 每个 ROS 2 工作空间的源代码位于 `src/` 目录。
- `build/`、`install/` 与 `log/` 是 `colcon` 生成的可再生内容，不提交到 Git。
- Python 的 `__pycache__/`、`*.pyc` 和 `*.egg-info/` 同样不提交。
- 修改任一工作空间后，需在该工作空间重新执行 `colcon build` 并加载新的 `install/setup.bash`。

## Troubleshooting

找不到 ROS 2 命令或包时，先加载系统环境和当前工作空间环境：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
```

确认当前终端识别到的包：

```bash
ros2 pkg list | grep -E 'demo_|status_|patrol_'
```

小海龟没有运动时，确认 `turtlesim_node` 已启动，并检查速度话题：

```bash
ros2 topic echo /turtle1/cmd_vel
```
