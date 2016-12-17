; Auto-generated. Do not edit!


(cl:in-package mpc-msg)


;//! \htmlinclude msgMpc_data.msg.html

(cl:defclass <msgMpc_data> (roslisp-msg-protocol:ros-message)
  ((xPos
    :reader xPos
    :initarg :xPos
    :type cl:float
    :initform 0.0)
   (yPos
    :reader yPos
    :initarg :yPos
    :type cl:float
    :initform 0.0)
   (zPos
    :reader zPos
    :initarg :zPos
    :type cl:float
    :initform 0.0)
   (controlFlag
    :reader controlFlag
    :initarg :controlFlag
    :type cl:fixnum
    :initform 0)
   (xPosRef
    :reader xPosRef
    :initarg :xPosRef
    :type cl:float
    :initform 0.0)
   (yPosRef
    :reader yPosRef
    :initarg :yPosRef
    :type cl:float
    :initform 0.0)
   (zPosRef
    :reader zPosRef
    :initarg :zPosRef
    :type cl:float
    :initform 0.0))
)

(cl:defclass msgMpc_data (<msgMpc_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <msgMpc_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'msgMpc_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mpc-msg:<msgMpc_data> is deprecated: use mpc-msg:msgMpc_data instead.")))

(cl:ensure-generic-function 'xPos-val :lambda-list '(m))
(cl:defmethod xPos-val ((m <msgMpc_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:xPos-val is deprecated.  Use mpc-msg:xPos instead.")
  (xPos m))

(cl:ensure-generic-function 'yPos-val :lambda-list '(m))
(cl:defmethod yPos-val ((m <msgMpc_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:yPos-val is deprecated.  Use mpc-msg:yPos instead.")
  (yPos m))

(cl:ensure-generic-function 'zPos-val :lambda-list '(m))
(cl:defmethod zPos-val ((m <msgMpc_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:zPos-val is deprecated.  Use mpc-msg:zPos instead.")
  (zPos m))

(cl:ensure-generic-function 'controlFlag-val :lambda-list '(m))
(cl:defmethod controlFlag-val ((m <msgMpc_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:controlFlag-val is deprecated.  Use mpc-msg:controlFlag instead.")
  (controlFlag m))

(cl:ensure-generic-function 'xPosRef-val :lambda-list '(m))
(cl:defmethod xPosRef-val ((m <msgMpc_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:xPosRef-val is deprecated.  Use mpc-msg:xPosRef instead.")
  (xPosRef m))

(cl:ensure-generic-function 'yPosRef-val :lambda-list '(m))
(cl:defmethod yPosRef-val ((m <msgMpc_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:yPosRef-val is deprecated.  Use mpc-msg:yPosRef instead.")
  (yPosRef m))

(cl:ensure-generic-function 'zPosRef-val :lambda-list '(m))
(cl:defmethod zPosRef-val ((m <msgMpc_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpc-msg:zPosRef-val is deprecated.  Use mpc-msg:zPosRef instead.")
  (zPosRef m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <msgMpc_data>) ostream)
  "Serializes a message object of type '<msgMpc_data>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'xPos))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'yPos))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'zPos))))
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
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'xPosRef))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'yPosRef))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'zPosRef))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <msgMpc_data>) istream)
  "Deserializes a message object of type '<msgMpc_data>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xPos) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yPos) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zPos) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'controlFlag) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xPosRef) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yPosRef) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zPosRef) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<msgMpc_data>)))
  "Returns string type for a message object of type '<msgMpc_data>"
  "mpc/msgMpc_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'msgMpc_data)))
  "Returns string type for a message object of type 'msgMpc_data"
  "mpc/msgMpc_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<msgMpc_data>)))
  "Returns md5sum for a message object of type '<msgMpc_data>"
  "6bc2414c1027b318ae658fa2e1750a8e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'msgMpc_data)))
  "Returns md5sum for a message object of type 'msgMpc_data"
  "6bc2414c1027b318ae658fa2e1750a8e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<msgMpc_data>)))
  "Returns full string definition for message of type '<msgMpc_data>"
  (cl:format cl:nil "float64 xPos~%float64 yPos~%float64 zPos~%~%int8   controlFlag~%~%float64 xPosRef~%float64 yPosRef~%float64 zPosRef~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'msgMpc_data)))
  "Returns full string definition for message of type 'msgMpc_data"
  (cl:format cl:nil "float64 xPos~%float64 yPos~%float64 zPos~%~%int8   controlFlag~%~%float64 xPosRef~%float64 yPosRef~%float64 zPosRef~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <msgMpc_data>))
  (cl:+ 0
     8
     8
     8
     1
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <msgMpc_data>))
  "Converts a ROS message object to a list"
  (cl:list 'msgMpc_data
    (cl:cons ':xPos (xPos msg))
    (cl:cons ':yPos (yPos msg))
    (cl:cons ':zPos (zPos msg))
    (cl:cons ':controlFlag (controlFlag msg))
    (cl:cons ':xPosRef (xPosRef msg))
    (cl:cons ':yPosRef (yPosRef msg))
    (cl:cons ':zPosRef (zPosRef msg))
))
