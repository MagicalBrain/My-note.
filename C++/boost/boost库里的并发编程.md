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

#### exchange()

#### storage()

### 并发顺序一致性

atomic库在头文件`<boost/memory_order.hpp>`里定义了内存访问顺序概念,它是一个简单的枚举类型,允许用户自己控制代码的顺序一致性:

```cpp
enum memory_order {  //位于boost名字空间
   memory_order_relaxed =0,
   memory_order_consume = 1,
   memory_order_acquire =2,
   memory_order_release =4,
   memory_order_acq_rel =6,   // acquire | release
   memory_order_seg_cst =14   // acg_rel | 8
};
```

实际上，atomic<T> 的每个成员函数都有一个 `memory_order`默认参数（操作符重载除外），它指定了原子操作的内存顺序：

```cpp
template< typename T >
class atomic : public atomics::detail::base atomic<T>
{
public:
   т load (memory order order = memory order seq cst);
   void store(T value, memory_order order = memory_order_seq_cst);
   T exchange (T new value, memory_order = memory_order_seq cst);
   bool compare exchange weak (T & expected, T desired, memory order);
   bool compare exchange strong (T & expected, T desired, memory_order);
}
```

可见`memory_order`的默认值是`memory_order_seq_cst`，它是最严格的顺序一致性约束，不允许编译器或CPU为优化而调整代码或指令的执行顺序，保证在并发环境里任何CPU看到的指令顺序是相同的，程序的执行与CPU单线程时相同。

```cpp
template<typename T>
class ref_count {    //泛型的引用计数类

private:
   typedef boost::atomic<int> atomic type;
   //定义atomic类型
   mutable atomic type m count{0};
   //初始化,注意是mutable

protected:
   ref_count () {}   //这里不能使用default
   ~ref_count () {}

public:
   typedef boost::intrusive_ptr<T> counted ptr; //定义intrusive_ptr 

   //增加引用计数
   void add_ref() const {
      //不做任何顺序要求
      m_count.fetch_add(1, boost: :memory_ order relaxed);
   }

   //减少引用计数
   void sub_ref() const {

      //释放,值的修改后续操作可见
      if (m_count.fetch_sub(1, boost: :memory order release) == 1)
         //原子级别的线程防护
         boost::atomic_thread_fence(boost::memory_order_acquire) ; //获取之前的修改
      delete static_cast<const T*>(this); //删除指针,需要转型
   }

   //获取引用计数,注意decltype
   //C++14里可以直接用auto推导
   //取值,也可以用隐式类型转换
   decltype (m_count.load()) count() const
   {
      return m count.load();
   }

public:
   //可变参数模板
   template<typename ... Args>
   static counted_ptr make_ptr(Args&& ... args) //工厂函数
   {
      return counted_ptr(new T(std::forward<Args>(args) ...));
   }

private:
   friend void intrusive_ptr_add_ref(const T* p) //intrusive_ptr要求函数
   {
      p->add_ref();
   }

   friend void intrusive_ptr_release(const T* p) //intrusive ptr要求函数
   {
      p->sub_ref();
   }
};
```

ref_count的用法和intrusive_ref_counter一样，只要自定义类从它派生就会自
动获得引用计数能力，能够被intrusive_ptr管理：

```cpp
//添加引用计数能力
class demo : public ref_count<demo>
{
public:
   demo() = default;
   ~demo()= default;
   int x;
};

int main () {
   auto p = demo::make_ptr();
   
   //创建智能指针
   p->x=10;
   assert (p->x== 10) ;
   assert (p->count() == 1);      //检查引用计数
}
```
