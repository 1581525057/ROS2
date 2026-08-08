"""第一课：一个 launch 同时启动服务端和客户端。"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='patrol_service__demo',
            executable='patrol_server',
            name='servzer_node',
            output='screen',
        ),
        Node(
            package='patrol_service__demo',
            executable='partom_client',
            name='patrol_client',
            output='screen',
        ),
    ])
