// Auto-generated. Do not edit!

// (in-package generate_reference.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class msgReference {
  constructor() {
    this.signal = 0;
    this.next_ref_x = 0.0;
    this.next_ref_y = 0.0;
    this.next_ref_z = 0.0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type msgReference
    // Serialize message field [signal]
    bufferInfo = _serializer.int16(obj.signal, bufferInfo);
    // Serialize message field [next_ref_x]
    bufferInfo = _serializer.float64(obj.next_ref_x, bufferInfo);
    // Serialize message field [next_ref_y]
    bufferInfo = _serializer.float64(obj.next_ref_y, bufferInfo);
    // Serialize message field [next_ref_z]
    bufferInfo = _serializer.float64(obj.next_ref_z, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type msgReference
    let tmp;
    let len;
    let data = new msgReference();
    // Deserialize message field [signal]
    tmp = _deserializer.int16(buffer);
    data.signal = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [next_ref_x]
    tmp = _deserializer.float64(buffer);
    data.next_ref_x = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [next_ref_y]
    tmp = _deserializer.float64(buffer);
    data.next_ref_y = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [next_ref_z]
    tmp = _deserializer.float64(buffer);
    data.next_ref_z = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'generate_reference/msgReference';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1443c667f03adfad10148dcd7f2ec861';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 signal
    
    float64 next_ref_x
    float64 next_ref_y
    float64 next_ref_z
    
    `;
  }

};

module.exports = msgReference;
