# boost-test的基本使用

## 简单例子

```cpp
#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(first_test)
{
  int i = 1;
  BOOST_TEST(i);
  BOOST_TEST(i == 2);
}
```

以上代码定义了一个测试模块，模块名为：`My Test`
**注意**：
模块名允许包含空格。

## boost.test提供的测试工具

```cpp
BOOST_WARN( predicate )
BOOST_CHECK( predicate )
BOOST_REQUIRE( predicate )
```

predicate——谓词

These tools are used to validate the predicate value. The only parameter for these tools is a boolean predicate value that gets validated. It could be any expression that could be evaluated and converted to boolean value. The expression gets evaluated only once, so it's safe to pass complex expression for validation.

这些工具用于验证谓词值。这些工具的唯一参数是一个经过验证的布尔谓词值。它可以是任何可以计算并转换为布尔值的表达式。表达式只计算一次，所以传递复杂表达式进行验证是安全的。

```cpp
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test )
{
    int i=2;
    BOOST_WARN( sizeof(int) == sizeof(short) );
    BOOST_CHECK( i == 1 );
    BOOST_REQUIRE( i > 5 );
    BOOST_CHECK( i == 6 ); // will never reach this check
}
```

输出：
```bash
Running 1 test case...
test.cpp(7): warning in "test": condition sizeof(int) == sizeof(short) is not satisfied
test.cpp(8): error in "test": check i == 1 failed
test.cpp(9): fatal error in "test": critical check i > 5 failed

*** 2 failures detected in test suite "Master Test Suite"
```

可见：
BOOST_WARN接受到false会发出警告warning；
BOOST_CHECK接受到false会发出错误指令error；
BOOST_REQUIRE接受到false会发出fatal error并终止当前程序；
