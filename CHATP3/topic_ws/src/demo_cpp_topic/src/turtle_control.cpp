#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include <chrono>

class Turtlr_ControlNode : public rclcpp::Node {
  private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
    double target_x{1.0};
    double target_y{1.0};
    double k{1.0};
    double max_speed{1.0};

  public:
    explicit Turtlr_ControlNode(const std::string &node_name) : Node(node_name) {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        subscriber_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, [this](const turtlesim::msg::Pose::SharedPtr msg) {
            on_pose_received(msg);
        });
    }

    void on_pose_received(const turtlesim::msg::Pose::SharedPtr pose) {
        auto current_x = pose->x;
        auto current_y = pose->y;
        RCLCPP_INFO(get_logger(), "当前的:x=%f,当前的:y=%f", current_x, current_y);

        auto distance = std::sqrt(
            (target_x - current_x) * (target_x - current_x) + (target_y - current_y) * (target_y - current_y));

        auto angle = std::atan2((target_y - current_y), (target_x - current_x)) - pose->theta;

        auto msg = geometry_msgs::msg::Twist();
        if ((distance > 0.1)) {
            if (fabs(angle) > 0.2) {
                msg.angular.z = fabs(angle);
            } else {
                msg.angular.z = 0;
                msg.linear.x = k * distance;
            }
        }

        if (msg.linear.x > max_speed) {
            msg.linear.x = max_speed;
        }

        publisher_->publish(msg);
    }
};

int main(int argc,char*argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Turtlr_ControlNode>("turtlr_control");
    rclcpp::spin(node);
    rclcpp::shutdown();
}

 


