# Ubuntu18.04安装gRPC

这里主要是跟着[官方教程][官方教程]来的

[官方教程]:https://grpc.io/docs/languages/cpp/quickstart/

但是官方教程有点问题。

## 安装依赖

```
sudo apt install -y build-essential autoconf libtool pkg-config
```

## 下载并安装grpc

**首先确保Cmake版本高于3.13**
Ubuntu18.04默认的cmake是3.10，需要卸载并安装更高版本的Cmake。

1、下载grpc
```
git clone --recurse-submodules -b v1.37.1 https://github.com/grpc/grpc
```

如果遇到网络问题，则试试

```
git clone git clone -branch v1.37.1 https://github.com/grpc/grpc
cd grpc
git submodule update --init
```

这里要注意版本问题。

2、编译安装grpc

a.
```
mkdir -p cmake/build && cmake/build
```

b.
```
cmake -DCMAKE_BUILD_TYPE=Release -DgRPC_INSTALL=ON -DBUILD_SHARED_LIBS=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_ZLIB_PROVIDER=package -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_SSL_PROVIDER=package ../..
```

c.
```
make -j$(nproc)
```

d.
```
sudo make install
```

就安装完成了。
