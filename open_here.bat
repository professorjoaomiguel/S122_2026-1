@echo off
:: Atalho para abrir o PowerShell 7 (pwsh) diretamente nesta pasta
:: Se o pwsh não existir, ele cai para o powershell padrão (v5)

where pwsh >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    start pwsh -NoExit -Command "Set-Location '%~dp0'; Write-Host '--- S122 IoT Environment ---' -ForegroundColor Cyan; Write-Host 'Caminho: %~dp0' -ForegroundColor Gray"
) else (
    start powershell -NoExit -Command "Set-Location '%~dp0'; Write-Host 'PowerShell 7 nao encontrado. Usando v5.' -ForegroundColor Yellow"
)
