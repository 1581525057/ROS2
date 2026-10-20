# ROS 2 小球检测工作空间

使用 `ball.pt` 的 YOLO 模型从相机识别红球或蓝球，并将目标信息与 FDILink IMU 的三个欧拉角通过串口发送给单片机；当前不控制电机。

模型类别是 `red ball` 和 `bule ball`（模型本身把 blue 拼成 bule），程序已兼容。

## 构建

本机为 ROS 2 Humble，运行节点使用 Conda `cv` 环境；编译 ROS 消息接口时使用系统 Python。串口节点需要 `pyserial`：

```bash
/home/yezi/miniconda3/envs/cv/bin/python -m pip install pyserial==3.5
source /opt/ros/humble/setup.bash
cd /home/yezi/ROS2/Robocup/ball_tracking_ws
colcon build --symlink-install --cmake-args -DPython3_EXECUTABLE=/usr/bin/python3
source install/setup.bash
```

## 运行

打开 `src/ball_tracker/ball_tracker/node.py`，在文件顶部修改 `TARGET_BALL`（`"red"` 或 `"blue"`）和 `CAMERA_INDEX`（如 `4` 对应 `/dev/video4`）。保存并重启节点即可，不用每次输入参数。当前文件选择蓝球、4 号相机，并弹出 `ball_tracker` 实时画面：

```bash
ros2 run ball_tracker ball_tracker_node
```

如需临时覆盖文件顶部的选择，仍可在命令行指定：

```bash
ros2 run ball_tracker ball_tracker_node --ros-args -p target_ball:=blue -p camera_index:=0
```

如果设备号会变化，可指定稳定的设备路径，例如 `-p camera_device:=/dev/v4l/by-id/你的相机-video-index0`。非空的 `camera_device` 优先于 `camera_index`。运行中也可用 `ros2 param set /ball_tracker target_ball blue` 切换目标。

画面中的白色竖线是图像中心，绿色框和圆点标出选中的球，顶栏显示 `error_x`、`error_y` 和相对面积。相机正常但未识别到目标时显示 `NOT FOUND`；读帧失败时显示 `CAMERA OFFLINE`。不需要弹窗时加 `-p preview:=false`。

预览窗口按相机取帧速度刷新，YOLO 推理在后台进行，识别消息仍按推理完成速度发布。节点默认尝试使用 MJPG 格式以提高 USB 相机帧率；若相机不支持或画面异常，可加 `-p camera_mjpg:=false`。窗口实际帧率仍受相机、光线和 USB 连接影响。

查看输出：

```bash
ros2 topic echo /ball/target
ros2 topic echo /ball/target_msg
```

`/ball/target` 保留原有 JSON 输出；新增 `/ball/target_msg`，类型为 `ball_tracker_interfaces/msg/BallTarget`，字段包括 `camera_ok`、`detected`、`target_ball`、`error_x_norm`、`error_y_norm`、`area_ratio`、`width_norm`、`height_norm` 和时间戳。未检测到球时，消息的 5 个位置与大小字段为 0。

## 串口节点

单独运行串口节点时，在 `src/ball_tracker/ball_tracker/serial_node.py` 顶部设置 `SERIAL_DEVICE`、`BAUD_RATE` 和 `SEND_HZ`。默认是 `/dev/ttyUSB1`、`115200`、**100 Hz**。先启动 IMU 和视觉节点，再在另一个已经 source 工作空间的终端运行：

```bash
ros2 run ball_tracker ball_serial_node
```

临时指定端口和波特率：

```bash
ros2 run ball_tracker ball_serial_node --ros-args -p serial_device:=/dev/ttyACM0 -p baud_rate:=115200
```

球串口发送固定 38 字节 v3 目标、启停与姿态帧。IMU 每更新一次就立即发送，独立定时器还持续以至少 100 Hz 发送最近状态；球目标沿用最近一次视觉结果。LoRa key1 第一次按下变为 1 并保持启动，再按一次变为 0 才停止；key2=0 红球、1 蓝球。LoRa 失联时保持最后的启动位；只有收到有效 key1=0 才清除启动位及球目标数据，角度仍可发送。详细格式见 [串口协议](SERIAL_PROTOCOL.md)。单片机接收端需要支持 v3、38 字节格式和启动位。无串口设备时节点会重试，不影响视觉节点运行。LoRa 按键节点继续从独立串口接收按键并发布到 `/lora/keys`。

