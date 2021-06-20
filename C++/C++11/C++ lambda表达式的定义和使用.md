# C++ lambda表达式的定义和使用

lambda表达式是C++11标准才有的内容。

## 我们要明白lambda表达式的作用是什么？

 lambda表达式本质就是一个**函数**，而且这个函数是匿名的，也就是一个没有函数名的函数。也可以理解为一个未命名的[**内联函数**]。
为什么不需要函数名呢，因为我们直接（一次性的）用它，嵌入式用的它，不需要在其他地方调用它。
    lambda表达式也叫闭包。闭就是封闭的意思，封闭的意思就是其他地方都不调用它，包就是函数。
    lambda表达式 其实就是一个函数对象，他内部创建了一个重载()操作符的类。
    lambda 表达式的简单语法如下：

```cpp
[capture] (parameters) -> return value { body }
```

只有 [capture] 捕获列表和 { body } 函数体是必选的，其他可选。

## 如何定义一个lambda表达式

### 带参数的例子

例子1:
```cpp
[] (const string &a, const string &b){ return a.size() <b.size() ;}
```

**注意**：
如果在lambda表达式中没有`return`语句，则默认返回`void`。

这是一个捕获列表为空的lambda表达式，等价于函数：
```cpp
//比较函数,用来按长度排序单词
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

捕获列表为空，说明lambda表达式不使用它所在区域中的局部变量。

### 使用捕获列表的例子

```cpp
[sz](const string &a)
    {return a.size() >= sz; };
```

捕获列表只用于局部的非static变量，lambda可直接使用所在区域外已声明的命名空间里的name，例如cout。



## 如何使用定义好的lambda表达式

```cpp
auto f1 = [](const int a, const int b){return a + b;};

std::cin >> a >> b;
std::cout << f1(a, b) << std::endl;
```

这是一个最简单的例子。
**注意**：`auto`标识符不可以省略。

## 例子 Example

```cpp

```

## C++ Primer习题

### 10.3.2节：
练习10.14:编写一个lambda，接受两个int，返回它们的和。

```cpp
[](const int a, const int b){return a + b;};
```

练习10.15:编写一个lambda，捕获它所在函数的int，并接受一个int参数。lambda应该返回捕获的int和int参数的和。

```cpp
int num;
[num](const int a){return a + num;};
```

练习10.16:使用lambda编写你自己版本的biggies

`biggies`函数的作用是：
给定一个存放若干个字符串的`vector`，打印输出所有超过给定长度的字符串。

书本上完整的`biggies`：

```cpp
void biggies (
    vector<string> &words,
    vector<string>::size_type sz    //这是一个unsigned类型用于存储vector容器最大长度
    )
{
    elimDups (words) ; //将words按字典序排序,删除重复单词
    //按长度排序,长度相同的单词维持字典序
    stable sort (
        words.begin(), words.end (),
        [] (const string &a, const string &b)
            return a.size() <b.size();}
    );
    //获取一个迭代器,指向第一个满足size ()>= sz的元素
    auto wc = find_if (
        words.begin(), words.end (),
        [sz] (const string &a)
            { return a.size () >= sz; }
    );
    //计算满足size >= sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " "<< make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    //打印长度大于等于给定值的单词,每个单词后面接一个空格
    for_each(
        wc, words.end(),
        [] (const string &s) {cout << s << "";}
    );
    cout < endl;
}
```

```cpp

```

练习10.17:重写10.3.1节练习10.12（第345页）的程序，在对sort的调用中使用lambda来代替函数compareIsbn。

```cpp

```

练习10.18:重写biggies，用partition代替find-if。我们在10.3.1节练习10.13（第345页）中介绍了partition算法。

```cpp

```

练习10.19:用stable-partition重写前一题的程序，与stablesort类似，在划分后的序列中维持原有元素的顺序。

```cpp

```

## 名词解释

**内联函数**：todo

## 参考资料

1. [cppreference][cppreference]
2. 《C++ Primer》5th chapter 10.3.2

[cppreference]:https://en.cppreference.com/w/cpp/language/lambda