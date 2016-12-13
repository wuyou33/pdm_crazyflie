// Auto-generated. Do not edit!

// (in-package mpc.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class msgMPC_Data {
  constructor() {
    this.xPos = 0.0;
    this.yPos = 0.0;
    this.zPos = 0.0;
    this.controlFlag = 0;
    this.xPosRef = 0.0;
    this.yPosRef = 0.0;
    this.zPosRef = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type msgMPC_Data
    // Serialize message field [xPos]
    bufferInfo = _serializer.float64(obj.xPos, bufferInfo);
    // Serialize message field [yPos]
    bufferInfo = _serializer.float64(obj.yPos, bufferInfo);
    // Serialize message field [zPos]
    bufferInfo = _serializer.float64(obj.zPos, bufferInfo);
    // Serialize message field [controlFlag]
    bufferInfo = _serializer.int8(obj.controlFlag, bufferInfo);
    // Serialize message field [xPosRef]
    bufferInfo = _serializer.float64(obj.xPosRef, bufferInfo);
    // Serialize message field [yPosRef]
    bufferInfo = _serializer.float64(obj.yPosRef, bufferInfo);
    // Serialize message field [zPosRef]
    bufferInfo = _serializer.float64(obj.zPosRef, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type msgMPC_Data
    let tmp;
    let len;
    let data = new msgMPC_Data();
    // Deserialize message field [xPos]
    tmp = _deserializer.float64(buffer);
    data.xPos = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [yPos]
    tmp = _deserializer.float64(buffer);
    data.yPos = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [zPos]
    tmp = _deserializer.float64(buffer);
    data.zPos = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [controlFlag]
    tmp = _deserializer.int8(buffer);
    data.controlFlag = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [xPosRef]
    tmp = _deserializer.float64(buffer);
    data.xPosRef = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [yPosRef]
    tmp = _deserializer.float64(buffer);
    data.yPosRef = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [zPosRef]
    tmp = _deserializer.float64(buffer);
    data.zPosRef = tmp.data;
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
    return '6bc2414c1027b318ae658fa2e1750a8e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 xPos
    float64 yPos
    float64 zPos
    
    int8   controlFlag
    
    float64 xPosRef
    float64 yPosRef
    float64 zPosRef
    
    `;
  }

};

module.exports = msgMPC_Data;
