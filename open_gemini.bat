@echo off
:: Atalho para abrir o Gemini CLI diretamente nesta pasta
:: Tenta usar o PowerShell 7 (pwsh) se disponível

where pwsh >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    start pwsh -NoExit -Command "Set-Location '%~dp0'; Write-Host '--- Iniciando Gemini Tutor S122 ---' -ForegroundColor Cyan; gemini"
) else (
    start powershell -NoExit -Command "Set-Location '%~dp0'; Write-Host '--- Iniciando Gemini Tutor S122 ---' -ForegroundColor Cyan; gemini"
)
