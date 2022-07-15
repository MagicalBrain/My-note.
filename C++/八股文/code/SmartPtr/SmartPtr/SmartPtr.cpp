// SmartPtr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <memory>

void test_auto_ptr() {
    std::auto_ptr<std::string> p1(new std::string("hello"));
    std::auto_ptr<std::string> p2;

    // 执行结束这条语句后p1对象的所有权就交到了p2的手上
    p2 = p1;

    // 访问p2没有问题
    std::cout << p2->c_str() << std::endl;
    // 访问p1会触发中断，因为此时p1已没有对象的所有权了
    std::cout << p1->c_str() << std::endl;
}

void test_unique_ptr() {
    std::unique_ptr<std::string> p1(new std::string("hello"));
    std::unique_ptr<std::string> p2;

    // 这句就编译器就直接报错了，编译不通过，无法运行
    //p2 = p1;

    /*std::cout << p2->c_str() << std::endl;
    std::cout << p1->c_str() << std::endl;*/
}

int main()
{
    std::cout << "Hello World!\n";

    //test_auto_ptr();
    test_unique_ptr();
    
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
