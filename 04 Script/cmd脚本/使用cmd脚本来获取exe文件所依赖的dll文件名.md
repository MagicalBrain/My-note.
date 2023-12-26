<!--
 * @Author: MB's X13 374870361@qq.com
 * @Date: 2023-12-26 17:26:01
 * @LastEditors: MB's X13 374870361@qq.com
 * @LastEditTime: 2023-12-26 17:46:42
 * @Description: 
-->
# 使用cmd脚本来获取exe文件所依赖的dll文件名

## 结果

不太行

## 示例

你可以使用以下的 CMD 脚本来调用 `dumpbin.exe` 并找出 `my.exe` 所依赖的所有 DLL 文件，并将这些 DLL 文件名保存到一个文本文件中。

```batch
@echo off

set "exePath=my.exe"
set "outputFile=output.txt"

REM 使用 dumpbin.exe 获取依赖的 DLL 列表
for /f "tokens=2 delims= " %%i in ('dumpbin /dependents "%exePath%" ^| findstr /i ".dll"') do (
    REM 将每个 DLL 文件名追加到输出文件中
    echo %%i >> "%outputFile%"
)
```

请将脚本中的 `my.exe` 替换为你实际的可执行文件路径和名称，并将 `output.txt` 替换为你希望保存 DLL 文件名的文本文件路径和名称。

脚本的执行步骤如下：

1. 设置 `exePath` 变量为你的可执行文件路径和名称。
2. 设置 `outputFile` 变量为输出文本文件的路径和名称。
3. 使用 `dumpbin.exe` 命令获取 `my.exe` 的依赖 DLL 列表，并使用 `findstr` 过滤出包含 ".dll" 的行。
4. 对于每个依赖 DLL 文件，将其文件名追加到输出文件中。

运行脚本后，输出文件 `output.txt` 将包含 `my.exe` 所依赖的所有 DLL 文件名。如果有多个依赖 DLL，每个 DLL 文件名将单独占据一行。

请确保 `dumpbin.exe` 可以在脚本所在的路径或系统路径中找到。