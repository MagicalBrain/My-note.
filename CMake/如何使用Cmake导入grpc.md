# 如何使用Cmake导入grpc

```
# 导入gRPC库
find_package(gRPC REQUIRED)
if (gRPC_FOUND)
    set(gRPC_INCLUDE_DIRS "/usr/local/include/grpc")
    include_directories(${gRPC_INCLUDE_DIRS})
    
    set(gRPC_LIBRARY_DIRS "/usr/local/lib")
    link_directories(${gRPC_LIBRARY_DIRS})
    add_definitions(${gRPC_DEFINITIONS})
    message(STATUS "found gRPC ${gRPC_VERSION} Library ${gRPC_LIBRARIES}")
    
    message("*****")
    message("gRPC include ${gRPC_INCLUDE_DIRS}")
    message("gRPC link ${gRPC_LIBRARY_DIRS}")
    message("gRPC definitions ${gRPC_DEFINITIONS}")
    message("gRPC Library ${gRPC_LIBRARIES}")
    message("gRPC Library_dirs ${gRPC_LIBRARY_DIRS}")
endif (gRPC_FOUND)

# 导入websocketpp库
find_package(websocketpp REQUIRED)
if (websocketpp_FOUND)
    set(websocketpp_INCLUDE_DIRS "/usr/local/include/websocketpp")
    include_directories(${websocketpp_INCLUDE_DIRS})

    set(websocketpp_LIBRARY_DIRS "/usr/local/lib")
    link_directories(${websocketpp_LIBRARY_DIRS})
    add_definitions(${websocketpp_DEFINITIONS})
    message(STATUS "found websocketpp ${websocketpp_VERSION} Library ${websocketpp_LIBRARIES}")

    message("*****")
    message("websocketpp include ${websocketpp_INCLUDE_DIRS}")
    message("websocketpp link ${websocketpp_LIBRARY_DIRS}")
    message("websocketpp definitions ${websocketpp_DEFINITIONS}")
    message("websocketpp Library ${websocketpp_LIBRARIES}")
    message("websocketpp Library_dirs ${websocketpp_LIBRARY_DIRS}")
endif (websocketpp_FOUND)
```

其实上面的都不需要，导入gRPC关键在于include```common.cmake```文件。

而websocketpp库只有头文件，只要确保`/usr/local/include/`里有websocketpp的头文件即可，或者`include`安装目录也行。
