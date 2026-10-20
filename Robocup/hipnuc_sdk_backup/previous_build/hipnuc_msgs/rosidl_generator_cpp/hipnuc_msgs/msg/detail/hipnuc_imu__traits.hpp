// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice

#ifndef HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__TRAITS_HPP_
#define HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hipnuc_msgs/msg/detail/hipnuc_imu__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace hipnuc_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HipnucImu & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: source
  {
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
    out << ", ";
  }

  // member: valid
  {
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << ", ";
  }

  // member: node_id
  {
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << ", ";
  }

  // member: main_status
  {
    out << "main_status: ";
    rosidl_generator_traits::value_to_yaml(msg.main_status, out);
    out << ", ";
  }

  // member: gyro_bias_converged
  {
    out << "gyro_bias_converged: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_bias_converged, out);
    out << ", ";
  }

  // member: attitude_converged
  {
    out << "attitude_converged: ";
    rosidl_generator_traits::value_to_yaml(msg.attitude_converged, out);
    out << ", ";
  }

  // member: magnetic_disturbance
  {
    out << "magnetic_disturbance: ";
    rosidl_generator_traits::value_to_yaml(msg.magnetic_disturbance, out);
    out << ", ";
  }

  // member: device_static
  {
    out << "device_static: ";
    rosidl_generator_traits::value_to_yaml(msg.device_static, out);
    out << ", ";
  }

  // member: magnetometer_aiding
  {
    out << "magnetometer_aiding: ";
    rosidl_generator_traits::value_to_yaml(msg.magnetometer_aiding, out);
    out << ", ";
  }

  // member: ins_status
  {
    out << "ins_status: ";
    rosidl_generator_traits::value_to_yaml(msg.ins_status, out);
    out << ", ";
  }

  // member: acceleration
  {
    if (msg.acceleration.size() == 0) {
      out << "acceleration: []";
    } else {
      out << "acceleration: [";
      size_t pending_items = msg.acceleration.size();
      for (auto item : msg.acceleration) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: angular_velocity
  {
    if (msg.angular_velocity.size() == 0) {
      out << "angular_velocity: []";
    } else {
      out << "angular_velocity: [";
      size_t pending_items = msg.angular_velocity.size();
      for (auto item : msg.angular_velocity) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: magnetic_field
  {
    if (msg.magnetic_field.size() == 0) {
      out << "magnetic_field: []";
    } else {
      out << "magnetic_field: [";
      size_t pending_items = msg.magnetic_field.size();
      for (auto item : msg.magnetic_field) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << ", ";
  }

  // member: quaternion_wxyz
  {
    if (msg.quaternion_wxyz.size() == 0) {
      out << "quaternion_wxyz: []";
    } else {
      out << "quaternion_wxyz: [";
      size_t pending_items = msg.quaternion_wxyz.size();
      for (auto item : msg.quaternion_wxyz) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: inclination
  {
    if (msg.inclination.size() == 0) {
      out << "inclination: []";
    } else {
      out << "inclination: [";
      size_t pending_items = msg.inclination.size();
      for (auto item : msg.inclination) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: inclination_yaw
  {
    out << "inclination_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.inclination_yaw, out);
    out << ", ";
  }

  // member: device_time_us
  {
    out << "device_time_us: ";
    rosidl_generator_traits::value_to_yaml(msg.device_time_us, out);
    out << ", ";
  }

  // member: utc_valid
  {
    out << "utc_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_valid, out);
    out << ", ";
  }

  // member: utc_year
  {
    out << "utc_year: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_year, out);
    out << ", ";
  }

  // member: utc_month
  {
    out << "utc_month: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_month, out);
    out << ", ";
  }

  // member: utc_day
  {
    out << "utc_day: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_day, out);
    out << ", ";
  }

  // member: utc_hour
  {
    out << "utc_hour: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_hour, out);
    out << ", ";
  }

  // member: utc_minute
  {
    out << "utc_minute: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_minute, out);
    out << ", ";
  }

  // member: utc_second
  {
    out << "utc_second: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_second, out);
    out << ", ";
  }

  // member: utc_millisecond
  {
    out << "utc_millisecond: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_millisecond, out);
    out << ", ";
  }

  // member: gps_week
  {
    out << "gps_week: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_week, out);
    out << ", ";
  }

  // member: gps_tow_ms
  {
    out << "gps_tow_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_tow_ms, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: pressure
  {
    out << "pressure: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure, out);
    out << ", ";
  }

  // member: heave_surge_sway
  {
    if (msg.heave_surge_sway.size() == 0) {
      out << "heave_surge_sway: []";
    } else {
      out << "heave_surge_sway: [";
      size_t pending_items = msg.heave_surge_sway.size();
      for (auto item : msg.heave_surge_sway) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: heave_surge_sway_frequency
  {
    if (msg.heave_surge_sway_frequency.size() == 0) {
      out << "heave_surge_sway_frequency: []";
    } else {
      out << "heave_surge_sway_frequency: [";
      size_t pending_items = msg.heave_surge_sway_frequency.size();
      for (auto item : msg.heave_surge_sway_frequency) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: altitude_msl
  {
    out << "altitude_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_msl, out);
    out << ", ";
  }

  // member: gnss_longitude
  {
    out << "gnss_longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_longitude, out);
    out << ", ";
  }

  // member: gnss_latitude
  {
    out << "gnss_latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_latitude, out);
    out << ", ";
  }

  // member: gnss_altitude_msl
  {
    out << "gnss_altitude_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_altitude_msl, out);
    out << ", ";
  }

  // member: gnss_velocity_enu
  {
    if (msg.gnss_velocity_enu.size() == 0) {
      out << "gnss_velocity_enu: []";
    } else {
      out << "gnss_velocity_enu: [";
      size_t pending_items = msg.gnss_velocity_enu.size();
      for (auto item : msg.gnss_velocity_enu) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: geoid_separation
  {
    out << "geoid_separation: ";
    rosidl_generator_traits::value_to_yaml(msg.geoid_separation, out);
    out << ", ";
  }

  // member: velocity_enu
  {
    if (msg.velocity_enu.size() == 0) {
      out << "velocity_enu: []";
    } else {
      out << "velocity_enu: [";
      size_t pending_items = msg.velocity_enu.size();
      for (auto item : msg.velocity_enu) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: acceleration_enu
  {
    if (msg.acceleration_enu.size() == 0) {
      out << "acceleration_enu: []";
    } else {
      out << "acceleration_enu: [";
      size_t pending_items = msg.acceleration_enu.size();
      for (auto item : msg.acceleration_enu) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position_quality
  {
    out << "position_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.position_quality, out);
    out << ", ";
  }

  // member: position_satellites
  {
    out << "position_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.position_satellites, out);
    out << ", ";
  }

  // member: heading_quality
  {
    out << "heading_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_quality, out);
    out << ", ";
  }

  // member: heading_satellites
  {
    out << "heading_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_satellites, out);
    out << ", ";
  }

  // member: pdop
  {
    out << "pdop: ";
    rosidl_generator_traits::value_to_yaml(msg.pdop, out);
    out << ", ";
  }

  // member: hdop
  {
    out << "hdop: ";
    rosidl_generator_traits::value_to_yaml(msg.hdop, out);
    out << ", ";
  }

  // member: differential_age
  {
    out << "differential_age: ";
    rosidl_generator_traits::value_to_yaml(msg.differential_age, out);
    out << ", ";
  }

  // member: odometer_speed
  {
    out << "odometer_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.odometer_speed, out);
    out << ", ";
  }

  // member: speed_over_ground
  {
    out << "speed_over_ground: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_over_ground, out);
    out << ", ";
  }

  // member: course_over_ground
  {
    out << "course_over_ground: ";
    rosidl_generator_traits::value_to_yaml(msg.course_over_ground, out);
    out << ", ";
  }

  // member: nmea_status
  {
    out << "nmea_status: ";
    rosidl_generator_traits::value_to_yaml(msg.nmea_status, out);
    out << ", ";
  }

  // member: nmea_mode
  {
    out << "nmea_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.nmea_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HipnucImu & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: source
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
    out << "\n";
  }

  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << "\n";
  }

  // member: node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << "\n";
  }

  // member: main_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "main_status: ";
    rosidl_generator_traits::value_to_yaml(msg.main_status, out);
    out << "\n";
  }

  // member: gyro_bias_converged
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_bias_converged: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_bias_converged, out);
    out << "\n";
  }

  // member: attitude_converged
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "attitude_converged: ";
    rosidl_generator_traits::value_to_yaml(msg.attitude_converged, out);
    out << "\n";
  }

  // member: magnetic_disturbance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "magnetic_disturbance: ";
    rosidl_generator_traits::value_to_yaml(msg.magnetic_disturbance, out);
    out << "\n";
  }

  // member: device_static
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_static: ";
    rosidl_generator_traits::value_to_yaml(msg.device_static, out);
    out << "\n";
  }

  // member: magnetometer_aiding
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "magnetometer_aiding: ";
    rosidl_generator_traits::value_to_yaml(msg.magnetometer_aiding, out);
    out << "\n";
  }

  // member: ins_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ins_status: ";
    rosidl_generator_traits::value_to_yaml(msg.ins_status, out);
    out << "\n";
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.acceleration.size() == 0) {
      out << "acceleration: []\n";
    } else {
      out << "acceleration:\n";
      for (auto item : msg.acceleration) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angular_velocity.size() == 0) {
      out << "angular_velocity: []\n";
    } else {
      out << "angular_velocity:\n";
      for (auto item : msg.angular_velocity) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: magnetic_field
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.magnetic_field.size() == 0) {
      out << "magnetic_field: []\n";
    } else {
      out << "magnetic_field:\n";
      for (auto item : msg.magnetic_field) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }

  // member: quaternion_wxyz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.quaternion_wxyz.size() == 0) {
      out << "quaternion_wxyz: []\n";
    } else {
      out << "quaternion_wxyz:\n";
      for (auto item : msg.quaternion_wxyz) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: inclination
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.inclination.size() == 0) {
      out << "inclination: []\n";
    } else {
      out << "inclination:\n";
      for (auto item : msg.inclination) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: inclination_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inclination_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.inclination_yaw, out);
    out << "\n";
  }

  // member: device_time_us
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_time_us: ";
    rosidl_generator_traits::value_to_yaml(msg.device_time_us, out);
    out << "\n";
  }

  // member: utc_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_valid, out);
    out << "\n";
  }

  // member: utc_year
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_year: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_year, out);
    out << "\n";
  }

  // member: utc_month
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_month: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_month, out);
    out << "\n";
  }

  // member: utc_day
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_day: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_day, out);
    out << "\n";
  }

  // member: utc_hour
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_hour: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_hour, out);
    out << "\n";
  }

  // member: utc_minute
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_minute: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_minute, out);
    out << "\n";
  }

  // member: utc_second
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_second: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_second, out);
    out << "\n";
  }

  // member: utc_millisecond
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_millisecond: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_millisecond, out);
    out << "\n";
  }

  // member: gps_week
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_week: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_week, out);
    out << "\n";
  }

  // member: gps_tow_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_tow_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_tow_ms, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: pressure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pressure: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure, out);
    out << "\n";
  }

  // member: heave_surge_sway
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.heave_surge_sway.size() == 0) {
      out << "heave_surge_sway: []\n";
    } else {
      out << "heave_surge_sway:\n";
      for (auto item : msg.heave_surge_sway) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: heave_surge_sway_frequency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.heave_surge_sway_frequency.size() == 0) {
      out << "heave_surge_sway_frequency: []\n";
    } else {
      out << "heave_surge_sway_frequency:\n";
      for (auto item : msg.heave_surge_sway_frequency) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: altitude_msl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_msl, out);
    out << "\n";
  }

  // member: gnss_longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_longitude, out);
    out << "\n";
  }

  // member: gnss_latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_latitude, out);
    out << "\n";
  }

  // member: gnss_altitude_msl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_altitude_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_altitude_msl, out);
    out << "\n";
  }

  // member: gnss_velocity_enu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.gnss_velocity_enu.size() == 0) {
      out << "gnss_velocity_enu: []\n";
    } else {
      out << "gnss_velocity_enu:\n";
      for (auto item : msg.gnss_velocity_enu) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: geoid_separation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "geoid_separation: ";
    rosidl_generator_traits::value_to_yaml(msg.geoid_separation, out);
    out << "\n";
  }

  // member: velocity_enu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocity_enu.size() == 0) {
      out << "velocity_enu: []\n";
    } else {
      out << "velocity_enu:\n";
      for (auto item : msg.velocity_enu) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: acceleration_enu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.acceleration_enu.size() == 0) {
      out << "acceleration_enu: []\n";
    } else {
      out << "acceleration_enu:\n";
      for (auto item : msg.acceleration_enu) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position_quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.position_quality, out);
    out << "\n";
  }

  // member: position_satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.position_satellites, out);
    out << "\n";
  }

  // member: heading_quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_quality, out);
    out << "\n";
  }

  // member: heading_satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_satellites, out);
    out << "\n";
  }

  // member: pdop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pdop: ";
    rosidl_generator_traits::value_to_yaml(msg.pdop, out);
    out << "\n";
  }

  // member: hdop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hdop: ";
    rosidl_generator_traits::value_to_yaml(msg.hdop, out);
    out << "\n";
  }

  // member: differential_age
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "differential_age: ";
    rosidl_generator_traits::value_to_yaml(msg.differential_age, out);
    out << "\n";
  }

  // member: odometer_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "odometer_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.odometer_speed, out);
    out << "\n";
  }

  // member: speed_over_ground
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_over_ground: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_over_ground, out);
    out << "\n";
  }

  // member: course_over_ground
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "course_over_ground: ";
    rosidl_generator_traits::value_to_yaml(msg.course_over_ground, out);
    out << "\n";
  }

  // member: nmea_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nmea_status: ";
    rosidl_generator_traits::value_to_yaml(msg.nmea_status, out);
    out << "\n";
  }

  // member: nmea_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nmea_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.nmea_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HipnucImu & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hipnuc_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hipnuc_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hipnuc_msgs::msg::HipnucImu & msg,
  std::ostream & out, size_t indentation = 0)
{
  hipnuc_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hipnuc_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hipnuc_msgs::msg::HipnucImu & msg)
{
  return hipnuc_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hipnuc_msgs::msg::HipnucImu>()
{
  return "hipnuc_msgs::msg::HipnucImu";
}

template<>
inline const char * name<hipnuc_msgs::msg::HipnucImu>()
{
  return "hipnuc_msgs/msg/HipnucImu";
}

template<>
struct has_fixed_size<hipnuc_msgs::msg::HipnucImu>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hipnuc_msgs::msg::HipnucImu>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hipnuc_msgs::msg::HipnucImu>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__TRAITS_HPP_
