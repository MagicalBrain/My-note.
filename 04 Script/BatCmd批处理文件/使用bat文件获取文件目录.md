# 使用bat文件获取文件目录

```batch
@echo off
rem "尝试获取文件目录路径"
echo 当前盘符：%~d0
echo 当前盘符和路径：%~dp0
echo 当前盘符和路径的短文件名格式：%~sdp0
echo 当前批处理全路径：%~f0
echo 当前CMD默认目录：%cd%
pause
```

运行结果：

```batch
C:\hrl\MyNotes\Win10\BatCmd批处理文件>rem "尝试获取文件目录路径"
当前盘符：C:
当前盘符和路径：C:\hrl\MyNotes\Win10\BatCmd批处理文件\
当前盘符和路径的短文件名格式：C:\hrl\MyNotes\Win10\BATCMD~1\
当前批处理全路径：C:\hrl\MyNotes\Win10\BatCmd批处理文件\GetPath.bat
当前CMD默认目录：C:\hrl\MyNotes\Win10\BatCmd批处理文件
请按任意键继续. . .
```
