# Set the folder path to change to
$targetFolder = $args[0]

if (-not $targetFolder) {
    $targetFolder = Get-Location
}

Set-Location -Path $targetFolder

# Start Developer PowerShell for Visual Studio 2022
& "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\Launch-VsDevShell.ps1" -SkipAutomaticLocation

# Open Visual Studio Code
& "code" "."
