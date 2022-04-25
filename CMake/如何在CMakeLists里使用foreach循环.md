# 如何在CMakeLists里使用foreach循环

有时候我们需要使用cmake同时编译多个可执行文件，这时就需要用到

[foreach][foreach]

[foreach]:https://cmake.org/cmake/help/latest/command/foreach.html

```bash
foreach(<loop_var> <items>)
  <commands>
endforeach()
```
