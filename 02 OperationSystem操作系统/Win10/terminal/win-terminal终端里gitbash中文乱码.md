# win terminal终端里gitbash中文乱码

打开`setting.json`

```json
{
    "commandline": "C:\\Program Files\\Git\\bin\\bash.exe",
    "guid": "{3d24b0fa-a54b-4d85-84e8-4f9357d5ec3c}",
    "hidden": false,
    "icon": "C:\\Program Files\\Git\\mingw64\\share\\git\\git-for-windows.ico",
    "name": "Git-Bash"
}
```

将`"commandline": "C:\\Program Files\\Git\\bin\\bash.exe"`改为    `"commandline": "C:\\Program Files\\Git\\bin\\bash.exe --login -i"`:

```json
{
    "commandline": "C:\\Program Files\\Git\\bin\\bash.exe --login -i",
    "guid": "{3d24b0fa-a54b-4d85-84e8-4f9357d5ec3c}",
    "hidden": false,
    "icon": "C:\\Program Files\\Git\\mingw64\\share\\git\\git-for-windows.ico",
    "name": "Git-Bash"
}
```
