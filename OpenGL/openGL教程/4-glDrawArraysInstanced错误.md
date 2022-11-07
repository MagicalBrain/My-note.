# 4-管理3D图形数据

## 在Release版本下的问题

```bash
Previous IPDB not found, fall back to full compilation.
1>All 388 functions were compiled because no usable IPDB/IOBJ from previous compilation was found.
1>已完成代码的生成
1>glew32s.lib(glew.obj) : warning LNK4099: 未找到 PDB“vc120.pdb”(使用“glew32s.lib(glew.obj)”或在“C:\Users\37487\Documents\hrl\OpenGL-Learning\Release\vc120.pdb”中寻找)；正在链接对象，如同没有调试信息一样
```

其中
```bash
lew32s.lib(glew.obj) : warning LNK4099: 未找到 PDB“vc120.pdb”(使用“glew32s.lib(glew.obj)”或在“C:\Users\37487\Documents\hrl\OpenGL-Learning\Release\vc120.pdb”中寻找)；正在链接对象，如同没有调试信息一样
```
这个警告是正常的。

原来的调试输出：

```
$(IntDir)vc$(PlatformToolsetVersion).pdb
```

修改后的调试文件输出：

```
$(OutDir)$(TargetName).pdb
```

## 尝试在Debug版本下进行调试

Debug环境配置失败，原因应该是boost的问题。
因为我在这个项目中寻找.glsl文件使用boost::filesystem来实现的。

## 最后运行成功的配置

在官方的代码里，用了一部分自己的代码，然后新建项目就成功了，难道继承类还有什么个数限制吗？


