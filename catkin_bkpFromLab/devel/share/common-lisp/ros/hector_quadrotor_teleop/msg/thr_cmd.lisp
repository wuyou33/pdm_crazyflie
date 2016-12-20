; Auto-generated. Do not edit!


(cl:in-package hector_quadrotor_teleop-msg)


;//! \htmlinclude thr_cmd.msg.html

(cl:defclass <thr_cmd> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (thrust
    :reader thrust
    :initarg :thrust
    :type cl:float
    :initform 0.0))
)

(cl:defclass thr_cmd (<thr_cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <thr_cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'thr_cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hector_quadrotor_teleop-msg:<thr_cmd> is deprecated: use hector_quadrotor_teleop-msg:thr_cmd instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <thr_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hector_quadrotor_teleop-msg:header-val is deprecated.  Use hector_quadrotor_teleop-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'thrust-val :lambda-list '(m))
(cl:defmethod thrust-val ((m <thr_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hector_quadrotor_teleop-msg:thrust-val is deprecated.  Use hector_quadrotor_teleop-msg:thrust instead.")
  (thrust m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <thr_cmd>) ostream)
  "Serializes a message object of type '<thr_cmd>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'thrust))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <thr_cmd>) istream)
  "Deserializes a message object of type '<thr_cmd>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'thrust) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<thr_cmd>)))
  "Returns string type for a message object of type '<thr_cmd>"
  "hector_quadrotor_teleop/thr_cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'thr_cmd)))
  "Returns string type for a message object of type 'thr_cmd"
  "hector_quadrotor_teleop/thr_cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<thr_cmd>)))
  "Returns md5sum for a message object of type '<thr_cmd>"
  "c61da3a8868a8b502eaf0b0abd839f57")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'thr_cmd)))
  "Returns md5sum for a message object of type 'thr_cmd"
  "c61da3a8868a8b502eaf0b0abd839f57")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<thr_cmd>)))
  "Returns full string definition for message of type '<thr_cmd>"
  (cl:format cl:nil "Header header~%float32 thrust~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'thr_cmd)))
  "Returns full string definition for message of type 'thr_cmd"
  (cl:format cl:nil "Header header~%float32 thrust~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <thr_cmd>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <thr_cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'thr_cmd
    (cl:cons ':header (header msg))
    (cl:cons ':thrust (thrust msg))
))
