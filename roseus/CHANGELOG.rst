^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package roseus
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1.3.9 (2015-09-14)
------------------
* roseus.cpp: add ros::create-timer function
* Contributors: Kei Okada, Ryohei Ueda

1.3.8 (2015-09-12)
------------------
* [roseus] Add test to read ros parameter with default value 1000 times
* [roseus] Use COPYOBJ instead of copyobj to copy object of default
  parameter in ros::get-param
* fix ros::resolve-path returns nil for non existing package name
* add test for ros::resolve-path
* [euslisp/roseus.l] compile when loaded as package://
* [euslisp/roseus.l] fix roseus-add-files to use normal compile-file-if-src-newer
* [test/test-compile-message.l] add test for compiling message
* Contributors: Kei Okada, Ryohei Ueda, Yohei Kakiuchi

1.3.7 (2015-08-18)
------------------
* geneus stuff

  * [cmake/get_all_depends.py] hydro releaes still uses 2.2.2, so we need to update pkg_map
  * [cmake/roseus.cmake] display eus-related package version
  * [cmake/roseus.cmake] call find_package  to get ${_pkg}_PREFIX
  * [cmake/roseus.cmake] fix for get_all_depends in installed space
  * [cmake/roseus.cmake] Set CMAKE_PREFIX_PATH to run generate all deps
  * [cmake/roseus.cmake] Add condition for roseus_SOURCE_PREFIX when building roseus
  * [cmake/roseus.cmake] Add macro(_package_depends_impl) in roseus.cmake
  * [cmake/get_all_depends.py] Add cmake/get_all_depends.py to get all implicit depends

* marker conversion
  * [euslisp/roseus-utils.l] fix eusobj->marker-msg 's check body type
  * [euslisp/roseus-utils.l] remove debug code (marker-msg->shape)

* test codes
  * [test/test-roseus.l] add test for irtpointcloud
  * [test/test-roseus.l] add test code for marker message <-> eus object conversion function in euslisp/roseus-utils.l
  * [test/test-genmsg.sh, test/test-genmsg.catkin.test] check after remove messages in devel/share/roseus/ros
  * [test/test-genmsg.sh] add test to check if messages in roseus is generated
  * [roseus/test/test-rosues.l] make-random-pointcloud is only available on jskeus 1.0.9

* build system
* [roseus/CMakeLists.txt] somehow regex in if statemet must be double quated?
* [roseus/cmake/roseus.cmake] Unset DISPLAY environmental variable when generating eusdoc to avoid init-xwindow error
* [roseus] Add .gitignore

* Contributors: Kei Okada, Kentaro Wada, Ryohei Ueda, Yohei Kakiuchi, Yuto Inagaki

1.3.6 (2015-06-11)
------------------
* [CMakeLists.txt] add catkin_INCLUDE_DIRS, this fixes #317
* [roseus] Add NO_GENERATE_EUSDOC environmental variable to disable
  generation of eusdoc
* Contributors: Kei Okada, Ryohei Ueda

1.3.5 (2015-05-15)
------------------
* [roseus.cpp] remove error message in get-topic-subscriber
* [roseus.cpp] add more documentations
* [cmake/roseus.cmake] update generate_eusdoc for installed functions\n\n this requires https://github.com/euslisp/EusLisp/pull/112
* [cmake/roseus.cmake] do not raise error when geneus doc failed
* [euslisp/{eustf.l, roseus-utils.l, roseus.l}] add more documenations
* [roseus.cpp] is fix error message, You must call ros::init() -> (ros::roseus "name")
* [roseus/CMakeLists.txt] add compiler option for C to suppress looking-up undefined symbol when linking using Clang compiler
* [roseus/eustf.cpp] undef duplicated macros defined in standard library and in euslisp
* [roseus.cpp] remove error message meanless in get-topic-publisher
* Contributors: Yuki Furuta, Kei Okada, Yuto Inagaki

1.3.4 (2015-05-03)
------------------
* [roseus.cpp] add get-host, get-nodes, get-port, get-uri, get-topics, from http://docs.ros.org/indigo/api/roscpp/html/master_8h.html
* [euslisp/roseus-utils.l] support bodyset object
* [euslisp/roseus-utils.l] support random color
* [euslisp/roseus-utils.l] support object with :glvertices
* [jsk_roseus] Parallelize generate-all-msg-srv
* Contributors: Kei Okada, Ryohei Ueda

1.3.3 (2015-04-29)
------------------
* [roseus/cmake/roseus.cmake] need to know roseus exeutable path when compile within same workspace
* [roseus/CMkeLists.txt] in some cases, rosversion tf2_ros did not resspond the results, use tf2_ros_VERSION, since this is only for old tf2, so we can remove this
* Contributors: Kei Okada

1.3.2 (2015-04-28)
------------------
* [cmake/roseus.cmake] use ${PROJECT_NAME}_generate_messages_eus_all_target for depend to eusdoc
* Contributors: Kei Okada

