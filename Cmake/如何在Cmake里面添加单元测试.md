# 如何在Cmake里面添加单元测试

## Boost.Test

## CMake Cookbook上的例子

### `sum_integers.hpp`
```cpp
#pragma once
#include <vector>
int sum_integers(const std::vector<int> integers);
```


### `sum_integers.cpp`
```cpp
#include "sum_integers.hpp"
#include <vector>

int sum_integers(const std::vector<int> integers) {
    auto sum =0;
    for (auto i : integers) {
        sum += i;
    }
    return sum;
}
```

### `main.cpp`
```cpp
#include "sum_integers.hpp"

#include <iostream>
#include <string>
#include <vector>

// we assume all arguments are integers and we sum them up 
// for simplicity we do not verify the type of arguments 
int main(int argc, char *argv[]) {
    std::vector<int> integers;
    for (auto i = 1; i < argc; i++) 
        integers.push_back(std: :stoi(argv[i]));
    auto sum = sum_integers(integers);
    
    std::cout << sum << std: endl;
}
```

假设有一个`test.cpp`：

```cpp
#include "sum_integers.hpp"
#include <vector>

#define BOOST_TEST_MODULE example_test_suite
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(add_example)
{
    auto integers = {1, 2, 3, 4, 5};
    auto result = sum_integers(integers);
    BOOST_REQUIRE(result == 15);
}
```

### 编写CMakeLists.txt

```bash
#set minimum cmake version
cmake_minimum_required (VERSION 3.5) 
#project name and language
project(recipe-04 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# example library
add_library(sum_integers sum_integers.cpp) 
#main code
add_executable(sum_up main.cpp)
target_link_libraries(sum_up sum_integers)

find_package(Boost REQUIRED COMPONENTS unit_test_framework) 
add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test
    PRIVATE
    sum_integers
    Boost::unit_test_framework
)
# avoid undefined reference to "main" in test.cpp
target_compile_definitions(cpp_test
    PRIVATE
    BOOST_TEST_DYN_LINK
)

enable_testing()
add_test(
    NAME boost_test
    COMMAND $<TARGET_FILE:cpp_test>
)

```

### 运行命令

```bash
mkdir build && cd build
cmake .. && make -j$(nproc)
ctest
```

----

测试代码目录下CMakeLists.txt：
```bash
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
 
include_directories(${Boost_INCLUDE_DIRS})
 
add_executable(Test first_test.cpp)
 
target_link_libraries(Test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

```

项目主目录下CMakeLists.txt：
```bash
include(CTest)
enable_testing()
add_subdirectory(test)
add_test(NAME unit_test COMMAND Test)
```



## 参考资料

cmake cookbook（goodnotes）
https://blog.csdn.net/viking_xie/article/details/105947420
