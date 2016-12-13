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
  :slots (_xPos _yPos _zPos _controlFlag _xPosRef _yPosRef _zPosRef ))

(defmethod mpc::msgMPC_Data
  (:init
   (&key
    ((:xPos __xPos) 0.0)
    ((:yPos __yPos) 0.0)
    ((:zPos __zPos) 0.0)
    ((:controlFlag __controlFlag) 0)
    ((:xPosRef __xPosRef) 0.0)
    ((:yPosRef __yPosRef) 0.0)
    ((:zPosRef __zPosRef) 0.0)
    )
   (send-super :init)
   (setq _xPos (float __xPos))
   (setq _yPos (float __yPos))
   (setq _zPos (float __zPos))
   (setq _controlFlag (round __controlFlag))
   (setq _xPosRef (float __xPosRef))
   (setq _yPosRef (float __yPosRef))
   (setq _zPosRef (float __zPosRef))
   self)
  (:xPos
   (&optional __xPos)
   (if __xPos (setq _xPos __xPos)) _xPos)
  (:yPos
   (&optional __yPos)
   (if __yPos (setq _yPos __yPos)) _yPos)
  (:zPos
   (&optional __zPos)
   (if __zPos (setq _zPos __zPos)) _zPos)
  (:controlFlag
   (&optional __controlFlag)
   (if __controlFlag (setq _controlFlag __controlFlag)) _controlFlag)
  (:xPosRef
   (&optional __xPosRef)
   (if __xPosRef (setq _xPosRef __xPosRef)) _xPosRef)
  (:yPosRef
   (&optional __yPosRef)
   (if __yPosRef (setq _yPosRef __yPosRef)) _yPosRef)
  (:zPosRef
   (&optional __zPosRef)
   (if __zPosRef (setq _zPosRef __zPosRef)) _zPosRef)
  (:serialization-length
   ()
   (+
    ;; float64 _xPos
    8
    ;; float64 _yPos
    8
    ;; float64 _zPos
    8
    ;; int8 _controlFlag
    1
    ;; float64 _xPosRef
    8
    ;; float64 _yPosRef
    8
    ;; float64 _zPosRef
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _xPos
       (sys::poke _xPos (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yPos
       (sys::poke _yPos (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zPos
       (sys::poke _zPos (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int8 _controlFlag
       (write-byte _controlFlag s)
     ;; float64 _xPosRef
       (sys::poke _xPosRef (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yPosRef
       (sys::poke _yPosRef (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zPosRef
       (sys::poke _zPosRef (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _xPos
     (setq _xPos (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yPos
     (setq _yPos (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zPos
     (setq _zPos (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int8 _controlFlag
     (setq _controlFlag (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _controlFlag 127) (setq _controlFlag (- _controlFlag 256)))
   ;; float64 _xPosRef
     (setq _xPosRef (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yPosRef
     (setq _yPosRef (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zPosRef
     (setq _zPosRef (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get mpc::msgMPC_Data :md5sum-) "6bc2414c1027b318ae658fa2e1750a8e")
(setf (get mpc::msgMPC_Data :datatype-) "mpc/msgMPC_Data")
(setf (get mpc::msgMPC_Data :definition-)
      "float64 xPos
float64 yPos
float64 zPos

int8   controlFlag

float64 xPosRef
float64 yPosRef
float64 zPosRef

")



(provide :mpc/msgMPC_Data "6bc2414c1027b318ae658fa2e1750a8e")


