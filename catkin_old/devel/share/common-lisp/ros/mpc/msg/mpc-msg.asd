
(cl:in-package :asdf)

(defsystem "mpc-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "msgMpc_data" :depends-on ("_package_msgMpc_data"))
    (:file "_package_msgMpc_data" :depends-on ("_package"))
    (:file "msgMpc_input" :depends-on ("_package_msgMpc_input"))
    (:file "_package_msgMpc_input" :depends-on ("_package"))
  ))