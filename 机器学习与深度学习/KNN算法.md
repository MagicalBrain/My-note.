# K近邻算法（KNN）


---

## 算法描述

对未知类别属性的数据集中的每个点依次执行以下操作：
(1) 计算已知类别数据集中的点与当前点之间的距离；
(2) 按照距离递增次序排序；
(3) 选取与当前点距离最小的k个点；
(4) 确定前k个点所在类别的出现频率；
(5) 返回前k个点出现频率最高的类别作为当前点的预测分类。

## 优点
精度高，对异常值不敏感，无数据输入假定

## 缺点
计算复杂度高、空间复杂度高

## 适用数据范围
**数值型**和**标称型**




