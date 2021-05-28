# 如何使用gcc命令编译多个文件

## 使用include

如果要编译多个文件，include路径在哪是一个重要问题。

假设在```HYDeviceDemo.cpp```中：
```cpp
#include <include/head.h>
```

则可使用```-I```命令：

```
g++  HYDeviceDemo.cpp -o hydevicedemo.o  -I ../include
```

还可以设置```include```搜索的路径；
[参考链接][参考链接]

[参考链接]:https://blog.csdn.net/quicmous/article/details/106790319

如果是：
```cpp
#include "include/head.h"
```

则是：

## include第三方库

开发经常会用到一些第三方库，就必须要搞明白怎么用这些第三方库。

使用```pkg-config```命令

以OpenCV为例：

```
g++ `pkg-config opencv4 --cflags` HYDeviceDemo.cpp -o hydevicedemo.o `pkg-config opencv4 --libs`
```

----

```
g++ `pkg-config opencv4 --cflags` HYDeviceDemo.cpp -o hydevicedemo.o `pkg-config opencv4 --libs` -I ../include
```

**如果项目所包含的文件太多，还是推荐使用Cmake**
