// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RawImu {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.angular_velocity = new Array(3).fill(0);
    this.linear_acceleration = new Array(3).fill(0);
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type RawImu
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [angular_velocity]
    obj.angular_velocity.forEach((val) => {
      bufferInfo = _serializer.int16(val, bufferInfo);
    });
    // Serialize message field [linear_acceleration]
    obj.linear_acceleration.forEach((val) => {
      bufferInfo = _serializer.int16(val, bufferInfo);
    });
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type RawImu
    let tmp;
    let len;
    let data = new RawImu();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    len = 3;
    // Deserialize message field [angular_velocity]
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.int16(buffer);
      data.angular_velocity[i] = tmp.data;
      buffer = tmp.buffer;
    }
    len = 3;
    // Deserialize message field [linear_acceleration]
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.int16(buffer);
      data.linear_acceleration[i] = tmp.data;
      buffer = tmp.buffer;
    }
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/RawImu';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '398f651a68070a719c7938171d0fcc45';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int16[3] angular_velocity
    int16[3] linear_acceleration
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

};

module.exports = RawImu;
