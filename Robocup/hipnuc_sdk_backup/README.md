# HiPNUC ROS 2 driver source

This directory contains only the source needed to build the HiPNUC ROS 2
`hipnuc_imu` and `hipnuc_msgs` packages: `ros/ros2`, `ros/common`, `c/hipnuc`,
and `c/serial`. It was copied from `hipnuc/products` commit `2676ffb`.

`c/COLCON_IGNORE` keeps the C library source from being discovered as separate
colcon packages. The ROS 2 driver builds those libraries through CMake.

Upstream: https://github.com/hipnuc/products
