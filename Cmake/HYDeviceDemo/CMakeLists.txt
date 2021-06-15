cmake_minimum_required (VERSION 3.13)
project(HYDeviceDemo LANGUAGES CXX)

# 导入boost库
#find_package(Boost REQUIRED)
#if (Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    link_directories(${Boost_LIBRARY_DIRS})
#    add_definitions(${Boost_DEFINITIONS})
#    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")
#endif (Boost_FOUND)

find_package(Boost 1.74.0 COMPONENTS thread log log_setup)
include_directories(${Boost_INCLUDE_DIRS})

# 导入opencv库
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif (OpenCV_FOUND)

# 导入pcl库
find_package(PCL REQUIRED)
if (PCL_FOUND)
    include_directories(${PCL_INCLUDE_DIRS})
    link_directories(${PCL_LIBRARY_DIRS})
    add_definitions(${PCL_DEFINITIONS})
    message(STATUS "found PCL ${PCL_VERSION} Library ${PCL_LIBRARIES}")
endif (PCL_FOUND)

# 导入HYDeviceSDK库
set(HYDeviceSDK_DIR "/home/hrl/hydevicesdk/HYDeviceSDK")
find_package(HYDeviceSDK REQUIRED)
if (HYDeviceSDK_FOUND)
    include_directories(${HYDeviceSDK_INCLUDE_DIRS})
    link_directories(${HYDeviceSDK_LIBRARY_DIRS})
    add_definitions(${HYDeviceSDK_DEFINITIONS})
    message(STATUS "found HYDeviceSDK ${HYDeviceSDK_VERSION} Library ${HYDeviceSDK_LIBRARIES}")

    message("*****")
    message("HYDeviceSDK include ${HYDeviceSDK_INCLUDE_DIRS}")
    message("HYDeviceSDK link ${HYDeviceSDK_LIBRARY_DIRS}")
    message("HYDeviceSDK definitions ${HYDeviceSDK_DEFINITIONS}")
    message("HYDeviceSDK Library ${HYDeviceSDK_LIBRARIES}")
    message("HYDeviceSDK Library_dirs ${HYDeviceSDK_LIBRARY_DIRS}")
endif (HYDeviceSDK_FOUND)

# add_compile_options(-std=c++14)
# add_definitions(-std=c++14)

#add_definitions(-D _USRDLL)

#启动对C++14标准的支持
set(CMAKE_CXX_STANDARD 14)
# 显式要求指明支持C++标准
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件
# include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/proto/Generated)

# 添加源代码文件
# aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

# 链接库
target_link_libraries(${PROJECT_NAME} 
    ${Boost_LIBRARIES}
    Boost::log
    Boost::log_setup
    ${OpenCV_LIBRARIES}
    ${PCL_LIBRARIES}
    ${HYDeviceSDK_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
