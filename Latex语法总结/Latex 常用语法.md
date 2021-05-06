# Latex 常用语法

标签（空格分隔）： Latex语法

---

##待研究的问题
- [ ] 如何空多行？


## 排版
### 首行缩进
导入一下两个宏包
```latex
\usepackage{indentfirst}
\setlength{\parindent}{2em}
```

使用```\noindent```和```\indent```来控制是否首行缩进，还可控制首行缩进的多少

### 插入空格
```latex
\ 
%注意后面是有一个空格的！
```

https://blog.csdn.net/bennyfun79/article/details/15500575

### 插入空行
使用双反斜杠即可，还可在后面加```{distance}```来控制行距
```latex
~\\
```

### 插入分页符
```
\newpape
```

## 字体控制

### 设置字体颜色

首先导入color包：

```latex
\usepackage{color}
```

设置成红色：

```latex
{\color{red} text}
```

或者
```latex
\textcolor[rgb]{1,0,0}{text}
```

## 插入特殊元素
### 插入表格

```
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

https://blog.csdn.net/juechenyi/article/details/77116011

### 插入图片

```
\begin{figure}[htbp]
    \centering
    \includegraphics[height = 7cm]{14802.png}
    \caption{RTL View}\label{14802}
\end{figure}
```

#### 插入子图

```latex
\begin{figure}[htbp]
    \centering
    \subfigure[1]{
        \begin{minipage}{6cm}
            \includegraphics[height = 10cm]{1.png}
            %\caption{世博超市一楼}\label{14801}
        \end{minipage}
    }
    

    \subfigure[2]{
        \begin{minipage}{6cm}
            \includegraphics[height = 10cm]{2.png}
            %\caption{世博超市二楼}\label{14802}
        \end{minipage}
    }
\end{figure}
```

## 插入代码
### 用到的包
```latex
\usepackage{listings}
```

### 示例一
```latex
\begin{lstlisting}[language = {[ANSI]C}]

%要插入的代码：
Status InitQueue(SeQueue Q, int size)
{
    Q.elem = (ElemType*) malloc (size*sizeof(ElemType));
    if (Q.elem == NULL)
        return OVERFLOW;
    Q.maxSize = size;
    Q.front = Q.rear = 0;
    return OK;
}

\end{lstlisting}
```

### 插入MATLAB代码且可显示中文注释

### 设置语法高亮等格式
```latex
\definecolor{mygreen}{rgb}{0,0.6,0}
\definecolor{mygray}{rgb}{0.5,0.5,0.5}
\definecolor{mymauve}{rgb}{0.58,0,0.82}

\lstset{ %
  backgroundcolor=\color{white},   % choose the background color; you must add \usepackage{color} or \usepackage{xcolor}
  basicstyle=\footnotesize,        % the size of the fonts that are used for the code
  breakatwhitespace=false,         % sets if automatic breaks should only happen at whitespace
  breaklines=true,                 % sets automatic line breaking
  captionpos=bl,                    % sets the caption-position to bottom
  commentstyle=\color{mygreen},    % comment style
  deletekeywords={...},            % if you want to delete keywords from the given language
  escapeinside={\%*}{*)},          % if you want to add LaTeX within your code
  extendedchars=true,              % lets you use non-ASCII characters; for 8-bits encodings only, does not work with UTF-8
  frame=single,                    % adds a frame around the code
  keepspaces=true,                 % keeps spaces in text, useful for keeping indentation of code (possibly needs columns=flexible)
  keywordstyle=\color{blue},       % keyword style
  %language=Python,                 % the language of the code
  morekeywords={*,...},            % if you want to add more keywords to the set
  numbers=left,                    % where to put the line-numbers; possible values are (none, left, right)
  numbersep=5pt,                   % how far the line-numbers are from the code
  numberstyle=\tiny\color{mygray}, % the style that is used for the line-numbers
  rulecolor=\color{black},         % if not set, the frame-color may be changed on line-breaks within not-black text (e.g. comments (green here))
  showspaces=false,                % show spaces everywhere adding particular underscores; it overrides 'showstringspaces'
  showstringspaces=false,          % underline spaces within strings only
  showtabs=false,                  % show tabs within strings adding particular underscores
  stepnumber=1,                    % the step between two line-numbers. If it's 1, each line will be numbered
  stringstyle=\color{orange},     % string literal style
  tabsize=2,                       % sets default tabsize to 2 spaces
  %title=myPython.py                   % show the filename of files included with \lstinputlisting; also try caption instead of title
}
\begin{lstlisting}[language={[ANSI]C},title={bubbleSort.c}]
#include <iostream>
#define LENGTH 8
using namespace std;
//测试用的代码，bubbleSort函数
int main() {
	int temp,number[LENGTH]={95,45,15,78,84,51,24,12};
	for(int i=0;i<LENGTH;i++)
		for(int j=0;j<LENGTH-1-i;j++)
			if(number[j]>number[j+1]) {
				temp=number[j];
				number[j]=number[j+1];
				number[j+1]=temp;
			} //if end
	for(int i=0;i<LENGTH;i++) cout<<number[i]<<" ";
	cout<<endl;
}//main end
\end{lstlisting}
\lstinputlisting[language=Python, title=myPython.py]{myPython.py}
```

作者：打工是不可能打工滴 
来源：CSDN 
原文：https://blog.csdn.net/golden1314521/article/details/39924449 
版权声明：本文为博主原创文章，转载请附上博文链接！

## 控制PDF
### 输出目录表书签

只需在在导入包的语句那里加上以下语句

```latex
\usepackage[breaklinks,colorlinks,linkcolor=black,citecolor=black,urlcolor=black]{hyperref}
```

## 控制标题

### 是否生成编号

```latex
\section*{绪论}
```

即可让序号消失，不过目录里也没有了，此时就应该用下面的代码加入目录

### 是否加进目录

```latex
\addcontentsline{toc}{section}{绪论}
```
即可加入目录

### 去掉编号，加入目录

比如说有些书籍前面会有序或者绪论，这是可以用这语法使其不出现序号并可加入目录，以免后面第一章的编号却是2，显得很奇怪。

```latex
\section*{绪论}
\addcontentsline{toc}{section}{绪论}
```

参考链接：
http://blog.sciencenet.cn/blog-287000-754637.html

