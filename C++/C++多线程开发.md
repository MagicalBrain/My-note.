# C++ 多线程开发

## 应用程序、进程、线程

**进程与应用程序**
一个进程就是正在运行的一个应用程序或者说可执行程序。

**进程与线程**
计算机系统里，资源分配是以进程为单位的；而处理机的分配则是以线程为单位的。

但是各个操作系统的具体情况不同。

在Linux里，进程与线程实际上没有区别，线程不过是所谓的轻量级进程。
进程不仅是资源分配的单位，而且也是可执行的，是处理机调度的单位。

在Windows里，进程只负责资源分配，它实际上不进行任何操作，所有的操作都由其内部的线程来完成。

可见只有Linux才是真正意义上的多进程多任务的操作系统。

## 进程

@import "./C++如何创建进程.md"
