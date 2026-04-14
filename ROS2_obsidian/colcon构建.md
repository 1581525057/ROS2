# colcon 构建

[[ROS2学习地图]] | [[ROS2工作空间与包结构]]

---

## 常用命令

```bash
# 进入工作空间（必须在 ws 根目录，不是 src）
cd ~/ROS2_Repository/CHAPT3/topic_ws

# 加载 ROS2 环境
source /opt/ros/humble/setup.bash

# 构建全部包
colcon build

# 只构建指定包（速度快，推荐迭代时用）
colcon build --packages-select demo_cpp_topic
colcon build --packages-select demo_python_topic

# 构建后加载工作空间环境（每次新终端都要执行）
source install/setup.bash

# 运行节点
ros2 run <package_name> <node_name>

# 确认包已注册
ros2 pkg list | grep demo_
```

---

## 运行测试

```bash
colcon test
colcon test-result --verbose
```

---

## 注意事项

- `colcon build` 必须在工作空间根目录执行，不能在 `src` 里
- 每次新终端都需要重新 `source install/setup.bash`
- Python 包修改后一般不需要重新 build（除非改了 setup.py）
- C++ 包每次改代码都需要重新 `colcon build`

---

## 相关笔记

- [[ROS2工作空间与包结构]]
