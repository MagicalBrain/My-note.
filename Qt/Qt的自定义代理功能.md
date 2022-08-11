# Qt的自定义代理功能

控件的自定义代理功能可以让控件根据数据类型来绑定对应的编辑组件。
其实就是自定义数据的显示和编辑方式

## 自定义代理类的基本设计要求

![](./asset/%E8%87%AA%E5%AE%9A%E4%B9%89%E4%BB%A3%E7%90%86%E7%B1%BB.png.jpg)

Qt中有关代理的几个类的层次结构如上图5-12所示

QAbstractItemDelegate是所有代理类的抽象基类，
QStyledItemDelegate是视图组件使用的缺省的代理类，QItemDelegate也是类似功能的类。

QStyledItemDelegate 与QItemDelegate 的差别在于：QStyledItemDelegate 可以使用当前的样式表设置来绘制组件，因此建议使用 QStyledItemDelegate 作为自定义代理组件的基类。

无论是QStyledItemDelegate还是QItemDelegate继承设计自定义代理组件，都必须实现以下4个函数：

1. createEditor()
   1. 创建用于编辑模型数据的widget组件，如一个QSpinBox组件，或一个QComboBox组件
2. setEditorData()
   1. 从数据模型获取数据，供widget组件进行编辑
3. setModelDate()
   1. 将widget上的数据更新到数据模型
4. updateEditorGeometry()
   1. 用于给widget组件设置一个合适的大小

## 基于QSpinBox的自定义代理类

## 自定义代理类的使用

## 基于QComboBox的自定义代理类

```cpp
class MainWindow : public QMainWindow
{
    private:
        QWIntSpinDelegate initSpinDelegate;
        QWFloatSpinDelegate floatSpinDelegate;
        QWComboBoxDelegate comboBoxDelegate;
}

MainWindow::MainWindow(QWidget* parent) : 
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    theModel = new QStandardItemModel(2, FixeColumnCount, this);
    theSelection = new QItemSelectionModel(theModel);

    connect(theSelection, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));

    ui->tableView->setModel(theModel);
    ui->tableView->setSelectionModel(theSelection);

    ui->tableView->setItemDelegateForColumn(0, &intSpinDelegate);
    ui->tableView->setItemDelegateForColumn(1, &floatSpinDelegate);
    ui->tableView->setItemDelegateForColumn(2, &floatSpinDelegate);
    ui->tableView->setItemDelegateForColumn(3, &floatSpinDelegate);
    ui->tableView->setItemDelegateForColumn(4, &comboBoxDelegate);
}
```


