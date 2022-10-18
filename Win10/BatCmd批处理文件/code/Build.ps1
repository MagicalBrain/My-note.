$VsDevCmdPath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\2017\Professional\Common7\Tools"

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