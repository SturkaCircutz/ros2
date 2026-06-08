#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/u_int8.hpp"

#include <algorithm>
#include <cmath>

// in order to process msg from the camera
using namespace std::placeholders;
using namespace std::chrono_literals;

class MyNode : public rclcpp::Node
{
    public:
        MyNode(): Node("my_node"){ // mynode is a public subclass of rclcpp node
            // rclcpp info are preferred over printf

            //create substription is a template function
            declare_parameter("timer_period_s", 5); // if timer_period_s does not set use 5
            auto timer_period_s = std::chrono::seconds(get_parameter("timer_period_s").as_int());
            auto qos = rclcpp::QoS(10).reliable();
            subscriber_ = create_subscription<sensor_msgs::msg::Image>(
                "/image", qos, std::bind(&MyNode::image_callback, this, _1));
            
            publisher_ = create_publisher<std_msgs::msg::UInt8>("/brightness", 10);
            RCLCPP_INFO(get_logger(), "node started!");
            timer_ = create_wall_timer(timer_period_s, std::bind(&MyNode::timer_callback, this));
            // call the timer callback function after counting down 5 seconds.
        }
    private:
        void timer_callback(){
            RCLCPP_INFO(get_logger(), "Timer activate");
            // print info to notify that timer is activated.
        }
        void image_callback(const sensor_msgs::msg::Image::SharedPtr image){
            if (image->data.empty()) {
                RCLCPP_WARN(get_logger(), "received empty image");
                return;
            }

            long long sum = 0;
            for(uint8_t value : image->data){
                sum+=value;
            }

            double avg = static_cast<double>(sum) / image->data.size();
            

            std_msgs::msg::UInt8 brightness_msg;
            brightness_msg.data = static_cast<uint8_t>(
                std::clamp(std::lround(avg), 0L, 255L));
            publisher_->publish(brightness_msg);

            RCLCPP_INFO(get_logger(), "brightness average: %.2f", avg);
        }

        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
        rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        
};

int main(int argc, char ** argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}


// subscriber is used to respond the speaker by invoking some code instead of printing 
//the things that are sent by speaker.
