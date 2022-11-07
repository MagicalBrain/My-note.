# 1、矩阵

## 1.1 基本公式

### 1.1.1 矩阵转置的运算律

1. $$(A^T)^T = A$$
2. $$(A+B)^T = A^T+B^T$$
3. $$(kA)^T = kA^T$$
4. $$(AB)^T = B^T A^T$$

### 1.1.2 **“穿脱原则”**

矩阵的转置、求伴随矩阵、求逆运算是**可交换**的。

## 1.2 特殊矩阵

稍微提一下不太重要的特殊矩阵类型：

1. 零矩阵：所有元素都是0
2. 单位矩阵：主要注意符号(可能是$E$也可能是$I$)
3. 数量矩阵：常数$k$和单位矩阵的乘积

### 1.2.1 **对角矩阵**
非主对角线元素皆为0

### 1.2.2 **对称矩阵**

转置矩阵和自己是一样的。

$$A^T = A$$
$$a_{i,j} = a_{j,i}$$

### 1.2.3 **反对称矩阵**

转置矩阵等于负的自己

$$A^T = -A$$

符号：
$A^{\wedge}$是$A$的反对称矩阵

### 1.2.4 **正交矩阵**

**正交矩阵的定义**：
$$A^TA=E$$

#### 1.2.4.1 正交矩阵的性质

1. $|A| = 1 或-1$，$|A|^2 = 1$
2. $A^T = A^{-1}$
3. A的伴随矩阵、逆矩阵都是正交矩阵

#### 1.2.4.2 正交矩阵常考的点

$$(E+A^T) = (E^T+A^T) = (A+E)^T$$


### 1.2.5 **可交换矩阵**
$$AB=BA$$

### 1.2.6 实矩阵

矩阵中所有元素都是实数（$R$集）

### 1.2.7 实对称矩阵

矩阵中所有元素均是实数，且满足对称矩阵的定义：$A^T = A$

### 1.2.8 正定矩阵（考研不一定考）

对于一个$n$阶的实对称矩阵$A$，任意的非零向量$x$都有：

$$\forall x \in \mathbb{R}^n , x^TAx > 0 | x \neq 0$$

则$A$为正定矩阵

### 1.2.9 半正定矩阵（考研不一定考）

其实是正定矩阵的推广，条件稍微宽松一点。

对于一个$n$阶的实对称矩阵$A$，任意的非零向量$x$都有：

$$\forall x \in \mathbb{R}^n , x^TAx \geqslant 0 | x \neq 0$$

则$A$为半正定矩阵


## 1.3 矩阵等价的充要条件

$A \sim B$即存在$P,Q$可逆，使$$B = PAQ$$

## 1.4 方阵的幂$A^n$

#### 1、秩为1型

即$r(A)=1$，三行成比例的矩阵

若$A=\alpha \beta^T$，其中$\alpha、\beta$均是n维非零列向量，则$A^n = l^{n-1} A$，其中$l=\sum\limits^n_{i=1} a_n$

$$A = \begin{bmatrix}
   1 & 2 & -1\\ -2& -4 & 2 \\ 3 & 6 & -3\end{bmatrix}$$

通过观察可知，每一列都与第一列成比例，设比例分别为$b_1,b_2,b_3$则：

$$b_1 = 1,b_2=2,b_3=-1$$

$$A = \begin{bmatrix} a_1\\ a_2 \\ a_3 \end{bmatrix} \begin{bmatrix} b_1 & b_2 & b_3 \end{bmatrix}$$

$$A = \begin{bmatrix} 1\\ -2 \\ 3 \end{bmatrix} \begin{bmatrix} 1 & 2 & -1 \end{bmatrix}$$

便可以化为上面的秩为1的矩阵进行计算$A^n$了

#### 2、

$$A = \begin{bmatrix}
   0 & a & c\\
   0 & 0 & b \\
   0 & 0 & 0
  \end{bmatrix} $$ 型

若$A = \begin{bmatrix}
   0 & a & c\\
   0 & 0 & b \\
   0 & 0 & 0
  \end{bmatrix}$ ,则$A^2 = \begin{bmatrix}
   0 & 0 & ab\\
   0 & 0 & 0 \\
   0 & 0 & 0
  \end{bmatrix}$，$A^3 = A^4 =\cdots = A^n = 0$

#### 3、用相似

若$P^{-1}AP=\Lambda$，则$P^{-1}A^nP=\Lambda^n$,于是$A^n=P\Lambda^nP^{-1}$

#### 4、用归纳法

