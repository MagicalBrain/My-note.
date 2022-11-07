# 解决Git上传下载跨平台项目换行符问题

这个问题的解决其实很简单，设置git就好。

## Windows上git设置

```bash
git config --global core.autocrlf true
```

在Windows系统上，把它设置成true，这样当签出代码时，LF会被转换成CRLF

## Linux或者macOS上git设置

```bash
git config --global core.autocrlf input
```

这样会在Windows系统上的签出文件中保留CRLF，会在Mac和Linux系统上，包括仓库中保留LF
