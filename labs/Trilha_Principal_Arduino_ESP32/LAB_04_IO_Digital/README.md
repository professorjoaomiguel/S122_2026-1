# LAB 04: Entradas e Saídas Digitais

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Chaves e Alertas de I/O)

---

## 🚀 Como Iniciar?
Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Nesta prática, exploramos a interação básica entre o mundo físico e o digital: como o código lê um sinal externo (botão) e como aciona um atuador (LED).

---

## 🎯 Objetivos Técnicos
*   Configurar pinos como entrada (`INPUT_PULLUP`) e saída (`OUTPUT`).
*   Implementar estruturas de decisão (`if/else`).
*   Monitorar estados internos via **Serial Monitor**.

---

## 🧱 Setup de Hardware
Monte o circuito completo para todos os níveis:
*   **LED Externo + Resistor:** Pino 12.
*   **Pushbutton:** Pino 2 (conectado ao GND).

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: Saída Direta
O objetivo é apenas validar se o LED está funcionando.
```cpp
// [TAG] DEFINICOES
const int pinoLED = 12;

void setup() {
  // [TAG] SETUP_PINOS
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  // --- Etapa 1: Forçar Ligado ---
  digitalWrite(pinoLED, HIGH);
}
```

### 🚀 Passo 2: Leitura de Botão e Serial
Agora, acoplamos a entrada digital sem apagar o anterior. Use o Serial Monitor para "enxergar" o que o chip sente.
```cpp
// [TAG] DEFINICOES
const int pinoBotao = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLED, OUTPUT);
  // [TAG] SETUP_PINOS
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // --- Etapa 2: Escuta ---
  bool estado = digitalRead(pinoBotao);
  Serial.print("Estado do Botao: "); Serial.println(estado);
  delay(100);
}
```

### 🚀 Passo 3: Lógica de Controle
Finalmente, unimos a leitura à ação. O código agora toma uma decisão baseada no botão.
```cpp
void loop() {
  // --- Etapa 3: Decisao ---
  // [TAG] LOGICA_CONTROLE
  if (digitalRead(pinoBotao) == LOW) { // Botao pressionado
    digitalWrite(pinoLED, HIGH);
    Serial.println("Porta Aberta!");
  } else {
    digitalWrite(pinoLED, LOW);
  }
  delay(50);
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este circuito representa o **Sensor de Porta**:
- O Botão simula o contato magnético que detecta se a porta está fechada.
- O LED representa o Alerta Visual para o operador no campo.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de Máquinas Agrícolas de Ijuí/Panambi**, como um sensor de "presença de grãos" ou "porta de silo fechada" utiliza essa mesma lógica de I/O Digital?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Modifique o código para que o LED **pisque** rapidamente enquanto o botão estiver pressionado, em vez de apenas ficar aceso.
2.  O que aconteceria se esquecêssemos de definir o pino como `INPUT_PULLUP`?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Log:** Print do Serial Monitor exibindo as mensagens de detecção.

---
*UC S122 - Internet das Coisas*
