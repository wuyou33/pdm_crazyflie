
(cl:in-package :asdf)

(defsystem "mpc-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "msgMPC" :depends-on ("_package_msgMPC"))
    (:file "_package_msgMPC" :depends-on ("_package"))
    (:file "msgMPC_Data" :depends-on ("_package_msgMPC_Data"))
    (:file "_package_msgMPC_Data" :depends-on ("_package"))
  ))