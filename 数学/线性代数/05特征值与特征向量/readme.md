# 1、特征值

## 1.1 $A$的特征值与特征向量

### 1.1.1 特征值与特征向量的定义

$$A \xi = \lambda \xi,(\xi \neq 0)$$

#### 1.1.1.1 特征值的计算

解方程：$$|\lambda E - A| = 0$$

**常见命题**：

若$|\alpha A + \beta E| = 0$，且$\alpha \neq 0$，则$-\frac{b}{a}$是$A$的特征值

#### 1.1.1.2 特征值的性质

若$\lambda_{1}, \lambda_{2}, \cdots, \lambda_{n}$是$A$的n个特征值，则：
$$
\left\{\begin{array}{l}
{|\boldsymbol{A}|=\lambda_{1} \lambda_{2} \cdots \lambda_{n}} \\
{\operatorname{tr}(\boldsymbol{A})=\sum\limits_{i= 1}^n a_{ii}=\lambda_{1}+\lambda_{2}+\cdots+\lambda_{n}}
\end{array}\right.
$$


#### 1.1.1.3 重要结论

$$
\begin{array}{|ccccccccc|}
\hline 矩阵 &A & {k A} & {A^{k}} & {f(A)} & {A^{-1}} & {A^{*}} & A^T & {P^{-1} A P} \\
\hline 特征值 &\lambda & {k \lambda} & {\lambda^{k}} & {f(\lambda)} & {\frac{1}{\lambda}} & {\frac{|A|}{\lambda}} & {\lambda} & {\lambda}\\
\hline 特征向量 &\xi & {\xi} & {\xi} & {\xi} & {\xi} & {\xi} & 需单独计算 & {\mathbf{p}^{-1} \xi} \\
\hline
\end{array}
$$

若$f(A) = 0$ 则有$f(\lambda) = 0$

### 1.1.2 特征向量

#### 1.1.2.1 特征向量的性质

1. $k$重特征值至多只有$k$个线性无关的特征向量（直接使用，不用证）
2. 若$\xi_1,\xi_2$是A的属于不同特征值$\lambda_1,\lambda_2$的特征向量，则$\xi_1,\xi_2$线性无关
3. 若$\xi_1,\xi_2$是A的属于同一特征值$\lambda$的特征向量，则$k_1 \xi_1 + k_2 \xi_2(k_1,k_2不同时为0)$仍是A的属于特征值$\lambda$的特征向量
4. 若$\xi_1,\xi_2$是A的属于不同特征值$\lambda_1,\lambda_2$的特征向量，则当$k_1 \neq 0,k_2 \neq 0$时,$k_1 \xi_1 + k_2 \xi_2$仍是A的属于特征值$\lambda$的特征向量

## 1.2 矩阵方程

1. $A B=O \Rightarrow A\left[\beta_{1}, \beta_{2}, \cdots, \beta_{n}\right]=[0,0, \cdots, 0]$，即$A\beta_i = 0 \beta_i$，若其中$\beta_i$均为非零向量，则每一个$\beta_i$均为$A$的属于$\lambda = 0$的特征向量。
2. $$
\begin{aligned}
&A B=C \Rightarrow A\left[\beta_{1}, \beta_{2}, \cdots, \beta_{n}\right]=\left[\gamma_{1}, \gamma_{2}, \cdots, \gamma_{n}\right] \stackrel{若}{=}\left[\lambda_{1} \beta_{1}, \lambda_{2} \beta_{2}, \cdots\right.\\
&\left.\lambda_{n} \boldsymbol{\beta}_{n}\right\rfloor
\end{aligned}
$$即$A\beta_i = \lambda_i \beta_i$，其中$\gamma_i = \lambda_i \beta_i$,若$\beta_i$均为非零向量，则$\beta_i$为$A$的属于$\lambda_i$的特征向量
1. $AP = PB,可逆 \Rightarrow P^{-1}AP = B \Rightarrow A \sim B \Rightarrow \lambda_A = \lambda_B$
2. $A$的每行元素之和为$k$，则：$
A\left[\begin{array}{c}
{1} \\
{1} \\
{\vdots} \\
{1}
\end{array}\right]=k\left[\begin{array}{c}
{1} \\
{1} \\
{\vdots} \\
{1}
\end{array}\right] \Rightarrow k 是特征值
$且$\left[\begin{array}{c}
{1} \\
{1} \\
{\vdots} \\
{1}
\end{array}\right]
$是A的属于$k$的特征向量

## 1.3 秩

若$r(A) = 1$则$\lambda_{1}=\cdots=\lambda_{n-1}=0, \lambda_{n}=\operatorname{tr}(A)$
且$\xi_{1}, \cdots, \xi_{n-1}$是$n-1$重特征值$\lambda=0$的线性无关特征向量
