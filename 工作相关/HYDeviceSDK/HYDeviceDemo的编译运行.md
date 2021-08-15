# HYDeviceDemo的编译运行

这是HYDeviceSDK的演示代码

运行命令：

```
g++ `pkg-config opencv4 --cflags` HYDeviceDemo.cpp -o HYDeviceDemo.o `pkg-config opencv4 --libs` -I ../include -L  -lHYDeviceSDK
```

`pkg-config opencv4 --cflags`和`pkg-config opencv4 --libs`需成对使用，用来导入`opencv4`库。

```
asd
```
