cmake_minimum_required (VERSION 3.8)
project(HYDeviceDemo LANGUAGES CXX)

if (NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX /usr/local)
endif ()

#find_package(Boost REQUIRED)
#if (Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    link_directories(${Boost_LIBRARY_DIRS})
#    add_definitions(${Boost_DEFINITIONS})
#    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")
#endif ()

# 21-07-06 修改
find_package(Boost 1.74.0 COMPONENTS thread log log_setup)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)    
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif ()

find_package(PCL REQUIRED)
if (PCL_FOUND)    
    include_directories(${PCL_INCLUDE_DIRS})
    link_directories(${PCL_LIBRARY_DIRS})
    add_definitions(${PCL_DEFINITIONS})
    message(STATUS "found PCL ${PCL_VERSION} Library ${PCL_LIBRARIES}")
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

find_package(HYDeviceSDK REQUIRED)
if (HYDeviceSDK_FOUND)    
    include_directories(${HYDeviceSDK_INCLUDE_DIRS})
    link_directories(${HYDeviceSDK_LIBRARY_DIRS})
    add_definitions(${HYDeviceSDK_DEFINITIONS})
    message(STATUS "found HYDeviceSDK Library ${HYDeviceSDK_LIBRARIES}")
endif ()

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)

add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

target_link_libraries(${PROJECT_NAME} 
    ${HYDeviceSDK_LIBRARIES}
    ${Boost_LIBRARIES} 
    # 21-07-06
    Boost::log
    Boost::log_setup
    ${PCL_LIBRARIES} 
    ${OpenCV_LIBRARIES} 
    gRPC::grpc++_reflection 
    gRPC::grpc++ 
    gRPC::grpc
    # ${CMAKE_INSTALL_PREFIX}/lib/libre2.a
    ${CMAKE_INSTALL_PREFIX}/lib/libre2.so
    protobuf::libprotobuf          
)

install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    )