1.3.1 (2015-04-26)
------------------
* [cmake/roseus.cmake] fix for package only with action
* [roseus/test/roseus.cmake] check package only action messages, (jsk_demo_common)
* Contributors: Kei Okada

1.3.0 (2015-04-24)
------------------

* add generate_eusdoc

  * [roseus/cmake/roseus.cmake] depends on install_roseus for doc generation
  * [roseus/CMakeLists.txt] generate eus-docs
  * [roseus/cmake/roseus.cmake] add generate_eusdoc macro

* CMakeLists.txt

  * [roseus/CMakeLists.txt] use add_custom_target to copy roseus to   bin

* roseus.cmake

  * [cmake/roseus/roseus.cmake] fix for msg in workspace using {$msg}_SOURCE_PREFIX
  * do not raise error for old catkin

* convert unit8[] as string https://github.com/jsk-ros-pkg/geneus/issues/14

  * [test/test_geneus] add test for fixed length data
  * [test-genmsg.sh] compile with -j1 and -l1, unset MAKEFLAGS  https://github.com/catkin/catkin_tools/pull/85
  * [roseus] fix test for treating uint8[] as string

* [roseus] add test-anonymous for `#179 <https://github.com/jsk-ros-pkg/jsk_roseus/issues/179>`_
* Contributors: Yuki Furuta, Kei Okada

1.2.6 (2015-02-21)
------------------
* [test-genmsg.sh] fix for latest source code
* [CMakeLists.txt] create symlink from share/roseus -> ../../bin/roseus
* [test-genmsg.sh] fix typo rosun -> rosrun
* [test/test-genmsg.sh] add test for 'manifest should have all depends packages'
* [test/test-genmsg.sh] remove rosbuild settings
* [roseus] Install roseus binary to share directory
* [generate-all-msg-srv] fix msg gen
* Contributors: Yuki Furuta, Kei Okada, Yuto Inagaki

1.2.5 (2015-02-13)
------------------
* [roseus.cmake] add more condition
* [roseus] Add class to synchronize multiple topics with the same timestamp like message_filters
* Contributors: Ryohei Ueda, Kei Okada

1.2.4 (2015-02-12)
------------------
* do not run upstream message generation on buildfirm
* fir for generating manifest for packages does not have depends
* add test code for geneus
* more fix to generate-all-msg-srv
* fit for generating msgs
* add target package those who does not have msg files
* [roseus] generate-all-msgs-srv.sh fix for new geneus package
* roseus messages under home-dir is nolonger supported
* [roseus] add more debug messages ros message generation
* [roseus] test/test-genmsg.sh, fix typo start-from -> start-with for catkin-tools
* Contributors: Kei Okada

1.2.3 (2015-02-02)
------------------
* find package if not messages path is not found
* [roseus] Fix typo
* euslisp is now non-catkin package

1.2.2 (2015-01-27)
------------------
* do not compile message if it is already installed

1.2.1 (2015-01-27)
------------------
* install generated messages

1.2.0 (2015-01-26)
------------------
* [roseus] If user return invalid instance in service callback, print error message
* use EUSDIR insted of using rospack find euslisp
* Contributors: Ryohei Ueda, Kei Okada

1.1.33 (2015-01-26)
-------------------
* fix wrong all_generate_message_eus target

1.1.32 (2015-01-26)
-------------------
* generate all roseus messages on buildfirm

1.1.31 (2015-01-23)
-------------------
* add dynamic_reconfigure
* fix to use catkin-tools
* remove old manifest.xml, fully catkinize
* use originl source (node rosmake proxy package) for euslisp
* add new macro, generate_all_roseus_message() to generate all dependency msgs using new geneus written by python
* enable alpha when converting eus object to ros marker
* [roseus] Fix error of VERSION_LESS around TF2_ROS_VERSION
* Contributors: Ryohei Ueda, Kei Okada, Yusuke Furuta

1.1.30 (2015-01-14)
-------------------
* use -L to find symlinked irteusgl

1.1.29 (2014-12-27)
-------------------
* check it euslisp provide euslisp_INCLUDE_DIR

1.1.28 (2014-12-26)
-------------------
* simplify function
* add compare function for ros::time
* Contributors: Chi Wun Au

1.1.27 (2014-12-20)
-------------------
* update body's worldcoords before using its faces
* add logger and level key param to ros::roseus
* fix typo of ros::coords->pose
* add :anonymous to ros::roseus
* add set_logger_level func
* modified typo ros::rosinfo => ros::ros-info
* add warning if id is set
* update param-test.l for testing parameter handling by roseus
* add code for reading dictionary type parameter to roseus

1.1.26 (2014-11-10)
-------------------
* Add utility function to set dynamic_reconfigure parameter
* Contributors: Ryohei Ueda

1.1.25 (2014-10-10)
-------------------

1.1.23 (2014-09-24)
-------------------

1.1.22 (2014-09-04)
-------------------
* install roseus to global bin, fixed #146
* fix bracket mathing in roseus-utils.l
* call error when package:// is not found, fix typo, see #140
* Contributors: Kei Okada, Masaki Murooka

