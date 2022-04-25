# CMakeLists如何打开调试设置

## Win10

### Visual Studio 2019

直接修改vs的编译设置和CMakeLists.txt里的添加dll的设置即可。

### Qt Creator

## Linux

其实就是CMake如何调试代码或者项目的问题。

```bash
SET(CMAKE_BUILD_TYPE "Debug")

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
```


