# visual studio 如何查看dll所含有的符号（函数）

主要使用的是vs自带的dumplib工具

可以在vs的开发者powershell里直接调用

```shell
dumpbin /exports filename.dll
```