先求出前面几个$A^2,A^3$看出规律得$A^n$

#### 5、拆分矩阵

若$A = B+C$，且$BC=CB$（即$C或B=E$）

$A^n=(B+E)^n$二项式展开得：
$$(B+E)^n = C^0_nB^0E^n + C^1_nB^1E^{n-1} \cdots C^n_nB^nE^0$$

# 二、伴随矩阵的计算

## 2.1 伴随矩阵的性质

1、$$A \cdot A^* = A^* \cdot A = |A| \cdot E$$

2、$|A^*|=|A|^{n-1}$

3、$$(A^T)^* = (A^*)^T$$

4、$(kA)^* = k^{n-1}A^* $

5、$(-A)^*= (-1)^{n-1}A^*$

6、$A^{-1}=\frac{1}{|A|}A^*$

7、$A^* = |A|A^{-1}$

8、$(A^*)^{-1} = \frac{1}{|A|}A = (A^{-1})^*$

9、$(A^*)^* = |A|^{n-2}A$

10、$|(A^*)^*| = |A|^{(n-1)^2}$

11、$(AB)^* = B^*A^*$



## 2.2求法

1. 定义法（先求$A_{ij}$，然后拼成$A^*$）
2. 公式法（$A$可逆，$A^* = |A|A^{-1}$）

## 2.3 伴随矩阵常考的考点

$$a_{ij}=A_{ij} \Leftrightarrow A^T = A^*$$

## 2.4 伴随矩阵的秩

