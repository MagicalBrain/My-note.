::�����ļ����б�
set List=ip.txt
 ECHO %LIST%
::����ԭ�ļ�������Ŀ¼
set SrcPath="%~dp0dt\"
 ECHO %SRCPATH%
::����Ŀ���ļ���·��
set SavPath="%~dp0output"
ECHO %SAVPATH%
for /f "usebackq delims=" %%a in ("%List%") do (
               XCOPY  %srcpath%"*%%a*"  %SavPath%\  /S /Y
            
            )

