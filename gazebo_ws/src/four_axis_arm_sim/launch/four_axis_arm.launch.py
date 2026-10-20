"""Launch the four-axis arm with DM-J4310-style MIT torque control."""
from pathlib import Path
import uuid

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, SetEnvironmentVariable
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

URDF_PATH = Path('/home/yezi/ROS2/four_axis_arm.urdf')


def generate_launch_description():
    partition = f'four_axis_arm_{uuid.uuid4().hex[:12]}'
    arm_share = Path(get_package_share_directory('four_axis_arm_sim'))
    gazebo_share = Path(get_package_share_directory('ros_gz_sim'))
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(str(gazebo_share / 'launch' / 'gz_sim.launch.py')),
        launch_arguments={'gz_args': f'-r {arm_share / "worlds" / "arm_world.sdf"}'}.items(),
    )
    spawn = Node(
        package='ros_gz_sim', executable='create',
        arguments=['-world', 'arm_world', '-file', str(URDF_PATH), '-name', 'four_axis_arm'],
        output='screen',
    )
    bridge_topics = [
        '/world/arm_world/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
        '/arm/joint_state@sensor_msgs/msg/JointState[gz.msgs.Model',
        '/arm/imu@sensor_msgs/msg/Imu[gz.msgs.IMU',
    ]
    for joint in ('joint1', 'joint2', 'joint3', 'joint4'):
        bridge_topics.append(
            f'/model/four_axis_arm/joint/{joint}/cmd_force@std_msgs/msg/Float64]gz.msgs.Double'
        )
    bridge = Node(
        package='ros_gz_bridge', executable='parameter_bridge',
        arguments=bridge_topics,
        remappings=[
            ('/world/arm_world/clock', '/clock'),
            ('/arm/joint_state', '/arm/joint_states_raw'),
        ],
        output='screen',
    )
    motor = Node(package='four_axis_arm_sim', executable='mit_controller', output='screen')
    robot_state = Node(
        package='robot_state_publisher', executable='robot_state_publisher',
        parameters=[{'robot_description': URDF_PATH.read_text(), 'use_sim_time': True}],
        output='screen',
    )
    rviz = Node(
        package='rviz2', executable='rviz2', name='rviz2',
        arguments=['-d', str(arm_share / 'rviz' / 'four_axis_arm.rviz')],
        parameters=[{'use_sim_time': True}],
        condition=IfCondition(LaunchConfiguration('rviz')),
        output='screen',
    )
    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='false',
                              description='Open RViz alongside Gazebo'),
        SetEnvironmentVariable('IGN_PARTITION', partition),
        SetEnvironmentVariable('GZ_PARTITION', partition),
        gazebo, spawn, bridge, motor, robot_state, rviz,
    ])
