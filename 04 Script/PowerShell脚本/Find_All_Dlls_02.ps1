$exePath = "my.exe"
$output = dumpbin /dependents $exePath
$pattern = ".*dll"
$matches = [regex]::Matches($output, $pattern)
foreach ($match in $matches) {
    $dllName = $match.Value
    Write-Output $dllName
}
