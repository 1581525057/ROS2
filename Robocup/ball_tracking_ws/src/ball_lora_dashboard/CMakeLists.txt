cmake_minimum_required(VERSION 3.8)
project(ball_lora_dashboard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(ament_cmake REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets Test Concurrent)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBZIP REQUIRED IMPORTED_TARGET libzip)

add_library(ball_lora_protocol src/protocol.cpp)
target_include_directories(ball_lora_protocol PUBLIC include)

add_library(ball_lora_excel src/excel_export.cpp)
target_include_directories(ball_lora_excel PUBLIC include)
target_link_libraries(ball_lora_excel PUBLIC Qt5::Core PkgConfig::LIBZIP)

add_executable(ball_lora_dashboard
  src/main.cpp
  src/main_window.cpp
  src/plot_widget.cpp
  src/serial_port.cpp
  src/serial_device_combo.cpp
  include/ball_lora_dashboard/main_window.hpp
  include/ball_lora_dashboard/plot_widget.hpp
  include/ball_lora_dashboard/serial_port.hpp
  include/ball_lora_dashboard/serial_device_combo.hpp
)
target_include_directories(ball_lora_dashboard PRIVATE include)
target_link_libraries(ball_lora_dashboard PRIVATE ball_lora_protocol ball_lora_excel
                                                  Qt5::Widgets Qt5::Concurrent)

install(TARGETS ball_lora_dashboard DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  enable_testing()
  add_executable(test_protocol test/test_protocol.cpp)
  target_include_directories(test_protocol PRIVATE include)
  target_link_libraries(test_protocol PRIVATE ball_lora_protocol)
  add_test(NAME protocol COMMAND test_protocol)

  add_executable(test_serial_port
    test/test_serial_port.cpp
    src/serial_port.cpp
    include/ball_lora_dashboard/serial_port.hpp
  )
  target_include_directories(test_serial_port PRIVATE include)
  target_link_libraries(test_serial_port PRIVATE Qt5::Widgets util)
  add_test(NAME serial_port COMMAND test_serial_port)

  add_executable(test_plot_widget
    test/test_plot_widget.cpp
    src/plot_widget.cpp
    include/ball_lora_dashboard/plot_widget.hpp
  )
  target_include_directories(test_plot_widget PRIVATE include)
  target_link_libraries(test_plot_widget PRIVATE Qt5::Widgets Qt5::Test)
  add_test(NAME plot_widget COMMAND test_plot_widget)
  set_tests_properties(plot_widget PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")

  add_executable(test_excel_export test/test_excel_export.cpp)
  target_include_directories(test_excel_export PRIVATE include)
  target_link_libraries(test_excel_export PRIVATE ball_lora_excel Qt5::Core PkgConfig::LIBZIP)
  add_test(NAME excel_export COMMAND test_excel_export)

  add_executable(test_serial_device_combo
    test/test_serial_device_combo.cpp
    src/serial_device_combo.cpp
  )
  target_include_directories(test_serial_device_combo PRIVATE include)
  target_link_libraries(test_serial_device_combo PRIVATE Qt5::Widgets)
  add_test(NAME serial_device_combo COMMAND test_serial_device_combo)
  set_tests_properties(serial_device_combo PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")
endif()

ament_package()
