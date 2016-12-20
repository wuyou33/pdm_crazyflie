// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Compass {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.magnetic_heading = 0.0;
    this.declination = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type Compass
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [magnetic_heading]
    bufferInfo = _serializer.float32(obj.magnetic_heading, bufferInfo);
    // Serialize message field [declination]
    bufferInfo = _serializer.float32(obj.declination, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type Compass
    let tmp;
    let len;
    let data = new Compass();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [magnetic_heading]
    tmp = _deserializer.float32(buffer);
    data.magnetic_heading = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [declination]
    tmp = _deserializer.float32(buffer);
    data.declination = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/Compass';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '69b5db73a2f794a5a815baf6b84a4be5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32 magnetic_heading
    float32 declination
    
    
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

module.exports = Compass;
