# LAB 06: Comunicação I2C e a Transição Monolítico ➡️ M3F Sliced
**Módulo 01: Fundamentos da Borda (Edge)**  

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Display LCD e Barramento I2C)

---

> [!IMPORTANT]
> **A Revolução do Clean Code na IoT:**
> Até agora, você escreveu seus códigos em um único arquivo (monolítico). Conforme adicionamos sensores, displays e futuramente WiFi e MQTT, o arquivo principal vira uma bagunça de "espaguete". Neste laboratório, você aprenderá a criar uma interface visual local (LCD) e, em seguida, fará a sua primeira **Transição Arquitetural**: fatiar o código monolítico em abas separadas baseadas na metodologia **M3F**!

---

## 🎯 Objetivos Técnicos
1.  Compreender o barramento de comunicação industrial **I2C**.
2.  Manipular a biblioteca `LiquidCrystal_I2C`.
3.  **Transição Monolítico-Estruturado:** Fatiar o firmware em arquivos modulares separando a Camada Física/Edge do resto do fluxo.

---

## 🧱 Setup de Hardware
Mantenha os sensores do **LAB 05** e adicione o display:
*   **ESP32 DevKit v4**
*   **DHT22 (Sensor Clima):** Pino 15.
*   **LDR (Luz):** Pino analógico 34.
*   **LCD 16x2 (I2C):** Pinos SDA (Pino 21 do ESP32) e SCL (Pino 22 do ESP32).

---

## ⚙️ Workflow Passo a Passo

### 🏗️ Passo 1: O Código Monolítico (Tudo em Um)
Primeiro, vamos construir a solução de forma clássica: um arquivo único (`sketch.ino`). Ele junta as leituras analógica/digital do LAB 05 com a biblioteca do LCD I2C.

1.  No Wokwi, configure seu circuito com os componentes e crie o código abaixo no arquivo `sketch.ino`:

```cpp
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estufa IoT Monol");
  delay(1500);
}

void loop() {
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();
  int luzRaw = analogRead(LDRPIN);
  int luzPerc = map(luzRaw, 0, 4095, 0, 100); // ADC do ESP32 vai até 4095

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro de leitura!");
    return;
  }

  // Print Serial (Debug)
  Serial.printf("T: %.1f C | U: %.1f %% | Luz: %d%%\n", temp, umid, luzPerc);

  // Print LCD (Visualização Local)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("Temp: %.1f C", temp);
  lcd.setCursor(0, 1);
  lcd.printf("Umid: %.1f %%", umid);

  delay(2000);
}
```
2.  **Rode a simulação.** Verifique se a temperatura e a umidade aparecem perfeitamente no LCD.

---

### 🪓 Passo 2: O Fatiamento M3F (A Transição para Abas)
Parabéns, seu monolítico funciona! Contudo, no **LAB 08 (WiFi)** teremos dezenas de linhas de rede, e no **LAB 11 (MQTT)** mais de 50 linhas de conexões e soquetes. Misturar isso com sensores e LCDs em um só arquivo causará bugs difíceis de rastrear.

Seguindo a **Metodologia M3F**, vamos fatiar esse código em **3 abas físicas** no Wokwi para separar a **Camada Física/Edge** das outras regras.

#### Passo 1: Criar a aba `Bibliotecas.h`
Clique no botão de adicionar arquivo no Wokwi (ou crie no VS Code) e nomeie como `Bibliotecas.h`. Mova para lá todas as inclusões de bibliotecas, definições de pinos e declarações de variáveis globais que serão compartilhadas usando `extern`:

```cpp
// --- Bibliotecas.h ---
#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

// Objetos globais (declarados como extern para que todas as abas enxerguem)
extern DHT dht;
extern LiquidCrystal_I2C lcd;

// Variáveis globais de dados
extern float temp;
extern float umid;
extern int luzPerc;

#endif
```

#### Passo 2: Criar a aba `_1_Phy.ino` (Camada Física / Edge)
Crie uma nova aba chamada `_1_Phy.ino`. Este arquivo conterá apenas a lógica física de sensoriamento, atuação e exibição no display LCD, isolando o hardware local no Edge:

```cpp
// --- _1_Phy.ino ---
#include "Bibliotecas.h"

void setupEdge() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estufa Sliced!");
  delay(1500);
}

void loopEdge() {
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  int luzRaw = analogRead(LDRPIN);
  luzPerc = map(luzRaw, 0, 4095, 0, 100);

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro no DHT22!");
    return;
  }

  // Exibição local
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("Temp: %.1f C", temp);
  lcd.setCursor(0, 1);
  lcd.printf("Umid: %.1f %%", umid);
}
```

#### Passo 3: Limpar o arquivo principal `sketch.ino`
Agora, o seu arquivo principal se torna o **Coordenador Geral** do sistema, mantendo a estrutura limpa e sem detalhes de hardware:

```cpp
// --- sketch.ino ---
#include "Bibliotecas.h"

// Instanciação física das variáveis globais
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temp = 0.0;
float umid = 0.0;
int luzPerc = 0;

// Declaração das funções do Edge
void setupEdge();
void loopEdge();

void setup() {
  Serial.begin(115200);
  Serial.println("--- [M3F] Inicializando Sistema Sliced ---");
  
  setupEdge(); // Inicializa sensores e LCD
}

void loop() {
  loopEdge(); // Executa leitura física local
  
  // Debug Serial
  Serial.printf("[Debug] T: %.1fC | U: %.1f%% | Luz: %d%%\n", temp, umid, luzPerc);
  
  delay(2000);
}
```

---

### 🧪 Passo 3: Teste e Validação
1.  Execute a simulação com as 3 abas ativas.
2.  Verifique se o display continua mostrando a temperatura e umidade exatamente igual ao monolítico.
3.  **Reflexão:** Note como o `loop()` do seu arquivo principal ficou limpo e fácil de ler. 

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, a modularização fatiada representa a arquitetura corporativa real: se amanhã precisarmos trocar o WiFi por LoRa, ou o sensor DHT22 por um termopar analógico, alteramos **apenas a aba correspondente**, sem quebrar ou precisar reescrever o código inteiro!

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de Automação de Caxias do Sul**, por que sistemas industriais usam bibliotecas modulares e isoladas em vez de códigos monolíticos para gerenciar painéis de IHMs?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Adicione um LED vermelho ao circuito. Altere a aba `Bibliotecas.h` (definindo o pino do LED) e a aba `_1_Phy.ino` (para acender o LED se a temperatura passar de 32°C). Perceba como você **não precisou mexer em nada** no coordenador principal `sketch.ino`!
2.  Qual a utilidade do comando `extern` nas variáveis dentro de `Bibliotecas.h`?

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** Link do circuito simulado (com as abas separadas).
*   **Printscreen:** Foto do editor com as abas `sketch.ino`, `Bibliotecas.h` e `_1_Phy.ino` abertas e funcionando.

---
*UC S122 - Internet das Coisas*
