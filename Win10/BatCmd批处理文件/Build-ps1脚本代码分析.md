# Build.ps1脚本代码分析

```shell
# 设置路径
$VsDevCmdPath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\2017\Professional\Common7\Tools"

# 检查路径是否存在
if (Test-Path $VsDevCmdPath\VsDevCmd.bat)
{
    pushd $VsDevCmdPath    
    cmd.exe /c "VsDevCmd.bat&set" |
    foreach {
        if ($_ -match "=") {
            $v = $_.split("="); set-item -force -path "ENV:\$($v[0])"  -value "$($v[1])"
          }
    }
    popd
    
    Invoke-Expression "MSBuild.exe HySDK.sln -target:Clean"    
    Invoke-Expression "MSBuild.exe HySDK.sln -target:Build -property:Configuration=Release -property:Platform=x64"
}
```
