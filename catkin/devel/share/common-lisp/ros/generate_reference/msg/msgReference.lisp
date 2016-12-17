; Auto-generated. Do not edit!


(cl:in-package generate_reference-msg)


;//! \htmlinclude msgReference.msg.html

(cl:defclass <msgReference> (roslisp-msg-protocol:ros-message)
  ((signal
    :reader signal
    :initarg :signal
    :type cl:fixnum
    :initform 0)
   (next_ref_x
    :reader next_ref_x
    :initarg :next_ref_x
    :type cl:float
    :initform 0.0)
   (next_ref_y
    :reader next_ref_y
    :initarg :next_ref_y
    :type cl:float
    :initform 0.0)
   (next_ref_z
    :reader next_ref_z
    :initarg :next_ref_z
    :type cl:float
    :initform 0.0))
)

(cl:defclass msgReference (<msgReference>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <msgReference>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'msgReference)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name generate_reference-msg:<msgReference> is deprecated: use generate_reference-msg:msgReference instead.")))

(cl:ensure-generic-function 'signal-val :lambda-list '(m))
(cl:defmethod signal-val ((m <msgReference>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader generate_reference-msg:signal-val is deprecated.  Use generate_reference-msg:signal instead.")
  (signal m))

(cl:ensure-generic-function 'next_ref_x-val :lambda-list '(m))
(cl:defmethod next_ref_x-val ((m <msgReference>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader generate_reference-msg:next_ref_x-val is deprecated.  Use generate_reference-msg:next_ref_x instead.")
  (next_ref_x m))

(cl:ensure-generic-function 'next_ref_y-val :lambda-list '(m))
(cl:defmethod next_ref_y-val ((m <msgReference>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader generate_reference-msg:next_ref_y-val is deprecated.  Use generate_reference-msg:next_ref_y instead.")
  (next_ref_y m))

(cl:ensure-generic-function 'next_ref_z-val :lambda-list '(m))
(cl:defmethod next_ref_z-val ((m <msgReference>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader generate_reference-msg:next_ref_z-val is deprecated.  Use generate_reference-msg:next_ref_z instead.")
  (next_ref_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <msgReference>) ostream)
  "Serializes a message object of type '<msgReference>"
  (cl:let* ((signed (cl:slot-value msg 'signal)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'next_ref_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'next_ref_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'next_ref_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <msgReference>) istream)
  "Deserializes a message object of type '<msgReference>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'signal) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'next_ref_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'next_ref_y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'next_ref_z) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<msgReference>)))
  "Returns string type for a message object of type '<msgReference>"
  "generate_reference/msgReference")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'msgReference)))
  "Returns string type for a message object of type 'msgReference"
  "generate_reference/msgReference")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<msgReference>)))
  "Returns md5sum for a message object of type '<msgReference>"
  "1443c667f03adfad10148dcd7f2ec861")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'msgReference)))
  "Returns md5sum for a message object of type 'msgReference"
  "1443c667f03adfad10148dcd7f2ec861")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<msgReference>)))
  "Returns full string definition for message of type '<msgReference>"
  (cl:format cl:nil "int16 signal~%~%float64 next_ref_x~%float64 next_ref_y~%float64 next_ref_z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'msgReference)))
  "Returns full string definition for message of type 'msgReference"
  (cl:format cl:nil "int16 signal~%~%float64 next_ref_x~%float64 next_ref_y~%float64 next_ref_z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <msgReference>))
  (cl:+ 0
     2
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <msgReference>))
  "Converts a ROS message object to a list"
  (cl:list 'msgReference
    (cl:cons ':signal (signal msg))
    (cl:cons ':next_ref_x (next_ref_x msg))
    (cl:cons ':next_ref_y (next_ref_y msg))
    (cl:cons ':next_ref_z (next_ref_z msg))
))
