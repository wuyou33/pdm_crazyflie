// Auto-generated. Do not edit!

// (in-package mpc.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class msgMPC {
  constructor() {
    this.phi = 0.0;
    this.theta = 0.0;
    this.psi = 0.0;
    this.thrust = 0.0;
    this.controlflag = 0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type msgMPC
    // Serialize message field [phi]
    bufferInfo = _serializer.float64(obj.phi, bufferInfo);
    // Serialize message field [theta]
    bufferInfo = _serializer.float64(obj.theta, bufferInfo);
    // Serialize message field [psi]
    bufferInfo = _serializer.float64(obj.psi, bufferInfo);
    // Serialize message field [thrust]
    bufferInfo = _serializer.float64(obj.thrust, bufferInfo);
    // Serialize message field [controlflag]
    bufferInfo = _serializer.int8(obj.controlflag, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type msgMPC
    let tmp;
    let len;
    let data = new msgMPC();
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
    // Deserialize message field [controlflag]
    tmp = _deserializer.int8(buffer);
    data.controlflag = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'mpc/msgMPC';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '71696ac0d5bc75bed22942029948a6b9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 phi
    float64 theta
    float64 psi
    float64 thrust
    
    int8 controlflag
    
    `;
  }

};

module.exports = msgMPC;
