#include "composition_test/listener_component.hpp"


namespace composition
{

Listener::Listener(const rclcpp::NodeOptions & options)
: Node("listener", options)
{
  // Create a callback function for when messages are received.
  // Variations of this function also exist using, for example, UniquePtr for zero-copy transport.
  auto callback =
    [this](std_msgs::msg::String::ConstSharedPtr msg) -> void
    {
      RCLCPP_INFO(this->get_logger(), "I heard: [%s]", msg->data.c_str());
      std::flush(std::cout);
    };
  sub_ = create_subscription<std_msgs::msg::String>("chatter", 10, callback);
}

}  // namespace composition

#include "rclcpp_components/register_node_macro.hpp"


RCLCPP_COMPONENTS_REGISTER_NODE(composition::Listener)
