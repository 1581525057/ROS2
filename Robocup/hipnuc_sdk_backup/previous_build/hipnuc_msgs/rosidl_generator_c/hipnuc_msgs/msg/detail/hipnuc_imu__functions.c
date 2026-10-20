// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice
#include "hipnuc_msgs/msg/detail/hipnuc_imu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
hipnuc_msgs__msg__HipnucImu__init(hipnuc_msgs__msg__HipnucImu * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    hipnuc_msgs__msg__HipnucImu__fini(msg);
    return false;
  }
  // source
  // valid
  // node_id
  // main_status
  // gyro_bias_converged
  // attitude_converged
  // magnetic_disturbance
  // device_static
  // magnetometer_aiding
  // ins_status
  // acceleration
  // angular_velocity
  // magnetic_field
  // roll
  // pitch
  // yaw
  // heading
  // quaternion_wxyz
  // inclination
  // inclination_yaw
  // device_time_us
  // utc_valid
  // utc_year
  // utc_month
  // utc_day
  // utc_hour
  // utc_minute
  // utc_second
  // utc_millisecond
  // gps_week
  // gps_tow_ms
  // temperature
  // pressure
  // heave_surge_sway
  // heave_surge_sway_frequency
  // longitude
  // latitude
  // altitude_msl
  // gnss_longitude
  // gnss_latitude
  // gnss_altitude_msl
  // gnss_velocity_enu
  // geoid_separation
  // velocity_enu
  // acceleration_enu
  // position_quality
  // position_satellites
  // heading_quality
  // heading_satellites
  // pdop
  // hdop
  // differential_age
  // odometer_speed
  // speed_over_ground
  // course_over_ground
  // nmea_status
  // nmea_mode
  return true;
}

void
hipnuc_msgs__msg__HipnucImu__fini(hipnuc_msgs__msg__HipnucImu * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // source
  // valid
  // node_id
  // main_status
  // gyro_bias_converged
  // attitude_converged
  // magnetic_disturbance
  // device_static
  // magnetometer_aiding
  // ins_status
  // acceleration
  // angular_velocity
  // magnetic_field
  // roll
  // pitch
  // yaw
  // heading
  // quaternion_wxyz
  // inclination
  // inclination_yaw
  // device_time_us
  // utc_valid
  // utc_year
  // utc_month
  // utc_day
  // utc_hour
  // utc_minute
  // utc_second
  // utc_millisecond
  // gps_week
  // gps_tow_ms
  // temperature
  // pressure
  // heave_surge_sway
  // heave_surge_sway_frequency
  // longitude
  // latitude
  // altitude_msl
  // gnss_longitude
  // gnss_latitude
  // gnss_altitude_msl
  // gnss_velocity_enu
  // geoid_separation
  // velocity_enu
  // acceleration_enu
  // position_quality
  // position_satellites
  // heading_quality
  // heading_satellites
  // pdop
  // hdop
  // differential_age
  // odometer_speed
  // speed_over_ground
  // course_over_ground
  // nmea_status
  // nmea_mode
}

