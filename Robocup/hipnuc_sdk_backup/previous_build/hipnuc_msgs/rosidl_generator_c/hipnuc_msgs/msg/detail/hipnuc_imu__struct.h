// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice

#ifndef HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__STRUCT_H_
#define HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'VALID_STATUS'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_STATUS = 1ull
};

/// Constant 'VALID_INS_STATUS'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_INS_STATUS = 2ull
};

/// Constant 'VALID_ACC'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_ACC = 4ull
};

/// Constant 'VALID_GYR'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_GYR = 8ull
};

/// Constant 'VALID_MAG'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_MAG = 16ull
};

/// Constant 'VALID_ROLL_PITCH'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_ROLL_PITCH = 32ull
};

/// Constant 'VALID_HEADING'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_HEADING = 64ull
};

/// Constant 'VALID_QUAT'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_QUAT = 128ull
};

/// Constant 'VALID_DEVICE_TIME'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_DEVICE_TIME = 256ull
};

/// Constant 'VALID_UTC'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_UTC = 512ull
};

/// Constant 'VALID_GPS_TIME'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_GPS_TIME = 1024ull
};

/// Constant 'VALID_PRESSURE'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_PRESSURE = 2048ull
};

/// Constant 'VALID_TEMPERATURE'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_TEMPERATURE = 4096ull
};

/// Constant 'VALID_INCLINATION'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_INCLINATION = 8192ull
};

/// Constant 'VALID_HEAVE'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_HEAVE = 16384ull
};

/// Constant 'VALID_POSITION'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_POSITION = 32768ull
};

/// Constant 'VALID_VELOCITY_ENU'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_VELOCITY_ENU = 65536ull
};

/// Constant 'VALID_ACC_ENU'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_ACC_ENU = 131072ull
};

/// Constant 'VALID_POSITION_QUALITY'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_POSITION_QUALITY = 262144ull
};

/// Constant 'VALID_PDOP'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_PDOP = 524288ull
};

/// Constant 'VALID_DIFF_AGE'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_DIFF_AGE = 1048576ull
};

/// Constant 'VALID_UNDULATION'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_UNDULATION = 2097152ull
};

/// Constant 'VALID_ODOMETER'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_ODOMETER = 4194304ull
};

/// Constant 'VALID_GNSS_POSITION'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_GNSS_POSITION = 8388608ull
};

/// Constant 'VALID_GNSS_VELOCITY'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_GNSS_VELOCITY = 16777216ull
};

/// Constant 'VALID_SOG'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_SOG = 33554432ull
};

/// Constant 'VALID_NODE_ID'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_NODE_ID = 67108864ull
};

/// Constant 'VALID_YAW'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_YAW = 134217728ull
};

/// Constant 'VALID_ALTITUDE'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_ALTITUDE = 268435456ull
};

/// Constant 'VALID_HEADING_QUALITY'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_HEADING_QUALITY = 536870912ull
};

/// Constant 'VALID_POSITION_SATELLITES'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_POSITION_SATELLITES = 1073741824ull
};

/// Constant 'VALID_HEADING_SATELLITES'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_HEADING_SATELLITES = 2147483648ull
};

/// Constant 'VALID_HDOP'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_HDOP = 4294967296ull
};

/// Constant 'VALID_HEAVE_FREQUENCY'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_HEAVE_FREQUENCY = 8589934592ull
};

/// Constant 'VALID_GNSS_ALTITUDE'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_GNSS_ALTITUDE = 17179869184ull
};

/// Constant 'VALID_COG'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_COG = 34359738368ull
};

/// Constant 'VALID_NMEA_STATUS'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_NMEA_STATUS = 68719476736ull
};

/// Constant 'VALID_NMEA_MODE'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_NMEA_MODE = 137438953472ull
};

/// Constant 'VALID_UTC_TIME_OF_DAY'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_UTC_TIME_OF_DAY = 274877906944ull
};

