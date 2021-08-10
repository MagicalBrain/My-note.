# Websocketpp的安装

## Windows10

由于这个库只有头文件，所以编译安装比较简单。

下载zip后，解压到路径`filename`，然后将这个路径在vs的属性表里`C++`->`常规`->`附加包含目录`

添加websocketpp所在的目录路径即可。

## Ubuntu

以Ubuntu 18.04 为例

由于这个库只有头文件，所以编译安装比较简单

```
mkdir -p cmake/build && cd build
cmake ../..
make -j$(nproc)
sudo make install
```
