# gRPC的安装(Linux)

这里主要是跟着[官方教程][官方教程]来的，基于Ubuntu18.04

[官方教程]:https://grpc.io/docs/languages/cpp/quickstart/

但是官方教程有点问题。

## 安装依赖

```bash
sudo apt install -y build-essential autoconf libtool pkg-config
```

## 下载并安装grpc

**首先确保Cmake版本高于3.13**
Ubuntu18.04默认的cmake是3.10，需要卸载并安装更高版本的Cmake。

1、下载grpc
```bash
git clone --recurse-submodules -b v1.37.1 https://github.com/grpc/grpc
```

如果遇到网络问题，则试试

```bash
git clone -branch v1.37.1 https://github.com/grpc/grpc
cd grpc
git submodule update --init
```

这里要注意版本问题。
如果是要下载1.38.0，则是：
```bash
git clone -b v1.38.0 https://github.com/grpc/grpc
```

很有可能会遇到网络问题，多试几次就好。

2、编译安装grpc

a.
```bash
mkdir -p cmake/build && cd cmake/build
```

b.
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DgRPC_INSTALL=ON -DBUILD_SHARED_LIBS=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_ZLIB_PROVIDER=package -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_SSL_PROVIDER=package ../..
```

c.
```bash
make -j$(nproc)
```

d.
```bash
sudo make install
```

就安装完成了。

### 如果这里的cmake出问题

protobuf库找不到，那就去安装protobuf库

```bash
cd /grpc/third_party/protobuf
mkdir-p cmake/build
cd cmake/build
cmake -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..
make -j
sudo make install
```


## 安装完gRPC，别忘了安装abseil

```bash
mkdir -p third_party/abseil-cpp/cmake/build
pushd third_party/abseil-cpp/cmake/build
cmake -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \  -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE \  ../..
make -j
make install
popd
```

## 如果protoc的安装有问题

[参考链接1][参考链接1]

[参考链接1]:https://blog.csdn.net/chenwr2018/article/details/105109987?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162209950016780265478710%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162209950016780265478710&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-24-105109987.first_rank_v2_pc_rank_v29&utm_term=%E5%8D%B8%E8%BD%BDgRPC&spm=1018.2226.3001.4187

[参考链接2][参考链接2]

[参考链接2]:https://www.cnblogs.com/youxin/p/4073703.html

希望有用，如果不行，可能得卸载了重新安装，问题是卸载不知道怎么卸载才干净。

## libprotoc.so.26找不到

/usr/local/bin/protoc: error while loading shared libraries: libprotoc.so.26: cannot open shared object file: No such file or directory

## openssl找不到

```bash
CMake Error at /usr/local/share/cmake-3.14/Modules/FindPackageHandleStandardArgs.cmake:137 (message):
  Could NOT find OpenSSL, try to set the path to OpenSSL root folder in the
  system variable OPENSSL_ROOT_DIR (missing: OPENSSL_CRYPTO_LIBRARY
  OPENSSL_INCLUDE_DIR)
```

可能是没有安装openssl的开发库：
```bash
sudo apt install libssl-dev
```

如果还有其它问题，考虑重新装新版本的openssl吧。

https://blog.csdn.net/wanxuexiang/article/details/89647737

看样子还是得重新装openssl啊

https://blog.csdn.net/u012670181/article/details/104102110

可能会出现的错误：
ubuntu 18.04 openssl: relocation error: openssl: symbol EVP_mdc2 version OPENSSL_1_1_0 not defined i

解决方案：

https://blog.csdn.net/lc11535/article/details/111769295

https://www.5axxw.com/questions/content/b78m2c

使用export命令修改`LD_LIBRARY_PATH`

```
export LD_LIBRARY_PATH=/usr/local/ssl/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
```

`/usr/local/ssl/lib`即`openssl`安装的动态库路径

最后

https://blog.csdn.net/wanxuexiang/article/details/89647737

直接手动指明openssl的安装路径：
```
cmake -DOPENSSL_ROOT_DIR=/usr/local/ssl -DOPENSSL_LIBRARIES=/usr/local/ssl/lib ../..
```

## 跑一下官方的demo验证安装

首先cd到demo所在的目录：
```bash
cd examples/cpp/helloworld
```

创建`build`文件夹
```bash
mkdir -p cmake/build
```

在`build`文件夹里运行：
```bash
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../..
make -j$(nproc)
```

运行服务端程序：
```bash
./greeter_server
```

在另外一个终端里cd到当前目录运行客户端程序
```bash
./greeter_client
```

输出结果：
```bash
Greeter received: Hello world
```

### 在cmake编译example时遇到的问题

#### openssl库找不到

参照上面的openssl解决办法

#### protobuf库找不到

cmake报错信息：
```bash
CMake Error at CMakeLists.txt:5 (find_package):
  Could not find a package configuration file provided by "Protobuf" with any
  of the following names:

    ProtobufConfig.cmake
    protobuf-config.cmake

  Add the installation prefix of "Protobuf" to CMAKE_PREFIX_PATH or set
  "Protobuf_DIR" to a directory containing one of the above files.  If
  "Protobuf" provides a separate development package or SDK, be sure it has
  been installed.
```

如果之前安装过，那就时安装的方式不对，现在新版本只能用cmake来安装，之前可能是用脚本或者什么可执行文件安装的，都不行。

#### abseil.....某个头文件找不到

直接将`/grpc/third_party/abseil-cpp/`下的`absl`文件夹复制到`/usr/local/include`路径下
