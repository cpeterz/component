#include "composition_test/talker_component.hpp"

// #include <chrono>
// #include <iostream>
// #include <memory>
// #include <utility>

// #include "rclcpp/rclcpp.hpp"
// #include "std_msgs/msg/string.hpp"


using namespace std::chrono_literals;

namespace composition
{
Talker::Talker(const rclcpp::NodeOptions & options)
: Node("talker", options), count_(0)
{
  // Create a publisher of "std_mgs/String" messages on the "chatter" topic.
  pub_ = create_publisher<std_msgs::msg::String>("chatter", 10);

  // Use a timer to schedule periodic message publishing.
  timer_ = create_wall_timer(1s, std::bind(&Talker::on_timer, this));
}

void Talker::on_timer()
{
  auto msg = std::make_unique<std_msgs::msg::String>();
  msg->data = "Hello World: " + std::to_string(++count_);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg->data.c_str());

  std::flush(std::cout);

  // Put the message into a queue to be processed by the middleware.
  // This call is non-blocking.
  pub_->publish(std::move(msg));
}

}  // namespace composition

// int main(int argc,char **argv)
// {
//     rclcpp::init(argc,argv);
//     auto node = std::make_shared<composition::Talker>();
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(composition::Talker)
