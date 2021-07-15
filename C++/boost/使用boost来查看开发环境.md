# 使用boost来查看开发环境

```cpp
#include <iostream>

#include <boost/version.hpp>
#include <boost/config.hpp>

using namespace std;

int main() {
    cout << "Boost版本号：" << BOOST_VERSION << endl;
    cout << "Boost库版本号：" << BOOST_LIB_VERSION << endl;
    
    cout << "操作系统：" << BOOST_PLATFORM << endl;
    cout << "编译器：" << BOOST_COMPILER << endl;
    cout << "标准库：" << BOOST_STDLIB << endl;
    return 0;
}
```

输出为：
```bash
Boost版本号：107600
Boost库版本号：1_76
操作系统：Mac OS
编译器：Clang version 12.0.5 (clang-1205.0.22.9)
标准库：libc++ version 12000
```
