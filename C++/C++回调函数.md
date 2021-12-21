# C++回调函数

这里的笔记参考了逼乎：回调函数（callback）是什么？问题下的几个回答

## 1、什么是回调函数？

回调函数的定义：
如果一个函数可以作为参数被其它函数调用，那么这个函数就是回调函数

## 2、回调函数有什么作用？

很多时候我们编写一个函数，或者调用别人写的函数，我们不知道这个函数什么时候结束执行返回结果（通常时间很长），但我们清除地知道调用这个函数之后应该做什么。

举个简单例子（我搞机器人比较多，就以机器人通讯为例子，可能不是很恰当）：

假设我这台机器人是非主控的（非主控就是厂家没有提供直接控制机器人运动的api），那我只能通过编写通信代码给机器人发送点位再调用机器人示教器上的代码（假设这台机器人是支持编程调用示教器程序的）
一开始我会这么写代码：

```cpp
// send() 函数被定义用来发送点位
// setPRG() 函数被定义用来 触发IO 让示教器上的机器人运动程序往下执行
if (send() == false)
    return 0;

setPRG();
```

*这个例子举得不是很好，有将简单问题复杂化的趋势*

我不知道我的点位什么时候发给机器人，不知道```send()```什么时候结束执行，但我清楚地知道成功调用```send()```之后调用```setPRG()```。
这时我们就可以使用回调函数了。

## 3、什么时候应该提供回调函数？

从2中可以知道，回调函数的使用情况是不知道被调用的函数什么时候返回，但是知道被调用函数结束后作什么？
这时从函数的使用者角度来阐述的。

如果我们是函数的编写者，我们要提供一个函数库给别人用，我们清楚地知道我们编写的函数是做什么的，但是我们不知道用户调用我们的函数之后做什么，此时就应该提供回调函数参数

## 4、怎么用回调函数？

### 直接使用函数指针

函数指针是最简单的实现回调函数的方式

```cpp
#include <cstdio>

//第一步，声明函数指针。下面是声明一个函数指针，这个函数指针的类型名叫func，它指向的函数返回值为void，调用的参数为int
typedef void(*func)(int);

void Print(int i ){
  printf("%d\n", i);
}

int main () {
    //  第二步，定义一个函数指针，并且指向一个符合函数指针声明的函数
    func f = &Print;
    f(1);  //调用函数
    return 0;
}
```

作者：码农自来也
链接：https://zhuanlan.zhihu.com/p/83943973

如果是2里的例子，那么代码可以改为：

`./code/callback4-1.cpp`

```cpp
#include <iostream>

void setPRG() {
	std::cout << "set PRG of movement." << std::endl;
}

bool send(void(*func)()) {
	std::cout << "send location" << std::endl;
	setPRG();
	return true;
}

int main() {
	send(setPRG);
	return 0;
}
```

### 如何在多态里实现回调函数

`.code/callback4-2.cpp`

```cpp
/*
* callback 4-2
* 在面向对象 多态里 实现回调函数
*/
#include <iostream>

class Interface{
  public:
    virtual void do_something() = 0;
    virtual ~Interface(){}
};

class Impl : public Interface {
  public:
  virtual ~Impl(){}
  virtual void do_something(){
     std::cout <<"Impl::dosomething" << std::endl;
  }
};

int main(){
  Interface *f = new Impl();
  f->do_something();
  return 0;
}
```

因为函数指针无法指向成员函数，所以如果要实现成员函数的回调必须要写一个该成员所属类的基类。

然后通过该类来new一个新类，再调用其成员函数，以此实现回调。

那如果不想为了实现回调而新定义一个基类，那就只能用C++11里的function和bind库了

### function库



### bind库

## 5、回调函数的类型有哪些？

### 同步回调

### 异步回调
