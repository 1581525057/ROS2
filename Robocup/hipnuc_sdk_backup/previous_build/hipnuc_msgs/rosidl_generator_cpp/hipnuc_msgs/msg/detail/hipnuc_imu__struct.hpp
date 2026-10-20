// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice

#ifndef HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__STRUCT_HPP_
#define HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hipnuc_msgs__msg__HipnucImu __attribute__((deprecated))
#else
# define DEPRECATED__hipnuc_msgs__msg__HipnucImu __declspec(deprecated)
#endif

namespace hipnuc_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HipnucImu_
{
  using Type = HipnucImu_<ContainerAllocator>;

  explicit HipnucImu_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->source = 0;
      this->valid = 0ull;
      this->node_id = 0;
      this->main_status = 0;
      this->gyro_bias_converged = false;
      this->attitude_converged = false;
      this->magnetic_disturbance = false;
      this->device_static = false;
      this->magnetometer_aiding = false;
      this->ins_status = 0;
      std::fill<typename std::array<float, 3>::iterator, float>(this->acceleration.begin(), this->acceleration.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->angular_velocity.begin(), this->angular_velocity.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->magnetic_field.begin(), this->magnetic_field.end(), 0.0f);
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
      this->heading = 0.0f;
      std::fill<typename std::array<float, 4>::iterator, float>(this->quaternion_wxyz.begin(), this->quaternion_wxyz.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->inclination.begin(), this->inclination.end(), 0.0f);
      this->inclination_yaw = 0.0f;
      this->device_time_us = 0ull;
      this->utc_valid = false;
      this->utc_year = 0;
      this->utc_month = 0;
      this->utc_day = 0;
      this->utc_hour = 0;
      this->utc_minute = 0;
      this->utc_second = 0;
      this->utc_millisecond = 0;
      this->gps_week = 0;
      this->gps_tow_ms = 0ul;
      this->temperature = 0.0f;
      this->pressure = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->heave_surge_sway.begin(), this->heave_surge_sway.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->heave_surge_sway_frequency.begin(), this->heave_surge_sway_frequency.end(), 0.0f);
      this->longitude = 0.0;
      this->latitude = 0.0;
      this->altitude_msl = 0.0;
      this->gnss_longitude = 0.0;
      this->gnss_latitude = 0.0;
      this->gnss_altitude_msl = 0.0;
      std::fill<typename std::array<float, 3>::iterator, float>(this->gnss_velocity_enu.begin(), this->gnss_velocity_enu.end(), 0.0f);
      this->geoid_separation = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->velocity_enu.begin(), this->velocity_enu.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->acceleration_enu.begin(), this->acceleration_enu.end(), 0.0f);
      this->position_quality = 0;
      this->position_satellites = 0;
      this->heading_quality = 0;
      this->heading_satellites = 0;
      this->pdop = 0.0f;
      this->hdop = 0.0f;
      this->differential_age = 0.0f;
      this->odometer_speed = 0.0f;
      this->speed_over_ground = 0.0f;
      this->course_over_ground = 0.0f;
      this->nmea_status = 0;
      this->nmea_mode = 0;
    }
  }

  explicit HipnucImu_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    acceleration(_alloc),
    angular_velocity(_alloc),
    magnetic_field(_alloc),
    quaternion_wxyz(_alloc),
    inclination(_alloc),
    heave_surge_sway(_alloc),
    heave_surge_sway_frequency(_alloc),
    gnss_velocity_enu(_alloc),
    velocity_enu(_alloc),
    acceleration_enu(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->source = 0;
      this->valid = 0ull;
      this->node_id = 0;
      this->main_status = 0;
      this->gyro_bias_converged = false;
      this->attitude_converged = false;
      this->magnetic_disturbance = false;
      this->device_static = false;
      this->magnetometer_aiding = false;
      this->ins_status = 0;
      std::fill<typename std::array<float, 3>::iterator, float>(this->acceleration.begin(), this->acceleration.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->angular_velocity.begin(), this->angular_velocity.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->magnetic_field.begin(), this->magnetic_field.end(), 0.0f);
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
      this->heading = 0.0f;
      std::fill<typename std::array<float, 4>::iterator, float>(this->quaternion_wxyz.begin(), this->quaternion_wxyz.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->inclination.begin(), this->inclination.end(), 0.0f);
      this->inclination_yaw = 0.0f;
      this->device_time_us = 0ull;
      this->utc_valid = false;
      this->utc_year = 0;
      this->utc_month = 0;
      this->utc_day = 0;
      this->utc_hour = 0;
      this->utc_minute = 0;
      this->utc_second = 0;
      this->utc_millisecond = 0;
      this->gps_week = 0;
      this->gps_tow_ms = 0ul;
      this->temperature = 0.0f;
      this->pressure = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->heave_surge_sway.begin(), this->heave_surge_sway.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->heave_surge_sway_frequency.begin(), this->heave_surge_sway_frequency.end(), 0.0f);
      this->longitude = 0.0;
      this->latitude = 0.0;
      this->altitude_msl = 0.0;
      this->gnss_longitude = 0.0;
      this->gnss_latitude = 0.0;
      this->gnss_altitude_msl = 0.0;
      std::fill<typename std::array<float, 3>::iterator, float>(this->gnss_velocity_enu.begin(), this->gnss_velocity_enu.end(), 0.0f);
      this->geoid_separation = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->velocity_enu.begin(), this->velocity_enu.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->acceleration_enu.begin(), this->acceleration_enu.end(), 0.0f);
      this->position_quality = 0;
      this->position_satellites = 0;
      this->heading_quality = 0;
      this->heading_satellites = 0;
      this->pdop = 0.0f;
      this->hdop = 0.0f;
      this->differential_age = 0.0f;
      this->odometer_speed = 0.0f;
      this->speed_over_ground = 0.0f;
      this->course_over_ground = 0.0f;
      this->nmea_status = 0;
      this->nmea_mode = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _source_type =
    uint8_t;
  _source_type source;
  using _valid_type =
    uint64_t;
  _valid_type valid;
  using _node_id_type =
    uint8_t;
  _node_id_type node_id;
  using _main_status_type =
    uint16_t;
  _main_status_type main_status;
  using _gyro_bias_converged_type =
    bool;
  _gyro_bias_converged_type gyro_bias_converged;
  using _attitude_converged_type =
    bool;
  _attitude_converged_type attitude_converged;
  using _magnetic_disturbance_type =
    bool;
  _magnetic_disturbance_type magnetic_disturbance;
  using _device_static_type =
    bool;
  _device_static_type device_static;
  using _magnetometer_aiding_type =
    bool;
  _magnetometer_aiding_type magnetometer_aiding;
  using _ins_status_type =
    uint8_t;
  _ins_status_type ins_status;
  using _acceleration_type =
    std::array<float, 3>;
  _acceleration_type acceleration;
  using _angular_velocity_type =
    std::array<float, 3>;
  _angular_velocity_type angular_velocity;
  using _magnetic_field_type =
    std::array<float, 3>;
  _magnetic_field_type magnetic_field;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _heading_type =
    float;
  _heading_type heading;
  using _quaternion_wxyz_type =
    std::array<float, 4>;
  _quaternion_wxyz_type quaternion_wxyz;
  using _inclination_type =
    std::array<float, 2>;
  _inclination_type inclination;
  using _inclination_yaw_type =
    float;
  _inclination_yaw_type inclination_yaw;
  using _device_time_us_type =
    uint64_t;
  _device_time_us_type device_time_us;
  using _utc_valid_type =
    bool;
  _utc_valid_type utc_valid;
  using _utc_year_type =
    uint16_t;
  _utc_year_type utc_year;
  using _utc_month_type =
    uint8_t;
  _utc_month_type utc_month;
  using _utc_day_type =
    uint8_t;
  _utc_day_type utc_day;
  using _utc_hour_type =
    uint8_t;
  _utc_hour_type utc_hour;
  using _utc_minute_type =
    uint8_t;
  _utc_minute_type utc_minute;
  using _utc_second_type =
    uint8_t;
  _utc_second_type utc_second;
  using _utc_millisecond_type =
    uint16_t;
  _utc_millisecond_type utc_millisecond;
  using _gps_week_type =
    uint16_t;
  _gps_week_type gps_week;
  using _gps_tow_ms_type =
    uint32_t;
  _gps_tow_ms_type gps_tow_ms;
  using _temperature_type =
    float;
  _temperature_type temperature;
  using _pressure_type =
    float;
  _pressure_type pressure;
  using _heave_surge_sway_type =
    std::array<float, 3>;
  _heave_surge_sway_type heave_surge_sway;
  using _heave_surge_sway_frequency_type =
    std::array<float, 3>;
  _heave_surge_sway_frequency_type heave_surge_sway_frequency;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _altitude_msl_type =
    double;
  _altitude_msl_type altitude_msl;
  using _gnss_longitude_type =
    double;
  _gnss_longitude_type gnss_longitude;
  using _gnss_latitude_type =
    double;
  _gnss_latitude_type gnss_latitude;
  using _gnss_altitude_msl_type =
    double;
  _gnss_altitude_msl_type gnss_altitude_msl;
  using _gnss_velocity_enu_type =
    std::array<float, 3>;
  _gnss_velocity_enu_type gnss_velocity_enu;
  using _geoid_separation_type =
    float;
  _geoid_separation_type geoid_separation;
  using _velocity_enu_type =
    std::array<float, 3>;
  _velocity_enu_type velocity_enu;
  using _acceleration_enu_type =
    std::array<float, 3>;
  _acceleration_enu_type acceleration_enu;
  using _position_quality_type =
    uint8_t;
  _position_quality_type position_quality;
  using _position_satellites_type =
    uint8_t;
  _position_satellites_type position_satellites;
  using _heading_quality_type =
    uint8_t;
  _heading_quality_type heading_quality;
  using _heading_satellites_type =
    uint8_t;
  _heading_satellites_type heading_satellites;
  using _pdop_type =
    float;
  _pdop_type pdop;
  using _hdop_type =
    float;
  _hdop_type hdop;
  using _differential_age_type =
    float;
  _differential_age_type differential_age;
  using _odometer_speed_type =
    float;
  _odometer_speed_type odometer_speed;
  using _speed_over_ground_type =
    float;
  _speed_over_ground_type speed_over_ground;
  using _course_over_ground_type =
    float;
  _course_over_ground_type course_over_ground;
  using _nmea_status_type =
    uint8_t;
  _nmea_status_type nmea_status;
  using _nmea_mode_type =
    uint8_t;
  _nmea_mode_type nmea_mode;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__source(
    const uint8_t & _arg)
  {
    this->source = _arg;
    return *this;
  }
  Type & set__valid(
    const uint64_t & _arg)
  {
    this->valid = _arg;
    return *this;
  }
  Type & set__node_id(
    const uint8_t & _arg)
  {
    this->node_id = _arg;
    return *this;
  }
  Type & set__main_status(
    const uint16_t & _arg)
  {
    this->main_status = _arg;
    return *this;
  }
  Type & set__gyro_bias_converged(
    const bool & _arg)
  {
    this->gyro_bias_converged = _arg;
    return *this;
  }
  Type & set__attitude_converged(
    const bool & _arg)
  {
    this->attitude_converged = _arg;
    return *this;
  }
  Type & set__magnetic_disturbance(
    const bool & _arg)
  {
    this->magnetic_disturbance = _arg;
    return *this;
  }
  Type & set__device_static(
    const bool & _arg)
  {
    this->device_static = _arg;
    return *this;
  }
  Type & set__magnetometer_aiding(
    const bool & _arg)
  {
    this->magnetometer_aiding = _arg;
    return *this;
  }
  Type & set__ins_status(
    const uint8_t & _arg)
  {
    this->ins_status = _arg;
    return *this;
  }
  Type & set__acceleration(
    const std::array<float, 3> & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__angular_velocity(
    const std::array<float, 3> & _arg)
  {
    this->angular_velocity = _arg;
    return *this;
  }
  Type & set__magnetic_field(
    const std::array<float, 3> & _arg)
  {
    this->magnetic_field = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__heading(
    const float & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__quaternion_wxyz(
    const std::array<float, 4> & _arg)
  {
    this->quaternion_wxyz = _arg;
    return *this;
  }
  Type & set__inclination(
    const std::array<float, 2> & _arg)
  {
    this->inclination = _arg;
    return *this;
  }
  Type & set__inclination_yaw(
    const float & _arg)
  {
    this->inclination_yaw = _arg;
    return *this;
  }
  Type & set__device_time_us(
    const uint64_t & _arg)
  {
    this->device_time_us = _arg;
    return *this;
  }
  Type & set__utc_valid(
    const bool & _arg)
  {
    this->utc_valid = _arg;
    return *this;
  }
  Type & set__utc_year(
    const uint16_t & _arg)
  {
    this->utc_year = _arg;
    return *this;
  }
  Type & set__utc_month(
    const uint8_t & _arg)
  {
    this->utc_month = _arg;
    return *this;
  }
  Type & set__utc_day(
    const uint8_t & _arg)
  {
    this->utc_day = _arg;
    return *this;
  }
  Type & set__utc_hour(
    const uint8_t & _arg)
  {
    this->utc_hour = _arg;
    return *this;
  }
  Type & set__utc_minute(
    const uint8_t & _arg)
  {
    this->utc_minute = _arg;
    return *this;
  }
  Type & set__utc_second(
    const uint8_t & _arg)
  {
    this->utc_second = _arg;
    return *this;
  }
  Type & set__utc_millisecond(
    const uint16_t & _arg)
  {
    this->utc_millisecond = _arg;
    return *this;
  }
  Type & set__gps_week(
    const uint16_t & _arg)
  {
    this->gps_week = _arg;
    return *this;
  }
  Type & set__gps_tow_ms(
    const uint32_t & _arg)
  {
    this->gps_tow_ms = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__pressure(
    const float & _arg)
  {
    this->pressure = _arg;
    return *this;
  }
  Type & set__heave_surge_sway(
    const std::array<float, 3> & _arg)
  {
    this->heave_surge_sway = _arg;
    return *this;
  }
  Type & set__heave_surge_sway_frequency(
    const std::array<float, 3> & _arg)
  {
    this->heave_surge_sway_frequency = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__altitude_msl(
    const double & _arg)
  {
    this->altitude_msl = _arg;
    return *this;
  }
  Type & set__gnss_longitude(
    const double & _arg)
  {
    this->gnss_longitude = _arg;
    return *this;
  }
  Type & set__gnss_latitude(
    const double & _arg)
  {
    this->gnss_latitude = _arg;
    return *this;
  }
  Type & set__gnss_altitude_msl(
    const double & _arg)
  {
    this->gnss_altitude_msl = _arg;
    return *this;
  }
  Type & set__gnss_velocity_enu(
    const std::array<float, 3> & _arg)
  {
    this->gnss_velocity_enu = _arg;
    return *this;
  }
  Type & set__geoid_separation(
    const float & _arg)
  {
    this->geoid_separation = _arg;
    return *this;
  }
  Type & set__velocity_enu(
    const std::array<float, 3> & _arg)
  {
    this->velocity_enu = _arg;
    return *this;
  }
  Type & set__acceleration_enu(
    const std::array<float, 3> & _arg)
  {
    this->acceleration_enu = _arg;
    return *this;
  }
  Type & set__position_quality(
    const uint8_t & _arg)
  {
    this->position_quality = _arg;
    return *this;
  }
  Type & set__position_satellites(
    const uint8_t & _arg)
  {
    this->position_satellites = _arg;
    return *this;
  }
  Type & set__heading_quality(
    const uint8_t & _arg)
  {
    this->heading_quality = _arg;
    return *this;
  }
  Type & set__heading_satellites(
    const uint8_t & _arg)
  {
    this->heading_satellites = _arg;
    return *this;
  }
  Type & set__pdop(
    const float & _arg)
  {
    this->pdop = _arg;
    return *this;
  }
  Type & set__hdop(
    const float & _arg)
  {
    this->hdop = _arg;
    return *this;
  }
  Type & set__differential_age(
    const float & _arg)
  {
    this->differential_age = _arg;
    return *this;
  }
  Type & set__odometer_speed(
    const float & _arg)
  {
    this->odometer_speed = _arg;
    return *this;
  }
  Type & set__speed_over_ground(
    const float & _arg)
  {
    this->speed_over_ground = _arg;
    return *this;
  }
  Type & set__course_over_ground(
    const float & _arg)
  {
    this->course_over_ground = _arg;
    return *this;
  }
  Type & set__nmea_status(
    const uint8_t & _arg)
  {
    this->nmea_status = _arg;
    return *this;
  }
  Type & set__nmea_mode(
    const uint8_t & _arg)
  {
    this->nmea_mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint64_t VALID_STATUS =
    1u;
  static constexpr uint64_t VALID_INS_STATUS =
    2u;
  static constexpr uint64_t VALID_ACC =
    4u;
  static constexpr uint64_t VALID_GYR =
    8u;
  static constexpr uint64_t VALID_MAG =
    16u;
  static constexpr uint64_t VALID_ROLL_PITCH =
    32u;
  static constexpr uint64_t VALID_HEADING =
    64u;
  static constexpr uint64_t VALID_QUAT =
    128u;
  static constexpr uint64_t VALID_DEVICE_TIME =
    256u;
  static constexpr uint64_t VALID_UTC =
    512u;
  static constexpr uint64_t VALID_GPS_TIME =
    1024u;
  static constexpr uint64_t VALID_PRESSURE =
    2048u;
  static constexpr uint64_t VALID_TEMPERATURE =
    4096u;
  static constexpr uint64_t VALID_INCLINATION =
    8192u;
  static constexpr uint64_t VALID_HEAVE =
    16384u;
  static constexpr uint64_t VALID_POSITION =
    32768u;
  static constexpr uint64_t VALID_VELOCITY_ENU =
    65536u;
  static constexpr uint64_t VALID_ACC_ENU =
    131072u;
  static constexpr uint64_t VALID_POSITION_QUALITY =
    262144u;
  static constexpr uint64_t VALID_PDOP =
    524288u;
  static constexpr uint64_t VALID_DIFF_AGE =
    1048576u;
  static constexpr uint64_t VALID_UNDULATION =
    2097152u;
  static constexpr uint64_t VALID_ODOMETER =
    4194304u;
  static constexpr uint64_t VALID_GNSS_POSITION =
    8388608u;
  static constexpr uint64_t VALID_GNSS_VELOCITY =
    16777216u;
  static constexpr uint64_t VALID_SOG =
    33554432u;
  static constexpr uint64_t VALID_NODE_ID =
    67108864u;
  static constexpr uint64_t VALID_YAW =
    134217728u;
  static constexpr uint64_t VALID_ALTITUDE =
    268435456u;
  static constexpr uint64_t VALID_HEADING_QUALITY =
    536870912u;
  static constexpr uint64_t VALID_POSITION_SATELLITES =
    1073741824u;
  static constexpr uint64_t VALID_HEADING_SATELLITES =
    2147483648u;
  static constexpr uint64_t VALID_HDOP =
    4294967296u;
  static constexpr uint64_t VALID_HEAVE_FREQUENCY =
    8589934592u;
  static constexpr uint64_t VALID_GNSS_ALTITUDE =
    17179869184u;
  static constexpr uint64_t VALID_COG =
    34359738368u;
  static constexpr uint64_t VALID_NMEA_STATUS =
    68719476736u;
  static constexpr uint64_t VALID_NMEA_MODE =
    137438953472u;
  static constexpr uint64_t VALID_UTC_TIME_OF_DAY =
    274877906944u;
  static constexpr uint64_t VALID_INCLINATION_YAW =
    549755813888u;

  // pointer types
  using RawPtr =
    hipnuc_msgs::msg::HipnucImu_<ContainerAllocator> *;
  using ConstRawPtr =
    const hipnuc_msgs::msg::HipnucImu_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hipnuc_msgs::msg::HipnucImu_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hipnuc_msgs::msg::HipnucImu_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hipnuc_msgs__msg__HipnucImu
    std::shared_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hipnuc_msgs__msg__HipnucImu
    std::shared_ptr<hipnuc_msgs::msg::HipnucImu_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HipnucImu_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->source != other.source) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->node_id != other.node_id) {
      return false;
    }
    if (this->main_status != other.main_status) {
      return false;
    }
    if (this->gyro_bias_converged != other.gyro_bias_converged) {
      return false;
    }
    if (this->attitude_converged != other.attitude_converged) {
      return false;
    }
    if (this->magnetic_disturbance != other.magnetic_disturbance) {
      return false;
    }
    if (this->device_static != other.device_static) {
      return false;
    }
    if (this->magnetometer_aiding != other.magnetometer_aiding) {
      return false;
    }
    if (this->ins_status != other.ins_status) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->angular_velocity != other.angular_velocity) {
      return false;
    }
    if (this->magnetic_field != other.magnetic_field) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->quaternion_wxyz != other.quaternion_wxyz) {
      return false;
    }
    if (this->inclination != other.inclination) {
      return false;
    }
    if (this->inclination_yaw != other.inclination_yaw) {
      return false;
    }
    if (this->device_time_us != other.device_time_us) {
      return false;
    }
    if (this->utc_valid != other.utc_valid) {
      return false;
    }
    if (this->utc_year != other.utc_year) {
      return false;
    }
    if (this->utc_month != other.utc_month) {
      return false;
    }
    if (this->utc_day != other.utc_day) {
      return false;
    }
    if (this->utc_hour != other.utc_hour) {
      return false;
    }
    if (this->utc_minute != other.utc_minute) {
      return false;
    }
    if (this->utc_second != other.utc_second) {
      return false;
    }
    if (this->utc_millisecond != other.utc_millisecond) {
      return false;
    }
    if (this->gps_week != other.gps_week) {
      return false;
    }
    if (this->gps_tow_ms != other.gps_tow_ms) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->pressure != other.pressure) {
      return false;
    }
    if (this->heave_surge_sway != other.heave_surge_sway) {
      return false;
    }
    if (this->heave_surge_sway_frequency != other.heave_surge_sway_frequency) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->altitude_msl != other.altitude_msl) {
      return false;
    }
    if (this->gnss_longitude != other.gnss_longitude) {
      return false;
    }
    if (this->gnss_latitude != other.gnss_latitude) {
      return false;
    }
    if (this->gnss_altitude_msl != other.gnss_altitude_msl) {
      return false;
    }
    if (this->gnss_velocity_enu != other.gnss_velocity_enu) {
      return false;
    }
    if (this->geoid_separation != other.geoid_separation) {
      return false;
    }
    if (this->velocity_enu != other.velocity_enu) {
      return false;
    }
    if (this->acceleration_enu != other.acceleration_enu) {
      return false;
    }
    if (this->position_quality != other.position_quality) {
      return false;
    }
    if (this->position_satellites != other.position_satellites) {
      return false;
    }
    if (this->heading_quality != other.heading_quality) {
      return false;
    }
    if (this->heading_satellites != other.heading_satellites) {
      return false;
    }
    if (this->pdop != other.pdop) {
      return false;
    }
    if (this->hdop != other.hdop) {
      return false;
    }
    if (this->differential_age != other.differential_age) {
      return false;
    }
    if (this->odometer_speed != other.odometer_speed) {
      return false;
    }
    if (this->speed_over_ground != other.speed_over_ground) {
      return false;
    }
    if (this->course_over_ground != other.course_over_ground) {
      return false;
    }
    if (this->nmea_status != other.nmea_status) {
      return false;
    }
    if (this->nmea_mode != other.nmea_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const HipnucImu_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HipnucImu_

// alias to use template instance with default allocator
using HipnucImu =
  hipnuc_msgs::msg::HipnucImu_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_STATUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_INS_STATUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_ACC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_GYR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_MAG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_ROLL_PITCH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_HEADING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_QUAT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_DEVICE_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_UTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_GPS_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_PRESSURE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_TEMPERATURE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_INCLINATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_HEAVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_POSITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_VELOCITY_ENU;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_ACC_ENU;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_POSITION_QUALITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_PDOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_DIFF_AGE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_UNDULATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_ODOMETER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_GNSS_POSITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_GNSS_VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_SOG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_NODE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_YAW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_ALTITUDE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_HEADING_QUALITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_POSITION_SATELLITES;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_HEADING_SATELLITES;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_HDOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_HEAVE_FREQUENCY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_GNSS_ALTITUDE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_COG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_NMEA_STATUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_NMEA_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_UTC_TIME_OF_DAY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint64_t HipnucImu_<ContainerAllocator>::VALID_INCLINATION_YAW;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace hipnuc_msgs

#endif  // HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__STRUCT_HPP_
