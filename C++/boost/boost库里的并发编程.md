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

```cpp
template< >
class atomic < I >   //对整数类型特化
{
public:
   //操作同atomic<T>

public:
   T fetch_add(T v);    //加法，返回原值
   T fetch_sub(Tv);     //减法,返回原值
   T fetch_and(T v);    //逻辑与,返回原值
   T fetch_or(T v);     //逻辑或,返回原值
   T fetch_xor(T v);    //辑异或,返回值

   T operator++();      //自增操作
   T operator--();      //自减操作
   //其他+=/-=/&=/1=/^=
}

template< typename T>
class atomics <T* >     //对指针类型特化
{
public:
   //操作同atomic<T>
public:
   T* fetch_add (ptrdiff_t v);      //指针加偏移,返回原值
   T* fetch_sub(ptrdiff_t v);       //指针减偏移,返回原值
}
```

从类摘要中我们可以发现一点, atomis大部分成员函数返回的都不是左值,这意味着它与非原子化的类型有明显的不同。

### 基本用法

#### 构造方法

构造方法分为两种方式：
1. 有参构造
   1. 创建有初值的atomic
2. 无参构造
   1. 创建没有初值的atomic，这是一个危险的操作。

#### store()和load()

store()和load()是最重要的成员函数。
以原子的方式存取atomic内部的值，不会因为并发访问造成数据不一致。

还用操作服重载简化了这两个成员函数的调用：

```cpp
atomic<bool> b{false};  //原子化bool
assert(!b.load());      //显式调用load取值

b.store(true);    //显式调用store存值
assert(b);        //隐式类型转换，等价于load
```


