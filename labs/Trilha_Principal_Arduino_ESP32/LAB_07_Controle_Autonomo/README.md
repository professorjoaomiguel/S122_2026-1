# LAB 07: Lógica de Controle e Atuadores

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Lógica de Controle Autônomo e Histerese)

---

### 🔌 Hardware Requerido
*   **Placa:** **ESP32 DevKit v4**
*   **Finalidade:** Processamento em borda (Edge), I/O avançado e IoT

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/esp32.svg" alt="ESP32 DevKit v4" width="160">
</p>

---

Nesta etapa final do Módulo 01, transformamos o sistema em uma entidade autônoma. O desafio é acoplar a **Ação** (Atuadores) em resposta ao que foi lido nos ganchos de **Percepção** (Sensores).

---

## 🚀 Como Iniciar?
1. Abra um projeto vazio para ESP32 (Arduino C++) no simulador: 🚀 [**Projeto Vazio: ESP32 (Arduino)**](https://wokwi.com/projects/new/esp32).
2. Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

## 🎯 Objetivos Técnicos
*   Implementar estruturas de decisão (`if/else`).
*   Introduzir o conceito de **Histerese**.
*   Entender o controle de potência via Relé/LED.

---

## 🧱 Setup de Hardware
Mantenha os sensores e o LCD e adicione os atuadores finais:
*   **LED Azul (Ventoinha):** Pino 11.
*   **Buzzer (Alarme):** Pino 8.
*   **Sensores/LCD:** Conforme LAB 05 e 06.

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: Gancho de Atuação
No seu código modular, localize a tag `[TAG] LOGICA_CONTROLE` e insira a regra de negócio inicial.

```cpp
// [TAG] DEFINICOES
const int PINO_VENTOINHA = 11;
const float LIMITE_TEMP = 30.0;

void setup() {
  // [TAG] SETUP_PINOS
  pinMode(PINO_VENTOINHA, OUTPUT);
}

void loop() {
  // [TAG] LEITURA_DADOS (Do LAB 05)
  float t = dht.readTemperature();
  
  // [TAG] LOGICA_CONTROLE
  if (t > LIMITE_TEMP) {
    digitalWrite(PINO_VENTOINHA, HIGH);
  } else {
    digitalWrite(PINO_VENTOINHA, LOW);
  }
}
```

### 🚀 Passo 2: Alarmes Multi-nível
Não altere a ventoinha. Adicione uma segunda camada de proteção sob o mesmo gancho.

```cpp
  // Abaixo da lógica da ventoinha em [TAG] LOGICA_CONTROLE:
  if (t > 40.0) {
    tone(8, 1000); // Som de Alerta Crítico
  } else {
    noTone(8);
  }
```

### 🚀 Passo 3: Refinamento (Histerese)
Aperfeiçoe o código anterior para evitar o "repique" do relé.

```cpp
  // Refinando em [TAG] LOGICA_CONTROLE:
  if (t > 30.0) {
    digitalWrite(PINO_VENTOINHA, HIGH);
  } 
  else if (t < 28.0) { // Histerese: margem de 2 graus
    digitalWrite(PINO_VENTOINHA, LOW);
  }
```

### 🚀 Passo 4: Código Consolidado Final (Aba _1_Phy.ino)
Ao final das etapas do laboratório, a sua aba física **`_1_Phy.ino`** unificada deverá conter a lógica de leitura, normalização, controle com histerese e acionamento dos alarmes:

```cpp
// --- _1_Phy.ino ---
#include "Bibliotecas.h"

bool ventoinhaLigada = false; // Estado interno do atuador

void setupEdge() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Controle IoT!");
  
  pinMode(PINO_VENTOINHA, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
  
  digitalWrite(PINO_VENTOINHA, LOW);
  noTone(PINO_BUZZER);
  delay(1500);
}

void loopEdge() {
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  int luzRaw = analogRead(LDRPIN);
  luzPerc = map(luzRaw, 0, 4095, 0, 100);

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro na leitura física!");
    return;
  }

  // --- LÓGICA DE CONTROLE DA VENTOINHA COM HISTERESE ---
  if (temp > 30.0) {
    ventoinhaLigada = true;
    digitalWrite(PINO_VENTOINHA, HIGH);
  } 
  else if (temp < 28.0) {
    ventoinhaLigada = false;
    digitalWrite(PINO_VENTOINHA, LOW);
  }

  // --- ALARME CRÍTICO COM BUZZER ---
  if (temp > 40.0) {
    tone(PINO_BUZZER, 1000);
  } else {
    noTone(PINO_BUZZER);
  }

  // --- ATUALIZAÇÃO DO LCD ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("Temp: %.1f C", temp);
  lcd.setCursor(0, 1);
  lcd.printf("Umid: %.1f %%", umid);
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, esta é a **Automação Climática**. O sistema agora possui instinto de preservação: ele "sente" o calor e "age" ligando a refrigeração antes que as plantas murchem.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL Automotivo**, como um sistema similar controla a ventoinha do radiador para proteger o motor de fundir por calor excessivo?

---

## 🧠 Atividades de Desafio Prático e Reflexão
Agora que você construiu um sistema de controle de ciclo fechado, implemente um feedback visual para o usuário local!

### 🚨 Desafio: Feedback no Display Local
*   **Missão:** Use o display LCD para sinalizar o estado dos atuadores em tempo real.
    *   Modifique a exibição no LCD in `_1_Phy.ino` para alternar ou exibir na segunda linha a informação do status da ventoinha (ex: `FAN: ON` ou `FAN: OFF`), facilitando o diagnóstico visual para o operador local de campo.

### ❓ Reflexão Técnica
1.  **Por que usamos a lógica de Histerese (margem de 2°C) no controle da ventoinha?** O que aconteceria se definíssemos apenas um valor rígido de 30°C para ligar e desligar, e a temperatura ambiente ficasse oscilando em torno de 30.01°C e 29.99°C? Como isso afeta a vida útil de relés e motores elétricos na indústria?
2.  Como o barramento I2C simplificou a pinagem necessária para ligar o LCD ao ESP32 (quantos pinos seriam necessários se usássemos o modo paralelo clássico)?

---

## 📂 Solução de Referência e Recursos
O professor disponibilizou uma pasta chamada [**`solucao_referencia/`**](./solucao_referencia/) neste laboratório. Ela contém o circuito físico configurado e a lógica modular 100% implementada para o laboratório, bem como a resolução do desafio no display LCD. Use-a para validar sua lógica depois de tentar resolver sozinho!

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** Link do simulador (com as abas separadas).
*   **Reflexão:** Explique com suas palavras a lógica de Histerese implementada no seu relatório.

---
*UC S122 - Internet das Coisas*