/// Constant 'VALID_INCLINATION_YAW'.
enum
{
  hipnuc_msgs__msg__HipnucImu__VALID_INCLINATION_YAW = 549755813888ull
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/HipnucImu in the package hipnuc_msgs.
/**
  * One decoded HiPNUC measurement in SI units. `valid` is the bit mask from
  * hipnuc_sample.h (HIPNUC_VALID_*): read a field only when its bit is set.
  * Bits indicate field presence, not solution convergence or a valid GNSS fix.
  * Fields without a set bit are placeholders. INS and GNSS origins may differ.
 */
typedef struct hipnuc_msgs__msg__HipnucImu
{
  /// host ROS time after decoding, before publishing; body-axis frame_id
  std_msgs__msg__Header header;
  /// 1 HI91, 2 HI81, 3 HI83, 4 GGA, 5 RMC, 6 J1939, 7 CANFD83
  uint8_t source;
  uint64_t valid;
  /// CAN source address or HI83 node id
  uint8_t node_id;
  /// raw status bits (a set WB_CONV/ATT_CONV bit means NOT converged)
  uint16_t main_status;
  bool gyro_bias_converged;
  bool attitude_converged;
  bool magnetic_disturbance;
  bool device_static;
  bool magnetometer_aiding;
  /// 0 invalid, 1 aligning, 3 navigating, 6 dead reckoning
  uint8_t ins_status;
  /// m/s^2, body axes, specific force
  float acceleration[3];
  /// rad/s, body axes
  float angular_velocity[3];
  /// T
  float magnetic_field[3];
  /// rad, device Euler convention
  float roll;
  float pitch;
  float yaw;
  /// rad, clockwise from north (INS / J1939)
  float heading;
  /// body to navigation
  float quaternion_wxyz[4];
  /// rad
  float inclination[2];
  /// rad, HI83 inclinometer yaw, VALID_INCLINATION_YAW
  float inclination_yaw;
  /// HI91: 32-bit ms count, wraps (UTC time of day once synchronized)
  uint64_t device_time_us;
  /// VALID_UTC, date and time; VALID_UTC_TIME_OF_DAY alone leaves the date zero
  bool utc_valid;
  uint16_t utc_year;
  uint8_t utc_month;
  uint8_t utc_day;
  uint8_t utc_hour;
  uint8_t utc_minute;
  uint8_t utc_second;
  uint16_t utc_millisecond;
  uint16_t gps_week;
  uint32_t gps_tow_ms;
  /// degC
  float temperature;
  /// Pa; raw product field, validity/freshness not guaranteed
  float pressure;
  /// m, VALID_HEAVE
  float heave_surge_sway[3];
  /// Hz, VALID_HEAVE_FREQUENCY
  float heave_surge_sway_frequency[3];
  /// INS origin, deg WGS84, VALID_POSITION
  double longitude;
  double latitude;
  /// INS origin, m MSL, VALID_ALTITUDE
  double altitude_msl;
  /// GNSS antenna, deg WGS84, VALID_GNSS_POSITION
  double gnss_longitude;
  double gnss_latitude;
  /// GNSS antenna, m MSL, VALID_GNSS_ALTITUDE
  double gnss_altitude_msl;
  /// m/s, VALID_GNSS_VELOCITY
  float gnss_velocity_enu[3];
  /// GNSS geoid separation, m
  float geoid_separation;
  /// m/s
  float velocity_enu[3];
  /// m/s^2
  float acceleration_enu[3];
  /// GGA quality: 0 none, 1 GNSS, 2 DGNSS, 4 RTK fixed, 5 RTK float
  uint8_t position_quality;
  uint8_t position_satellites;
  /// 4 = fixed; only then is a dual-antenna heading valid
  uint8_t heading_quality;
  uint8_t heading_satellites;
  float pdop;
  float hdop;
  /// s
  float differential_age;
  /// m/s
  float odometer_speed;
  /// m/s, VALID_SOG
  float speed_over_ground;
  /// rad clockwise from north, VALID_COG
  float course_over_ground;
  /// ASCII A/V, VALID_NMEA_STATUS
  uint8_t nmea_status;
  /// raw ASCII RMC mode, VALID_NMEA_MODE
  uint8_t nmea_mode;
} hipnuc_msgs__msg__HipnucImu;

// Struct for a sequence of hipnuc_msgs__msg__HipnucImu.
typedef struct hipnuc_msgs__msg__HipnucImu__Sequence
{
  hipnuc_msgs__msg__HipnucImu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hipnuc_msgs__msg__HipnucImu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__STRUCT_H_