1.1.21 (2014-06-30)
-------------------

1.1.20 (2014-06-29)
-------------------
* roseus_c_util.c : remove compile_warnings
* test-genmsg.sh: add roscpp to CATKIN_DEPENDS
* test-genmsg.sh: catkin_make with --make-args VERBOSE=1
* test-genmsg.sh/test-genmsg.catkin.test : check #120 situation
* roseus.cpp : support reconnection of service when persist is set true
* Contributors: Ryohei Ueda, Kei Okada

1.1.19 (2014-06-11)
-------------------
* (#112,#113) fix service persist without keyward
  ros::service-call (name value &optional (persist nil))
* Contributors: Ryohei Ueda, Kei Okada

1.1.18 (2014-05-16)
-------------------

1.1.17 (2014-05-11)
-------------------

1.1.16 (2014-05-11)
-------------------

1.1.15 (2014-05-10)
-------------------

1.1.14 (2014-05-09)
-------------------
* add hasHeader for roscpp >= 1.11.1
* fix typo in install roseus
* Contributors: Kei Okada

1.1.13 (2014-05-06)
-------------------
* add more message when install roseus
* Contributors: Kei Okada

1.1.12 (2014-05-06)
-------------------

1.1.11 (2014-05-04)
-------------------

1.1.10 (2014-05-03)
-------------------

1.1.9 (2014-05-03)
------------------
* add debug message when install roseus
* Contributors: Kei Okada

1.1.8 (2014-05-02)
------------------
* create symlink in global/bin/roseus
* Contributors: Kei Okada

1.1.7 (2014-04-28)
------------------

1.1.6 (2014-04-28)
------------------

1.1.5 (2014-04-27)
------------------

1.1.4 (2014-04-25)
------------------
* check msg file udder CMAKE_PREFIX_PATH (#68)
* (#31) use 120 as wait-for-transform
* Contributors: Kei Okada

1.1.3 (2014-04-14)
------------------
* add rosdnoe to depends(#64)
* Contributors: Kei Okada

1.1.0 (2014-04-07)
------------------
* add geneus package that generate ros message for euslisp
* (`#32 <https://github.com/jsk-ros-pkg/jsk_roseus/issues/32>`_) copy jsk_roseus for one workspace and remove build on rosbuild
* (`#32 <https://github.com/jsk-ros-pkg/jsk_roseus/issues/32>`_) add rich test for euslisp message generation, remove scripts and generate them from one shell script.
  * one workspace/separated workspace
  * add several dependency
  * action messages generation
* (`#32 <https://github.com/jsk-ros-pkg/jsk_roseus/issues/32>`_) add scripts to test geneus more
* (`#32 <https://github.com/jsk-ros-pkg/jsk_roseus/issues/32>`_) check if test the message has created or not by simple roseus program, add euslisp test rather than cpp test code
* (`#32 <https://github.com/jsk-ros-pkg/jsk_roseus/issues/32>`_) add test-genmsg, test message generation on catkin and rosbuild
* add check delay of lookuptransform
* add checking delay of tf return
* Contributors: Ryohei Ueda, Yohei Kakiuchi, Kei Okada

1.0.4 (2014-03-31)
------------------
* fix for catkin environment
* set euslisp_PACKAGE_PATH for both devel and installed
* switch from svnversion to git rev-parse --short HEAD
* removed debug messages
* Contributors: Ryohei Ueda, Kei Okada

1.0.3 (2014-03-29)
------------------
* catkin.cmake add rostest to find_package
* `#14 <https://github.com/jsk-ros-pkg/jsk_roseus/issues/14>`_: depend roseus message generation on python message generation.
  in roseus.cmake, do not take into account the dependencies between messages
  and packages and just depends roseus message generation on python message generation.
  The 1st reason is the difference between hydro and groovy. On groovy, genmsg
  does not craete the targets of foo_generate_messages_py
  which are already compiled, I mean the packages installed by apt.
  The 2nd reason is that roseus message generation utilizes rospy and it requires
  for rospy messages to be available. So this dependencies are required.
  Namely, the dependency will be like this:
  parent_pkg
  +-child_pkg
    +-grandchild_pkg
      +-grandchild_pkg_generate_messages_py
        +-euslip targets for grandchild_pkg
* Contributors: Ryohei Ueda
* roseus/test/test-tf.test: tf2_buffer_server output to screen

1.0.2 (2014-03-28)
------------------
* roseus.cmake: remove debug code
* roseus/test/test-add-two-ints.l: reduce test time
* Contributors: Kei Okada

1.0.1 (2014-03-27)
------------------
* roseus: add version numeber to 1.0.0
* Contributors: Haseru Chen, Shunnich Nozawa, Yuki Furuta, Kei Okada, Yuto Inagaki, Manabu Saito, kazuto Murase, Yohei Kakiuchi, Eisoku Kuroiwa, Ryohei Ueda, Hiroyuki Mikita
