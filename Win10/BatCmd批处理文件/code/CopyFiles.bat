::设置文件名列表
set List=ip.txt
 ECHO %LIST%
::设置原文件所在主目录
set SrcPath="%~dp0dt\"
 ECHO %SRCPATH%
::设置目标文件夹路径
set SavPath="%~dp0output"
ECHO %SAVPATH%
for /f "usebackq delims=" %%a in ("%List%") do (
               XCOPY  %srcpath%"*%%a*"  %SavPath%\  /S /Y
            
            )

