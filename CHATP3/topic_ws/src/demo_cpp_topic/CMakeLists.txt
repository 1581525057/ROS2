cmake_minimum_required(VERSION 3.8)
project(demo_cpp_topic)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

add_executable(turtle_circle src/turtle_circle.cpp)
add_executable(turtle_circle_yezi src/turtle_circle_yezi.cpp)
add_executable(turtle_control src/turtle_control.cpp)
add_executable(turtle_control_yezi src/turtle_control_yezi.cpp)

ament_target_dependencies(turtle_circle rclcpp geometry_msgs)
ament_target_dependencies(turtle_circle_yezi  rclcpp geometry_msgs)
ament_target_dependencies(turtle_control  rclcpp geometry_msgs turtlesim)
ament_target_dependencies(turtle_control_yezi  rclcpp geometry_msgs turtlesim)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  # Skip xmllint because offline environments cannot always fetch the ROS
  # package schema referenced by package.xml.
  set(ament_cmake_xmllint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
install(TARGETS turtle_circle turtle_circle_yezi turtle_control turtle_control_yezi
DESTINATION lib/${PROJECT_NAME})

ament_package()
