@echo off

echo 当前环境所在的盘符和路径：%~dp0

rem setx /M MYSDK_ROOT C:\hrl\

set cpplib=C:\hrl\MyCPP\PTA-Basic

setx /m "MYSDK_ROOT" "C:\hrl\MyCPP\"

pause