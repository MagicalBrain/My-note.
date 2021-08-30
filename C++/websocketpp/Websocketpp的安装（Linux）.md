# Websocketpp的安装（Linux）

以Ubuntu 18.04 为例

由于这个库只有头文件，所以编译安装比较简单

```bash
mkdir -p cmake/build && cd build
cmake ../..
make -j$(nproc)
sudo make install
```
