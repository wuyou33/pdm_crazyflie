// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Altimeter {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.altitude = 0.0;
    this.pressure = 0.0;
    this.qnh = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type Altimeter
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [altitude]
    bufferInfo = _serializer.float32(obj.altitude, bufferInfo);
    // Serialize message field [pressure]
    bufferInfo = _serializer.float32(obj.pressure, bufferInfo);
    // Serialize message field [qnh]
    bufferInfo = _serializer.float32(obj.qnh, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type Altimeter
    let tmp;
    let len;
    let data = new Altimeter();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [altitude]
    tmp = _deserializer.float32(buffer);
    data.altitude = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [pressure]
    tmp = _deserializer.float32(buffer);
    data.pressure = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [qnh]
    tmp = _deserializer.float32(buffer);
    data.qnh = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/Altimeter';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c785451e2f67a76b902818138e9b53c6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32 altitude
    float32 pressure
    float32 qnh
    
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

module.exports = Altimeter;
