# Write-Host "准备执行，脚本执行马上开始！ "

# 临时绕过签名限制
PowerShell -ExecutionPolicy Bypass -File .\Find_All_Dlls.ps1

# Write-Host "开始执行脚本"

# 设置 my.exe 文件的路径
# $exePath = "G:\HRL-WorkSpace\HNNK_Meditation_V1\release\HNNK_1024.exe"
$exePath = "C:\Users\hrl\AppData\Local\youdao\dict\Application\YoudaoDict.exe"

# 调用 dumpbin.exe 工具并将输出重定向到临时文件
# $tempFile = [System.IO.Path]::GetTempFileName()

$tempFile = "tempfile.txe"
# & "dumpbin.exe" /DEPENDENTS $exePath > $tempFile
# "dumpbin.exe" /DEPENDENTS $exePath > $tempFile
"dumpbin.exe /DEPENDENTS $exePath" | Out-File -FilePath $tempFile

# 读取临时文件，提取 DLL 文件名
# $dllNames = Get-Content $tempFile | Select-String -Pattern "^\s+([^\s]+\.dll)" | ForEach-Object { $_.Matches.Groups[1].Value }

# # 将 DLL 文件名保存到 txt 文件
# $outputFile = "dll_list.txt"
# $dllNames | Out-File -FilePath $outputFile -Encoding UTF8

# 显示成功消息
# Write-Host "DLL 文件名已保存到 $outputFile"
# Write-Output "DLL 文件名已保存到 $outputFile"

# 删除临时文件
# Remove-Item $tempFile
