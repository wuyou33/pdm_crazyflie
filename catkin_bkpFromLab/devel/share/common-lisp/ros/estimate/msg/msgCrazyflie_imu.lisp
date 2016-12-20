; Auto-generated. Do not edit!


(cl:in-package estimate-msg)


;//! \htmlinclude msgCrazyflie_imu.msg.html

(cl:defclass <msgCrazyflie_imu> (roslisp-msg-protocol:ros-message)
  ((imu_msg
    :reader imu_msg
    :initarg :imu_msg
    :type cl:float
    :initform 0.0))
)

(cl:defclass msgCrazyflie_imu (<msgCrazyflie_imu>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <msgCrazyflie_imu>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'msgCrazyflie_imu)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name estimate-msg:<msgCrazyflie_imu> is deprecated: use estimate-msg:msgCrazyflie_imu instead.")))

(cl:ensure-generic-function 'imu_msg-val :lambda-list '(m))
(cl:defmethod imu_msg-val ((m <msgCrazyflie_imu>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_msg-val is deprecated.  Use estimate-msg:imu_msg instead.")
  (imu_msg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <msgCrazyflie_imu>) ostream)
  "Serializes a message object of type '<msgCrazyflie_imu>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <msgCrazyflie_imu>) istream)
  "Deserializes a message object of type '<msgCrazyflie_imu>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_msg) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<msgCrazyflie_imu>)))
  "Returns string type for a message object of type '<msgCrazyflie_imu>"
  "estimate/msgCrazyflie_imu")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'msgCrazyflie_imu)))
  "Returns string type for a message object of type 'msgCrazyflie_imu"
  "estimate/msgCrazyflie_imu")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<msgCrazyflie_imu>)))
  "Returns md5sum for a message object of type '<msgCrazyflie_imu>"
  "b709b46dc338f97917b3e18f3e2367ba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'msgCrazyflie_imu)))
  "Returns md5sum for a message object of type 'msgCrazyflie_imu"
  "b709b46dc338f97917b3e18f3e2367ba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<msgCrazyflie_imu>)))
  "Returns full string definition for message of type '<msgCrazyflie_imu>"
  (cl:format cl:nil "float32 imu_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'msgCrazyflie_imu)))
  "Returns full string definition for message of type 'msgCrazyflie_imu"
  (cl:format cl:nil "float32 imu_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <msgCrazyflie_imu>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <msgCrazyflie_imu>))
  "Converts a ROS message object to a list"
  (cl:list 'msgCrazyflie_imu
    (cl:cons ':imu_msg (imu_msg msg))
))
