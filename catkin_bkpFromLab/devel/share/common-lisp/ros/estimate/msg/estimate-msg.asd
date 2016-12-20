
(cl:in-package :asdf)

(defsystem "estimate-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "msgCrazyflie_data" :depends-on ("_package_msgCrazyflie_data"))
    (:file "_package_msgCrazyflie_data" :depends-on ("_package"))
  ))