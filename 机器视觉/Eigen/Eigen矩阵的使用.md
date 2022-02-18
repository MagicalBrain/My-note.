# Eigen矩阵的使用

## 如何定义矩阵

## 矩阵计算

## 矩阵的加减法

`Eigen`库重载了C++的`+-`运算符用于支持矩阵计算

### 矩阵乘法

矩阵乘法包括矩阵和矩阵的乘法和矩阵和向量的乘法。

因为不管是数学还是Eigen，都把向量看作是矩阵的特殊形式。

```cpp
// 矩阵与矩阵相乘
Eigen::Matrix4d A, B;
// 给A、B赋值
Eigen::Matrix4d C = A * B;

// 矩阵与向量相乘
Eigen::Matrix4d A;
Eigen::Vector4d B;
// 这里省略了对A、B的赋值操作
Eigen::Vector4d C = A * B;
Eigen::Matrix4d D = B * A;
```

## 矩阵分块

```cpp
handeye.block<rowsize, colsize>(startrows, startcol);
```

即从handeye矩阵中的$(startrows, startcol)$元素开始，分一块大小为$rowsize \times colsize$的区域

```cpp
    // 是则handeye为手眼矩阵，否则为手眼矩阵的逆矩阵
    Eigen::Matrix4f handeye = eye_to_hand_ ? handeye_ : handeye_.inverse();

    // 从手眼矩阵中获取旋转矩阵
    Eigen::Matrix3f handeye_r = handeye.block<3, 3>(0, 0);

    // 从手眼矩阵中获取t矩阵 即x, y, z方向上相对于相机的距离
    Eigen::Vector3f handeye_t = handeye.block<3, 1>(0, 3);
```

## 将openCV的Mat转成Eigen::Matrix

所需头文件：`#include <opencv2/core/eigen.hpp>`

```cpp
// Eigen矩阵转cv::Mat
cv::eigen2cv();

// cv::Mat转Eigen矩阵
cv::cv2eigen();
```
