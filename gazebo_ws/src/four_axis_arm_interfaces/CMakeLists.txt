cmake_minimum_required(VERSION 3.8)
project(four_axis_arm_interfaces)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/MitCommand.msg"
  "msg/MotorState.msg"
  "msg/EncoderState.msg"
  "srv/SetEncoderZero.srv"
  DEPENDENCIES std_msgs
)
ament_export_dependencies(rosidl_default_runtime)
ament_package()
