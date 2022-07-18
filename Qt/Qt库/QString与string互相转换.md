# QString与string互相转换

QString与std::string互相转换

## std::string转QString

```cpp
std::string str = "";
QString qstr = QString::fromStdString(str);
```

## QString转std::string

```cpp
QString qstr = "";
std::string str = qstr.toStdString();
```
