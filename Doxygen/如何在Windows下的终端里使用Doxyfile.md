# 如何在Windows下的终端里使用Doxyfile

打开PowerShell，输入：

```bash
[PATH]doxygen.exe -g
```

假设我的Doxygen安装路径为：
`D:\doxygen\bin\`

那么就应该输入命令：

```bash
D:\doxygen\bin\doxygen.exe -g
```

生成默认的Doxygen文件，同理可以直接编译Doxyfile:
```bash
D:\doxygen\bin\doxygen.exe Doxyfile
```
