# vscode如何在terminal里设置git bash

## 旧版

```json

```

## 新版

打开terminal的设置json`setting.json`

```json
{
    "editor.fontSize": 14,
    "security.workspace.trust.untrustedFiles": "open",
    "editor.unicodeHighlight.invisibleCharacters": false,
    "markdown-preview-enhanced.previewTheme": "newsprint.css",
    
    
    "terminal.integrated.profiles.windows": {
        "GitBash": {
            "path": "D:\\Git\\Git\\bin\\bash.exe",
            "args": []
            
        },
        "PowerShell": {
            "source": "PowerShell",
            "icon": "terminal-powershell"
        },
        "Command Prompt": {
            "path": [
                "${env:windir}\\Sysnative\\cmd.exe",
                "${env:windir}\\System32\\cmd.exe"
            ],
            "args": [],
            "icon": "terminal-cmd"
        },
        
    },
    "terminal.integrated.defaultProfile.windows": "GitBash",
    "terminal.external.windowsExec": "D:\\Git\\Git\\bin --login",
}
```

版本号如下：
```
Version: 1.65.0 (user setup)
Commit: b5205cc8eb4fbaa726835538cd82372cc0222d43
Date: 2022-03-02T11:12:08.962Z
Electron: 13.5.2
Chromium: 91.0.4472.164
Node.js: 14.16.0
V8: 9.1.269.39-electron.0
OS: Windows_NT x64 10.0.19044
```
