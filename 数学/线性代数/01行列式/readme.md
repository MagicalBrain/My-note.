# 线性代数

## 基本符号

r：行
c：列

## 行列式的计算

### （上下）三角形

$$\begin{pmatrix}
   a_0 & 1 & 1 & \cdots & 1\\
    & a_1 &  &  &0 \\
    &  & a_2 &  &0 \\
   \cdots &  &  & \cdots & \cdots\\
    &  &  &  & a_n
  \end{pmatrix} $$

$$= 主对角线元素的乘积 = a_0 \times a_1 \cdots \times a_n$$

### 次三角形

  $$\begin{pmatrix}
    &  &  & \cdots & a_{1n}\\
    &  &  & a_{2,n-1} &0 \\
    &  & a_{3,n-2} &  &0 \\
   \cdots &  &  & \cdots & \cdots\\
    a_{n1}&  &  &  & 
  \end{pmatrix} $$

$$ = (-1)^{\frac{n(n-1)}{2}}a_{1n}\times a_{2,n-1} \cdots a_{n1}$$

### “两线一星”

$$\begin{pmatrix}
   a_0 & b_0 &  & \cdots & \\
    & a_1 & b_1 &  &0 \\
    &  & a_2 & b_2 &0 \\
   \cdots &  &  & \cdots & \cdots\\&&&a_{n-1}&b_{n-1}\\   b_n &  &  &  & a_n
  \end{pmatrix} $$

直接抓住两个“星”拉普拉斯展开就会得到两个三角行列式

### “三对角型”

例如：
   $$\begin{pmatrix}
   1-x & x & 0 & 0 &0 \\
   1 & 1-x & x & 0 &0 \\
   0 & 1 & 1-x & x &0 \\
   0 & 0 & 1 & 1-x & x\\
   0 & 0 & 0 & 1 & 1-x
  \end{pmatrix} $$

可直接展开得两项递推式：$D_n=\alpha D_{n-1}+ \beta D_{a-2}$

1. n较小，直接递推算
2. 用第二数学归纳法证明
3. 将$D_n=\alpha D_{n-1}+ \beta D_{a-2}$变形为$D_n - pD_{n-1}=q(D_{n-1} - pD_{n-2})$，其中$$p+q=\alpha,\\
-pq=\beta$$

### “X”型

$$\begin{pmatrix}
   a_0 & 1 & 1 & \cdots & 1\\
   1 & a_1 &  &  &0 \\
   1 &  & a_2 &  &0 \\
   \cdots &  &  & \cdots & \cdots\\
   1 &  &  &  & a_n
  \end{pmatrix} $$

### “箭头”型（又称之为“爪”型）

例如：
$$\begin{pmatrix}
   a_0 & 1 & 1 & \cdots & 1\\
   1 & a_1 &  &  &0 \\
   1 &  & a_2 &  &0 \\
   \cdots &  &  & \cdots & \cdots\\
   1 &  &  &  & a_n
  \end{pmatrix} $$

  $$c_1 - \frac{c_2}{a_1}\\
  c_1 - \frac{c_3}{a_2}\\
  \cdots\\
  c_1- \frac{c_{n+1}}{a_n}$$
 得： 
  $$\begin{pmatrix}
   a_0-\frac{1}{a_1}-\frac{1}{a_2} \cdots \frac{1}{a_n} & 1 & 1 & \cdots & 1\\
    & a_1 &  &  &0 \\
   &  & a_2 &  &0 \\
   \cdots &  &  & \cdots & \cdots\\
  &  &  &  & a_n
  \end{pmatrix} $$
  $$=   \prod_{i=0}^{i=n}a_i (a_0-\frac{1}{a_1}-\frac{1}{a_2} \cdots \frac{1}{a_n})$$

  $$= \prod_{i=1}^{i=n}a_i(a_0 - \sum_{j=1}^{j=n}\frac{1}{a_j})$$

### 行列元素和相等的矩阵

把行（列）所有元素加到第一行或第一列再利用行列式的性质化简

### “加边”型

除了主对角线或次对角线，其他元素成比例

$$\begin{pmatrix}
   a_1+b_1 & a_2 &  & \cdots & a_n\\
   a_1 & a_2+b_2 &  &  &a_n \\
   a_1 &  & a_3+b_3 &  &a_n \\
   \cdots &  &  & \cdots & \cdots\\
   a_1 &  a_2& \cdots &  & a_n+b_n
  \end{pmatrix} $$

可加多一条边（行或列）：$(1,a_1,\cdots,a_1)^T,(一共有n+1个元素)$，除了第一个元素是1之外，其他元素都是对应的行（列）的比例

可通过行列式的性质化简为上面的爪形行列式进行计算

### 抽象矩阵的行列式

一般用以下公式
1、
$$
|k \boldsymbol{A}|=k^{n}|\boldsymbol{A}|
$$

2、
$$
|A B|=|A||B|
$$

3、
$$
\left|A^{T}\right|=|A|
$$

$$
\left|A^{T} A\right|=|A|^{2}
$$

$$
\left|A^{T} \pm B^{T}\right|=\left|(A \pm B)^{T}\right|=|A \pm B|
$$

4、
$$
\left|\boldsymbol{A}^{-1}\right|=\frac{1}{|\boldsymbol{A}|}=|\boldsymbol{A}|^{-1}
$$

5、
$$
\boldsymbol{A}^{*}=|\boldsymbol{A}| \boldsymbol{A}^{-1}
$$

6、
$$
A A^{*}=A^{*} A=|A| E
$$

7、
$$
\boldsymbol{A}^{-1}=\frac{\boldsymbol{A}^{*}}{|\boldsymbol{A}|}=|\mathbf{A}|^{-1} \mathbf{A}^{*}
$$

$$
 \mathbf{A}^{*}=|\mathbf{A}| \mathbf{A}^{-1}
$$

8、
$$
\left|A^{*}\right|=|A|^{n-1}
$$

9、
$$
\left(A^{*}\right)^{*}=|A|^{n-2} A
$$

10、按行展开式得
$$
a_{i 1} A_{j 1}+a_{i 2} A_{j 2}+\cdots+a_{i n} A_{j n}=\left\{\begin{array}{c}{|\mathbf{A}|, i=j} \\ {0, i \neq j}\end{array}\right.
$$

11、按列展开式得
$$
a_{1 i} A_{1 j}+a_{2 i} A_{2 j}+\dots+a_{n i} A_{n j}=\left\{\begin{array}{c}{|A|, i=j} \\ {0, i \neq j}\end{array}\right.
$$
