# Doxygen的主界面生成

主要是新建一个文本文件，.doc .md……都可以
然后里面全部都是注释，在Doxygen能够识别的注释第一行添加`\mainpage`即可

然后就可以在注释里按相应的语法写主界面的内容了

如果出现注释的符号有乱码，则可把所有注释符号都删掉试试

## 例子

**Main.md**：

```markdown
/*
\mainpage

# HYDeviceSDK

这是显扬科技有线公司的HYDeviceSDK。
*/
```