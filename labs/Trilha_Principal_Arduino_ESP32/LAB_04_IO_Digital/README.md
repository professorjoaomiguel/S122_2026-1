# LAB 04: Entradas e Saídas Digitais

Nesta prática, exploramos a interação básica entre o mundo físico e o digital: como o código lê um sinal externo (botão) e como aciona um atuador (LED).

---

## 🎯 Objetivos Técnicos
*   Configurar pinos como entrada (`INPUT_PULLUP`) e saída (`OUTPUT`).
*   Implementar estruturas de decisão (`if/else`).
*   Monitorar estados internos via **Serial Monitor**.

---

## 🧱 Setup de Hardware
*   **LED Externo + Resistor:** Pino 12.
*   **Pushbutton:** Pino 2 (conectado ao GND).

---

## ⚙️ Workflow Passo a Passo

### Nível 1: Saída Direta
1.  Escreva um código que apenas liga o LED no pino 12.
2.  Valide se a fiação está correta no Wokwi.

### Nível 2: Leitura de Botão e Serial
1.  Configure o pino 2 como `INPUT_PULLUP`.
2.  Envie para o Serial Monitor o valor lido do pino (`HIGH` ou `LOW`).
3.  **Reflexão:** Por que o botão retorna `LOW` quando pressionado?

### Nível 3: Lógica de Controle
1.  Integre os níveis anteriores: Se o botão for pressionado, o LED liga. Caso contrário, desliga.

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  bool pressionado = (digitalRead(2) == LOW);
  
  if (pressionado) {
    digitalWrite(12, HIGH);
    Serial.println("Porta Aberta!");
  } else {
    digitalWrite(12, LOW);
  }
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
