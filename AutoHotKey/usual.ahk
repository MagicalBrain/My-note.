﻿#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

;禁用一些可能会干扰到的快捷键
;!::
;return

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
Send +{End}
return

;从行尾到行首
!+Left::
Send +{Home}
return

;保存文件
!s::
Send ^{s}
return

;打开文件
!o::
Send ^{o}
return

;新建文件以及打开新的标签页
!n::
Send ^{n}
return

!t::
Send ^{t}
return

;回到桌面
!d::
Send #{d}
return

;尝试解决打不出感叹号的问题
;+1::
;Send {!}1
;return