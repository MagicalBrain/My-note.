#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello Concurrent World!" << std::endl;
}

/*
* Linux 下运行命令：
* g++ *.cpp -o *.o -lpthread
*/
int main() {
    std::thread t(hello);
    t.join();
    return 0;
}
