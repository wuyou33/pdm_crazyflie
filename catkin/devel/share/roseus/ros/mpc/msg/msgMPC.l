;; Auto-generated. Do not edit!


(when (boundp 'mpc::msgMPC)
  (if (not (find-package "MPC"))
    (make-package "MPC"))
  (shadow 'msgMPC (find-package "MPC")))
(unless (find-package "MPC::MSGMPC")
  (make-package "MPC::MSGMPC"))

(in-package "ROS")
;;//! \htmlinclude msgMPC.msg.html


(defclass mpc::msgMPC
  :super ros::object
  :slots (_phi _theta _psi _thrust _controlflag ))

(defmethod mpc::msgMPC
  (:init
   (&key
    ((:phi __phi) 0.0)
    ((:theta __theta) 0.0)
    ((:psi __psi) 0.0)
    ((:thrust __thrust) 0.0)
    ((:controlflag __controlflag) 0)
    )
   (send-super :init)
   (setq _phi (float __phi))
   (setq _theta (float __theta))
   (setq _psi (float __psi))
   (setq _thrust (float __thrust))
   (setq _controlflag (round __controlflag))
   self)
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
  (:controlflag
   (&optional __controlflag)
   (if __controlflag (setq _controlflag __controlflag)) _controlflag)
  (:serialization-length
   ()
   (+
    ;; float64 _phi
    8
    ;; float64 _theta
    8
    ;; float64 _psi
    8
    ;; float64 _thrust
    8
    ;; int8 _controlflag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _phi
       (sys::poke _phi (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _theta
       (sys::poke _theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _psi
       (sys::poke _psi (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _thrust
       (sys::poke _thrust (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int8 _controlflag
       (write-byte _controlflag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _phi
     (setq _phi (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _theta
     (setq _theta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _psi
     (setq _psi (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _thrust
     (setq _thrust (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int8 _controlflag
     (setq _controlflag (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _controlflag 127) (setq _controlflag (- _controlflag 256)))
   ;;
   self)
  )

(setf (get mpc::msgMPC :md5sum-) "71696ac0d5bc75bed22942029948a6b9")
(setf (get mpc::msgMPC :datatype-) "mpc/msgMPC")
(setf (get mpc::msgMPC :definition-)
      "float64 phi
float64 theta
float64 psi
float64 thrust

int8 controlflag

")



(provide :mpc/msgMPC "71696ac0d5bc75bed22942029948a6b9")


