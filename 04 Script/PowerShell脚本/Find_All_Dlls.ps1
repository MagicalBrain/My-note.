# Write-Host "׼��ִ�У��ű�ִ�����Ͽ�ʼ�� "

# ��ʱ�ƹ�ǩ������
PowerShell -ExecutionPolicy Bypass -File .\Find_All_Dlls.ps1

# Write-Host "��ʼִ�нű�"

# ���� my.exe �ļ���·��
# $exePath = "G:\HRL-WorkSpace\HNNK_Meditation_V1\release\HNNK_1024.exe"
$exePath = "C:\Users\hrl\AppData\Local\youdao\dict\Application\YoudaoDict.exe"

# ���� dumpbin.exe ���߲�������ض�����ʱ�ļ�
# $tempFile = [System.IO.Path]::GetTempFileName()

$tempFile = "tempfile.txe"
# & "dumpbin.exe" /DEPENDENTS $exePath > $tempFile
# "dumpbin.exe" /DEPENDENTS $exePath > $tempFile
"dumpbin.exe /DEPENDENTS $exePath" | Out-File -FilePath $tempFile

# ��ȡ��ʱ�ļ�����ȡ DLL �ļ���
# $dllNames = Get-Content $tempFile | Select-String -Pattern "^\s+([^\s]+\.dll)" | ForEach-Object { $_.Matches.Groups[1].Value }

# # �� DLL �ļ������浽 txt �ļ�
# $outputFile = "dll_list.txt"
# $dllNames | Out-File -FilePath $outputFile -Encoding UTF8

# ��ʾ�ɹ���Ϣ
# Write-Host "DLL �ļ����ѱ��浽 $outputFile"
# Write-Output "DLL �ļ����ѱ��浽 $outputFile"

# ɾ����ʱ�ļ�
# Remove-Item $tempFile
