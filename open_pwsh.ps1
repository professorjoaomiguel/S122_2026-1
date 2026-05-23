# Script para abrir o PowerShell 7 na pasta do projeto
# Versão: 2026/1 - S122

Write-Host "--- S122 Internet das Coisas ---" -ForegroundColor Cyan
Write-Host "Abrindo ambiente de desenvolvimento..." -ForegroundColor Yellow

# Verifica se o pwsh (PowerShell 7) está instalado
if (Get-Command pwsh -ErrorAction SilentlyContinue) {
    Set-Location -Path $PSScriptRoot
    Write-Host "Diretório atual: $PSScriptRoot"
} else {
    Write-Warning "PowerShell 7 (pwsh) não encontrado. Usando PowerShell padrão."
}
