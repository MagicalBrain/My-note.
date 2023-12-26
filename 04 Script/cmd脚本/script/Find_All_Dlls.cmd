@REM @echo off
echo "开始查找"


set "exePath=C:\Users\hrl\AppData\Local\youdao\dict\Application\YoudaoDict.exe"
set "outputFile=C:\Users\hrl\AppData\Local\youdao\dict\Application\output.txt"

for /f "tokens=2 delims= " %i% in ('dumpbin /dependents "%exePath%" ^| findstr /i ".dll"') do (
    REM 将每个 DLL 文件名追加到输出文件中
    echo %%~nxi >> "%outputFile%"
)
