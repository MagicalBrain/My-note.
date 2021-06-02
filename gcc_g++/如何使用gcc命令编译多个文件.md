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

则不需要再gcc命令中指明路径，但是要在```#include "[filename]"```里写清楚文件的相对路径。

## include第三方库

开发经常会用到一些第三方库，就必须要搞明白怎么用这些第三方库。

使用```pkg-config```命令

以OpenCV为例：

```
g++ `pkg-config opencv4 --cflags` HYDeviceDemo.cpp -o hydevicedemo.o `pkg-config opencv4 --libs`
```

----

例如：

```
g++ `pkg-config opencv4 --cflags` HYDeviceDemo.cpp -o hydevicedemo.o `pkg-config opencv4 --libs` -I ../include
```

使用`-l`或者`-L`指令

`-l`指令是从系统的环境路径指定一个库来链接。
`-lname`即链接一个名为`name`的库

在`-l`指令和参数前加`-L`是指明库的路径为当前目录

例如：
```
g++ ... -lname
```
是直接从`/usr/local/lib`目录里找`name`库文件

```
g++ ... -L -lname
```
是直接从当前目录里找`name`库文件

**如果项目所包含的文件太多，还是推荐使用Cmake**

## 使用gcc/g++编译动态库和静态库

### 生成静态库：.a

```
gcc -c try1.c
 
gcc -c try2.c
 
ar cqs libtry.a try1.o try2.o
# 或
ar r libtry.a try1.o try2.o
```

先使用```gcc -c```编译```try1.c, try2.c```成```try1.o, try2.o```文件。
再使用```ar```命令把```try1.o, try2.o```生成```libtry.a```静态库

### 生成动态库：.so

```
gcc -shared -o libtry.so try.c
```

把```try.c```生成```libtry.so```动态库

如果将多个```.c```或者```.cpp```文件生成```.so```文件失败，可能是需要再gcc命令的最后加上```-fPTC```参数。

### 检查库里是否含有对应的符号及其实现

先cd到库的目录下

```
nm -D 库名  | grep 函数名
```
