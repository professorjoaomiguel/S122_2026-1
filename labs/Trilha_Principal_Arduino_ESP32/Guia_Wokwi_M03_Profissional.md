# Guia Wokwi Módulo 03 - Workflow Profissional VS Code S122

O Wokwi web é ótimo para prototipagem rápida, mas na **UC S122** trabalhamos como engenheiros. Vamos levar a simulação para dentro do seu **Visual Studio Code**.

---

## 🛠️ 1. Por que usar VS Code + Wokwi?
1.  **Autocomplete (IntelliSense):** O VS Code ajuda você a escrever código sem erros de digitação.
2.  **Git/GitHub:** Você pode versionar seu projeto (essencial para o trabalho de conclusão).
3.  **Bibliotecas:** Gerenciamento local de bibliotecas via PlatformIO ou Arduino CLI.
4.  **Edge Copilot:** Use IAs para auxiliar na codificação profissional.

---

## 🔑 2. O Wokwi Token (Licença)
A extensão do VS Code requer que você se identifique:
1.  Vá em [wokwi.com/dashboard/settings](https://wokwi.com/dashboard/settings).
2.  Gere seu **Wokwi API Token**.
3.  No VS Code, pressione `Ctrl+Shift+P` (ou `F1`), digite `Wokwi: Set API Token` e cole seu código.

---

## 📁 3. A Estrutura de Arquivos Profissional
Um projeto Wokwi no VS Code precisa de no mínimo **três arquivos** na raiz da pasta:

### 1️⃣ `diagram.json` (Hardware)
Define o hardware (onde os fios ligam).
*   **Dica:** Desenhe no Wokwi Web primeiro e use o comando `F1 -> Wokwi: Export Hardware` para baixar este arquivo para sua pasta local.

### 2️⃣ `wokwi.toml` (Configuração)
Explica ao VS Code qual "motor" rodar.
```toml
[wokwi]
version = 1
firmware = 'path/para/seu/binario.ino' # O arquivo de código
elf = 'path/para/seu/binario.elf'     # Onde o binário compilado está
```

### 3️⃣ `libraries.txt` (Dependências)
Onde você lista as bibliotecas que o simulador deve buscar automaticamente:
```text
Adafruit GFX Library
LiquidCrystal I2C
PubSubClient
```

---

## 🚀 4. Executando a Simulação
1.  Pressione `F1` no VS Code.
2.  Escolha `Wokwi: Start Simulator`.
3.  Uma nova aba se abrirá à direita (ou em seu navegador padrão) mostrando o hardware e a execução do código.

---

## 🛠️ Solução de Problemas (Troubleshooting M03)
*   **Wokwi Simulator no VS Code fica preto?** Certifique-se de que o arquivo `diagram.json` está formatado corretamente. Uma vírgula faltando no JSON quebra a renderização.
*   **Erro "ELF file not found"?** Isso acontece se você não compilou o código antes de tentar simular. Compile o projeto (Arduino CLI ou PlatformIO) primeiro.
*   **As bibliotecas não funcionam?** Se você estiver usando **PlatformIO**, as bibliotecas devem estar no arquivo `platformio.ini`. O arquivo `libraries.txt` só é necessário para o workflow simples da extensão Arduino.

---
### 🔗 Navegação do Ecossistema Wokwi S122
- **[🏠 Índice Mestre](./Wokwi_Master_Index.md)**
- **[📖 Manual de Laboratório (Práticas)](./Wokwi_Lab_Manual_S122.md)**
- **[🟢 Módulo 01: Fundamentos](./Guia_Wokwi_M01_Fundamentos.md)**
- **[🔵 Módulo 02: Redes e M3F](./Guia_Wokwi_M02_Redes.md)**
- **[🔴 Módulo 03: Workflow Profissional](./Guia_Wokwi_M03_Profissional.md)**

---
*Versão 2026/1 - Prof. João Miguel*
