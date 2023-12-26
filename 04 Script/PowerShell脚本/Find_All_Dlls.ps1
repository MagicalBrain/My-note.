# 设置 my.exe 文件的路径
$exePath = "G:\HRL-WorkSpace\HNNK_Meditation_V1\release\HNNK_1024.exe"

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
