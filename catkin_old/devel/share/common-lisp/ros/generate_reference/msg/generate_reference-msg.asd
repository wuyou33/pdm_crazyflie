
(cl:in-package :asdf)

(defsystem "generate_reference-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "msgReference" :depends-on ("_package_msgReference"))
    (:file "_package_msgReference" :depends-on ("_package"))
  ))