#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("cpp_node");
    RCLCPP_INFO(node->get_logger(), "C++节点");
    rclcpp::spin(node);
    return 0;
} 

