# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target hipnuc_msgs::hipnuc_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${hipnuc_msgs_TARGETS}.
if(hipnuc_msgs_TARGETS AND NOT TARGET hipnuc_msgs::hipnuc_msgs)
  add_library(hipnuc_msgs::hipnuc_msgs INTERFACE IMPORTED)
  set_target_properties(hipnuc_msgs::hipnuc_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${hipnuc_msgs_TARGETS}")
endif()
