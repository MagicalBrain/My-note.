# C++模板类的定义与使用

标签（空格分隔）： C++

---

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




