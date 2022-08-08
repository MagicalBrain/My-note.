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

## 删除整个文件夹

删除整个文件夹及其里面的所有内容

```cpp
// 文件夹的路径
QString del_file = QString("./data/2019-03-23");
QDir dir;
// 设置QDir对象的路径
dir.setPath(del_file);
// 开始删除
dir.removeRecursively();
```

注意：
这个方法Qt5之后的Qt版本才有

## 读取文件的大小

## 计算文件夹里文件个数

```cpp
QDir *dir = new QDir("D:\\");  

QStringList filter;
//filter<<"*.dat";
//dir->setNameFilters(filter); //过滤文件类型

QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));

int count=fileInfo->count();  //文件个数
cout<<count<<endl;
cout<<fileInfo->at(2).filePath().toStdString()<<endl;  //文件路径
cout<<fileInfo->at(2).fileName().toStdString()<<endl;  //文件名称
```

## 计算文件夹里所有文件的大小

```cpp
qint64 fileSize(const QString &path)
{
    QDir dir(path);
    qint64 size = 0;
    
    //dir.entryInfoList(QDir::Files)返回文件信息
    // 遍历获取目录内所有文件和子文件夹
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files)) {
        size += fileInfo.size();
    }
    
    //dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot) 返回所有子目录，并进行过滤 
    foreach(QString subDir, dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot)) {
        //若存在子目录，则递归调用fileSize()函数（即本函数）
        size += fileSize(path + QDir::separator() + subDir);
    }

    return size;
}

```

## 参考链接

[Qt5官方文档](https://doc.qt.io/qt-5/qdir.html)
[Qt6官方文档](https://doc.qt.io/qt-6/qdir.html)
