# LAB 07: Lógica de Controle e Atuadores

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Lógica de Controle Autônomo e Histerese)

---

Nesta etapa final do Módulo 01, transformamos o sistema em uma entidade autônoma. O desafio é acoplar a **Ação** (Atuadores) em resposta ao que foi lido nos ganchos de **Percepção** (Sensores).

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

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, esta é a **Automação Climática**. O sistema agora possui instinto de preservação: ele "sente" o calor e "age" ligando a refrigeração antes que as plantas murcharem.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL Automotivo**, como um sistema similar controla a ventoinha do radiador para proteger o motor de fundir por calor excessivo?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Use a tag `[TAG] DISPLAY_LOCAL` (do LAB 06) para exibir o status "FAN: ON" ou "FAN: OFF" no LCD junto com a temperatura.
2.  Por que a modularização via ganchos (tags) facilitou a adição da ventoinha sem estragar a leitura do sensor?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Reflexão:** Explique a lógica de Histerese que você implementou.

---
*UC S122 - Internet das Coisas*
