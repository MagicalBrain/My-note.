/*
* test 2022-07-15
* 测试string与char*互相转换
*/
#include <iostream>
#include <string>

int main() {
	char cstr[10] = {0};
    std::string sstr;
    try {
        std::cin >> sstr;
        cstr = sstr.c_str();
    }
    catch (const std::exception& err) {
        std::cout << err.what() << std::endl;
    }
	return 0;
}
