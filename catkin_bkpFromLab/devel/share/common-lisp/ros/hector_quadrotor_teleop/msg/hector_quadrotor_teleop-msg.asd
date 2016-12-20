
(cl:in-package :asdf)

(defsystem "hector_quadrotor_teleop-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "adv_cmd_vel" :depends-on ("_package_adv_cmd_vel"))
    (:file "_package_adv_cmd_vel" :depends-on ("_package"))
  ))