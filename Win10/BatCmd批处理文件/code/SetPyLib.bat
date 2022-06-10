@echo off
echo .
echo  ------------------用管理员权限运行 -----------------
echo  ----------------------- 准备 -----------------------
echo.

rem  tarDir 是  python 安装目录
set tarDir=d:\dev\python
rem  pyLibDir 是  python Lib 目录
set pyLibDir=d:\dev\python\Lib

rem "打印一下 目录信息"
echo "---python_Dir   ---- %tarDir%"
echo "---python_Lib_Dir---- %pyLibDir%"
            
set remain=%path%

set finded=false
set findedLib=false
rem "以下目的是查找环境变量里面是否已经设置了，如果没有设置才设置" 
:loop
for /f "tokens=1* delims=;" %%a in ("%remain%") do (
   if "%tarDir%"=="%%a" (
      set finded=true
	  echo "path find 1============== %tarDir%"
   ) 
   
   if "%pyLibDir%"=="%%a" (
      set findedLib=true
	  echo "path find 2============== %pyLibDir%"
   ) 
        
   set remain=%%b
)

if defined remain goto :loop

if "%finded%"=="false" (
	if "%findedLib%"=="false" (
       echo "设置环境变量"
	   setx /m "path" "%pyLibDir%;%tarDir%;%path%"
	) else (
	   setx /m "path" "%tarDir%;%path%"
	)
)

if "%finded%"=="true" (
	if "%findedLib%"=="false" (
	   echo "设置环境变量"
	   setx /m "path" "%pyLibDir%;%path%"
	) 
)
echo  ----------------------- 完成 -----------------------
pause
