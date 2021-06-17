# function函数模板类

首先注意与`std::bind`区分，`std::bind`是一个函数模板，而`std::function`是一个函数模板类（是一个类）。

这个类主要是为了方便定义回调函数（指针）的。

## 包含头文件

```cpp
#include <functional>
```

## 使用例子

```cpp
#include <iostream>
#include <string>
#include <functional>

using namespact std;

std::function<void(int a)> fun1;
std::function<void(string str)> fun2;
std::function<void(int a, int b)> fun3;

void norm1(int a) {
    cout << "普通函数" << endl;
}

static void norm2(string str) {
    cout << "普通静态函数" << endl;
    cout << str << endl;
}

auto lamba = [](int a, int b) -> string{
    int c = a + b;
    return "boy";
}

int main() {
    fun1 = norm1;
    fun1(3);

    fun2 = static norm2;
    fun2("hello");

    fun3 = lambda;
    cout << fun3(2, 3) << endl;
    return 0;
}
```
