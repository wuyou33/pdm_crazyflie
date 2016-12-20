; Auto-generated. Do not edit!


(cl:in-package beginner_tutorials-msg)


;//! \htmlinclude msgCrazyflie_data.msg.html

(cl:defclass <msgCrazyflie_data> (roslisp-msg-protocol:ros-message)
  ((imu_msg
    :reader imu_msg
    :initarg :imu_msg
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (vrpn_msg
    :reader vrpn_msg
    :initarg :vrpn_msg
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass msgCrazyflie_data (<msgCrazyflie_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <msgCrazyflie_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'msgCrazyflie_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorials-msg:<msgCrazyflie_data> is deprecated: use beginner_tutorials-msg:msgCrazyflie_data instead.")))

(cl:ensure-generic-function 'imu_msg-val :lambda-list '(m))
(cl:defmethod imu_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:imu_msg-val is deprecated.  Use beginner_tutorials-msg:imu_msg instead.")
  (imu_msg m))

(cl:ensure-generic-function 'vrpn_msg-val :lambda-list '(m))
(cl:defmethod vrpn_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:vrpn_msg-val is deprecated.  Use beginner_tutorials-msg:vrpn_msg instead.")
  (vrpn_msg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <msgCrazyflie_data>) ostream)
  "Serializes a message object of type '<msgCrazyflie_data>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'imu_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'imu_msg))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'vrpn_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'vrpn_msg))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <msgCrazyflie_data>) istream)
  "Deserializes a message object of type '<msgCrazyflie_data>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'imu_msg) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'imu_msg)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'vrpn_msg) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'vrpn_msg)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<msgCrazyflie_data>)))
  "Returns string type for a message object of type '<msgCrazyflie_data>"
  "beginner_tutorials/msgCrazyflie_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'msgCrazyflie_data)))
  "Returns string type for a message object of type 'msgCrazyflie_data"
  "beginner_tutorials/msgCrazyflie_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<msgCrazyflie_data>)))
  "Returns md5sum for a message object of type '<msgCrazyflie_data>"
  "6af109ec49fecf2fd5c4a5b152fa11fb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'msgCrazyflie_data)))
  "Returns md5sum for a message object of type 'msgCrazyflie_data"
  "6af109ec49fecf2fd5c4a5b152fa11fb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<msgCrazyflie_data>)))
  "Returns full string definition for message of type '<msgCrazyflie_data>"
  (cl:format cl:nil "float32[] imu_msg~%float32[] vrpn_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'msgCrazyflie_data)))
  "Returns full string definition for message of type 'msgCrazyflie_data"
  (cl:format cl:nil "float32[] imu_msg~%float32[] vrpn_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <msgCrazyflie_data>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'imu_msg) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'vrpn_msg) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <msgCrazyflie_data>))
  "Converts a ROS message object to a list"
  (cl:list 'msgCrazyflie_data
    (cl:cons ':imu_msg (imu_msg msg))
    (cl:cons ':vrpn_msg (vrpn_msg msg))
))
