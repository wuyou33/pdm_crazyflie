// Auto-generated. Do not edit!

// (in-package hector_uav_msgs.srv)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class EnableMotorsRequest {
  constructor() {
    this.enable = false;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type EnableMotorsRequest
    // Serialize message field [enable]
    bufferInfo = _serializer.bool(obj.enable, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type EnableMotorsRequest
    let tmp;
    let len;
    let data = new EnableMotorsRequest();
    // Deserialize message field [enable]
    tmp = _deserializer.bool(buffer);
    data.enable = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'hector_uav_msgs/EnableMotorsRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8c1211af706069c994c06e00eb59ac9e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool enable
    
    `;
  }

};

class EnableMotorsResponse {
  constructor() {
    this.success = false;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type EnableMotorsResponse
    // Serialize message field [success]
    bufferInfo = _serializer.bool(obj.success, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type EnableMotorsResponse
    let tmp;
    let len;
    let data = new EnableMotorsResponse();
    // Deserialize message field [success]
    tmp = _deserializer.bool(buffer);
    data.success = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a service object
    return 'hector_uav_msgs/EnableMotorsResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    
    `;
  }

};

module.exports = {
  Request: EnableMotorsRequest,
  Response: EnableMotorsResponse
};
