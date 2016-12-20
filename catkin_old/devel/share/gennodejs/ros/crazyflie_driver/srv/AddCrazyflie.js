// Auto-generated. Do not edit!

// (in-package crazyflie_driver.srv)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let LogBlock = require('../msg/LogBlock.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class AddCrazyflieRequest {
  constructor() {
    this.uri = '';
    this.tf_prefix = '';
    this.roll_trim = 0.0;
    this.pitch_trim = 0.0;
    this.enable_logging = false;
    this.enable_parameters = false;
    this.log_blocks = [];
    this.use_ros_time = false;
    this.enable_logging_imu = false;
    this.enable_logging_temperature = false;
    this.enable_logging_magnetic_field = false;
    this.enable_logging_pressure = false;
    this.enable_logging_battery = false;
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
    // Serialize message field [enable_parameters]
    bufferInfo = _serializer.bool(obj.enable_parameters, bufferInfo);
    // Serialize the length for message field [log_blocks]
    bufferInfo = _serializer.uint32(obj.log_blocks.length, bufferInfo);
    // Serialize message field [log_blocks]
    obj.log_blocks.forEach((val) => {
      bufferInfo = LogBlock.serialize(val, bufferInfo);
    });
    // Serialize message field [use_ros_time]
    bufferInfo = _serializer.bool(obj.use_ros_time, bufferInfo);
    // Serialize message field [enable_logging_imu]
    bufferInfo = _serializer.bool(obj.enable_logging_imu, bufferInfo);
    // Serialize message field [enable_logging_temperature]
    bufferInfo = _serializer.bool(obj.enable_logging_temperature, bufferInfo);
    // Serialize message field [enable_logging_magnetic_field]
    bufferInfo = _serializer.bool(obj.enable_logging_magnetic_field, bufferInfo);
    // Serialize message field [enable_logging_pressure]
    bufferInfo = _serializer.bool(obj.enable_logging_pressure, bufferInfo);
    // Serialize message field [enable_logging_battery]
    bufferInfo = _serializer.bool(obj.enable_logging_battery, bufferInfo);
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
    // Deserialize message field [enable_parameters]
    tmp = _deserializer.bool(buffer);
    data.enable_parameters = tmp.data;
    buffer = tmp.buffer;
    // Deserialize array length for message field [log_blocks]
    tmp = _deserializer.uint32(buffer);
    len = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [log_blocks]
    data.log_blocks = new Array(len);
    for (let i = 0; i < len; ++i) {
      tmp = LogBlock.deserialize(buffer);
      data.log_blocks[i] = tmp.data;
      buffer = tmp.buffer;
    }
    // Deserialize message field [use_ros_time]
    tmp = _deserializer.bool(buffer);
    data.use_ros_time = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [enable_logging_imu]
    tmp = _deserializer.bool(buffer);
    data.enable_logging_imu = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [enable_logging_temperature]
    tmp = _deserializer.bool(buffer);
    data.enable_logging_temperature = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [enable_logging_magnetic_field]
    tmp = _deserializer.bool(buffer);
    data.enable_logging_magnetic_field = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [enable_logging_pressure]
    tmp = _deserializer.bool(buffer);
    data.enable_logging_pressure = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [enable_logging_battery]
    tmp = _deserializer.bool(buffer);
    data.enable_logging_battery = tmp.data;
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
    return 'ecc01ed9b37cee7a67ca59fc53aeb029';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string uri
    string tf_prefix
    float32 roll_trim
    float32 pitch_trim
    bool enable_logging
    bool enable_parameters
    LogBlock[] log_blocks
    bool use_ros_time
    bool enable_logging_imu
    bool enable_logging_temperature
    bool enable_logging_magnetic_field
    bool enable_logging_pressure
    bool enable_logging_battery
    
    ================================================================================
    MSG: crazyflie_driver/LogBlock
    string topic_name
    int16 frequency
    string[] variables
    
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
