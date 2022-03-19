# Const关键字的用法

## 修饰变量

## 修饰类成员函数

假设有个类：

```cpp
#pragma once

#include <iostream>

class MyClassTestConst
{
public:
	MyClassTestConst();
	~MyClassTestConst();

public:
	void getNum(int& num) const;

	void setNum01(int num) const;

	void setNum02(int num) ;

private:
	int num_;
};
```

类实现：

```cpp
#include "ConstFunction.h"

MyClassTestConst::MyClassTestConst()
{
	num_ = 0;
}

MyClassTestConst::~MyClassTestConst()
{
}

void MyClassTestConst::getNum(int& num) const
{
	num = num_;
}

void MyClassTestConst::setNum01(int num) const
{
	// 下面这行被注释的代码会报错
	// 
	//num_ = num;
}

void MyClassTestConst::setNum02(int num)
{
	num_ = num;
}
```

测试函数：

```cpp
void testConstFunction() {
	MyClassTestConst test_demo;

	int num;
	test_demo.getNum(num);
	std::cout << num << std::endl;

	test_demo.setNum01(10);
	test_demo.getNum(num);
	std::cout << num << std::endl;

	test_demo.setNum02(10);
	test_demo.getNum(num);
	std::cout << num << std::endl;
}
```

输出结果：

```bash
MainConsole is running!
0
0
10
```
