# Doxygen的安装

[官网地址][官网地址]

## win10

安装前还需安装[graphviz][graphviz下载地址]。

[win10版本下载地址][win10下载地址]

跟着提示走next就行了。

win10上面的用GUI界面设置就行
https://blog.csdn.net/qq_28223455/article/details/88422335

## Linux

### 直接下载安装

```bash
sudo apt-get install graphviz
sudo apt-get install doxygen
```

### 编译安装所需要的依赖

If you downloaded the source distribution, you need at least the following to build the executable:

The GNU tools flex, bison, libiconv and GNU make
You need python (version 2.7 or higher, see https://www.python.org).
In order to generate a Makefile for your platform, you need cmake version 3.3 or later.

如果你需要下载源文件来编译，至少需要以下依赖：
1. GNU工具flex、bison、libiconv、make
2. 还需要python版本2.7或更高
3. 为了在自己的平台上生成Makefile，还需要cmake 3.3或更高版本



To take full advantage of doxygen's features the following additional tools should be installed.

Qt Software's GUI toolkit Qt version 4.3 or higher (including Qt 5). This is needed to build the GUI front-end doxywizard.

A $\LaTeX$ distribution: for instance TeX Live This is needed for generating $\LaTeX$, Postscript, and PDF output.

the Graph visualization toolkit version 2.38 or higher Needed for the include dependency graphs, the graphical inheritance graphs, and the collaboration graphs. If you compile graphviz yourself, make sure you do include freetype support (which requires the freetype library and header files), otherwise the graphs will not render proper text labels.

For formulas in the HTML output (when MathJax is not used) or in case you do not wish to use pdflatex, the ghostscript interpreter is needed. You can find it at www.ghostscript.com.

为了使用doxygen完整的功能，还需要下载以下工具；
1. Qt 4.3 或更高，这是生成GUI帮助文档所需要的
2. LaTex，这是生成pdf所需要的
3. the Graph visualization toolkit version 2.38 or higher (graphviz),这是在文档中添加、引用图片所需要的
4. ghostscript，为了输出HTML中的公式（MathJax不会被使用），或者不想用pdflatex编译latex文件的话，就需要用这个

[ghost官网][ghost]

**注意**：
如果你想自己编译安装graphviz，请确保添加了`freetype`的支持：`freetype`的库文件和头文件，否则图像将不会在文中渲染出合适的标签。

#### libiconv的安装

make是ubuntu自带的，flex、bison安装比较简单，直接apt-get install即可，主要是libiconv的安装比较麻烦

下载`tar.gz`包
```bash
wget http://ftp.gnu.org/pub/gnu/libiconv/libiconv-1.14.tar.gz
tar -zxvf libiconv-1.14.tar.gz && cd libiconv-1.14
./configure --prefix=/usr/local
make -j$(nproc)
sudo make install
```

在`make -j`这一步可能会遇到错误：
```bash
In file included from progname.c:26:0:
./stdio.h:1010:1: error: ‘gets’ undeclared here (not in a function); did you mean ‘fgets’?
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 ^
Makefile:914: recipe for target 'progname.o' failed
make[2]: *** [progname.o] Error 1
```

解决方法：
```bash
vim srclib/stdio.h
```

找到
```bash
 /* It is very rare that the developer ever has full control of stdin,
  so any use of gets warrants an unconditional warning.  Assume it is
  always declared, since it is required by C89.  */
  _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
```

即将
```bash
_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
```

改成
```bash
#if defined(__GLIBC__) && !defined(__UCLIBC__) && !__GLIBC_PREREQ(2, 16)
    _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
#endif
```

接下来就是设置软连接：
```bash
ln -s /usr/local/lib/libiconv.so /usr/lib
ln -s /usr/local/lib/libiconv.so.2 /usr/lib/libiconv.so.2
ldconfig
```

**验证安装**

test:
```cpp
#include <iconv.h>
    int main() {
    iconv(iconv_t(-1), 0, 0, 0, 0);
    return 0;
}
```

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>


#ifndef ICONV_CONST
# define ICONV_CONST const
#endif


/*!
 对字符串进行语言编码转换
 param from  原始编码，比如"GB2312",的按照iconv支持的写
 param to      转换的目的编码
 param save  转换后的数据保存到这个指针里，需要在外部分配内存
 param savelen 存储转换后数据的内存大小
 param src      原始需要转换的字符串
 param srclen    原始字符串长度
 */
int convert(const char *from, const char *to, char* save, int savelen, char *src, int srclen)
{
    iconv_t cd;
    char   *inbuf = src;
    char *outbuf = save;
    size_t outbufsize = savelen;
    int status = 0;
    size_t  savesize = 0;
    size_t inbufsize = srclen;
    const char* inptr = inbuf;
    size_t      insize = inbufsize;
    char* outptr = outbuf;
    size_t outsize = outbufsize;
    
    cd = iconv_open(to, from);
    iconv(cd,NULL,NULL,NULL,NULL);
    if (inbufsize == 0) {
        status = -1;
        goto done;
    }
    while (insize > 0) {
        size_t res = iconv(cd,(ICONV_CONST char**)&inptr,&insize,&outptr,&outsize);
        if (outptr != outbuf) {
            int saved_errno = errno;
            int outsize = outptr - outbuf;
            strncpy(save+savesize, outbuf, outsize);
            errno = saved_errno;
        }
        if (res == (size_t)(-1)) {
            if (errno == EILSEQ) {
                int one = 1;
                iconvctl(cd,ICONV_SET_DISCARD_ILSEQ,&one);
                status = -3;
            } else if (errno == EINVAL) {
                if (inbufsize == 0) {
                    status = -4;
                    goto done;
                } else {
                    break;
                }
            } else if (errno == E2BIG) {
                status = -5;
                goto done;
            } else {
                status = -6;
                goto done;
            }
        }
    }
    status = strlen(save);
done:
    iconv_close(cd);
    return status;
}

int main() {
    char *save = malloc(100 * sizeof(char));
    char *src = "Hello World!";
    convert("ASCII", "utf-8", save, 100, src, 13);
    puts(save);
    return 0;
}
```

### 开始安装

先下载`tar.gz`包
```bash
git clone https://github.com/doxygen/doxygen.git
cd doxygen
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
sudo make install
```

在使用cmake指令的时候，可能会报错：
```bash
CMake Error at /home/hrl/cmake-3.14.7-Linux-x86_64/share/cmake-3.14/Modules/FindPackageHandleStandardArgs.cmake:137 (message):
  Could NOT find Iconv (missing: ICONV_COMPILES)
Call Stack (most recent call first):
  /home/hrl/cmake-3.14.7-Linux-x86_64/share/cmake-3.14/Modules/FindPackageHandleStandardArgs.cmake:378 (_FPHSA_FAILURE_MESSAGE)
  cmake/FindIconv.cmake:87 (find_package_handle_standard_args)
  CMakeLists.txt:120 (find_package)
```

无它，其实就是前面的libiconv环境变量没有配好。

```
ICONV_INCLUDE_DIR iconv.h
ICONV_LIBRARY NAMES iconv64
```

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ..

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DICONV_INCLUDE_DIR=/usr/include ..

 cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DICONV_INCLUDE_DIR=/usr/local/include ..

  cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DICONV_INCLUDE_DIR=/usr/local/libiconv ..

cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/doxygen -DICONV_INCLUDE_DIR=/usr/local/libiconv/include ..

```cpp
#include <iconv.h>
int main() {
    iconv(iconv_t(-1), 0, 0, 0, 0);
    return 0;
}
```



[官网地址]:https://www.doxygen.nl/download.html
[ghost]:https://www.ghostscript.com/

[win10下载地址]:https://sourceforge.net/projects/doxygen/files/snapshots/

[graphviz下载地址]:http://www.graphviz.org/download/
