// Auto-generated. Do not edit!

// (in-package mpc.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class msgMPC_Data {
  constructor() {
    this.xpos = 0.0;
    this.ypos = 0.0;
    this.zpos = 0.0;
    this.sw = 0;
    this.xpos_ref = 0.0;
    this.ypos_ref = 0.0;
    this.zpos_ref = 0.0;
    this.xvel = 0.0;
    this.yvel = 0.0;
    this.zvel = 0.0;
    this.phi = 0.0;
    this.theta = 0.0;
    this.psi = 0.0;
    this.thrust = 0.0;
    this.xpos_obs = 0.0;
    this.ypos_obs = 0.0;
    this.zpos_obs = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type msgMPC_Data
    // Serialize message field [xpos]
    bufferInfo = _serializer.float64(obj.xpos, bufferInfo);
    // Serialize message field [ypos]
    bufferInfo = _serializer.float64(obj.ypos, bufferInfo);
    // Serialize message field [zpos]
    bufferInfo = _serializer.float64(obj.zpos, bufferInfo);
    // Serialize message field [sw]
    bufferInfo = _serializer.int16(obj.sw, bufferInfo);
    // Serialize message field [xpos_ref]
    bufferInfo = _serializer.float64(obj.xpos_ref, bufferInfo);
    // Serialize message field [ypos_ref]
    bufferInfo = _serializer.float64(obj.ypos_ref, bufferInfo);
    // Serialize message field [zpos_ref]
    bufferInfo = _serializer.float64(obj.zpos_ref, bufferInfo);
    // Serialize message field [xvel]
    bufferInfo = _serializer.float64(obj.xvel, bufferInfo);
    // Serialize message field [yvel]
    bufferInfo = _serializer.float64(obj.yvel, bufferInfo);
    // Serialize message field [zvel]
    bufferInfo = _serializer.float64(obj.zvel, bufferInfo);
    // Serialize message field [phi]
    bufferInfo = _serializer.float64(obj.phi, bufferInfo);
    // Serialize message field [theta]
    bufferInfo = _serializer.float64(obj.theta, bufferInfo);
    // Serialize message field [psi]
    bufferInfo = _serializer.float64(obj.psi, bufferInfo);
    // Serialize message field [thrust]
    bufferInfo = _serializer.float64(obj.thrust, bufferInfo);
    // Serialize message field [xpos_obs]
    bufferInfo = _serializer.float64(obj.xpos_obs, bufferInfo);
    // Serialize message field [ypos_obs]
    bufferInfo = _serializer.float64(obj.ypos_obs, bufferInfo);
    // Serialize message field [zpos_obs]
    bufferInfo = _serializer.float64(obj.zpos_obs, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type msgMPC_Data
    let tmp;
    let len;
    let data = new msgMPC_Data();
    // Deserialize message field [xpos]
    tmp = _deserializer.float64(buffer);
    data.xpos = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [ypos]
    tmp = _deserializer.float64(buffer);
    data.ypos = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [zpos]
    tmp = _deserializer.float64(buffer);
    data.zpos = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [sw]
    tmp = _deserializer.int16(buffer);
    data.sw = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [xpos_ref]
    tmp = _deserializer.float64(buffer);
    data.xpos_ref = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [ypos_ref]
    tmp = _deserializer.float64(buffer);
    data.ypos_ref = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [zpos_ref]
    tmp = _deserializer.float64(buffer);
    data.zpos_ref = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [xvel]
    tmp = _deserializer.float64(buffer);
    data.xvel = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [yvel]
    tmp = _deserializer.float64(buffer);
    data.yvel = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [zvel]
    tmp = _deserializer.float64(buffer);
    data.zvel = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [phi]
    tmp = _deserializer.float64(buffer);
    data.phi = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [theta]
    tmp = _deserializer.float64(buffer);
    data.theta = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [psi]
    tmp = _deserializer.float64(buffer);
    data.psi = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [thrust]
    tmp = _deserializer.float64(buffer);
    data.thrust = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [xpos_obs]
    tmp = _deserializer.float64(buffer);
    data.xpos_obs = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [ypos_obs]
    tmp = _deserializer.float64(buffer);
    data.ypos_obs = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [zpos_obs]
    tmp = _deserializer.float64(buffer);
    data.zpos_obs = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'mpc/msgMPC_Data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a9b89a1a4b30c0f87ae7593794fcf97f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 xpos
    float64 ypos
    float64 zpos
    
    int16   sw
    
    float64 xpos_ref
    float64 ypos_ref
    float64 zpos_ref
    
    float64 xvel
    float64 yvel
    float64 zvel
    
    float64 phi
    float64 theta
    float64 psi
    float64 thrust
    
    float64 xpos_obs
    float64 ypos_obs
    float64 zpos_obs
    
    `;
  }

};

module.exports = msgMPC_Data;
