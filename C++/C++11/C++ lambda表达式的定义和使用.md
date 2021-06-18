# C++ lambda表达式的定义和使用

lambda表达式是C++11标准才有的内容。

## 我们要明白lambda表达式的作用是什么？

 lambda表达式本质就是一个**函数**，而且这个函数是匿名的，也就是一个没有函数名的函数。
为什么不需要函数名呢，因为我们直接（一次性的）用它，嵌入式用的它，不需要在其他地方调用它。
    lambda表达式也叫闭包。闭就是封闭的意思，封闭的意思就是其他地方都不调用它，包就是函数。
    lambda表达式 其实就是一个函数对象，他内部创建了一个重载()操作符的类。
    lambda 表达式的简单语法如下：[capture] (parameters) -> return value { body },只有 [capture] 捕获列表和 { body } 函数体是必选的，其他可选。

## 如何定义一个lambda表达式

## 如何使用定义好的lambda表达式

## 例子 Example

```cpp

```

## 参考资料

1. [cppreference][cppreference]
2. 《C++ Primer》5th chapter 10.3.2

[cppreference]:https://en.cppreference.com/w/cpp/language/lambda