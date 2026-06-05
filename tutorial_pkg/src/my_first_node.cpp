#include "rclcpp/rclcpp.hpp"
class MyNode : public rclcpp::Node
{
    public:
        MyNode(): Node("my_node"){ // mynode is a public subclass of rclcpp node
            // rclcpp info are preferred over printf
            RCLCPP_INFO(get_logger(), "node started!");
        }
        
};

int main(int argc, char ** argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}