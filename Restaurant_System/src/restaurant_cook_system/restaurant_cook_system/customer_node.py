import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.msg import SetParametersResult
from restaurant_interfaces.msg import FoodOrder
import random

class CustomerPublisher(Node):
    def __init__(self):
        super().__init__("customer_node")
        self.get_logger().info('节点customer_node启动')

        self.order_id = 0
        self.customer_name = [
    '艾琳', '露西娅', '伊芙琳', '薇奥拉', '黛安娜',
    '艾莉丝', '克莱尔', '赛琳娜', '安妮雅', '莉莉安',
    '娜塔莉', '奥黛丽', '苏菲娅', '维奥莱特', '伊莎贝拉',
    '薇薇安', '海伦娜', '朱丽叶', '洛蕾塔', '塞西莉亚'
]
        self.dishes__pool = [
    # 主食
    '炒饭', '蛋炒饭', '扬州炒饭', '面条', '牛肉面', '炸酱面',
    '重庆小面', '热干面', '刀削面', '兰州拉面', '青椒肉丝盖面',
    '卤肉饭', '煲仔饭', '咖喱饭', '鸡排饭', '饺子', '馄饨',
    '包子', '小笼包', '披萨', '意大利面',

    # 肉类
    '鸡翅', '辣子鸡丁', '大盘鸡', '白切鸡', '宫保鸡丁',
    '口水鸡', '烤鸭', '红烧肉', '回锅肉', '糖醋排骨',
    '红烧牛肉', '水煮牛肉', '孜然羊肉', '羊肉串', '烤五花肉',
    '锅包肉', '梅菜扣肉', '东坡肉', '粉蒸肉',

    # 海鲜
    '波士顿龙虾', '大闸蟹', '小青龙', '金枪鱼刺身',
    '三文鱼刺身', '清蒸鲈鱼', '烤生蚝', '蒜蓉扇贝',
    '香辣虾', '油焖大虾', '酸菜鱼', '水煮鱼', '章鱼小丸子',

    # 素菜
    '青椒肉丝', '麻婆豆腐', '鱼香茄子', '地三鲜',
    '干煸四季豆', '手撕包菜', '酸辣土豆丝', '番茄炒蛋',
    '蒜蓉西兰花', '蚝油生菜', '凉拌黄瓜',

    # 火锅与烧烤
    '毛肚火锅', '重庆火锅', '潮汕牛肉火锅', '番茄火锅',
    '菌菇火锅', '串串香', '麻辣烫', '冒菜', '烧烤',
    '烤鱼', '烤肉', '铁板烧',

    # 快餐与小吃
    '汉堡', '薯条', '炸鸡', '鸡米花', '热狗',
    '肉夹馍', '煎饼果子', '手抓饼', '臭豆腐', '凉皮',
    '螺蛳粉', '过桥米线', '烤冷面', '锅盔', '生煎包',

    # 汤与粥
    '皮蛋瘦肉粥', '小米粥', '海鲜粥', '胡辣汤',
    '酸辣汤', '冬瓜排骨汤', '玉米鸡汤', '番茄蛋花汤',

    # 饮品与甜点
    '可乐', '雪碧', '奶茶', '咖啡', '柠檬茶',
    '橙汁', '酸梅汤', '椰汁', '双皮奶', '杨枝甘露',
    '冰淇淋', '蛋糕', '提拉米苏', '蛋挞'
]


        self.declare_parameter('period',3.0)
        self.period_time = self.get_parameter('period').value
        self.food_pulisher_ = self.create_publisher(FoodOrder,'new_order',10)
        self.timer = self.create_timer(self.period_time,self.send_food)

        # 【新增】监听运行过程中发来的参数修改请求。
        self.add_on_set_parameters_callback(
            self.parameter_callback
        )

    # 【新增】period 变化时，检查新值并用新周期重建定时器。
    def parameter_callback(self, parameters):
        for parameter in parameters:
            if parameter.name != 'period':
                continue

            # period 声明为 double，因此终端应传 1.0，而不是整数 1。
            if parameter.type_ != Parameter.Type.DOUBLE:
                return SetParametersResult(
                    successful=False,
                    reason='period 必须是浮点数，例如 1.0'
                )

            if parameter.value <= 0.0:
                return SetParametersResult(
                    successful=False,
                    reason='period 必须大于 0'
                )

            # 【修改】Humble 支持直接修改现有 Timer 的纳秒周期，不再销毁和重建。
            self.period_time = parameter.value
            self.timer.timer_period_ns = int(
                self.period_time * 1_000_000_000
            )
            # 【修改】从现在开始按新周期重新计时。
            self.timer.reset()

            self.get_logger().info(
                f'订单发布周期已修改为 {self.period_time} 秒'
            )

        return SetParametersResult(successful=True)

    def send_food(self):
        msg = FoodOrder()
        msg.order_id = self.order_id
        self.order_id +=1 

        msg.customer_name = random.choice(self.customer_name)

        dish_count = random.randint(1, 4)
        msg.dishes  = random.sample(self.dishes__pool,k = dish_count)
        self.get_logger().info(f'已发送订单号：{msg.order_id}')
        self.food_pulisher_.publish(msg)
        

def main(args = None):
    rclpy.init(args=args)
    node = CustomerPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        # 【修正】launch 退出时可能已经关闭上下文，避免重复 shutdown 报错。
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
