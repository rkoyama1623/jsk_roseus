/* (average &rest numbers) */
/*
このサンプルは、euslispのインスタンスを返す関数をc/c++で書く方法を記述します。
このサンプルをビルドした場合、実行方法は、
```
(average 1 2 3) ;; return 2
(print myvar) ;; return 2 (average function set myvar)
```
です。

c言語で記述する場合は、
```
#include "eus.h"
pointer ___sample(register context *ctx, int n, pointer *argv, pointer env);
void register_sample() { // what is this?
char modname[] = "___sample";
return add_module_initializer(modname, (pointer (*)())___sample);
}
```
に続けて、共通部分を記述します。

c++で記述する場合は、
以下のように、特定のheaderファイルと、名前衝突回避のためのマクロが必要です。

euslispのインスタンスは皆`pointer`型で、配列argvで渡されます。
返り値もpointer型として、returnします。
*/


// for eus.h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <string>
#define class   eus_class
#define throw   eus_throw
#define export  eus_export
#define vector  eus_vector
#define string  eus_string

#include "eus.h"

#undef class
#undef throw
#undef export
#undef vector
#undef string


extern "C" {
  pointer ___sample(register context *ctx, int n, pointer *argv, pointer env);
  void register_sample() { // what is this?
    char modname[] = "___sample";
    return add_module_initializer(modname, (pointer (*)())___sample);
  }
}

// 以下のコードはc/c++で共通です。

static pointer MY_SYM; // symbol for average function
pointer AVERAGE(context *ctx, int n, pointer *argv)
{
  int i;
  float sum=0.0, a, av;
  pointer result;
  numunion nu;
  for (i=0; i<n; i++) {
    a = ckfltval(argv[i]);
    sum += a;
  } /*get floating value from args*/
  av = sum / n;
  result = makeflt((eusfloat_t) av);
  MY_SYM -> c.sym.speval = result;
  return( result );
}

pointer ___sample(register context *ctx, int n, pointer *argv, pointer env)
{
  pointer p=Spevalof(PACKAGE); // PACKAGE is extern pointer
  /* set package to ROS */
  // pointer rospkg; // PACKAGE is extern pointer
  // rospkg=findpkg(makestring("TF",2));
  // if (rospkg == 0) rospkg=makepkg(ctx,makestring("TF", 2),NIL,NIL);
  // Spevalof(PACKAGE)=rospkg;
  // rospkg=findpkg(makestring("ROS",3));
  // if (rospkg == 0 ) {
  // // ROS_ERROR("Coudld not found ROS package; Please load eusros.so");
  // exit(2);
  // }
  // Spevalof(PACKAGE)=rospkg;
  defun(ctx,"AVERAGE", argv[0], (pointer (*)())AVERAGE);
  char sym_name[] = "MYVAR";
  MY_SYM = intern(ctx,sym_name,strlen(sym_name), userpkg); // new symbol

  pointer_update(Spevalof(PACKAGE),p); // what is this? chane name of package?
  return 0;
}

// void ave(context *ctx, int n, pointer *argv)
// {
//   char *p;
//   p = "AVERAGE";
//   // defun(ctx,p,argv[0],AVERAGE);
//   defun(ctx, p, argv[0], (pointer (*)()) AVERAGE);
//   /\*kindly set the result in symbol*\/
//   MY_SYM = intern(ctx,p,strlen(p),userpkg); /\* make a new symbol*\/
// }

