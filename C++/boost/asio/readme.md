# boost库里的asio

## 学习目标

- [ ] 1. 掌握asio库的常用接口和使用
- [ ] 2. 实现简单的字符串收发
- [ ] 3. 实现2D图的收发
- [ ] 4. 实现3D点云的收发
- [ ] 5. 实现多张2D图的收发

## 概述

asio库是基于前摄器（Proactor）模式（设计模式的一种）封装了操作系统的select、poll、epoll、kqueue等机制。

实现了异步IO模型。

核心类是`io_service`，相当于前摄器模式中的Proactor，asio的任何操作都需要有io_service的参与（是参与，而不是一定要在代码里写它）

## 同步模式与异步模式

### 同步模式

在同步模式下，程序发起一个IO操作，向io_service提交请求，io_service把操作转交给操作系统然后同步等待（就是没有返回就一直等）。

当IO操作完成后，操作系统通知io_service，然后io_service再把结果发回给程序，完成整个同步流程。

==这个处理流程和多线程的thread.join()很像==

### 异步模式

在异步模式下，程序除了要发起的IO操作外，还要定义一个用于回调的完成处理函数(complete handle)。
io_service同样把IO操作转交给操作系统执行，但它不同步等待，而是立即返回。

调用io_service的run()成员函数可以等待异步操作完成，当异步操作完成时io_service 从操作系统获取结果，再调用handler执行后续的逻辑。

## handler

handler是asio的重要概念，它是3符合某种函数签名的回调函数。

handler必须是可拷贝的。
io_service会存储handler的拷贝，当某种异步事件发生时io_service就会调用时间对应的 handler

但要小心，由于operator()是异步发生的，时机不确定，必须保证它们引用的外部变量可用，否则就会发生未定义行为。

asio库里的handler主要有以下三种：

1. 只有一个error_code参数，标志某个异步事件完成了，是最基本的handler
2. error_code和signal_number两个参数，标志发生一个UNIX信号事件
3. error_code 和signal_number两个参数，标志某个读写操作完成了，可读写的数据字节数是bytes_transferred，通常用于socket回调

```cpp
void handler(
    const error_code & ec   // 操作的错误码
);


void handler(
    const error_code & ec, // 操作的错误码
    int signal_number   // 引发操作的信号值
);

void handler(const error_code & ec, std::size_t bytes_transferred);
```

## 参考链接

[C++ boost::asio编程-同步TCP详解及实例代码](https://blog.csdn.net/flyingleo1981/article/details/8901074)

## 参考书籍

《Boost程序库完全开发指南-深入Cpp标准库-第四版》
