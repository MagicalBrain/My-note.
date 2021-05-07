# Latex插入表格

## 一个简单的例子

```Latex
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

## 表格换行实例

```Latex
\begin{table}[htbp]
    %\centering
    \caption{阅读书目}
    
    \begin{tabular}{|c|c|c|c|c|c|c|}
    \hline
    序号&书名（原书名）&作者（译者）&出版社&出版时间&版次&丛书名\\
    \hline
    1&《深度学习》&（美）伊恩·古德菲洛等著&&&&\\ &&赵申剑等译&人民邮电出版社&2017.8&1&无\\
    \hline
    2&《深度学习 &&&&&\\ & 从入门到实战》&高志强等著&中国铁道出版社&2018.6&1&无\\
    \hline
    3&《深度学习&&&&&\\ &轻松学》&冯超著&电子工业出版社&2017.7&1&无\\
    \hline
    4&《TensorFlow&&&&&\\ &技术解析与实战》&李嘉璇著&人民邮电出版社&2017.6&1&无\\
    \hline
    5&《深度学习&&&&&\\ &轻松学》&冯超著&电子工业出版社&2017.7&1&无\\
    \hline
    \end{tabular}
\end{table}
```

## 合并单元格示例

```latex
\usepackage{amsmath, amssymb}
\usepackage{makecell}
\usepackage{multirow}

\begin{tabular}{|c|r|r|}
    \hline
    \multirow{2}*{姓名} &
    \multicolumn{2}{c|}{成绩}\\
    \cline{2-3} 
    & 语文 & 数学\\ \hline
    王小丫 & 95 & 99 \\ \hline
\end{tabular}
```