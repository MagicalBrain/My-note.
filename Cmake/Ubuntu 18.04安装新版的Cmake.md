# Ubuntu 18.04 安装新版的Cmake

因为Ubuntu 18.04自带的Cmake版本是Cmake 3.10，安装某些软件的时候会出问题，例如装```gRPC```库，要求是3.13及以上。

## 1、卸载旧版的Cmake

```
sudo apt remove cmake
```

## 2、下载新版的Cmake

先```cd```进要下载的文件加目录，命令行输入：

```
wget http://www.cmake.org/files/v3.16/cmake-3.16.6.tar.gz
```

下载好后解压：
```
tar zxvf cmake-3.19.0-rc1.tar.gz
```

## 3、安装

进入目录会看到只有 bin、  doc、  man、  share三个文件夹，没有 bootstrap文件，因为新版本的好像是已经编译好的，所以只要加入path里面就可以在命令行直接使用命令了

打开个人path配置
```
sudo vim ~/.bashrc
```

在末尾添加如下的内容

```
export PATH=/home/[usrname]/cmake-3.15.2-Linux-x86_64/bin:$PATH
```
注意这里的路径应该根据自己的电脑和Cmake版本的实际情况来设置。
即将刚才解压出来的路径里的bin文件夹的路径添加进PATH。

接着在终端source一下.bashrc文件让path立即生效
```
source ~/.bashrc
```
注意：
这里source完后，在别的终端窗口里是不会生效的，需要重启终端才可生效。

安装完毕测试版本
```
cmake --version
```
如果显示的是刚才安装的Cmake版本号，就说明安装成功了。

编写简单的cmake
使用cmake首先得有个CMakeList.txt文件，你需要把配置信息写在该文件中，然后通过cmake去处理该文件。
 将设有下面一个helloworld.cpp文件
 

//helloworld.cpp文件
#include<iostream>
using namespace std;
int main(){
    cout<<"hello world!"<<endl;
    return 0;
}
这时候我们就可以写个如下的CMakeList.txt文件

#cmake最小需要版本
cmake_minimum_required(VERSION 2.8)
 
#项目名字
project(HELLOWORLD)
 
#包含原程序,即把给定目录下的源程序复制给变量DIR_SRC
aux_source_directory(DIR_SRC ./)
 
#生成程序
add_executable(helloworld ${DIR_SRC})
然后执行如下命令

$mkdir build
$cd build
$cmake ..
$make
$./helloworld

这样就编译好程序并运行。

添加静态库或者动态库

而假设我们程序用到了在/usr/lib下的一个静态库libmy.a，那就需要添加如下两个命令
#库所在位置
link_directories(/usr/lib)

#程序编译时候链接库
target_link_libraries(helloworld my)
————————————————
版权声明：本文为CSDN博主「光子乘羽」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/hanshuning/article/details/100540218