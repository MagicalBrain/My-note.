# ROS使用教程——工作空间和功能包

## 工作空间

### 创建工作空间

命令：

```bash
mkdir -p ~/[workspace name]/src
cd ~/[workspace name]/src
catkin_init_workspace
```

```bash
Creating symlink "/home/hrl/Desktop/MyROSWorkspace/src/CMakeLists.txt" pointing to "/opt/ros/melodic/share/catkin/cmake/toplevel.cmake"
```

### 编译工作空间

```bash
cd ~/[workspace name]
catkin_make
```

```bash
Base path: /home/hrl/Desktop/MyROSWorkspace
Source space: /home/hrl/Desktop/MyROSWorkspace/src
Build space: /home/hrl/Desktop/MyROSWorkspace/build
Devel space: /home/hrl/Desktop/MyROSWorkspace/devel
Install space: /home/hrl/Desktop/MyROSWorkspace/install
####
#### Running command: "cmake /home/hrl/Desktop/MyROSWorkspace/src -DCATKIN_DEVEL_PREFIX=/home/hrl/Desktop/MyROSWorkspace/devel -DCMAKE_INSTALL_PREFIX=/home/hrl/Desktop/MyROSWorkspace/install -G Unix Makefiles" in "/home/hrl/Desktop/MyROSWorkspace/build"
####
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Using CATKIN_DEVEL_PREFIX: /home/hrl/Desktop/MyROSWorkspace/devel
-- Using CMAKE_PREFIX_PATH: /opt/ros/melodic
-- This workspace overlays: /opt/ros/melodic
-- Found PythonInterp: /usr/bin/python2 (found suitable version "2.7.17", minimum required is "2") 
-- Using PYTHON_EXECUTABLE: /usr/bin/python2
-- Using Debian Python package layout
-- Using empy: /usr/bin/empy
-- Using CATKIN_ENABLE_TESTING: ON
-- Call enable_testing()
-- Using CATKIN_TEST_RESULTS_DIR: /home/hrl/Desktop/MyROSWorkspace/build/test_results
-- Found gtest sources under '/usr/src/googletest': gtests will be built
-- Found gmock sources under '/usr/src/googletest': gmock will be built
-- Found PythonInterp: /usr/bin/python2 (found version "2.7.17") 
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Looking for pthread_create
-- Looking for pthread_create - not found
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE  
-- Using Python nosetests: /usr/bin/nosetests-2.7
-- catkin 0.7.29
-- BUILD_SHARED_LIBS is on
-- BUILD_SHARED_LIBS is on
-- Configuring done
-- Generating done
-- Build files have been written to: /home/hrl/Desktop/MyROSWorkspace/build
####
#### Running command: "make -j8 -l8" in "/home/hrl/Desktop/MyROSWorkspace/build"
####
```

编译时：
`~/[workspace name]/`根目录里会产生build和devel两个文件夹

编译完成后：
`devel`文件夹会生成几个`.sh`文件用于设置环境变量。

`source setup.sh`便可在当前终端里设置环境变量

**注意**：
新版本的安装脚本都给你写好了的。

本地永久设置环境变量：
```bash
local_setup.*
```

根据你使用的shell来选择即可。

检查环境变量：
```bash
echo $ROS_PACKAGE_PATH
```

## 功能包

### 创建功能包

可直接使用`catkin_create_pkg`命令

```bash
cd ~/[workspace name]/src
# catkin_create_pkg [package name]
catkin_create_pkg pkg-HRL
```

```bash
WARNING: Package name "pkg-HRL" does not follow the naming conventions. It should start with a lower case letter and only contain lower case letters, digits, underscores, and dashes.
Created file pkg-HRL/CMakeLists.txt
Created file pkg-HRL/package.xml
Successfully created files in /home/hrl/Desktop/MyROSWorkspace/src/pkg-HRL. Please adjust the values in package.xml.
```

----

`catkin_create_pkg`命令详解：

```bash
catkin_create_pkg [package name] [depend 1] [depend 2] [depend 3] ...
```

###
