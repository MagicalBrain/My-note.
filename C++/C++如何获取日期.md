# C++如何获取日期

## time.h

使用跨平台的通用代码：
使用`currentDateTime()`函数，代码如下：

@import "./code/getDate.cpp"

## ctime.h

```cpp
//日期
CTime time = CTime::GetCurrentTime();
string date;

CString curdate = time.Format("%Y-%m-%d");
date = (CStringA)curdate;
QVariant Qdate(QString::QString::fromStdString(date));
HY_LOG_I("Date Data add finish");
```        

如果报错，以下办法可能可以解决：

1、
![](asset/CTimeError.png)

将上面的字符集设为==多字节字符集==即可

2、
还有一个更好的办法可以让上面这段代码兼容性更强，就是改成：

```cpp
CString curdate = time.Format(_T("%Y-%m-%d"));
```

`_T("a string")`其实就是一个宏，用来控制字符串编码的，让该字符串支持Unicode编码

[相关知识参考](https://www.cnblogs.com/devcjq/articles/2430693.html)
