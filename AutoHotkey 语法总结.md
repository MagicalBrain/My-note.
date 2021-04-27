# AutoHotkey 语法总结

## 介绍

AutoHotkey是一种可以方便地在win10上创建快捷键的脚本语言。

## 使用目的

方便自己的日常使用，主要是指在某些方面可以兼容macOS上的快捷键。

## 语法

```ahk
^j::
Send, My First Script
return
```

```^j::```是定义快捷键的代码。

```^```是 “Ctrl”
```j```是字母 “j”

类似于函数，第一行定义的是 按下 那些按键
第三行是函数的结束，无返回值。
这两行里的就是要执行的操作。

### 按键的定义

```#```是 “win”

```^```是 “Ctrl”
```!```是 “Alt”
```+```是 “Shift”

方向键：


## 尝试定义一些macOS上的快捷键

### 光标到行首

macOS上是：“Alt + $\leftarrow$”

```
!Left::
Send {Home}
return
```

### 光标到行末

macOS上是：“Alt + $\rightarrow$”

```
!Right::
Send {End}
return
```

### 光标到文件起始点

macOS上是：“Alt + $\uparrow$”

```
!Up::
Send ^{Home}
return
```

### 光标到文件结尾

macOS上是：“Alt + $\downarrow$”

```
!Down::
Send ^{End}
return
```