;; Auto-generated. Do not edit!


(when (boundp 'hector_quadrotor_teleop::adv_cmd_vel)
  (if (not (find-package "HECTOR_QUADROTOR_TELEOP"))
    (make-package "HECTOR_QUADROTOR_TELEOP"))
  (shadow 'adv_cmd_vel (find-package "HECTOR_QUADROTOR_TELEOP")))
(unless (find-package "HECTOR_QUADROTOR_TELEOP::ADV_CMD_VEL")
  (make-package "HECTOR_QUADROTOR_TELEOP::ADV_CMD_VEL"))

(in-package "ROS")
;;//! \htmlinclude adv_cmd_vel.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass hector_quadrotor_teleop::adv_cmd_vel
  :super ros::object
  :slots (_header _linear _angular ))

(defmethod hector_quadrotor_teleop::adv_cmd_vel
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:linear __linear) (instance geometry_msgs::Vector3 :init))
    ((:angular __angular) (instance geometry_msgs::Vector3 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _linear __linear)
   (setq _angular __angular)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:linear
   (&rest __linear)
   (if (keywordp (car __linear))
       (send* _linear __linear)
     (progn
       (if __linear (setq _linear (car __linear)))
       _linear)))
  (:angular
   (&rest __angular)
   (if (keywordp (car __angular))
       (send* _angular __angular)
     (progn
       (if __angular (setq _angular (car __angular)))
       _angular)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Vector3 _linear
    (send _linear :serialization-length)
    ;; geometry_msgs/Vector3 _angular
    (send _angular :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Vector3 _linear
       (send _linear :serialize s)
     ;; geometry_msgs/Vector3 _angular
       (send _angular :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Vector3 _linear
     (send _linear :deserialize buf ptr-) (incf ptr- (send _linear :serialization-length))
   ;; geometry_msgs/Vector3 _angular
     (send _angular :deserialize buf ptr-) (incf ptr- (send _angular :serialization-length))
   ;;
   self)
  )

(setf (get hector_quadrotor_teleop::adv_cmd_vel :md5sum-) "09119d3b0067bd05b1a6696c168cebb3")
(setf (get hector_quadrotor_teleop::adv_cmd_vel :datatype-) "hector_quadrotor_teleop/adv_cmd_vel")
(setf (get hector_quadrotor_teleop::adv_cmd_vel :definition-)
      "std_msgs/Header header
geometry_msgs/Vector3 linear
geometry_msgs/Vector3 angular

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :hector_quadrotor_teleop/adv_cmd_vel "09119d3b0067bd05b1a6696c168cebb3")


