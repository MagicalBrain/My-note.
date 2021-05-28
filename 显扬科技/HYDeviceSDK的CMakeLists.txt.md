# HYDeviceSDK的CMakeLists.txt

HYDeviceSDK依赖与opencv和gRPC。

对于opencv的部分先照着之前HYSDK的来写，至于gRPC部分就照着gRPC的官方example下的helloworld来写试试。

## HYDeviceSDK

### HYDeviceSDK的目录结构

### HYDeviceSDK的CMakeLists.txt

```
# 设置cmake版本限制，这里很迷，教程那写着得3.13以上，结果这里却是3.5.1
cmake_minimum_required(VERSION 3.5.1)

# 设置项目名称
project(HYDevice LANGUAGES CXX)

# 寻找 OpenCV安装包依赖
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif (OpenCV_FOUND)

# 添加proto文件的路径？ 注意是以CMakeLists.txt文件所在的路径为准的
# Proto file
get_filename_component(hy_proto "./protos/HYGRPCService.proto" ABSOLUTE)
get_filename_component(hy_proto_path "${hy_proto}" PATH)

# 设置生成proto文件的路径常量
# Generated sources
set(hy_proto_srcs "./protos/Generated/HYGRPCService.pb.cc")
set(hy_proto_hdrs "./protos/Generated/HYGRPCService.pb.h")
set(hy_grpc_srcs "./protos/Generated/HYGRPCService.grpc.pb.cc")
set(hy_grpc_hdrs "./protos/Generated/HYGRPCService.grpc.pb.h")

add_custom_command(
      OUTPUT "${hy_proto_srcs}" "${hy_proto_hdrs}" "${hy_grpc_srcs}" "${hy_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "./protos/Generated"
        --cpp_out "./protos/Generated"
        -I "${hy_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hy_proto}"
      DEPENDS "${hy_proto}")

# include生成的 .pb.h 文件
# Include generated *.pb.h files
include_directories("./protos/Generated" 
    ${PROJECT_SOURCE_DIR}/include)

# hy_grpc_proto
add_library(hy_grpc_proto
  ${hy_grpc_srcs}
  ${hy_grpc_hdrs}
  ${hy_proto_srcs}
  ${hy_proto_hdrs})

target_link_libraries(hy_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

# Targets greeter_[async_](client|server)
foreach(_target
  greeter_client greeter_server
  greeter_async_client greeter_async_client2 greeter_async_server)

  add_executable(${_target} "${_target}.cc" 
    ${PROJECT_NAME} ${PROJECT_SRCS})
  
  target_link_libraries(${_target}
    hy_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
    ${PROJECT_NAME}
    ${OpenCV_LIBRARIES})
endforeach()

# 安装？
install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    )

```

## grpc/example/cpp/helloworld

### grpc/example/cpp/helloworld的目录结构

### grpc/example/cpp/helloworld的CMakeLists.txt

```
# cmake build file for C++ helloworld example.
# Assumes protobuf and gRPC have been installed using cmake.
# See cmake_externalproject/CMakeLists.txt for all-in-one cmake build
# that automatically builds all the dependencies before building helloworld.

# 设置cmake版本限制，这里很迷，教程那写着得3.13以上，结果这里却是3.5.1
cmake_minimum_required(VERSION 3.5.1)

# 设置项目名称
project(HelloWorld C CXX)

# 添加include路径 暂时不知道有什么用
include(../cmake/common.cmake)

# 添加proto文件的路径？
# Proto file
get_filename_component(hw_proto "../../protos/helloworld.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

# 生成proto文件？
# Generated sources
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.h")

add_custom_command(
      OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
      DEPENDS "${hw_proto}")

# include生成的 .pb.h 文件
# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# hw_grpc_proto
add_library(hw_grpc_proto
  ${hw_grpc_srcs}
  ${hw_grpc_hdrs}
  ${hw_proto_srcs}
  ${hw_proto_hdrs})
  
target_link_libraries(hw_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

# Targets greeter_[async_](client|server)
foreach(_target
  greeter_client greeter_server
  greeter_async_client greeter_async_client2 greeter_async_server)

  add_executable(${_target} "${_target}.cc")
  
  target_link_libraries(${_target}
    hw_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()

```