# std::shared_ptr智能指针的使用

## 包含的头文件

```cpp
#include <memory>
```

std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Several shared_ptr objects may own the same object. The object is destroyed and its memory deallocated when either of the following happens:

the last remaining shared_ptr owning the object is destroyed;
the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().

The object is destroyed using delete-expression or a custom deleter that is supplied to shared_ptr during construction.

shared_ptr是一个智能指针，通过指针保持对象的共享所有权。多个shared_ptr对象可能拥有同一个对象。当发生以下情况之一时，对象将被销毁并释放其内存:

最后剩下的拥有该对象的shared_ptr被销毁;
通过operator=或reset()为拥有该对象的最后一个shared_ptr分配另一个指针。

对象是使用delete-expression或在构造期间提供给shared_ptr的自定义删除器销毁的。

A shared_ptr can share ownership of an object while storing a pointer to another object. This feature can be used to point to member objects while owning the object they belong to. The stored pointer is the one accessed by get(), the dereference and the comparison operators. The managed pointer is the one passed to the deleter when use count reaches zero.

A shared_ptr may also own no objects, in which case it is called empty (an empty shared_ptr may have a non-null stored pointer if the aliasing constructor was used to create it).

shared_ptr可以共享一个对象的所有权，同时存储指向另一个对象的指针。此特性可用于在拥有成员对象所属对象时指向成员对象。存储的指针是通过get()、解引用和比较操作符访问的指针。托管指针是当使用计数为零时传递给删除器的指针。
shared_ptr也可能不拥有任何对象，在这种情况下它被称为空的(如果使用别名构造函数创建了一个空的shared_ptr可能有一个非空的存储指针)。

## 简单的例子

```cpp
#include <iostream>
#include <memory>

using namespace std;
using std::shared_ptr;

int main() {
    shared_ptr<string> ptr;
    if (ptr == nullptr)
        cout << "ptr is nullptr" << endl;
    return 0;
}
```

输出结果为：
```bash
ptr is nullptr
```

[std::shared_ptr][std::shared_ptr]

[std::shared_ptr]:https://en.cppreference.com/w/cpp/memory/shared_ptr
