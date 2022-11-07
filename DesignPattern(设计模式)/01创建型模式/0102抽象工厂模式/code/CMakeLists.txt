
#  minimum required cmake version: 3.1.0
cmake_minimum_required(VERSION 3.1.0)

project(TestAbstractFactoryPattern)

# set the directory of executable files (指定可执行文件的路径为bin目录)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


# directory of opencv headers (OpenCV_INCLUDE_DIRS是cmake自动找到的目录)
#include_directories(
#    
#)

#link_directories(${PCL_LIBRARY_DIRS})

#add_definitions(${PCL_DEFINITIONS})

add_executable(testAbstractFactoryPattern 
    AbstractFactoryPattern.h
    AbstractFactory.hpp
    AbstractFruit.hpp
    RealFruit.hpp
    main.cpp )

set_property(TARGET testAbstractFactoryPattern PROPERTY CXX_STANDARD 11)

#target_link_libraries(my-pointcloud 
#    ${OpenCV_LIBS}
#    ${realsense2_LIBRARY}
#    ${PCL_LIBRARIES}
#)
