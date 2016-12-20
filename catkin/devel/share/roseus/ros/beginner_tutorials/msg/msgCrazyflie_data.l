;; Auto-generated. Do not edit!


(when (boundp 'beginner_tutorials::msgCrazyflie_data)
  (if (not (find-package "BEGINNER_TUTORIALS"))
    (make-package "BEGINNER_TUTORIALS"))
  (shadow 'msgCrazyflie_data (find-package "BEGINNER_TUTORIALS")))
(unless (find-package "BEGINNER_TUTORIALS::MSGCRAZYFLIE_DATA")
  (make-package "BEGINNER_TUTORIALS::MSGCRAZYFLIE_DATA"))

(in-package "ROS")
;;//! \htmlinclude msgCrazyflie_data.msg.html


(defclass beginner_tutorials::msgCrazyflie_data
  :super ros::object
  :slots (_imu_msg _vrpn_msg ))

(defmethod beginner_tutorials::msgCrazyflie_data
  (:init
   (&key
    ((:imu_msg __imu_msg) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:vrpn_msg __vrpn_msg) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _imu_msg __imu_msg)
   (setq _vrpn_msg __vrpn_msg)
   self)
  (:imu_msg
   (&optional __imu_msg)
   (if __imu_msg (setq _imu_msg __imu_msg)) _imu_msg)
  (:vrpn_msg
   (&optional __vrpn_msg)
   (if __vrpn_msg (setq _vrpn_msg __vrpn_msg)) _vrpn_msg)
  (:serialization-length
   ()
   (+
    ;; float32[] _imu_msg
    (* 4    (length _imu_msg)) 4
    ;; float32[] _vrpn_msg
    (* 4    (length _vrpn_msg)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[] _imu_msg
     (write-long (length _imu_msg) s)
     (dotimes (i (length _imu_msg))
       (sys::poke (elt _imu_msg i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _vrpn_msg
     (write-long (length _vrpn_msg) s)
     (dotimes (i (length _vrpn_msg))
       (sys::poke (elt _vrpn_msg i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[] _imu_msg
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _imu_msg (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _imu_msg i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _vrpn_msg
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _vrpn_msg (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _vrpn_msg i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get beginner_tutorials::msgCrazyflie_data :md5sum-) "6af109ec49fecf2fd5c4a5b152fa11fb")
(setf (get beginner_tutorials::msgCrazyflie_data :datatype-) "beginner_tutorials/msgCrazyflie_data")
(setf (get beginner_tutorials::msgCrazyflie_data :definition-)
      "float32[] imu_msg
float32[] vrpn_msg

")



(provide :beginner_tutorials/msgCrazyflie_data "6af109ec49fecf2fd5c4a5b152fa11fb")


