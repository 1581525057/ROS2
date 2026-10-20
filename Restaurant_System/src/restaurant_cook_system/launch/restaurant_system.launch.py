from launch import LaunchDescription #用来装载所有需要执行的启动动作
from launch.actions import DeclareLaunchArgument #声明一个可以从终端传入的 launch 参数
from launch.substitutions import LaunchConfiguration #读取终端传入的参数值
from launch_ros.actions import Node #专门用于启动 ROS 2 节点。
from launch_ros.parameter_descriptions import ParameterValue #明确指定参数的数据类型。


def generate_launch_description():
    # 【新增】声明一个 launch 参数；不传时默认每 3 秒发布一份订单。
    period_argument = DeclareLaunchArgument(
        'period',
        default_value='3.0',
        description='顾客发布订单的时间间隔，单位为秒'
    )

    # 【升级】这里设置启动初值；节点启动后还可以用 ros2 param set 动态修改。
    customer_period = ParameterValue(
        LaunchConfiguration('period'),
        value_type=float
    )

    return LaunchDescription([
        period_argument,

        # 厨房先列出，方便阅读；launch 启动节点时不依赖书写顺序保证通信。
        Node(
            package='restaurant_cook_system',
            executable='kitchen_node',
            name='kitchen_node',
            output='screen'
        ),

        Node(
            package='restaurant_cook_system',
            executable='cashier_node',
            name='cashier_node',
            output='screen'
        ),

        Node(
            package='restaurant_cook_system',
            executable='customer_node',
            name='customer_node',
            output='screen',
            # 【新增】把 launch 参数传给 customer_node 中声明的 period 参数。
            parameters=[{
                'period': customer_period
            }]
        )
    ])
