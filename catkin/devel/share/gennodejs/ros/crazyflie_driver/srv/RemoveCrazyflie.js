// Auto-generated. Do not edit!

// (in-package crazyflie_driver.srv)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class RemoveCrazyflieRequest {
  constructor() {
    this.uri = '';
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type RemoveCrazyflieRequest
    // Serialize message field [uri]
    bufferInfo = _serializer.string(obj.uri, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type RemoveCrazyflieRequest
    let tmp;
    let len;
    let data = new RemoveCrazyflieRequest();
    // Deserialize message field [uri]
    tmp = _deserializer.string(buffer);
    data.uri = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'crazyflie_driver/RemoveCrazyflieRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '636fe5e07550f026d28388e95c38a9f4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string uri
    
    `;
  }

};

class RemoveCrazyflieResponse {
  constructor() {
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type RemoveCrazyflieResponse
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type RemoveCrazyflieResponse
    let tmp;
    let len;
    let data = new RemoveCrazyflieResponse();
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'crazyflie_driver/RemoveCrazyflieResponse';
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
  Request: RemoveCrazyflieRequest,
  Response: RemoveCrazyflieResponse
};
