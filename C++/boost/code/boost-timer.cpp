#include <iostream>

#include <boost/timer.hpp>  //timer的头文件

using namespace std;
using namespace boost;  //打开boost名字空间

int main() {
    timer t;    //声明一个计时器对象，开始计时
    cout << "max timespan:"     //可度量的最大时间，以小时为单位
         << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan:"     //可度量的最小时间，以秒为单位
         << t.elapsed_min() << "s" << endl;
    cout << "now time elapsed:"     //输出已经流逝的时间
         << t.elapsed() << "s" << endl;
    return 0;
}
