;; Auto-generated. Do not edit!


(when (boundp 'mpc::msgMPC_Data)
  (if (not (find-package "MPC"))
    (make-package "MPC"))
  (shadow 'msgMPC_Data (find-package "MPC")))
(unless (find-package "MPC::MSGMPC_DATA")
  (make-package "MPC::MSGMPC_DATA"))

(in-package "ROS")
;;//! \htmlinclude msgMPC_Data.msg.html


(defclass mpc::msgMPC_Data
  :super ros::object
  :slots (_xpos _ypos _zpos _sw _xpos_ref _ypos_ref _zpos_ref _xvel _yvel _zvel _phi _theta _psi _thrust _xpos_obs _ypos_obs _zpos_obs ))

(defmethod mpc::msgMPC_Data
  (:init
   (&key
    ((:xpos __xpos) 0.0)
    ((:ypos __ypos) 0.0)
    ((:zpos __zpos) 0.0)
    ((:sw __sw) 0)
    ((:xpos_ref __xpos_ref) 0.0)
    ((:ypos_ref __ypos_ref) 0.0)
    ((:zpos_ref __zpos_ref) 0.0)
    ((:xvel __xvel) 0.0)
    ((:yvel __yvel) 0.0)
    ((:zvel __zvel) 0.0)
    ((:phi __phi) 0.0)
    ((:theta __theta) 0.0)
    ((:psi __psi) 0.0)
    ((:thrust __thrust) 0.0)
    ((:xpos_obs __xpos_obs) 0.0)
    ((:ypos_obs __ypos_obs) 0.0)
    ((:zpos_obs __zpos_obs) 0.0)
    )
   (send-super :init)
   (setq _xpos (float __xpos))
   (setq _ypos (float __ypos))
   (setq _zpos (float __zpos))
   (setq _sw (round __sw))
   (setq _xpos_ref (float __xpos_ref))
   (setq _ypos_ref (float __ypos_ref))
   (setq _zpos_ref (float __zpos_ref))
   (setq _xvel (float __xvel))
   (setq _yvel (float __yvel))
   (setq _zvel (float __zvel))
   (setq _phi (float __phi))
   (setq _theta (float __theta))
   (setq _psi (float __psi))
   (setq _thrust (float __thrust))
   (setq _xpos_obs (float __xpos_obs))
   (setq _ypos_obs (float __ypos_obs))
   (setq _zpos_obs (float __zpos_obs))
   self)
  (:xpos
   (&optional __xpos)
   (if __xpos (setq _xpos __xpos)) _xpos)
  (:ypos
   (&optional __ypos)
   (if __ypos (setq _ypos __ypos)) _ypos)
  (:zpos
   (&optional __zpos)
   (if __zpos (setq _zpos __zpos)) _zpos)
  (:sw
   (&optional __sw)
   (if __sw (setq _sw __sw)) _sw)
  (:xpos_ref
   (&optional __xpos_ref)
   (if __xpos_ref (setq _xpos_ref __xpos_ref)) _xpos_ref)
  (:ypos_ref
   (&optional __ypos_ref)
   (if __ypos_ref (setq _ypos_ref __ypos_ref)) _ypos_ref)
  (:zpos_ref
   (&optional __zpos_ref)
   (if __zpos_ref (setq _zpos_ref __zpos_ref)) _zpos_ref)
  (:xvel
   (&optional __xvel)
   (if __xvel (setq _xvel __xvel)) _xvel)
  (:yvel
   (&optional __yvel)
   (if __yvel (setq _yvel __yvel)) _yvel)
  (:zvel
   (&optional __zvel)
   (if __zvel (setq _zvel __zvel)) _zvel)
  (:phi
   (&optional __phi)
   (if __phi (setq _phi __phi)) _phi)
  (:theta
   (&optional __theta)
   (if __theta (setq _theta __theta)) _theta)
  (:psi
   (&optional __psi)
   (if __psi (setq _psi __psi)) _psi)
  (:thrust
   (&optional __thrust)
   (if __thrust (setq _thrust __thrust)) _thrust)
  (:xpos_obs
   (&optional __xpos_obs)
   (if __xpos_obs (setq _xpos_obs __xpos_obs)) _xpos_obs)
  (:ypos_obs
   (&optional __ypos_obs)
   (if __ypos_obs (setq _ypos_obs __ypos_obs)) _ypos_obs)
  (:zpos_obs
   (&optional __zpos_obs)
   (if __zpos_obs (setq _zpos_obs __zpos_obs)) _zpos_obs)
  (:serialization-length
   ()
   (+
    ;; float64 _xpos
    8
    ;; float64 _ypos
    8
    ;; float64 _zpos
    8
    ;; int16 _sw
    2
    ;; float64 _xpos_ref
    8
    ;; float64 _ypos_ref
    8
    ;; float64 _zpos_ref
    8
    ;; float64 _xvel
    8
    ;; float64 _yvel
    8
    ;; float64 _zvel
    8
    ;; float64 _phi
    8
    ;; float64 _theta
    8
    ;; float64 _psi
    8
    ;; float64 _thrust
    8
    ;; float64 _xpos_obs
    8
    ;; float64 _ypos_obs
    8
    ;; float64 _zpos_obs
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _xpos
       (sys::poke _xpos (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ypos
       (sys::poke _ypos (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zpos
       (sys::poke _zpos (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int16 _sw
       (write-word _sw s)
     ;; float64 _xpos_ref
       (sys::poke _xpos_ref (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ypos_ref
       (sys::poke _ypos_ref (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zpos_ref
       (sys::poke _zpos_ref (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _xvel
       (sys::poke _xvel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yvel
       (sys::poke _yvel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zvel
       (sys::poke _zvel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _phi
       (sys::poke _phi (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _theta
       (sys::poke _theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _psi
       (sys::poke _psi (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _thrust
       (sys::poke _thrust (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _xpos_obs
       (sys::poke _xpos_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ypos_obs
       (sys::poke _ypos_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zpos_obs
       (sys::poke _zpos_obs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _xpos
     (setq _xpos (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ypos
     (setq _ypos (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zpos
     (setq _zpos (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int16 _sw
     (setq _sw (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _xpos_ref
     (setq _xpos_ref (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ypos_ref
     (setq _ypos_ref (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zpos_ref
     (setq _zpos_ref (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _xvel
     (setq _xvel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yvel
     (setq _yvel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zvel
     (setq _zvel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _phi
     (setq _phi (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _theta
     (setq _theta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _psi
     (setq _psi (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _thrust
     (setq _thrust (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _xpos_obs
     (setq _xpos_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ypos_obs
     (setq _ypos_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zpos_obs
     (setq _zpos_obs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get mpc::msgMPC_Data :md5sum-) "a9b89a1a4b30c0f87ae7593794fcf97f")
(setf (get mpc::msgMPC_Data :datatype-) "mpc/msgMPC_Data")
(setf (get mpc::msgMPC_Data :definition-)
      "float64 xpos
float64 ypos
float64 zpos

int16   sw

float64 xpos_ref
float64 ypos_ref
float64 zpos_ref

float64 xvel
float64 yvel
float64 zvel

float64 phi
float64 theta
float64 psi
float64 thrust

float64 xpos_obs
float64 ypos_obs
float64 zpos_obs

")



(provide :mpc/msgMPC_Data "a9b89a1a4b30c0f87ae7593794fcf97f")


