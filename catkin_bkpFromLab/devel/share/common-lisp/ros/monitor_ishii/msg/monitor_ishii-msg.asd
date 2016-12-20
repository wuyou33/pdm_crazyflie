
(cl:in-package :asdf)

(defsystem "monitor_ishii-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "msgMPC" :depends-on ("_package_msgMPC"))
    (:file "_package_msgMPC" :depends-on ("_package"))
  ))