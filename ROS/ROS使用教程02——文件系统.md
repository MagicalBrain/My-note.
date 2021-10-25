# ROS使用教程02——文件系统

## 工作空间文件目录

### src

存放功能包、项目、克隆包等

最重要的文件是**CMakerList.txt**

当你在工作空间中配置功能包时，CMakeList.txt调用CMake。

### build

主要存放CMake和catkin为功能包和项目保存的缓存信息、配置和其它中间文件。

### devel

用来保存编译后的程序，这些是无需安装就能用来测试的程序。

## 文件类型

### 功能包

#### include/package_name/

包含库所需的头文件

#### msg/

存放非标准消息的文件

#### src

存储程序源代码的地方

#### srv

表示服务类型

#### CMakeList.txt

CMake的生成脚本文件

#### package.xml

功能包清单文件

### ROS提供的工具

#### rospack

用来获取信息或在系统中查找工作空间

#### catkin_create_pkg

创建一个新的功能包

#### rosdep

安装功能包所需的系统依赖项

#### 
