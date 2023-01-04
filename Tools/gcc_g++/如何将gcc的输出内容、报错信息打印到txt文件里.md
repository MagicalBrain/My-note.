# 如何将gcc的输出内容、报错信息打印到txt文件里

再```gcc```命令后加上```&> filename.txt```即可。

例如：
```
g++ `pkg-config opencv4 --cflags` -c $GRPC.cpp -o $GRPC.o -I ../include &> Error.txt
```
