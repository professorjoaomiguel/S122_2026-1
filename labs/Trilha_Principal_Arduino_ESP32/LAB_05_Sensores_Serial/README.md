# LAB 05: Sensores e Comunicação Serial

Aprendemos a coletar dados do ambiente usando sinais analógicos (LDR) e digitais (DHT22). A evolução aqui é o domínio da **escala**: de valores brutos para informações úteis.

---

## 🎯 Objetivos Técnicos
*   Leitura de Conversores Analógico-Digitais (ADC).
*   Uso de bibliotecas externas (DHT22).
*   Normalização de escalas com a função `map()`.

---

## 🧱 Setup de Hardware
Monte a base completa. Ela será usada em todos os níveis:
*   **DHT22 (Sensor Clima):** Pino 4.
*   **LDR (Luz):** Pino A0 (usando resistor de 10k como divisor).

---

## ⚙️ Workflow Passo a Passo

### Nível 1: O Mundo Analógico (LDR)
Começamos com o sensor mais simples. No código, foque apenas em ler o pino A0.

```cpp
// [TAG] DEFINICOES
void setup() {
  Serial.begin(9600);
  // [TAG] SETUP_INICIAL
}

void loop() {
  // --- Nível 1: Leitura Bruta ---
  int luzRaw = analogRead(A0);
  Serial.print("Luz Bruta: "); Serial.println(luzRaw);
  
  // [TAG] PROCESSAMENTO
  
  // [TAG] SAIDA_SERIAL
  
  delay(500);
}
```

### Nível 2: Normalização (Map)
Não apague o código anterior! Use a tag `[TAG] PROCESSAMENTO` para inserir a conversão.

```cpp
  // --- Nível 2: Conversao ---
  // Insira em [TAG] PROCESSAMENTO:
  int luzPerc = map(luzRaw, 0, 1023, 0, 100);
  
  // Atualize [TAG] SAIDA_SERIAL:
  Serial.print("Luz %: "); Serial.println(luzPerc);
```

### Nível 3: Integração DHT22
Agora, acoplamos a biblioteca de clima. Observe como as tags ajudam a saber onde cada parte deve entrar.

```cpp
// [TAG] DEFINICOES
#include "DHT.h"
DHT dht(4, DHT22); 

void setup() {
  Serial.begin(9600);
  // [TAG] SETUP_INICIAL
  dht.begin(); 
}

void loop() {
  // --- Nível 1 e 2: LDR ---
  int luzPerc = map(analogRead(A0), 0, 1023, 0, 100);
  
  // --- Nível 3: DHT22 ---
  // Insira apos as leituras anteriores:
  float temp = dht.readTemperature();
  
  // [TAG] SAIDA_SERIAL
  Serial.print("T: "); Serial.print(temp);
  Serial.print("C | Luz: "); Serial.print(luzPerc); Serial.println("%");
  
  delay(2000); // Intervalo exigido pelo DHT
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

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Use a tag `[TAG] PROCESSAMENTO` para adicionar um `if` que imprime "ALERTA" apenas se a temperatura for maior que 35°C.
2.  Por que as tags de organização são importantes quando o código começa a crescer?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Log:** Print do Serial Monitor com a telemetria completa.

---
*UC S122 - Internet das Coisas*