bool
hipnuc_msgs__msg__HipnucImu__are_equal(const hipnuc_msgs__msg__HipnucImu * lhs, const hipnuc_msgs__msg__HipnucImu * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // source
  if (lhs->source != rhs->source) {
    return false;
  }
  // valid
  if (lhs->valid != rhs->valid) {
    return false;
  }
  // node_id
  if (lhs->node_id != rhs->node_id) {
    return false;
  }
  // main_status
  if (lhs->main_status != rhs->main_status) {
    return false;
  }
  // gyro_bias_converged
  if (lhs->gyro_bias_converged != rhs->gyro_bias_converged) {
    return false;
  }
  // attitude_converged
  if (lhs->attitude_converged != rhs->attitude_converged) {
    return false;
  }
  // magnetic_disturbance
  if (lhs->magnetic_disturbance != rhs->magnetic_disturbance) {
    return false;
  }
  // device_static
  if (lhs->device_static != rhs->device_static) {
    return false;
  }
  // magnetometer_aiding
  if (lhs->magnetometer_aiding != rhs->magnetometer_aiding) {
    return false;
  }
  // ins_status
  if (lhs->ins_status != rhs->ins_status) {
    return false;
  }
  // acceleration
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->acceleration[i] != rhs->acceleration[i]) {
      return false;
    }
  }
  // angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->angular_velocity[i] != rhs->angular_velocity[i]) {
      return false;
    }
  }
  // magnetic_field
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->magnetic_field[i] != rhs->magnetic_field[i]) {
      return false;
    }
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  // quaternion_wxyz
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->quaternion_wxyz[i] != rhs->quaternion_wxyz[i]) {
      return false;
    }
  }
  // inclination
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->inclination[i] != rhs->inclination[i]) {
      return false;
    }
  }
  // inclination_yaw
  if (lhs->inclination_yaw != rhs->inclination_yaw) {
    return false;
  }
  // device_time_us
  if (lhs->device_time_us != rhs->device_time_us) {
    return false;
  }
  // utc_valid
  if (lhs->utc_valid != rhs->utc_valid) {
    return false;
  }
  // utc_year
  if (lhs->utc_year != rhs->utc_year) {
    return false;
  }
  // utc_month
  if (lhs->utc_month != rhs->utc_month) {
    return false;
  }
  // utc_day
  if (lhs->utc_day != rhs->utc_day) {
    return false;
  }
  // utc_hour
  if (lhs->utc_hour != rhs->utc_hour) {
    return false;
  }
  // utc_minute
  if (lhs->utc_minute != rhs->utc_minute) {
    return false;
  }
  // utc_second
  if (lhs->utc_second != rhs->utc_second) {
    return false;
  }
  // utc_millisecond
  if (lhs->utc_millisecond != rhs->utc_millisecond) {
    return false;
  }
  // gps_week
  if (lhs->gps_week != rhs->gps_week) {
    return false;
  }
  // gps_tow_ms
  if (lhs->gps_tow_ms != rhs->gps_tow_ms) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // pressure
  if (lhs->pressure != rhs->pressure) {
    return false;
  }
  // heave_surge_sway
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->heave_surge_sway[i] != rhs->heave_surge_sway[i]) {
      return false;
    }
  }
  // heave_surge_sway_frequency
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->heave_surge_sway_frequency[i] != rhs->heave_surge_sway_frequency[i]) {
      return false;
    }
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // altitude_msl
  if (lhs->altitude_msl != rhs->altitude_msl) {
    return false;
  }
  // gnss_longitude
  if (lhs->gnss_longitude != rhs->gnss_longitude) {
    return false;
  }
  // gnss_latitude
  if (lhs->gnss_latitude != rhs->gnss_latitude) {
    return false;
  }
  // gnss_altitude_msl
  if (lhs->gnss_altitude_msl != rhs->gnss_altitude_msl) {
    return false;
  }
  // gnss_velocity_enu
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->gnss_velocity_enu[i] != rhs->gnss_velocity_enu[i]) {
      return false;
    }
  }
  // geoid_separation
  if (lhs->geoid_separation != rhs->geoid_separation) {
    return false;
  }
  // velocity_enu
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->velocity_enu[i] != rhs->velocity_enu[i]) {
      return false;
    }
  }
  // acceleration_enu
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->acceleration_enu[i] != rhs->acceleration_enu[i]) {
      return false;
    }
  }
  // position_quality
  if (lhs->position_quality != rhs->position_quality) {
    return false;
  }
  // position_satellites
  if (lhs->position_satellites != rhs->position_satellites) {
    return false;
  }
  // heading_quality
  if (lhs->heading_quality != rhs->heading_quality) {
    return false;
  }
  // heading_satellites
  if (lhs->heading_satellites != rhs->heading_satellites) {
    return false;
  }
  // pdop
  if (lhs->pdop != rhs->pdop) {
    return false;
  }
  // hdop
  if (lhs->hdop != rhs->hdop) {
    return false;
  }
  // differential_age
  if (lhs->differential_age != rhs->differential_age) {
    return false;
  }
  // odometer_speed
  if (lhs->odometer_speed != rhs->odometer_speed) {
    return false;
  }
  // speed_over_ground
  if (lhs->speed_over_ground != rhs->speed_over_ground) {
    return false;
  }
  // course_over_ground
  if (lhs->course_over_ground != rhs->course_over_ground) {
    return false;
  }
  // nmea_status
  if (lhs->nmea_status != rhs->nmea_status) {
    return false;
  }
  // nmea_mode
  if (lhs->nmea_mode != rhs->nmea_mode) {
    return false;
  }
  return true;
}

