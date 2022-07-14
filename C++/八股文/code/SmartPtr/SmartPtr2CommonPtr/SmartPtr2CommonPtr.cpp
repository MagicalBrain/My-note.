// SmartPtr2CommonPtr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>

/// @brief shared_ptr 转成 普通指针
void shared_ptr2cptr() {
    std::cout << "start transfer smartptr to common ptr!\n";

    std::shared_ptr<std::string> str_ptr1 = std::make_shared<std::string>("this is a string.");
    std::string* str_cptr1 = str_ptr1.get();

    std::vector<std::string*> str_cptrs;

    str_cptrs.push_back(str_cptr1);
    //str_cptrs.push_back(str_ptr1);

    try
    {
        std::cout << str_cptrs.size() << std::endl;
        std::cout << str_cptrs[0]->c_str() << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout << err.what() << std::endl;
    }
}

/// @brief 普通指针转换成shared_ptr
void cptr2shared_ptr() {
    try
    {
        std::shared_ptr<std::string> str_sptr;

        std::string* str_ptr = new std::string("a string");

        str_sptr.reset(str_ptr);

        std::cout << *str_sptr << std::endl;

        // 注意要和new成对使用
        delete str_ptr;
    }
    catch (const std::exception& err)
    {
        std::cout << err.what() << std::endl;
    }
    
}

int main()
{
    std::cout << "start transfer program!\n";
    
    //shared_ptr2cptr();
    cptr2shared_ptr();

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
