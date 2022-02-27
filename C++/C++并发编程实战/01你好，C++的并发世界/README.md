# 你好，C++的并发世界

## 1.1 何为并发

## 1.2 为什么使用并发

## 1.3 C++中的并发和多线程

## 1.4 开始入门

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