$$
r\left(A^{*}\right)=\left\{\begin{array}{ll}{n,} & {r(A)=n} \\ {1,} & {r(A)=n-1} \\ {0,} & {r(A)<n-1}\end{array}\right.
$$


# 三、逆矩阵的计算

## 1、逆矩阵的性质

1、$(A^{-1})^{-1} = A$

2、$(kA)^{-1} = \frac{1}{k}A^{-1}，(k \neq 0)$

3、$(AB)^{-1}=B^{-1}A^{-1}$（穿脱原则）

4、$(A^T)^{-1} = (A^{-1})^T$

5、$|A^{-1}| = |A|^{-1}$

#### 2、逆矩阵的求法

##### 具体型

1. 定义法（适用于抽象矩阵）
2. 公式法（$A^{-1}=\frac{A^*}{|A|}$）
3. 初等变换法$$(\frac{A}{E}) \sim (\frac{E}{A})$$
$$(A|E) \sim (E|A)$$

##### 抽象型

1. 利用题设，用$E = AB$的恒等变形,则$A^{-1} = B$
2. 若有$A = BC$，且B、C均可逆，则$A^{-1} = C^{-1}B^{-1}$

### 分块矩阵

1. 加法：$$
\left[\begin{array}{cc}{A_{1}} & {A_{2}} \\ {A_{3}} & {A_{1}}\end{array}\right]+\left[\begin{array}{cc}{B_{1}} & {B_{2}} \\ {B_{3}} & {B_{4}}\end{array}\right]=\left[\begin{array}{cc}{A_{1}+B_{1}} & {A_{2}+B_{2}} \\ {A_{3}+B_{3}} & {A_{4}+B_{4}}\end{array}\right]$$

2. 数乘$$k\left[\begin{array}{ll}{A} & {B} \\ {C} & {D}\end{array}\right]=\left[\begin{array}{ll}{k A} & {k B} \\ {k C} & {k D}\end{array}\right]$$

3. 乘法$$
\left[\begin{array}{ll}{A} & {B} \\ {C} & {D}\end{array}\right]\left[\begin{array}{ll}{X} & {Y} \\ {Z} & {W}\end{array}\right]=\left[\begin{array}{ll}{A X+B Z} & {A Y+B W} \\ {C X+D Z} & {C Y+D W}\end{array}\right]$$

4. 若A,B为m，n阶方阵，则分块对角阵的幂为：$$\left[\begin{array}{cc}{A} & {O} \\ {O} & {B}\end{array}\right]^{k}=\left[\begin{array}{cc}{A^{k}} & {O} \\ {O} & {B^{k}}\end{array}\right]$$

5. 已知$$A=\left[\begin{array}{ll}{B} & {O} \\ {D} & {C}\end{array}\right]$$，其中B是r阶可逆矩阵，C是s阶可逆矩阵，则A可逆，且：$$A^{-1}=\left[\begin{array}{ll}{B^{-1}} & {O} \\ {-C^{-1}DB^{-1}} & {C^{-1}}\end{array}\right]$$

6. 主对角线分块矩阵
$$
A=\left[\begin{array}{cccc}
{A_{1}} & {} & {} & {} \\
{} & {A_{2}} & {} & {} \\
{} & {} & {\ddots} & {} \\
{} & {} & {} & {A_{s}}
\end{array}\right]
$$

$$
A^{-1}=\left[\begin{array}{cccc}
{A_{1}^{-1}} & {} & {} & {} \\
{} & {A_{2}^{-1}} & {} & {} \\
{} & {} & {\ddots} & {} \\
{} & {} & {} & {A_{s}^{-1}}
\end{array}\right]
$$

$$
A=\left[\begin{array}{cccc}{} & {} & {} & {A_{1}} \\{} & {} & {A_{2}} & {} \\{} & {\cdots} & {} & {} \\{A_{s}} & {} & {} & {}\end{array}\right]
$$

$$
A^{-1}=\left[\begin{array}{cccc}{} & {} & {} & {A_{s}^{-1}} \\{} & {} & {\cdots} & {} \\{} & {A_{2}^{-1}} & {} & {} \\{A_{1}^{-1}} & {} & {} & {}\end{array}\right]
$$

### 四、初等矩阵（初等变换）

#### 左乘与右乘

**左乘**即**行变换**

**右乘**即**列变换**

#### 三种初等矩阵

**倍乘初等矩阵**
$$E_i(k)$$
把第i 行（列）的元素乘以k倍

**互换初等矩阵**
$$E_{ij}$$
把第j 行（列）与第i 行（列）的元素进行交换

**倍加初等矩阵**
$$E_{ij}(k)$$
把第j 行（列）的元素乘以k倍加到第i 行（列）

#### 三种初等矩阵的求逆公式

**倍乘初等矩阵**
$$[E_i(k)]^{-1} = E_i(\frac{1}{k})$$

**互换初等矩阵**
$$E_{ij}^{-1} = E_{ij}$$

**倍加初等矩阵**
$$[E_{ij}(k)]^{-1} = E_{ij}(-k)$$

### 矩阵方程

1. 消公因式
2. 提取公因式
3. 移项

#### 公式：

1. $AA^* = |A|E$
2. $A^2 - E = (A+E)(A-E) = (A-E)(A+E)$
3. $A^3 - E = (A-E)(A^2 +A+E)$
4. $A^T B^T = (BA)^T$
5. A,B可逆时$A^{-1} B^{-1} = (BA)^{-1} $
6. $A^* B^* = (BA)^*$
7. A可逆时$(A^{-1})^* = (A^*)^{-1}$
8. A可逆时$(A^{-1})^T = (A^T)^{-1}$
9. A可逆时$(A^{*})^T = (A^T)^{*}$

### 五、秩

**有关秩的等式和不等式**

1. $0 \leqslant r(A) \leqslant min\{m,n\}$（定义）
2. $r(kA) = r(A);(k\neq 0)$
3. $r(AB) \leqslant min\{r(A),r(B)\}$
4. $r(A+B) \leqslant r(A)+r(B)$
5. $r(\begin{bmatrix}
   A & O\\
   O & B 
    \end{bmatrix}) \leqslant r(A) +r(B)$
6. $r(A)+r(B) \leqslant r(\begin{bmatrix}
   A & O\\
   C & B 
    \end{bmatrix}) \leqslant r(A)+r(B)+r(C)$
1. $r(AB)\geqslant r(A)+r(B)-n \Leftrightarrow 当AB = O时，r(A)+r(B)\leqslant n$（n是A的列数或B的行数）
2. $r(A) = r(A^T)=r(AA^T)=r(A^TA)$
3. $r(A^*) = $
4. $若A是n阶方阵，A^2=A,则r(A)+r(E-A)=n$
5. $若A是n阶方阵,A^2=E,则r(A+E)+r(A-E)=n$
6. $Ax = 0$，基础解系所含向量个数为$S = n-r(A)$
7. 若$A \sim \Lambda$，则$n_i = n - r(\lambda_i E - A)$，其中$\lambda_i$是$n_i$重特征根
8. 若$A \sim \Lambda$，则$r(A)$等于非零特征值的个数，重根按重数算

## 矩阵求导

### 矩阵求导计算法则

单位矩阵$E$的导数为0

$$(AB)' = A'B + AB'$$

[矩阵求导的本质](https://zhuanlan.zhihu.com/p/263777564)
[矩阵求导的推导](https://zhuanlan.zhihu.com/p/273729929)

## 错题

### 2021 张宇 30讲 习题