#include <iostream>
#include <thread>

void hello()
{
    std::cout<<"Hello Concurrent World\n";
}

int main()
{
    // 启动一个线程，并绑定函数hello
    std::thread t(hello);
    // 线程执行结束返回
    t.join();
}
