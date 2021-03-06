;; test-mongo-client.l
;; Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>

(require :unittest "lib/llib/unittest.l")
(require :mongo-client "package://roseus_mongo/euslisp/mongo-client.l")

(init-unit-test)

(deftest mongo-client-param
  (assert (string= *mongo-database* "test_database"))
  (assert (string= *mongo-collection* "test_collection")))

(deftest mongo-client

  (mongo::wait-for-server)

  (setq msg (instance geometry_msgs::Pose :init
                      :position (instance geometry_msgs::Point :init :x 1 :y 2 :z 3)))
  (setq doc-id (mongo::insert msg))
  (warn "doc-id: ~A~%" doc-id)

  (setq res (mongo::query geometry_msgs::Pose :query '((:_id . ((:$oid . doc-id)))) :single t :msg-only t))
  (print res)
  (assert (equal msg (car res)))

  (setq assume-nil (mongo::query geometry_msgs::TransformStamped :msg-only t))
  (assert (null assume-nil))

  (setq assume-fail (mongo::delete-by-id "11a1e111e111111e11000000"))
  (assert (not assume-fail))

  (setq assume-success (mongo::delete-by-id doc-id))
  (assert assume-success)
  (setq assume-deleted
        (mongo::query geometry_msgs::Pose :query '((:_id . ((:$oid . doc-id)))) :single t :msg-only t))
  (assert (null assume-deleted))

  (dotimes (i 10)
    (send msg :position :x i)
    (mongo::insert msg))

  (setq res-many (mongo::query geometry_msgs::Pose :sort '((:natural . 1 )) :msg-only t))
  (dotimes (i 10)
    (assert (eq (float i) (send (elt res-many i) :position :x)))))

(run-all-tests)
(exit)

(provide :test-mongo-client) ;; end of test-mongo-client.l
