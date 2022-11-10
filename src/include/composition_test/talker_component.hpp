#ifndef COMPOSITION__TALKER_COMPONENT_HPP_
#define COMPOSITION__TALKER_COMPONENT_HPP_
//#ifdef __GNUC__
//     #define COMPOSITION_EXPORT __attribute__ ((dllexport))
//     #define COMPOSITION_IMPORT __attribute__ ((dllimport))
//   #else
//     #define COMPOSITION_EXPORT __declspec(dllexport)
//     #define COMPOSITION_IMPORT __declspec(dllimport)
//   #endif
//   #ifdef COMPOSITION_BUILDING_DLL
//     #define COMPOSITION_PUBLIC COMPOSITION_EXPORT
//   #else
//     #define COMPOSITION_PUBLIC COMPOSITION_IMPORT
//   #endif

// #ifdef COMPOSITION_BUILDING_DLL
//     #define COMPOSITION_PUBLIC COMPOSITION_EXPORT
// #else
//     #define COMPOSITION_PUBLIC COMPOSITION_IMPORT
// #endif

// #include "composition/visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>

namespace composition
{

class Talker : public rclcpp::Node
{
public:
//暂不知此宏定义的含义,猜测跟options有关
//   COMPOSITION_PUBLIC
  explicit Talker(const rclcpp::NodeOptions & options);

protected:
  void on_timer();

private:
  size_t count_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

}  // namespace composition

#endif  // COMPOSITION__TALKER_COMPONENT_HPP_