bool
hipnuc_msgs__msg__HipnucImu__copy(
  const hipnuc_msgs__msg__HipnucImu * input,
  hipnuc_msgs__msg__HipnucImu * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // source
  output->source = input->source;
  // valid
  output->valid = input->valid;
  // node_id
  output->node_id = input->node_id;
  // main_status
  output->main_status = input->main_status;
  // gyro_bias_converged
  output->gyro_bias_converged = input->gyro_bias_converged;
  // attitude_converged
  output->attitude_converged = input->attitude_converged;
  // magnetic_disturbance
  output->magnetic_disturbance = input->magnetic_disturbance;
  // device_static
  output->device_static = input->device_static;
  // magnetometer_aiding
  output->magnetometer_aiding = input->magnetometer_aiding;
  // ins_status
  output->ins_status = input->ins_status;
  // acceleration
  for (size_t i = 0; i < 3; ++i) {
    output->acceleration[i] = input->acceleration[i];
  }
  // angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    output->angular_velocity[i] = input->angular_velocity[i];
  }
  // magnetic_field
  for (size_t i = 0; i < 3; ++i) {
    output->magnetic_field[i] = input->magnetic_field[i];
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // heading
  output->heading = input->heading;
  // quaternion_wxyz
  for (size_t i = 0; i < 4; ++i) {
    output->quaternion_wxyz[i] = input->quaternion_wxyz[i];
  }
  // inclination
  for (size_t i = 0; i < 2; ++i) {
    output->inclination[i] = input->inclination[i];
  }
  // inclination_yaw
  output->inclination_yaw = input->inclination_yaw;
  // device_time_us
  output->device_time_us = input->device_time_us;
  // utc_valid
  output->utc_valid = input->utc_valid;
  // utc_year
  output->utc_year = input->utc_year;
  // utc_month
  output->utc_month = input->utc_month;
  // utc_day
  output->utc_day = input->utc_day;
  // utc_hour
  output->utc_hour = input->utc_hour;
  // utc_minute
  output->utc_minute = input->utc_minute;
  // utc_second
  output->utc_second = input->utc_second;
  // utc_millisecond
  output->utc_millisecond = input->utc_millisecond;
  // gps_week
  output->gps_week = input->gps_week;
  // gps_tow_ms
  output->gps_tow_ms = input->gps_tow_ms;
  // temperature
  output->temperature = input->temperature;
  // pressure
  output->pressure = input->pressure;
  // heave_surge_sway
  for (size_t i = 0; i < 3; ++i) {
    output->heave_surge_sway[i] = input->heave_surge_sway[i];
  }
  // heave_surge_sway_frequency
  for (size_t i = 0; i < 3; ++i) {
    output->heave_surge_sway_frequency[i] = input->heave_surge_sway_frequency[i];
  }
  // longitude
  output->longitude = input->longitude;
  // latitude
  output->latitude = input->latitude;
  // altitude_msl
  output->altitude_msl = input->altitude_msl;
  // gnss_longitude
  output->gnss_longitude = input->gnss_longitude;
  // gnss_latitude
  output->gnss_latitude = input->gnss_latitude;
  // gnss_altitude_msl
  output->gnss_altitude_msl = input->gnss_altitude_msl;
  // gnss_velocity_enu
  for (size_t i = 0; i < 3; ++i) {
    output->gnss_velocity_enu[i] = input->gnss_velocity_enu[i];
  }
  // geoid_separation
  output->geoid_separation = input->geoid_separation;
  // velocity_enu
  for (size_t i = 0; i < 3; ++i) {
    output->velocity_enu[i] = input->velocity_enu[i];
  }
  // acceleration_enu
  for (size_t i = 0; i < 3; ++i) {
    output->acceleration_enu[i] = input->acceleration_enu[i];
  }
  // position_quality
  output->position_quality = input->position_quality;
  // position_satellites
  output->position_satellites = input->position_satellites;
  // heading_quality
  output->heading_quality = input->heading_quality;
  // heading_satellites
  output->heading_satellites = input->heading_satellites;
  // pdop
  output->pdop = input->pdop;
  // hdop
  output->hdop = input->hdop;
  // differential_age
  output->differential_age = input->differential_age;
  // odometer_speed
  output->odometer_speed = input->odometer_speed;
  // speed_over_ground
  output->speed_over_ground = input->speed_over_ground;
  // course_over_ground
  output->course_over_ground = input->course_over_ground;
  // nmea_status
  output->nmea_status = input->nmea_status;
  // nmea_mode
  output->nmea_mode = input->nmea_mode;
  return true;
}

