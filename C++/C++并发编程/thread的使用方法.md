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
#include <thread>  // 1

void hello()  // 2
{
  std::cout << "Hello Concurrent World\n";
}

int main() {
  std::thread t(hello);  // 3
  t.join();  // 4
}
```

## 获取线程ID

## 等待线程结束

## 参考链接

https://mp.weixin.qq.com/s/VHLhLHHHqj_9sXn_YbnIMw
