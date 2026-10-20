// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hipnuc_msgs/msg/detail/hipnuc_imu__rosidl_typesupport_introspection_c.h"
#include "hipnuc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hipnuc_msgs/msg/detail/hipnuc_imu__functions.h"
#include "hipnuc_msgs/msg/detail/hipnuc_imu__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hipnuc_msgs__msg__HipnucImu__init(message_memory);
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_fini_function(void * message_memory)
{
  hipnuc_msgs__msg__HipnucImu__fini(message_memory);
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__acceleration(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__acceleration(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__acceleration(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__acceleration(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__acceleration(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__acceleration(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__acceleration(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__angular_velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__angular_velocity(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__angular_velocity(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__angular_velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__angular_velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__angular_velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__angular_velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__magnetic_field(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__magnetic_field(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__magnetic_field(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__magnetic_field(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__magnetic_field(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__magnetic_field(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__magnetic_field(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__quaternion_wxyz(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__quaternion_wxyz(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__quaternion_wxyz(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__quaternion_wxyz(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__quaternion_wxyz(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__quaternion_wxyz(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__quaternion_wxyz(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__inclination(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__inclination(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__inclination(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__inclination(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__inclination(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__inclination(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__inclination(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__heave_surge_sway(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__heave_surge_sway(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__heave_surge_sway(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__heave_surge_sway(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__heave_surge_sway(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__heave_surge_sway(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__heave_surge_sway(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__heave_surge_sway_frequency(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__heave_surge_sway_frequency(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__heave_surge_sway_frequency(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__heave_surge_sway_frequency(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__heave_surge_sway_frequency(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__heave_surge_sway_frequency(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__heave_surge_sway_frequency(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__gnss_velocity_enu(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__gnss_velocity_enu(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__gnss_velocity_enu(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__gnss_velocity_enu(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__gnss_velocity_enu(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__gnss_velocity_enu(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__gnss_velocity_enu(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__velocity_enu(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__velocity_enu(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__velocity_enu(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__velocity_enu(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__velocity_enu(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__velocity_enu(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__velocity_enu(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__acceleration_enu(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__acceleration_enu(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__acceleration_enu(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__acceleration_enu(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__acceleration_enu(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__acceleration_enu(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__acceleration_enu(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_member_array[58] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, source),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, node_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "main_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, main_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gyro_bias_converged",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, gyro_bias_converged),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "attitude_converged",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, attitude_converged),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "magnetic_disturbance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, magnetic_disturbance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_static",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, device_static),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "magnetometer_aiding",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, magnetometer_aiding),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ins_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, ins_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, acceleration),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__acceleration,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__acceleration,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__acceleration,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__acceleration,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__acceleration,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__angular_velocity,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__angular_velocity,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__angular_velocity,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__angular_velocity,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__angular_velocity,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "magnetic_field",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, magnetic_field),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__magnetic_field,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__magnetic_field,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__magnetic_field,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__magnetic_field,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__magnetic_field,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, heading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quaternion_wxyz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, quaternion_wxyz),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__quaternion_wxyz,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__quaternion_wxyz,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__quaternion_wxyz,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__quaternion_wxyz,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__quaternion_wxyz,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inclination",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, inclination),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__inclination,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__inclination,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__inclination,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__inclination,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__inclination,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inclination_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, inclination_yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_time_us",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, device_time_us),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_year",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_year),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_month",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_month),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_day",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_day),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_hour",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_hour),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_minute",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_minute),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_second",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_second),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "utc_millisecond",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, utc_millisecond),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gps_week",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, gps_week),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gps_tow_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, gps_tow_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pressure",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, pressure),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heave_surge_sway",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, heave_surge_sway),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__heave_surge_sway,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__heave_surge_sway,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__heave_surge_sway,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__heave_surge_sway,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__heave_surge_sway,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heave_surge_sway_frequency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, heave_surge_sway_frequency),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__heave_surge_sway_frequency,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__heave_surge_sway_frequency,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__heave_surge_sway_frequency,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__heave_surge_sway_frequency,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__heave_surge_sway_frequency,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "longitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, longitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "latitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, latitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "altitude_msl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, altitude_msl),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gnss_longitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, gnss_longitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gnss_latitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, gnss_latitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gnss_altitude_msl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, gnss_altitude_msl),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gnss_velocity_enu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, gnss_velocity_enu),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__gnss_velocity_enu,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__gnss_velocity_enu,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__gnss_velocity_enu,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__gnss_velocity_enu,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__gnss_velocity_enu,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "geoid_separation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, geoid_separation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity_enu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, velocity_enu),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__velocity_enu,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__velocity_enu,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__velocity_enu,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__velocity_enu,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__velocity_enu,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration_enu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, acceleration_enu),  // bytes offset in struct
    NULL,  // default value
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__size_function__HipnucImu__acceleration_enu,  // size() function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_const_function__HipnucImu__acceleration_enu,  // get_const(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__get_function__HipnucImu__acceleration_enu,  // get(index) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__fetch_function__HipnucImu__acceleration_enu,  // fetch(index, &value) function pointer
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__assign_function__HipnucImu__acceleration_enu,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_quality",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, position_quality),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_satellites",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, position_satellites),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heading_quality",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, heading_quality),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heading_satellites",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, heading_satellites),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pdop",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, pdop),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hdop",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, hdop),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "differential_age",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, differential_age),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "odometer_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, odometer_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_over_ground",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, speed_over_ground),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "course_over_ground",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, course_over_ground),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "nmea_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, nmea_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "nmea_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hipnuc_msgs__msg__HipnucImu, nmea_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_members = {
  "hipnuc_msgs__msg",  // message namespace
  "HipnucImu",  // message name
  58,  // number of fields
  sizeof(hipnuc_msgs__msg__HipnucImu),
  hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_member_array,  // message members
  hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_init_function,  // function to initialize message memory (memory has to be allocated)
  hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_type_support_handle = {
  0,
  &hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hipnuc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hipnuc_msgs, msg, HipnucImu)() {
  hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_type_support_handle.typesupport_identifier) {
    hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hipnuc_msgs__msg__HipnucImu__rosidl_typesupport_introspection_c__HipnucImu_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
