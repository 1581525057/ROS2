#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include <chrono>
#include <cmath>

class Turtlr_ControlNode : public rclcpp::Node {
  private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
    float x_target{3.0f};
    float y_target{1.0f};
    float kp = 2.0f;
    float max_speed = 2.0;

  public:
    explicit Turtlr_ControlNode(const std::string &node_name) : Node(node_name) {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        subscription_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, [this](turtlesim::msg::Pose::SharedPtr msg) {
            on_pose_received(msg);
        });
    }

    void on_pose_received(turtlesim::msg::Pose::SharedPtr pos) {
        auto current_x = pos->x;
        auto current_y = pos->y;
        RCLCPP_INFO(get_logger(), "当前x的坐标为：%f,当前y的坐标为：%f", current_x, current_y);

        auto distance_error = std::sqrt((x_target - current_x) * (x_target - current_x) + (y_target - current_y) * (y_target - current_y));

        auto angle_error = std::atan2((y_target - current_y), (x_target - current_x)) - pos->theta;

        auto msg = geometry_msgs::msg::Twist();
        if (distance_error > 0.05f) {
            if (angle_error > 0.2) {
                angle_error = 0.2;
            } else if (angle_error < -0.2) {
                angle_error = -0.2;
            }

            msg.angular.z = angle_error;

            if (std::fabs(angle_error) < 0.2) {
                auto speed = distance_error * kp;

                if (speed > max_speed) {
                    speed = max_speed;
                } else if (speed < -max_speed) {
                    speed = -max_speed;
                }
                msg.linear.x = speed;
            }
        }

        publisher_->publish(msg);
    }
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Turtlr_ControlNode>("tutrtlr_control");
    rclcpp::spin(node);
    rclcpp::shutdown();
}
