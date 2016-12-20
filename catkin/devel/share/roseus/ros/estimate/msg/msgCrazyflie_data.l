;; Auto-generated. Do not edit!


(when (boundp 'estimate::msgCrazyflie_data)
  (if (not (find-package "ESTIMATE"))
    (make-package "ESTIMATE"))
  (shadow 'msgCrazyflie_data (find-package "ESTIMATE")))
(unless (find-package "ESTIMATE::MSGCRAZYFLIE_DATA")
  (make-package "ESTIMATE::MSGCRAZYFLIE_DATA"))

(in-package "ROS")
;;//! \htmlinclude msgCrazyflie_data.msg.html


(defclass estimate::msgCrazyflie_data
  :super ros::object
  :slots (_imu_time_msg _imu_angx_msg _imu_angy_msg _imu_angz_msg _imu_linx_msg _imu_liny_msg _imu_linz_msg _vrpn_time_msg _vrpn_posx_msg _vrpn_posy_msg _vrpn_posz_msg _vrpn_velx_msg _vrpn_vely_msg _vrpn_velz_msg _vrpn_linx_msg _vrpn_liny_msg _vrpn_linz_msg _vrpn_orix_msg _vrpn_oriy_msg _vrpn_oriz_msg _vrpn_oriw_msg _vrpn_roll_msg _vrpn_pitch_msg _vrpn_yaw_msg _vrpn_time_msg_obs _vrpn_posx_msg_obs _vrpn_posy_msg_obs _vrpn_posz_msg_obs _vrpn_velx_msg_obs _vrpn_vely_msg_obs _vrpn_velz_msg_obs _vrpn_linx_msg_obs _vrpn_liny_msg_obs _vrpn_linz_msg_obs _vrpn_orix_msg_obs _vrpn_oriy_msg_obs _vrpn_oriz_msg_obs _vrpn_oriw_msg_obs _vrpn_roll_msg_obs _vrpn_pitch_msg_obs _vrpn_yaw_msg_obs ))

(defmethod estimate::msgCrazyflie_data
  (:init
   (&key
    ((:imu_time_msg __imu_time_msg) 0.0)
    ((:imu_angx_msg __imu_angx_msg) 0.0)
    ((:imu_angy_msg __imu_angy_msg) 0.0)
    ((:imu_angz_msg __imu_angz_msg) 0.0)
    ((:imu_linx_msg __imu_linx_msg) 0.0)
    ((:imu_liny_msg __imu_liny_msg) 0.0)
    ((:imu_linz_msg __imu_linz_msg) 0.0)
    ((:vrpn_time_msg __vrpn_time_msg) 0.0)
    ((:vrpn_posx_msg __vrpn_posx_msg) 0.0)
    ((:vrpn_posy_msg __vrpn_posy_msg) 0.0)
    ((:vrpn_posz_msg __vrpn_posz_msg) 0.0)
    ((:vrpn_velx_msg __vrpn_velx_msg) 0.0)
    ((:vrpn_vely_msg __vrpn_vely_msg) 0.0)
    ((:vrpn_velz_msg __vrpn_velz_msg) 0.0)
    ((:vrpn_linx_msg __vrpn_linx_msg) 0.0)
    ((:vrpn_liny_msg __vrpn_liny_msg) 0.0)
    ((:vrpn_linz_msg __vrpn_linz_msg) 0.0)
    ((:vrpn_orix_msg __vrpn_orix_msg) 0.0)
    ((:vrpn_oriy_msg __vrpn_oriy_msg) 0.0)
    ((:vrpn_oriz_msg __vrpn_oriz_msg) 0.0)
    ((:vrpn_oriw_msg __vrpn_oriw_msg) 0.0)
    ((:vrpn_roll_msg __vrpn_roll_msg) 0.0)
    ((:vrpn_pitch_msg __vrpn_pitch_msg) 0.0)
    ((:vrpn_yaw_msg __vrpn_yaw_msg) 0.0)
    ((:vrpn_time_msg_obs __vrpn_time_msg_obs) 0.0)
    ((:vrpn_posx_msg_obs __vrpn_posx_msg_obs) 0.0)
    ((:vrpn_posy_msg_obs __vrpn_posy_msg_obs) 0.0)
    ((:vrpn_posz_msg_obs __vrpn_posz_msg_obs) 0.0)
    ((:vrpn_velx_msg_obs __vrpn_velx_msg_obs) 0.0)
    ((:vrpn_vely_msg_obs __vrpn_vely_msg_obs) 0.0)
    ((:vrpn_velz_msg_obs __vrpn_velz_msg_obs) 0.0)
    ((:vrpn_linx_msg_obs __vrpn_linx_msg_obs) 0.0)
    ((:vrpn_liny_msg_obs __vrpn_liny_msg_obs) 0.0)
    ((:vrpn_linz_msg_obs __vrpn_linz_msg_obs) 0.0)
    ((:vrpn_orix_msg_obs __vrpn_orix_msg_obs) 0.0)
    ((:vrpn_oriy_msg_obs __vrpn_oriy_msg_obs) 0.0)
    ((:vrpn_oriz_msg_obs __vrpn_oriz_msg_obs) 0.0)
    ((:vrpn_oriw_msg_obs __vrpn_oriw_msg_obs) 0.0)
    ((:vrpn_roll_msg_obs __vrpn_roll_msg_obs) 0.0)
    ((:vrpn_pitch_msg_obs __vrpn_pitch_msg_obs) 0.0)
    ((:vrpn_yaw_msg_obs __vrpn_yaw_msg_obs) 0.0)
    )
   (send-super :init)
   (setq _imu_time_msg (float __imu_time_msg))
   (setq _imu_angx_msg (float __imu_angx_msg))
   (setq _imu_angy_msg (float __imu_angy_msg))
   (setq _imu_angz_msg (float __imu_angz_msg))
   (setq _imu_linx_msg (float __imu_linx_msg))
   (setq _imu_liny_msg (float __imu_liny_msg))
   (setq _imu_linz_msg (float __imu_linz_msg))
   (setq _vrpn_time_msg (float __vrpn_time_msg))
   (setq _vrpn_posx_msg (float __vrpn_posx_msg))
   (setq _vrpn_posy_msg (float __vrpn_posy_msg))
   (setq _vrpn_posz_msg (float __vrpn_posz_msg))
   (setq _vrpn_velx_msg (float __vrpn_velx_msg))
   (setq _vrpn_vely_msg (float __vrpn_vely_msg))
   (setq _vrpn_velz_msg (float __vrpn_velz_msg))
   (setq _vrpn_linx_msg (float __vrpn_linx_msg))
   (setq _vrpn_liny_msg (float __vrpn_liny_msg))
   (setq _vrpn_linz_msg (float __vrpn_linz_msg))
   (setq _vrpn_orix_msg (float __vrpn_orix_msg))
   (setq _vrpn_oriy_msg (float __vrpn_oriy_msg))
   (setq _vrpn_oriz_msg (float __vrpn_oriz_msg))
   (setq _vrpn_oriw_msg (float __vrpn_oriw_msg))
   (setq _vrpn_roll_msg (float __vrpn_roll_msg))
   (setq _vrpn_pitch_msg (float __vrpn_pitch_msg))
   (setq _vrpn_yaw_msg (float __vrpn_yaw_msg))
   (setq _vrpn_time_msg_obs (float __vrpn_time_msg_obs))
   (setq _vrpn_posx_msg_obs (float __vrpn_posx_msg_obs))
   (setq _vrpn_posy_msg_obs (float __vrpn_posy_msg_obs))
   (setq _vrpn_posz_msg_obs (float __vrpn_posz_msg_obs))
   (setq _vrpn_velx_msg_obs (float __vrpn_velx_msg_obs))
   (setq _vrpn_vely_msg_obs (float __vrpn_vely_msg_obs))
   (setq _vrpn_velz_msg_obs (float __vrpn_velz_msg_obs))
   (setq _vrpn_linx_msg_obs (float __vrpn_linx_msg_obs))
   (setq _vrpn_liny_msg_obs (float __vrpn_liny_msg_obs))
   (setq _vrpn_linz_msg_obs (float __vrpn_linz_msg_obs))
   (setq _vrpn_orix_msg_obs (float __vrpn_orix_msg_obs))
   (setq _vrpn_oriy_msg_obs (float __vrpn_oriy_msg_obs))
   (setq _vrpn_oriz_msg_obs (float __vrpn_oriz_msg_obs))
   (setq _vrpn_oriw_msg_obs (float __vrpn_oriw_msg_obs))
   (setq _vrpn_roll_msg_obs (float __vrpn_roll_msg_obs))
   (setq _vrpn_pitch_msg_obs (float __vrpn_pitch_msg_obs))
   (setq _vrpn_yaw_msg_obs (float __vrpn_yaw_msg_obs))
   self)
  (:imu_time_msg
   (&optional __imu_time_msg)
   (if __imu_time_msg (setq _imu_time_msg __imu_time_msg)) _imu_time_msg)
  (:imu_angx_msg
   (&optional __imu_angx_msg)
   (if __imu_angx_msg (setq _imu_angx_msg __imu_angx_msg)) _imu_angx_msg)
  (:imu_angy_msg
   (&optional __imu_angy_msg)
   (if __imu_angy_msg (setq _imu_angy_msg __imu_angy_msg)) _imu_angy_msg)
  (:imu_angz_msg
   (&optional __imu_angz_msg)
   (if __imu_angz_msg (setq _imu_angz_msg __imu_angz_msg)) _imu_angz_msg)
  (:imu_linx_msg
   (&optional __imu_linx_msg)
   (if __imu_linx_msg (setq _imu_linx_msg __imu_linx_msg)) _imu_linx_msg)
  (:imu_liny_msg
   (&optional __imu_liny_msg)
   (if __imu_liny_msg (setq _imu_liny_msg __imu_liny_msg)) _imu_liny_msg)
  (:imu_linz_msg
   (&optional __imu_linz_msg)
   (if __imu_linz_msg (setq _imu_linz_msg __imu_linz_msg)) _imu_linz_msg)
  (:vrpn_time_msg
   (&optional __vrpn_time_msg)
   (if __vrpn_time_msg (setq _vrpn_time_msg __vrpn_time_msg)) _vrpn_time_msg)
  (:vrpn_posx_msg
   (&optional __vrpn_posx_msg)
   (if __vrpn_posx_msg (setq _vrpn_posx_msg __vrpn_posx_msg)) _vrpn_posx_msg)
  (:vrpn_posy_msg
   (&optional __vrpn_posy_msg)
   (if __vrpn_posy_msg (setq _vrpn_posy_msg __vrpn_posy_msg)) _vrpn_posy_msg)
  (:vrpn_posz_msg
   (&optional __vrpn_posz_msg)
   (if __vrpn_posz_msg (setq _vrpn_posz_msg __vrpn_posz_msg)) _vrpn_posz_msg)
  (:vrpn_velx_msg
   (&optional __vrpn_velx_msg)
   (if __vrpn_velx_msg (setq _vrpn_velx_msg __vrpn_velx_msg)) _vrpn_velx_msg)
  (:vrpn_vely_msg
   (&optional __vrpn_vely_msg)
   (if __vrpn_vely_msg (setq _vrpn_vely_msg __vrpn_vely_msg)) _vrpn_vely_msg)
  (:vrpn_velz_msg
   (&optional __vrpn_velz_msg)
   (if __vrpn_velz_msg (setq _vrpn_velz_msg __vrpn_velz_msg)) _vrpn_velz_msg)
  (:vrpn_linx_msg
   (&optional __vrpn_linx_msg)
   (if __vrpn_linx_msg (setq _vrpn_linx_msg __vrpn_linx_msg)) _vrpn_linx_msg)
  (:vrpn_liny_msg
   (&optional __vrpn_liny_msg)
   (if __vrpn_liny_msg (setq _vrpn_liny_msg __vrpn_liny_msg)) _vrpn_liny_msg)
  (:vrpn_linz_msg
   (&optional __vrpn_linz_msg)
   (if __vrpn_linz_msg (setq _vrpn_linz_msg __vrpn_linz_msg)) _vrpn_linz_msg)
  (:vrpn_orix_msg
   (&optional __vrpn_orix_msg)
   (if __vrpn_orix_msg (setq _vrpn_orix_msg __vrpn_orix_msg)) _vrpn_orix_msg)
  (:vrpn_oriy_msg
   (&optional __vrpn_oriy_msg)
   (if __vrpn_oriy_msg (setq _vrpn_oriy_msg __vrpn_oriy_msg)) _vrpn_oriy_msg)
  (:vrpn_oriz_msg
   (&optional __vrpn_oriz_msg)
   (if __vrpn_oriz_msg (setq _vrpn_oriz_msg __vrpn_oriz_msg)) _vrpn_oriz_msg)
  (:vrpn_oriw_msg
   (&optional __vrpn_oriw_msg)
   (if __vrpn_oriw_msg (setq _vrpn_oriw_msg __vrpn_oriw_msg)) _vrpn_oriw_msg)
  (:vrpn_roll_msg
   (&optional __vrpn_roll_msg)
   (if __vrpn_roll_msg (setq _vrpn_roll_msg __vrpn_roll_msg)) _vrpn_roll_msg)
  (:vrpn_pitch_msg
   (&optional __vrpn_pitch_msg)
   (if __vrpn_pitch_msg (setq _vrpn_pitch_msg __vrpn_pitch_msg)) _vrpn_pitch_msg)
  (:vrpn_yaw_msg
   (&optional __vrpn_yaw_msg)
   (if __vrpn_yaw_msg (setq _vrpn_yaw_msg __vrpn_yaw_msg)) _vrpn_yaw_msg)
  (:vrpn_time_msg_obs
   (&optional __vrpn_time_msg_obs)
   (if __vrpn_time_msg_obs (setq _vrpn_time_msg_obs __vrpn_time_msg_obs)) _vrpn_time_msg_obs)
  (:vrpn_posx_msg_obs
   (&optional __vrpn_posx_msg_obs)
   (if __vrpn_posx_msg_obs (setq _vrpn_posx_msg_obs __vrpn_posx_msg_obs)) _vrpn_posx_msg_obs)
  (:vrpn_posy_msg_obs
   (&optional __vrpn_posy_msg_obs)
   (if __vrpn_posy_msg_obs (setq _vrpn_posy_msg_obs __vrpn_posy_msg_obs)) _vrpn_posy_msg_obs)
  (:vrpn_posz_msg_obs
   (&optional __vrpn_posz_msg_obs)
   (if __vrpn_posz_msg_obs (setq _vrpn_posz_msg_obs __vrpn_posz_msg_obs)) _vrpn_posz_msg_obs)
  (:vrpn_velx_msg_obs
   (&optional __vrpn_velx_msg_obs)
   (if __vrpn_velx_msg_obs (setq _vrpn_velx_msg_obs __vrpn_velx_msg_obs)) _vrpn_velx_msg_obs)
  (:vrpn_vely_msg_obs
   (&optional __vrpn_vely_msg_obs)
   (if __vrpn_vely_msg_obs (setq _vrpn_vely_msg_obs __vrpn_vely_msg_obs)) _vrpn_vely_msg_obs)
  (:vrpn_velz_msg_obs
   (&optional __vrpn_velz_msg_obs)
   (if __vrpn_velz_msg_obs (setq _vrpn_velz_msg_obs __vrpn_velz_msg_obs)) _vrpn_velz_msg_obs)
  (:vrpn_linx_msg_obs
   (&optional __vrpn_linx_msg_obs)
   (if __vrpn_linx_msg_obs (setq _vrpn_linx_msg_obs __vrpn_linx_msg_obs)) _vrpn_linx_msg_obs)
  (:vrpn_liny_msg_obs
   (&optional __vrpn_liny_msg_obs)
   (if __vrpn_liny_msg_obs (setq _vrpn_liny_msg_obs __vrpn_liny_msg_obs)) _vrpn_liny_msg_obs)
  (:vrpn_linz_msg_obs
   (&optional __vrpn_linz_msg_obs)
   (if __vrpn_linz_msg_obs (setq _vrpn_linz_msg_obs __vrpn_linz_msg_obs)) _vrpn_linz_msg_obs)
  (:vrpn_orix_msg_obs
   (&optional __vrpn_orix_msg_obs)
   (if __vrpn_orix_msg_obs (setq _vrpn_orix_msg_obs __vrpn_orix_msg_obs)) _vrpn_orix_msg_obs)
  (:vrpn_oriy_msg_obs
   (&optional __vrpn_oriy_msg_obs)
   (if __vrpn_oriy_msg_obs (setq _vrpn_oriy_msg_obs __vrpn_oriy_msg_obs)) _vrpn_oriy_msg_obs)
  (:vrpn_oriz_msg_obs
   (&optional __vrpn_oriz_msg_obs)
   (if __vrpn_oriz_msg_obs (setq _vrpn_oriz_msg_obs __vrpn_oriz_msg_obs)) _vrpn_oriz_msg_obs)
  (:vrpn_oriw_msg_obs
   (&optional __vrpn_oriw_msg_obs)
   (if __vrpn_oriw_msg_obs (setq _vrpn_oriw_msg_obs __vrpn_oriw_msg_obs)) _vrpn_oriw_msg_obs)
  (:vrpn_roll_msg_obs
   (&optional __vrpn_roll_msg_obs)
   (if __vrpn_roll_msg_obs (setq _vrpn_roll_msg_obs __vrpn_roll_msg_obs)) _vrpn_roll_msg_obs)
  (:vrpn_pitch_msg_obs
   (&optional __vrpn_pitch_msg_obs)
   (if __vrpn_pitch_msg_obs (setq _vrpn_pitch_msg_obs __vrpn_pitch_msg_obs)) _vrpn_pitch_msg_obs)
  (:vrpn_yaw_msg_obs
   (&optional __vrpn_yaw_msg_obs)
   (if __vrpn_yaw_msg_obs (setq _vrpn_yaw_msg_obs __vrpn_yaw_msg_obs)) _vrpn_yaw_msg_obs)
  (:serialization-length
   ()
   (+
    ;; float64 _imu_time_msg
    8
    ;; float64 _imu_angx_msg
    8
    ;; float64 _imu_angy_msg
    8
    ;; float64 _imu_angz_msg
    8
    ;; float64 _imu_linx_msg
    8
    ;; float64 _imu_liny_msg
    8
    ;; float64 _imu_linz_msg
    8
    ;; float64 _vrpn_time_msg
    8
    ;; float64 _vrpn_posx_msg
    8
    ;; float64 _vrpn_posy_msg
    8
    ;; float64 _vrpn_posz_msg
    8
    ;; float64 _vrpn_velx_msg
    8
    ;; float64 _vrpn_vely_msg
    8
    ;; float64 _vrpn_velz_msg
    8
    ;; float64 _vrpn_linx_msg
    8
    ;; float64 _vrpn_liny_msg
    8
    ;; float64 _vrpn_linz_msg
    8
    ;; float64 _vrpn_orix_msg
    8
    ;; float64 _vrpn_oriy_msg
    8
    ;; float64 _vrpn_oriz_msg
    8
    ;; float64 _vrpn_oriw_msg
    8
    ;; float64 _vrpn_roll_msg
    8
    ;; float64 _vrpn_pitch_msg
    8
    ;; float64 _vrpn_yaw_msg
    8
    ;; float64 _vrpn_time_msg_obs
    8
    ;; float64 _vrpn_posx_msg_obs
    8
    ;; float64 _vrpn_posy_msg_obs
    8
    ;; float64 _vrpn_posz_msg_obs
    8
    ;; float64 _vrpn_velx_msg_obs
    8
    ;; float64 _vrpn_vely_msg_obs
    8
    ;; float64 _vrpn_velz_msg_obs
    8
    ;; float64 _vrpn_linx_msg_obs
    8
    ;; float64 _vrpn_liny_msg_obs
    8
    ;; float64 _vrpn_linz_msg_obs
    8
    ;; float64 _vrpn_orix_msg_obs
    8
    ;; float64 _vrpn_oriy_msg_obs
    8
    ;; float64 _vrpn_oriz_msg_obs
    8
    ;; float64 _vrpn_oriw_msg_obs
    8
    ;; float64 _vrpn_roll_msg_obs
    8
    ;; float64 _vrpn_pitch_msg_obs
    8
    ;; float64 _vrpn_yaw_msg_obs
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _imu_time_msg
       (sys::poke _imu_time_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _imu_angx_msg
       (sys::poke _imu_angx_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _imu_angy_msg
       (sys::poke _imu_angy_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _imu_angz_msg
       (sys::poke _imu_angz_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _imu_linx_msg
       (sys::poke _imu_linx_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _imu_liny_msg
       (sys::poke _imu_liny_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _imu_linz_msg
       (sys::poke _imu_linz_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_time_msg
       (sys::poke _vrpn_time_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_posx_msg
       (sys::poke _vrpn_posx_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_posy_msg
       (sys::poke _vrpn_posy_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_posz_msg
       (sys::poke _vrpn_posz_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_velx_msg
       (sys::poke _vrpn_velx_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_vely_msg
       (sys::poke _vrpn_vely_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_velz_msg
       (sys::poke _vrpn_velz_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_linx_msg
       (sys::poke _vrpn_linx_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_liny_msg
       (sys::poke _vrpn_liny_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_linz_msg
       (sys::poke _vrpn_linz_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_orix_msg
       (sys::poke _vrpn_orix_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_oriy_msg
       (sys::poke _vrpn_oriy_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_oriz_msg
       (sys::poke _vrpn_oriz_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_oriw_msg
       (sys::poke _vrpn_oriw_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_roll_msg
       (sys::poke _vrpn_roll_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_pitch_msg
       (sys::poke _vrpn_pitch_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_yaw_msg
       (sys::poke _vrpn_yaw_msg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_time_msg_obs
       (sys::poke _vrpn_time_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_posx_msg_obs
       (sys::poke _vrpn_posx_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_posy_msg_obs
       (sys::poke _vrpn_posy_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_posz_msg_obs
       (sys::poke _vrpn_posz_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_velx_msg_obs
       (sys::poke _vrpn_velx_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_vely_msg_obs
       (sys::poke _vrpn_vely_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_velz_msg_obs
       (sys::poke _vrpn_velz_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_linx_msg_obs
       (sys::poke _vrpn_linx_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_liny_msg_obs
       (sys::poke _vrpn_liny_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_linz_msg_obs
       (sys::poke _vrpn_linz_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_orix_msg_obs
       (sys::poke _vrpn_orix_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_oriy_msg_obs
       (sys::poke _vrpn_oriy_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_oriz_msg_obs
       (sys::poke _vrpn_oriz_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_oriw_msg_obs
       (sys::poke _vrpn_oriw_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_roll_msg_obs
       (sys::poke _vrpn_roll_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_pitch_msg_obs
       (sys::poke _vrpn_pitch_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vrpn_yaw_msg_obs
       (sys::poke _vrpn_yaw_msg_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _imu_time_msg
     (setq _imu_time_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _imu_angx_msg
     (setq _imu_angx_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _imu_angy_msg
     (setq _imu_angy_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _imu_angz_msg
     (setq _imu_angz_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _imu_linx_msg
     (setq _imu_linx_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _imu_liny_msg
     (setq _imu_liny_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _imu_linz_msg
     (setq _imu_linz_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_time_msg
     (setq _vrpn_time_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_posx_msg
     (setq _vrpn_posx_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_posy_msg
     (setq _vrpn_posy_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_posz_msg
     (setq _vrpn_posz_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_velx_msg
     (setq _vrpn_velx_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_vely_msg
     (setq _vrpn_vely_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_velz_msg
     (setq _vrpn_velz_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_linx_msg
     (setq _vrpn_linx_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_liny_msg
     (setq _vrpn_liny_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_linz_msg
     (setq _vrpn_linz_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_orix_msg
     (setq _vrpn_orix_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_oriy_msg
     (setq _vrpn_oriy_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_oriz_msg
     (setq _vrpn_oriz_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_oriw_msg
     (setq _vrpn_oriw_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_roll_msg
     (setq _vrpn_roll_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_pitch_msg
     (setq _vrpn_pitch_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_yaw_msg
     (setq _vrpn_yaw_msg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_time_msg_obs
     (setq _vrpn_time_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_posx_msg_obs
     (setq _vrpn_posx_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_posy_msg_obs
     (setq _vrpn_posy_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_posz_msg_obs
     (setq _vrpn_posz_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_velx_msg_obs
     (setq _vrpn_velx_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_vely_msg_obs
     (setq _vrpn_vely_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_velz_msg_obs
     (setq _vrpn_velz_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_linx_msg_obs
     (setq _vrpn_linx_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_liny_msg_obs
     (setq _vrpn_liny_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_linz_msg_obs
     (setq _vrpn_linz_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_orix_msg_obs
     (setq _vrpn_orix_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_oriy_msg_obs
     (setq _vrpn_oriy_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_oriz_msg_obs
     (setq _vrpn_oriz_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_oriw_msg_obs
     (setq _vrpn_oriw_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_roll_msg_obs
     (setq _vrpn_roll_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_pitch_msg_obs
     (setq _vrpn_pitch_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vrpn_yaw_msg_obs
     (setq _vrpn_yaw_msg_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get estimate::msgCrazyflie_data :md5sum-) "7b9455838bed400b7a1587cd4cf1be0a")
(setf (get estimate::msgCrazyflie_data :datatype-) "estimate/msgCrazyflie_data")
(setf (get estimate::msgCrazyflie_data :definition-)
      "float64 imu_time_msg
float64 imu_angx_msg
float64 imu_angy_msg
float64 imu_angz_msg
float64 imu_linx_msg
float64 imu_liny_msg
float64 imu_linz_msg
float64 vrpn_time_msg
float64 vrpn_posx_msg
float64 vrpn_posy_msg
float64 vrpn_posz_msg
float64 vrpn_velx_msg
float64 vrpn_vely_msg
float64 vrpn_velz_msg
float64 vrpn_linx_msg
float64 vrpn_liny_msg
float64 vrpn_linz_msg
float64 vrpn_orix_msg
float64 vrpn_oriy_msg
float64 vrpn_oriz_msg
float64 vrpn_oriw_msg
float64 vrpn_roll_msg
float64 vrpn_pitch_msg
float64 vrpn_yaw_msg

float64 vrpn_time_msg_obs
float64 vrpn_posx_msg_obs
float64 vrpn_posy_msg_obs
float64 vrpn_posz_msg_obs
float64 vrpn_velx_msg_obs
float64 vrpn_vely_msg_obs
float64 vrpn_velz_msg_obs
float64 vrpn_linx_msg_obs
float64 vrpn_liny_msg_obs
float64 vrpn_linz_msg_obs
float64 vrpn_orix_msg_obs
float64 vrpn_oriy_msg_obs
float64 vrpn_oriz_msg_obs
float64 vrpn_oriw_msg_obs
float64 vrpn_roll_msg_obs
float64 vrpn_pitch_msg_obs
float64 vrpn_yaw_msg_obs

")



(provide :estimate/msgCrazyflie_data "7b9455838bed400b7a1587cd4cf1be0a")


