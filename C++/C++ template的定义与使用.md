# C++ template的定义与使用

## 1、函数模板

1.模板实例化时，模板实参必须支持模板中类型对应的所有运算符操作。

```cpp
template <typename T>
T max(const T &a, const T &b) {
    return a > b? a : b;
}

class NdGreater {
};

int main() {
    NdGreater n1, n2;
    ::max(n1, n2); // 不支持 > 编译报错
}
```

vs2019报错信息如下：

|严重性	|代码	|说明	|项目	|文件	|行|	禁止显示状态|
|--|--|--|--|--|--|--|
|错误|	C2676|	二进制“>”:“const T”不定义该运算符或到预定义运算符可接收的类型的转换|	TemplateLearning|	C:\hrl\MyLearning\CPP-Learning\TemplateLearning\test01.hpp|	5|	


2.模板编译时会进行两阶段检查

a.模板定义时，进行和类型参数无关的检查，如未定义的符号等。

b.模板实例化时，进行类型参数相关的检查。

```cpp
template<typename T>
void foo(T t) {
    undeclared(); // 如果 undeclared()未定义，第一阶段就会报错，因为与模板参数无关
    static_assert(sizeof(T) > 10, "T too small"); //与模板参数有关，只会在第二阶段报错
}
```

3.根据两阶段检查，模板在实例化时要看到完整定义，最简单的方法是将实现放在头文件中。

## 2、模板参数推断
1.函数模板的模板参数可以通过传递的函数参数进行推断。

2.函数推断时会用到参数类型转换，规则如下：

a.如果函数参数是按引用传递的，任何类型转换都不被允许。==（此处有疑问，const 转换还是可以的）==

b.如果函数参数是按值传递的，可以进行==退化（decay)转换== [^1]：const（指针或者引用只有顶层 const 可以被忽略） 和 volatile 被忽略；引用变为非引用；数组和函数变为对应指针类型。

```cpp
template <typename T>
void RefFunc(const T &a, const T &b){};

template <typename T>
void NoRefFunc(T a, T b){};

int main() {
    int *const ic = nullptr;
    const int *ci = nullptr;
    int *p = nullptr;
    RefFunc(p, ic);  // ok 顶层const可以被忽略 T 为 int *
    RefFunc(p, ci);  // error 底层const不可以忽略
    NoRefFunc(p, ci); // error 底层const不可以忽略

    int i = 0;
    int &ri = i;
    NoRefFunc(i, ri); // ok ri从int &转换为int

    int arr[4];
    NoRefFunc(p, arr);  // ok arr 被推断为int *

    NoRefFunc(4, 5.0);  // error T 可以推断为int或double
}
```

## 参考逼乎文章

https://zhuanlan.zhihu.com/p/454432180

## 附录

这里主要对文中没讲过的专业术语进行解释

[^1]: 退化转换，转换的过程中丢失了信息故称之为退化
