/*
* 这是一个使用了Lambda表达式的例子
*/
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello Concurrent World!" << std::endl;
}

/*
* Linux 下运行命令：
* g++ *.cpp -o *.o -lpthread -std=c++11
*/
int main() {
    std::thread t ([=](){
        std::cout << "Hello Concurrent World!" << std::endl;
    });
    t.join();
    return 0;
}
