# launch/02_launch_arguments.launch.py

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # 读取 launch 参数
    robot_name = LaunchConfiguration('robot_name')
    allow_task = LaunchConfiguration('allow_task')
    target_name = LaunchConfiguration('target_name')

    return LaunchDescription([
        # 声明 launch 参数
        DeclareLaunchArgument(
            'robot_name',
            default_value='robot-01',
            description='服务机器人名称',
        ),
        DeclareLaunchArgument(
            'allow_task',
            default_value='true',
            description='是否接受任务',
        ),
        DeclareLaunchArgument(
            'target_name',
            default_value='room-A',
            description='目标地点',
        ),

        # 服务端节点
        Node(
            package='patrol_service__demo',
            executable='patrol_server',
            name='servzer_node',
            output='screen',
            parameters=[
                {
                    'robot_name': robot_name,
                    'allow_task': allow_task,
                }
            ],
        ),

        # 客户端节点
        Node(
            package='patrol_service__demo',
            executable='partom_client',
            name='patrol_client',
            output='screen',
            parameters=[
                {
                    'target_name': target_name,
                }
            ],
        ),
    ])

