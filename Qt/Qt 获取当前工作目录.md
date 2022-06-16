# Qt 获取当前工作目录

## 获取可执行文件所在的路径

```cpp
// 获取 可执行文件的路径
QString applicationDirPath;
applicationDirPath = QCoreApplication::applicationDirPath();
HY_LOG_I("the path of exe is {}", applicationDirPath.toStdString());
```

## 获取当前工作路径

```cpp
// 获取 当前工作路径
QString currentPath;
QDir dir;
currentPath = dir.currentPath();
HY_LOG_I("the path of HYDetect's Workspace is {}", currentPath.toStdString());
```
