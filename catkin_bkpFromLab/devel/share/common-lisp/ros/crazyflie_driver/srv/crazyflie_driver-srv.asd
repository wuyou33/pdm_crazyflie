
(cl:in-package :asdf)

(defsystem "crazyflie_driver-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "AddCrazyflie" :depends-on ("_package_AddCrazyflie"))
    (:file "_package_AddCrazyflie" :depends-on ("_package"))
    (:file "UpdateParams" :depends-on ("_package_UpdateParams"))
    (:file "_package_UpdateParams" :depends-on ("_package"))
  ))