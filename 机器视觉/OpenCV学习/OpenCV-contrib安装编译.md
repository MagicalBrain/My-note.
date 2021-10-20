# OpenCV-contrib安装编译

## vs2019编译遇到问题


错误代码	MSB3073	

命令
```bash
setlocal
"C:\Program Files\CMake\bin\cmake.exe" -DBUILD_TYPE=Debug -P cmake_install.cmake
if %errorlevel% neq 0 goto :cmEnd
:cmEnd
endlocal & call :cmErrorLevel %errorlevel% & goto :cmDone
:cmErrorLevel
exit /b %1
:cmDone
if %errorlevel% neq 0 goto :VCEnd
:VCEnd
```
已退出，代码为 1。	

INSTALL	C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VC\v160\Microsoft.CppCommon.targets	155	

其实从上面也是可以看出setlocal命令是：

```bash
setlocal
"C:\Program Files\CMake\bin\cmake.exe" -DBUILD_TYPE=$(Configuration) -P cmake_install.cmake
if %errorlevel% neq 0 goto :cmEnd
:cmEnd
endlocal & call :cmErrorLevel %errorlevel% & goto :cmDone
:cmErrorLevel
exit /b %1
:cmDone
if %errorlevel% neq 0 goto :VCEnd
```

严重性	代码	说明	项目	文件	行	禁止显示状态
错误	LNK1104	无法打开文件“..\..\lib\Debug\opencv_world440d.lib”	opencv_annotation	C:\opencvWITHcontrib\opencv_contrib-4.4.0\build\apps\annotation\LINK	1	
