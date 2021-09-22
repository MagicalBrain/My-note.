#include <iostream>

int main() {
    //系统宏
#ifdef __ANDROID__
	//string port("/dev/ttyUSB1");
    std::cout << "The Operation is Android." << std::endl;
#elif __linux__
	//string port("/dev/ttyUSB0");
    std::cout << "The Operation is Linux." << std::endl;
#elif _WIN32
	//string port("Com3");
    std::cout << "The Operation is Windows." << std::endl;
#endif
}