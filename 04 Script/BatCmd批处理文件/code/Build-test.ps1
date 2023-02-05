#$VsDevCmdPath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\2017\Professional\Common7\Tools"
$VsDevCmdPath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\2019\Community\Common7\Tools"
echo "$VsDevCmdPath"

pause

if (Test-Path $VsDevCmdPath\VsDevCmd.bat)
{
    echo "${VsDevCmdPath}·������"
    pause

    pushd $VsDevCmdPath    
    cmd.exe /c "VsDevCmd.bat&set" |
    foreach {
        if ($_ -match "=") {
            $v = $_.split("="); set-item -force -path "ENV:\$($v[0])"  -value "$($v[1])"
          }
    }

    pause

    popd
    
    pause

    Invoke-Expression "MSBuild.exe HySDK.sln -target:Clean"    
    Invoke-Expression "MSBuild.exe HySDK.sln -target:Build -property:Configuration=Release -property:Platform=x64"

    pause
}

echo "�������н���"

pause
