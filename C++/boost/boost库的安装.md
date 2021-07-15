# boost库的安装

## windows10

直接下载`.exe`可执行文件后，点击安装即可。

## Linux

以Ubuntu 18.04 为例

下载好```tar.gz```文件或者```tar.bz```文件，并将文件移到`/usr/local`目录下。

解压到一个目录

cd到目录里，```./bootstrap.sh```编译生成

然后```./b2```编译生成动态库
（**注意**：这里版本不同的话，运行安装的脚本可能不同）

然后```./b2 header```编译生成头文件

最后`./b2 install`安装（注意，得用sudo权限！）

### 验证安装

```cpp
#include<iostream>
#include<boost/lexical_cast.hpp>
//using namespace std;

//using namespace boost;
int main()
{
   int a = boost::lexical_cast<int>("123456");
   std::cout << a <<std::endl;
   return 0;
}
```
运行命令
```
g++ src.cpp -o src
./src
```
输出结果：
```
123456
```

## macOS

与Linux类似。
