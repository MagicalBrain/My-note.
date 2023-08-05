# vscode markdown pdf插件安装和使用

这个插件说白了就是将markdown保存成html，然后在Chrome浏览器里打印导出pdf。

## 安装

由上可知，这个插件的安装之前得先安装Chrome浏览器。

64位机Chrome浏览器安装位置：

```bash
C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe
```

然后直接到vscode插件那里下载并安装`markdown pdf`插件。

安装的时候会显示找不到Chrome，没关系。
等安装完再去设置Chrome的路径

打开插件的设置json，将`"markdown-pdf.executablePath"`修改成下面的：

```json
{
    "workbench.colorTheme": "Default Dark+",
    "markdown-preview-enhanced.previewTheme": "vue.css",
    "editor.fontSize": 18,
    "security.workspace.trust.untrustedFiles": "open",
    "editor.minimap.maxColumn": 100,
    "extensions.ignoreRecommendations": true,
    "terminal.integrated.defaultProfile.windows": "Git Bash",
    "markdown-pdf.executablePath": "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe",
    "markdown-pdf.highlightStyle": "brown-paper.css"
}
```

## Markdown-Notes-Pack

为了提升在vscode里写markdown体验，还可以安装
`Markdown-Notes-Pack`这个插件
