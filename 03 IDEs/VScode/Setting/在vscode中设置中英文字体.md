# 在vscode中设置中英文字体

setting中搜索font family：

```bash
Consolas, '楷体', monospace
```
## ubuntu

'Droid Sans Mono', 'monospace', monospace

注意在ubuntu中，设置好系统的默认中文字体就行，这里不用改了。

----

这里介绍一种不用修改系统字体设置的办法

```bash
~/.config/Code/User/settings.json
```

```json
// 路径
{
    "window.titleBarStyle": "custom",
   
    "editor.fontFamily": "'Droid Sans Mono',  'monospace', '微软雅黑', monospace",
    "editor.inlayHints.fontFamily": "'Droid Sans Mono', '微软雅黑', monospace",
    "terminal.integrated.fontFamily": "'Droid Sans Mono', 'monospace', monospace",
    "debug.console.fontFamily": "'Droid Sans Mono', 'monospace', monospace"
}
```

## 参考链接

https://blog.csdn.net/qq_33580192/article/details/110563328
