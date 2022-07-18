# QFile类

这个类是Qt用来对文件或者文件夹进行操作的



## 创建文件



## 创建文件夹

## 删除文件

## 移动文件

## 构造、析构函数及public函数列表

```cpp
QFile(const QString &name, QObject *parent)
QFile(QObject *parent)
QFile(const QString &name)
QFile()
virtual	~QFile()
```

```cpp
copy(const QString &newName)
bool	exists() const
bool	link(const QString &linkName)
bool	moveToTrash()
bool	open(FILE *fh, QIODevice::OpenMode mode, QFileDevice::FileHandleFlags handleFlags = DontCloseHandle)
bool	open(int fd, QIODevice::OpenMode mode, QFileDevice::FileHandleFlags handleFlags = DontCloseHandle)
bool	remove()
bool	rename(const QString &newName)
void	setFileName(const QString &name)
QString	symLinkTarget() const
```

## 参考链接

[Qt5官方文档](https://doc.qt.io/qt-5/qfile.html)
[Qt6官方文档](https://doc.qt.io/qt-6/qfile.html)
