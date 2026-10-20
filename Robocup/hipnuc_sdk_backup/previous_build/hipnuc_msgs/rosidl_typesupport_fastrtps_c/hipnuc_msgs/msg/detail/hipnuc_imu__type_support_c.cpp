// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice
#include "hipnuc_msgs/msg/detail/hipnuc_imu__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hipnuc_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hipnuc_msgs/msg/detail/hipnuc_imu__struct.h"
#include "hipnuc_msgs/msg/detail/hipnuc_imu__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hipnuc_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hipnuc_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hipnuc_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _HipnucImu__ros_msg_type = hipnuc_msgs__msg__HipnucImu;

static bool _HipnucImu__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HipnucImu__ros_msg_type * ros_message = static_cast<const _HipnucImu__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: source
  {
    cdr << ros_message->source;
  }

  // Field name: valid
  {
    cdr << ros_message->valid;
  }

  // Field name: node_id
  {
    cdr << ros_message->node_id;
  }

  // Field name: main_status
  {
    cdr << ros_message->main_status;
  }

  // Field name: gyro_bias_converged
  {
    cdr << (ros_message->gyro_bias_converged ? true : false);
  }

  // Field name: attitude_converged
  {
    cdr << (ros_message->attitude_converged ? true : false);
  }

  // Field name: magnetic_disturbance
  {
    cdr << (ros_message->magnetic_disturbance ? true : false);
  }

  // Field name: device_static
  {
    cdr << (ros_message->device_static ? true : false);
  }

  // Field name: magnetometer_aiding
  {
    cdr << (ros_message->magnetometer_aiding ? true : false);
  }

  // Field name: ins_status
  {
    cdr << ros_message->ins_status;
  }

  // Field name: acceleration
  {
    size_t size = 3;
    auto array_ptr = ros_message->acceleration;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: angular_velocity
  {
    size_t size = 3;
    auto array_ptr = ros_message->angular_velocity;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: magnetic_field
  {
    size_t size = 3;
    auto array_ptr = ros_message->magnetic_field;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: roll
  {
    cdr << ros_message->roll;
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  // Field name: heading
  {
    cdr << ros_message->heading;
  }

  // Field name: quaternion_wxyz
  {
    size_t size = 4;
    auto array_ptr = ros_message->quaternion_wxyz;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: inclination
  {
    size_t size = 2;
    auto array_ptr = ros_message->inclination;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: inclination_yaw
  {
    cdr << ros_message->inclination_yaw;
  }

  // Field name: device_time_us
  {
    cdr << ros_message->device_time_us;
  }

  // Field name: utc_valid
  {
    cdr << (ros_message->utc_valid ? true : false);
  }

  // Field name: utc_year
  {
    cdr << ros_message->utc_year;
  }

  // Field name: utc_month
  {
    cdr << ros_message->utc_month;
  }

  // Field name: utc_day
  {
    cdr << ros_message->utc_day;
  }

  // Field name: utc_hour
  {
    cdr << ros_message->utc_hour;
  }

  // Field name: utc_minute
  {
    cdr << ros_message->utc_minute;
  }

  // Field name: utc_second
  {
    cdr << ros_message->utc_second;
  }

  // Field name: utc_millisecond
  {
    cdr << ros_message->utc_millisecond;
  }

  // Field name: gps_week
  {
    cdr << ros_message->gps_week;
  }

  // Field name: gps_tow_ms
  {
    cdr << ros_message->gps_tow_ms;
  }

  // Field name: temperature
  {
    cdr << ros_message->temperature;
  }

  // Field name: pressure
  {
    cdr << ros_message->pressure;
  }

  // Field name: heave_surge_sway
  {
    size_t size = 3;
    auto array_ptr = ros_message->heave_surge_sway;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: heave_surge_sway_frequency
  {
    size_t size = 3;
    auto array_ptr = ros_message->heave_surge_sway_frequency;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: longitude
  {
    cdr << ros_message->longitude;
  }

  // Field name: latitude
  {
    cdr << ros_message->latitude;
  }

  // Field name: altitude_msl
  {
    cdr << ros_message->altitude_msl;
  }

  // Field name: gnss_longitude
  {
    cdr << ros_message->gnss_longitude;
  }

  // Field name: gnss_latitude
  {
    cdr << ros_message->gnss_latitude;
  }

  // Field name: gnss_altitude_msl
  {
    cdr << ros_message->gnss_altitude_msl;
  }

  // Field name: gnss_velocity_enu
  {
    size_t size = 3;
    auto array_ptr = ros_message->gnss_velocity_enu;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: geoid_separation
  {
    cdr << ros_message->geoid_separation;
  }

  // Field name: velocity_enu
  {
    size_t size = 3;
    auto array_ptr = ros_message->velocity_enu;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: acceleration_enu
  {
    size_t size = 3;
    auto array_ptr = ros_message->acceleration_enu;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: position_quality
  {
    cdr << ros_message->position_quality;
  }

  // Field name: position_satellites
  {
    cdr << ros_message->position_satellites;
  }

  // Field name: heading_quality
  {
    cdr << ros_message->heading_quality;
  }

  // Field name: heading_satellites
  {
    cdr << ros_message->heading_satellites;
  }

  // Field name: pdop
  {
    cdr << ros_message->pdop;
  }

  // Field name: hdop
  {
    cdr << ros_message->hdop;
  }

  // Field name: differential_age
  {
    cdr << ros_message->differential_age;
  }

  // Field name: odometer_speed
  {
    cdr << ros_message->odometer_speed;
  }

  // Field name: speed_over_ground
  {
    cdr << ros_message->speed_over_ground;
  }

  // Field name: course_over_ground
  {
    cdr << ros_message->course_over_ground;
  }

  // Field name: nmea_status
  {
    cdr << ros_message->nmea_status;
  }

  // Field name: nmea_mode
  {
    cdr << ros_message->nmea_mode;
  }

  return true;
}

static bool _HipnucImu__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HipnucImu__ros_msg_type * ros_message = static_cast<_HipnucImu__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: source
  {
    cdr >> ros_message->source;
  }

  // Field name: valid
  {
    cdr >> ros_message->valid;
  }

  // Field name: node_id
  {
    cdr >> ros_message->node_id;
  }

  // Field name: main_status
  {
    cdr >> ros_message->main_status;
  }

  // Field name: gyro_bias_converged
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->gyro_bias_converged = tmp ? true : false;
  }

  // Field name: attitude_converged
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->attitude_converged = tmp ? true : false;
  }

  // Field name: magnetic_disturbance
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->magnetic_disturbance = tmp ? true : false;
  }

  // Field name: device_static
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->device_static = tmp ? true : false;
  }

  // Field name: magnetometer_aiding
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->magnetometer_aiding = tmp ? true : false;
  }

  // Field name: ins_status
  {
    cdr >> ros_message->ins_status;
  }

  // Field name: acceleration
  {
    size_t size = 3;
    auto array_ptr = ros_message->acceleration;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: angular_velocity
  {
    size_t size = 3;
    auto array_ptr = ros_message->angular_velocity;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: magnetic_field
  {
    size_t size = 3;
    auto array_ptr = ros_message->magnetic_field;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: roll
  {
    cdr >> ros_message->roll;
  }

  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr >> ros_message->yaw;
  }

  // Field name: heading
  {
    cdr >> ros_message->heading;
  }

  // Field name: quaternion_wxyz
  {
    size_t size = 4;
    auto array_ptr = ros_message->quaternion_wxyz;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: inclination
  {
    size_t size = 2;
    auto array_ptr = ros_message->inclination;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: inclination_yaw
  {
    cdr >> ros_message->inclination_yaw;
  }

  // Field name: device_time_us
  {
    cdr >> ros_message->device_time_us;
  }

  // Field name: utc_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->utc_valid = tmp ? true : false;
  }

  // Field name: utc_year
  {
    cdr >> ros_message->utc_year;
  }

  // Field name: utc_month
  {
    cdr >> ros_message->utc_month;
  }

  // Field name: utc_day
  {
    cdr >> ros_message->utc_day;
  }

  // Field name: utc_hour
  {
    cdr >> ros_message->utc_hour;
  }

  // Field name: utc_minute
  {
    cdr >> ros_message->utc_minute;
  }

  // Field name: utc_second
  {
    cdr >> ros_message->utc_second;
  }

  // Field name: utc_millisecond
  {
    cdr >> ros_message->utc_millisecond;
  }

  // Field name: gps_week
  {
    cdr >> ros_message->gps_week;
  }

  // Field name: gps_tow_ms
  {
    cdr >> ros_message->gps_tow_ms;
  }

  // Field name: temperature
  {
    cdr >> ros_message->temperature;
  }

  // Field name: pressure
  {
    cdr >> ros_message->pressure;
  }

  // Field name: heave_surge_sway
  {
    size_t size = 3;
    auto array_ptr = ros_message->heave_surge_sway;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: heave_surge_sway_frequency
  {
    size_t size = 3;
    auto array_ptr = ros_message->heave_surge_sway_frequency;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: longitude
  {
    cdr >> ros_message->longitude;
  }

  // Field name: latitude
  {
    cdr >> ros_message->latitude;
  }

  // Field name: altitude_msl
  {
    cdr >> ros_message->altitude_msl;
  }

  // Field name: gnss_longitude
  {
    cdr >> ros_message->gnss_longitude;
  }

  // Field name: gnss_latitude
  {
    cdr >> ros_message->gnss_latitude;
  }

  // Field name: gnss_altitude_msl
  {
    cdr >> ros_message->gnss_altitude_msl;
  }

  // Field name: gnss_velocity_enu
  {
    size_t size = 3;
    auto array_ptr = ros_message->gnss_velocity_enu;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: geoid_separation
  {
    cdr >> ros_message->geoid_separation;
  }

  // Field name: velocity_enu
  {
    size_t size = 3;
    auto array_ptr = ros_message->velocity_enu;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: acceleration_enu
  {
    size_t size = 3;
    auto array_ptr = ros_message->acceleration_enu;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: position_quality
  {
    cdr >> ros_message->position_quality;
  }

  // Field name: position_satellites
  {
    cdr >> ros_message->position_satellites;
  }

  // Field name: heading_quality
  {
    cdr >> ros_message->heading_quality;
  }

  // Field name: heading_satellites
  {
    cdr >> ros_message->heading_satellites;
  }

  // Field name: pdop
  {
    cdr >> ros_message->pdop;
  }

  // Field name: hdop
  {
    cdr >> ros_message->hdop;
  }

  // Field name: differential_age
  {
    cdr >> ros_message->differential_age;
  }

  // Field name: odometer_speed
  {
    cdr >> ros_message->odometer_speed;
  }

  // Field name: speed_over_ground
  {
    cdr >> ros_message->speed_over_ground;
  }

  // Field name: course_over_ground
  {
    cdr >> ros_message->course_over_ground;
  }

  // Field name: nmea_status
  {
    cdr >> ros_message->nmea_status;
  }

  // Field name: nmea_mode
  {
    cdr >> ros_message->nmea_mode;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hipnuc_msgs
size_t get_serialized_size_hipnuc_msgs__msg__HipnucImu(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HipnucImu__ros_msg_type * ros_message = static_cast<const _HipnucImu__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name source
  {
    size_t item_size = sizeof(ros_message->source);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name valid
  {
    size_t item_size = sizeof(ros_message->valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name node_id
  {
    size_t item_size = sizeof(ros_message->node_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name main_status
  {
    size_t item_size = sizeof(ros_message->main_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_bias_converged
  {
    size_t item_size = sizeof(ros_message->gyro_bias_converged);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name attitude_converged
  {
    size_t item_size = sizeof(ros_message->attitude_converged);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name magnetic_disturbance
  {
    size_t item_size = sizeof(ros_message->magnetic_disturbance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name device_static
  {
    size_t item_size = sizeof(ros_message->device_static);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name magnetometer_aiding
  {
    size_t item_size = sizeof(ros_message->magnetometer_aiding);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ins_status
  {
    size_t item_size = sizeof(ros_message->ins_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acceleration
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->acceleration;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angular_velocity
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->angular_velocity;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name magnetic_field
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->magnetic_field;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name roll
  {
    size_t item_size = sizeof(ros_message->roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heading
  {
    size_t item_size = sizeof(ros_message->heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name quaternion_wxyz
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->quaternion_wxyz;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name inclination
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->inclination;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name inclination_yaw
  {
    size_t item_size = sizeof(ros_message->inclination_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name device_time_us
  {
    size_t item_size = sizeof(ros_message->device_time_us);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_valid
  {
    size_t item_size = sizeof(ros_message->utc_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_year
  {
    size_t item_size = sizeof(ros_message->utc_year);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_month
  {
    size_t item_size = sizeof(ros_message->utc_month);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_day
  {
    size_t item_size = sizeof(ros_message->utc_day);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_hour
  {
    size_t item_size = sizeof(ros_message->utc_hour);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_minute
  {
    size_t item_size = sizeof(ros_message->utc_minute);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_second
  {
    size_t item_size = sizeof(ros_message->utc_second);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_millisecond
  {
    size_t item_size = sizeof(ros_message->utc_millisecond);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gps_week
  {
    size_t item_size = sizeof(ros_message->gps_week);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gps_tow_ms
  {
    size_t item_size = sizeof(ros_message->gps_tow_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temperature
  {
    size_t item_size = sizeof(ros_message->temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pressure
  {
    size_t item_size = sizeof(ros_message->pressure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heave_surge_sway
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->heave_surge_sway;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heave_surge_sway_frequency
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->heave_surge_sway_frequency;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name longitude
  {
    size_t item_size = sizeof(ros_message->longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name latitude
  {
    size_t item_size = sizeof(ros_message->latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name altitude_msl
  {
    size_t item_size = sizeof(ros_message->altitude_msl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gnss_longitude
  {
    size_t item_size = sizeof(ros_message->gnss_longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gnss_latitude
  {
    size_t item_size = sizeof(ros_message->gnss_latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gnss_altitude_msl
  {
    size_t item_size = sizeof(ros_message->gnss_altitude_msl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gnss_velocity_enu
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->gnss_velocity_enu;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name geoid_separation
  {
    size_t item_size = sizeof(ros_message->geoid_separation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name velocity_enu
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->velocity_enu;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acceleration_enu
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->acceleration_enu;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position_quality
  {
    size_t item_size = sizeof(ros_message->position_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position_satellites
  {
    size_t item_size = sizeof(ros_message->position_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heading_quality
  {
    size_t item_size = sizeof(ros_message->heading_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heading_satellites
  {
    size_t item_size = sizeof(ros_message->heading_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pdop
  {
    size_t item_size = sizeof(ros_message->pdop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hdop
  {
    size_t item_size = sizeof(ros_message->hdop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name differential_age
  {
    size_t item_size = sizeof(ros_message->differential_age);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name odometer_speed
  {
    size_t item_size = sizeof(ros_message->odometer_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_over_ground
  {
    size_t item_size = sizeof(ros_message->speed_over_ground);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name course_over_ground
  {
    size_t item_size = sizeof(ros_message->course_over_ground);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nmea_status
  {
    size_t item_size = sizeof(ros_message->nmea_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nmea_mode
  {
    size_t item_size = sizeof(ros_message->nmea_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HipnucImu__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hipnuc_msgs__msg__HipnucImu(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hipnuc_msgs
size_t max_serialized_size_hipnuc_msgs__msg__HipnucImu(
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

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: source
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: node_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: main_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: gyro_bias_converged
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: attitude_converged
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: magnetic_disturbance
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: device_static
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: magnetometer_aiding
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ins_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: acceleration
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: angular_velocity
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: magnetic_field
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: heading
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: quaternion_wxyz
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: inclination
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: inclination_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: device_time_us
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: utc_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: utc_year
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: utc_month
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: utc_day
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: utc_hour
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: utc_minute
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: utc_second
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: utc_millisecond
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: gps_week
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: gps_tow_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temperature
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pressure
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: heave_surge_sway
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: heave_surge_sway_frequency
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: longitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: latitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: altitude_msl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gnss_longitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gnss_latitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gnss_altitude_msl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gnss_velocity_enu
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: geoid_separation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: velocity_enu
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: acceleration_enu
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: position_quality
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: position_satellites
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: heading_quality
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: heading_satellites
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: pdop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hdop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: differential_age
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: odometer_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed_over_ground
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: course_over_ground
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nmea_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: nmea_mode
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
    using DataType = hipnuc_msgs__msg__HipnucImu;
    is_plain =
      (
      offsetof(DataType, nmea_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _HipnucImu__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_hipnuc_msgs__msg__HipnucImu(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HipnucImu = {
  "hipnuc_msgs::msg",
  "HipnucImu",
  _HipnucImu__cdr_serialize,
  _HipnucImu__cdr_deserialize,
  _HipnucImu__get_serialized_size,
  _HipnucImu__max_serialized_size
};

static rosidl_message_type_support_t _HipnucImu__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HipnucImu,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hipnuc_msgs, msg, HipnucImu)() {
  return &_HipnucImu__type_support;
}

#if defined(__cplusplus)
}
#endif
