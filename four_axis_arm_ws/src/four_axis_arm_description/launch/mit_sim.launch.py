"""一条命令启动四轴机械臂的 Gazebo MIT 力矩控制仿真。

运行方式：ros2 launch four_axis_arm_description mit_sim.launch.py

这份 launch 负责把五部分接起来：
  1. Gazebo：加载保存的世界和机械臂，计算关节的物理运动。
  2. ros_gz_bridge：在 Gazebo Transport 和 ROS 2 之间转发状态、时钟、力矩。
  3. mit_control：接收 /arm/mit_command，计算四个关节应施加的力矩。
  4. robot_state_publisher：根据 URDF 和 /joint_states 发布 /tf。
  5. RViz：根据 /robot_description 与 /tf 显示机械臂。

完整的控制与反馈方向：
  ROS MIT 指令 -> mit_control -> ROS cmd_force -> bridge -> Gazebo 关节
  Gazebo 关节状态 -> bridge -> mit_control -> /joint_states -> /tf -> RViz

这是 MIT 力矩控制模式。原来的 sim.launch.py 是 Gazebo 滑块位置控制模式；
两种模式使用不同的 URDF 和世界文件，避免两个控制器同时给同一关节施力。
"""

# Path 用来拼接路径；包安装位置由 ROS 2 查询，不依赖启动时的当前目录。
from pathlib import Path

# 找到 colcon 安装后的包共享目录，例如 install/.../share/four_axis_arm_description。
from ament_index_python.packages import get_package_share_directory
# LaunchDescription 是 launch 最终返回的“要启动哪些动作”的清单。
from launch import LaunchDescription
# 用 IncludeLaunchDescription 复用 ros_gz_sim 已写好的 Gazebo 启动文件。
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
# Node 用来声明一个需要启动的 ROS 2 节点及其参数、命令行参数。
from launch_ros.actions import Node


def generate_launch_description():
    # ROS 2 执行 ros2 launch 时会调用本函数；这里只创建启动动作。
    # share 是本包的安装目录，构建后 urdf/world/rviz 文件都在这里。
    share = Path(get_package_share_directory('four_axis_arm_description'))

    # MIT 模式使用的 URDF 只有 ApplyJointForce 插件，没有滑块模式的
    # JointPositionController 插件。URDF 描述连杆、关节和仿真插件。
    urdf = share / 'urdf' / 'four_axis_arm_gazebo.urdf'

    # 这个 SDF 世界含地面、光源以及机械臂；其中机械臂模型名是
    # arm_four_model。下面 cmd_force 话题中的模型名必须与它一致。
    world = share / 'world' / 'arm_world_mit.sdf'

    # RViz 布局文件保存了 Fixed Frame、RobotModel 等显示设置。
    rviz_config = share / 'rviz' / 'four_axis_arm.rviz'

    # 先找到 ros_gz_sim 包自带的 gz_sim.launch.py，再将它包含进来。
    # gz_args 相当于传给 Gazebo 的命令行参数：-r 表示启动后立即运行仿真，
    # world 指定要打开的 SDF 世界。这里不加载滑块 GUI 配置。
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            str(Path(get_package_share_directory('ros_gz_sim'))
                / 'launch' / 'gz_sim.launch.py')),
        launch_arguments={'gz_args': f'-r {world}'}.items(),
    )

    # 每个字符串定义一条 bridge 规则，格式为：
    #   话题名@ROS消息类型[Gazebo消息类型  表示 Gazebo -> ROS 2
    #   话题名@ROS消息类型]Gazebo消息类型  表示 ROS 2 -> Gazebo
    # '[' 和 ']' 是方向标记，不能随意互换。
    bridge_topics = [
        # Gazebo 的 JointStatePublisher 插件发 /arm/joint_state。
        # Gazebo 消息是 gz.msgs.Model；bridge 把它转成 ROS JointState。
        '/arm/joint_state@sensor_msgs/msg/JointState[gz.msgs.Model',
        # Gazebo 仿真时间转成 ROS /clock，供 use_sim_time 的节点使用。
        '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
    ]

    # 为四个关节分别加一条 ROS -> Gazebo 的力矩桥接规则。
    # 例如 joint2 展开后得到：
    # /model/arm_four_model/joint/joint2/cmd_force
    # @std_msgs/msg/Float64]gz.msgs.Double
    # mit_control 发布 ROS Float64；Gazebo ApplyJointForce 接收 gz.msgs.Double。
    for joint in ('joint1', 'joint2', 'joint3', 'joint4'):
        bridge_topics.append(
            f'/model/arm_four_model/joint/{joint}/cmd_force'
            '@std_msgs/msg/Float64]gz.msgs.Double')

    # 这里才真正声明 bridge 节点：相当于运行 ros_gz_bridge 的
    # parameter_bridge 程序，并把上面的六条话题规则传给它。
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=bridge_topics,
        # 仅将 ROS 一侧的原话题名改成 /arm/joint_states_raw。
        # Gazebo 一侧仍叫 /arm/joint_state；MIT 节点订阅的是 raw 话题。
        # 这样 /joint_states 可以留给 MIT 节点发布带力矩估计的反馈。
        remappings=[('/arm/joint_state', '/arm/joint_states_raw')],
        # 把节点日志显示在运行 ros2 launch 的终端。
        output='screen',
    )

    # 本包的 MIT 控制节点：订阅 /arm/mit_command 和
    # /arm/joint_states_raw，计算力矩并发布到上述四个 cmd_force 话题。
    # 它还发布 /joint_states（物理关节角）和 /arm/motor_state（电机反馈）。
    mit_control = Node(
        package='four_axis_arm_description',
        executable='mit_control',
        # use_sim_time=True 让节点使用 Gazebo 经 /clock 给出的仿真时间。
        # model_name 用来组成 /model/arm_four_model/joint/.../cmd_force。
        parameters=[{'use_sim_time': True, 'model_name': 'arm_four_model'}],
        output='screen',
    )

    # robot_state_publisher 本身不控制关节。它从 MIT 节点的
    # /joint_states 读取实际关节角，结合 URDF 中的关节结构计算 /tf。
    # robot_description 是 URDF 全文，不是 URDF 文件路径。
    state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': urdf.read_text(), 'use_sim_time': True}],
        output='screen',
    )

    # RViz 只做显示：-d 加载已保存的布局；实际姿态来自 /tf。
    # 它和 robot_state_publisher 使用同一套仿真时间。
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', str(rviz_config)],
        parameters=[{'use_sim_time': True}],
        output='screen',
    )

    # 将刚才创建的五个启动动作交给 launch 系统。
    # 列表顺序不是“等前一个完全准备好才启动下一个”；各节点启动后
    # 会通过话题自动发现彼此，因此 Gazebo 需要几秒加载模型是正常的。
    return LaunchDescription([
        gazebo, bridge, mit_control, state_publisher, rviz,
    ])
