// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice
#include "hipnuc_msgs/msg/detail/hipnuc_imu__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hipnuc_msgs/msg/detail/hipnuc_imu__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace hipnuc_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hipnuc_msgs
cdr_serialize(
  const hipnuc_msgs::msg::HipnucImu & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: source
  cdr << ros_message.source;
  // Member: valid
  cdr << ros_message.valid;
  // Member: node_id
  cdr << ros_message.node_id;
  // Member: main_status
  cdr << ros_message.main_status;
  // Member: gyro_bias_converged
  cdr << (ros_message.gyro_bias_converged ? true : false);
  // Member: attitude_converged
  cdr << (ros_message.attitude_converged ? true : false);
  // Member: magnetic_disturbance
  cdr << (ros_message.magnetic_disturbance ? true : false);
  // Member: device_static
  cdr << (ros_message.device_static ? true : false);
  // Member: magnetometer_aiding
  cdr << (ros_message.magnetometer_aiding ? true : false);
  // Member: ins_status
  cdr << ros_message.ins_status;
  // Member: acceleration
  {
    cdr << ros_message.acceleration;
  }
  // Member: angular_velocity
  {
    cdr << ros_message.angular_velocity;
  }
  // Member: magnetic_field
  {
    cdr << ros_message.magnetic_field;
  }
  // Member: roll
  cdr << ros_message.roll;
  // Member: pitch
  cdr << ros_message.pitch;
  // Member: yaw
  cdr << ros_message.yaw;
  // Member: heading
  cdr << ros_message.heading;
  // Member: quaternion_wxyz
  {
    cdr << ros_message.quaternion_wxyz;
  }
  // Member: inclination
  {
    cdr << ros_message.inclination;
  }
  // Member: inclination_yaw
  cdr << ros_message.inclination_yaw;
  // Member: device_time_us
  cdr << ros_message.device_time_us;
  // Member: utc_valid
  cdr << (ros_message.utc_valid ? true : false);
  // Member: utc_year
  cdr << ros_message.utc_year;
  // Member: utc_month
  cdr << ros_message.utc_month;
  // Member: utc_day
  cdr << ros_message.utc_day;
  // Member: utc_hour
  cdr << ros_message.utc_hour;
  // Member: utc_minute
  cdr << ros_message.utc_minute;
  // Member: utc_second
  cdr << ros_message.utc_second;
  // Member: utc_millisecond
  cdr << ros_message.utc_millisecond;
  // Member: gps_week
  cdr << ros_message.gps_week;
  // Member: gps_tow_ms
  cdr << ros_message.gps_tow_ms;
  // Member: temperature
  cdr << ros_message.temperature;
  // Member: pressure
  cdr << ros_message.pressure;
  // Member: heave_surge_sway
  {
    cdr << ros_message.heave_surge_sway;
  }
  // Member: heave_surge_sway_frequency
  {
    cdr << ros_message.heave_surge_sway_frequency;
  }
  // Member: longitude
  cdr << ros_message.longitude;
  // Member: latitude
  cdr << ros_message.latitude;
  // Member: altitude_msl
  cdr << ros_message.altitude_msl;
  // Member: gnss_longitude
  cdr << ros_message.gnss_longitude;
  // Member: gnss_latitude
  cdr << ros_message.gnss_latitude;
  // Member: gnss_altitude_msl
  cdr << ros_message.gnss_altitude_msl;
  // Member: gnss_velocity_enu
  {
    cdr << ros_message.gnss_velocity_enu;
  }
  // Member: geoid_separation
  cdr << ros_message.geoid_separation;
  // Member: velocity_enu
  {
    cdr << ros_message.velocity_enu;
  }
  // Member: acceleration_enu
  {
    cdr << ros_message.acceleration_enu;
  }
  // Member: position_quality
  cdr << ros_message.position_quality;
  // Member: position_satellites
  cdr << ros_message.position_satellites;
  // Member: heading_quality
  cdr << ros_message.heading_quality;
  // Member: heading_satellites
  cdr << ros_message.heading_satellites;
  // Member: pdop
  cdr << ros_message.pdop;
  // Member: hdop
  cdr << ros_message.hdop;
  // Member: differential_age
  cdr << ros_message.differential_age;
  // Member: odometer_speed
  cdr << ros_message.odometer_speed;
  // Member: speed_over_ground
  cdr << ros_message.speed_over_ground;
  // Member: course_over_ground
  cdr << ros_message.course_over_ground;
  // Member: nmea_status
  cdr << ros_message.nmea_status;
  // Member: nmea_mode
  cdr << ros_message.nmea_mode;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hipnuc_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hipnuc_msgs::msg::HipnucImu & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: source
  cdr >> ros_message.source;

  // Member: valid
  cdr >> ros_message.valid;

  // Member: node_id
  cdr >> ros_message.node_id;

  // Member: main_status
  cdr >> ros_message.main_status;

  // Member: gyro_bias_converged
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gyro_bias_converged = tmp ? true : false;
  }

  // Member: attitude_converged
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.attitude_converged = tmp ? true : false;
  }

  // Member: magnetic_disturbance
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.magnetic_disturbance = tmp ? true : false;
  }

  // Member: device_static
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.device_static = tmp ? true : false;
  }

  // Member: magnetometer_aiding
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.magnetometer_aiding = tmp ? true : false;
  }

  // Member: ins_status
  cdr >> ros_message.ins_status;

  // Member: acceleration
  {
    cdr >> ros_message.acceleration;
  }

  // Member: angular_velocity
  {
    cdr >> ros_message.angular_velocity;
  }

  // Member: magnetic_field
  {
    cdr >> ros_message.magnetic_field;
  }

  // Member: roll
  cdr >> ros_message.roll;

  // Member: pitch
  cdr >> ros_message.pitch;

  // Member: yaw
  cdr >> ros_message.yaw;

  // Member: heading
  cdr >> ros_message.heading;

  // Member: quaternion_wxyz
  {
    cdr >> ros_message.quaternion_wxyz;
  }

  // Member: inclination
  {
    cdr >> ros_message.inclination;
  }

  // Member: inclination_yaw
  cdr >> ros_message.inclination_yaw;

  // Member: device_time_us
  cdr >> ros_message.device_time_us;

  // Member: utc_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.utc_valid = tmp ? true : false;
  }

  // Member: utc_year
  cdr >> ros_message.utc_year;

  // Member: utc_month
  cdr >> ros_message.utc_month;

  // Member: utc_day
  cdr >> ros_message.utc_day;

  // Member: utc_hour
  cdr >> ros_message.utc_hour;

  // Member: utc_minute
  cdr >> ros_message.utc_minute;

  // Member: utc_second
  cdr >> ros_message.utc_second;

  // Member: utc_millisecond
  cdr >> ros_message.utc_millisecond;

  // Member: gps_week
  cdr >> ros_message.gps_week;

  // Member: gps_tow_ms
  cdr >> ros_message.gps_tow_ms;

  // Member: temperature
  cdr >> ros_message.temperature;

  // Member: pressure
  cdr >> ros_message.pressure;

  // Member: heave_surge_sway
  {
    cdr >> ros_message.heave_surge_sway;
  }

  // Member: heave_surge_sway_frequency
  {
    cdr >> ros_message.heave_surge_sway_frequency;
  }

  // Member: longitude
  cdr >> ros_message.longitude;

  // Member: latitude
  cdr >> ros_message.latitude;

  // Member: altitude_msl
  cdr >> ros_message.altitude_msl;

  // Member: gnss_longitude
  cdr >> ros_message.gnss_longitude;

  // Member: gnss_latitude
  cdr >> ros_message.gnss_latitude;

  // Member: gnss_altitude_msl
  cdr >> ros_message.gnss_altitude_msl;

  // Member: gnss_velocity_enu
  {
    cdr >> ros_message.gnss_velocity_enu;
  }

  // Member: geoid_separation
  cdr >> ros_message.geoid_separation;

  // Member: velocity_enu
  {
    cdr >> ros_message.velocity_enu;
  }

  // Member: acceleration_enu
  {
    cdr >> ros_message.acceleration_enu;
  }

  // Member: position_quality
  cdr >> ros_message.position_quality;

  // Member: position_satellites
  cdr >> ros_message.position_satellites;

  // Member: heading_quality
  cdr >> ros_message.heading_quality;

  // Member: heading_satellites
  cdr >> ros_message.heading_satellites;

  // Member: pdop
  cdr >> ros_message.pdop;

  // Member: hdop
  cdr >> ros_message.hdop;

  // Member: differential_age
  cdr >> ros_message.differential_age;

  // Member: odometer_speed
  cdr >> ros_message.odometer_speed;

  // Member: speed_over_ground
  cdr >> ros_message.speed_over_ground;

  // Member: course_over_ground
  cdr >> ros_message.course_over_ground;

  // Member: nmea_status
  cdr >> ros_message.nmea_status;

  // Member: nmea_mode
  cdr >> ros_message.nmea_mode;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hipnuc_msgs
