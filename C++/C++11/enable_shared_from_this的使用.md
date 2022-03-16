# std::enable_shared_from_this的使用

## 使用场景

在很多场合，经常会遇到一种情况，想要安全地获取对象的this指针。
一般来说我们不建议直接返回this指针，可以想象下有这么一种情况，返回的this指针保存在外部一个局部/全局变量，当对象已经被析构了，但是外部变量并不知道指针指向的对象已经被析构了，如果此时外部使用了这个指针就会发生程序奔溃。
既要像指针操作对象一样，又能安全的析构对象，很自然就想到，智能指针就很合适！

那么智能指针如何使用呢？现在我们来看一段代码。

```cpp
#include <iostream>
#include <memory>

class Widget{
public:
    Widget(){
        std::cout << "Widget constructor run" << std::endl;
    }
    ~Widget(){
        std::cout << "Widget destructor run" << std::endl;
    }

    std::shared_ptr<Widget> GetSharedObject(){
        return std::shared_ptr<Widget>(this);
    }
};

int main()
{
    std::shared_ptr<Widget> p(new Widget());            // 调用了一次无参构造函数
    std::shared_ptr<Widget> q = p->GetSharedObject();   // 调用了一次拷贝构造函数

    std::cout << p.use_count() << std::endl;            // 输出引用数
    std::cout << q.use_count() << std::endl;            // 输出引用数

    return 0;
}
// 运行enable_shared_from_this01.cpp
```

运行结果：

```bash
Widget constructor run # 调用了一次构造函数
1
1
Widget destructor run   # 程序结束运行调用析构函数
Widget destructor run   # 程序结束运行调用析构函数
free(): double free detected in tcache 2
[1]    167 abort (core dumped)  ./enable_shared_from_this01.o
```

调用了一次构造函数却调用了两次析构函数，其实这里看不出什么，因为`q = p`的时候应该是调用了一次拷贝构造函数
但问题在于p和q的引用次数都是1，它们指向的都是一个对象。
程序运行的时候从始至终都只有一个实例化对象，但却调用了两次无参析构函数，这才是问题所在。
第二次调用无参析构函数肯定会崩溃，因为析构函数要释放的对象已经被释放了。

而这个时候就需要我们使用`std::enable_shared_from_this`出场了

`std::enable_shared_from_this`可以避免上述问题。

## 原理

`std::enable_shared_from_this`的定义：

```cpp
#include <memory>
template<class _Tp>
class _LIBCPP_TEMPLATE_VIS enable_shared_from_this
{
    mutable weak_ptr<_Tp> __weak_this_;
protected:
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    enable_shared_from_this() _NOEXCEPT {}
    _LIBCPP_INLINE_VISIBILITY
    enable_shared_from_this(enable_shared_from_this const&) _NOEXCEPT {}
    _LIBCPP_INLINE_VISIBILITY
    enable_shared_from_this& operator=(enable_shared_from_this const&) _NOEXCEPT
        {return *this;}
    _LIBCPP_INLINE_VISIBILITY
    ~enable_shared_from_this() {}
public:
    _LIBCPP_INLINE_VISIBILITY
    shared_ptr<_Tp> shared_from_this()
        {return shared_ptr<_Tp>(__weak_this_);}
    _LIBCPP_INLINE_VISIBILITY
    shared_ptr<_Tp const> shared_from_this() const
        {return shared_ptr<const _Tp>(__weak_this_);}

#if _LIBCPP_STD_VER > 14
    _LIBCPP_INLINE_VISIBILITY
    weak_ptr<_Tp> weak_from_this() _NOEXCEPT
       { return __weak_this_; }

    _LIBCPP_INLINE_VISIBILITY
    weak_ptr<const _Tp> weak_from_this() const _NOEXCEPT
        { return __weak_this_; }
#endif // _LIBCPP_STD_VER > 14

    template <class _Up> friend class shared_ptr;
};
```

std::enable_shared_from_this是模板类，内部有个_Tp类型weak_ptr指针，调用shared_from_this成员函数便可获取到_Tp类型智能指针，从这里可以看出，_Tp类型就是我们的目标类型。

再来看看std::enable_shared_from_this的构造函数都是protected，因此不能直接创建std::enable_from_shared_from_this类的实例变量，只能作为基类使用。

可见`std::enable_shared_from_this`只能被继承使用

因此使用方法如下代码所示：

```cpp
#include <iostream>
#include <memory>

// 继承 std::enable_shared_from_this模板类
class Widget : public std::enable_shared_from_this<Widget>{
public:
    Widget(){
        std::cout << "Widget constructor run" << std::endl;
    }
    ~Widget(){
        std::cout << "Widget destructor run" << std::endl;
    }

    // 实现 获取this智能指针
    std::shared_ptr<Widget> GetSharedObject(){
        return shared_from_this();
    }
};

int main()
{
    std::shared_ptr<Widget> p(new Widget());
    std::shared_ptr<Widget> q = p->GetSharedObject();

    std::cout << p.use_count() << std::endl;
    std::cout << q.use_count() << std::endl;

    return 0;
}
// 运行enable_shared_from_this02.cpp
```

运行程序输出结果为：
```bash
Widget constructor run
2
2
Widget destructor run
```

这样子就对了，引用计数也是正确的，程序就不会崩溃了

## 实战

## 参考链接

https://zhuanlan.zhihu.com/p/393571228#:~:text=std%3A%3Aena,%E6%88%91%E4%BB%AC%E7%9A%84%E7%9B%AE%E6%A0%87%E7%B1%BB%E5%9E%8B%E3%80%82
