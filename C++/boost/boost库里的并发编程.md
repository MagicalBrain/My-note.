# boost库里的并发编程

boost库中有3个用于并发编程的组件，分别是：
1. atomic
   1. 实现了基于C++标准库的原子操作
2. thread
   1. 兼容C++标准库的线程库
3. asio
   1. 用于同步和异步I/O操作的功能强大的库

## atomic组件

包含头文件：
```cpp
#include <boost/atomic.hpp>
using namespace boost;
```
