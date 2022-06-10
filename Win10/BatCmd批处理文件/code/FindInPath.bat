rem "尝试在MySDK_ROOT里寻找变量"

rem  tarDir 是  我们要寻找的变量
set tarDir=C:\hrl\MyCPP\PTA-Basic

set finded=false
set findedLib=false
rem "以下目的是查找环境变量里面是否已经设置了" 
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
