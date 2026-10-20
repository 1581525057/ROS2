# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hipnuc_msgs:msg/HipnucImu.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'acceleration'
# Member 'angular_velocity'
# Member 'magnetic_field'
# Member 'quaternion_wxyz'
# Member 'inclination'
# Member 'heave_surge_sway'
# Member 'heave_surge_sway_frequency'
# Member 'gnss_velocity_enu'
# Member 'velocity_enu'
# Member 'acceleration_enu'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HipnucImu(type):
    """Metaclass of message 'HipnucImu'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'VALID_STATUS': 1,
        'VALID_INS_STATUS': 2,
        'VALID_ACC': 4,
        'VALID_GYR': 8,
        'VALID_MAG': 16,
        'VALID_ROLL_PITCH': 32,
        'VALID_HEADING': 64,
        'VALID_QUAT': 128,
        'VALID_DEVICE_TIME': 256,
        'VALID_UTC': 512,
        'VALID_GPS_TIME': 1024,
        'VALID_PRESSURE': 2048,
        'VALID_TEMPERATURE': 4096,
        'VALID_INCLINATION': 8192,
        'VALID_HEAVE': 16384,
        'VALID_POSITION': 32768,
        'VALID_VELOCITY_ENU': 65536,
        'VALID_ACC_ENU': 131072,
        'VALID_POSITION_QUALITY': 262144,
        'VALID_PDOP': 524288,
        'VALID_DIFF_AGE': 1048576,
        'VALID_UNDULATION': 2097152,
        'VALID_ODOMETER': 4194304,
        'VALID_GNSS_POSITION': 8388608,
        'VALID_GNSS_VELOCITY': 16777216,
        'VALID_SOG': 33554432,
        'VALID_NODE_ID': 67108864,
        'VALID_YAW': 134217728,
        'VALID_ALTITUDE': 268435456,
        'VALID_HEADING_QUALITY': 536870912,
        'VALID_POSITION_SATELLITES': 1073741824,
        'VALID_HEADING_SATELLITES': 2147483648,
        'VALID_HDOP': 4294967296,
        'VALID_HEAVE_FREQUENCY': 8589934592,
        'VALID_GNSS_ALTITUDE': 17179869184,
        'VALID_COG': 34359738368,
        'VALID_NMEA_STATUS': 68719476736,
        'VALID_NMEA_MODE': 137438953472,
        'VALID_UTC_TIME_OF_DAY': 274877906944,
        'VALID_INCLINATION_YAW': 549755813888,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hipnuc_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hipnuc_msgs.msg.HipnucImu')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hipnuc_imu
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hipnuc_imu
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hipnuc_imu
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hipnuc_imu
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hipnuc_imu

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'VALID_STATUS': cls.__constants['VALID_STATUS'],
            'VALID_INS_STATUS': cls.__constants['VALID_INS_STATUS'],
            'VALID_ACC': cls.__constants['VALID_ACC'],
            'VALID_GYR': cls.__constants['VALID_GYR'],
            'VALID_MAG': cls.__constants['VALID_MAG'],
            'VALID_ROLL_PITCH': cls.__constants['VALID_ROLL_PITCH'],
            'VALID_HEADING': cls.__constants['VALID_HEADING'],
            'VALID_QUAT': cls.__constants['VALID_QUAT'],
            'VALID_DEVICE_TIME': cls.__constants['VALID_DEVICE_TIME'],
            'VALID_UTC': cls.__constants['VALID_UTC'],
            'VALID_GPS_TIME': cls.__constants['VALID_GPS_TIME'],
            'VALID_PRESSURE': cls.__constants['VALID_PRESSURE'],
            'VALID_TEMPERATURE': cls.__constants['VALID_TEMPERATURE'],
            'VALID_INCLINATION': cls.__constants['VALID_INCLINATION'],
            'VALID_HEAVE': cls.__constants['VALID_HEAVE'],
            'VALID_POSITION': cls.__constants['VALID_POSITION'],
            'VALID_VELOCITY_ENU': cls.__constants['VALID_VELOCITY_ENU'],
            'VALID_ACC_ENU': cls.__constants['VALID_ACC_ENU'],
            'VALID_POSITION_QUALITY': cls.__constants['VALID_POSITION_QUALITY'],
            'VALID_PDOP': cls.__constants['VALID_PDOP'],
            'VALID_DIFF_AGE': cls.__constants['VALID_DIFF_AGE'],
            'VALID_UNDULATION': cls.__constants['VALID_UNDULATION'],
            'VALID_ODOMETER': cls.__constants['VALID_ODOMETER'],
            'VALID_GNSS_POSITION': cls.__constants['VALID_GNSS_POSITION'],
            'VALID_GNSS_VELOCITY': cls.__constants['VALID_GNSS_VELOCITY'],
            'VALID_SOG': cls.__constants['VALID_SOG'],
            'VALID_NODE_ID': cls.__constants['VALID_NODE_ID'],
            'VALID_YAW': cls.__constants['VALID_YAW'],
            'VALID_ALTITUDE': cls.__constants['VALID_ALTITUDE'],
            'VALID_HEADING_QUALITY': cls.__constants['VALID_HEADING_QUALITY'],
            'VALID_POSITION_SATELLITES': cls.__constants['VALID_POSITION_SATELLITES'],
            'VALID_HEADING_SATELLITES': cls.__constants['VALID_HEADING_SATELLITES'],
            'VALID_HDOP': cls.__constants['VALID_HDOP'],
            'VALID_HEAVE_FREQUENCY': cls.__constants['VALID_HEAVE_FREQUENCY'],
            'VALID_GNSS_ALTITUDE': cls.__constants['VALID_GNSS_ALTITUDE'],
            'VALID_COG': cls.__constants['VALID_COG'],
            'VALID_NMEA_STATUS': cls.__constants['VALID_NMEA_STATUS'],
            'VALID_NMEA_MODE': cls.__constants['VALID_NMEA_MODE'],
            'VALID_UTC_TIME_OF_DAY': cls.__constants['VALID_UTC_TIME_OF_DAY'],
            'VALID_INCLINATION_YAW': cls.__constants['VALID_INCLINATION_YAW'],
        }

    @property
    def VALID_STATUS(self):
        """Message constant 'VALID_STATUS'."""
        return Metaclass_HipnucImu.__constants['VALID_STATUS']

    @property
    def VALID_INS_STATUS(self):
        """Message constant 'VALID_INS_STATUS'."""
        return Metaclass_HipnucImu.__constants['VALID_INS_STATUS']

    @property
    def VALID_ACC(self):
        """Message constant 'VALID_ACC'."""
        return Metaclass_HipnucImu.__constants['VALID_ACC']

    @property
    def VALID_GYR(self):
        """Message constant 'VALID_GYR'."""
        return Metaclass_HipnucImu.__constants['VALID_GYR']

    @property
    def VALID_MAG(self):
        """Message constant 'VALID_MAG'."""
        return Metaclass_HipnucImu.__constants['VALID_MAG']

    @property
    def VALID_ROLL_PITCH(self):
        """Message constant 'VALID_ROLL_PITCH'."""
        return Metaclass_HipnucImu.__constants['VALID_ROLL_PITCH']

    @property
    def VALID_HEADING(self):
        """Message constant 'VALID_HEADING'."""
        return Metaclass_HipnucImu.__constants['VALID_HEADING']

    @property
    def VALID_QUAT(self):
        """Message constant 'VALID_QUAT'."""
        return Metaclass_HipnucImu.__constants['VALID_QUAT']

    @property
    def VALID_DEVICE_TIME(self):
        """Message constant 'VALID_DEVICE_TIME'."""
        return Metaclass_HipnucImu.__constants['VALID_DEVICE_TIME']

    @property
    def VALID_UTC(self):
        """Message constant 'VALID_UTC'."""
        return Metaclass_HipnucImu.__constants['VALID_UTC']

    @property
    def VALID_GPS_TIME(self):
        """Message constant 'VALID_GPS_TIME'."""
        return Metaclass_HipnucImu.__constants['VALID_GPS_TIME']

    @property
    def VALID_PRESSURE(self):
        """Message constant 'VALID_PRESSURE'."""
        return Metaclass_HipnucImu.__constants['VALID_PRESSURE']

    @property
    def VALID_TEMPERATURE(self):
        """Message constant 'VALID_TEMPERATURE'."""
        return Metaclass_HipnucImu.__constants['VALID_TEMPERATURE']

    @property
    def VALID_INCLINATION(self):
        """Message constant 'VALID_INCLINATION'."""
        return Metaclass_HipnucImu.__constants['VALID_INCLINATION']

    @property
    def VALID_HEAVE(self):
        """Message constant 'VALID_HEAVE'."""
        return Metaclass_HipnucImu.__constants['VALID_HEAVE']

    @property
    def VALID_POSITION(self):
        """Message constant 'VALID_POSITION'."""
        return Metaclass_HipnucImu.__constants['VALID_POSITION']

    @property
    def VALID_VELOCITY_ENU(self):
        """Message constant 'VALID_VELOCITY_ENU'."""
        return Metaclass_HipnucImu.__constants['VALID_VELOCITY_ENU']

    @property
    def VALID_ACC_ENU(self):
        """Message constant 'VALID_ACC_ENU'."""
        return Metaclass_HipnucImu.__constants['VALID_ACC_ENU']

    @property
    def VALID_POSITION_QUALITY(self):
        """Message constant 'VALID_POSITION_QUALITY'."""
        return Metaclass_HipnucImu.__constants['VALID_POSITION_QUALITY']

    @property
    def VALID_PDOP(self):
        """Message constant 'VALID_PDOP'."""
        return Metaclass_HipnucImu.__constants['VALID_PDOP']

    @property
    def VALID_DIFF_AGE(self):
        """Message constant 'VALID_DIFF_AGE'."""
        return Metaclass_HipnucImu.__constants['VALID_DIFF_AGE']

    @property
    def VALID_UNDULATION(self):
        """Message constant 'VALID_UNDULATION'."""
        return Metaclass_HipnucImu.__constants['VALID_UNDULATION']

    @property
    def VALID_ODOMETER(self):
        """Message constant 'VALID_ODOMETER'."""
        return Metaclass_HipnucImu.__constants['VALID_ODOMETER']

    @property
    def VALID_GNSS_POSITION(self):
        """Message constant 'VALID_GNSS_POSITION'."""
        return Metaclass_HipnucImu.__constants['VALID_GNSS_POSITION']

    @property
    def VALID_GNSS_VELOCITY(self):
        """Message constant 'VALID_GNSS_VELOCITY'."""
        return Metaclass_HipnucImu.__constants['VALID_GNSS_VELOCITY']

    @property
    def VALID_SOG(self):
        """Message constant 'VALID_SOG'."""
        return Metaclass_HipnucImu.__constants['VALID_SOG']

    @property
    def VALID_NODE_ID(self):
        """Message constant 'VALID_NODE_ID'."""
        return Metaclass_HipnucImu.__constants['VALID_NODE_ID']

    @property
    def VALID_YAW(self):
        """Message constant 'VALID_YAW'."""
        return Metaclass_HipnucImu.__constants['VALID_YAW']

    @property
    def VALID_ALTITUDE(self):
        """Message constant 'VALID_ALTITUDE'."""
        return Metaclass_HipnucImu.__constants['VALID_ALTITUDE']

    @property
    def VALID_HEADING_QUALITY(self):
        """Message constant 'VALID_HEADING_QUALITY'."""
        return Metaclass_HipnucImu.__constants['VALID_HEADING_QUALITY']

    @property
    def VALID_POSITION_SATELLITES(self):
        """Message constant 'VALID_POSITION_SATELLITES'."""
        return Metaclass_HipnucImu.__constants['VALID_POSITION_SATELLITES']

    @property
    def VALID_HEADING_SATELLITES(self):
        """Message constant 'VALID_HEADING_SATELLITES'."""
        return Metaclass_HipnucImu.__constants['VALID_HEADING_SATELLITES']

    @property
    def VALID_HDOP(self):
        """Message constant 'VALID_HDOP'."""
        return Metaclass_HipnucImu.__constants['VALID_HDOP']

    @property
    def VALID_HEAVE_FREQUENCY(self):
        """Message constant 'VALID_HEAVE_FREQUENCY'."""
        return Metaclass_HipnucImu.__constants['VALID_HEAVE_FREQUENCY']

    @property
    def VALID_GNSS_ALTITUDE(self):
        """Message constant 'VALID_GNSS_ALTITUDE'."""
        return Metaclass_HipnucImu.__constants['VALID_GNSS_ALTITUDE']

    @property
    def VALID_COG(self):
        """Message constant 'VALID_COG'."""
        return Metaclass_HipnucImu.__constants['VALID_COG']

    @property
    def VALID_NMEA_STATUS(self):
        """Message constant 'VALID_NMEA_STATUS'."""
        return Metaclass_HipnucImu.__constants['VALID_NMEA_STATUS']

    @property
    def VALID_NMEA_MODE(self):
        """Message constant 'VALID_NMEA_MODE'."""
        return Metaclass_HipnucImu.__constants['VALID_NMEA_MODE']

    @property
    def VALID_UTC_TIME_OF_DAY(self):
        """Message constant 'VALID_UTC_TIME_OF_DAY'."""
        return Metaclass_HipnucImu.__constants['VALID_UTC_TIME_OF_DAY']

    @property
    def VALID_INCLINATION_YAW(self):
        """Message constant 'VALID_INCLINATION_YAW'."""
        return Metaclass_HipnucImu.__constants['VALID_INCLINATION_YAW']


class HipnucImu(metaclass=Metaclass_HipnucImu):
    """
    Message class 'HipnucImu'.

    Constants:
      VALID_STATUS
      VALID_INS_STATUS
      VALID_ACC
      VALID_GYR
      VALID_MAG
      VALID_ROLL_PITCH
      VALID_HEADING
      VALID_QUAT
      VALID_DEVICE_TIME
      VALID_UTC
      VALID_GPS_TIME
      VALID_PRESSURE
      VALID_TEMPERATURE
      VALID_INCLINATION
      VALID_HEAVE
      VALID_POSITION
      VALID_VELOCITY_ENU
      VALID_ACC_ENU
      VALID_POSITION_QUALITY
      VALID_PDOP
      VALID_DIFF_AGE
      VALID_UNDULATION
      VALID_ODOMETER
      VALID_GNSS_POSITION
      VALID_GNSS_VELOCITY
      VALID_SOG
      VALID_NODE_ID
      VALID_YAW
      VALID_ALTITUDE
      VALID_HEADING_QUALITY
      VALID_POSITION_SATELLITES
      VALID_HEADING_SATELLITES
      VALID_HDOP
      VALID_HEAVE_FREQUENCY
      VALID_GNSS_ALTITUDE
      VALID_COG
      VALID_NMEA_STATUS
      VALID_NMEA_MODE
      VALID_UTC_TIME_OF_DAY
      VALID_INCLINATION_YAW
    """

    __slots__ = [
        '_header',
        '_source',
        '_valid',
        '_node_id',
        '_main_status',
        '_gyro_bias_converged',
        '_attitude_converged',
        '_magnetic_disturbance',
        '_device_static',
        '_magnetometer_aiding',
        '_ins_status',
        '_acceleration',
        '_angular_velocity',
        '_magnetic_field',
        '_roll',
        '_pitch',
        '_yaw',
        '_heading',
        '_quaternion_wxyz',
        '_inclination',
        '_inclination_yaw',
        '_device_time_us',
        '_utc_valid',
        '_utc_year',
        '_utc_month',
        '_utc_day',
        '_utc_hour',
        '_utc_minute',
        '_utc_second',
        '_utc_millisecond',
        '_gps_week',
        '_gps_tow_ms',
        '_temperature',
        '_pressure',
        '_heave_surge_sway',
        '_heave_surge_sway_frequency',
        '_longitude',
        '_latitude',
        '_altitude_msl',
        '_gnss_longitude',
        '_gnss_latitude',
        '_gnss_altitude_msl',
        '_gnss_velocity_enu',
        '_geoid_separation',
        '_velocity_enu',
        '_acceleration_enu',
        '_position_quality',
        '_position_satellites',
        '_heading_quality',
        '_heading_satellites',
        '_pdop',
        '_hdop',
        '_differential_age',
        '_odometer_speed',
        '_speed_over_ground',
        '_course_over_ground',
        '_nmea_status',
        '_nmea_mode',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'source': 'uint8',
        'valid': 'uint64',
        'node_id': 'uint8',
        'main_status': 'uint16',
        'gyro_bias_converged': 'boolean',
        'attitude_converged': 'boolean',
        'magnetic_disturbance': 'boolean',
        'device_static': 'boolean',
        'magnetometer_aiding': 'boolean',
        'ins_status': 'uint8',
        'acceleration': 'float[3]',
        'angular_velocity': 'float[3]',
        'magnetic_field': 'float[3]',
        'roll': 'float',
        'pitch': 'float',
        'yaw': 'float',
        'heading': 'float',
        'quaternion_wxyz': 'float[4]',
        'inclination': 'float[2]',
        'inclination_yaw': 'float',
        'device_time_us': 'uint64',
        'utc_valid': 'boolean',
        'utc_year': 'uint16',
        'utc_month': 'uint8',
        'utc_day': 'uint8',
        'utc_hour': 'uint8',
        'utc_minute': 'uint8',
        'utc_second': 'uint8',
        'utc_millisecond': 'uint16',
        'gps_week': 'uint16',
        'gps_tow_ms': 'uint32',
        'temperature': 'float',
        'pressure': 'float',
        'heave_surge_sway': 'float[3]',
        'heave_surge_sway_frequency': 'float[3]',
        'longitude': 'double',
        'latitude': 'double',
        'altitude_msl': 'double',
        'gnss_longitude': 'double',
        'gnss_latitude': 'double',
        'gnss_altitude_msl': 'double',
        'gnss_velocity_enu': 'float[3]',
        'geoid_separation': 'float',
        'velocity_enu': 'float[3]',
        'acceleration_enu': 'float[3]',
        'position_quality': 'uint8',
        'position_satellites': 'uint8',
        'heading_quality': 'uint8',
        'heading_satellites': 'uint8',
        'pdop': 'float',
        'hdop': 'float',
        'differential_age': 'float',
        'odometer_speed': 'float',
        'speed_over_ground': 'float',
        'course_over_ground': 'float',
        'nmea_status': 'uint8',
        'nmea_mode': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.source = kwargs.get('source', int())
        self.valid = kwargs.get('valid', int())
        self.node_id = kwargs.get('node_id', int())
        self.main_status = kwargs.get('main_status', int())
        self.gyro_bias_converged = kwargs.get('gyro_bias_converged', bool())
        self.attitude_converged = kwargs.get('attitude_converged', bool())
        self.magnetic_disturbance = kwargs.get('magnetic_disturbance', bool())
        self.device_static = kwargs.get('device_static', bool())
        self.magnetometer_aiding = kwargs.get('magnetometer_aiding', bool())
        self.ins_status = kwargs.get('ins_status', int())
        if 'acceleration' not in kwargs:
            self.acceleration = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.acceleration = kwargs.get('acceleration')
        if 'angular_velocity' not in kwargs:
            self.angular_velocity = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.angular_velocity = kwargs.get('angular_velocity')
        if 'magnetic_field' not in kwargs:
            self.magnetic_field = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.magnetic_field = kwargs.get('magnetic_field')
        self.roll = kwargs.get('roll', float())
        self.pitch = kwargs.get('pitch', float())
        self.yaw = kwargs.get('yaw', float())
        self.heading = kwargs.get('heading', float())
        if 'quaternion_wxyz' not in kwargs:
            self.quaternion_wxyz = numpy.zeros(4, dtype=numpy.float32)
        else:
            self.quaternion_wxyz = kwargs.get('quaternion_wxyz')
        if 'inclination' not in kwargs:
            self.inclination = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.inclination = kwargs.get('inclination')
        self.inclination_yaw = kwargs.get('inclination_yaw', float())
        self.device_time_us = kwargs.get('device_time_us', int())
        self.utc_valid = kwargs.get('utc_valid', bool())
        self.utc_year = kwargs.get('utc_year', int())
        self.utc_month = kwargs.get('utc_month', int())
        self.utc_day = kwargs.get('utc_day', int())
        self.utc_hour = kwargs.get('utc_hour', int())
        self.utc_minute = kwargs.get('utc_minute', int())
        self.utc_second = kwargs.get('utc_second', int())
        self.utc_millisecond = kwargs.get('utc_millisecond', int())
        self.gps_week = kwargs.get('gps_week', int())
        self.gps_tow_ms = kwargs.get('gps_tow_ms', int())
        self.temperature = kwargs.get('temperature', float())
        self.pressure = kwargs.get('pressure', float())
        if 'heave_surge_sway' not in kwargs:
            self.heave_surge_sway = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.heave_surge_sway = kwargs.get('heave_surge_sway')
        if 'heave_surge_sway_frequency' not in kwargs:
            self.heave_surge_sway_frequency = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.heave_surge_sway_frequency = kwargs.get('heave_surge_sway_frequency')
        self.longitude = kwargs.get('longitude', float())
        self.latitude = kwargs.get('latitude', float())
        self.altitude_msl = kwargs.get('altitude_msl', float())
        self.gnss_longitude = kwargs.get('gnss_longitude', float())
        self.gnss_latitude = kwargs.get('gnss_latitude', float())
        self.gnss_altitude_msl = kwargs.get('gnss_altitude_msl', float())
        if 'gnss_velocity_enu' not in kwargs:
            self.gnss_velocity_enu = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.gnss_velocity_enu = kwargs.get('gnss_velocity_enu')
        self.geoid_separation = kwargs.get('geoid_separation', float())
        if 'velocity_enu' not in kwargs:
            self.velocity_enu = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.velocity_enu = kwargs.get('velocity_enu')
        if 'acceleration_enu' not in kwargs:
            self.acceleration_enu = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.acceleration_enu = kwargs.get('acceleration_enu')
        self.position_quality = kwargs.get('position_quality', int())
        self.position_satellites = kwargs.get('position_satellites', int())
        self.heading_quality = kwargs.get('heading_quality', int())
        self.heading_satellites = kwargs.get('heading_satellites', int())
        self.pdop = kwargs.get('pdop', float())
        self.hdop = kwargs.get('hdop', float())
        self.differential_age = kwargs.get('differential_age', float())
        self.odometer_speed = kwargs.get('odometer_speed', float())
        self.speed_over_ground = kwargs.get('speed_over_ground', float())
        self.course_over_ground = kwargs.get('course_over_ground', float())
        self.nmea_status = kwargs.get('nmea_status', int())
        self.nmea_mode = kwargs.get('nmea_mode', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.source != other.source:
            return False
        if self.valid != other.valid:
            return False
        if self.node_id != other.node_id:
            return False
        if self.main_status != other.main_status:
            return False
        if self.gyro_bias_converged != other.gyro_bias_converged:
            return False
        if self.attitude_converged != other.attitude_converged:
            return False
        if self.magnetic_disturbance != other.magnetic_disturbance:
            return False
        if self.device_static != other.device_static:
            return False
        if self.magnetometer_aiding != other.magnetometer_aiding:
            return False
        if self.ins_status != other.ins_status:
            return False
        if any(self.acceleration != other.acceleration):
            return False
        if any(self.angular_velocity != other.angular_velocity):
            return False
        if any(self.magnetic_field != other.magnetic_field):
            return False
        if self.roll != other.roll:
            return False
        if self.pitch != other.pitch:
            return False
        if self.yaw != other.yaw:
            return False
        if self.heading != other.heading:
            return False
        if any(self.quaternion_wxyz != other.quaternion_wxyz):
            return False
        if any(self.inclination != other.inclination):
            return False
        if self.inclination_yaw != other.inclination_yaw:
            return False
        if self.device_time_us != other.device_time_us:
            return False
        if self.utc_valid != other.utc_valid:
            return False
        if self.utc_year != other.utc_year:
            return False
        if self.utc_month != other.utc_month:
            return False
        if self.utc_day != other.utc_day:
            return False
        if self.utc_hour != other.utc_hour:
            return False
        if self.utc_minute != other.utc_minute:
            return False
        if self.utc_second != other.utc_second:
            return False
        if self.utc_millisecond != other.utc_millisecond:
            return False
        if self.gps_week != other.gps_week:
            return False
        if self.gps_tow_ms != other.gps_tow_ms:
            return False
        if self.temperature != other.temperature:
            return False
        if self.pressure != other.pressure:
            return False
        if any(self.heave_surge_sway != other.heave_surge_sway):
            return False
        if any(self.heave_surge_sway_frequency != other.heave_surge_sway_frequency):
            return False
        if self.longitude != other.longitude:
            return False
        if self.latitude != other.latitude:
            return False
        if self.altitude_msl != other.altitude_msl:
            return False
        if self.gnss_longitude != other.gnss_longitude:
            return False
        if self.gnss_latitude != other.gnss_latitude:
            return False
        if self.gnss_altitude_msl != other.gnss_altitude_msl:
            return False
        if any(self.gnss_velocity_enu != other.gnss_velocity_enu):
            return False
        if self.geoid_separation != other.geoid_separation:
            return False
        if any(self.velocity_enu != other.velocity_enu):
            return False
        if any(self.acceleration_enu != other.acceleration_enu):
            return False
        if self.position_quality != other.position_quality:
            return False
        if self.position_satellites != other.position_satellites:
            return False
        if self.heading_quality != other.heading_quality:
            return False
        if self.heading_satellites != other.heading_satellites:
            return False
        if self.pdop != other.pdop:
            return False
        if self.hdop != other.hdop:
            return False
        if self.differential_age != other.differential_age:
            return False
        if self.odometer_speed != other.odometer_speed:
            return False
        if self.speed_over_ground != other.speed_over_ground:
            return False
        if self.course_over_ground != other.course_over_ground:
            return False
        if self.nmea_status != other.nmea_status:
            return False
        if self.nmea_mode != other.nmea_mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def source(self):
        """Message field 'source'."""
        return self._source

    @source.setter
    def source(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'source' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'source' field must be an unsigned integer in [0, 255]"
        self._source = value

    @builtins.property
    def valid(self):
        """Message field 'valid'."""
        return self._valid

    @valid.setter
    def valid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'valid' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'valid' field must be an unsigned integer in [0, 18446744073709551615]"
        self._valid = value

    @builtins.property
    def node_id(self):
        """Message field 'node_id'."""
        return self._node_id

    @node_id.setter
    def node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'node_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'node_id' field must be an unsigned integer in [0, 255]"
        self._node_id = value

    @builtins.property
    def main_status(self):
        """Message field 'main_status'."""
        return self._main_status

    @main_status.setter
    def main_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'main_status' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'main_status' field must be an unsigned integer in [0, 65535]"
        self._main_status = value

    @builtins.property
    def gyro_bias_converged(self):
        """Message field 'gyro_bias_converged'."""
        return self._gyro_bias_converged

    @gyro_bias_converged.setter
    def gyro_bias_converged(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'gyro_bias_converged' field must be of type 'bool'"
        self._gyro_bias_converged = value

    @builtins.property
    def attitude_converged(self):
        """Message field 'attitude_converged'."""
        return self._attitude_converged

    @attitude_converged.setter
    def attitude_converged(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'attitude_converged' field must be of type 'bool'"
        self._attitude_converged = value

    @builtins.property
    def magnetic_disturbance(self):
        """Message field 'magnetic_disturbance'."""
        return self._magnetic_disturbance

    @magnetic_disturbance.setter
    def magnetic_disturbance(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'magnetic_disturbance' field must be of type 'bool'"
        self._magnetic_disturbance = value

    @builtins.property
    def device_static(self):
        """Message field 'device_static'."""
        return self._device_static

    @device_static.setter
    def device_static(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'device_static' field must be of type 'bool'"
        self._device_static = value

    @builtins.property
    def magnetometer_aiding(self):
        """Message field 'magnetometer_aiding'."""
        return self._magnetometer_aiding

    @magnetometer_aiding.setter
    def magnetometer_aiding(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'magnetometer_aiding' field must be of type 'bool'"
        self._magnetometer_aiding = value

    @builtins.property
    def ins_status(self):
        """Message field 'ins_status'."""
        return self._ins_status

    @ins_status.setter
    def ins_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ins_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ins_status' field must be an unsigned integer in [0, 255]"
        self._ins_status = value

    @builtins.property
    def acceleration(self):
        """Message field 'acceleration'."""
        return self._acceleration

    @acceleration.setter
    def acceleration(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'acceleration' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'acceleration' numpy.ndarray() must have a size of 3"
            self._acceleration = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'acceleration' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._acceleration = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def angular_velocity(self):
        """Message field 'angular_velocity'."""
        return self._angular_velocity

    @angular_velocity.setter
    def angular_velocity(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'angular_velocity' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'angular_velocity' numpy.ndarray() must have a size of 3"
            self._angular_velocity = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'angular_velocity' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._angular_velocity = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def magnetic_field(self):
        """Message field 'magnetic_field'."""
        return self._magnetic_field

    @magnetic_field.setter
    def magnetic_field(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'magnetic_field' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'magnetic_field' numpy.ndarray() must have a size of 3"
            self._magnetic_field = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'magnetic_field' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._magnetic_field = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def roll(self):
        """Message field 'roll'."""
        return self._roll

    @roll.setter
    def roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'roll' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'roll' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._roll = value

    @builtins.property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value

    @builtins.property
    def heading(self):
        """Message field 'heading'."""
        return self._heading

    @heading.setter
    def heading(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heading' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heading = value

    @builtins.property
    def quaternion_wxyz(self):
        """Message field 'quaternion_wxyz'."""
        return self._quaternion_wxyz

    @quaternion_wxyz.setter
    def quaternion_wxyz(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'quaternion_wxyz' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 4, \
                "The 'quaternion_wxyz' numpy.ndarray() must have a size of 4"
            self._quaternion_wxyz = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'quaternion_wxyz' field must be a set or sequence with length 4 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._quaternion_wxyz = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def inclination(self):
        """Message field 'inclination'."""
        return self._inclination

    @inclination.setter
    def inclination(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'inclination' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'inclination' numpy.ndarray() must have a size of 2"
            self._inclination = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'inclination' field must be a set or sequence with length 2 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._inclination = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def inclination_yaw(self):
        """Message field 'inclination_yaw'."""
        return self._inclination_yaw

    @inclination_yaw.setter
    def inclination_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'inclination_yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'inclination_yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._inclination_yaw = value

    @builtins.property
    def device_time_us(self):
        """Message field 'device_time_us'."""
        return self._device_time_us

    @device_time_us.setter
    def device_time_us(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'device_time_us' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'device_time_us' field must be an unsigned integer in [0, 18446744073709551615]"
        self._device_time_us = value

    @builtins.property
    def utc_valid(self):
        """Message field 'utc_valid'."""
        return self._utc_valid

    @utc_valid.setter
    def utc_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'utc_valid' field must be of type 'bool'"
        self._utc_valid = value

    @builtins.property
    def utc_year(self):
        """Message field 'utc_year'."""
        return self._utc_year

    @utc_year.setter
    def utc_year(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_year' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'utc_year' field must be an unsigned integer in [0, 65535]"
        self._utc_year = value

    @builtins.property
    def utc_month(self):
        """Message field 'utc_month'."""
        return self._utc_month

    @utc_month.setter
    def utc_month(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_month' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'utc_month' field must be an unsigned integer in [0, 255]"
        self._utc_month = value

    @builtins.property
    def utc_day(self):
        """Message field 'utc_day'."""
        return self._utc_day

    @utc_day.setter
    def utc_day(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_day' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'utc_day' field must be an unsigned integer in [0, 255]"
        self._utc_day = value

    @builtins.property
    def utc_hour(self):
        """Message field 'utc_hour'."""
        return self._utc_hour

    @utc_hour.setter
    def utc_hour(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_hour' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'utc_hour' field must be an unsigned integer in [0, 255]"
        self._utc_hour = value

    @builtins.property
    def utc_minute(self):
        """Message field 'utc_minute'."""
        return self._utc_minute

    @utc_minute.setter
    def utc_minute(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_minute' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'utc_minute' field must be an unsigned integer in [0, 255]"
        self._utc_minute = value

    @builtins.property
    def utc_second(self):
        """Message field 'utc_second'."""
        return self._utc_second

    @utc_second.setter
    def utc_second(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_second' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'utc_second' field must be an unsigned integer in [0, 255]"
        self._utc_second = value

    @builtins.property
    def utc_millisecond(self):
        """Message field 'utc_millisecond'."""
        return self._utc_millisecond

    @utc_millisecond.setter
    def utc_millisecond(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_millisecond' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'utc_millisecond' field must be an unsigned integer in [0, 65535]"
        self._utc_millisecond = value

    @builtins.property
    def gps_week(self):
        """Message field 'gps_week'."""
        return self._gps_week

    @gps_week.setter
    def gps_week(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gps_week' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'gps_week' field must be an unsigned integer in [0, 65535]"
        self._gps_week = value

    @builtins.property
    def gps_tow_ms(self):
        """Message field 'gps_tow_ms'."""
        return self._gps_tow_ms

    @gps_tow_ms.setter
    def gps_tow_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gps_tow_ms' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'gps_tow_ms' field must be an unsigned integer in [0, 4294967295]"
        self._gps_tow_ms = value

    @builtins.property
    def temperature(self):
        """Message field 'temperature'."""
        return self._temperature

    @temperature.setter
    def temperature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temperature' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'temperature' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._temperature = value

    @builtins.property
    def pressure(self):
        """Message field 'pressure'."""
        return self._pressure

    @pressure.setter
    def pressure(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pressure' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pressure' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pressure = value

    @builtins.property
    def heave_surge_sway(self):
        """Message field 'heave_surge_sway'."""
        return self._heave_surge_sway

    @heave_surge_sway.setter
    def heave_surge_sway(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'heave_surge_sway' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'heave_surge_sway' numpy.ndarray() must have a size of 3"
            self._heave_surge_sway = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'heave_surge_sway' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._heave_surge_sway = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def heave_surge_sway_frequency(self):
        """Message field 'heave_surge_sway_frequency'."""
        return self._heave_surge_sway_frequency

    @heave_surge_sway_frequency.setter
    def heave_surge_sway_frequency(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'heave_surge_sway_frequency' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'heave_surge_sway_frequency' numpy.ndarray() must have a size of 3"
            self._heave_surge_sway_frequency = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'heave_surge_sway_frequency' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._heave_surge_sway_frequency = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def longitude(self):
        """Message field 'longitude'."""
        return self._longitude

    @longitude.setter
    def longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'longitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._longitude = value

    @builtins.property
    def latitude(self):
        """Message field 'latitude'."""
        return self._latitude

    @latitude.setter
    def latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'latitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._latitude = value

    @builtins.property
    def altitude_msl(self):
        """Message field 'altitude_msl'."""
        return self._altitude_msl

    @altitude_msl.setter
    def altitude_msl(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'altitude_msl' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'altitude_msl' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._altitude_msl = value

    @builtins.property
    def gnss_longitude(self):
        """Message field 'gnss_longitude'."""
        return self._gnss_longitude

    @gnss_longitude.setter
    def gnss_longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gnss_longitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gnss_longitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gnss_longitude = value

    @builtins.property
    def gnss_latitude(self):
        """Message field 'gnss_latitude'."""
        return self._gnss_latitude

    @gnss_latitude.setter
    def gnss_latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gnss_latitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gnss_latitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gnss_latitude = value

    @builtins.property
    def gnss_altitude_msl(self):
        """Message field 'gnss_altitude_msl'."""
        return self._gnss_altitude_msl

    @gnss_altitude_msl.setter
    def gnss_altitude_msl(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gnss_altitude_msl' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gnss_altitude_msl' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gnss_altitude_msl = value

    @builtins.property
    def gnss_velocity_enu(self):
        """Message field 'gnss_velocity_enu'."""
        return self._gnss_velocity_enu

    @gnss_velocity_enu.setter
    def gnss_velocity_enu(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'gnss_velocity_enu' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'gnss_velocity_enu' numpy.ndarray() must have a size of 3"
            self._gnss_velocity_enu = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'gnss_velocity_enu' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._gnss_velocity_enu = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def geoid_separation(self):
        """Message field 'geoid_separation'."""
        return self._geoid_separation

    @geoid_separation.setter
    def geoid_separation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'geoid_separation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'geoid_separation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._geoid_separation = value

    @builtins.property
    def velocity_enu(self):
        """Message field 'velocity_enu'."""
        return self._velocity_enu

    @velocity_enu.setter
    def velocity_enu(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'velocity_enu' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'velocity_enu' numpy.ndarray() must have a size of 3"
            self._velocity_enu = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'velocity_enu' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._velocity_enu = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def acceleration_enu(self):
        """Message field 'acceleration_enu'."""
        return self._acceleration_enu

    @acceleration_enu.setter
    def acceleration_enu(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'acceleration_enu' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'acceleration_enu' numpy.ndarray() must have a size of 3"
            self._acceleration_enu = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'acceleration_enu' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._acceleration_enu = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def position_quality(self):
        """Message field 'position_quality'."""
        return self._position_quality

    @position_quality.setter
    def position_quality(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'position_quality' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'position_quality' field must be an unsigned integer in [0, 255]"
        self._position_quality = value

    @builtins.property
    def position_satellites(self):
        """Message field 'position_satellites'."""
        return self._position_satellites

    @position_satellites.setter
    def position_satellites(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'position_satellites' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'position_satellites' field must be an unsigned integer in [0, 255]"
        self._position_satellites = value

    @builtins.property
    def heading_quality(self):
        """Message field 'heading_quality'."""
        return self._heading_quality

    @heading_quality.setter
    def heading_quality(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'heading_quality' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'heading_quality' field must be an unsigned integer in [0, 255]"
        self._heading_quality = value

    @builtins.property
    def heading_satellites(self):
        """Message field 'heading_satellites'."""
        return self._heading_satellites

    @heading_satellites.setter
    def heading_satellites(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'heading_satellites' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'heading_satellites' field must be an unsigned integer in [0, 255]"
        self._heading_satellites = value

    @builtins.property
    def pdop(self):
        """Message field 'pdop'."""
        return self._pdop

    @pdop.setter
    def pdop(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pdop' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pdop' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pdop = value

    @builtins.property
    def hdop(self):
        """Message field 'hdop'."""
        return self._hdop

    @hdop.setter
    def hdop(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hdop' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hdop' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hdop = value

    @builtins.property
    def differential_age(self):
        """Message field 'differential_age'."""
        return self._differential_age

    @differential_age.setter
    def differential_age(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'differential_age' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'differential_age' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._differential_age = value

    @builtins.property
    def odometer_speed(self):
        """Message field 'odometer_speed'."""
        return self._odometer_speed

    @odometer_speed.setter
    def odometer_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'odometer_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'odometer_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._odometer_speed = value

    @builtins.property
    def speed_over_ground(self):
        """Message field 'speed_over_ground'."""
        return self._speed_over_ground

    @speed_over_ground.setter
    def speed_over_ground(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_over_ground' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'speed_over_ground' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._speed_over_ground = value

    @builtins.property
    def course_over_ground(self):
        """Message field 'course_over_ground'."""
        return self._course_over_ground

    @course_over_ground.setter
    def course_over_ground(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'course_over_ground' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'course_over_ground' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._course_over_ground = value

    @builtins.property
    def nmea_status(self):
        """Message field 'nmea_status'."""
        return self._nmea_status

    @nmea_status.setter
    def nmea_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nmea_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'nmea_status' field must be an unsigned integer in [0, 255]"
        self._nmea_status = value

    @builtins.property
    def nmea_mode(self):
        """Message field 'nmea_mode'."""
        return self._nmea_mode

    @nmea_mode.setter
    def nmea_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nmea_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'nmea_mode' field must be an unsigned integer in [0, 255]"
        self._nmea_mode = value
