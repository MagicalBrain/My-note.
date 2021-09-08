# Inward-region-growing-based accurate partitioning of closely stacked objects for bin-picking

## 3 proposed method 提出的方法

1. 获取点云
2. 识别边界
3. 提升边界的提取效果，并获取边界生长所需的“萌芽”
   1. 基于自身和临近的点的几何特征来提升
   2. 自身 -> BGF算法
   3. 临近点 -> BDC
4. 计算初始生长的方向并开始生长
5. “生长”物体内部的点并获取最终结果

### 3.1 边界萌芽生长算法（Boundary bud generation (BBG) algorithm）

### 3.2 
