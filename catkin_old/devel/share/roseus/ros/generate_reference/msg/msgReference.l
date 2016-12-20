;; Auto-generated. Do not edit!


(when (boundp 'generate_reference::msgReference)
  (if (not (find-package "GENERATE_REFERENCE"))
    (make-package "GENERATE_REFERENCE"))
  (shadow 'msgReference (find-package "GENERATE_REFERENCE")))
(unless (find-package "GENERATE_REFERENCE::MSGREFERENCE")
  (make-package "GENERATE_REFERENCE::MSGREFERENCE"))

(in-package "ROS")
;;//! \htmlinclude msgReference.msg.html


(defclass generate_reference::msgReference
  :super ros::object
  :slots (_signal _next_ref_x _next_ref_y _next_ref_z ))

(defmethod generate_reference::msgReference
  (:init
   (&key
    ((:signal __signal) 0)
    ((:next_ref_x __next_ref_x) 0.0)
    ((:next_ref_y __next_ref_y) 0.0)
    ((:next_ref_z __next_ref_z) 0.0)
    )
   (send-super :init)
   (setq _signal (round __signal))
   (setq _next_ref_x (float __next_ref_x))
   (setq _next_ref_y (float __next_ref_y))
   (setq _next_ref_z (float __next_ref_z))
   self)
  (:signal
   (&optional __signal)
   (if __signal (setq _signal __signal)) _signal)
  (:next_ref_x
   (&optional __next_ref_x)
   (if __next_ref_x (setq _next_ref_x __next_ref_x)) _next_ref_x)
  (:next_ref_y
   (&optional __next_ref_y)
   (if __next_ref_y (setq _next_ref_y __next_ref_y)) _next_ref_y)
  (:next_ref_z
   (&optional __next_ref_z)
   (if __next_ref_z (setq _next_ref_z __next_ref_z)) _next_ref_z)
  (:serialization-length
   ()
   (+
    ;; int16 _signal
    2
    ;; float64 _next_ref_x
    8
    ;; float64 _next_ref_y
    8
    ;; float64 _next_ref_z
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _signal
       (write-word _signal s)
     ;; float64 _next_ref_x
       (sys::poke _next_ref_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _next_ref_y
       (sys::poke _next_ref_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _next_ref_z
       (sys::poke _next_ref_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _signal
     (setq _signal (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _next_ref_x
     (setq _next_ref_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _next_ref_y
     (setq _next_ref_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _next_ref_z
     (setq _next_ref_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get generate_reference::msgReference :md5sum-) "1443c667f03adfad10148dcd7f2ec861")
(setf (get generate_reference::msgReference :datatype-) "generate_reference/msgReference")
(setf (get generate_reference::msgReference :definition-)
      "int16 signal

float64 next_ref_x
float64 next_ref_y
float64 next_ref_z

")



(provide :generate_reference/msgReference "1443c667f03adfad10148dcd7f2ec861")


