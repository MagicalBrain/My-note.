# 方程组的解

## 具体型方程组

### 含参数的线性方程组

1. 系数阵或增广阵 初等变换化为阶梯型
2. 方形的 可用克拉默法则：$$|A| \neq 0 \Leftrightarrow 方程有唯一解 \Leftrightarrow \lambda不是f(\lambda)的零点$$ $$|A| = 0 \Leftrightarrow \lambda 是f(\lambda)的零点$$
3. 该问题的变体：含参数向量之间的关系

### 方程组的公共解与同解问题

#### 求两个方程组的公共解

###### 1、已知两方程组，联立求解公共解

齐次方程组$A_{m \times n} x=0$，$B_{m \times n} x=0$的公共解是满足$
\left[\begin{array}{l}
{A} \\
{B}
\end{array}\right] x=0
$的解，即联立求解。

同理可求$Ax = \alpha$和$Bx = \beta$的公共解

##### 2、已知一个方程组的通解和另一方程组求公共解

求出$Ax = 0$的通解$k_{1} \xi_{1}+k_{2} \xi_{2}+\cdots+k_{s} \xi_{s}$
代入$Bx = 0$求出$k_{i}$之间的关系代回$Ax = 0$的通解，即得公共解

##### 3、已知两方程组基础解系求公共解

若给出$A_{m \times n} x=0$的基础解系$\xi_{1}, \xi_{2}, \cdots, \xi_{s}$，$B_{m \times n} x=0$的基础解系$\eta_{1}, \eta_{2}, \cdots, \eta_{t}$，则公共解
$$
\gamma=k_{1} \xi_{1}+k_{2} \xi_{2}+\cdots+k_{s} \xi_{s}=l_{1} \boldsymbol{\eta}_{1}+l_{2} \boldsymbol{\eta}_{2}+\cdots+l_{t} \boldsymbol{\eta}_{t}
$$
即
$$
k_{1} \xi_{1}+k_{2} \xi_{2}+\cdots+k_{s} \xi_{s}-l_{1} \eta_{1}-l_{2} \eta_{2}-\cdots-l_{t} \eta_{t}=0
$$
解得$k_i$，$l_j$即可写出$\gamma$

#### 同解方程组问题

两方程组有完全相同的解，即通解方程组

$A_{m \times n} x=0$，$B_{m \times n} x=0$是通解方程组
$\Leftrightarrow$,$A_{m \times n} x=0$的解满足$B_{m \times n} x=0$；$B_{m \times n} x=0$的解也满足$A_{m \times n} x=0$，互相代入即可求出。

$\Leftrightarrow$ $r(A) = r(B)$，且$A_{m \times n} x=0$的解满足$B_{m \times n} x=0$或$B_{m \times n} x=0$的解也满足$A_{m \times n} x=0$

$$
\Leftrightarrow r(\boldsymbol{A})=r(\boldsymbol{B})=r\left(\left[\begin{array}{l}
{\boldsymbol{A}} \\
{\boldsymbol{B}}
\end{array}\right]\right)
$$

## 抽象型方程组

### 含未知参数的齐次方程组的解

$A x=0$，总有解，至少有零解

1. $r(A) = n$，只有零解
2. $r(A) < n$，有无穷多解

**常考结论**

1. $Ax=0$只有零解，则$r(A) = n$ 列满秩 $\nRightarrow r([\boldsymbol{A} | \boldsymbol{b}]) = n$，故$Ax=b$可能有解，也可能无解
2. $Ax=0$ 有无穷多解（有非零解），则$r(A) < n$ 列不满秩 $\nRightarrow r([\boldsymbol{A} | \boldsymbol{b}]) = n$，故$Ax=b$可能有解，也可能无解

### 含未知参数的非齐次方程组的解

$A_{m \times n} x=b$

1. $r(\boldsymbol{A}) \neq r([\boldsymbol{A} | \boldsymbol{b}])$，无解
2. $r(\boldsymbol{A})=r([\mathbf{A} | \boldsymbol{b}])=n$，有唯一解
3. $r(\boldsymbol{A})=r([\boldsymbol{A} ; \boldsymbol{b}])=r<n$ ，有无穷多解

**常考结论**

1. 若A行满秩，则$r(\boldsymbol{A})=r([\mathbf{A} | \boldsymbol{b}])$，故$A x=b$必有解
2. 若$A x=b$有唯一解，则$r(\boldsymbol{A})=r([\mathbf{A} | \boldsymbol{b}]) =A的列数$，故$A x=b$只有零解
3. 若$A x=b$有无穷多的解，则$r(\boldsymbol{A})=r([\mathbf{A} | \boldsymbol{b}]) < A的列数$，故$A x=b$有非零解

**2、3不可倒推**

### 基础解系

满足三条：

### 解的结构

### 解与系数的关系

### 用方程组的解讨论秩
