# thread的使用方法

这里除了介绍`std::thread`的使用方法还介绍了它和其它cpp线程工具一起使用的方法

`std::thread` 是 CPP 11 标准引进的

## 创建线程

```cpp
#include <iostream>
#include <thread>  // thread 所在的头文件

void hello()  // 线程将要执行的函数或者代码块
{
  std::cout << "Hello Concurrent World\n";
}

int main() {
  std::thread t(hello);  // 将线程和它将要执行的函数绑定
  t.join();  // 
}
```

### 线程创建需要注意的事情

```cpp
#include <iostream>
#include <thread>  

void hello()  
{
    while (1)
    std::cout << "Hello Concurrent World\n";
}

void func() {
    std::thread t(hello);
}

int main() {
    func();

    // 让主线程不要退出
    while(1) {};
    return 0;
}
```

乍看之下好像没有问题，实际运行的时候肯定会崩溃

崩溃的原因就是在func函数调用结束之后，func中的局部变量t（线程对象）被销毁；
但是此时t的线程函数还在运行。

所以我们在使用`std::thread`类的时候一定要小心：
必须保证线程函数运行的时候其线程对象有效。

想让程序运行不崩溃，我们还可以使用`detach()`方法
`detach()`方法可以让线程对象与线程函数分离，这样即使线程对象被销毁，也不会影响线程函数的运行。

修改代码如下：

```cpp
void func() {
    std::thread t(hello);
    t.detach();
}
```

## 获取线程ID

在Cpp 11 里，我们可以使用`std::this_thread`类的`get_id` 方法获取当前线程ID
`std::this_thread::get_id()`是一个类静态方法
`std::thread::get_id()`是一个类实例方法

```cpp
//test_cpp11_thread_id.cpp
#include <thread>
#include <iostream>
#include <sstream>

void worker_thread_func() {
    while (true) {}
}

int main() {
    std::thread t(worker_thread_func);

    // 获取线程的ID
    std::thread::id worker_thread_id = t.get_id();
    std::cout << "Worker thread id:" << worker_thread_id << std::endl;

    // 获取主线程id
    std::thread::id main_thread_id = std::this_thread::get_id();
    // 先将std::thread::id 转换为std::ostringstream 对象
    std::ostringstream oss;
    oss << main_thread_id;
    // 再将 std::ostringstream对象转换为 std::string
    std::string str = oss.str();
    std::cout << "main_thread_id is: " << str << std::endl;
    // 最后将 std::string str 转换为int
    unsigned long long threadid = std::stoull(str);
    std::cout << "main_thread_id is: " << threadid << std::endl;=

    while (true) {}
    return 0;
}
```

## 等待线程结束

## 参考链接

https://mp.weixin.qq.com/s/VHLhLHHHqj_9sXn_YbnIMw
