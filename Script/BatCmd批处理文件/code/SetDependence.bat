@echo off

echo 当前环境所在的盘符和路径：%~dp0

:: 设置opencv路径

set opencvlib="%~dp0%\opencv\build"
echo opencv路径为 %opencvlib%
::setx /m "OPENCV_ROOT" "%opencvlib%"

:: 设置pcl路径

set pcllib="%~dp0%\PCL 1.11.1"
echo pcl路径为 %pcllib%
::setx /m "PCL_ROOT" "%pcllib%"

:: 设置HYSDK路径

set hysdklib="%~dp0%\HYSDK"
echo hysdk路径为 %hysdklib%
::setx /m "HYSDK_ROOT" "%hysdklib%"

:: 将boost库的lib和dll复制到pcl的三方库里

set boostroot="%~dp0%\boost_1_74_0"
echo boost路径为 %boostroot%
:: dir /b .\lib64-msvc-14.2\*.lib
dir /b %boostroot%\lib64-msvc-14.2\*.lib > %boostroot%\boostlib.txt
dir /b %boostroot%\lib64-msvc-14.2\*.dll > %boostroot%\boostdll.txt

set boostlib="%boostroot%\boostlib.txt"
set boostlib=%boostlib:"=%

set boostdll="%boostroot%\boostdll.txt"
set boostdll=%boostdll:"=%

ECHO boostlib 为 %boostlib%
ECHO boostdll 为 %boostdll%

::设置目标文件夹路径
set CopyPath="%~dp0\target"
ECHO %CopyPath%

::for /f "usebackq delims=" %%a in ("%boostlib%") do (
::    XCOPY  %boostroot%\lib64-msvc-14.2\"*%%a*"  %CopyPath%\  /S /Y
::)
::
::for /f "usebackq delims=" %%a in ("%boostdll%") do (
::    XCOPY  %boostroot%\lib64-msvc-14.2\"*%%a*"  %CopyPath%\  /S /Y
::)

:: 将vtkwithqt库的所有内容复制到pcl的三方库里

set vtklib="%~dp0%\VTK 8.2.0 WithQt"
echo vtk路径为 %vtklib%
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
