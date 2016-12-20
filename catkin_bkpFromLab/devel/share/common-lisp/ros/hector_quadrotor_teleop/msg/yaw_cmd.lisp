; Auto-generated. Do not edit!


(cl:in-package hector_quadrotor_teleop-msg)


;//! \htmlinclude yaw_cmd.msg.html

(cl:defclass <yaw_cmd> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (turnrate
    :reader turnrate
    :initarg :turnrate
    :type cl:float
    :initform 0.0))
)

(cl:defclass yaw_cmd (<yaw_cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <yaw_cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'yaw_cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hector_quadrotor_teleop-msg:<yaw_cmd> is deprecated: use hector_quadrotor_teleop-msg:yaw_cmd instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <yaw_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hector_quadrotor_teleop-msg:header-val is deprecated.  Use hector_quadrotor_teleop-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'turnrate-val :lambda-list '(m))
(cl:defmethod turnrate-val ((m <yaw_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hector_quadrotor_teleop-msg:turnrate-val is deprecated.  Use hector_quadrotor_teleop-msg:turnrate instead.")
  (turnrate m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <yaw_cmd>) ostream)
  "Serializes a message object of type '<yaw_cmd>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'turnrate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <yaw_cmd>) istream)
  "Deserializes a message object of type '<yaw_cmd>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'turnrate) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<yaw_cmd>)))
  "Returns string type for a message object of type '<yaw_cmd>"
  "hector_quadrotor_teleop/yaw_cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'yaw_cmd)))
  "Returns string type for a message object of type 'yaw_cmd"
  "hector_quadrotor_teleop/yaw_cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<yaw_cmd>)))
  "Returns md5sum for a message object of type '<yaw_cmd>"
  "d8d2a0a1e3daa0fc410bf30a154fa6b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'yaw_cmd)))
  "Returns md5sum for a message object of type 'yaw_cmd"
  "d8d2a0a1e3daa0fc410bf30a154fa6b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<yaw_cmd>)))
  "Returns full string definition for message of type '<yaw_cmd>"
  (cl:format cl:nil "Header header~%float32 turnrate~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'yaw_cmd)))
  "Returns full string definition for message of type 'yaw_cmd"
  (cl:format cl:nil "Header header~%float32 turnrate~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <yaw_cmd>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <yaw_cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'yaw_cmd
    (cl:cons ':header (header msg))
    (cl:cons ':turnrate (turnrate msg))
))
