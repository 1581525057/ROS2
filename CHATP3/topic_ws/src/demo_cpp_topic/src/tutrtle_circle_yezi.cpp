#include "chrono"
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class Turtle_Circle : public rclcpp::Node {

  private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

  public:
    explicit Turtle_Circle(const std::string &node_name) : Node(node_name) {

        publisher_ = this->create_publisher<geometry_msgs::msg ::Twist>("turtle_circle", 10);

        timer_ = this->create_wall_timer(1000ms, [this]() {
            timer_callback();
        });
    };

    void timer_callback()
    {
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.z = 0.5;
        msg.linear.x = 1.0;
        publisher_->publish(msg);
    }
};

int main (int argc,char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Turtle_Circle>("cricle_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
}