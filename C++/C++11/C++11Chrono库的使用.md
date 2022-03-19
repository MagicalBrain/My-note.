# C++11 chrono库的使用

源于boost，现已成为C++11的标准

## 如何计时

```cpp
#include <chrono>   
using namespace std;
using namespace chrono;

auto start = system_clock::now();
// do something...
auto end   = system_clock::now();
auto duration = duration_cast<microseconds>(end - start);
cout <<  "花费了" 
     << double(duration.count()) * microseconds::period::num / microseconds::period::den 
     << "秒" << endl;
```
