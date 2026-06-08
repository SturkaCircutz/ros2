#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include "std_srvs/srv/empty.hpp"
#include "std_srvs/srv/trigger.hpp"

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
            timer_ = create_wall_timer(timer_period_s, std::bind(&MyNode::timer_callback, this));
            // call the timer callback function after counting down 5 seconds.
            client_ = create_client<std_srvs::srv::Empty>("/save");
            // define a client to call service and named it /save
            server_ = create_service<std_srvs::srv::Trigger>(
                "/image_counter", std::bind(&MyNode::counter_callback, this, _1, _2)
            );
            RCLCPP_INFO(get_logger(), "Node started!");

        }
    private:
        void timer_callback(){
            RCLCPP_INFO(get_logger(), "Timer activate");
            // print info to notify that timer is activated.
            if(!client_->wait_for_service(1s)){
                RCLCPP_ERROR(get_logger(), "failed to connect to the image save service");
                return;
            }
            saved_imgs_++;
            auto request = std::make_shared<std_srvs::srv::Empty::Request>();
            auto future = client_->async_send_request(request);
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
        void counter_callback(const std_srvs::srv::Trigger::Request::SharedPtr req, 
            const std_srvs::srv::Trigger::Response::SharedPtr res){
                res->success = 1;
                res->message = "saved images: " + std::to_string(saved_imgs_); 
            }
        uint saved_imgs_ = 0;
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
        rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Client<std_srvs::srv::Empty>::SharedPtr client_;
        rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr server_; // return how many images have been saved
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
