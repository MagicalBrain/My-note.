# Kuka机器人的使用中遇到的问题和错误

## 奇怪的语法错误

如图：
![](asset/奇怪的语法错误-1行列.jpg)

这里显示有句法错误的行号和列号都是负数，说明不是这个当前选定的程序有问题，而是其它程序有问题。

中间那里的提示说是`/R1/ArcWeldingFacade`模块有问题

**注意**：
报错的模块路径为`/R1/ArcWeldingFacade`，不是说模块在/R1目录下，而是在/R1及其子目录下。
故在寻找错误模块的时候不应该只在R1里面找，还要去R1的子目录下找。
使用WorkVisual软件来找会方便一点。

解决方法：
1. 如果该程序没有被使用、被引用（WorkVisual里会有提示），那么直接删除此程序即可
2. 打开出错的模块程序，改正里面的语法错误。

## WAIT FOR停下问题

用户权限问题：
可能需要`专家权限`

考虑使用替代代码：

```bash
;考虑使用如下代码替换
WHILE $OUT[14]==FALSE
   WAIT SEC 0.1
ENDWHILE
```

再不行考虑安装低版本的EthernetKRL 2.2.3

```bash
;WAIT FOR $OUT[14]==TRUE 
WHILE $OUT[14]==FALSE
   IF $OUT[14] == TRUE THEN
      EXIT
   ENDIF 
ENDWHILE
```

```bash
&ACCESS RVP
&REL 3
&PARAM DISKPATH = KRC:\R1\Program
DEF SERVER()

RET=EKI_Init("CONNECT")
RET=EKI_Open("CONNECT")

LOOP

WHILE $OUT[14] == TRUE
        $OUT[14]=FALSE

        $TOOL = tool_data[4]
        $LOAD = load_data[4]
        $BASE = base_data[4]

        RET=EKI_GetBool("CONNECT","Robot/readRobotStatus",READROBOTSTATUS)

        IF READROBOTSTATUS==TRUE THEN
            RET=EKI_SetReal("CONNECT","Robot/Pos/X",$POS_ACT.X)
            RET=EKI_SetReal("CONNECT","Robot/Pos/Y",$POS_ACT.Y)
            RET=EKI_SetReal("CONNECT","Robot/Pos/Z",$POS_ACT.Z)
            RET=EKI_SetReal("CONNECT","Robot/Pos/A",$POS_ACT.A)
            RET=EKI_SetReal("CONNECT","Robot/Pos/B",$POS_ACT.B)
            RET=EKI_SetReal("CONNECT","Robot/Pos/C",$POS_ACT.C)
            RET=EKI_SetBool("CONNECT","Robot/chuck",$OUT[2])
            RET=EKI_SetBool("CONNECT","Robot/ready",$OUT[1])
            RET=EKI_Send("CONNECT","Robot")
        ELSE
            RET=EKI_GetBool("CONNECT","Robot/onlySetIO",ONLYSETIO)
            IF ONLYSETIO==TRUE THEN
                RET=EKI_GetBool("CONNECT","Robot/chuck",$OUT[2])
                RET=EKI_Send("CONNECT","Robot")
            ELSE
                RET=EKI_GetReal("CONNECT","Robot/Pos/X",POS_FR.X)
                RET=EKI_GetReal("CONNECT","Robot/Pos/Y",POS_FR.Y)
                RET=EKI_GetReal("CONNECT","Robot/Pos/Z",POS_FR.Z)
                RET=EKI_GetReal("CONNECT","Robot/Pos/A",POS_FR.A)
                RET=EKI_GetReal("CONNECT","Robot/Pos/B",POS_FR.B)
                RET=EKI_GetReal("CONNECT","Robot/Pos/C",POS_FR.C)
                LIN POS_FR
                RET=EKI_Send("CONNECT","Robot")
            ENDIF
        ENDIF
    ENDWHILE

ENDLOOP

RET=EKI_Close("CONNECT")
RET=EKI_Clear("CONNECT")
END
```

----

运行报红是有错误？

尝试运行了一下新建的程序（模块），也是运行爆红。
新建的程序如下：
```bash
&ACCESS RV
&PARAM EDITMASK = *
&PARAM TEMPLATE = C:\KRC\Roboter\Template\vorgabe
DEF op( )
;FOLD INI;%{PE}
  ;FOLD BASISTECH INI
    GLOBAL INTERRUPT DECL 3 WHEN $STOPMESS==TRUE DO IR_STOPM ( )
    INTERRUPT ON 3 
    BAS (#INITMOV,0 )
  ;ENDFOLD (BASISTECH INI)
  ;FOLD USER INI
    ;Make your modifications here

  ;ENDFOLD (USER INI)
;ENDFOLD (INI)

;FOLD PTP HOME  Vel= 100 % DEFAULT;%{PE}%MKUKATPBASIS,%CMOVE,%VPTP,%P 1:PTP, 2:HOME, 3:, 5:100, 7:DEFAULT
$BWDSTART = FALSE
PDAT_ACT=PDEFAULT
FDAT_ACT=FHOME
BAS (#PTP_PARAMS,100 )
$H_POS=XHOME
PTP  XHOME
;ENDFOLD

;FOLD PTP HOME  Vel= 100 % DEFAULT;%{PE}%MKUKATPBASIS,%CMOVE,%VPTP,%P 1:PTP, 2:HOME, 3:, 5:100, 7:DEFAULT
$BWDSTART = FALSE
PDAT_ACT=PDEFAULT
FDAT_ACT=FHOME
BAS (#PTP_PARAMS,100 )
$H_POS=XHOME
PTP  XHOME
;ENDFOLD

END
```

运行到第一个折叠夹就报红，这正常吗？
这居然是正常的，难道说要让这玩意自动运行还需要另外一个控制柜吗？

不可能吧
