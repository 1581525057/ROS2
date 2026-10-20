// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice

#ifndef HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__BUILDER_HPP_
#define HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hipnuc_msgs/msg/detail/hipnuc_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hipnuc_msgs
{

namespace msg
{

namespace builder
{

class Init_HipnucImu_nmea_mode
{
public:
  explicit Init_HipnucImu_nmea_mode(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  ::hipnuc_msgs::msg::HipnucImu nmea_mode(::hipnuc_msgs::msg::HipnucImu::_nmea_mode_type arg)
  {
    msg_.nmea_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_nmea_status
{
public:
  explicit Init_HipnucImu_nmea_status(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_nmea_mode nmea_status(::hipnuc_msgs::msg::HipnucImu::_nmea_status_type arg)
  {
    msg_.nmea_status = std::move(arg);
    return Init_HipnucImu_nmea_mode(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_course_over_ground
{
public:
  explicit Init_HipnucImu_course_over_ground(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_nmea_status course_over_ground(::hipnuc_msgs::msg::HipnucImu::_course_over_ground_type arg)
  {
    msg_.course_over_ground = std::move(arg);
    return Init_HipnucImu_nmea_status(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_speed_over_ground
{
public:
  explicit Init_HipnucImu_speed_over_ground(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_course_over_ground speed_over_ground(::hipnuc_msgs::msg::HipnucImu::_speed_over_ground_type arg)
  {
    msg_.speed_over_ground = std::move(arg);
    return Init_HipnucImu_course_over_ground(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_odometer_speed
{
public:
  explicit Init_HipnucImu_odometer_speed(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_speed_over_ground odometer_speed(::hipnuc_msgs::msg::HipnucImu::_odometer_speed_type arg)
  {
    msg_.odometer_speed = std::move(arg);
    return Init_HipnucImu_speed_over_ground(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_differential_age
{
public:
  explicit Init_HipnucImu_differential_age(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_odometer_speed differential_age(::hipnuc_msgs::msg::HipnucImu::_differential_age_type arg)
  {
    msg_.differential_age = std::move(arg);
    return Init_HipnucImu_odometer_speed(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_hdop
{
public:
  explicit Init_HipnucImu_hdop(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_differential_age hdop(::hipnuc_msgs::msg::HipnucImu::_hdop_type arg)
  {
    msg_.hdop = std::move(arg);
    return Init_HipnucImu_differential_age(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_pdop
{
public:
  explicit Init_HipnucImu_pdop(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_hdop pdop(::hipnuc_msgs::msg::HipnucImu::_pdop_type arg)
  {
    msg_.pdop = std::move(arg);
    return Init_HipnucImu_hdop(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_heading_satellites
{
public:
  explicit Init_HipnucImu_heading_satellites(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_pdop heading_satellites(::hipnuc_msgs::msg::HipnucImu::_heading_satellites_type arg)
  {
    msg_.heading_satellites = std::move(arg);
    return Init_HipnucImu_pdop(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_heading_quality
{
public:
  explicit Init_HipnucImu_heading_quality(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_heading_satellites heading_quality(::hipnuc_msgs::msg::HipnucImu::_heading_quality_type arg)
  {
    msg_.heading_quality = std::move(arg);
    return Init_HipnucImu_heading_satellites(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_position_satellites
{
public:
  explicit Init_HipnucImu_position_satellites(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_heading_quality position_satellites(::hipnuc_msgs::msg::HipnucImu::_position_satellites_type arg)
  {
    msg_.position_satellites = std::move(arg);
    return Init_HipnucImu_heading_quality(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_position_quality
{
public:
  explicit Init_HipnucImu_position_quality(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_position_satellites position_quality(::hipnuc_msgs::msg::HipnucImu::_position_quality_type arg)
  {
    msg_.position_quality = std::move(arg);
    return Init_HipnucImu_position_satellites(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_acceleration_enu
{
public:
  explicit Init_HipnucImu_acceleration_enu(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_position_quality acceleration_enu(::hipnuc_msgs::msg::HipnucImu::_acceleration_enu_type arg)
  {
    msg_.acceleration_enu = std::move(arg);
    return Init_HipnucImu_position_quality(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_velocity_enu
{
public:
  explicit Init_HipnucImu_velocity_enu(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_acceleration_enu velocity_enu(::hipnuc_msgs::msg::HipnucImu::_velocity_enu_type arg)
  {
    msg_.velocity_enu = std::move(arg);
    return Init_HipnucImu_acceleration_enu(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_geoid_separation
{
public:
  explicit Init_HipnucImu_geoid_separation(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_velocity_enu geoid_separation(::hipnuc_msgs::msg::HipnucImu::_geoid_separation_type arg)
  {
    msg_.geoid_separation = std::move(arg);
    return Init_HipnucImu_velocity_enu(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_gnss_velocity_enu
{
public:
  explicit Init_HipnucImu_gnss_velocity_enu(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_geoid_separation gnss_velocity_enu(::hipnuc_msgs::msg::HipnucImu::_gnss_velocity_enu_type arg)
  {
    msg_.gnss_velocity_enu = std::move(arg);
    return Init_HipnucImu_geoid_separation(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_gnss_altitude_msl
{
public:
  explicit Init_HipnucImu_gnss_altitude_msl(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_gnss_velocity_enu gnss_altitude_msl(::hipnuc_msgs::msg::HipnucImu::_gnss_altitude_msl_type arg)
  {
    msg_.gnss_altitude_msl = std::move(arg);
    return Init_HipnucImu_gnss_velocity_enu(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_gnss_latitude
{
public:
  explicit Init_HipnucImu_gnss_latitude(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_gnss_altitude_msl gnss_latitude(::hipnuc_msgs::msg::HipnucImu::_gnss_latitude_type arg)
  {
    msg_.gnss_latitude = std::move(arg);
    return Init_HipnucImu_gnss_altitude_msl(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_gnss_longitude
{
public:
  explicit Init_HipnucImu_gnss_longitude(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_gnss_latitude gnss_longitude(::hipnuc_msgs::msg::HipnucImu::_gnss_longitude_type arg)
  {
    msg_.gnss_longitude = std::move(arg);
    return Init_HipnucImu_gnss_latitude(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_altitude_msl
{
public:
  explicit Init_HipnucImu_altitude_msl(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_gnss_longitude altitude_msl(::hipnuc_msgs::msg::HipnucImu::_altitude_msl_type arg)
  {
    msg_.altitude_msl = std::move(arg);
    return Init_HipnucImu_gnss_longitude(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_latitude
{
public:
  explicit Init_HipnucImu_latitude(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_altitude_msl latitude(::hipnuc_msgs::msg::HipnucImu::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_HipnucImu_altitude_msl(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_longitude
{
public:
  explicit Init_HipnucImu_longitude(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_latitude longitude(::hipnuc_msgs::msg::HipnucImu::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_HipnucImu_latitude(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_heave_surge_sway_frequency
{
public:
  explicit Init_HipnucImu_heave_surge_sway_frequency(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_longitude heave_surge_sway_frequency(::hipnuc_msgs::msg::HipnucImu::_heave_surge_sway_frequency_type arg)
  {
    msg_.heave_surge_sway_frequency = std::move(arg);
    return Init_HipnucImu_longitude(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_heave_surge_sway
{
public:
  explicit Init_HipnucImu_heave_surge_sway(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_heave_surge_sway_frequency heave_surge_sway(::hipnuc_msgs::msg::HipnucImu::_heave_surge_sway_type arg)
  {
    msg_.heave_surge_sway = std::move(arg);
    return Init_HipnucImu_heave_surge_sway_frequency(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_pressure
{
public:
  explicit Init_HipnucImu_pressure(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_heave_surge_sway pressure(::hipnuc_msgs::msg::HipnucImu::_pressure_type arg)
  {
    msg_.pressure = std::move(arg);
    return Init_HipnucImu_heave_surge_sway(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_temperature
{
public:
  explicit Init_HipnucImu_temperature(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_pressure temperature(::hipnuc_msgs::msg::HipnucImu::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_HipnucImu_pressure(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_gps_tow_ms
{
public:
  explicit Init_HipnucImu_gps_tow_ms(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_temperature gps_tow_ms(::hipnuc_msgs::msg::HipnucImu::_gps_tow_ms_type arg)
  {
    msg_.gps_tow_ms = std::move(arg);
    return Init_HipnucImu_temperature(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_gps_week
{
public:
  explicit Init_HipnucImu_gps_week(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_gps_tow_ms gps_week(::hipnuc_msgs::msg::HipnucImu::_gps_week_type arg)
  {
    msg_.gps_week = std::move(arg);
    return Init_HipnucImu_gps_tow_ms(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_millisecond
{
public:
  explicit Init_HipnucImu_utc_millisecond(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_gps_week utc_millisecond(::hipnuc_msgs::msg::HipnucImu::_utc_millisecond_type arg)
  {
    msg_.utc_millisecond = std::move(arg);
    return Init_HipnucImu_gps_week(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_second
{
public:
  explicit Init_HipnucImu_utc_second(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_millisecond utc_second(::hipnuc_msgs::msg::HipnucImu::_utc_second_type arg)
  {
    msg_.utc_second = std::move(arg);
    return Init_HipnucImu_utc_millisecond(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_minute
{
public:
  explicit Init_HipnucImu_utc_minute(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_second utc_minute(::hipnuc_msgs::msg::HipnucImu::_utc_minute_type arg)
  {
    msg_.utc_minute = std::move(arg);
    return Init_HipnucImu_utc_second(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_hour
{
public:
  explicit Init_HipnucImu_utc_hour(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_minute utc_hour(::hipnuc_msgs::msg::HipnucImu::_utc_hour_type arg)
  {
    msg_.utc_hour = std::move(arg);
    return Init_HipnucImu_utc_minute(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_day
{
public:
  explicit Init_HipnucImu_utc_day(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_hour utc_day(::hipnuc_msgs::msg::HipnucImu::_utc_day_type arg)
  {
    msg_.utc_day = std::move(arg);
    return Init_HipnucImu_utc_hour(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_month
{
public:
  explicit Init_HipnucImu_utc_month(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_day utc_month(::hipnuc_msgs::msg::HipnucImu::_utc_month_type arg)
  {
    msg_.utc_month = std::move(arg);
    return Init_HipnucImu_utc_day(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_year
{
public:
  explicit Init_HipnucImu_utc_year(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_month utc_year(::hipnuc_msgs::msg::HipnucImu::_utc_year_type arg)
  {
    msg_.utc_year = std::move(arg);
    return Init_HipnucImu_utc_month(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_utc_valid
{
public:
  explicit Init_HipnucImu_utc_valid(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_year utc_valid(::hipnuc_msgs::msg::HipnucImu::_utc_valid_type arg)
  {
    msg_.utc_valid = std::move(arg);
    return Init_HipnucImu_utc_year(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_device_time_us
{
public:
  explicit Init_HipnucImu_device_time_us(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_utc_valid device_time_us(::hipnuc_msgs::msg::HipnucImu::_device_time_us_type arg)
  {
    msg_.device_time_us = std::move(arg);
    return Init_HipnucImu_utc_valid(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_inclination_yaw
{
public:
  explicit Init_HipnucImu_inclination_yaw(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_device_time_us inclination_yaw(::hipnuc_msgs::msg::HipnucImu::_inclination_yaw_type arg)
  {
    msg_.inclination_yaw = std::move(arg);
    return Init_HipnucImu_device_time_us(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_inclination
{
public:
  explicit Init_HipnucImu_inclination(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_inclination_yaw inclination(::hipnuc_msgs::msg::HipnucImu::_inclination_type arg)
  {
    msg_.inclination = std::move(arg);
    return Init_HipnucImu_inclination_yaw(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_quaternion_wxyz
{
public:
  explicit Init_HipnucImu_quaternion_wxyz(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_inclination quaternion_wxyz(::hipnuc_msgs::msg::HipnucImu::_quaternion_wxyz_type arg)
  {
    msg_.quaternion_wxyz = std::move(arg);
    return Init_HipnucImu_inclination(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_heading
{
public:
  explicit Init_HipnucImu_heading(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_quaternion_wxyz heading(::hipnuc_msgs::msg::HipnucImu::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_HipnucImu_quaternion_wxyz(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_yaw
{
public:
  explicit Init_HipnucImu_yaw(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_heading yaw(::hipnuc_msgs::msg::HipnucImu::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_HipnucImu_heading(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_pitch
{
public:
  explicit Init_HipnucImu_pitch(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_yaw pitch(::hipnuc_msgs::msg::HipnucImu::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_HipnucImu_yaw(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_roll
{
public:
  explicit Init_HipnucImu_roll(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_pitch roll(::hipnuc_msgs::msg::HipnucImu::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_HipnucImu_pitch(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_magnetic_field
{
public:
  explicit Init_HipnucImu_magnetic_field(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_roll magnetic_field(::hipnuc_msgs::msg::HipnucImu::_magnetic_field_type arg)
  {
    msg_.magnetic_field = std::move(arg);
    return Init_HipnucImu_roll(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_angular_velocity
{
public:
  explicit Init_HipnucImu_angular_velocity(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_magnetic_field angular_velocity(::hipnuc_msgs::msg::HipnucImu::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_HipnucImu_magnetic_field(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_acceleration
{
public:
  explicit Init_HipnucImu_acceleration(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_angular_velocity acceleration(::hipnuc_msgs::msg::HipnucImu::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_HipnucImu_angular_velocity(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_ins_status
{
public:
  explicit Init_HipnucImu_ins_status(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_acceleration ins_status(::hipnuc_msgs::msg::HipnucImu::_ins_status_type arg)
  {
    msg_.ins_status = std::move(arg);
    return Init_HipnucImu_acceleration(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_magnetometer_aiding
{
public:
  explicit Init_HipnucImu_magnetometer_aiding(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_ins_status magnetometer_aiding(::hipnuc_msgs::msg::HipnucImu::_magnetometer_aiding_type arg)
  {
    msg_.magnetometer_aiding = std::move(arg);
    return Init_HipnucImu_ins_status(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_device_static
{
public:
  explicit Init_HipnucImu_device_static(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_magnetometer_aiding device_static(::hipnuc_msgs::msg::HipnucImu::_device_static_type arg)
  {
    msg_.device_static = std::move(arg);
    return Init_HipnucImu_magnetometer_aiding(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_magnetic_disturbance
{
public:
  explicit Init_HipnucImu_magnetic_disturbance(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_device_static magnetic_disturbance(::hipnuc_msgs::msg::HipnucImu::_magnetic_disturbance_type arg)
  {
    msg_.magnetic_disturbance = std::move(arg);
    return Init_HipnucImu_device_static(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_attitude_converged
{
public:
  explicit Init_HipnucImu_attitude_converged(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_magnetic_disturbance attitude_converged(::hipnuc_msgs::msg::HipnucImu::_attitude_converged_type arg)
  {
    msg_.attitude_converged = std::move(arg);
    return Init_HipnucImu_magnetic_disturbance(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_gyro_bias_converged
{
public:
  explicit Init_HipnucImu_gyro_bias_converged(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_attitude_converged gyro_bias_converged(::hipnuc_msgs::msg::HipnucImu::_gyro_bias_converged_type arg)
  {
    msg_.gyro_bias_converged = std::move(arg);
    return Init_HipnucImu_attitude_converged(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_main_status
{
public:
  explicit Init_HipnucImu_main_status(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_gyro_bias_converged main_status(::hipnuc_msgs::msg::HipnucImu::_main_status_type arg)
  {
    msg_.main_status = std::move(arg);
    return Init_HipnucImu_gyro_bias_converged(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_node_id
{
public:
  explicit Init_HipnucImu_node_id(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_main_status node_id(::hipnuc_msgs::msg::HipnucImu::_node_id_type arg)
  {
    msg_.node_id = std::move(arg);
    return Init_HipnucImu_main_status(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_valid
{
public:
  explicit Init_HipnucImu_valid(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_node_id valid(::hipnuc_msgs::msg::HipnucImu::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_HipnucImu_node_id(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_source
{
public:
  explicit Init_HipnucImu_source(::hipnuc_msgs::msg::HipnucImu & msg)
  : msg_(msg)
  {}
  Init_HipnucImu_valid source(::hipnuc_msgs::msg::HipnucImu::_source_type arg)
  {
    msg_.source = std::move(arg);
    return Init_HipnucImu_valid(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

class Init_HipnucImu_header
{
public:
  Init_HipnucImu_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HipnucImu_source header(::hipnuc_msgs::msg::HipnucImu::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HipnucImu_source(msg_);
  }

private:
  ::hipnuc_msgs::msg::HipnucImu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hipnuc_msgs::msg::HipnucImu>()
{
  return hipnuc_msgs::msg::builder::Init_HipnucImu_header();
}

}  // namespace hipnuc_msgs

#endif  // HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__BUILDER_HPP_
