# QDir

这个类是Qt专门用来进行文件处理的

## 检查文件路径是否存在

其实就是检查对应的文件夹是否存在

## 新建文件夹

```cpp
// 判断文件夹是否存在，不存在则创建
QString cloud_qpath = QString::fromStdString(cloud_path);
QDir dir_workspace(cloud_qpath);
if (!dir_workspace.exists()) {
    bool ismkdir = dir_workspace.mkdir(cloud_qpath);
    if (!ismkdir)
        //qDebug() << "Create path fail" << endl;
        HY_LOG_E("Create cloud path fail");
    else
        //qDebug() << "Create cloud_qpath success" << endl;
        HY_LOG_I("Create cloud path sucess");
}
else {
    //qDebug() << "cloud_qpath exist" << endl;
    HY_LOG_I("Create cloud_qpath exist");
}
```

## 读取文件的大小

## 计算文件夹里所有文件的大小

```cpp
qint64 fileSize(const QString &path)
{
     QDir dir(path);
     qint64 size = 0;

     foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files)) {
         size += fileInfo.size();
     }

     foreach(QString subDir, dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot)) {
         size += fileSize(path + QDir::separator() + subDir);
     }

     return size;
}

```

## 参考链接

[Qt5官方文档](https://doc.qt.io/qt-5/qdir.html)
[Qt6官方文档](https://doc.qt.io/qt-6/qdir.html)
