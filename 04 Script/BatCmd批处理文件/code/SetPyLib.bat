@echo off
echo .
echo  ------------------�ù���ԱȨ������ -----------------
echo  ----------------------- ׼�� -----------------------
echo.

rem  tarDir ��  python ��װĿ¼
set tarDir=d:\dev\python
rem  pyLibDir ��  python Lib Ŀ¼
set pyLibDir=d:\dev\python\Lib

rem "��ӡһ�� Ŀ¼��Ϣ"
echo "---python_Dir   ---- %tarDir%"
echo "---python_Lib_Dir---- %pyLibDir%"
            
set remain=%path%

set finded=false
set findedLib=false
rem "����Ŀ���ǲ��һ������������Ƿ��Ѿ������ˣ����û�����ò�����" 
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
       echo "���û�������"
	   setx /m "path" "%pyLibDir%;%tarDir%;%path%"
	) else (
	   setx /m "path" "%tarDir%;%path%"
	)
)

if "%finded%"=="true" (
	if "%findedLib%"=="false" (
	   echo "���û�������"
	   setx /m "path" "%pyLibDir%;%path%"
	) 
)
echo  ----------------------- ��� -----------------------
pause
