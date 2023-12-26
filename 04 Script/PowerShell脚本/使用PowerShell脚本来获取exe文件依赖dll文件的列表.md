<!--
 * @Author: MB's X13 374870361@qq.com
 * @Date: 2023-12-26 16:24:51
 * @LastEditors: MB's X13 374870361@qq.com
 * @LastEditTime: 2023-12-26 17:46:19
 * @Description: 
-->
# 使用PowerShell脚本来获取exe文件依赖dll文件的列表

## 结果

不太行

## 示例

以下是一个示例的 PowerShell 脚本，它使用 `dumpbin.exe` 工具来找出 `my.exe` 所依赖的所有 DLL，并将文件名保存到一个文本文件中：

```powershell
# 设置 my.exe 文件的路径
$exePath = "C:\path\to\my.exe"

# 调用 dumpbin.exe 工具并将输出重定向到临时文件
$tempFile = [System.IO.Path]::GetTempFileName()
& "dumpbin.exe" /DEPENDENTS $exePath > $tempFile

# 读取临时文件，提取 DLL 文件名
$dllNames = Get-Content $tempFile | Select-String -Pattern "^\s+([^\s]+\.dll)" | ForEach-Object { $_.Matches.Groups[1].Value }

# 将 DLL 文件名保存到 txt 文件
$outputFile = "dll_list.txt"
$dllNames | Out-File -FilePath $outputFile -Encoding UTF8

# 显示成功消息
Write-Host "DLL 文件名已保存到 $outputFile"

# 删除临时文件
Remove-Item $tempFile
```

请确保将 `C:\path\to\my.exe` 替换为实际的 `my.exe` 文件路径，而且 `dumpbin.exe` 工具（一般是 Visual Studio 的一部分）在系统路径中可用。

该脚本会调用 `dumpbin.exe` 工具来分析 `my.exe` 文件的依赖关系，并将结果保存到一个临时文件中。然后，它会提取 DLL 文件名，并将它们保存到名为 `dll_list.txt` 的文本文件中。最后，它会显示成功消息，并删除临时文件。

请注意，执行此脚本需要具有适当的权限和正确配置的环境。
