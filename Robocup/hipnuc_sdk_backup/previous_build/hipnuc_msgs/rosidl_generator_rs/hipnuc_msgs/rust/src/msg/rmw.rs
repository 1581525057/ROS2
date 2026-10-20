#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "hipnuc_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__hipnuc_msgs__msg__HipnucImu() -> *const std::ffi::c_void;
}

#[link(name = "hipnuc_msgs__rosidl_generator_c")]
extern "C" {
    fn hipnuc_msgs__msg__HipnucImu__init(msg: *mut HipnucImu) -> bool;
    fn hipnuc_msgs__msg__HipnucImu__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HipnucImu>, size: usize) -> bool;
    fn hipnuc_msgs__msg__HipnucImu__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HipnucImu>);
    fn hipnuc_msgs__msg__HipnucImu__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HipnucImu>, out_seq: *mut rosidl_runtime_rs::Sequence<HipnucImu>) -> bool;
}

// Corresponds to hipnuc_msgs__msg__HipnucImu
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// One decoded HiPNUC measurement in SI units. `valid` is the bit mask from
/// hipnuc_sample.h (HIPNUC_VALID_*): read a field only when its bit is set.
/// Bits indicate field presence, not solution convergence or a valid GNSS fix.
/// Fields without a set bit are placeholders. INS and GNSS origins may differ.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HipnucImu {
    /// host ROS time after decoding, before publishing; body-axis frame_id
    pub header: std_msgs::msg::rmw::Header,

    /// 1 HI91, 2 HI81, 3 HI83, 4 GGA, 5 RMC, 6 J1939, 7 CANFD83
    pub source: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub valid: u64,

    /// CAN source address or HI83 node id
    pub node_id: u8,

    /// raw status bits (a set WB_CONV/ATT_CONV bit means NOT converged)
    pub main_status: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gyro_bias_converged: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub attitude_converged: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub magnetic_disturbance: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub device_static: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub magnetometer_aiding: bool,

    /// 0 invalid, 1 aligning, 3 navigating, 6 dead reckoning
    pub ins_status: u8,

    /// m/s^2, body axes, specific force
    pub acceleration: [f32; 3],

    /// rad/s, body axes
    pub angular_velocity: [f32; 3],

    /// T
    pub magnetic_field: [f32; 3],

    /// rad, device Euler convention
    pub roll: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pitch: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub yaw: f32,

    /// rad, clockwise from north (INS / J1939)
    pub heading: f32,

    /// body to navigation
    pub quaternion_wxyz: [f32; 4],

    /// rad
    pub inclination: [f32; 2],

    /// rad, HI83 inclinometer yaw, VALID_INCLINATION_YAW
    pub inclination_yaw: f32,

    /// HI91: 32-bit ms count, wraps (UTC time of day once synchronized)
    pub device_time_us: u64,

    /// VALID_UTC, date and time; VALID_UTC_TIME_OF_DAY alone leaves the date zero
    pub utc_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub utc_year: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub utc_month: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub utc_day: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub utc_hour: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub utc_minute: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub utc_second: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub utc_millisecond: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gps_week: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gps_tow_ms: u32,

    /// degC
    pub temperature: f32,

    /// Pa; raw product field, validity/freshness not guaranteed
    pub pressure: f32,

    /// m, VALID_HEAVE
    pub heave_surge_sway: [f32; 3],

    /// Hz, VALID_HEAVE_FREQUENCY
    pub heave_surge_sway_frequency: [f32; 3],

    /// INS origin, deg WGS84, VALID_POSITION
    pub longitude: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub latitude: f64,

    /// INS origin, m MSL, VALID_ALTITUDE
    pub altitude_msl: f64,

    /// GNSS antenna, deg WGS84, VALID_GNSS_POSITION
    pub gnss_longitude: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gnss_latitude: f64,

    /// GNSS antenna, m MSL, VALID_GNSS_ALTITUDE
    pub gnss_altitude_msl: f64,

    /// m/s, VALID_GNSS_VELOCITY
    pub gnss_velocity_enu: [f32; 3],

    /// GNSS geoid separation, m
    pub geoid_separation: f32,

    /// m/s
    pub velocity_enu: [f32; 3],

    /// m/s^2
    pub acceleration_enu: [f32; 3],

    /// GGA quality: 0 none, 1 GNSS, 2 DGNSS, 4 RTK fixed, 5 RTK float
    pub position_quality: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position_satellites: u8,

    /// 4 = fixed; only then is a dual-antenna heading valid
    pub heading_quality: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub heading_satellites: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pdop: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hdop: f32,

    /// s
    pub differential_age: f32,

    /// m/s
    pub odometer_speed: f32,

    /// m/s, VALID_SOG
    pub speed_over_ground: f32,

    /// rad clockwise from north, VALID_COG
    pub course_over_ground: f32,

    /// ASCII A/V, VALID_NMEA_STATUS
    pub nmea_status: u8,

    /// raw ASCII RMC mode, VALID_NMEA_MODE
    pub nmea_mode: u8,

}

impl HipnucImu {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_STATUS: u64 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_INS_STATUS: u64 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_ACC: u64 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_GYR: u64 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_MAG: u64 = 16;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_ROLL_PITCH: u64 = 32;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_HEADING: u64 = 64;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_QUAT: u64 = 128;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_DEVICE_TIME: u64 = 256;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_UTC: u64 = 512;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_GPS_TIME: u64 = 1024;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_PRESSURE: u64 = 2048;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_TEMPERATURE: u64 = 4096;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_INCLINATION: u64 = 8192;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_HEAVE: u64 = 16384;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_POSITION: u64 = 32768;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_VELOCITY_ENU: u64 = 65536;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_ACC_ENU: u64 = 131072;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_POSITION_QUALITY: u64 = 262144;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_PDOP: u64 = 524288;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_DIFF_AGE: u64 = 1048576;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_UNDULATION: u64 = 2097152;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_ODOMETER: u64 = 4194304;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_GNSS_POSITION: u64 = 8388608;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_GNSS_VELOCITY: u64 = 16777216;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_SOG: u64 = 33554432;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_NODE_ID: u64 = 67108864;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_YAW: u64 = 134217728;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_ALTITUDE: u64 = 268435456;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_HEADING_QUALITY: u64 = 536870912;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_POSITION_SATELLITES: u64 = 1073741824;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_HEADING_SATELLITES: u64 = 2147483648;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_HDOP: u64 = 4294967296;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_HEAVE_FREQUENCY: u64 = 8589934592;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_GNSS_ALTITUDE: u64 = 17179869184;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_COG: u64 = 34359738368;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_NMEA_STATUS: u64 = 68719476736;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_NMEA_MODE: u64 = 137438953472;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_UTC_TIME_OF_DAY: u64 = 274877906944;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID_INCLINATION_YAW: u64 = 549755813888;

}


impl Default for HipnucImu {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !hipnuc_msgs__msg__HipnucImu__init(&mut msg as *mut _) {
        panic!("Call to hipnuc_msgs__msg__HipnucImu__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HipnucImu {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { hipnuc_msgs__msg__HipnucImu__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { hipnuc_msgs__msg__HipnucImu__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { hipnuc_msgs__msg__HipnucImu__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HipnucImu {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HipnucImu where Self: Sized {
  const TYPE_NAME: &'static str = "hipnuc_msgs/msg/HipnucImu";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__hipnuc_msgs__msg__HipnucImu() }
  }
}


