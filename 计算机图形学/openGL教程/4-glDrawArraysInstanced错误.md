# 4-管理3D图形数据

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
