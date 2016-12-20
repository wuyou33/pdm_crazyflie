// Auto-generated. Do not edit!

// (in-package hector_quadrotor_teleop.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class adv_cmd_vel {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.linear = new geometry_msgs.msg.Vector3();
    this.angular = new geometry_msgs.msg.Vector3();
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type adv_cmd_vel
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [linear]
    bufferInfo = geometry_msgs.msg.Vector3.serialize(obj.linear, bufferInfo);
    // Serialize message field [angular]
    bufferInfo = geometry_msgs.msg.Vector3.serialize(obj.angular, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type adv_cmd_vel
    let tmp;
    let len;
    let data = new adv_cmd_vel();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [linear]
    tmp = geometry_msgs.msg.Vector3.deserialize(buffer);
    data.linear = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [angular]
    tmp = geometry_msgs.msg.Vector3.deserialize(buffer);
    data.angular = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'hector_quadrotor_teleop/adv_cmd_vel';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '09119d3b0067bd05b1a6696c168cebb3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    geometry_msgs/Vector3 linear
    geometry_msgs/Vector3 angular
    
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
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    `;
  }

};

module.exports = adv_cmd_vel;
