cmake_minimum_required (VERSION 3.13)
project(HYDeviceSDK LANGUAGES CXX)

if (NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX /usr/local)
endif ()

find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_definitions(${Boost_DEFINITIONS})
    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")
endif ()

find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)    
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif ()

find_package(Protobuf REQUIRED)
if (Protobuf_FOUND)    
    include_directories(${Protobuf_INCLUDE_DIRS})
    link_directories(${Protobuf_LIBRARY_DIRS})
    add_definitions(${Protobuf_DEFINITIONS})
    message(STATUS "found Protobuf ${Protobuf_VERSION} Library ${Protobuf_LIBRARIES}")
endif ()

find_package(gRPC CONFIG REQUIRED)
if (gRPC_FOUND)  
    set(GRPCPP_INCLUDE_DIRS $<TARGET_PROPERTY:gRPC::grpc++,INTERFACE_INCLUDE_DIRECTORIES>)
    set(GRPCPP_LIBRARIES $<TARGET_PROPERTY:gRPC::grpc++,INTERFACE_LINK_LIBRARIES>)  
    message(STATUS "find package found gRPC ${gRPC_VERSION} Library ${gRPC_LIBRARIES}")
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(GRPC REQUIRED grpc)
    pkg_search_module(GRPCPP REQUIRED grpc++)
    list(APPEND GRPCPP_INCLUDE_DIRS ${gRPC_LIBRARIESRPC_INCLUDE_DIRS})
    list(APPEND GRPCPP_LIBRARIES ${gRPC_LIBRARIESRPC_LIBRARIES})
    message(STATUS "pkg search found gRPC ${gRPC_VERSION} Library ${gRPC_LIBRARIES}")
endif()

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
get_target_property(protoc_location protobuf::protoc LOCATION)

message(STATUS "protoc is at ${protoc_location}") 
message(STATUS "grpc plugin is at ${grpc_cpp_plugin_location}") 

set(PROTO_PATH
${PROJECT_SOURCE_DIR}/proto
)
set(PROTO_FILES
${PROTO_PATH}/HYGRPCService.proto
)

set(PROTO_SRC_DIR ${PROJECT_SOURCE_DIR}/proto/Generated)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})

set(PROTO_SRCS "${PROTO_SRC_DIR}/HYGRPCService.pb.cc")
set(PROTO_HDRS "${PROTO_SRC_DIR}/HYGRPCService.pb.h")
set(GRPC_SRCS "${PROTO_SRC_DIR}/HYGRPCService.grpc.pb.cc")
set(GRPC_HDRS "${PROTO_SRC_DIR}/HYGRPCService.grpc.pb.h")

add_custom_command(
      OUTPUT "${PROTO_SRCS}" "${PROTO_HDRS}" "${GRPC_SRCS}" "${GRPC_HDRS}"
      COMMAND ${protoc_location}
      ARGS --grpc_out "${PROTO_SRC_DIR}"
        --cpp_out "${PROTO_SRC_DIR}"
        --proto_path "${PROTO_PATH}"
        --plugin=protoc-gen-grpc="${grpc_cpp_plugin_location}"
        "${PROTO_FILES}"
      DEPENDS "${PROTO_FILES}")

aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)

ADD_LIBRARY(${PROJECT_NAME} SHARED  ${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS} ${PROJECT_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    ${PROJECT_SOURCE_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake @ONLY)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    )

install(DIRECTORY include/
	DESTINATION include/${PROJECT_NAME}
)

install(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake 
    DESTINATION lib/cmake/${PROJECT_NAME}
)  

# 添加Doxygen编译

find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_LIST_DIR}/docs/Doxyfile.in)
    # set(MAINPAGE ${CMAKE_CURRENT_LIST_DIR}/docs/MainPage.md)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    # configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} )

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
