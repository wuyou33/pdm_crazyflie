; Auto-generated. Do not edit!


(cl:in-package mpc-msg)


;//! \htmlinclude msgMpc_input.msg.html

(cl:defclass <msgMpc_input> (roslisp-msg-protocol:ros-message)
  ((rollPhi
    :reader rollPhi
    :initarg :rollPhi
    :type cl:float
    :initform 0.0)
   (thetaPitch
    :reader thetaPitch
    :initarg :thetaPitch
    :type cl:float
    :initform 0.0)
   (psiYawRate
    :reader psiYawRate
    :initarg :psiYawRate
    :type cl:float
    :initform 0.0)
   (thrust
    :reader thrust
    :initarg :thrust
    :type cl:float
    :initform 0.0)
   (controlFlag
    :reader controlFlag
    :initarg :controlFlag
    :type cl:fixnum
    :initform 0))
)

(cl:defclass msgMpc_input (<msgMpc_input>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <msgMpc_input>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'msgMpc_input)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mpc-msg:<msgMpc_input> is deprecated: use mpc-msg:msgMpc_input instead.")))

(cl:ensure-generic-function 'rollPhi-val :lambda-list '(m))
(cl:defmethod rollPhi-val ((m <msgMpc_input>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:rollPhi-val is deprecated.  Use mpc-msg:rollPhi instead.")
  (rollPhi m))

(cl:ensure-generic-function 'thetaPitch-val :lambda-list '(m))
(cl:defmethod thetaPitch-val ((m <msgMpc_input>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:thetaPitch-val is deprecated.  Use mpc-msg:thetaPitch instead.")
  (thetaPitch m))

(cl:ensure-generic-function 'psiYawRate-val :lambda-list '(m))
(cl:defmethod psiYawRate-val ((m <msgMpc_input>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:psiYawRate-val is deprecated.  Use mpc-msg:psiYawRate instead.")
  (psiYawRate m))

(cl:ensure-generic-function 'thrust-val :lambda-list '(m))
(cl:defmethod thrust-val ((m <msgMpc_input>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:thrust-val is deprecated.  Use mpc-msg:thrust instead.")
  (thrust m))

(cl:ensure-generic-function 'controlFlag-val :lambda-list '(m))
(cl:defmethod controlFlag-val ((m <msgMpc_input>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:controlFlag-val is deprecated.  Use mpc-msg:controlFlag instead.")
  (controlFlag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <msgMpc_input>) ostream)
  "Serializes a message object of type '<msgMpc_input>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'rollPhi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'thetaPitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'psiYawRate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'thrust))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'controlFlag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <msgMpc_input>) istream)
  "Deserializes a message object of type '<msgMpc_input>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rollPhi) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'thetaPitch) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'psiYawRate) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'thrust) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'controlFlag) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<msgMpc_input>)))
  "Returns string type for a message object of type '<msgMpc_input>"
  "mpc/msgMpc_input")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'msgMpc_input)))
  "Returns string type for a message object of type 'msgMpc_input"
  "mpc/msgMpc_input")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<msgMpc_input>)))
  "Returns md5sum for a message object of type '<msgMpc_input>"
  "64731ea8c92ca2a1540116905352cf9e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'msgMpc_input)))
  "Returns md5sum for a message object of type 'msgMpc_input"
  "64731ea8c92ca2a1540116905352cf9e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<msgMpc_input>)))
  "Returns full string definition for message of type '<msgMpc_input>"
  (cl:format cl:nil "float64 rollPhi~%float64 thetaPitch~%float64 psiYawRate~%float64 thrust~%~%int8 controlFlag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'msgMpc_input)))
  "Returns full string definition for message of type 'msgMpc_input"
  (cl:format cl:nil "float64 rollPhi~%float64 thetaPitch~%float64 psiYawRate~%float64 thrust~%~%int8 controlFlag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <msgMpc_input>))
  (cl:+ 0
     8
     8
     8
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <msgMpc_input>))
  "Converts a ROS message object to a list"
  (cl:list 'msgMpc_input
    (cl:cons ':rollPhi (rollPhi msg))
    (cl:cons ':thetaPitch (thetaPitch msg))
    (cl:cons ':psiYawRate (psiYawRate msg))
    (cl:cons ':thrust (thrust msg))
    (cl:cons ':controlFlag (controlFlag msg))
))
