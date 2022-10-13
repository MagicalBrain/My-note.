# 在Windows下编写cmd脚本编译Doxyfile

有时候我们的项目包含的第三方库比较多，vs的解决方案或者cmake里有时候没办法方便的把所有依赖库的注释都生成文档，这个时候在win上我们就需要编写cmd脚本来编译doxygen文档

```cmd
"%DOXYGEN_ROOT%/bin/doxygen.exe" Doxyfile
start "" doc/html/index.html
```
