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

# 对
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
