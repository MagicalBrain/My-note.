/*
* 使用 std::future 来获取异步任务的函数返回值
*/
#include <future>
#include <iostream>

// 一个异步任务
int find_the_answer_to_ltuae()
{
    return 42;
}

// 做其它事情的代码
void do_other_stuff()
{}

int main()
{
    // 利用async将future和任务函数绑定起来
    std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
    
    do_other_stuff();
    
    // 通过 std::future::get() 即可获取异步任务的函数返回值
    // std::future::get() 会阻塞当前线程等待 future 的返回值
    std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}