get_serialized_size(
  const hipnuc_msgs::msg::HipnucImu & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: source
  {
    size_t item_size = sizeof(ros_message.source);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: valid
  {
    size_t item_size = sizeof(ros_message.valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: node_id
  {
    size_t item_size = sizeof(ros_message.node_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: main_status
  {
    size_t item_size = sizeof(ros_message.main_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_bias_converged
  {
    size_t item_size = sizeof(ros_message.gyro_bias_converged);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: attitude_converged
  {
    size_t item_size = sizeof(ros_message.attitude_converged);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnetic_disturbance
  {
    size_t item_size = sizeof(ros_message.magnetic_disturbance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: device_static
  {
    size_t item_size = sizeof(ros_message.device_static);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnetometer_aiding
  {
    size_t item_size = sizeof(ros_message.magnetometer_aiding);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ins_status
  {
    size_t item_size = sizeof(ros_message.ins_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acceleration
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.acceleration[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angular_velocity
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.angular_velocity[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnetic_field
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.magnetic_field[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: roll
  {
    size_t item_size = sizeof(ros_message.roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pitch
  {
    size_t item_size = sizeof(ros_message.pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yaw
  {
    size_t item_size = sizeof(ros_message.yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heading
  {
    size_t item_size = sizeof(ros_message.heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: quaternion_wxyz
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.quaternion_wxyz[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: inclination
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.inclination[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: inclination_yaw
  {
    size_t item_size = sizeof(ros_message.inclination_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: device_time_us
  {
    size_t item_size = sizeof(ros_message.device_time_us);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_valid
  {
    size_t item_size = sizeof(ros_message.utc_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_year
  {
    size_t item_size = sizeof(ros_message.utc_year);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_month
  {
    size_t item_size = sizeof(ros_message.utc_month);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_day
  {
    size_t item_size = sizeof(ros_message.utc_day);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_hour
  {
    size_t item_size = sizeof(ros_message.utc_hour);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_minute
  {
    size_t item_size = sizeof(ros_message.utc_minute);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_second
  {
    size_t item_size = sizeof(ros_message.utc_second);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_millisecond
  {
    size_t item_size = sizeof(ros_message.utc_millisecond);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gps_week
  {
    size_t item_size = sizeof(ros_message.gps_week);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gps_tow_ms
  {
    size_t item_size = sizeof(ros_message.gps_tow_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperature
  {
    size_t item_size = sizeof(ros_message.temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pressure
  {
    size_t item_size = sizeof(ros_message.pressure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heave_surge_sway
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.heave_surge_sway[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heave_surge_sway_frequency
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.heave_surge_sway_frequency[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: longitude
  {
    size_t item_size = sizeof(ros_message.longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: latitude
  {
    size_t item_size = sizeof(ros_message.latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: altitude_msl
  {
    size_t item_size = sizeof(ros_message.altitude_msl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gnss_longitude
  {
    size_t item_size = sizeof(ros_message.gnss_longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gnss_latitude
  {
    size_t item_size = sizeof(ros_message.gnss_latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gnss_altitude_msl
  {
    size_t item_size = sizeof(ros_message.gnss_altitude_msl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gnss_velocity_enu
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.gnss_velocity_enu[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: geoid_separation
  {
    size_t item_size = sizeof(ros_message.geoid_separation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: velocity_enu
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.velocity_enu[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acceleration_enu
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.acceleration_enu[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: position_quality
  {
    size_t item_size = sizeof(ros_message.position_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: position_satellites
  {
    size_t item_size = sizeof(ros_message.position_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heading_quality
  {
    size_t item_size = sizeof(ros_message.heading_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heading_satellites
  {
    size_t item_size = sizeof(ros_message.heading_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pdop
  {
    size_t item_size = sizeof(ros_message.pdop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hdop
  {
    size_t item_size = sizeof(ros_message.hdop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: differential_age
  {
    size_t item_size = sizeof(ros_message.differential_age);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: odometer_speed
  {
    size_t item_size = sizeof(ros_message.odometer_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed_over_ground
  {
    size_t item_size = sizeof(ros_message.speed_over_ground);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: course_over_ground
  {
    size_t item_size = sizeof(ros_message.course_over_ground);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: nmea_status
  {
    size_t item_size = sizeof(ros_message.nmea_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: nmea_mode
  {
    size_t item_size = sizeof(ros_message.nmea_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hipnuc_msgs
max_serialized_size_HipnucImu(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: source
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: node_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: main_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gyro_bias_converged
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: attitude_converged
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: magnetic_disturbance
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: device_static
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: magnetometer_aiding
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ins_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: acceleration
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angular_velocity
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: magnetic_field
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: heading
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: quaternion_wxyz
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: inclination
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: inclination_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: device_time_us
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: utc_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: utc_year
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: utc_month
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: utc_day
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: utc_hour
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: utc_minute
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: utc_second
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: utc_millisecond
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gps_week
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gps_tow_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temperature
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pressure
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: heave_surge_sway
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: heave_surge_sway_frequency
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: longitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: latitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: altitude_msl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gnss_longitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gnss_latitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gnss_altitude_msl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gnss_velocity_enu
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: geoid_separation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: velocity_enu
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: acceleration_enu
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: position_quality
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: position_satellites
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: heading_quality
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: heading_satellites
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pdop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hdop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: differential_age
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: odometer_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: speed_over_ground
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: course_over_ground
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: nmea_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: nmea_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = hipnuc_msgs::msg::HipnucImu;
    is_plain =
      (
      offsetof(DataType, nmea_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _HipnucImu__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hipnuc_msgs::msg::HipnucImu *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HipnucImu__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hipnuc_msgs::msg::HipnucImu *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HipnucImu__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hipnuc_msgs::msg::HipnucImu *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HipnucImu__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HipnucImu(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HipnucImu__callbacks = {
  "hipnuc_msgs::msg",
  "HipnucImu",
  _HipnucImu__cdr_serialize,
  _HipnucImu__cdr_deserialize,
  _HipnucImu__get_serialized_size,
  _HipnucImu__max_serialized_size
};

static rosidl_message_type_support_t _HipnucImu__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HipnucImu__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hipnuc_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hipnuc_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<hipnuc_msgs::msg::HipnucImu>()
{
  return &hipnuc_msgs::msg::typesupport_fastrtps_cpp::_HipnucImu__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hipnuc_msgs, msg, HipnucImu)() {
  return &hipnuc_msgs::msg::typesupport_fastrtps_cpp::_HipnucImu__handle;
}

#ifdef __cplusplus
}
#endif
