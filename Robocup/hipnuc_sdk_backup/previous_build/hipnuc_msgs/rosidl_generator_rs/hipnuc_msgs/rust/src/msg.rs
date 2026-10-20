#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to hipnuc_msgs__msg__HipnucImu
/// One decoded HiPNUC measurement in SI units. `valid` is the bit mask from
/// hipnuc_sample.h (HIPNUC_VALID_*): read a field only when its bit is set.
/// Bits indicate field presence, not solution convergence or a valid GNSS fix.
/// Fields without a set bit are placeholders. INS and GNSS origins may differ.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HipnucImu {
    /// host ROS time after decoding, before publishing; body-axis frame_id
    pub header: std_msgs::msg::Header,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HipnucImu::default())
  }
}

impl rosidl_runtime_rs::Message for HipnucImu {
  type RmwMsg = super::msg::rmw::HipnucImu;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        source: msg.source,
        valid: msg.valid,
        node_id: msg.node_id,
        main_status: msg.main_status,
        gyro_bias_converged: msg.gyro_bias_converged,
        attitude_converged: msg.attitude_converged,
        magnetic_disturbance: msg.magnetic_disturbance,
        device_static: msg.device_static,
        magnetometer_aiding: msg.magnetometer_aiding,
        ins_status: msg.ins_status,
        acceleration: msg.acceleration,
        angular_velocity: msg.angular_velocity,
        magnetic_field: msg.magnetic_field,
        roll: msg.roll,
        pitch: msg.pitch,
        yaw: msg.yaw,
        heading: msg.heading,
        quaternion_wxyz: msg.quaternion_wxyz,
        inclination: msg.inclination,
        inclination_yaw: msg.inclination_yaw,
        device_time_us: msg.device_time_us,
        utc_valid: msg.utc_valid,
        utc_year: msg.utc_year,
        utc_month: msg.utc_month,
        utc_day: msg.utc_day,
        utc_hour: msg.utc_hour,
        utc_minute: msg.utc_minute,
        utc_second: msg.utc_second,
        utc_millisecond: msg.utc_millisecond,
        gps_week: msg.gps_week,
        gps_tow_ms: msg.gps_tow_ms,
        temperature: msg.temperature,
        pressure: msg.pressure,
        heave_surge_sway: msg.heave_surge_sway,
        heave_surge_sway_frequency: msg.heave_surge_sway_frequency,
        longitude: msg.longitude,
        latitude: msg.latitude,
        altitude_msl: msg.altitude_msl,
        gnss_longitude: msg.gnss_longitude,
        gnss_latitude: msg.gnss_latitude,
        gnss_altitude_msl: msg.gnss_altitude_msl,
        gnss_velocity_enu: msg.gnss_velocity_enu,
        geoid_separation: msg.geoid_separation,
        velocity_enu: msg.velocity_enu,
        acceleration_enu: msg.acceleration_enu,
        position_quality: msg.position_quality,
        position_satellites: msg.position_satellites,
        heading_quality: msg.heading_quality,
        heading_satellites: msg.heading_satellites,
        pdop: msg.pdop,
        hdop: msg.hdop,
        differential_age: msg.differential_age,
        odometer_speed: msg.odometer_speed,
        speed_over_ground: msg.speed_over_ground,
        course_over_ground: msg.course_over_ground,
        nmea_status: msg.nmea_status,
        nmea_mode: msg.nmea_mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      source: msg.source,
      valid: msg.valid,
      node_id: msg.node_id,
      main_status: msg.main_status,
      gyro_bias_converged: msg.gyro_bias_converged,
      attitude_converged: msg.attitude_converged,
      magnetic_disturbance: msg.magnetic_disturbance,
      device_static: msg.device_static,
      magnetometer_aiding: msg.magnetometer_aiding,
      ins_status: msg.ins_status,
        acceleration: msg.acceleration,
        angular_velocity: msg.angular_velocity,
        magnetic_field: msg.magnetic_field,
      roll: msg.roll,
      pitch: msg.pitch,
      yaw: msg.yaw,
      heading: msg.heading,
        quaternion_wxyz: msg.quaternion_wxyz,
        inclination: msg.inclination,
      inclination_yaw: msg.inclination_yaw,
      device_time_us: msg.device_time_us,
      utc_valid: msg.utc_valid,
      utc_year: msg.utc_year,
      utc_month: msg.utc_month,
      utc_day: msg.utc_day,
      utc_hour: msg.utc_hour,
      utc_minute: msg.utc_minute,
      utc_second: msg.utc_second,
      utc_millisecond: msg.utc_millisecond,
      gps_week: msg.gps_week,
      gps_tow_ms: msg.gps_tow_ms,
      temperature: msg.temperature,
      pressure: msg.pressure,
        heave_surge_sway: msg.heave_surge_sway,
        heave_surge_sway_frequency: msg.heave_surge_sway_frequency,
      longitude: msg.longitude,
      latitude: msg.latitude,
      altitude_msl: msg.altitude_msl,
      gnss_longitude: msg.gnss_longitude,
      gnss_latitude: msg.gnss_latitude,
      gnss_altitude_msl: msg.gnss_altitude_msl,
        gnss_velocity_enu: msg.gnss_velocity_enu,
      geoid_separation: msg.geoid_separation,
        velocity_enu: msg.velocity_enu,
        acceleration_enu: msg.acceleration_enu,
      position_quality: msg.position_quality,
      position_satellites: msg.position_satellites,
      heading_quality: msg.heading_quality,
      heading_satellites: msg.heading_satellites,
      pdop: msg.pdop,
      hdop: msg.hdop,
      differential_age: msg.differential_age,
      odometer_speed: msg.odometer_speed,
      speed_over_ground: msg.speed_over_ground,
      course_over_ground: msg.course_over_ground,
      nmea_status: msg.nmea_status,
      nmea_mode: msg.nmea_mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      source: msg.source,
      valid: msg.valid,
      node_id: msg.node_id,
      main_status: msg.main_status,
      gyro_bias_converged: msg.gyro_bias_converged,
      attitude_converged: msg.attitude_converged,
      magnetic_disturbance: msg.magnetic_disturbance,
      device_static: msg.device_static,
      magnetometer_aiding: msg.magnetometer_aiding,
      ins_status: msg.ins_status,
      acceleration: msg.acceleration,
      angular_velocity: msg.angular_velocity,
      magnetic_field: msg.magnetic_field,
      roll: msg.roll,
      pitch: msg.pitch,
      yaw: msg.yaw,
      heading: msg.heading,
      quaternion_wxyz: msg.quaternion_wxyz,
      inclination: msg.inclination,
      inclination_yaw: msg.inclination_yaw,
      device_time_us: msg.device_time_us,
      utc_valid: msg.utc_valid,
      utc_year: msg.utc_year,
      utc_month: msg.utc_month,
      utc_day: msg.utc_day,
      utc_hour: msg.utc_hour,
      utc_minute: msg.utc_minute,
      utc_second: msg.utc_second,
      utc_millisecond: msg.utc_millisecond,
      gps_week: msg.gps_week,
      gps_tow_ms: msg.gps_tow_ms,
      temperature: msg.temperature,
      pressure: msg.pressure,
      heave_surge_sway: msg.heave_surge_sway,
      heave_surge_sway_frequency: msg.heave_surge_sway_frequency,
      longitude: msg.longitude,
      latitude: msg.latitude,
      altitude_msl: msg.altitude_msl,
      gnss_longitude: msg.gnss_longitude,
      gnss_latitude: msg.gnss_latitude,
      gnss_altitude_msl: msg.gnss_altitude_msl,
      gnss_velocity_enu: msg.gnss_velocity_enu,
      geoid_separation: msg.geoid_separation,
      velocity_enu: msg.velocity_enu,
      acceleration_enu: msg.acceleration_enu,
      position_quality: msg.position_quality,
      position_satellites: msg.position_satellites,
      heading_quality: msg.heading_quality,
      heading_satellites: msg.heading_satellites,
      pdop: msg.pdop,
      hdop: msg.hdop,
      differential_age: msg.differential_age,
      odometer_speed: msg.odometer_speed,
      speed_over_ground: msg.speed_over_ground,
      course_over_ground: msg.course_over_ground,
      nmea_status: msg.nmea_status,
      nmea_mode: msg.nmea_mode,
    }
  }
}


