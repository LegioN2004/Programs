Install-Module vssetup -Scope CurrentUser
$i = (Get-VSSetupInstance)
Import-Module "$($i.InstallationPath)/Common7/Tools/Microsoft.VisualStudio.DevShell.dll"
Enter-VsDevShell $i.Instanceid -DevCmdArguments '-arch=amd64 -host_arch=amd64'
