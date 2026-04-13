// 引入 ROS2 C++ 客户端库。写 ROS2 节点、创建发布者、定时器，都要用它。
#include "rclcpp/rclcpp.hpp"
// 引入 Twist 消息类型。turtlesim 的速度控制话题 /turtle1/cmd_vel 需要这种消息。
#include "geometry_msgs/msg/twist.hpp"
// 引入时间相关工具。下面的 1000ms 就来自这个头文件。
#include <chrono>

// 让代码可以直接写 1000ms，而不用写 std::chrono::milliseconds(1000)。
using namespace std::chrono_literals;

// 定义一个类，类名叫 Turtle_CircleNode。
// class 表示“自定义一种类型”，这里就是自定义一个 ROS2 节点类型。
// : public rclcpp::Node 表示这个类继承 ROS2 的 Node。
// 简单理解：Turtle_CircleNode 是一个“加强版 Node”，所以它能创建话题发布者和定时器。
class Turtle_CircleNode : public rclcpp::Node
{
private:
  // private 表示下面的成员只能在这个类里面使用，外面不能直接访问。

  // 创建一个“发布者指针”变量，变量名叫 publisher_。
  // rclcpp::Publisher<geometry_msgs::msg::Twist>
  //   表示这是一个发布 Twist 消息的发布者。
  // ::SharedPtr
  //   表示这是一个智能指针，ROS2 常用这种方式管理对象，不需要手动 delete。
  // publisher_
  //   末尾下划线是常见写法，表示它是类的成员变量。
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

  // 创建一个“定时器指针”变量，变量名叫 timer_。
  // 定时器会每隔一段时间自动调用一个函数。
  rclcpp::TimerBase::SharedPtr timer_;

public:
  // public 表示下面的成员可以被外部使用。

  // 这是构造函数：创建 Turtle_CircleNode 对象时，会自动执行这里的代码。
  // explicit 的作用：禁止一些容易让人迷糊的自动类型转换，写构造函数时常见。
  // const std::string &node_name
  //   node_name 是节点名字。
  //   std::string 表示字符串。
  //   const 表示函数里不会修改这个字符串。
  //   & 表示引用，避免复制一份字符串，提高效率。
  // : Node(node_name)
  //   这是初始化父类 rclcpp::Node，把 node_name 交给 ROS2，作为真正的节点名。
  explicit Turtle_CircleNode(const std::string & node_name)
  : Node(node_name)
  {
    // this 表示“当前这个对象自己”。
    // create_publisher<geometry_msgs::msg::Twist>
    //   创建一个发布者，并说明它发布的消息类型是 Twist。
    // "/turtle1/cmd_vel"
    //   是 turtlesim 小乌龟接收速度指令的话题名。
    // 10
    //   是队列长度。消息来不及发送时，最多先缓存 10 条。
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

    // 创建一个定时器。
    // 1000ms 表示每 1000 毫秒执行一次，也就是每 1 秒执行一次。
    // std::bind(&Turtle_CircleNode::timer_callback, this)
    //   意思是：定时器到时间后，调用当前对象的 timer_callback 函数。
    // &Turtle_CircleNode::timer_callback
    //   表示取这个类里的 timer_callback 函数。
    // this
    //   表示调用的是“当前这个节点对象”的 timer_callback。
    timer_ = this->create_wall_timer(1000ms, std::bind(&Turtle_CircleNode::timer_callback, this));
  }

  // 定时器回调函数。
  // “回调”就是：不是我们直接调用它，而是 ROS2 定时器到点后自动调用它。
  void timer_callback()
  {
    // 创建一个 Twist 消息对象，变量名叫 msg。
    // auto 表示让编译器自己推断类型。
    // 这里右边是 geometry_msgs::msg::Twist()，所以 msg 的类型就是 Twist。
    auto msg = geometry_msgs::msg::Twist();

    // linear 表示线速度，也就是直着走的速度。
    // x 表示 x 方向。
    // 设成 1.0，意思是小乌龟一直往前走。
    msg.linear.x = 1.0;

    // angular 表示角速度，也就是旋转速度。
    // z 表示绕 z 轴旋转。平面里的转弯通常就是绕 z 轴转。
    // 设成 0.5，意思是小乌龟一边前进一边慢慢转弯。
    // 直走速度 + 转弯速度 同时存在，所以小乌龟会画圆。
    msg.angular.z = 0.5;

    // 把 msg 发布到 /turtle1/cmd_vel。
    // turtlesim 收到后，小乌龟就会按照这个速度运动。
    publisher_->publish(msg);
  }
};


// C++ 程序入口。程序从 main 函数开始执行。
// argc 表示命令行参数的数量。
// argv 表示命令行参数的内容。
int main(int argc, char * argv[])
{
  // 初始化 ROS2。
  // 凡是 ROS2 C++ 程序，通常一开始都要先调用 rclcpp::init。
  rclcpp::init(argc, argv);

  // 创建一个 Turtle_CircleNode 节点对象。
  // std::make_shared 会创建智能指针，ROS2 节点通常用 shared_ptr 管理。
  // "turtle_circle" 是节点名字。
  auto node = std::make_shared<Turtle_CircleNode>("turtle_circle");

  // 让节点开始运行。
  // spin 的意思是：一直等待并处理 ROS2 事件，比如定时器回调、话题消息等。
  // 如果没有 spin，定时器不会持续执行，程序很快就结束了。
  rclcpp::spin(node);

  // 关闭 ROS2，释放相关资源。
  // 当 spin 结束后，一般调用 shutdown。
  rclcpp::shutdown();

  // main 返回 0，表示程序正常结束。
  return 0;
}
