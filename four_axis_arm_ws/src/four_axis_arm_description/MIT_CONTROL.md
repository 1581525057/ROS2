# 四轴机械臂的 MIT 仿真控制

这是 **Gazebo 仿真电机**：ROS 2 节点按照达妙 MIT 指令的五个字段计算力矩，
再通过 `ros_gz_bridge` 把力矩送到 Gazebo 的 `ApplyJointForce` 插件。
它不连接实体电机，也不发送 CAN 帧。

## 启动

```bash
cd /home/yezi/ROS2/four_axis_arm_ws
source /opt/ros/humble/setup.bash
colcon build --packages-up-to four_axis_arm_description
source install/setup.bash
ros2 launch four_axis_arm_description mit_sim.launch.py
```

这个启动文件同时打开 Gazebo 和 RViz。原来的 `sim.launch.py` 是滑块位置控制模式；
运行 MIT 模式时使用 `mit_sim.launch.py`，它加载不带位置控制插件的模型。

## 发送一条 MIT 指令

在**另一个终端**执行：

```bash
source /opt/ros/humble/setup.bash
source /home/yezi/ROS2/four_axis_arm_ws/install/setup.bash
ros2 topic pub --once /arm/mit_command four_axis_arm_interfaces/msg/MitCommand \
  "{joint_name: joint1, position_des: 0.5, velocity_des: 0.0, kp: 40.0, kd: 1.5, torque_ff: 0.0, enable: true}"
```

`joint_name` 可换成 `joint2`、`joint3`、`joint4`。角度单位是 rad，
速度是 rad/s，前馈力矩是 N·m。控制律为：

```text
力矩 = Kp × (目标角度 - 实际角度)
     + Kd × (目标速度 - 实际速度)
     + 前馈力矩
```

`position_des` 使用**标定后的角度**；物理目标角度等于它加上
`urdf/four_axis_arm_gazebo.urdf` 中的 `<encoder_zero>` 值。
`/joint_states` 则始终发布物理关节角，供 RViz 的 TF 使用。

查看反馈：

```bash
ros2 topic echo /arm/motor_state
ros2 topic echo /joint_states --once
```

撤去某个关节的驱动力矩时，向它发送 `enable: false` 的 MIT 指令。

## 仿真范围

代码模拟了 MIT 字段量化、7 N·m 输出峰值、随速度下降的可用力矩和
15 ms 的简化力矩响应。7 N·m 峰值及 200 rpm 空载转速来自
[DM-J4310-2EC V1.1 使用说明书](https://docs.openarm.dev/assets/files/dm4310-5d089e0b013d8e2fc203c5b670008a66.pdf)。
15 ms 响应时间和速度力矩曲线是仿真假设；扭矩反馈是控制器输出的估计值，
不代表传感器实测值。纯 PD 控制下，受重力影响的关节可能停在目标角度附近，
而非完全相等；可用前馈力矩补偿。单次指令会保持到下一条指令，当前仿真没有
模拟实体驱动器的通信超时保护。真实电机还需要 CAN 驱动、设备 ID、使能流程和反馈解析。
