# C++ char指针与string如何相互转换

## string转char*

### c_str()

```cpp
    string str = "hello, world!";
    char p1[1024] = "hello";
    p1 = str.c_str();
    /*
    一定要使用strcpy()函数 等来操作方法c_str()返回的指针
    p1最后指向的内容是垃圾,因为str对象被析构,其内容被处理
    */
```

正确用法：

```cpp
string str = "hello, world!";
char p1[1024] = "hello";
//p1 = str.c_str();
strcpy(p1, str.c_str());
```

### data()

与`c_str()`同理

```cpp
strcpy(p2, str.data());
```

## char*转string

### 直接赋值

```cpp
char s1[1014] = "hello";
char *p1 = s1;
std::string str = p1;
```

这里没有问题，其实是因为char数组这样赋值给指针没有问题。

**注意**：
这里的直接赋值值得是同一个作用域下，或者char*指向的作用域包含了string的作用域，否则可能会乱码

例如常见错误中的`getString1()`和`getString2()`

### assign()

```cpp
char c1[1024] = "getString2";
string re;
re.assign(c1, strlen(c1));
```

## 常见错误

1、

```cpp
#include <iostream>
#include <cstring>

using namespace std;

char* getString1() {
    char str[1024] = "getString1";
    //char *p = str;
    return str;
}

int main() {
    char s1[1014] = "hello";
    char *p1 = s1;
    
    char *p2 = getString1();

    cout << "s1 is: " << s1 
        << "strlen of s1 is: " << strlen(s1) << endl;


    cout << "p1 is: " << p1 
        << "strlen of p1 is: " << strlen (p1) << endl;

    cout << "p2 is: " << p2
        << "strlen of p2 is: " << strlen (p2) << endl;
    return 0;
}
```

输出：
```bash
s1 is: hellostrlen of s1 is: 5
p1 is: hellostrlen of p1 is: 5
[1]    351 segmentation fault (core dumped)  ./string2char.o
```

2、
```cpp
char* EliteRobotPlugin::mutexSendAndRecv(const std::string& send_msg)
{
    std::lock_guard<std::mutex> guard(m_);
    client_->write(send_msg.c_str(), send_msg.length());
    HY_LOG_D("send messagess {}", send_msg);
    char buffer[1024] = { 0 };
    client_->read(buffer, 1024);
    HY_LOG_D("recvice messagess {}", buffer);
    return buffer;
}

/* ----- 调用代码如下 ----- */
std::string send_msg = "";
send_msg = j.dump();
send_msg += "\n";
// 这里程序就会崩溃
std::string buffer = mutexSendAndRecv(send_msg);
```

```cpp
std::string EliteRobotPlugin::mutexSendAndRecv(const std::string& send_msg)
{
    std::lock_guard<std::mutex> guard(m_);
    client_->write(send_msg.c_str(), send_msg.length());
    HY_LOG_D("send messagess {}", send_msg);
    char buffer[1024] = { 0 };
    client_->read(buffer, 1024);
    HY_LOG_D("recvice messagess {}", buffer);

    std::string re;
    re.assign(buffer, strlen(buffer));
    return re;
}
```
