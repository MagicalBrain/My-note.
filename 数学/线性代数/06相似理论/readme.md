# 矩阵相似理论

# 1、矩阵相似

## 1.1 矩阵相似的定义

**相似的定义：**
设$A,B$为两个$n$阶方阵，若存在$n$阶可逆矩阵$P$使得$P^{-1}AP = B$ ，则称$A$相似于$B$，记$A \sim B$

## 1.2 矩阵相似的性质

1. $A \sim A$
2. 若$A \sim B$，则$B \sim A$
3. 若$A \sim B, B \sim C$，则有$A \sim C$
4. 若$A \sim B$，则有：
    1. $r(A) = r(B)$
    2. $|A| = |B|$
    3. $| \lambda E - A| = |\lambda E - B|$
    4. $A,B$具有相同的特征值
    5. $A^m \sim B^m$
    6. $f(A) \sim f(B)$
    7. $A^T \sim B^T$
5. 若$A \sim B$，且$A$可逆，则
    1. $A^{-1} \sim B^{-1}$
    2. $f(A^{-1}) \sim f(B^{-1})$
    3. $A^* \sim B^*$

## 1.3 A相似于B

### 四个性质(必要条件)

1. $A \sim B \Rightarrow |A| = |B|$
2. $r(A) = r(B)$
3. $tr(A) = tr(B)$
4. $\lambda_A = \lambda_B$或$|\lambda E - A| = |\lambda E - B|$

**注意**：
1的反推只能否定相似，而不能证明相似

### 重要结论

1. $A \sim B \Rightarrow A^{\mathrm{T}} \sim B^{\mathrm{T}}, A^{-1} \sim B^{-1}, A^{*} \sim B^{*}$
2. $A \sim B \Rightarrow  A^{-1} \sim B^{-1}, A^{*} \sim B^{*}$，A可逆
3. $\boldsymbol{A} \sim \boldsymbol{B} \Rightarrow \boldsymbol{A}^{m} \sim \boldsymbol{B}^{m}, f(\mathbf{A}) \sim f(\mathbf{B})$
4. $A \sim B, B \sim \Lambda \Rightarrow A \sim \Lambda$
5. $ \boldsymbol{A} \sim \boldsymbol{\Lambda}, \boldsymbol{B} \sim \boldsymbol{\Lambda} \Rightarrow \mathbf{A} \sim \mathbf{B}$
6. $$A \sim C, B \sim D \Rightarrow\left[\begin{array}{ll}
{A} & {O} \\
{O} & {B}
\end{array}\right] \sim\left[\begin{array}{ll}
{C} & {O} \\
{O} & {D}
\end{array}\right]
$$


# 2、 相似对角化

## 2.1 矩阵的相似对角化的定义

**矩阵的相似对角化的定义：**
设$A,B$为两个$n$阶方阵，若存在$n$阶可逆矩阵$P$使得$P^{-1}AP = \Lambda$ ，则称$A$可相似对角化，记$A \sim \Lambda$，$\Lambda$是$A$的相似标准型

## 2.2 矩阵相似对角化的条件

1. $A$有$n$个线性无关的特征向量$\Leftrightarrow A \sim \Lambda$
2. $n_i = n - r(\lambda_i E - A) \Leftrightarrow A \sim \Lambda$

### 充分条件

1. A是实对称矩阵
2. 有n个互异特征值
3. $A^2 = A$
4. $A^2 = E$
5. $r(A) = 1$且$tr(A) \neq 0 \Rightarrow A \sim \Lambda$

### 必要条件

1. $A \sim \Lambda \Rightarrow r(A) = $非零特征值个数（重根按重数算）

### 否定条件

1. A的特征值全为k，但$A \neq kE \Rightarrow A 不可对角化$
2. $A \neq O , A^k = O,(k \geqslant 1) \Rightarrow A 不可对角化$

# 3、 实对称与正交矩阵

若$A$为实对称矩阵，有$QAQ^{-1} = \Lambda$，求可逆矩阵$Q$的步骤：

1. 求出$A$的特征值
2. 求特征值对应的线性无关的特征向量$\xi_{1},\xi_{2},\cdots,\xi_{n}$
3. 对重根的特征值对应的特征向量施密特正交化（如果已经正交就不用正交化了），再对所有特征向量进行单位化,求得$\eta_{1},\eta_{2},\cdots,\eta_{n}$
4. $Q = [\xi_{1},\xi_{2},\cdots,\xi_{n}]$

**施密特正交化的步骤：**

1. $\eta_1 = \xi_1$
2. $\eta_2 = \xi_2 - \frac{(\xi_2,\eta_1)}{(\eta_1,\eta_1)}\eta_1$
3. $\eta_i = \xi_i - \frac{(\xi_{i},\eta_{i-1})}{(\eta_{i-1},\eta_{i-1})}\eta_{i-1}$

#### 若A为实对称则：

1. $\lambda_{1} \neq \lambda_{2} \Rightarrow \xi_{1} \perp \xi_{2} \Rightarrow\left(\xi_{1}, \xi_{2}\right)=0$
2. 不同特征值正交：$\boldsymbol{P}^{\mathrm{T}} \boldsymbol{P}=\boldsymbol{E} \Leftrightarrow \boldsymbol{P}^{-1}=\boldsymbol{P}^{\mathrm{T}}$
3. 可用相似对角阵相似对角化：存在$P P^{-1} A P = \Lambda$

#### 若A为正交矩阵：

1. $P^TP = E$
2. $\Leftrightarrow P^{-1} = P^T$
3. $P^T$是正交矩阵
4. $P^{-1}$是正交矩阵
5. $P^*$是正交矩阵
6. $-P$是正交矩阵

#### 若$P,Q$为同阶正交矩阵：

1. 则$PQ$为正交矩阵