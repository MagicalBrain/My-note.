# boost库的安装

## windows10

## Ubuntu

以Ubuntu 18.04 为例

下载好```tar.gz```文件或者```tar.bz```文件

解压到一个目录

cd到目录里，```./bootstrap.sh```安装

然后```./b2```安装
（**注意**：这里版本不同的话，运行安装的脚本可能不同）

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
