# Latex 结构化实例

标签（空格分隔）： Latex语法

---

**注意**
使用的是XeLatex

```Latex
\documentclass{article}
\usepackage[UTF8]{ctex}
\usepackage[a4paper, left = 10mm, right = 10mm, top = 15mm, bottom = 15mm]{geometry}
\usepackage{graphicx}


\title{符号学 原理与推演}
\author{黄瑞霖}
\date{\today}

\begin{document}

\maketitle

\tableofcontents


\begin{abstract}
这是摘要。
这是我的第一份读书笔记
\end{abstract}

\section{符号的构成}
阿斯蒂芬爱上对方过后就哭了阿斯顿发生酒叟递交了呢\par
酒叟IC金瓯个我就去你来撒快递费给偶加两三年的分泌物：

\section{改变字体}
以下是废话：

起来你看圣诞节佛罗尿结石贷方金额见识到了妇女个偶尔建档立卡sad积分地附近1
时代峰峻

\subsection{一个子标题}


阿萨德

爱上的我

共Joi1

跑的是极品奇葩

徐州市地方

反倒是可怕

按时打卡强迫

啊圣诞节哦i1

爱神的箭Opi

撒的奇偶i1

撒娇都拼命

```

## 引用

```latex
\begin{quote}
{\kaishu 初九，潜龙勿用。}\footnote{这是楷书}

{\fangsong 初九，潜龙勿用。}\footnote{这是仿宋}
\end{quote}
```

## 插入图片

```Latex

\section{插入图片}
记得插入graphicx宏包

\begin{figure}[htbp]
\centering
\includegraphics[height = 8cm]{AI.jpg}
\caption{人工智能}\label{AI}

\end{figure}
```

## 插入表格

```Latex
\section{插入表格}
\begin{table}[htbp]
\centering
\caption{附一个表}

\begin{tabular}{cccccccc}
\hline
1&2&3&4&5&6&7&8\\
\hline
1&2&3&4&5&6&7&8\\
\hline

\end{tabular}
\end{table}
```

## 插入公式

```Latex
\section{插入公式}
\subsection{文字中的公式符号}
胜利大街$y = \sin (x) $佛网

\subsection{单行公式}
\begin{equation}
y = \sin (x)
\end{equation}
```

## 交叉引用实例

```Latex
\section{交叉引用}
从图\ref{AI}中，可以看出……


\end{document}
```

$y = \sin(x)$

$y = sin(x)$


