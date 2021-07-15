# boost的timer类的基本用法

timer接口简单，轻巧好用，适用于要求不高的程序计时任务。
但它不适合高精度的时间测量任务，精度依赖于操作系统和编译器，不同平台精度不一样。
也不适合用于天、月、年为单位的时间测量，那应该使用`cpu_timer`组件。

timer位于命名空间boost，需要包含头文件`<boost/timer.hpp>`

```cpp
#include <boost/timer.hpp>
using namespace boost;
```

## 用法

```cpp
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
```

输出结果：
```bash
max timespan:5.1241e+09h
min timespan:1e-06s
now time elapsed:0.000119s
```
