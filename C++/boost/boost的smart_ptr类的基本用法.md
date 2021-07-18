# boost的smart_ptr类的基本用法

## scoped_ptr

`scoped_ptr`是一个很类似`auto-ptr/unique-ptr`的智能指针，它包装了new操作符在堆上分配的动态对象，能够保证动态创建的对象在任何时候都可以被正确地删除。但scoped_ptr的所有权更加严格，不能转让，一旦scoped_ptr获取了对象的管理权，我们就无法再从它那里取回来。scoped-ptr拥有一个很好的名字，它向代码的阅读者传递了明确的信息：这个智能指针只能在本作用域里使用，不希望被转让。

```cpp
scoped_ptr<string> sp(new string("text");   //构造一个scoped_ptr对象 
assert(sp);      //使用显式bool转型
assert(sp ！= nullptr);     //空指针比较操作
```
