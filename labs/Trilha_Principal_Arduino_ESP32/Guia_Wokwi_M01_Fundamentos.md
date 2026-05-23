# Guia Wokwi Módulo 01 - Fundamentos e Hardware S122

Neste primeiro módulo, dominaremos a interface e a lógica de montagem física simulada. O Wokwi é um simulador de alto desempenho (HPC) que roda circuitos integrados em tempo real no seu navegador.

---

## 💻 1. A Interface Wokwi
A interface é dividida em três áreas principais:
1.  **Code Editor (Esquerda):** Onde escrevemos o firmware (C++ para Arduino/ESP32 ou Python para MicroPython).
2.  **Simulation Canvas (Direita):** Onde os componentes são montados e os fios conectados.
3.  **Serial Monitor (Rodapé):** Janela de depuração essencial para a arquitetura M3F.

### 🛑 Fluxo de Trabalho (O Loop PBL)
1.  **Add Components:** Clique no botão `+`.
2.  **Wire:** Clique em um pino e arraste até o outro.
3.  **Code:** Escreva ou cole sua lógica.
4.  **Simulate:** Clique em `Start Simulation`.

---

## 🔋 2. Eletrônica Digital Simulada
Diferente de simuladores "ideais", o Wokwi tenta aproximar-se da realidade:
*   **LEDs:** Podem queimar se não houver um resistor (sim, o simulador avisa com um ícone de explosão 💥).
*   **Breadboards:** O uso de protoboards é opcado mas recomendado para organização.
*   **Logic Analyzer:** Uma ferramenta avançada disponível no menu de componentes para ver as ondas de sinais (como PWM ou I2C) em tempo real.

---

## 📟 3. O "Cérebro" ESP32 no Wokwi
O ESP32 é o foco da UC S122. No simulador, o modelo `DevKit v1` é o padrão:
*   **Pinos:** GPIO 2 (LED Interno), GPIO 21 (SDA), GPIO 22 (SCL) são os mais usados.
*   **Boot:** Diferente do hardware real, o ESP32 no Wokwi entra em modo de gravação instantaneamente.
*   **Memória:** O simulador valida estouros de buffer e memória stack.

### 🛠️ Diferenças do Arduino Uno
*   O Arduino Uno opera em **5V**.
*   O ESP32 opera em **3.3V**. 
*   **⚠️ Cuidado:** Ligar 5V em pinos do ESP32 no simulador também gerará avisos de "Overvoltage".

---

## 🛠️ Solução de Problemas (Troubleshooting M01)
*   **Simulação não inicia?** Verifique se não há fios "soltos" ou se o código tem erros de sintaxe (vermelho no rodapé).
*   **FPS Baixo (Lentidão)?** Se o seu circuito tiver muitos sensores enviando dados em milissegundos, adicione um `delay(10);` no final do `loop()` para aliviar o processador do seu computador.
*   **Fios Bagunçados?** Use a tecla `R` enquanto seleciona um fio para trocar a cor. Use cores padrão: **Vermelho (VCC)**, **Preto (GND)**.

---
### 🔗 Navegação do Ecossistema Wokwi S122
- **[🏠 Índice Mestre](./Wokwi_Master_Index.md)**
- **[📖 Manual de Laboratório (Práticas)](./Wokwi_Lab_Manual_S122.md)**
- **[🟢 Módulo 01: Fundamentos](./Guia_Wokwi_M01_Fundamentos.md)**
- **[🔵 Módulo 02: Redes e M3F](./Guia_Wokwi_M02_Redes.md)**
- **[🔴 Módulo 03: Workflow Profissional](./Guia_Wokwi_M03_Profissional.md)**

---
*Versão 2026/1 - Prof. João Miguel*
