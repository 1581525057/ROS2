#include "rclcpp/rclcpp.hpp"

class PersonNode : public rclcpp::Node
{

private:
    std::string name;
    int age_;

public:
    PersonNode(const std::string &node_name, const std::string &name, const int &age)
        : Node(node_name)
    {
        this->name = name;
        this->age_ = age;
    };

    void eat(const std::string &food_name)
    {
        RCLCPP_INFO(get_logger(), "我是%s,%d岁,爱吃%s", name.c_str(), age_, food_name.c_str());
    };
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PersonNode>("person_node", "叶子", 20);
    RCLCPP_INFO(node->get_logger(), "c++ node");
    node->eat("帝王蟹");
    rclcpp::spin(node);
    rclcpp::shutdown();
}