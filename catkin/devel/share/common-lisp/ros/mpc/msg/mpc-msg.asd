
(cl:in-package :asdf)

(defsystem "mpc-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "msgMPC_Data" :depends-on ("_package_msgMPC_Data"))
    (:file "_package_msgMPC_Data" :depends-on ("_package"))
    (:file "msgMPC_Input" :depends-on ("_package_msgMPC_Input"))
    (:file "_package_msgMPC_Input" :depends-on ("_package"))
  ))