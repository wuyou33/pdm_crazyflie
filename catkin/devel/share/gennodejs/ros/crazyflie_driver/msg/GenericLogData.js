// Auto-generated. Do not edit!

// (in-package crazyflie_driver.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class GenericLogData {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.values = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type GenericLogData
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize the length for message field [values]
    bufferInfo = _serializer.uint32(obj.values.length, bufferInfo);
    // Serialize message field [values]
    obj.values.forEach((val) => {
      bufferInfo = _serializer.float64(val, bufferInfo);
    });
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type GenericLogData
    let tmp;
    let len;
    let data = new GenericLogData();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize array length for message field [values]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [values]
    data.values = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float64(buffer);
      data.values[i] = tmp.data;
      buffer = tmp.buffer;
    }
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'crazyflie_driver/GenericLogData';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bfa79f36371fee74e53d96afde61049b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float64[] values
    
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

module.exports = GenericLogData;
