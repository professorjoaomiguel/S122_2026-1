# Guia: Como Iniciar um Laboratório (GitHub ➡️ Wokwi Web)
`#Wokwi` `#GitHub` `#Setup` `#PassoAPasso`

Este guia explica como você deve levar as orientações e arquivos base deste repositório para o simulador Wokwi na web.

---

## 🚀 O Processo em 3 Passos

### 1. Preparação (Lado GitHub)
Navegue até a pasta do laboratório desejado (ex: `LAB_05_Sensores_Serial`).
-   Abra o arquivo `README.md` para ler as instruções e desafios.
-   Se houver um arquivo `diagram.json`, abra-o e **copie todo o conteúdo** (Ctrl+A, Ctrl+C). Este arquivo contém o desenho do hardware.
-   Se houver um arquivo `sketch.ino`, faça o mesmo (Copie o código).

### 2. Criação (Lado Wokwi)
Abra um projeto vazio diretamente para a placa do laboratório:
*   🚀 [**Projeto Vazio: Arduino Uno**](https://wokwi.com/projects/new/arduino-uno)
*   🚀 [**Projeto Vazio: ESP32 DevKit v4**](https://wokwi.com/projects/new/esp32)
*   🚀 [**Projeto Vazio: Raspberry Pi Pico**](https://wokwi.com/projects/new/pi-pico)

### 3. Sincronização (O "Pulo do Gato")
Para não ter que desenhar o circuito do zero (a menos que o desafio peça), faça o seguinte:
1.  No editor do Wokwi, procure a aba chamada **diagram.json**.
2.  Apague o conteúdo atual e **cole** o que você copiou do GitHub. *Automaticamente, os componentes e fios aparecerão na tela!*
3.  Volte para a aba do código (geralmente `sketch.ino` ou `main.py`).
4.  Cole o código base que você copiou ou comece a digitar conforme o roteiro.

---

## 🛠️ Dicas de Ouro

### 📂 Bibliotecas
Se o laboratório usar componentes como DHT22 ou LCD I2C:
1.  Clique no ícone de **Library Manager** (ícone de pastinha/livros na aba esquerda).
2.  Clique no botão **+** (Add).
3.  Digite o nome da biblioteca (ex: `DHT sensor library`) e selecione-a. Sem isso, seu código dará erro de compilação.

### 💾 Salvando seu Progresso
-   O Wokwi gera um link único para o seu projeto. **Salve este link!**
-   É este link que você deve enviar no Google Classroom ao final da aula.

---
**⬅️ [Voltar ao Índice](./WIKI_INDEX.md)**
