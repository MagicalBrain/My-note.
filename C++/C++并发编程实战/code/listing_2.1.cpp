#include <thread>

void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            // 潜在访问安全隐患：悬空引用
            do_something(i);
        }
    }
};


void oops()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);

    // 不等待线程结束，分离式运行线程
    my_thread.detach();
    // 函数结束时，线程可能还在运行
}

int main()
{
    oops();
}
