# 如何使用Cmake来编译项目


## 以下是一个项目的CMakeList.txt

仅仅是作为参考

```
cmake_minimum_required (VERSION 3.8)
project(HYDeviceSDK LANGUAGES CXX)

find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_definitions(${Boost_DEFINITIONS})
    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")
endif (Boost_FOUND)

find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif (OpenCV_FOUND)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)

add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${PCL_LIBRARIES}
    ${OpenCV_LIBRARIES}
)

if (NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX /usr/local)
endif (NOT CMAKE_INSTALL_PREFIX)

install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    )
```