hipnuc_msgs__msg__HipnucImu *
hipnuc_msgs__msg__HipnucImu__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hipnuc_msgs__msg__HipnucImu * msg = (hipnuc_msgs__msg__HipnucImu *)allocator.allocate(sizeof(hipnuc_msgs__msg__HipnucImu), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hipnuc_msgs__msg__HipnucImu));
  bool success = hipnuc_msgs__msg__HipnucImu__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hipnuc_msgs__msg__HipnucImu__destroy(hipnuc_msgs__msg__HipnucImu * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hipnuc_msgs__msg__HipnucImu__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hipnuc_msgs__msg__HipnucImu__Sequence__init(hipnuc_msgs__msg__HipnucImu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hipnuc_msgs__msg__HipnucImu * data = NULL;

  if (size) {
    data = (hipnuc_msgs__msg__HipnucImu *)allocator.zero_allocate(size, sizeof(hipnuc_msgs__msg__HipnucImu), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hipnuc_msgs__msg__HipnucImu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hipnuc_msgs__msg__HipnucImu__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hipnuc_msgs__msg__HipnucImu__Sequence__fini(hipnuc_msgs__msg__HipnucImu__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hipnuc_msgs__msg__HipnucImu__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hipnuc_msgs__msg__HipnucImu__Sequence *
hipnuc_msgs__msg__HipnucImu__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hipnuc_msgs__msg__HipnucImu__Sequence * array = (hipnuc_msgs__msg__HipnucImu__Sequence *)allocator.allocate(sizeof(hipnuc_msgs__msg__HipnucImu__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hipnuc_msgs__msg__HipnucImu__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hipnuc_msgs__msg__HipnucImu__Sequence__destroy(hipnuc_msgs__msg__HipnucImu__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hipnuc_msgs__msg__HipnucImu__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hipnuc_msgs__msg__HipnucImu__Sequence__are_equal(const hipnuc_msgs__msg__HipnucImu__Sequence * lhs, const hipnuc_msgs__msg__HipnucImu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hipnuc_msgs__msg__HipnucImu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hipnuc_msgs__msg__HipnucImu__Sequence__copy(
  const hipnuc_msgs__msg__HipnucImu__Sequence * input,
  hipnuc_msgs__msg__HipnucImu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hipnuc_msgs__msg__HipnucImu);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hipnuc_msgs__msg__HipnucImu * data =
      (hipnuc_msgs__msg__HipnucImu *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hipnuc_msgs__msg__HipnucImu__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hipnuc_msgs__msg__HipnucImu__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hipnuc_msgs__msg__HipnucImu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
