# C++类的使用

## 类成员的类型

### public

class的默认成员类型。

所有调用class的代码都可以调用这个类型的类成员

### private

struct的默认成员类型。

只有这个类的成员函数内的代码可以调用这个类型的类成员

### protected

多用于类的多态中。

只有这个类自己和它的子类可以访问，其它代码都不能访问这个属性的成员。

## 构造函数

## 类的继承

### 虚基类

### 多态

C++是通过虚基类的机制来实现多态的抽象的。

#### 多态里的构造函数

#### 多态里的析构函数

## 友元函数

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。

友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend，如下所示：

```cpp
class Box
{
   double width;
public:
   double length;
   friend void printWidth( Box box );
   void setWidth( double wid );
};

#include <iostream>
 
using namespace std;
 
class Box
{
   double width;
public:
   friend void printWidth( Box box );
   void setWidth( double wid );
};
 
// 成员函数定义
void Box::setWidth( double wid )
{
    width = wid;
}
 
// 请注意：printWidth() 不是任何类的成员函数
void printWidth( Box box )
{
   /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
   cout << "Width of box : " << box.width <<endl;
}
 
// 程序的主函数
int main( )
{
   Box box;
 
   // 使用成员函数设置宽度
   box.setWidth(10.0);
   
   // 使用友元函数输出宽度
   printWidth( box );
 
   return 0;
}
```

成员函数与友元函数的区别：

1. 友元函数的声明必须有`friend`关键字；而成员函数没有
2. 成员函数的调用必须通过类的实例对象；而友元函数无需通过类的实例对象

