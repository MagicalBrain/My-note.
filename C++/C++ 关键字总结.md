# C++ 关键字总结

## static 关键字

这里参考了[^static]



[^static]: 菜鸟教程 https://www.runoob.com/w3cnote/cpp-static-usage.html

## const 关键字

使用const关键字是因为我们不想改变某些变量的值（让这些变量作为常量），如果后面还需要改的话，那么就是程序设计的问题导致用错了const。

这个时候也有补救的办法，但是这个办法不建议使用，如果需要修改const变量，应该修改的不是代码，而是相关部分的程序设计。
因为所谓补救的办法也是不能修改cosnt变量的值的，而是修改其类型使某些不支持const类型变量的函数接受。

参考链接：
[微软官方文档](https://docs.microsoft.com/zh-cn/cpp/cpp/const-cpp?view=msvc-170)
[cppreference](https://en.cppreference.com/w/cpp/keyword/const)

### C与C++里const的区别



### const_cast

```cpp
const string in = "asdf";
string* out = const_cast<string*>(&in);
```

## inline 关键字

为了解决一些频繁调用的小函数大量消耗栈空间（栈内存）的问题，特别的引入了 inline 修饰符，表示为内联函数。

栈空间就是指放置程序的局部数据（也就是函数内数据）的内存空间。

在系统下，栈空间是有限的，假如频繁大量的使用就会造成因栈空间不足而导致程序出错的问题，如，函数的死循环递归调用的最终结果就是导致栈内存空间枯竭。

```cpp
#include <stdio.h>
 
inline const char *num_check(int v)
{
    return (v % 2 > 0) ? "奇" : "偶";
}
 
int main(void)
{
    int i;
    for (i = 0; i < 100; i++)
        printf("%02d   %s\n", i, num_check(i));
    return 0;
}
```
这里代码参考[^inline]

上面的例子就是标准的内联函数的用法，使用 inline 修饰带来的好处我们表面看不出来，其实，在内部的工作就是在每个 for 循环的内部任何调用 num_check(i) 的地方都换成了 (i%2>0)?"奇":"偶"，这样就避免了频繁调用函数对栈内存重复开辟所带来的消耗。

[^inline]: 菜鸟教程 https://www.runoob.com/w3cnote/cpp-inline-usage.html

### inline使用限制

inline 的使用是有所限制的：
1. inline 只适合函数体内代码简单的涵数使用，不能包含复杂的结构控制语句例如 while、switch；
2. inline函数不能递归（即，自己内部还调用自己）。

### inline仅是一个对编译器的建议

inline 函数仅仅是一个对编译器的建议，所以最后能否真正内联，看编译器的意思，它如果认为函数不复杂，能在调用点展开，就会真正内联，并不是说声明了内联就会内联，声明内联只是一个建议而已。

### 建议 inline 函数的定义放在头文件中

其次，因为内联函数要在调用点展开，所以编译器必须随处可见内联函数的定义，要不然就成了非内联函数的调用了。所以，这要求每个调用了内联函数的文件都出现了该内联函数的定义。

因此，将内联函数的定义放在头文件里实现是合适的，省却你为每个文件实现一次的麻烦。

声明跟定义要一致：如果在每个文件里都实现一次该内联函数的话，那么，最好保证每个定义都是一样的，否则，将会引起未定义的行为。如果不是每个文件里的定义都一样，那么，编译器展开的是哪一个，那要看具体的编译器而定。所以，最好将内联函数定义放在头文件中。

### inline对类成员函数的作用

在类内定义的成员函数，默认都是内联函数。

但是在类外定义的则需要加inline关键字，否则就不是内联函数了

类内定义：

```cpp
class A
{
    public:void Foo(int x, int y) {  } // 自动地成为内联函数
}
```

将成员函数的定义体放在类声明之中虽然能带来书写上的方便，但不是一种良好的编程风格，上例应该改成：

```cpp
// 头文件
class A
{
    public:
    void Foo(int x, int y);
}
 
 
// 定义实现文件
inline void A::Foo(int x, int y){}
```

### inline 是一种"用于实现的关键字"

inline放在声明前没有任何用，而且这也不是良好的CPP代码风格，因为用户不需要知道函数是否内联

错误的用法：

```cpp
inline void Foo(int x, int y); // inline 仅与函数声明放在一起
void Foo(int x, int y){}
```

正确的用法：

```cpp
void Foo(int x, int y);
inline void Foo(int x, int y) {} // inline 与函数定义体放在一起
```

### 慎用 inline

内联能提高函数的执行效率，为什么不把所有的函数都定义成内联函数？
如果所有的函数都是内联函数，还用得着"内联"这个关键字吗？ 

内联是以代码**膨胀（复制）**为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。 
如果执行函数体内代码的时间，相比于函数调用的开销较大，那么效率的提升会很少。
另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。

以下情况不宜使用内联： 
（1）如果函数体内的代码比较长，使用内联将导致内存消耗代价较高。 
（2）如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。
（3）类的构造函数和析构函数不应该是内联的，尽管内联构造函数和析构函数容易让人误解成使用内联更有效。要当心构造函数和析构函数可能会隐藏一些行为，如"偷偷地"执行了基类或成员对象的构造函数和析构函数。所以不要随便地将构造函数和析构函数的定义体放在类声明中。一个好的编译器将会根据函数的定义体，自动地取消不值得的内联（这进一步说明了 inline 不应该出现在函数的声明中）。

## constexpr 关键字

在C++11中引入，在C++14中改进。

constexpr的作用有点类似与const，但是它不仅可以作用于变量还可作用于表达式，甚至还可以用于函数和类

### constexpr与const区别

||const|constexpr|
|:--:|:--|:--|
|作用对象|1. 变量<br>2. **类成员函数**|1. 变量<br>2. 函数<br>3. 类<br>4. **表达式**|
|作用|1. 指定变量为常量，告知编译器不可修改<br>（但如果错误地使用，也还是可以修改的，但不建议这么做，除非不得已而为之）<br>2. 指定类成员函数为**只读**函数，该类型的函数不会修改其调用的对象||



参考链接：
[微软官方文档](https://docs.microsoft.com/zh-cn/cpp/cpp/constexpr-cpp?view=msvc-170)
[cppreference](https://en.cppreference.com/w/cpp/language/constexpr)

## volatile 关键字

这个关键字是用来防止编译器优化的。说白了，在PC上面这个关键词很难起到作用，基本是只有在嵌入式平台才会用。

举个例子：

```cpp
int a;

a = 10;
a = 11;
a = 12;
a = 13;
```

以上四条语句中，编译器会认为只有最后一条`a = 13`是有用的，所以编译器只会生成`a = 13`的机器码，但是在嵌入式系统和多线程编程中，这样做可能会产生问题。

而且是否使用volatile关键字是区分普通的软件工程师和嵌入式工程师的明显区别之一。

### volatile与const

### cv关键词

https://zh.cppreference.com/w/cpp/language/cv

### volatile限定的成员函数

即所谓的非静态成员函数

### 具体例子

### 参考链接

[百度百科](https://baike.baidu.com/item/volatile/10606957)
[逼乎文章](https://zhuanlan.zhihu.com/p/138819184)
[cppreference](https://zh.cppreference.com/w/cpp/keyword/volatile)
[微软官方文档](https://docs.microsoft.com/zh-cn/cpp/cpp/volatile-cpp?view=msvc-170)