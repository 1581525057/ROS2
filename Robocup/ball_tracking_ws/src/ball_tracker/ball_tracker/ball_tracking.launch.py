import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


# ===== 运行配置：修改这里后重新构建工作区 =====
# 视觉追踪
MODEL_PATH = "/home/yezi/yolo/ultralytics-8.3.163/ball.pt"
CAMERA_INDEX = 0
CAMERA_DEVICE = ""  # 填写设备路径后优先于 CAMERA_INDEX
CAMERA_MJPG = True  # 相机支持时使用 MJPG，降低 USB 带宽占用
TARGET_BALL = "red"  # 默认颜色；LoRa key2=0 红球、key2=1 蓝球，key1 控制启停
CONFIDENCE = 0.5
PREVIEW = True

# 球目标数据发送串口
START_BALL_SERIAL = True  # 球目标发送串口，须与 LoRa 使用不同设备
BALL_SERIAL_DEVICE = "/dev/serial/by-path/pci-0000:00:14.0-usb-0:3.4:1.0-port0"
BALL_BAUD_RATE = 115200
BALL_SEND_HZ = 100.0
BALL_STALE_TIMEOUT = 1.5
IMU_STALE_TIMEOUT = 0.5

# FDILink IMU 串口；优先使用稳定的 by-id 路径
IMU_SERIAL_DEVICE = "/dev/serial/by-id/usb-Silicon_Labs_CP2102_USB_to_UART_Bridge_Controller_0001-if00-port0"
IMU_BAUD_RATE = 921600

# LoRa 按键接收串口（须与球串口和陀螺仪都不同）
START_LORA_KEYS = True  # 无独立 LoRa 串口时保持关闭；启动参数可覆盖
LORA_SERIAL_DEVICE = "/dev/serial/by-path/pci-0000:00:14.0-usb-0:3.2:1.0-port0"
LORA_BAUD_RATE = 9600
LORA_LINK_TIMEOUT_S = 2.0  # 超过此时间未收到按键则判定链路离线
# ==============================================


def generate_launch_description():
    lora_serial_device = LaunchConfiguration("lora_serial_device")
    start_lora = LaunchConfiguration("start_lora")
    imu_serial_device = LaunchConfiguration("imu_serial_device")

    def check_serial_devices(context):
        devices = {"IMU": imu_serial_device.perform(context)}
        if start_lora.perform(context).lower() in ("true", "1", "yes"):
            devices["LoRa"] = lora_serial_device.perform(context)
        if START_BALL_SERIAL:
            devices["ball"] = LaunchConfiguration("serial_device").perform(context)
        resolved = {name: os.path.realpath(path) for name, path in devices.items()}
        if len(set(resolved.values())) != len(resolved):
            raise RuntimeError(
                "Ball, LoRa and IMU must use different serial ports: "
                + str(devices) + " -> " + str(resolved)
            )
        return []

    actions = [
        DeclareLaunchArgument(
            "start_lora",
            default_value=str(START_LORA_KEYS).lower(),
            description="Enable the LoRa key receiver when a separate serial port is available",
        ),
        DeclareLaunchArgument(
            "lora_serial_device",
            default_value=LORA_SERIAL_DEVICE,
            description="Serial device used to receive LoRa keys",
        ),
        DeclareLaunchArgument(
            "imu_serial_device",
            default_value=IMU_SERIAL_DEVICE,
            description="Serial device used by the FDILink IMU",
        ),
        DeclareLaunchArgument(
            "serial_device",
            default_value=BALL_SERIAL_DEVICE,
            description="Serial device used to send ball targets to the MCU",
        ),
        OpaqueFunction(function=check_serial_devices),
        Node(
            package="fdilink_ahrs",
            executable="ahrs_driver_node",
            name="ahrs_bringup",
            output="screen",
            parameters=[{
                "serial_port_": imu_serial_device,
                "serial_baud_": IMU_BAUD_RATE,
            }],
        ),
        Node(
            package="ball_tracker",
            executable="ball_tracker_node",
            output="screen",
            parameters=[{
                "model_path": MODEL_PATH,
                "camera_index": CAMERA_INDEX,
                "camera_device": CAMERA_DEVICE,
                "camera_mjpg": CAMERA_MJPG,
                "target_ball": TARGET_BALL,
                "confidence": CONFIDENCE,
                "preview": PREVIEW,
            }],
        ),
    ]

    actions.append(Node(
        package="ball_tracker",
        executable="lora_keys_node",
        condition=IfCondition(start_lora),
        output="screen",
        parameters=[{
            "serial_device": lora_serial_device,
            "baud_rate": LORA_BAUD_RATE,
            "link_timeout_s": LORA_LINK_TIMEOUT_S,
        }],
    ))

    if START_BALL_SERIAL:
        actions.extend([
            Node(
                package="ball_tracker",
                executable="ball_serial_node",
                output="screen",
                parameters=[{
                    "serial_device": LaunchConfiguration("serial_device"),
                    "baud_rate": BALL_BAUD_RATE,
                    "send_hz": BALL_SEND_HZ,
                    "stale_timeout": BALL_STALE_TIMEOUT,
                    "imu_stale_timeout": IMU_STALE_TIMEOUT,
                }],
            ),
        ])

    return LaunchDescription(actions)
