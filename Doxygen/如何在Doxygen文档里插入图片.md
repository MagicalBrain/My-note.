# 如何在Doxygen文档里插入图片

首先需要根据你编写文档的语言来，是html、latex、还是markdown。

根据对应语言的语法写引用图片，但这还不够。

还需要在`Doxygen`设置文件里找到`IMAGE_PATH`把图片存放的路径写进去。

例如：
假设图片都存到asset文件下，那么把asset文件夹的路径添加到`IMAGE_PATH`后，就可以用以下方式引用图片了（Markdown语法）
```markdown
![](hypick-install.png)
```
或者
```markdown
![](./asset/hypick-install.png)
```
