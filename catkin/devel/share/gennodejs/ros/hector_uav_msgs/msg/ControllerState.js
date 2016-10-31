// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ControllerState {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.source = 0;
    this.mode = 0;
    this.state = 0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type ControllerState
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [source]
    bufferInfo = _serializer.uint8(obj.source, bufferInfo);
    // Serialize message field [mode]
    bufferInfo = _serializer.uint8(obj.mode, bufferInfo);
    // Serialize message field [state]
    bufferInfo = _serializer.uint8(obj.state, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type ControllerState
    let tmp;
    let len;
    let data = new ControllerState();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [source]
    tmp = _deserializer.uint8(buffer);
    data.source = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [mode]
    tmp = _deserializer.uint8(buffer);
    data.mode = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [state]
    tmp = _deserializer.uint8(buffer);
    data.state = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/ControllerState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cf55b8af1d9e1de941887ee78e23079c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    uint8 source
    
    uint8 mode
    uint8 MOTORS = 1
    uint8 ATTITUDE = 2
    uint8 VELOCITY = 4
    uint8 POSITION = 8
    uint8 TURNRATE = 16
    uint8 HEADING = 32
    uint8 CLIMBRATE = 64
    uint8 HEIGHT = 128
    
    uint8 state
    uint8 MOTORS_RUNNING = 1
    uint8 FLYING = 2
    uint8 AIRBORNE = 4
    
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

// Constants for message
ControllerState.Constants = {
  MOTORS: 1,
  ATTITUDE: 2,
  VELOCITY: 4,
  POSITION: 8,
  TURNRATE: 16,
  HEADING: 32,
  CLIMBRATE: 64,
  HEIGHT: 128,
  MOTORS_RUNNING: 1,
  FLYING: 2,
  AIRBORNE: 4,
}

module.exports = ControllerState;
