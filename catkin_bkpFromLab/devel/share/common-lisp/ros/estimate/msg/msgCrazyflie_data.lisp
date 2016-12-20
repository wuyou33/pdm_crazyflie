; Auto-generated. Do not edit!


(cl:in-package estimate-msg)


;//! \htmlinclude msgCrazyflie_data.msg.html

(cl:defclass <msgCrazyflie_data> (roslisp-msg-protocol:ros-message)
  ((imu_time_msg
    :reader imu_time_msg
    :initarg :imu_time_msg
    :type cl:float
    :initform 0.0)
   (imu_angx_msg
    :reader imu_angx_msg
    :initarg :imu_angx_msg
    :type cl:float
    :initform 0.0)
   (imu_angy_msg
    :reader imu_angy_msg
    :initarg :imu_angy_msg
    :type cl:float
    :initform 0.0)
   (imu_angz_msg
    :reader imu_angz_msg
    :initarg :imu_angz_msg
    :type cl:float
    :initform 0.0)
   (imu_linx_msg
    :reader imu_linx_msg
    :initarg :imu_linx_msg
    :type cl:float
    :initform 0.0)
   (imu_liny_msg
    :reader imu_liny_msg
    :initarg :imu_liny_msg
    :type cl:float
    :initform 0.0)
   (imu_linz_msg
    :reader imu_linz_msg
    :initarg :imu_linz_msg
    :type cl:float
    :initform 0.0)
   (vrpn_time_msg
    :reader vrpn_time_msg
    :initarg :vrpn_time_msg
    :type cl:float
    :initform 0.0)
   (vrpn_posx_msg
    :reader vrpn_posx_msg
    :initarg :vrpn_posx_msg
    :type cl:float
    :initform 0.0)
   (vrpn_posy_msg
    :reader vrpn_posy_msg
    :initarg :vrpn_posy_msg
    :type cl:float
    :initform 0.0)
   (vrpn_posz_msg
    :reader vrpn_posz_msg
    :initarg :vrpn_posz_msg
    :type cl:float
    :initform 0.0)
   (vrpn_velx_msg
    :reader vrpn_velx_msg
    :initarg :vrpn_velx_msg
    :type cl:float
    :initform 0.0)
   (vrpn_vely_msg
    :reader vrpn_vely_msg
    :initarg :vrpn_vely_msg
    :type cl:float
    :initform 0.0)
   (vrpn_velz_msg
    :reader vrpn_velz_msg
    :initarg :vrpn_velz_msg
    :type cl:float
    :initform 0.0)
   (vrpn_linx_msg
    :reader vrpn_linx_msg
    :initarg :vrpn_linx_msg
    :type cl:float
    :initform 0.0)
   (vrpn_liny_msg
    :reader vrpn_liny_msg
    :initarg :vrpn_liny_msg
    :type cl:float
    :initform 0.0)
   (vrpn_linz_msg
    :reader vrpn_linz_msg
    :initarg :vrpn_linz_msg
    :type cl:float
    :initform 0.0)
   (vrpn_orix_msg
    :reader vrpn_orix_msg
    :initarg :vrpn_orix_msg
    :type cl:float
    :initform 0.0)
   (vrpn_oriy_msg
    :reader vrpn_oriy_msg
    :initarg :vrpn_oriy_msg
    :type cl:float
    :initform 0.0)
   (vrpn_oriz_msg
    :reader vrpn_oriz_msg
    :initarg :vrpn_oriz_msg
    :type cl:float
    :initform 0.0)
   (vrpn_oriw_msg
    :reader vrpn_oriw_msg
    :initarg :vrpn_oriw_msg
    :type cl:float
    :initform 0.0)
   (vrpn_roll_msg
    :reader vrpn_roll_msg
    :initarg :vrpn_roll_msg
    :type cl:float
    :initform 0.0)
   (vrpn_pitch_msg
    :reader vrpn_pitch_msg
    :initarg :vrpn_pitch_msg
    :type cl:float
    :initform 0.0)
   (vrpn_yaw_msg
    :reader vrpn_yaw_msg
    :initarg :vrpn_yaw_msg
    :type cl:float
    :initform 0.0)
   (vrpn_time_msg_obs
    :reader vrpn_time_msg_obs
    :initarg :vrpn_time_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_posx_msg_obs
    :reader vrpn_posx_msg_obs
    :initarg :vrpn_posx_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_posy_msg_obs
    :reader vrpn_posy_msg_obs
    :initarg :vrpn_posy_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_posz_msg_obs
    :reader vrpn_posz_msg_obs
    :initarg :vrpn_posz_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_velx_msg_obs
    :reader vrpn_velx_msg_obs
    :initarg :vrpn_velx_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_vely_msg_obs
    :reader vrpn_vely_msg_obs
    :initarg :vrpn_vely_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_velz_msg_obs
    :reader vrpn_velz_msg_obs
    :initarg :vrpn_velz_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_linx_msg_obs
    :reader vrpn_linx_msg_obs
    :initarg :vrpn_linx_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_liny_msg_obs
    :reader vrpn_liny_msg_obs
    :initarg :vrpn_liny_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_linz_msg_obs
    :reader vrpn_linz_msg_obs
    :initarg :vrpn_linz_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_orix_msg_obs
    :reader vrpn_orix_msg_obs
    :initarg :vrpn_orix_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_oriy_msg_obs
    :reader vrpn_oriy_msg_obs
    :initarg :vrpn_oriy_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_oriz_msg_obs
    :reader vrpn_oriz_msg_obs
    :initarg :vrpn_oriz_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_oriw_msg_obs
    :reader vrpn_oriw_msg_obs
    :initarg :vrpn_oriw_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_roll_msg_obs
    :reader vrpn_roll_msg_obs
    :initarg :vrpn_roll_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_pitch_msg_obs
    :reader vrpn_pitch_msg_obs
    :initarg :vrpn_pitch_msg_obs
    :type cl:float
    :initform 0.0)
   (vrpn_yaw_msg_obs
    :reader vrpn_yaw_msg_obs
    :initarg :vrpn_yaw_msg_obs
    :type cl:float
    :initform 0.0))
)

