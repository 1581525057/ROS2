import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped #消息接口
from tf2_ros import TransformBroadcaster #消息发布器
from tf_transformations import quaternion_from_euler
import math

class CameraTF(Node):
    def __init__(self):
        super().__init__('camera_tf')
        self.broadcaster = TransformBroadcaster(self)
        self.create_timer(0.01,self.publish_tf)

    def publish_tf(self):
        transform = TransformStamped()
        transform.header.frame_id = 'camera_link'
        transform.child_frame_id = 'bottle_link'
        transform.header.stamp = self.get_clock().now().to_msg()

        transform.transform.translation.x = 0.2
        transform.transform.translation.y = 0.0
        transform.transform.translation.z = 0.5

         # 欧拉角转四元数
        rotation_quat = quaternion_from_euler(math.radians(180), 0, 0)
        transform.transform.rotation.x = rotation_quat[0]
        transform.transform.rotation.y = rotation_quat[1]
        transform.transform.rotation.z = rotation_quat[2]
        transform.transform.rotation.w = rotation_quat[3]

        self.broadcaster.sendTransform(transform)

def main(args = None):
    rclpy.init()
    node = CameraTF()
    rclpy.spin(node)
    rclpy.shutdown()
