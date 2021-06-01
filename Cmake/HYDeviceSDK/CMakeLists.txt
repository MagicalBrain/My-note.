cmake_minimum_required (VERSION 3.8)
project(HYDeviceSDK LANGUAGES CXX)

# 导入boost库
find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_definitions(${Boost_DEFINITIONS})
    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")
endif (Boost_FOUND)

# 导入opencv库
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif (OpenCV_FOUND)

# 导入gRPC库
find_package(gRPC REQUIRED)
if (gRPC_FOUND)
    include_directories(${gRPC_INCLUDE_DIRS})
    link_directories(${gRPC_LIBRARY_DIRS})
    add_definitions(${gRPC_DEFINITIONS})
    message(STATUS "found gRPC ${gRPC_VERSION} Library ${gRPC_LIBRARIES}")
endif (gRPC_FOUND)

# 导入websocketpp库
find_package(websocketpp REQUIRED)
if (websocketpp_FOUND)
    include_directories(${websocketpp_INCLUDE_DIRS})
    link_directories(${websocketpp_LIBRARY_DIRS})
    add_definitions(${websocketpp_DEFINITIONS})
    message(STATUS "found websocketpp ${websocketpp_VERSION} Library ${websocketpp_LIBRARIES}")
endif (websocketpp_FOUND)

# 添加头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加源代码文件
# aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)

# 生成库
add_library(${PROJECT_NAME} src/HYSensorClient.cpp src/HYGRPCClient.cpp src/HYWebSocketClient.cpp)

# 生成静态库
# add_library(${PROJECT_NAME} STATIC HYSensorClient.cpp HYGRPCClient.cpp HYWebsocketClient.cpp)

# 生成动态库
# add_library(${PROJECT_NAME} SHARED HYSensorClient.cpp HYGRPCClient.cpp HYWebsocketClient.cpp)

# 链接库
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${OpenCV_LIBRARIES}
    ${gRPC_LIBRARIES}
    ${websocketpp_LIBRARIES}
)


