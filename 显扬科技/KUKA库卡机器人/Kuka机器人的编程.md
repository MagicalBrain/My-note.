# Kuka机器人的编程

## 新建程序


## KRL程序的结构

注意：
KRL里面没有注释语法，一下带有中文的是注释，编辑程序的时候要删除。

```bash
DEF my_program()    
# DEF 行显示程序名称。如果程序是一个函数，则 DEF 行以“DEFFCT” 开头并包括其它说明。DEF 行可以显示或隐藏。

INI
# INI 行包括内部变量和参数初始化的内容。

PTP HOME Vel= 100 % DEFAULT # 起始位置
...
LIN point_5 CONT Vel= 2 m/s CPDAT1 Tool[3] Base[4] # LIN运动
...
PTP point_1 CONT Vel= 100 % PDAT1 Tool[3] Base[4] # PTP运动
...
PTP HOME Vel- 100 % DEFAULT # 起始位置

END
# END 行是各程序的最后一行。
# 如果程序是一个函数，则 END行 为“ENDFCT”。END 行不得删除！
```

## 创建折叠夹Fold

```bash
;FOLD 名称
指令
;ENDFOLD < 名称>
```

折叠可以嵌套。

```bash
;;FOLD 名称
指令
;;ENDFOLD < 名称>
```

双分号是不过是为了防止在编辑的时候合上。

## 对工具和基座标进行编程


