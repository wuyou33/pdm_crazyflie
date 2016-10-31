// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RC {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.status = 0;
    this.valid = false;
    this.axis = [];
    this.axis_function = [];
    this.swit = [];
    this.swit_function = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type RC
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [status]
    bufferInfo = _serializer.uint8(obj.status, bufferInfo);
    // Serialize message field [valid]
    bufferInfo = _serializer.bool(obj.valid, bufferInfo);
    // Serialize the length for message field [axis]
    bufferInfo = _serializer.uint32(obj.axis.length, bufferInfo);
    // Serialize message field [axis]
    obj.axis.forEach((val) => {
      bufferInfo = _serializer.float32(val, bufferInfo);
    });
    // Serialize the length for message field [axis_function]
    bufferInfo = _serializer.uint32(obj.axis_function.length, bufferInfo);
    // Serialize message field [axis_function]
    bufferInfo.buffer.push(obj.axis_function);
    bufferInfo.length += obj.axis_function.length;
    // Serialize the length for message field [swit]
    bufferInfo = _serializer.uint32(obj.swit.length, bufferInfo);
    // Serialize message field [swit]
    obj.swit.forEach((val) => {
      bufferInfo = _serializer.int8(val, bufferInfo);
    });
    // Serialize the length for message field [swit_function]
    bufferInfo = _serializer.uint32(obj.swit_function.length, bufferInfo);
    // Serialize message field [swit_function]
    bufferInfo.buffer.push(obj.swit_function);
    bufferInfo.length += obj.swit_function.length;
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type RC
    let tmp;
    let len;
    let data = new RC();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [status]
    tmp = _deserializer.uint8(buffer);
    data.status = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [valid]
    tmp = _deserializer.bool(buffer);
    data.valid = tmp.data;
    buffer = tmp.buffer;
    // Deserialize array length for message field [axis]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [axis]
    data.axis = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.float32(buffer);
      data.axis[i] = tmp.data;
      buffer = tmp.buffer;
    }
    // Deserialize array length for message field [axis_function]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [axis_function]
    data.axis_function = buffer.slice(0, len);
    buffer =  buffer.slice(len);
    // Deserialize array length for message field [swit]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [swit]
    data.swit = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.int8(buffer);
      data.swit[i] = tmp.data;
      buffer = tmp.buffer;
    }
    // Deserialize array length for message field [swit_function]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [swit_function]
    data.swit_function = buffer.slice(0, len);
    buffer =  buffer.slice(len);
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/RC';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2691c2fe8c5ab2323146bdd8dd2e449e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    uint8 ROLL = 1
    uint8 PITCH = 2
    uint8 YAW = 3
    uint8 STEER = 4
    uint8 HEIGHT = 5
    uint8 THRUST = 6
    uint8 BRAKE = 7
    
    uint8 status
    bool valid
    
    float32[] axis
    uint8[] axis_function
    
    int8[] swit
    uint8[] swit_function
    
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
RC.Constants = {
  ROLL: 1,
  PITCH: 2,
  YAW: 3,
  STEER: 4,
  HEIGHT: 5,
  THRUST: 6,
  BRAKE: 7,
}

module.exports = RC;