FDILink ROS 2 驱动和依赖的 `serial` 库已放在 `src/fdilink_ahrs` 与 `src/serial`，与球追踪功能包一起构建。驱动发布 `/euler_angles`（`geometry_msgs/msg/Vector3`，x/y/z 分别为 roll/pitch/heading，单位弧度），球串口节点换算成度后发给单片机。使用 `ball_tracking.launch.py` 时，IMU 和球串口都会启动。IMU 默认使用本机 CP2102 设备的 `/dev/serial/by-id/...0001...` 稳定路径，波特率 921600；球串口默认使用配置中的独立设备。可用 `imu_serial_device:=...` 和 `serial_device:=...` 覆盖。LoRa 默认按 `START_LORA_KEYS=True` 启动，可用 `start_lora:=false` 关闭，或用 `lora_serial_device:=/dev/你的LoRa设备` 指定端口。尚未收到过有效按键状态时启动位为 0；收到后，LoRa 掉线不改变最后的启动位。三个串口必须指向不同设备，启动时会检查路径冲突。

集成启动命令（未连接 LoRa 时加 `start_lora:=false`）：

```bash
source /opt/ros/humble/setup.bash
source /home/yezi/ROS2/Robocup/ball_tracking_ws/install/setup.bash
ros2 launch ball_tracker ball_tracking.launch.py start_lora:=false
```

另一台电脑上的 C++/Qt 上位机位于 [ball_lora_dashboard 功能包](src/ball_lora_dashboard/README.md)。它直接连接另一端的 LoRa 串口，可以发送红球、蓝球按键帧。

启动时节点会尝试打开相机；如果相机未接入，会持续发布 `detected:false` 并重试。设备号可能在重新插拔后变化，可用 `ls /dev/video*` 检查。

## 发布的数据

话题 `/ball/target`，类型 `std_msgs/msg/String`，内容为 JSON，每次处理画面均发布。示例：

```json
{"stamp_ns":123456789,"camera_ok":true,"detected":true,"target_ball":"red","image_width":640,"image_height":480,"confidence":0.93,"center_x_px":400.0,"center_y_px":250.0,"center_x_norm":0.625,"center_y_norm":0.5208,"error_x_norm":0.25,"error_y_norm":0.0417,"width_norm":0.1,"height_norm":0.1333,"area_ratio":0.0133,"bbox_xyxy":[368.0,218.0,432.0,282.0]}
```

- `camera_ok`: 当前是否成功读取相机画面。`false` 表示相机读帧或打开失败；`true` 且 `detected:false` 表示相机正常，但没识别到所选球。
- `detected`: 是否看到所选颜色的球。未看到时为 `false`，且不包含位置和大小字段；车端应停止沿用旧目标。
- `error_x_norm`: 水平偏差，`-1` 在最左，`0` 在正中，`+1` 在最右；可用于转向。
- `error_y_norm`: 垂直偏差，`-1` 在最上，`+1` 在最下。
- `area_ratio`、`width_norm`、`height_norm`: 图像中的相对大小，可用作接近程度的参考。未经相机标定，不能直接当作真实距离。
- `confidence`: 模型置信度；同色多个球时，发布画面中框最大的一个。
- `stamp_ns`: ROS 时钟纳秒时间戳，便于车端丢弃过期目标。

当相机读帧失败，节点先容忍短暂的单帧错误；连续失败 3 次才重新打开相机，并持续发布 `camera_ok:false`、`detected:false`。打不开相机时每隔约 1 秒重试，避免频繁重开设备。`model_path` 和 `confidence` 也可通过 ROS 参数修改。

如果移动时反复出现 `CAMERA OFFLINE`，先检查 USB 线和接头，并尽量将相机直接连接到电脑或使用供电稳定的集线器。本机内核日志已记录到该 USB 相机及上游集线器多次重置，软件重连只能恢复连接，无法消除硬件层面的中断。可使用稳定设备路径 `-p camera_device:=/dev/v4l/by-id/usb-LKZC_USB_Camera_200901010001-video-index0`，避免重新插拔后设备号改变。
