// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class YawrateCommand {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.turnrate = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type YawrateCommand
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [turnrate]
    bufferInfo = _serializer.float32(obj.turnrate, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type YawrateCommand
    let tmp;
    let len;
    let data = new YawrateCommand();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [turnrate]
    tmp = _deserializer.float32(buffer);
    data.turnrate = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/YawrateCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd8d2a0a1e3daa0fc410bf30a154fa6b6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32 turnrate
    
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

module.exports = YawrateCommand;
