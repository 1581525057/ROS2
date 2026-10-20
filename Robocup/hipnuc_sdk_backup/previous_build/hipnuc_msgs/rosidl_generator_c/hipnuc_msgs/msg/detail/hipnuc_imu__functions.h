// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice

#ifndef HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__FUNCTIONS_H_
#define HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hipnuc_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "hipnuc_msgs/msg/detail/hipnuc_imu__struct.h"

/// Initialize msg/HipnucImu message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hipnuc_msgs__msg__HipnucImu
 * )) before or use
 * hipnuc_msgs__msg__HipnucImu__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
bool
hipnuc_msgs__msg__HipnucImu__init(hipnuc_msgs__msg__HipnucImu * msg);

/// Finalize msg/HipnucImu message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
void
hipnuc_msgs__msg__HipnucImu__fini(hipnuc_msgs__msg__HipnucImu * msg);

/// Create msg/HipnucImu message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hipnuc_msgs__msg__HipnucImu__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
hipnuc_msgs__msg__HipnucImu *
hipnuc_msgs__msg__HipnucImu__create();

/// Destroy msg/HipnucImu message.
/**
 * It calls
 * hipnuc_msgs__msg__HipnucImu__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
void
hipnuc_msgs__msg__HipnucImu__destroy(hipnuc_msgs__msg__HipnucImu * msg);

/// Check for msg/HipnucImu message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
bool
hipnuc_msgs__msg__HipnucImu__are_equal(const hipnuc_msgs__msg__HipnucImu * lhs, const hipnuc_msgs__msg__HipnucImu * rhs);

/// Copy a msg/HipnucImu message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
bool
hipnuc_msgs__msg__HipnucImu__copy(
  const hipnuc_msgs__msg__HipnucImu * input,
  hipnuc_msgs__msg__HipnucImu * output);

/// Initialize array of msg/HipnucImu messages.
/**
 * It allocates the memory for the number of elements and calls
 * hipnuc_msgs__msg__HipnucImu__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
bool
hipnuc_msgs__msg__HipnucImu__Sequence__init(hipnuc_msgs__msg__HipnucImu__Sequence * array, size_t size);

/// Finalize array of msg/HipnucImu messages.
/**
 * It calls
 * hipnuc_msgs__msg__HipnucImu__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
void
hipnuc_msgs__msg__HipnucImu__Sequence__fini(hipnuc_msgs__msg__HipnucImu__Sequence * array);

/// Create array of msg/HipnucImu messages.
/**
 * It allocates the memory for the array and calls
 * hipnuc_msgs__msg__HipnucImu__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
hipnuc_msgs__msg__HipnucImu__Sequence *
hipnuc_msgs__msg__HipnucImu__Sequence__create(size_t size);

/// Destroy array of msg/HipnucImu messages.
/**
 * It calls
 * hipnuc_msgs__msg__HipnucImu__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
void
hipnuc_msgs__msg__HipnucImu__Sequence__destroy(hipnuc_msgs__msg__HipnucImu__Sequence * array);

/// Check for msg/HipnucImu message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
bool
hipnuc_msgs__msg__HipnucImu__Sequence__are_equal(const hipnuc_msgs__msg__HipnucImu__Sequence * lhs, const hipnuc_msgs__msg__HipnucImu__Sequence * rhs);

/// Copy an array of msg/HipnucImu messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hipnuc_msgs
bool
hipnuc_msgs__msg__HipnucImu__Sequence__copy(
  const hipnuc_msgs__msg__HipnucImu__Sequence * input,
  hipnuc_msgs__msg__HipnucImu__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HIPNUC_MSGS__MSG__DETAIL__HIPNUC_IMU__FUNCTIONS_H_
