// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class MotorPWM {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.pwm = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type MotorPWM
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize the length for message field [pwm]
    bufferInfo = _serializer.uint32(obj.pwm.length, bufferInfo);
    // Serialize message field [pwm]
    bufferInfo.buffer.push(obj.pwm);
    bufferInfo.length += obj.pwm.length;
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type MotorPWM
    let tmp;
    let len;
    let data = new MotorPWM();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize array length for message field [pwm]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [pwm]
    data.pwm = buffer.slice(0, len);
    buffer =  buffer.slice(len);
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/MotorPWM';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '42f78dd80f99e0208248b8a257b8a645';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    uint8[] pwm
    
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

module.exports = MotorPWM;
