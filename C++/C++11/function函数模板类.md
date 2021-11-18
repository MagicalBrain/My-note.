# function函数模板类

首先注意与`std::bind`区分，`std::bind`是一个函数模板，而`std::function`是一个函数模板类（是一个类）。

这个类主要是为了方便定义回调函数（指针）的。

## 包含头文件

```cpp
#include <functional>
```

## function操作

```cpp
function<T> f;      //f是一个用来存储可调用对象的空function，这些可调用对象的调用形式应该与函数类型 相同（即T是retType（args）
function<T> f(nullptr) ;    //显式地构造一个空function
function<T> f (obj);        //在f中存储可调用对象obj的副本
f;       //将f作为条件：当f含有一个可调用对象时为真；否则为假
f(args);    //调用f中的对象，参数是args
```

**function<T>**的成员类型
```cpp
result_type     //该function类型的可调用对象返回的类型
argument_type   //
first_argument_type 
second_argument_type
```

当T有一个或两个实参时定义的类型。如果 只有一个实参，则argument_type是该类型的同义词；如果有两个实参， 则first_argument_type和second_argument_type分别代表两个实参的类型

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

[function官网教程][function官网教程]

[function官网教程]:https://en.cppreference.com/w/cpp/utility/functional/function

```cpp
template< class >
class function; /* undefined */
//或者
template< class R, class... Args >
class function<R(Args...)>;
```

Class template std::function is a general-purpose polymorphic function wrapper. Instances of std::function can store, copy, and invoke any CopyConstructible Callable target -- functions, lambda expressions, bind expressions, or other function objects, as well as pointers to member functions and pointers to data members.

类模板`std::function`是一个通用的多态函数包装器。`std::function`的实例可以存储、复制和调用任何CopyConstructible和Callable的目标对象：函数、lambda表达式、`bind`表达式或其他函数对象，以及指向成员函数的指针和指向数据成员的指针。

The stored callable object is called the target of std::function. If a std::function contains no target, it is called empty. Invoking the target of an empty std::function results in std::bad_function_call exception being thrown.

存储的可调用对象称为`std::function`的target。如果`std::function`不包含target，则称为空。调用空`std::function`的target会引发`std::bad_function_call`异常。

std::function satisfies the requirements of CopyConstructible and CopyAssignable.

`std::function`满足CopyConstructible和CopyAssignable的要求。

## 成员类型 Member types

|Type	|Definition|
|:-:|:-:|
|result_type|	R|
|argument_type(deprecated in C++17)(removed in C++20)	|T if sizeof...(Args)==1 and T is the first and only type in Args...|
|first_argument_type(deprecated in C++17)(removed in C++20)	|T1 if sizeof...(Args)==2 and T1 is the first of the two types in Args...|
|second_argument_type(deprecated in C++17)(removed in C++20)	|T2 if sizeof...(Args)==2 and T2 is the second of the two types in Args...|

## Notes

Care should be taken when a std::function whose result type is a reference is initialized from a lambda expression without a trailing-return-type. Due to the way auto deduction works, such lambda expression will always return a prvalue. Hence, the resulting reference will usually bind to a temporary whose lifetime ends when std::function::operator() returns.

当你使用没有返回类型的lambda表达式初始化 结果类型为引用的`std::function`时，应该小心。由于自动推断的工作方式，这样的lambda表达式将总是返回一个prvalue。因此，产生的引用通常会绑定到一个临时变量，当`std::function::operator()`返回时，该临时变量的生存期结束。

```cpp
std::function<const int&()> F([]{ return 42; });
int x = F(); 
// Undefined behavior: the result of F() is a dangling reference
//未定义的行为:F()的结果是一个悬空引用
```

## 例子 Example

```cpp
#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
 
    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();
 
    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();
 
    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);
 
    // store a call to a data member accessor
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
 
    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);
 
    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
}
```

应该输出：

```cpp
-9
42
31337
314160
314160
num_: 314159
314161
314162
18
```