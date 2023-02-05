# python numpy 矩阵操作

标签（空格分隔）： Python

---

## 构建矩阵
### 法一

```python
import numpy as np

# 构建矩阵
n1 = np.arange(0,30,2)
# 控制生成数据从0开始，到30停止，步长为2

n1 = n1.reshape(3,5)
# 设置维度为3行5列，重生成矩阵

print(n1)
```

### 法二

```python
# 构建矩阵
n1 = np.linspace(0,30,15)
# 控制生成数据从0开始，到30停止，一共15个元素

n1.resize(3,5)
# 设置维度为3行5列，重生成矩阵
```

**注意：**
[reshape与resize的区别](https://blog.csdn.net/lanchunhui/article/details/51258503)
一般来讲，记住reshape是有关返回值（不是在原来的矩阵上改变，而是把改变后的存入一个副本并返回），而resize是没有的（是在原来的矩阵上改变）

### 一矩阵

注意不是线性代数上的单位矩阵，而是每个元素都是一的矩阵，数学上的单位矩阵是只有主对角线上的才是1，其余均为0

```python
n1 = np.ones((3,3))
```

### 零矩阵

```python
np.zeros((2, 3))
```

### 单位矩阵

```python
np.eye(3)
# 3维单位矩阵
```

### 由主对角线来构建矩阵

```python
n1 = np.diag(n1)
```

### 随机矩阵

```python
np.random.randint(0, 10, (4,3))
```
生成一个4行3列，每个元素都是0到10的随机数的矩阵

## 矩阵拼接

```python
np.hstack([p, 2*p])#水平拼接
np.vstack([p, 2*p])#竖直拼接
```

## 构建动态矩阵

```python
x = np.empty(shape=[0, 4], int)
x = np.append(x, [[1,2,3,4]], axis = 0)
x = np.append(x, [[1,2,3,4]], axis = 0)
```

**注意：**
必须是一行一行地添加

## 矩阵计算
### 乘法
不像许多矩阵语言，NumPy中的乘法运算符*指示按元素计算，矩阵乘法可以使用dot函数或创建矩阵对象实现

## 求最大值
```python
np.max(first_day)  使用max找数组中的最大值

np.argmax(first_day) 使用argmax找最大值的位置
```

## 函数和方法(method)总览

创建数组
arange, array, copy, empty, empty_like, eye, fromfile, fromfunction, identity, linspace, logspace, mgrid, ogrid, ones, ones_like, r , zeros, zeros_like 
转化
astype, atleast 1d, atleast 2d, atleast 3d, mat 
操作
array split, column stack, concatenate, diagonal, dsplit, dstack, hsplit, hstack, item, newaxis, ravel, repeat, reshape, resize, squeeze, swapaxes, take, transpose, vsplit, vstack 
询问
all, any, nonzero, where 
排序
argmax, argmin, argsort, max, min, ptp, searchsorted, sort 
运算
choose, compress, cumprod, cumsum, inner, fill, imag, prod, put, putmask, real, sum 
基本统计
cov, mean, std, var 
基本线性代数
cross, dot, outer, svd, vdot