# Latex常用 数学公式语法总结

[toc]

## 数学常用
### 约等号
$\approx$

```latex
\approx
```

### 正负号

$\pm$

```latex
\pm
```

### 花括号

$$\left\{a_i | a_i \in ElemSet, i=1,2,3,\dot,n, n \geqslant 0 \right\}$$

```latex
\left\{a_i | a_i \in ElemSet, i=1,2,3,\dot,n, n \geqslant 0 \right\}
```

### 乘号
$$\times$$

```latex
\times
```

点乘

$$\cdot$$

```latex
\cdot
```

### 上下标

```latex
a^x //上标
a_x //下标
```

显示效果

$$a^x=a_x$$

### 分数

```latex
\frac{f(x)}{f(x_0)}
```

显示效果：
$$\frac{f(x)}{f(x_0)}$$

### 绝对值符号

```latex
\lVert
```

$\lVert$

$\vert$

### 因为所以

```
\because
```
$\because$

```
\therefore
```
$\therefore$

## 几何学

### 相似

$\sim$

$\backsim$

$\cong$

$\backcong$

## 高数（微积分）
### 微元
$\Delta$

### 导数与偏导数

**导数：**

$\mathrm{d}$

```
\mathrm{d}
```

**偏导数：**
$\partial$
```
\partial
```

### 积分号

$$\int$$

$$\iint$$
$$\iiint$$

$$\idotsint$$

$$\oint$$

$$\oiint$$

$$\oiiint$$

### 极限符号

$$\lim_{x \to+ \infty}$$

$\lim\limits_{x \to+ \infty}$

### 梯度符号

$\nabla f$

## 线性代数
### 矩阵
$$
\begin{pmatrix}
   0 & 1 & 0 & 0 & 0\\
   0 & 0 & 1 & 0 & 0\\
   0 & 0 & 0 & 1 & 0\\
   0 & 0 & 0 & 0 & 1\\
   1 & 0 & 0 & 0 & 0
  \end{pmatrix} 
$$

$$
\begin{bmatrix}
   0 & 1 & 0 & 0 & 0\\
   0 & 0 & 1 & 0 & 0\\
   0 & 0 & 0 & 1 & 0\\
   0 & 0 & 0 & 0 & 1\\
   1 & 0 & 0 & 0 & 0
  \end{bmatrix} 
$$

## 概率论

### 波浪线
$\sim$

## 李群与李代数

$\mathfrak{sim}(3)$

## 特殊字母
### 希腊字母

alpha	$\alpha$

$\Alpha$

beta	$\beta$

$\Beta$

gamma	$\gamma$

$\Gamma$

delta	$\delta$

$\Delta$

epsilon	$\epsilon$

$\Epsilon$

zeta	$\zeta$

$\Zeta$

eta	$\eta$

$\Eta$

theta	$\theta$

$\Theta$

iota	$\iota$

$\Iota$

kappa	$\kappa$

$\Kappa$

lambda	$\lambda$

$\Lambda$

mu	$\mu$

$\Mu$

sigma	$\sigma$

$\Sigma$

phi	$\phi$

$\Phi$

omega	$\omega$ 

$\Omega$

rho	$\rho$

$\Rho$

psi	$\psi$

$\Psi$

xi $\xi$
$\Xi$

http://www.cnblogs.com/maryl/articles/2330119.html

## 统计学常用

$\hat \sigma^2$

## 物理量符号
### 密度
$\rho$

## 测绘地理信息专用
### 度

$45^{\circ}$

```
$45^{\circ}$
```

$45^{\circ}$

（2）这样定义一下用起来可能方便一些：

```
\def\degree{${}^{\circ}$} 
  
90\degree 
```

## 关系符
###大于等于号、小于等于号
$\le $ 
$ \leq $
$ \leqslant$

$\geqslant$
$\ge$
$\geq$
### 不等号
$\neq$



## 集合

### 实数集

$\mathbb{R}$ 或 $\mathbb R$

### 复数集

$\mathbb{C}$ 或 $\mathbb C$

### 补集
$\complement A$
$\overline A$

### 空集

$$\varnothing$$
$\emptyset$

## 大型运算符
### 累加
$$\sum_{i = 1}^{i = k}$$

$\sum\limits_{i = 1}^{i = k}$

### 累乘
$$\prod_{i = 1}^{i = k}$$

## 数理逻辑
### 属于
$\in$

### 任意
$\forall$

### 非
$\neg$

$$ \overline{A}$$

### 存在
$\exists$

### 且（合取）
$\wedge$

### 或（析取）
$\vee$

## 其他常用特殊符号

### 上取整、下取整

$$\lceil asd \rceil$$

$$\lfloor asd\rfloor$$

### 箭头
$\Rightarrow$
**上，下箭头**
$\uparrow$	↑↑
\downarrow	↓↓
\Uparrow	⇑⇑
\Downarrow	⇓⇓
\updownarrow	↕↕
\Updownarrow	⇕⇕
**左右箭头**
\rightarrow	→→
\leftarrow	←←
\Rightarrow	⇒⇒
\Leftarrow	⇐⇐

\longrightarrow	⟶⟶
\longleftarrow	⟵⟵
\Longrightarrow	⟹⟹
\Longleftarrow	⟸⟸
**等价箭头**
\longleftrightarrow	⟷⟷
$\Longleftrightarrow$
\leftrightarrow	↔↔
\Leftrightarrow	⇔⇔

$$\mathop{OC}\limits ^{\longrightarrow}$$

### 省略号
```
\dots
//或
\cdots
```
显示效果：
$$\dots = \cdots$$

## 特殊公式显示

### 大括号公式

```
\begin{equation}  
\left\{  
               
             x=\dfrac{3\pi}{2}(1+2t)\cos(\dfrac{3\pi}{2}(1+2t)),&  \\  
             y=s, & 0\leq s\leq L,|t|\leq1.\\  
             z=\dfrac{3\pi}{2}(1+2t)\sin(\dfrac{3\pi}{2}(1+2t)), &    
             \end{array}  
\right.  
\end{equation}  
```

$$
\left\{  
  \begin{array}{lr}  
  x=\dfrac{3\pi}{2}(1+2t)\cos(\dfrac{3\pi}{2}(1+2t)), &  \\  
  y=s, & 0\leq s\leq L,|t|\leq1.\\  
  z=\dfrac{3\pi}{2}(1+2t)\sin(\dfrac{3\pi}{2}(1+2t)), &    
  \end{array}  
\right. 
$$

### 带编号的公式显示

$$
\left\{  
  \begin{array}{lr}  
  x=\dfrac{3\pi}{2}(1+2t)\cos(\dfrac{3\pi}{2}(1+2t)), &  \\  
  y=s, & 0\leq s\leq L,|t|\leq1.\\  
  z=\dfrac{3\pi}{2}(1+2t)\sin(\dfrac{3\pi}{2}(1+2t)), &    
  \end{array}  
\right.  \tag{1}
$$

$$
\begin{equation} 
  \begin{split}
  n&=\left[\frac{b-a}{0.01}\right]+1,    \\
  &=\frac{1}{n}\sum\limits_{j=1}^{n}(\lambda_{0j}-\lambda_{j}).
  \end{split}
\end{equation}
$$

## 特殊数学符号（字母）

$$
\mathfrak{R}
$$

I. IV
II. IV