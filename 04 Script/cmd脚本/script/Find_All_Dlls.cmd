@REM @echo off
echo "��ʼ����"


set "exePath=C:\Users\hrl\AppData\Local\youdao\dict\Application\YoudaoDict.exe"
set "outputFile=C:\Users\hrl\AppData\Local\youdao\dict\Application\output.txt"

for /f "tokens=2 delims= " %i% in ('dumpbin /dependents "%exePath%" ^| findstr /i ".dll"') do (
    REM ��ÿ�� DLL �ļ���׷�ӵ�����ļ���
    echo %%~nxi >> "%outputFile%"
)
