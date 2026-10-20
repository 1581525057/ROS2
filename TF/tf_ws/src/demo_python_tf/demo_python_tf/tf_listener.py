"""定期查询两个坐标系之间的 TF，并打印平移和旋转。"""

import rclpy
from rclpy.node import Node
from tf2_ros import TransformListener, Buffer,TransformStamped
from tf_transformations import euler_from_quaternion


class TFListener(Node):
    """监听 TF 数据，每秒查询一次 bottle_link 相对于 base_link 的位姿。"""

    def __init__(self):
        """创建节点、TF 缓存、监听器和周期定时器。"""
        super().__init__("tf2_listener")

        # Buffer 保存收到的坐标变换，后续查询都从这里读取。
        self.buffer_ = Buffer()

        # TransformListener 订阅 TF 话题，并把收到的数据写入上面的 Buffer。
        # 第二个参数是当前节点，监听器借助它参与 ROS 2 通信。
        self.listener_ = TransformListener(self.buffer_, self)

        # 每隔 1 秒调用一次 get_transform；定时器对象要保存在节点上。
        self.timer_ = self.create_timer(1, self.get_transform)

    def get_transform(self):
        """查询最新变换，将四元数换成欧拉角后输出。"""
        try:
            # lookup_transform(目标坐标系, 源坐标系, 查询时间, 等待时长)：
            # 这里要得到 bottle_link 在 base_link 坐标系中的位置和朝向。
            # 时间 0 表示查询缓存里最新可用的变换；最多等待 1 秒。
            result:TransformStamped = self.buffer_.lookup_transform(
                "base_link",
                "bottle_link",
                rclpy.time.Time(seconds=0),
                rclpy.time.Duration(seconds=1),
            )

            # 查询结果还带有时间戳及坐标系名称；transform 是实际的位姿数据。
            transform = result.transform

            # TF 中的旋转是四元数，分量顺序为 x、y、z、w。
            # 转成欧拉角后依次得到 roll、pitch、yaw，单位是弧度。
            rotation_euler = euler_from_quaternion([
                transform.rotation.x,
                transform.rotation.y,
                transform.rotation.z,
                transform.rotation.w,
            ])

            # 同时打印平移、原始四元数和便于阅读的欧拉角。
            self.get_logger().info(f"平移:{transform.translation},旋转四元数:{transform.rotation}:旋转欧拉角:{rotation_euler}")
        except Exception as e:
            # 变换尚未收到、坐标系不存在或查询超时等情况都会进入这里。
            # 保留节点运行，等待下一个定时周期再次尝试。
            self.get_logger().warn(f"不能够获取坐标变换，原因: {str(e)}")


def main():
    """初始化 ROS 2，运行监听节点。"""
    rclpy.init()
    # 创建节点后，构造函数会同时启动 TF 监听和周期查询定时器。
    node = TFListener()
    # spin 持续处理收到的 TF 消息和定时器回调，直到节点被停止。
    rclpy.spin(node)
    # 节点结束运行后，关闭 ROS 2 Python 环境。
    rclpy.shutdown()
