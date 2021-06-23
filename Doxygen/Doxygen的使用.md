# Doxygen的使用

doxygen的使用方法通过doxygen -h可以获取。

## 创建配置文件doxyfile的方式

```bash
doxygen -s -g doxyfile  #简化版的doxyfile，没有很多注释信息。
# 或
doxygen -g doxyfile
```

输入命令：
```bash
doxygen -g doxyfile
```

输出如下：
```bash
Configuration file `Doxyfile' created.

Now edit the configuration file and enter

  doxygen Doxyfile

to generate the documentation for your project
```

You let doxygen generate the documentation, based on the settings in the configuration file:
想要让doxygen生成文档，使用如下命令即可：

```bash
doxygen <config_file>
```

如果想要将旧版本的doxygen配置文件升级到新版本，使用如下命令即可：
```bash
doxygen -u <config_file>
```

## Doxygen的设置

里面有很多选项和注释，我们一般只关心
1. 输出的路径
2. 输出的编码格式
3. 输出的语言
4. 源代码路径（可省，Doxygen会自动在当前目录下搜索）

## Doxyfile的设置

https://www.cnblogs.com/rongpmcu/p/7662765.html

选项的分类

Project related configuration options
Build related configuration options
Configuration options related to warning and progress messages
Configuration options related to the input files
Configuration options related to source browsing
Configuration options related to the alphabetical class index
Configuration options related to the HTML output
Configuration options related to the LaTeX output
Configuration options related to the RTF output
Configuration options related to the man page output
Configuration options related to the XML output
Configuration options related to the DOCBOOK output
Configuration options for the AutoGen Definitions output
Configuration options related to the Perl module output
Configuration options related to the preprocessor
Configuration options related to external references
Configuration options related to the dot tool

## 例子

```cpp
//!  A test class. 
/*!
  A more elaborate class description.
*/
 
class QTstyle_Test
{
  public:
 
    //! An enum.
    /*! More detailed enum description. */
    enum TEnum { 
                 TVal1, /*!< Enum value TVal1. */  
                 TVal2, /*!< Enum value TVal2. */  
                 TVal3  /*!< Enum value TVal3. */  
               } 
         //! Enum pointer.
         /*! Details. */
         *enumPtr, 
         //! Enum variable.
         /*! Details. */
         enumVar;  
    
    //! A constructor.
    /*!
      A more elaborate description of the constructor.
    */
    QTstyle_Test();
 
    //! A destructor.
    /*!
      A more elaborate description of the destructor.
    */
   ~QTstyle_Test();
    
    //! A normal member taking two arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param s a constant character pointer.
      \return The test results
      \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
    */
    int testMe(int a,const char *s);
       
    //! A pure virtual member.
    /*!
      \sa testMe()
      \param c1 the first argument.
      \param c2 the second argument.
    */
    virtual void testMeToo(char c1,char c2) = 0;
   
    //! A public variable.
    /*!
      Details.
    */
    int publicVar;
       
    //! A function variable.
    /*!
      Details.
    */
    int (*handler)(int a,int b);
};
```

上面是一个Qt风格的写法

## 函数注释

```cpp
/**
  @brief    从hidraw设备读取数据。
  @param    fd hidraw设备句柄。
  @param    r_buf 读取函数缓存指针。
  @param    len 读取大小。
  @return   0: 读取成功。\n
            -1: 读取失败。
 */
int usb_read(int fd,char *r_buf,int len)
{
    int    ret;
    char tmp_buf[520];
    if(r_buf == NULL) {  
        perror("usb_read::pointer error!");  
        return -1;  
    }

    ret = read(fd, tmp_buf, len+1);  
    if(ret < 0) {
        //printf("read data error  %d\n",ret);
        return -1;
    }
    memcpy(r_buf,&tmp_buf[1],len);
    return 0;
}
```

```cpp
/**
  @brief    根据输入的ip地址选择使用gRPC协议或者websocket协议来连接相机。
  @param    uri 输入的ip地址。
  @return   client: 连接成功，返回对应协议client类型的指针。\n
            nullptr: 连接失败，返回空指针。
 */
 ```

## 文件注释

```cpp
/**
 * @file    usb_hidraw_api.c
 * @author  xxx
 * @brief   操作hidraw设备接口open/close/read/write.
*/
```

## 类注释

