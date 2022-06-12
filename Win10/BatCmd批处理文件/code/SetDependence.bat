@echo off

echo ��ǰ�������ڵ��̷���·����%~dp0

:: ����opencv·��

set opencvlib="%~dp0%\opencv\build"
echo opencv·��Ϊ %opencvlib%
::setx /m "OPENCV_ROOT" "%opencvlib%"

:: ����pcl·��

set pcllib="%~dp0%\PCL 1.11.1"
echo pcl·��Ϊ %pcllib%
::setx /m "PCL_ROOT" "%pcllib%"

:: ����HYSDK·��

set hysdklib="%~dp0%\HYSDK"
echo hysdk·��Ϊ %hysdklib%
::setx /m "HYSDK_ROOT" "%hysdklib%"

:: ��boost���lib��dll���Ƶ�pcl����������

set boostroot="%~dp0%\boost_1_74_0"
echo boost·��Ϊ %boostroot%
:: dir /b .\lib64-msvc-14.2\*.lib
dir /b %boostroot%\lib64-msvc-14.2\*.lib > %boostroot%\boostlib.txt
dir /b %boostroot%\lib64-msvc-14.2\*.dll > %boostroot%\boostdll.txt

set boostlib="%boostroot%\boostlib.txt"
set boostlib=%boostlib:"=%

set boostdll="%boostroot%\boostdll.txt"
set boostdll=%boostdll:"=%

ECHO boostlib Ϊ %boostlib%
ECHO boostdll Ϊ %boostdll%

::����Ŀ���ļ���·��
set CopyPath="%~dp0\target"
ECHO %CopyPath%

::for /f "usebackq delims=" %%a in ("%boostlib%") do (
::    XCOPY  %boostroot%\lib64-msvc-14.2\"*%%a*"  %CopyPath%\  /S /Y
::)
::
::for /f "usebackq delims=" %%a in ("%boostdll%") do (
::    XCOPY  %boostroot%\lib64-msvc-14.2\"*%%a*"  %CopyPath%\  /S /Y
::)

:: ��vtkwithqt����������ݸ��Ƶ�pcl����������

set vtklib="%~dp0%\VTK 8.2.0 WithQt"
echo vtk·��Ϊ %vtklib%
:: dir /b .\lib64-msvc-14.2\*.lib
::dir /b %vtklib%\lib64-msvc-14.2\*.lib > %vtklib%\vtklib.txt
dir /b %vtklib% > %vtklib%\vtklist.txt

set CopyPath="%~dp0\vtktarget"
ECHO %CopyPath%

set vtklist=%vtklib%\vtklist.txt
set vtklist=%vtklist:"=%

echo %vtklist%

for /f "usebackq delims=" %%a in ("%vtklist%") do (
    XCOPY  %vtklib%\"*%%a*"  %CopyPath%\  /S /Y
)

pause
