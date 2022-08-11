# Qt中的Model-View结构

这个和Android开发的MVC模式类似

Model就是数据模型，View就是界面视图

Qt里将数据和界面分开编辑，两者通过信号与槽的方式通信

## 数据模型 Model

Qt提供的Model有：

1. QStringListModel
   1. 用于处理字符串列表数据的数据模型类
2. QStandardItemModel
   1. 标准的基于项数据的数据模型类，每个项数据可以是任何数据类型计算机上文件系统的数据模型类
3. QFileSystemModel
   1. 计算机上文件系统的数据模型类
4. QSortFilterProxyModel
   1. 与其他数据模型结合，提供排序和过滤功能的数据模型类
5. QSqlQueryModel
   1. 用于数据库SQL查询结果的数据模型类
6. QSqlTableModel
   1. 用于数据库的一个数据表的数据模型类
7. QSqlRelationalTableModel
   1. 用于关系型数据表的数据模型类

如果Qt提供的模型种类无法满足需求，那我们还可以用QAbstractItemModel、QAbstractListModel或QAbstractTableModel继承，定义自己需要的数据模型类。

## 视图组件 View


