from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node


def generate_launch_description():
    share = Path(get_package_share_directory("four_axis_arm_description"))
    urdf = share / "urdf" / "four_axis_arm.urdf"
    world = share / "world" / "arm_world.sdf"
    gazebo_gui = share / "config" / "gazebo_gui.config"
    rviz_config = share / "rviz" / "four_axis_arm.rviz"

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            str(Path(get_package_share_directory("ros_gz_sim"))
                / "launch" / "gz_sim.launch.py")
        ),
        launch_arguments={"gz_args": f"-r --gui-config {gazebo_gui} {world}"}.items(),
    )
    bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=[
            "/arm/joint_state@sensor_msgs/msg/JointState[gz.msgs.Model",
            "/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock",
        ],
        remappings=[("/arm/joint_state", "/joint_states")],
        output="screen",
    )
    state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{
            "robot_description": urdf.read_text(),
            "use_sim_time": True,
        }],
        output="screen",
    )
    rviz = Node(
        package="rviz2",
        executable="rviz2",
        arguments=["-d", str(rviz_config)],
        parameters=[{"use_sim_time": True}],
        output="screen",
    )
    return LaunchDescription([
        gazebo, bridge, state_publisher, rviz,
    ])
