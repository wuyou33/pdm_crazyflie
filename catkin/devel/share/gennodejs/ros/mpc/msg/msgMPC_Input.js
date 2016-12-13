// Auto-generated. Do not edit!

// (in-package mpc.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class msgMPC_Input {
  constructor() {
    this.rollPhi = 0.0;
    this.thetaPitch = 0.0;
    this.psiYawRate = 0.0;
    this.thrust = 0.0;
    this.controlFlag = 0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type msgMPC_Input
    // Serialize message field [rollPhi]
    bufferInfo = _serializer.float64(obj.rollPhi, bufferInfo);
    // Serialize message field [thetaPitch]
    bufferInfo = _serializer.float64(obj.thetaPitch, bufferInfo);
    // Serialize message field [psiYawRate]
    bufferInfo = _serializer.float64(obj.psiYawRate, bufferInfo);
    // Serialize message field [thrust]
    bufferInfo = _serializer.float64(obj.thrust, bufferInfo);
    // Serialize message field [controlFlag]
    bufferInfo = _serializer.int8(obj.controlFlag, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type msgMPC_Input
    let tmp;
    let len;
    let data = new msgMPC_Input();
    // Deserialize message field [rollPhi]
    tmp = _deserializer.float64(buffer);
    data.rollPhi = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [thetaPitch]
    tmp = _deserializer.float64(buffer);
    data.thetaPitch = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [psiYawRate]
    tmp = _deserializer.float64(buffer);
    data.psiYawRate = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [thrust]
    tmp = _deserializer.float64(buffer);
    data.thrust = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [controlFlag]
    tmp = _deserializer.int8(buffer);
    data.controlFlag = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'mpc/msgMPC_Input';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '64731ea8c92ca2a1540116905352cf9e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 rollPhi
    float64 thetaPitch
    float64 psiYawRate
    float64 thrust
    
    int8 controlFlag
    
    `;
  }

};

module.exports = msgMPC_Input;
