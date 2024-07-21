@SET ROOT=%~dp0
cmd /c start "" pwsh -noprofile -command "&{ cd %ROOT% && start-process pwsh -ArgumentList '-noprofile -file .\run_vscode.ps1'}"