rem "������MySDK_ROOT��Ѱ�ұ���"

rem  tarDir ��  ����ҪѰ�ҵı���
set tarDir=C:\hrl\MyCPP\PTA-Basic

set finded=false
set findedLib=false
rem "����Ŀ���ǲ��һ������������Ƿ��Ѿ�������" 
:loop
for /f "tokens=1* delims=;" %%a in ("%MYSDK_ROOT%") do (
   if "%tarDir%"=="%%a" (
      set finded=true
	  echo "path find 1============== %tarDir%"
   ) 
   else (
       echo "path can not find 1============== %tarDir%"
   )
)

echo "%finded%"

pause
