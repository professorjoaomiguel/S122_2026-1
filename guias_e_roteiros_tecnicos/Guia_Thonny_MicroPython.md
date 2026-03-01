# Thonny IDE - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Ambiente de desenvolvimento (IDE) amigável para MicroPython, ideal para iniciantes em programação de microcontroladores.
**Contexto M3F:** [X] Percepção (Edge) | [ ] Transporte (Fog) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Código Python escrito pelo usuário, arquivos `.bin` (firmware).
- **Saída (Output):** Envio de código para o ESP32 via Serial (REPL), gravação de arquivos na flash do dispositivo.

## 3. Instalação e Configuração

### 🪟 Windows
1.  **Download:** https://thonny.org
2.  **Procedimento:** Siga o instalador padrão. Configure o intérprete em "Executar > Configurar Intérprete > MicroPython (ESP32)".
3.  **Verificação:** Digite `print(1+1)` no painel inferior (Shell) com a placa conectada.

### 🐧 Linux
1.  **Comando de Instalação:** `sudo apt install thonny`
2.  **Verificação:** `thonny --version`

## 4. Integração (Ecossistema S122)
- **Conecta com:** ESP32 físico via porta USB/Serial.
- **Utiliza:** Guia_ESP32_MicroPython.md para lógica de sensores.

**Links Relacionados (CORE):**
- Guia ESP32: Guia_ESP32_MicroPython.md

## 5. Referências e Repositórios
- **Página Oficial:** https://thonny.org
- **MicroPython Wiki:** https://github.com/micropython/micropython/wiki
- **Repositório Thonny:** https://github.com/thonny/thonny

## 6. Solução de Problemas (Troubleshooting)
- **Erro: "Device is busy":** Outro programa (ex: Monitor Serial) está usando a porta. Feche-o e tente novamente.
- **Erro: Porta Serial não aparece:** Verifique drivers (CP210x/CH340) e o cabo USB (deve ser de dados).

## 7. Fontes de Consulta (AI & Web)
- Thonny User Guide: https://github.com/thonny/thonny/wiki
- Tutorial SENAI IoT: (Material Interno)

---
*Documento em constante atualização. Versão: 2026/1*
