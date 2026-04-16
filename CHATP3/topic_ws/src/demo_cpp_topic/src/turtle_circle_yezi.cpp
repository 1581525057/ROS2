#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>

using namespace std::chrono_literals;

class Turtle_CircleNode : public rclcpp::Node
{
private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

  rclcpp::TimerBase::SharedPtr timer_;

public:
  explicit Turtle_CircleNode(const std::string & node_name)
  : Node(node_name)
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

    timer_ = this->create_wall_timer(
      100ms, [this]() {
        timer_callback();
      });
  }

  void timer_callback()
  {
    auto msg = geometry_msgs::msg::Twist();
    msg.angular.z = 1.5;
    msg.linear.x = 5.0;
    publisher_->publish(msg);
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Turtle_CircleNode>("turtle_circle_yezi");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
