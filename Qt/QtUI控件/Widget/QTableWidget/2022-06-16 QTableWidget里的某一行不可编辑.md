# QTableWidget设置某一行不可编辑

示例代码：

```cpp
QStandardItemModel* model_; 
model_->setItem(
    i, 3, new QStandardItem(
        QString::QString("(%1,%2,%3)").arg(detect_result.result[0]).arg(detect_result.result[1]).arg(detect_result.result[2])
    )
);
model_->item(i, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
```
