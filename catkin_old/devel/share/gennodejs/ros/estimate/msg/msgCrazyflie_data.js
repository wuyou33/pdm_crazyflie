// Auto-generated. Do not edit!

// (in-package estimate.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class msgCrazyflie_data {
  constructor() {
    this.imu_time_msg = 0.0;
    this.imu_angx_msg = 0.0;
    this.imu_angy_msg = 0.0;
    this.imu_angz_msg = 0.0;
    this.imu_linx_msg = 0.0;
    this.imu_liny_msg = 0.0;
    this.imu_linz_msg = 0.0;
    this.vrpn_time_msg = 0.0;
    this.vrpn_posx_msg = 0.0;
    this.vrpn_posy_msg = 0.0;
    this.vrpn_posz_msg = 0.0;
    this.vrpn_velx_msg = 0.0;
    this.vrpn_vely_msg = 0.0;
    this.vrpn_velz_msg = 0.0;
    this.vrpn_linx_msg = 0.0;
    this.vrpn_liny_msg = 0.0;
    this.vrpn_linz_msg = 0.0;
    this.vrpn_orix_msg = 0.0;
    this.vrpn_oriy_msg = 0.0;
    this.vrpn_oriz_msg = 0.0;
    this.vrpn_oriw_msg = 0.0;
    this.vrpn_roll_msg = 0.0;
    this.vrpn_pitch_msg = 0.0;
    this.vrpn_yaw_msg = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type msgCrazyflie_data
    // Serialize message field [imu_time_msg]
    bufferInfo = _serializer.float64(obj.imu_time_msg, bufferInfo);
    // Serialize message field [imu_angx_msg]
    bufferInfo = _serializer.float64(obj.imu_angx_msg, bufferInfo);
    // Serialize message field [imu_angy_msg]
    bufferInfo = _serializer.float64(obj.imu_angy_msg, bufferInfo);
    // Serialize message field [imu_angz_msg]
    bufferInfo = _serializer.float64(obj.imu_angz_msg, bufferInfo);
    // Serialize message field [imu_linx_msg]
    bufferInfo = _serializer.float64(obj.imu_linx_msg, bufferInfo);
    // Serialize message field [imu_liny_msg]
    bufferInfo = _serializer.float64(obj.imu_liny_msg, bufferInfo);
    // Serialize message field [imu_linz_msg]
    bufferInfo = _serializer.float64(obj.imu_linz_msg, bufferInfo);
    // Serialize message field [vrpn_time_msg]
    bufferInfo = _serializer.float64(obj.vrpn_time_msg, bufferInfo);
    // Serialize message field [vrpn_posx_msg]
    bufferInfo = _serializer.float64(obj.vrpn_posx_msg, bufferInfo);
    // Serialize message field [vrpn_posy_msg]
    bufferInfo = _serializer.float64(obj.vrpn_posy_msg, bufferInfo);
    // Serialize message field [vrpn_posz_msg]
    bufferInfo = _serializer.float64(obj.vrpn_posz_msg, bufferInfo);
    // Serialize message field [vrpn_velx_msg]
    bufferInfo = _serializer.float64(obj.vrpn_velx_msg, bufferInfo);
    // Serialize message field [vrpn_vely_msg]
    bufferInfo = _serializer.float64(obj.vrpn_vely_msg, bufferInfo);
    // Serialize message field [vrpn_velz_msg]
    bufferInfo = _serializer.float64(obj.vrpn_velz_msg, bufferInfo);
    // Serialize message field [vrpn_linx_msg]
    bufferInfo = _serializer.float64(obj.vrpn_linx_msg, bufferInfo);
    // Serialize message field [vrpn_liny_msg]
    bufferInfo = _serializer.float64(obj.vrpn_liny_msg, bufferInfo);
    // Serialize message field [vrpn_linz_msg]
    bufferInfo = _serializer.float64(obj.vrpn_linz_msg, bufferInfo);
    // Serialize message field [vrpn_orix_msg]
    bufferInfo = _serializer.float64(obj.vrpn_orix_msg, bufferInfo);
    // Serialize message field [vrpn_oriy_msg]
    bufferInfo = _serializer.float64(obj.vrpn_oriy_msg, bufferInfo);
    // Serialize message field [vrpn_oriz_msg]
    bufferInfo = _serializer.float64(obj.vrpn_oriz_msg, bufferInfo);
    // Serialize message field [vrpn_oriw_msg]
    bufferInfo = _serializer.float64(obj.vrpn_oriw_msg, bufferInfo);
    // Serialize message field [vrpn_roll_msg]
    bufferInfo = _serializer.float64(obj.vrpn_roll_msg, bufferInfo);
    // Serialize message field [vrpn_pitch_msg]
    bufferInfo = _serializer.float64(obj.vrpn_pitch_msg, bufferInfo);
    // Serialize message field [vrpn_yaw_msg]
    bufferInfo = _serializer.float64(obj.vrpn_yaw_msg, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type msgCrazyflie_data
    let tmp;
    let len;
    let data = new msgCrazyflie_data();
    // Deserialize message field [imu_time_msg]
    tmp = _deserializer.float64(buffer);
    data.imu_time_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [imu_angx_msg]
    tmp = _deserializer.float64(buffer);
    data.imu_angx_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [imu_angy_msg]
    tmp = _deserializer.float64(buffer);
    data.imu_angy_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [imu_angz_msg]
    tmp = _deserializer.float64(buffer);
    data.imu_angz_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [imu_linx_msg]
    tmp = _deserializer.float64(buffer);
    data.imu_linx_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [imu_liny_msg]
    tmp = _deserializer.float64(buffer);
    data.imu_liny_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [imu_linz_msg]
    tmp = _deserializer.float64(buffer);
    data.imu_linz_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_time_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_time_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_posx_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_posx_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_posy_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_posy_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_posz_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_posz_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_velx_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_velx_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_vely_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_vely_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_velz_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_velz_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_linx_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_linx_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_liny_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_liny_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_linz_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_linz_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_orix_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_orix_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_oriy_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_oriy_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_oriz_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_oriz_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_oriw_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_oriw_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_roll_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_roll_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_pitch_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_pitch_msg = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_yaw_msg]
    tmp = _deserializer.float64(buffer);
    data.vrpn_yaw_msg = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'estimate/msgCrazyflie_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ffa6642ffc39e98623b6552d0c85332d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 imu_time_msg
    float64 imu_angx_msg
    float64 imu_angy_msg
    float64 imu_angz_msg
    float64 imu_linx_msg
    float64 imu_liny_msg
    float64 imu_linz_msg
    float64 vrpn_time_msg
    float64 vrpn_posx_msg
    float64 vrpn_posy_msg
    float64 vrpn_posz_msg
    float64 vrpn_velx_msg
    float64 vrpn_vely_msg
    float64 vrpn_velz_msg
    float64 vrpn_linx_msg
    float64 vrpn_liny_msg
    float64 vrpn_linz_msg
    float64 vrpn_orix_msg
    float64 vrpn_oriy_msg
    float64 vrpn_oriz_msg
    float64 vrpn_oriw_msg
    float64 vrpn_roll_msg
    float64 vrpn_pitch_msg
    float64 vrpn_yaw_msg
    
    
    `;
  }

};

module.exports = msgCrazyflie_data;
