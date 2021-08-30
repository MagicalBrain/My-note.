# 在Visual-Studio中将生成文件复制到指定的目录

有时候我们需要将vs项目生成的可执行文件或者dll文件复制到磁盘的某个目录下来使用。
但是每一次生成之后，都要去项目输出目录手动复制文件到使用的目录，十分麻烦。
巨硬已经可以让我们用bat脚本来简化这个操作，实现每一次生成后自动复制文件到使用目录。

## 生成后事件

右击 项目 属性 生成事件 生成后事件

命令行 编辑：

```bash
copy $(TargetPath) C:\hy\HinYeun-HRL\algorithmDemoPlugin-HRL\test4recognition\algorithm-plugin\$(TargetFileName)
```

还可以通过下面的计算结果来检查命令写的对不对，例如上面的计算结果：
```bash
copy C:\hy\HinYeun-HRL\algorithmDemoPlugin-HRL\x64\Release\recognizeCloseObjectPlugin.dll C:\hy\HinYeun-HRL\algorithmDemoPlugin-HRL\test4recognition\algorithm-plugin\recognizeCloseObjectPlugin.dll
```

## 参考目录

https://blog.csdn.net/a_dev/article/details/103683047
https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box?view=vs-2019
