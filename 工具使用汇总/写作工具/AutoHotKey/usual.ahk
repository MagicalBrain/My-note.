#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

;移动光标
!Left::
Send {Home}
return

!Right::
Send {End}
return

!Up::
Send ^{Home}
return

!Down::
Send ^{End}
return

;复制粘贴
!c::
Send ^{c}
return

!v::
Send ^{v}
return

;剪切
!x::
Send ^{x}
return

;撤销上一次的操作
!z::
Send ^{z}
return

;全选
!a::
Send ^{a}
return

;从行首到行尾
!+Right::
KeyWait, Right, D
Send +{End}
return

;从行尾到行首
!+Left::
KeyWait, Left, D
Send +{Home}
return

;查找字符串
!f::
Send ^{f}
return

;保存文件
!s::
Send ^{s}
return

;打开文件
!o::
Send ^{o}
return

;浏览器操作
;打开新窗口
!n::
Send ^{n}
return

;打开新的标签页
!t::
Send ^{t}
return

;关掉标签页
!w::
Send ^{w}
return

;系统操作
;新建文件同浏览器的新建窗口

;回到桌面
!d::
Send #{d}
return

