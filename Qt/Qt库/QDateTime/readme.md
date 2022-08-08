# QDateTime

这里介绍QDateTime的用法

## 初始化

```cpp
// 先按格式初始化一个字符串
string date_str1 = "2022-08-01-10:10:10";
// 然后这个格式给QDateTime对象赋值
QDateTime time1 = QDateTime::fromString(QString::fromStdString(date_str1), "yyyy-MM-dd-hh:mm:ss");
qDebug() << time1;
```

输出结果：

```cmd
QDateTime(2022-08-01 10:10:10.000 中国标准时间 Qt::LocalTime)
```

## 获取当前时间

```cpp
QDateTime current_date_time = QDateTime::currentDateTime();
```

输出结果：

```cmd
QDateTime(2022-08-08 09:49:13.419 中国标准时间 Qt::LocalTime)
```

## 格式化输出

```cpp
string date_str1 = "2022-08-01-10:10:10";
QDateTime time1 = QDateTime::fromString(QString::fromStdString(date_str1), "yyyy-MM-dd-hh:mm:ss");

qDebug() << time1.toString("yyyy-MM-dd-hh:mm:ss");
```

## 比较两个QDateTime

一般思路是将QDateTime转成无符号整型(uint)来处理

```cpp
string date_str1 = "2022-08-01-10:10:10";
string date_str2 = "2022-08-02-10:10:10";

QDateTime time1 = QDateTime::fromString(QString::fromStdString(date_str1), "yyyy-MM-dd-hh:mm:ss");
QDateTime time2 = QDateTime::fromString(QString::fromStdString(date_str2), "yyyy-MM-dd-hh:mm:ss");

re1 = time1.toTime_t();
re2 = time2.toTime_t();

if (re1 < re2) {
    // todo
}
```

## 计算两个QDateTime相差的时间

同上，也是将QDateTime转成无符号整型(uint)来处理

首先我们先要知道相差24小时整的QDateTime的差值为：86400
即一天24小时的秒数：$24 \times 60 \times 60 = 86400$

```cpp
string date_str1 = "2022-08-01-10:10:10";
string date_str2 = "2022-08-02-10:10:10";

QDateTime time1 = QDateTime::fromString(QString::fromStdString(date_str1), "yyyy-MM-dd-hh:mm:ss");
QDateTime time2 = QDateTime::fromString(QString::fromStdString(date_str2), "yyyy-MM-dd-hh:mm:ss");

qDebug() << "time2 - time1 is: " << time2.toTime_t() - time1.toTime_t();
```

输出结果为：

```cmd
time2 - time1 is:  86400
```

如果要判断两个QDateTime相差的时间，其实就是相减得出秒数再换算成相应的单位即可。
