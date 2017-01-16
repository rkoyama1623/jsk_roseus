# euslisp のC言語API
サンプルコードsample.cppを参照

# c++クラスのeusでのラップ方法
eustf.cppが参考になる．
newで作成したクラスインスタンスへのポインタは，deleteされるまでヒープに存在するので，その性質を利用する．

EUSTF_TRANSFORMERは，インスタンスへのポインタをeusinteger_tにキャストして返す．
EUSTF_ALLFRAMESASSTRINGはeusinteger_tとして受け取った値を(tf::Transformer *)にキャストしてtfのメソッドを利用する．
EUSTF_TRANSFORM_LISTENER_DISPOSEの中でdeleteする．

