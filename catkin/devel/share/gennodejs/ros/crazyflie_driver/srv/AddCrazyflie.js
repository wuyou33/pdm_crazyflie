// Auto-generated. Do not edit!

// (in-package crazyflie_driver.srv)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class AddCrazyflieRequest {
  constructor() {
    this.uri = '';
    this.tf_prefix = '';
    this.roll_trim = 0.0;
    this.pitch_trim = 0.0;
    this.enable_logging = false;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type AddCrazyflieRequest
    // Serialize message field [uri]
    bufferInfo = _serializer.string(obj.uri, bufferInfo);
    // Serialize message field [tf_prefix]
    bufferInfo = _serializer.string(obj.tf_prefix, bufferInfo);
    // Serialize message field [roll_trim]
    bufferInfo = _serializer.float32(obj.roll_trim, bufferInfo);
    // Serialize message field [pitch_trim]
    bufferInfo = _serializer.float32(obj.pitch_trim, bufferInfo);
    // Serialize message field [enable_logging]
    bufferInfo = _serializer.bool(obj.enable_logging, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type AddCrazyflieRequest
    let tmp;
    let len;
    let data = new AddCrazyflieRequest();
    // Deserialize message field [uri]
    tmp = _deserializer.string(buffer);
    data.uri = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [tf_prefix]
    tmp = _deserializer.string(buffer);
    data.tf_prefix = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [roll_trim]
    tmp = _deserializer.float32(buffer);
    data.roll_trim = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [pitch_trim]
    tmp = _deserializer.float32(buffer);
    data.pitch_trim = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [enable_logging]
    tmp = _deserializer.bool(buffer);
    data.enable_logging = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'crazyflie_driver/AddCrazyflieRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5b59a3ab8b313e5f8ea146f7129a4bf5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string uri
    string tf_prefix
    float32 roll_trim
    float32 pitch_trim
    bool enable_logging
    
    `;
  }

};

class AddCrazyflieResponse {
  constructor() {
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type AddCrazyflieResponse
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type AddCrazyflieResponse
    let tmp;
    let len;
    let data = new AddCrazyflieResponse();
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'crazyflie_driver/AddCrazyflieResponse';
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
  Request: AddCrazyflieRequest,
  Response: AddCrazyflieResponse
};
