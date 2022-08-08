# QFile函数列表

## 构造及析构函数

```cpp
QFile(const QString &name, QObject *parent)
QFile(QObject *parent)
QFile(const QString &name)
QFile()
virtual	~QFile()
```

## public成员函数

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