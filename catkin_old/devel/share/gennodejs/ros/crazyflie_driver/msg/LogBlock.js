// Auto-generated. Do not edit!

// (in-package crazyflie_driver.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class LogBlock {
  constructor() {
    this.topic_name = '';
    this.frequency = 0;
    this.variables = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type LogBlock
    // Serialize message field [topic_name]
    bufferInfo = _serializer.string(obj.topic_name, bufferInfo);
    // Serialize message field [frequency]
    bufferInfo = _serializer.int16(obj.frequency, bufferInfo);
    // Serialize the length for message field [variables]
    bufferInfo = _serializer.uint32(obj.variables.length, bufferInfo);
    // Serialize message field [variables]
    obj.variables.forEach((val) => {
      bufferInfo = _serializer.string(val, bufferInfo);
    });
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type LogBlock
    let tmp;
    let len;
    let data = new LogBlock();
    // Deserialize message field [topic_name]
    tmp = _deserializer.string(buffer);
    data.topic_name = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [frequency]
    tmp = _deserializer.int16(buffer);
    data.frequency = tmp.data;
    buffer = tmp.buffer;
    // Deserialize array length for message field [variables]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [variables]
    data.variables = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.string(buffer);
      data.variables[i] = tmp.data;
      buffer = tmp.buffer;
    }
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'crazyflie_driver/LogBlock';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd9325f33ff3a1ffc6b6c0323a9f9b181';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string topic_name
    int16 frequency
    string[] variables
    
    `;
  }

};

module.exports = LogBlock;
