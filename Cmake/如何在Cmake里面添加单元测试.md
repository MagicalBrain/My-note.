# 如何在Cmake里面添加单元测试

## Boost.Test

### 编写测试代码

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
cmake minimum_required (VERSION 3.5 FATAL ERROR) #project name and language
project (recipe-04 LANGUAGES CXX)

 # require C++11
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# example library
add_library(sum_integers sum_integers.cpp) #main code
add executable (sum_up main.cpp)
target_link_libraries (sum_up sum_integers)

find_package (Boost 1.54 REQUIRED COMPONENTS unit_test_framework add executable(cpp_test test.cpp)
target_link_libraries(cpp_test
PRIVATE
sum_integers
Boost::unit_test_framework

# avoid undefined reference to "main" in test.cpp
target_compile_definitions(cpp_test
    PRIVATE
    BOOST_TEST_DYN_LINK
)

enable_testing()
add_test(
    NAME boost_test
    COMMAND $<TARGET FILE: cpp_test>
)
```

### 运行命令

```bash
mkdir build && cd build
cmake .. && make -j$(nproc)
ctest
```

## 参考资料

cmake cookbook（goodnotes）
https://blog.csdn.net/viking_xie/article/details/105947420
