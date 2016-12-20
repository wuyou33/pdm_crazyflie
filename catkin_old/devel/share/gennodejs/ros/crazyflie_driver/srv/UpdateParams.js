// Auto-generated. Do not edit!

// (in-package crazyflie_driver.srv)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class UpdateParamsRequest {
  constructor() {
    this.params = [];
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type UpdateParamsRequest
    // Serialize the length for message field [params]
    bufferInfo = _serializer.uint32(obj.params.length, bufferInfo);
    // Serialize message field [params]
    obj.params.forEach((val) => {
      bufferInfo = _serializer.string(val, bufferInfo);
    });
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type UpdateParamsRequest
    let tmp;
    let len;
    let data = new UpdateParamsRequest();
    // Deserialize array length for message field [params]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [params]
    data.params = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = _deserializer.string(buffer);
      data.params[i] = tmp.data;
      buffer = tmp.buffer;
    }
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'crazyflie_driver/UpdateParamsRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '279e0627eb574ffe8968384218434f5f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string[] params
    
    `;
  }

};

class UpdateParamsResponse {
  constructor() {
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type UpdateParamsResponse
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type UpdateParamsResponse
    let tmp;
    let len;
    let data = new UpdateParamsResponse();
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'crazyflie_driver/UpdateParamsResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    `;
  }

};

module.exports = {
  Request: UpdateParamsRequest,
  Response: UpdateParamsResponse
};
