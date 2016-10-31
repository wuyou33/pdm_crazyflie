// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class MotorCommand {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.force = [];
    this.torque = [];
    this.frequency = [];
    this.voltage = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type MotorCommand
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize the length for message field [force]
    bufferInfo = _serializer.uint32(obj.force.length, bufferInfo);
    // Serialize message field [force]
    obj.force.forEach((val) => {
      bufferInfo = _serializer.float32(val, bufferInfo);
    });
    // Serialize the length for message field [torque]
    bufferInfo = _serializer.uint32(obj.torque.length, bufferInfo);
    // Serialize message field [torque]
    obj.torque.forEach((val) => {
      bufferInfo = _serializer.float32(val, bufferInfo);
    });
    // Serialize the length for message field [frequency]
    bufferInfo = _serializer.uint32(obj.frequency.length, bufferInfo);
    // Serialize message field [frequency]
    obj.frequency.forEach((val) => {
      bufferInfo = _serializer.float32(val, bufferInfo);
    });
    // Serialize the length for message field [voltage]
    bufferInfo = _serializer.uint32(obj.voltage.length, bufferInfo);
    // Serialize message field [voltage]
    obj.voltage.forEach((val) => {
      bufferInfo = _serializer.float32(val, bufferInfo);
    });
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type MotorCommand
    let tmp;
    let len;
    let data = new MotorCommand();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize array length for message field [force]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [force]
    data.force = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float32(buffer);
      data.force[i] = tmp.data;
      buffer = tmp.buffer;
    }
    // Deserialize array length for message field [torque]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [torque]
    data.torque = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float32(buffer);
      data.torque[i] = tmp.data;
      buffer = tmp.buffer;
    }
    // Deserialize array length for message field [frequency]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [frequency]
    data.frequency = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float32(buffer);
      data.frequency[i] = tmp.data;
      buffer = tmp.buffer;
    }
    // Deserialize array length for message field [voltage]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [voltage]
    data.voltage = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float32(buffer);
      data.voltage[i] = tmp.data;
      buffer = tmp.buffer;
    }
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/MotorCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ccd4d4d4606731d1c73409e9bfa55808';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32[] force
    float32[] torque
    float32[] frequency
    float32[] voltage
    
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

module.exports = MotorCommand;
