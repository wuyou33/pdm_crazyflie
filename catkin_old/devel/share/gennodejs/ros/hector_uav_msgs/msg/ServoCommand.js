// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ServoCommand {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.value = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type ServoCommand
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize the length for message field [value]
    bufferInfo = _serializer.uint32(obj.value.length, bufferInfo);
    // Serialize message field [value]
    obj.value.forEach((val) => {
      bufferInfo = _serializer.uint16(val, bufferInfo);
    });
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type ServoCommand
    let tmp;
    let len;
    let data = new ServoCommand();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize array length for message field [value]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [value]
    data.value = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.uint16(buffer);
      data.value[i] = tmp.data;
      buffer = tmp.buffer;
    }
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_uav_msgs/ServoCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd60ef35d4e3412dc6686b189be2523d0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    uint16[] value
    
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

module.exports = ServoCommand;
