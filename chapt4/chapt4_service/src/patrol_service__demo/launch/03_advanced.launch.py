"""第三课：包含其他 launch、命名空间、YAML 参数和条件启动。"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    package_share = FindPackageShare('patrol_service__demo')
    namespace = LaunchConfiguration('namespace')
    start_remote_param = LaunchConfiguration('start_remote_param')
    params_file = LaunchConfiguration('params_file')

    base_launch = PathJoinSubstitution([package_share, 'launch', '02_launch_arguments.launch.py'])
    default_params = PathJoinSubstitution([package_share, 'config', 'patrol_params.yaml'])

    return LaunchDescription([
        DeclareLaunchArgument('namespace', default_value='floor_1', description='给本组节点加的命名空间'),
        DeclareLaunchArgument('start_remote_param', default_value='true', description='是否启动远程参数节点'),
        DeclareLaunchArgument('params_file', default_value=default_params, description='ROS 参数 YAML 文件'),
        GroupAction([
            PushRosNamespace(namespace),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(base_launch),
                launch_arguments={
                    'robot_name': 'launch-robot',
                    'allow_task': 'true',
                    'target_name': 'loading-area',
                }.items(),
            ),
            Node(
                package='patrol_service__demo',
                executable='remote_param',
                name='remote_param',
                output='screen',
                parameters=[params_file],
                condition=IfCondition(start_remote_param),
            ),
        ]),
    ])
