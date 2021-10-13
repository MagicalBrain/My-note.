# Wix如何使用命令安装程序

使用命令安装做出来的安装包，并指明生成日志文件到当前目录

```bash
# 正常安装
msiexec /i  SetupProject1.msi

# 安装后写日志，MyInstaller.log
msiexec /i  SetupProject1.msi  /l*v  MyInstaller.log
```
