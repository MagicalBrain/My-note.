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
git clone -branch v1.37.1 https://github.com/grpc/grpc
cd grpc
git submodule update --init
```

这里要注意版本问题。
如果是要下载1.38.0，则是：
```
git clone -b v1.38.0 https://github.com/grpc/grpc
```

很有可能会遇到网络问题，多试几次就好。

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

## 如果protoc的安装有问题

[参考链接1][参考链接1]

[参考链接1]:https://blog.csdn.net/chenwr2018/article/details/105109987?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162209950016780265478710%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162209950016780265478710&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-24-105109987.first_rank_v2_pc_rank_v29&utm_term=%E5%8D%B8%E8%BD%BDgRPC&spm=1018.2226.3001.4187

[参考链接2][参考链接2]

[参考链接2]:https://www.cnblogs.com/youxin/p/4073703.html

希望有用，如果不行，可能得卸载了重新安装，问题是卸载不知道怎么卸载才干净。

## 跑一下官方的demo验证安装
