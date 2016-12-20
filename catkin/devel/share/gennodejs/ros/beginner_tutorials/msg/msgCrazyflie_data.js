// Auto-generated. Do not edit!

// (in-package beginner_tutorials.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class msgCrazyflie_data {
  constructor() {
    this.imu_msg = [];
    this.vrpn_msg = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type msgCrazyflie_data
    // Serialize the length for message field [imu_msg]
    bufferInfo = _serializer.uint32(obj.imu_msg.length, bufferInfo);
    // Serialize message field [imu_msg]
    obj.imu_msg.forEach((val) => {
      bufferInfo = _serializer.float32(val, bufferInfo);
    });
    // Serialize the length for message field [vrpn_msg]
    bufferInfo = _serializer.uint32(obj.vrpn_msg.length, bufferInfo);
    // Serialize message field [vrpn_msg]
    obj.vrpn_msg.forEach((val) => {
      bufferInfo = _serializer.float32(val, bufferInfo);
    });
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type msgCrazyflie_data
    let tmp;
    let len;
    let data = new msgCrazyflie_data();
    // Deserialize array length for message field [imu_msg]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [imu_msg]
    data.imu_msg = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float32(buffer);
      data.imu_msg[i] = tmp.data;
      buffer = tmp.buffer;
    }
    // Deserialize array length for message field [vrpn_msg]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [vrpn_msg]
    data.vrpn_msg = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float32(buffer);
      data.vrpn_msg[i] = tmp.data;
      buffer = tmp.buffer;
    }
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'beginner_tutorials/msgCrazyflie_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6af109ec49fecf2fd5c4a5b152fa11fb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[] imu_msg
    float32[] vrpn_msg
    
    `;
  }

};

module.exports = msgCrazyflie_data;
