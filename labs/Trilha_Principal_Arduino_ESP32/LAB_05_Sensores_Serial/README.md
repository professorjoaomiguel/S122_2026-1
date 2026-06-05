# LAB 05: Sensores e Comunicação Serial

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Leitura Física Analógica e Digital)

---

### 🔌 Hardware Requerido
*   **Placa:** **ESP32 DevKit v4**
*   **Finalidade:** Processamento em borda (Edge), I/O avançado e IoT

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/esp32.svg" alt="ESP32 DevKit v4" width="160">
</p>

---

## 🚀 Como Iniciar?
1. Abra um projeto vazio para ESP32 (Arduino C++) no simulador: 🚀 [**Projeto Vazio: ESP32 (Arduino)**](https://wokwi.com/projects/new/esp32).
2. Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Aprendemos a coletar dados do ambiente usando sinais analógicos (LDR) e digitais (DHT22). A evolução aqui é o domínio da **escala**: de valores brutos para informações úteis.

---

## 🎯 Objetivos Técnicos
*   Leitura de Conversores Analógico-Digitais (ADC).
*   Uso de bibliotecas externas (DHT22).
*   Normalização de escalas com a função `map()`.

---

## 🧱 Setup de Hardware
Monte a base completa. Ela será usada em todos os níveis:
*   **DHT22 (Sensor Clima):** Pino 15.
*   **LDR (Luz):** Pino analógico 34 (ADC1_CH6).

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: O Mundo Analógico (LDR)
Começamos com o sensor mais simples. No código, foque apenas em ler o pino A0.

```cpp
// [TAG] DEFINICOES
void setup() {
  Serial.begin(115200); // Uso recomendado de velocidade alta em ESP32
  // [TAG] SETUP_INICIAL
}

void loop() {
  // --- Etapa 1: Leitura Bruta ---
  int luzRaw = analogRead(34); // Pino 34 do ESP32
  Serial.print("Luz Bruta: "); Serial.println(luzRaw);
  
  // [TAG] PROCESSAMENTO
  
  // [TAG] SAIDA_SERIAL
  
  delay(500);
}
```

### 🚀 Passo 2: Normalização (Map)
Não apague o código anterior! Use a tag `[TAG] PROCESSAMENTO` para inserir a conversão.

```cpp
  // --- Etapa 2: Conversao ---
  // Insira em [TAG] PROCESSAMENTO:
  // Dica: O ADC do ESP32 tem resolução de 12 bits (0 a 4095)
  int luzPerc = map(luzRaw, 0, 4095, 0, 100);
  
  // Atualize [TAG] SAIDA_SERIAL:
  Serial.print("Luz %: "); Serial.println(luzPerc);
```

### 🚀 Passo 3: Integração DHT22
Agora, acoplamos a biblioteca de clima. Observe como as tags ajudam a saber onde cada parte deve entrar.

```cpp
// [TAG] DEFINICOES
#include "DHT.h"
DHT dht(15, DHT22); // Pino 15 para o DHT22

void setup() {
  Serial.begin(115200);
  // [TAG] SETUP_INICIAL
  dht.begin(); 
}

void loop() {
  // --- Etapa 1 e 2: LDR ---
  int luzPerc = map(analogRead(34), 0, 4095, 0, 100);
  
  // --- Etapa 3: DHT22 ---
  float temp = dht.readTemperature();
  
  // [TAG] SAIDA_SERIAL
  Serial.print("T: "); Serial.print(temp);
  Serial.print("C | Luz: "); Serial.print(luzPerc); Serial.println("%");
  
  delay(2000); // Intervalo exigido pelo DHT
}
```

### 🚀 Passo 4: Código Consolidado Final
Ao final de todos os passos, o seu código estará completo e estruturado da seguinte forma, integrando todas as fases de leitura e normalização:
```cpp
// [TAG] DEFINICOES
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  // [TAG] SETUP_INICIAL
  dht.begin();
  Serial.println("S122 - Estufa IoT: Sistema de Leituras Iniciado!");
}

void loop() {
  // --- Etapa 1 e 2: LDR ---
  int luzRaw = analogRead(LDRPIN);
  // [TAG] PROCESSAMENTO
  int luzPerc = map(luzRaw, 0, 4095, 0, 100); // ADC do ESP32 vai até 4095
  
  // --- Etapa 3: DHT22 ---
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro ao ler dados do DHT22!");
    delay(2000);
    return;
  }

  // [TAG] SAIDA_SERIAL
  Serial.printf("Luz: %d%% | Temp: %.1f C | Umid: %.1f %%\n", luzPerc, temp, umid);
  
  delay(2000); // Intervalo necessário entre as leituras do sensor
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este é o módulo de **Monitoramento Ambiental**. O DHT22 vigia a saúde térmica e o LDR decide se as plantas precisam de suplementação de luz.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de Vitivinicultura da Serra Gaúcha**, como o monitoramento de temperatura e umidade em tempo real pode evitar que uma safra de uva seja perdida por geada?

---

## 🧠 Atividades de Desafio Prático e Reflexão
Agora que você domina a leitura de sensores analógicos e digitais, aplique seu conhecimento em um cenário crítico de IoT!

### 🚨 Desafio: Alerta de Segurança e Mapeamento
*   **Missão:** Use a tag `[TAG] PROCESSAMENTO` para adicionar uma lógica condicional (`if`) que detecta condições críticas de estufa:
    1.  Se a temperatura for **maior que 35°C**, imprima uma mensagem de alerta no Monitor Serial: `[ALERTA DE SUPERAQUECIMENTO!] 🚨`.
    2.  Opcionalmente, observe a taxa de atualização dos sensores. Como o DHT22 precisa de $2\text{ s}$ para atualizar, o que acontece se tentarmos ler o sensor a cada $100\text{ ms}$?

### ❓ Reflexão Técnica
1.  **Por que as tags de organização (como `[TAG] DEFINICOES`) são fundamentais** quando o código começa a crescer?
2.  Por que o comando `analogRead` no ESP32 retorna valores de $0$ a $4095$, enquanto no Arduino Uno clássico retornava de $0$ a $1023$? Como isso impacta a precisão das nossas medições de luminosidade?

---

## 📂 Solução de Referência e Recursos
O professor disponibilizou uma pasta chamada [**`solucao_referencia/`**](./solucao_referencia/) neste laboratório. Ela contém o circuito físico configurado e a lógica 100% implementada para o laboratório, bem como a resolução do desafio crítico. Use-a para validar sua lógica depois de tentar resolver sozinho!

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link do Simulador]
*   **Log:** Captura de tela do Serial Monitor exibindo a telemetria com temperatura, umidade e luminosidade normalizadas.

---
*UC S122 - Internet das Coisas*
