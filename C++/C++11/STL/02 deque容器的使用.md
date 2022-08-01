# C++ deque容器的使用

## deque的简单介绍

`deque`是一种顺序容器，本质是一种双端队列。

`std::deque `（ double-ended queue ，双端队列）是有下标顺序容器，它允许在其首尾两端快速插入及删除。
另外，在 deque 任一端插入或删除不会非法化指向其余元素的指针或引用。

与 std::vector 相反， deque 的元素不是相接存储的：
典型实现用单独分配的固定大小数组的序列，外加额外的登记;
==这表示下标访问必须进行二次指针解引用==;
与之相比 vector 的下标访问只进行一次。

deque 的存储按需自动扩展及收缩。
扩展 deque 比扩展 std::vector 更优，因为它不涉及到复制既存元素到新内存位置。
另一方面， deque 典型地拥有较大的最小内存开销；
只保有一个元素的 deque 必须分配其整个内部数组
（例如 64 位 libstdc++ 上为对象大小 8 倍； 64 位 libc++ 上为对象大小 16 倍或 4096 字节的较大者）。

## 常见操作的复杂度

deque 上常见操作的复杂度（效率）如下：

1. 随机访问——常数 O(1)
2. 在结尾或起始插入或移除元素——常数 O(1)
3. 插入或移除元素——线性 O(n)

std::deque 满足容器 (Container) 、知分配器容器 (AllocatorAwareContainer) 、序列容器 (SequenceContainer) 和可逆容器 (ReversibleContainer) 的要求。

## 模板形参

T	-	元素的类型。
T 必须满足可复制赋值 (CopyAssignable) 和可复制构造 (CopyConstructible) 的要求。	(C++11 前)
加诸元素的要求依赖于容器上进行的实际操作。泛言之，要求元素类型是完整类型并满足可擦除 (Erasable) 的要求，但许多成员函数附带了更严格的要求。	(C++11 起)
Allocator	-	用于获取/释放内存及构造/析构内存中元素的分配器。类型必须满足分配器 (Allocator) 的要求。若 Allocator::value_type 与 T 不同则行为未定义 (C++20 前)程序非良构 (C++20 起)。

## 元素访问

```cpp
at
// 访问指定的元素，同时进行越界检查
// (公开成员函数)

operator[] 
// 访问指定的元素
// (公开成员函数)

front
// 访问第一个元素
// (公开成员函数)

back
// 访问最后一个元素
// (公开成员函数)
```

## 增删元素

* clear
清除内容
(公开成员函数)

* insert
插入元素
(公开成员函数)

emplace
  
(C++11)
 
原位构造元素
(公开成员函数)

erase
 
擦除元素
(公开成员函数)

push_back
 
将元素添加到容器末尾
(公开成员函数)

emplace_back
  
(C++11)
 
在容器末尾就地构造元素
(公开成员函数)

pop_back
 
移除末元素
(公开成员函数)

push_front
 
插入元素到容器起始
(公开成员函数)

emplace_front
  
(C++11)
 
在容器头部原位构造元素
(公开成员函数)

pop_front
 
移除首元素
(公开成员函数)

resize
 
改变容器中可存储元素的个数
(公开成员函数)

swap
 
交换内容
(公开成员函数)

## 参考连接

[cppreference](https://zh.cppreference.com/w/cpp/container/deque)
