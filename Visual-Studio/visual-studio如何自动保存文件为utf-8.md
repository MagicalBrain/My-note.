# visual-studio如何自动保存文件为utf-8

**注意**：
以下方法目前来看用处并不大。目前能够实现的有：
1. 读取中文
2. 编译运行不报错
3. CMD中文不乱码

但是未能实现：
读取文件的路径包含中文。
换句话说：如果代码里需要读取文件，而且文件的路径包含中文的话，那么即使程序能够成功运行也会触发异常。

----

下载安装扩展：`Force utf-8 No Bom`即可。

**注意**：
如果一开始你的项目就是非utf-8的，那么用这个插件的话，
只能依次打开项目里的所有文件手动按下ctrl+s才可以自动转换成utf-8保存。

但是这样编译的时候会有错

https://blog.csdn.net/dolphin98629/article/details/89082416
https://blog.csdn.net/hnlgzb/article/details/81911824

## 目前的解决方案——高级保存功能

使用vs的高级保存功能，将源代码文件保存为 **UTF-8 有签名**

经测试，如果是无签名的话，大概率会导致没有语法错误，却编译出错的情况。
