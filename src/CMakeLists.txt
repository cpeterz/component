cmake_minimum_required(VERSION 3.5)
project(composition_test)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# find_package(rcutils REQUIRED)
# find_package(std_msgs REQUIRED)
#容器必备包
find_package(rclcpp_components REQUIRED)
#找到自己包下的include
include_directories(include)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# find_package(rclcpp_components REQUIRED)

#必要，相当于一个声明
add_library(
   talker_component SHARED
   src/talker_component.cpp
)

add_library(
   listener_component SHARED
   src/listener_component.cpp
)
#添加必备依赖
ament_target_dependencies(
  talker_component
  "rclcpp"
  "rclcpp_components"
  # "std_msgs"
)

ament_target_dependencies(
  listener_component
  "rclcpp"
  "rclcpp_components"
  # "std_msgs"
)

#install,把构件放到自己的install目录下，运行的时候才找得到
install(TARGETS
  talker_component
  listener_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
#说是在注册，实际上并没有影响我的运行，搞不懂
rclcpp_components_register_nodes(talker_component "composition::Talker")
rclcpp_components_register_nodes(listener_component "composition::Listener")

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

#测了一下，要不要都无妨
# install(TARGETS
#   talker_component
#   DESTINATION lib/${PROJECT_NAME})

ament_package()