(cl:defclass msgCrazyflie_data (<msgCrazyflie_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <msgCrazyflie_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'msgCrazyflie_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name estimate-msg:<msgCrazyflie_data> is deprecated: use estimate-msg:msgCrazyflie_data instead.")))

(cl:ensure-generic-function 'imu_time_msg-val :lambda-list '(m))
(cl:defmethod imu_time_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_time_msg-val is deprecated.  Use estimate-msg:imu_time_msg instead.")
  (imu_time_msg m))

(cl:ensure-generic-function 'imu_angx_msg-val :lambda-list '(m))
(cl:defmethod imu_angx_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_angx_msg-val is deprecated.  Use estimate-msg:imu_angx_msg instead.")
  (imu_angx_msg m))

(cl:ensure-generic-function 'imu_angy_msg-val :lambda-list '(m))
(cl:defmethod imu_angy_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_angy_msg-val is deprecated.  Use estimate-msg:imu_angy_msg instead.")
  (imu_angy_msg m))

(cl:ensure-generic-function 'imu_angz_msg-val :lambda-list '(m))
(cl:defmethod imu_angz_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_angz_msg-val is deprecated.  Use estimate-msg:imu_angz_msg instead.")
  (imu_angz_msg m))

(cl:ensure-generic-function 'imu_linx_msg-val :lambda-list '(m))
(cl:defmethod imu_linx_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_linx_msg-val is deprecated.  Use estimate-msg:imu_linx_msg instead.")
  (imu_linx_msg m))

(cl:ensure-generic-function 'imu_liny_msg-val :lambda-list '(m))
(cl:defmethod imu_liny_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_liny_msg-val is deprecated.  Use estimate-msg:imu_liny_msg instead.")
  (imu_liny_msg m))

(cl:ensure-generic-function 'imu_linz_msg-val :lambda-list '(m))
(cl:defmethod imu_linz_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:imu_linz_msg-val is deprecated.  Use estimate-msg:imu_linz_msg instead.")
  (imu_linz_msg m))

(cl:ensure-generic-function 'vrpn_time_msg-val :lambda-list '(m))
(cl:defmethod vrpn_time_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_time_msg-val is deprecated.  Use estimate-msg:vrpn_time_msg instead.")
  (vrpn_time_msg m))

(cl:ensure-generic-function 'vrpn_posx_msg-val :lambda-list '(m))
(cl:defmethod vrpn_posx_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_posx_msg-val is deprecated.  Use estimate-msg:vrpn_posx_msg instead.")
  (vrpn_posx_msg m))

(cl:ensure-generic-function 'vrpn_posy_msg-val :lambda-list '(m))
(cl:defmethod vrpn_posy_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_posy_msg-val is deprecated.  Use estimate-msg:vrpn_posy_msg instead.")
  (vrpn_posy_msg m))

(cl:ensure-generic-function 'vrpn_posz_msg-val :lambda-list '(m))
(cl:defmethod vrpn_posz_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_posz_msg-val is deprecated.  Use estimate-msg:vrpn_posz_msg instead.")
  (vrpn_posz_msg m))

(cl:ensure-generic-function 'vrpn_velx_msg-val :lambda-list '(m))
(cl:defmethod vrpn_velx_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_velx_msg-val is deprecated.  Use estimate-msg:vrpn_velx_msg instead.")
  (vrpn_velx_msg m))

(cl:ensure-generic-function 'vrpn_vely_msg-val :lambda-list '(m))
(cl:defmethod vrpn_vely_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_vely_msg-val is deprecated.  Use estimate-msg:vrpn_vely_msg instead.")
  (vrpn_vely_msg m))

(cl:ensure-generic-function 'vrpn_velz_msg-val :lambda-list '(m))
(cl:defmethod vrpn_velz_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_velz_msg-val is deprecated.  Use estimate-msg:vrpn_velz_msg instead.")
  (vrpn_velz_msg m))

(cl:ensure-generic-function 'vrpn_linx_msg-val :lambda-list '(m))
(cl:defmethod vrpn_linx_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_linx_msg-val is deprecated.  Use estimate-msg:vrpn_linx_msg instead.")
  (vrpn_linx_msg m))

(cl:ensure-generic-function 'vrpn_liny_msg-val :lambda-list '(m))
(cl:defmethod vrpn_liny_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_liny_msg-val is deprecated.  Use estimate-msg:vrpn_liny_msg instead.")
  (vrpn_liny_msg m))

(cl:ensure-generic-function 'vrpn_linz_msg-val :lambda-list '(m))
(cl:defmethod vrpn_linz_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_linz_msg-val is deprecated.  Use estimate-msg:vrpn_linz_msg instead.")
  (vrpn_linz_msg m))

(cl:ensure-generic-function 'vrpn_orix_msg-val :lambda-list '(m))
(cl:defmethod vrpn_orix_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_orix_msg-val is deprecated.  Use estimate-msg:vrpn_orix_msg instead.")
  (vrpn_orix_msg m))

(cl:ensure-generic-function 'vrpn_oriy_msg-val :lambda-list '(m))
(cl:defmethod vrpn_oriy_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_oriy_msg-val is deprecated.  Use estimate-msg:vrpn_oriy_msg instead.")
  (vrpn_oriy_msg m))

(cl:ensure-generic-function 'vrpn_oriz_msg-val :lambda-list '(m))
(cl:defmethod vrpn_oriz_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_oriz_msg-val is deprecated.  Use estimate-msg:vrpn_oriz_msg instead.")
  (vrpn_oriz_msg m))

(cl:ensure-generic-function 'vrpn_oriw_msg-val :lambda-list '(m))
(cl:defmethod vrpn_oriw_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_oriw_msg-val is deprecated.  Use estimate-msg:vrpn_oriw_msg instead.")
  (vrpn_oriw_msg m))

(cl:ensure-generic-function 'vrpn_roll_msg-val :lambda-list '(m))
(cl:defmethod vrpn_roll_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_roll_msg-val is deprecated.  Use estimate-msg:vrpn_roll_msg instead.")
  (vrpn_roll_msg m))

(cl:ensure-generic-function 'vrpn_pitch_msg-val :lambda-list '(m))
(cl:defmethod vrpn_pitch_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_pitch_msg-val is deprecated.  Use estimate-msg:vrpn_pitch_msg instead.")
  (vrpn_pitch_msg m))

(cl:ensure-generic-function 'vrpn_yaw_msg-val :lambda-list '(m))
(cl:defmethod vrpn_yaw_msg-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_yaw_msg-val is deprecated.  Use estimate-msg:vrpn_yaw_msg instead.")
  (vrpn_yaw_msg m))

(cl:ensure-generic-function 'vrpn_time_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_time_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_time_msg_obs-val is deprecated.  Use estimate-msg:vrpn_time_msg_obs instead.")
  (vrpn_time_msg_obs m))

(cl:ensure-generic-function 'vrpn_posx_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_posx_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_posx_msg_obs-val is deprecated.  Use estimate-msg:vrpn_posx_msg_obs instead.")
  (vrpn_posx_msg_obs m))

(cl:ensure-generic-function 'vrpn_posy_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_posy_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_posy_msg_obs-val is deprecated.  Use estimate-msg:vrpn_posy_msg_obs instead.")
  (vrpn_posy_msg_obs m))

(cl:ensure-generic-function 'vrpn_posz_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_posz_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_posz_msg_obs-val is deprecated.  Use estimate-msg:vrpn_posz_msg_obs instead.")
  (vrpn_posz_msg_obs m))

(cl:ensure-generic-function 'vrpn_velx_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_velx_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_velx_msg_obs-val is deprecated.  Use estimate-msg:vrpn_velx_msg_obs instead.")
  (vrpn_velx_msg_obs m))

(cl:ensure-generic-function 'vrpn_vely_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_vely_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_vely_msg_obs-val is deprecated.  Use estimate-msg:vrpn_vely_msg_obs instead.")
  (vrpn_vely_msg_obs m))

(cl:ensure-generic-function 'vrpn_velz_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_velz_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_velz_msg_obs-val is deprecated.  Use estimate-msg:vrpn_velz_msg_obs instead.")
  (vrpn_velz_msg_obs m))

(cl:ensure-generic-function 'vrpn_linx_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_linx_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_linx_msg_obs-val is deprecated.  Use estimate-msg:vrpn_linx_msg_obs instead.")
  (vrpn_linx_msg_obs m))

(cl:ensure-generic-function 'vrpn_liny_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_liny_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_liny_msg_obs-val is deprecated.  Use estimate-msg:vrpn_liny_msg_obs instead.")
  (vrpn_liny_msg_obs m))

(cl:ensure-generic-function 'vrpn_linz_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_linz_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_linz_msg_obs-val is deprecated.  Use estimate-msg:vrpn_linz_msg_obs instead.")
  (vrpn_linz_msg_obs m))

(cl:ensure-generic-function 'vrpn_orix_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_orix_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_orix_msg_obs-val is deprecated.  Use estimate-msg:vrpn_orix_msg_obs instead.")
  (vrpn_orix_msg_obs m))

(cl:ensure-generic-function 'vrpn_oriy_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_oriy_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_oriy_msg_obs-val is deprecated.  Use estimate-msg:vrpn_oriy_msg_obs instead.")
  (vrpn_oriy_msg_obs m))

(cl:ensure-generic-function 'vrpn_oriz_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_oriz_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_oriz_msg_obs-val is deprecated.  Use estimate-msg:vrpn_oriz_msg_obs instead.")
  (vrpn_oriz_msg_obs m))

(cl:ensure-generic-function 'vrpn_oriw_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_oriw_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_oriw_msg_obs-val is deprecated.  Use estimate-msg:vrpn_oriw_msg_obs instead.")
  (vrpn_oriw_msg_obs m))

(cl:ensure-generic-function 'vrpn_roll_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_roll_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_roll_msg_obs-val is deprecated.  Use estimate-msg:vrpn_roll_msg_obs instead.")
  (vrpn_roll_msg_obs m))

(cl:ensure-generic-function 'vrpn_pitch_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_pitch_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_pitch_msg_obs-val is deprecated.  Use estimate-msg:vrpn_pitch_msg_obs instead.")
  (vrpn_pitch_msg_obs m))

(cl:ensure-generic-function 'vrpn_yaw_msg_obs-val :lambda-list '(m))
(cl:defmethod vrpn_yaw_msg_obs-val ((m <msgCrazyflie_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate-msg:vrpn_yaw_msg_obs-val is deprecated.  Use estimate-msg:vrpn_yaw_msg_obs instead.")
  (vrpn_yaw_msg_obs m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <msgCrazyflie_data>) ostream)
  "Serializes a message object of type '<msgCrazyflie_data>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'imu_time_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'imu_angx_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'imu_angy_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'imu_angz_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'imu_linx_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'imu_liny_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'imu_linz_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_time_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_posx_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_posy_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_posz_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_velx_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_vely_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_velz_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_linx_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_liny_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_linz_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_orix_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_oriy_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_oriz_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_oriw_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_roll_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_pitch_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_yaw_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_time_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_posx_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_posy_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_posz_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_velx_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_vely_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_velz_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_linx_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_liny_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_linz_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_orix_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_oriy_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_oriz_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_oriw_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_roll_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_pitch_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vrpn_yaw_msg_obs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <msgCrazyflie_data>) istream)
  "Deserializes a message object of type '<msgCrazyflie_data>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_time_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_angx_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_angy_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_angz_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_linx_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_liny_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_linz_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_time_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_posx_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_posy_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_posz_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_velx_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_vely_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_velz_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_linx_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_liny_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_linz_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_orix_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_oriy_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_oriz_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_oriw_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_roll_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_pitch_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_yaw_msg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_time_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_posx_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_posy_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_posz_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_velx_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_vely_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_velz_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_linx_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_liny_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_linz_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_orix_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_oriy_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_oriz_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_oriw_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_roll_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_pitch_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vrpn_yaw_msg_obs) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<msgCrazyflie_data>)))
  "Returns string type for a message object of type '<msgCrazyflie_data>"
  "estimate/msgCrazyflie_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'msgCrazyflie_data)))
  "Returns string type for a message object of type 'msgCrazyflie_data"
  "estimate/msgCrazyflie_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<msgCrazyflie_data>)))
  "Returns md5sum for a message object of type '<msgCrazyflie_data>"
  "7b9455838bed400b7a1587cd4cf1be0a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'msgCrazyflie_data)))
  "Returns md5sum for a message object of type 'msgCrazyflie_data"
  "7b9455838bed400b7a1587cd4cf1be0a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<msgCrazyflie_data>)))
  "Returns full string definition for message of type '<msgCrazyflie_data>"
  (cl:format cl:nil "float64 imu_time_msg~%float64 imu_angx_msg~%float64 imu_angy_msg~%float64 imu_angz_msg~%float64 imu_linx_msg~%float64 imu_liny_msg~%float64 imu_linz_msg~%float64 vrpn_time_msg~%float64 vrpn_posx_msg~%float64 vrpn_posy_msg~%float64 vrpn_posz_msg~%float64 vrpn_velx_msg~%float64 vrpn_vely_msg~%float64 vrpn_velz_msg~%float64 vrpn_linx_msg~%float64 vrpn_liny_msg~%float64 vrpn_linz_msg~%float64 vrpn_orix_msg~%float64 vrpn_oriy_msg~%float64 vrpn_oriz_msg~%float64 vrpn_oriw_msg~%float64 vrpn_roll_msg~%float64 vrpn_pitch_msg~%float64 vrpn_yaw_msg~%~%float64 vrpn_time_msg_obs~%float64 vrpn_posx_msg_obs~%float64 vrpn_posy_msg_obs~%float64 vrpn_posz_msg_obs~%float64 vrpn_velx_msg_obs~%float64 vrpn_vely_msg_obs~%float64 vrpn_velz_msg_obs~%float64 vrpn_linx_msg_obs~%float64 vrpn_liny_msg_obs~%float64 vrpn_linz_msg_obs~%float64 vrpn_orix_msg_obs~%float64 vrpn_oriy_msg_obs~%float64 vrpn_oriz_msg_obs~%float64 vrpn_oriw_msg_obs~%float64 vrpn_roll_msg_obs~%float64 vrpn_pitch_msg_obs~%float64 vrpn_yaw_msg_obs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'msgCrazyflie_data)))
  "Returns full string definition for message of type 'msgCrazyflie_data"
  (cl:format cl:nil "float64 imu_time_msg~%float64 imu_angx_msg~%float64 imu_angy_msg~%float64 imu_angz_msg~%float64 imu_linx_msg~%float64 imu_liny_msg~%float64 imu_linz_msg~%float64 vrpn_time_msg~%float64 vrpn_posx_msg~%float64 vrpn_posy_msg~%float64 vrpn_posz_msg~%float64 vrpn_velx_msg~%float64 vrpn_vely_msg~%float64 vrpn_velz_msg~%float64 vrpn_linx_msg~%float64 vrpn_liny_msg~%float64 vrpn_linz_msg~%float64 vrpn_orix_msg~%float64 vrpn_oriy_msg~%float64 vrpn_oriz_msg~%float64 vrpn_oriw_msg~%float64 vrpn_roll_msg~%float64 vrpn_pitch_msg~%float64 vrpn_yaw_msg~%~%float64 vrpn_time_msg_obs~%float64 vrpn_posx_msg_obs~%float64 vrpn_posy_msg_obs~%float64 vrpn_posz_msg_obs~%float64 vrpn_velx_msg_obs~%float64 vrpn_vely_msg_obs~%float64 vrpn_velz_msg_obs~%float64 vrpn_linx_msg_obs~%float64 vrpn_liny_msg_obs~%float64 vrpn_linz_msg_obs~%float64 vrpn_orix_msg_obs~%float64 vrpn_oriy_msg_obs~%float64 vrpn_oriz_msg_obs~%float64 vrpn_oriw_msg_obs~%float64 vrpn_roll_msg_obs~%float64 vrpn_pitch_msg_obs~%float64 vrpn_yaw_msg_obs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <msgCrazyflie_data>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <msgCrazyflie_data>))
  "Converts a ROS message object to a list"
  (cl:list 'msgCrazyflie_data
    (cl:cons ':imu_time_msg (imu_time_msg msg))
    (cl:cons ':imu_angx_msg (imu_angx_msg msg))
    (cl:cons ':imu_angy_msg (imu_angy_msg msg))
    (cl:cons ':imu_angz_msg (imu_angz_msg msg))
    (cl:cons ':imu_linx_msg (imu_linx_msg msg))
    (cl:cons ':imu_liny_msg (imu_liny_msg msg))
    (cl:cons ':imu_linz_msg (imu_linz_msg msg))
    (cl:cons ':vrpn_time_msg (vrpn_time_msg msg))
    (cl:cons ':vrpn_posx_msg (vrpn_posx_msg msg))
    (cl:cons ':vrpn_posy_msg (vrpn_posy_msg msg))
    (cl:cons ':vrpn_posz_msg (vrpn_posz_msg msg))
    (cl:cons ':vrpn_velx_msg (vrpn_velx_msg msg))
    (cl:cons ':vrpn_vely_msg (vrpn_vely_msg msg))
    (cl:cons ':vrpn_velz_msg (vrpn_velz_msg msg))
    (cl:cons ':vrpn_linx_msg (vrpn_linx_msg msg))
    (cl:cons ':vrpn_liny_msg (vrpn_liny_msg msg))
    (cl:cons ':vrpn_linz_msg (vrpn_linz_msg msg))
    (cl:cons ':vrpn_orix_msg (vrpn_orix_msg msg))
    (cl:cons ':vrpn_oriy_msg (vrpn_oriy_msg msg))
    (cl:cons ':vrpn_oriz_msg (vrpn_oriz_msg msg))
    (cl:cons ':vrpn_oriw_msg (vrpn_oriw_msg msg))
    (cl:cons ':vrpn_roll_msg (vrpn_roll_msg msg))
    (cl:cons ':vrpn_pitch_msg (vrpn_pitch_msg msg))
    (cl:cons ':vrpn_yaw_msg (vrpn_yaw_msg msg))
    (cl:cons ':vrpn_time_msg_obs (vrpn_time_msg_obs msg))
    (cl:cons ':vrpn_posx_msg_obs (vrpn_posx_msg_obs msg))
    (cl:cons ':vrpn_posy_msg_obs (vrpn_posy_msg_obs msg))
    (cl:cons ':vrpn_posz_msg_obs (vrpn_posz_msg_obs msg))
    (cl:cons ':vrpn_velx_msg_obs (vrpn_velx_msg_obs msg))
    (cl:cons ':vrpn_vely_msg_obs (vrpn_vely_msg_obs msg))
    (cl:cons ':vrpn_velz_msg_obs (vrpn_velz_msg_obs msg))
    (cl:cons ':vrpn_linx_msg_obs (vrpn_linx_msg_obs msg))
    (cl:cons ':vrpn_liny_msg_obs (vrpn_liny_msg_obs msg))
    (cl:cons ':vrpn_linz_msg_obs (vrpn_linz_msg_obs msg))
    (cl:cons ':vrpn_orix_msg_obs (vrpn_orix_msg_obs msg))
    (cl:cons ':vrpn_oriy_msg_obs (vrpn_oriy_msg_obs msg))
    (cl:cons ':vrpn_oriz_msg_obs (vrpn_oriz_msg_obs msg))
    (cl:cons ':vrpn_oriw_msg_obs (vrpn_oriw_msg_obs msg))
    (cl:cons ':vrpn_roll_msg_obs (vrpn_roll_msg_obs msg))
    (cl:cons ':vrpn_pitch_msg_obs (vrpn_pitch_msg_obs msg))
    (cl:cons ':vrpn_yaw_msg_obs (vrpn_yaw_msg_obs msg))
))
