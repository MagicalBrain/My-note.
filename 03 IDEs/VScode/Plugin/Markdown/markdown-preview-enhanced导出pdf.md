<!--
 * @Author: MB's X13 374870361@qq.com
 * @Date: 2023-04-30 17:52:33
 * @LastEditors: MB's X13 374870361@qq.com
 * @LastEditTime: 2023-09-28 09:57:55
 * @FilePath: \Notes\MyNotes\03 IDEs\VScode\Plugin\Markdown\markdown-preview-enhanced导出pdf.md
 * @Description: 
-->
# vscode的markdown插件 preview enhanced 导出pdf

参考：
https://blog.csdn.net/m0_37639589/article/details/91349425

## 使用chrome来导出pdf

先下载安装Google的Chrome浏览器

在插件的`setting.json`里加上`Chrome.exe`的安装路径：

```json
"markdown-pdf.executablePath" : "C:\\Program Files\\Google\\Chrome\\Application"
```

```json
{
    "editor.fontSize": 18,
    "security.workspace.trust.untrustedFiles": "open",
    "markdown-preview-enhanced.previewTheme": "vue.css",
    "cmake.configureOnOpen": false,
    "extensions.ignoreRecommendations": true,
    "terminal.integrated.defaultProfile.windows": "Git Bash",
    "terminal.external.windowsExec": "C:\\Program Files\\Git\\bin --login",
    "markdown-pdf.executablePath" : "C:\\Program Files\\Google\\Chrome\\Application"
}
```

然后重启vscode，就可以用了。

### 导出的pdf数学公式不显示问题

在开头加上：

```html
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>

```
