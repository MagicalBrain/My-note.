@echo off

echo ��ǰ�������ڵ��̷���·����%~dp0

rem setx /M MYSDK_ROOT C:\hrl\

set cpplib=C:\hrl\MyCPP\PTA-Basic

::��ӱ�����MYSDK_ROOT����
setx /m "MYSDK_ROOT" "%MYSDK_ROOT%;%cpplib%"

pause