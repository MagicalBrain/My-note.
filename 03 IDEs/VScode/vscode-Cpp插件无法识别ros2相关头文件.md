<!--
 * @Author: hrl_jxzx_pc_u22 374870361@qq.com
 * @Date: 2023-09-21 16:10:59
 * @LastEditors: hrl_jxzx_pc_u22 374870361@qq.com
 * @LastEditTime: 2023-09-21 16:13:37
 * @FilePath: /Notes/MyNotes/03 IDEs/VScode/vscode-Cpp插件无法识别ros2相关头文件.md
 * @Description: 
-->
# vscode-Cpp插件无法识别ros2相关头文件

我自己通常的做法

在git仓库中

```bash
vim .gitignore

# 添加

.vscode/
```

然后对于设置好的.vscode/进行强制添加

```bash
git add -f .vscode/
```

然后commit，push

如果识别不出来，那就按参考链接里的方法点一下小灯泡。
此时.vscode/里的cpp设置文件会恢复成初始状态，也就是有修改

然后运行命令：

```bash
git checkout.
```

应该就可以了

## 参考链接

https://blog.csdn.net/qq_45701501/article/details/117949024
