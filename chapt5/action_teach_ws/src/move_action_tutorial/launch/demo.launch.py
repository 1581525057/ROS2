from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    target_distance = LaunchConfiguration('target_distance')
    speed = LaunchConfiguration('speed')
    cancel_after = LaunchConfiguration('cancel_after')

    return LaunchDescription([
        DeclareLaunchArgument(
            'target_distance',
            default_value='5.0',
            description='Distance the simulated robot should travel in meters.',
        ),
        DeclareLaunchArgument(
            'speed',
            default_value='1.0',
            description='Simulated speed in meters per second.',
        ),
        DeclareLaunchArgument(
            'cancel_after',
            default_value='0.0',
            description='Cancel after this many seconds; 0 disables cancellation.',
        ),
        Node(
            package='move_action_tutorial',
            executable='move_server',
            name='move_action_server',
            output='screen',
        ),
        Node(
            package='move_action_tutorial',
            executable='move_client',
            name='move_action_client',
            output='screen',
            parameters=[{
                'target_distance': target_distance,
                'speed': speed,
                'cancel_after': cancel_after,
            }],
        ),
    ])
