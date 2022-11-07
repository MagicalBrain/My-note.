# 在Visual-Studio中将生成文件复制到指定的目录

有时候我们需要将vs项目生成的可执行文件或者dll文件复制到磁盘的某个目录下来使用。
但是每一次生成之后，都要去项目输出目录手动复制文件到使用的目录，十分麻烦。
巨硬已经可以让我们用bat脚本来简化这个操作，实现每一次生成后自动复制文件到使用目录。

## 生成后事件

右击 项目 属性 生成事件 生成后事件

命令行 编辑：

```bash
copy $(TargetPath) $(SolutionDir)test4recognition\algorithm-plugin\$(TargetFileName)
```

还可以通过下面的计算结果来检查命令写的对不对，例如上面的计算结果：
```bash
copy C:\hrl\HinYeun-HRL\algorithmDemoPlugin-HRL\x64\Release\recognizeCloseObjectPlugin.dll C:\hrl\HinYeun-HRL\algorithmDemoPlugin-HRL\test4recognition\algorithm-plugin\recognizeCloseObjectPlugin.dll
```

```bash
xcopy /y /s /d $(HYSDK_ROOT)\plugin\*.* $(ProjectDir)plugin\
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\ABB\bin\*.dll $(ProjectDir)plugin\robot\ABBRobotPlugin\
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\ABB\bin\*.dll $(SolutionDir)$(Platform)\$(Configuration)\
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\Aubo\bin\*.dll $(ProjectDir)plugin\robot\AuboRobotPlugin\
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\Huashu\bin\*.dll $(ProjectDir)plugin\robot\HuashuRobotPlugin\
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\libfranka\bin\*.dll $(ProjectDir)plugin\robot\FrankaRobotPlugin\
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\Poco\bin\PocoFoundation.dll $(ProjectDir)plugin\robot\FrankaRobotPlugin\
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\Poco\bin\PocoNet.dll $(ProjectDir)plugin\robot\FrankaRobotPlugin\
xcopy /y /s /d $(HYSDK_ROOT)\template\*.* $(ProjectDir)data\template\
xcopy /y /s /d $(HYSDK_ROOT)\template\*.* $(ProjectDir)data\template\
xcopy /y $(SolutionDir)$(Platform)\$(Configuration)\$(TargetName).exe $(HYSDK_ROOT)\bin
```

将WidgetBox.dll复制到项目的输出文件夹中去：
```bash
xcopy /y /s /d $(HYSDK_ROOT)\3rdParty\WidgetBox\bin\WidgetBoxPlugin.dll $(SolutionDir)$(Platform)\$(Configuration)\
```

## 参考目录

https://blog.csdn.net/a_dev/article/details/103683047
https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box?view=vs-2019
