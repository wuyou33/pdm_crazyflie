; Auto-generated. Do not edit!


(cl:in-package hector_quadrotor_teleop-msg)


;//! \htmlinclude adv_cmd_vel.msg.html

(cl:defclass <adv_cmd_vel> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (linear
    :reader linear
    :initarg :linear
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (angular
    :reader angular
    :initarg :angular
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass adv_cmd_vel (<adv_cmd_vel>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <adv_cmd_vel>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'adv_cmd_vel)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hector_quadrotor_teleop-msg:<adv_cmd_vel> is deprecated: use hector_quadrotor_teleop-msg:adv_cmd_vel instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <adv_cmd_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hector_quadrotor_teleop-msg:header-val is deprecated.  Use hector_quadrotor_teleop-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'linear-val :lambda-list '(m))
(cl:defmethod linear-val ((m <adv_cmd_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hector_quadrotor_teleop-msg:linear-val is deprecated.  Use hector_quadrotor_teleop-msg:linear instead.")
  (linear m))

(cl:ensure-generic-function 'angular-val :lambda-list '(m))
(cl:defmethod angular-val ((m <adv_cmd_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hector_quadrotor_teleop-msg:angular-val is deprecated.  Use hector_quadrotor_teleop-msg:angular instead.")
  (angular m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <adv_cmd_vel>) ostream)
  "Serializes a message object of type '<adv_cmd_vel>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'linear) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'angular) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <adv_cmd_vel>) istream)
  "Deserializes a message object of type '<adv_cmd_vel>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'linear) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'angular) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<adv_cmd_vel>)))
  "Returns string type for a message object of type '<adv_cmd_vel>"
  "hector_quadrotor_teleop/adv_cmd_vel")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'adv_cmd_vel)))
  "Returns string type for a message object of type 'adv_cmd_vel"
  "hector_quadrotor_teleop/adv_cmd_vel")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<adv_cmd_vel>)))
  "Returns md5sum for a message object of type '<adv_cmd_vel>"
  "09119d3b0067bd05b1a6696c168cebb3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'adv_cmd_vel)))
  "Returns md5sum for a message object of type 'adv_cmd_vel"
  "09119d3b0067bd05b1a6696c168cebb3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<adv_cmd_vel>)))
  "Returns full string definition for message of type '<adv_cmd_vel>"
  (cl:format cl:nil "std_msgs/Header header~%geometry_msgs/Vector3 linear~%geometry_msgs/Vector3 angular~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'adv_cmd_vel)))
  "Returns full string definition for message of type 'adv_cmd_vel"
  (cl:format cl:nil "std_msgs/Header header~%geometry_msgs/Vector3 linear~%geometry_msgs/Vector3 angular~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <adv_cmd_vel>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'linear))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'angular))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <adv_cmd_vel>))
  "Converts a ROS message object to a list"
  (cl:list 'adv_cmd_vel
    (cl:cons ':header (header msg))
    (cl:cons ':linear (linear msg))
    (cl:cons ':angular (angular msg))
))
