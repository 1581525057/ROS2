// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hipnuc_msgs:msg/HipnucImu.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "hipnuc_msgs/msg/detail/hipnuc_imu__struct.h"
#include "hipnuc_msgs/msg/detail/hipnuc_imu__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hipnuc_msgs__msg__hipnuc_imu__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("hipnuc_msgs.msg._hipnuc_imu.HipnucImu", full_classname_dest, 37) == 0);
  }
  hipnuc_msgs__msg__HipnucImu * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // source
    PyObject * field = PyObject_GetAttrString(_pymsg, "source");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->source = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "valid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->valid = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // node_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->node_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // main_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "main_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->main_status = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gyro_bias_converged
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_bias_converged");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gyro_bias_converged = (Py_True == field);
    Py_DECREF(field);
  }
  {  // attitude_converged
    PyObject * field = PyObject_GetAttrString(_pymsg, "attitude_converged");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->attitude_converged = (Py_True == field);
    Py_DECREF(field);
  }
  {  // magnetic_disturbance
    PyObject * field = PyObject_GetAttrString(_pymsg, "magnetic_disturbance");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->magnetic_disturbance = (Py_True == field);
    Py_DECREF(field);
  }
  {  // device_static
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_static");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->device_static = (Py_True == field);
    Py_DECREF(field);
  }
  {  // magnetometer_aiding
    PyObject * field = PyObject_GetAttrString(_pymsg, "magnetometer_aiding");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->magnetometer_aiding = (Py_True == field);
    Py_DECREF(field);
  }
  {  // ins_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "ins_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ins_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // acceleration
    PyObject * field = PyObject_GetAttrString(_pymsg, "acceleration");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->acceleration;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // angular_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "angular_velocity");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->angular_velocity;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // magnetic_field
    PyObject * field = PyObject_GetAttrString(_pymsg, "magnetic_field");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->magnetic_field;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heading = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // quaternion_wxyz
    PyObject * field = PyObject_GetAttrString(_pymsg, "quaternion_wxyz");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 4;
      float * dest = ros_message->quaternion_wxyz;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // inclination
    PyObject * field = PyObject_GetAttrString(_pymsg, "inclination");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 2;
      float * dest = ros_message->inclination;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // inclination_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "inclination_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->inclination_yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // device_time_us
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_time_us");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->device_time_us = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // utc_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->utc_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // utc_year
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_year");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_year = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_month
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_month");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_month = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_day
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_day");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_day = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_hour
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_hour");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_hour = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_minute
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_minute");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_minute = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_second
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_second");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_second = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_millisecond
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_millisecond");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_millisecond = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gps_week
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_week");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gps_week = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gps_tow_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_tow_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gps_tow_ms = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->temperature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pressure
    PyObject * field = PyObject_GetAttrString(_pymsg, "pressure");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pressure = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heave_surge_sway
    PyObject * field = PyObject_GetAttrString(_pymsg, "heave_surge_sway");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->heave_surge_sway;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // heave_surge_sway_frequency
    PyObject * field = PyObject_GetAttrString(_pymsg, "heave_surge_sway_frequency");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->heave_surge_sway_frequency;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // longitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "longitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->longitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // latitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "latitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->latitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // altitude_msl
    PyObject * field = PyObject_GetAttrString(_pymsg, "altitude_msl");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->altitude_msl = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gnss_longitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_longitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gnss_longitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gnss_latitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_latitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gnss_latitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gnss_altitude_msl
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_altitude_msl");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gnss_altitude_msl = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gnss_velocity_enu
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_velocity_enu");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->gnss_velocity_enu;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // geoid_separation
    PyObject * field = PyObject_GetAttrString(_pymsg, "geoid_separation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->geoid_separation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // velocity_enu
    PyObject * field = PyObject_GetAttrString(_pymsg, "velocity_enu");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->velocity_enu;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // acceleration_enu
    PyObject * field = PyObject_GetAttrString(_pymsg, "acceleration_enu");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 3;
      float * dest = ros_message->acceleration_enu;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // position_quality
    PyObject * field = PyObject_GetAttrString(_pymsg, "position_quality");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->position_quality = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // position_satellites
    PyObject * field = PyObject_GetAttrString(_pymsg, "position_satellites");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->position_satellites = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // heading_quality
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_quality");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->heading_quality = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // heading_satellites
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_satellites");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->heading_satellites = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pdop
    PyObject * field = PyObject_GetAttrString(_pymsg, "pdop");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pdop = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hdop
    PyObject * field = PyObject_GetAttrString(_pymsg, "hdop");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hdop = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // differential_age
    PyObject * field = PyObject_GetAttrString(_pymsg, "differential_age");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->differential_age = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // odometer_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "odometer_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->odometer_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_over_ground
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_over_ground");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_over_ground = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // course_over_ground
    PyObject * field = PyObject_GetAttrString(_pymsg, "course_over_ground");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->course_over_ground = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // nmea_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "nmea_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->nmea_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // nmea_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "nmea_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->nmea_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hipnuc_msgs__msg__hipnuc_imu__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HipnucImu */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hipnuc_msgs.msg._hipnuc_imu");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HipnucImu");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hipnuc_msgs__msg__HipnucImu * ros_message = (hipnuc_msgs__msg__HipnucImu *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // source
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->source);
    {
      int rc = PyObject_SetAttrString(_pymessage, "source", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // valid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->valid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->node_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // main_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->main_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "main_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_bias_converged
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gyro_bias_converged ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_bias_converged", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // attitude_converged
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->attitude_converged ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "attitude_converged", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // magnetic_disturbance
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->magnetic_disturbance ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "magnetic_disturbance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_static
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->device_static ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_static", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // magnetometer_aiding
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->magnetometer_aiding ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "magnetometer_aiding", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ins_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ins_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ins_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acceleration
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "acceleration");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->acceleration[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // angular_velocity
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "angular_velocity");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->angular_velocity[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // magnetic_field
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "magnetic_field");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->magnetic_field[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quaternion_wxyz
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "quaternion_wxyz");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->quaternion_wxyz[0]);
    memcpy(dst, src, 4 * sizeof(float));
    Py_DECREF(field);
  }
  {  // inclination
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "inclination");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->inclination[0]);
    memcpy(dst, src, 2 * sizeof(float));
    Py_DECREF(field);
  }
  {  // inclination_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->inclination_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "inclination_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_time_us
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->device_time_us);
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_time_us", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->utc_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_year
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_year);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_year", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_month
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_month);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_month", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_day
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_day);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_day", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_hour
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_hour);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_hour", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_minute
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_minute);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_minute", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_second
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_second);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_second", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_millisecond
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_millisecond);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_millisecond", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_week
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gps_week);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_week", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_tow_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gps_tow_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_tow_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pressure
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pressure);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pressure", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heave_surge_sway
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "heave_surge_sway");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->heave_surge_sway[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // heave_surge_sway_frequency
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "heave_surge_sway_frequency");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->heave_surge_sway_frequency[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // longitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->longitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "longitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // latitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->latitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "latitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // altitude_msl
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->altitude_msl);
    {
      int rc = PyObject_SetAttrString(_pymessage, "altitude_msl", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_longitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gnss_longitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_longitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_latitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gnss_latitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_latitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_altitude_msl
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gnss_altitude_msl);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_altitude_msl", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_velocity_enu
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "gnss_velocity_enu");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->gnss_velocity_enu[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // geoid_separation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->geoid_separation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "geoid_separation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // velocity_enu
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "velocity_enu");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->velocity_enu[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // acceleration_enu
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "acceleration_enu");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->acceleration_enu[0]);
    memcpy(dst, src, 3 * sizeof(float));
    Py_DECREF(field);
  }
  {  // position_quality
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->position_quality);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position_quality", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position_satellites
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->position_satellites);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position_satellites", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_quality
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->heading_quality);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_quality", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_satellites
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->heading_satellites);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_satellites", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pdop
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pdop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pdop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hdop
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hdop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hdop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // differential_age
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->differential_age);
    {
      int rc = PyObject_SetAttrString(_pymessage, "differential_age", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // odometer_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->odometer_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "odometer_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_over_ground
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_over_ground);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_over_ground", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // course_over_ground
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->course_over_ground);
    {
      int rc = PyObject_SetAttrString(_pymessage, "course_over_ground", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nmea_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->nmea_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nmea_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nmea_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->nmea_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nmea_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
