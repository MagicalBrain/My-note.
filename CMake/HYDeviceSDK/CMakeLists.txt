cmake_minimum_required (VERSION 3.13)
project(HYDeviceSDK LANGUAGES CXX)

# 导入boost库
find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_definitions(${Boost_DEFINITIONS})
    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")

    message("*****")
    message("Boost include ${Boost_INCLUDE_DIRS}")
    message("Boost link ${Boost_LIBRARY_DIRS}")
    message("Boost definitions ${Boost_DEFINITIONS}")
    message("Boost Library ${Boost_LIBRARIES}")
    message("Boost Library_dirs ${Boost_LIBRARY_DIRS}")
endif (Boost_FOUND)

# 导入opencv库
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")

    message("*****")
    message("OpenCV include ${OpenCV_INCLUDE_DIRS}")
    message("OpenCV link ${OpenCV_LIBRARY_DIRS}")
    message("OpenCV definitions ${OpenCV_DEFINITIONS}")
    message("OpenCV Library ${OpenCV_LIBRARIES}")
    message("OpenCV Library_dirs ${OpenCV_LIBRARY_DIRS}")
endif (OpenCV_FOUND)

# 导入opencv库
find_package(PCL REQUIRED)
if (PCL_FOUND)
    include_directories(${PCL_INCLUDE_DIRS})
    link_directories(${PCL_LIBRARY_DIRS})
    add_definitions(${PCL_DEFINITIONS})
    message(STATUS "found PCL ${PCL_VERSION} Library ${PCL_LIBRARIES}")

    message("*****")
    message("PCL include ${PCL_INCLUDE_DIRS}")
    message("PCL link ${PCL_LIBRARY_DIRS}")
    message("PCL definitions ${PCL_DEFINITIONS}")
    message("PCL Library ${PCL_LIBRARIES}")
    message("PCL Library_dirs ${PCL_LIBRARY_DIRS}")
endif (PCL_FOUND)

# 生成proto文件部分
include(common.cmake)
#set(_REFLECTION grpc++_reflection)
#set(_GRPC_GRPCPP grpc++)
#set(_PROTOBUF_LIBPROTOBUF libprotobuf)

# 设置proto文件路径
set(PROTO ${PROJECT_SOURCE_DIR}/proto/Generated)

# 添加C++11支持
# add_compile_options(-std=c++14)
# add_definitions(-std=c++14)

add_definitions(-D _USRDLL)

#启动对C++14标准的支持
set(CMAKE_CXX_STANDARD 14)
# 显式要求指明支持C++标准
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/proto/Generated)

# 添加源代码文件
# aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)

# 生成库
## 生成静态库
add_library(${PROJECT_NAME}_static STATIC src/HYGRPCClient.cpp src/HYWebSocketClient.cpp src/HYSensorClient.cpp 
    #include/HYSensorClient.h include/HYGRPCClient.h include/HYWebSocketClient.h
    ${PROTO}/HYGRPCService.grpc.pb.cc ${PROTO}/HYGRPCService.grpc.pb.h ${PROTO}/HYGRPCService.pb.cc ${PROTO}/HYGRPCService.pb.h)

## 生成动态库
add_library(${PROJECT_NAME} SHARED src/HYGRPCClient.cpp src/HYWebSocketClient.cpp src/HYSensorClient.cpp 
    #include/HYSensorClient.h include/HYGRPCClient.h include/HYWebSocketClient.h
    ${PROTO}/HYGRPCService.grpc.pb.cc ${PROTO}/HYGRPCService.grpc.pb.h ${PROTO}/HYGRPCService.pb.cc ${PROTO}/HYGRPCService.pb.h)

# 指定静态库的输出名称
set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# 使动态库和静态库同时存在
set_target_properties(${PROJECT_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(${PROJECT_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 链接库
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_static
    ${Boost_LIBRARIES}
    ${OpenCV_LIBRARIES}
    ${PCL_LIBRARIES}
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
)

# target_include_directories(${PROJECT_NAME} include)

# 设置install路径
if (NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX /usr/local/lib)
endif (NOT CMAKE_INSTALL_PREFIX)

# install
install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )

install(FILES
    include/HYSensorClient.h include/HYGRPCClient.h include/HYWebSocketClient.h include/HYDeviceSDK.h
    DESTINATION /usr/local/include
    )
