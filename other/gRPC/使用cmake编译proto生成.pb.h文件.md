# 使用cmake编译proto生成.pb.h文件

```
# 生成proto文件部分
include(common.cmake)

# 设置proto文件路径
set(PROTO ${PROJECT_SOURCE_DIR}/proto/Generated)

# Proto file
get_filename_component(hy_proto "${PROJECT_SOURCE_DIR}/proto/HYGRPCService.proto" ABSOLUTE)
get_filename_component(hy_proto_path "${hw_proto}" PATH)

# Generated sources
set(hy_proto_srcs "${PROTO}/HYGRPCService.pb.cc")
set(hy_proto_hdrs "${PROTO}/HYGRPCService.pb.h")
set(hy_grpc_srcs "${PROTO}/HYGRPCService.grpc.pb.cc")
set(hy_grpc_hdrs "${PROTO}/HYGRPCService.grpc.pb.h")
add_custom_command(
      OUTPUT "${hy_proto_srcs}" "${hy_proto_hdrs}" "${hy_grpc_srcs}" "${hy_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hy_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hy_proto}"
      DEPENDS "${hy_proto}")

# Include generated *.pb.h files
# include_directories("${CMAKE_CURRENT_BINARY_DIR}")

```