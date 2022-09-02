# project name
PROJECT(HELLO_WORLD)

# requirement of cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# set the directory of executable files (指定可执行文件的路径为bin目录)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add source code files to SRC_LIST (添加源码文件)
SET(SRC_LIST main.cpp)

# find required opencv (cmake可以自动寻找OpenCV相关路径，
# 当找到OpenCV程序库之后，就会定义几个变量：OpenCV_FOUND、
# OpenCV_INCLUDE_DIRS、OpenCV_LIBRARY_DIRS、OpenCV_LIBS，
# 它们分别指是否找到OpenCV、OpenCV的头文件目录、OpenCV的库文件目录、
# OpenCV的所有库文件列表)
FIND_PACKAGE(OpenCV REQUIRED)

# directory of opencv headers (OpenCV_INCLUDE_DIRS是cmake自动找到的目录)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

# name of executable file and path of source file (指定可执行文件的名称为helloopencv以及源码文件)
ADD_EXECUTABLE(helloopencv ${SRC_LIST})

# directory of opencv library (OpenCV_LIBRARY_DIRS是cmake自动找到的目录)
LINK_DIRECTORIES(${OpenCV_LIBRARY_DIRS})

# opencv libraries (指定链接的对象)
TARGET_LINK_LIBRARIES(helloopencv ${OpenCV_LIBS})