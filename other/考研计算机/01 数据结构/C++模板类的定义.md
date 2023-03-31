# C++模板类

## 模板类的定义

注意在```class```上面加```template<class Type>```

Type即指代可以变化的数据类型

## 模板类的构造函数与析构函数

**构造函数**：

构造函数的类外定义：

```c++
//类外定义
template<class Type>
class<Type>::class(Type a)	//a为参数
{
    ...
}
```

构造函数的调用：

```c++
class<int> L(a);	//尖括号里要填具体的数据类型，a是构造函数的实参
```

析构函数同理

## 模板类实例化的动态内存分配

```c++
class<Type> *p = new class<Type>(a);	//a为构造函数的实参根据构造函数的定义来
```



## 模板类的成员函数的声明、定义与调用

成员函数如果是在类定义的内部定义则与普通类的成员函数定义一样，但如果是在类的外部则稍有不同

普通类成员函数在类外定义：

```c++
type class::func()
{
    ...
}
```

模板类成员函数类外定义：

```c++
template<class Type>
type class<Type>::func()
{
    ...
}
```

模板类成员函数的调用：

```c++
//首先实例化一个成员
class<int> L;	//这里的尖括号里必须得填具体的数据类型才能实例化
L.func();
```




```c++
#pragma once
#include <iostream>

using namespace std;

typedef unsigned long Item;

template<class Type>
class Stack
{
private:
	enum { MAX = 10 };
	Type items[MAX];
	int top;
public:
	Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Type&item);
	bool pop(Type&item);
};

template<class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
Stack<Type>::isEmpty()
{
	return top == 0;
}

template<class Type>
Stack<Type>::isFull()
{
	return top == MAX;
}

template<class Type>
Stack<Type>::push(const Type& item)
{
	if (true)
	{

	}
}

//#endif
```