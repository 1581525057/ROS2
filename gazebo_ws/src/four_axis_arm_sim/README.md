# 四轴机械臂：Gazebo Fortress + DM-J4310 风格 MIT 控制

模型位于 `/home/yezi/ROS2/four_axis_arm.urdf`。程序位于本 ROS 2 Humble 工作空间。

外观参照用户提供的机械臂图片制作：哑光黑电机筒、浅色金属侧板、黄绿色饰片、关节螺钉与黑色夹爪。机械结构、全部视觉几何及颜色、碰撞体、质量与惯量、关节轴线与限位、编码器零点和传感器配置都定义在 `/home/yezi/ROS2/four_axis_arm.urdf`，不再依赖外部网格文件。为兼容 ROS 2 Humble 的 RViz 多外观材质显示，每块装饰由一个固定在机械连杆上的外观连杆承载；Gazebo 会合并固定连接，四个运动关节保持不变。它是原创示意外观，不是该产品的官方 CAD。

## 构建与启动

```bash
cd /home/yezi/ROS2/gazebo_ws
source /opt/ros/humble/setup.bash
colcon build --packages-up-to four_axis_arm_sim
source install/setup.bash
ros2 launch four_axis_arm_sim four_axis_arm.launch.py
```

同时打开 Gazebo 和 RViz：

```bash
ros2 launch four_axis_arm_sim four_axis_arm.launch.py rviz:=true
```

如果 Gazebo 已在运行，只打开 RViz（不要再次启动整个仿真）：

```bash
ros2 run rviz2 rviz2 -d /home/yezi/ROS2/gazebo_ws/install/four_axis_arm_sim/share/four_axis_arm_sim/rviz/four_axis_arm.rviz --ros-args -p use_sim_time:=true
```

RViz 显示 `/robot_description` 的模型，并利用 `/joint_states` 经 `robot_state_publisher` 生成的 `/tf` 跟随 Gazebo 关节运动；固定坐标系为 `world`。`/joint_states` 是物理关节角，标定后的电机角仍在 `/arm/motor_state` 和 `/arm/joint_states_calibrated`。

每次启动会使用独立的 Gazebo 通信分区，避免上次意外残留的 Gazebo 服务进程把旧时间和关节状态混入本次仿真。

另开终端使用前，也执行：

```bash
source /opt/ros/humble/setup.bash
source /home/yezi/ROS2/gazebo_ws/install/setup.bash
```

首次启动后机械臂会从水平姿态抬到展示姿态。四个关节初始保持控制已启用。

每次启动 Gazebo，机械臂都会从模型初始姿态开始，并由 MIT 控制器运动到展示姿态。不保存或恢复上次仿真的物理关节姿态。

## 双编码器与固定零点

固定零点保存在 URDF 中的 `<encoder_zero joint1="..." joint2="..." joint3="..." joint4="..."/>`，数值是各输出轴的原始物理关节角度，单位 rad。**标定零点不会改变机械臂物理姿态**；标定后的反馈角度 = 原始物理角度 - 固定零点。Gazebo 重启时不会重新标定。

把第 2 关节**当前**物理角度标为零（服务会直接改写 URDF）：

```bash
ros2 service call /arm/set_encoder_zero four_axis_arm_interfaces/srv/SetEncoderZero \
  "{joint_name: joint2, use_current_position: true, raw_zero_position: 0.0}"
```

也可以指定一个固定物理角度作为零点，例如第 2 关节的原始角度 `-0.5 rad`：

```bash
ros2 service call /arm/set_encoder_zero four_axis_arm_interfaces/srv/SetEncoderZero \
  "{joint_name: joint2, use_current_position: false, raw_zero_position: -0.5}"
```

将四个关节各自当前角度同时设为零时，把 `joint_name` 写成 `all`，并使用 `use_current_position: true`。也可停机后手动编辑 URDF 中的四个偏移值。`/arm/motor_state.position`、`/arm/joint_states_calibrated.position` 和 MIT 指令 `position_des` 使用标定后角度；`/joint_states` 保持物理角度，用于机器人运动学和 TF。`/arm/encoder_state` 分别输出理想电机轴单圈角、输出轴单圈角、零点偏移和标定后的角度。电机轴单圈角按 10:1 减速比从输出轴角度推算，尚未模拟齿隙、弹性或独立转子动力学。

## MIT 指令

发送给第 2 关节：

```bash
ros2 topic pub --once /arm/mit_command four_axis_arm_interfaces/msg/MitCommand \
  "{joint_name: joint2, position_des: 0.1, velocity_des: 0.0, kp: 25.0, kd: 1.5, torque_ff: 0.0, enable: true}"
```

每个关节使用同一个 `/arm/mit_command` 话题，把 `joint_name` 改成 `joint1`、`joint2`、`joint3` 或 `joint4`。控制律：

`τ = Kp × (目标角度 - 当前角度) + Kd × (目标角速度 - 当前角速度) + 前馈力矩`

角度单位 rad，角速度 rad/s，力矩 N·m。`enable: false` 会撤去该关节驱动力矩，受重力影响机械臂可能下落。

## 查看反馈

```bash
ros2 topic echo /arm/motor_state
ros2 topic echo /arm/encoder_state
ros2 topic echo /arm/joint_states_calibrated
ros2 topic echo /joint_states
ros2 topic echo /arm/imu
```

`/arm/motor_state` 每条消息对应一个关节，提供相对固定零点的角度、角速度、角加速度、估计输出力矩、目标力矩和是否达到限幅。`/joint_states` 包含四个关节的物理角度、角速度和估计输出力矩。`/arm/imu` 给出腕部 IMU 的线加速度和角速度，静止时线加速度也会包含重力。

## 模型边界

- 指令按 DM4310 SDK MIT 量程量化：位置 ±12.5 rad、速度 ±30 rad/s、Kp 0–500、Kd 0–5、力矩字段 ±10 N·m。输出另按 DM-J4310-2EC 手册的 7 N·m 峰值限制；高速可用力矩采用简化下降曲线。10 N·m 是协议字段量程，不能当成机械峰值。
- 反馈角度、速度来自 Gazebo 关节状态；角加速度由速度差分滤波得到；力矩是控制器输出的**估计值**，不是应变片或六维力传感器实测值，也不是末端接触力。
- 连杆质量与惯量为了演示已调到电机能够抬起的范围，尚未根据真实零件测量校准。15 ms 力矩响应时间、速度力矩曲线也是演示假设。
- 这是 ROS 话题上的 MIT 控制语义仿真，不是达妙 CAN 总线、驱动器固件、温升、电流或编码器误差的完整数字孪生；也尚未接入实际达妙硬件驱动。
- 标定零点来自 URDF。关节物理姿态不会跨 Gazebo 重启保存，因此每次启动的反馈角度由新仿真的物理角度减去同一个固定零点得到。真机的双编码器断电后仍可读取输出轴单圈绝对位置，原理不同。

参考：[DM-J4310-2EC 官方手册](https://docs.openarm.dev/assets/files/dm4310-5d089e0b013d8e2fc203c5b670008a66.pdf)、[达妙 SDK 的 DM4310 协议量程](https://github.com/dmBots/motor-sdk/blob/main/Python%E4%BE%8B%E7%A8%8B/u2can/DM_CAN.py)。
