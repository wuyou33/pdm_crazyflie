;; Auto-generated. Do not edit!


(when (boundp 'mpc::msgMpc_input)
  (if (not (find-package "MPC"))
    (make-package "MPC"))
  (shadow 'msgMpc_input (find-package "MPC")))
(unless (find-package "MPC::MSGMPC_INPUT")
  (make-package "MPC::MSGMPC_INPUT"))

(in-package "ROS")
;;//! \htmlinclude msgMpc_input.msg.html


(defclass mpc::msgMpc_input
  :super ros::object
  :slots (_rollPhi _thetaPitch _psiYawRate _thrust _controlFlag ))

(defmethod mpc::msgMpc_input
  (:init
   (&key
    ((:rollPhi __rollPhi) 0.0)
    ((:thetaPitch __thetaPitch) 0.0)
    ((:psiYawRate __psiYawRate) 0.0)
    ((:thrust __thrust) 0.0)
    ((:controlFlag __controlFlag) 0)
    )
   (send-super :init)
   (setq _rollPhi (float __rollPhi))
   (setq _thetaPitch (float __thetaPitch))
   (setq _psiYawRate (float __psiYawRate))
   (setq _thrust (float __thrust))
   (setq _controlFlag (round __controlFlag))
   self)
  (:rollPhi
   (&optional __rollPhi)
   (if __rollPhi (setq _rollPhi __rollPhi)) _rollPhi)
  (:thetaPitch
   (&optional __thetaPitch)
   (if __thetaPitch (setq _thetaPitch __thetaPitch)) _thetaPitch)
  (:psiYawRate
   (&optional __psiYawRate)
   (if __psiYawRate (setq _psiYawRate __psiYawRate)) _psiYawRate)
  (:thrust
   (&optional __thrust)
   (if __thrust (setq _thrust __thrust)) _thrust)
  (:controlFlag
   (&optional __controlFlag)
   (if __controlFlag (setq _controlFlag __controlFlag)) _controlFlag)
  (:serialization-length
   ()
   (+
    ;; float64 _rollPhi
    8
    ;; float64 _thetaPitch
    8
    ;; float64 _psiYawRate
    8
    ;; float64 _thrust
    8
    ;; int8 _controlFlag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _rollPhi
       (sys::poke _rollPhi (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _thetaPitch
       (sys::poke _thetaPitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _psiYawRate
       (sys::poke _psiYawRate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _thrust
       (sys::poke _thrust (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int8 _controlFlag
       (write-byte _controlFlag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _rollPhi
     (setq _rollPhi (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _thetaPitch
     (setq _thetaPitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _psiYawRate
     (setq _psiYawRate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _thrust
     (setq _thrust (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int8 _controlFlag
     (setq _controlFlag (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _controlFlag 127) (setq _controlFlag (- _controlFlag 256)))
   ;;
   self)
  )

(setf (get mpc::msgMpc_input :md5sum-) "64731ea8c92ca2a1540116905352cf9e")
(setf (get mpc::msgMpc_input :datatype-) "mpc/msgMpc_input")
(setf (get mpc::msgMpc_input :definition-)
      "float64 rollPhi
float64 thetaPitch
float64 psiYawRate
float64 thrust

int8 controlFlag

")



(provide :mpc/msgMpc_input "64731ea8c92ca2a1540116905352cf9e")


