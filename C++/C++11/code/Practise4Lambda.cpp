#include <iostream>

int main() {
    int a, b;
    //练习10.14
    auto f1 = [](const int a, const int b){return a + b;};
    std::cout << "练习 10.14" << std::endl 
        << "请输入两个整数：" << std::endl;
    std::cin >> a >> b;
    std::cout << f1(a, b) << std::endl;
    //练习10.15
    int num1, num2;
    std::cout << "练习 10.15" << std::endl 
        << "请输入两个整数：" << std::endl;
    std::cin >> num1 >> num2;
    auto f2 = [num1](const int b){return num1 + b;};
    std::cout << f2(num2) << std::endl;
    return 0;
}