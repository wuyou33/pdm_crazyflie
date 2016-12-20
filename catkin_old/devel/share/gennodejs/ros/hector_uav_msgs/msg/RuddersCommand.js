// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RuddersCommand {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.aileron = 0.0;
    this.elevator = 0.0;
    this.rudder = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type RuddersCommand
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [aileron]
    bufferInfo = _serializer.float32(obj.aileron, bufferInfo);
    // Serialize message field [elevator]
    bufferInfo = _serializer.float32(obj.elevator, bufferInfo);
    // Serialize message field [rudder]
    bufferInfo = _serializer.float32(obj.rudder, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type RuddersCommand
    let tmp;
    let len;
    let data = new RuddersCommand();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [aileron]
    tmp = _deserializer.float32(buffer);
    data.aileron = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [elevator]
    tmp = _deserializer.float32(buffer);
    data.elevator = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [rudder]
    tmp = _deserializer.float32(buffer);
    data.rudder = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/RuddersCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2e136cb8cfffc2233e404b320c27bca6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32 aileron
    float32 elevator
    float32 rudder
    
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

module.exports = RuddersCommand;
