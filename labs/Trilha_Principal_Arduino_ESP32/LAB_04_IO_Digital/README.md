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

### 🚀 Passo 4: Código Consolidado Final
Ao final das etapas anteriores, o seu código estará completo e estruturado da seguinte forma, integrando todas as fases:
```cpp
// [TAG] DEFINICOES
const int pinoLED = 12;   // LED Vermelho Externo
const int pinoBotao = 2;  // Pushbutton (Sensor de Porta)

void setup() {
  Serial.begin(9600); // Inicializa a comunicacao Serial
  Serial.println("S122 - Sistema de Seguranca Iniciado!");
  
  // [TAG] SETUP_PINOS
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP); // Habilita o resistor interno do ESP32
}

void loop() {
  // [TAG] LOGICA_CONTROLE
  bool estado = digitalRead(pinoBotao); // Le o estado lógico do botao
  
  if (estado == LOW) { // Botao conecta ao GND, ou seja, pressionado = LOW
    digitalWrite(pinoLED, HIGH);
    Serial.println("Porta ABERTA! LED LIGADO 🔴");
  } else {
    digitalWrite(pinoLED, LOW);
  }
  
  delay(50); // Atraso de estabilizacao (Debounce)
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este circuito representa o **Sensor de Porta**:
- O Botão simula o contato magnético que detecta se a porta da estufa está fechada.
- O LED representa o Alerta Visual para o operador de campo.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de Máquinas Agrícolas de Ijuí/Panambi**, como um sensor de "presença de grãos" ou "porta de silo fechada" utiliza essa mesma lógica de I/O Digital?

---

## 🧠 Atividades de Desafio Prático e Reflexão
Agora que você domina as entradas e saídas digitais básicas, aplique seu conhecimento em cenários reais de IoT e automação!

### 🚨 Desafio 1: O Alerta Visual Intermitente (Blink Condicional)
*   **Contexto:** Em sistemas industriais de segurança, se uma barreira física é violada, o LED de alerta não deve apenas ficar estático, ele precisa **piscar rapidamente** para chamar a atenção visual imediata do operador.
*   **Missão:** Modifique o código para que, enquanto a porta estiver aberta (botão pressionado), o LED Vermelho **pisque** em uma frequência de **5 vezes por segundo** (100ms ligado / 100ms desligado). Quando a porta for fechada, o LED deve apagar instantaneamente.

### 🛡️ Desafio 2 (Avançado): O Alarme com Trava de Segurança (Latch) e Reset por Tempo
*   **Contexto:** Em segurança patrimonial, se um invasor abrir uma porta e fechá-la rapidamente, um alarme simples desligará e ninguém notará. Por isso, usamos um alarme com **trava (latch)** que precisa de uma confirmação humana para desligar.
*   **Missão:**
    1.  Adicione um segundo LED ao seu circuito (ex: LED Amarelo no **pino 14**).
    2.  Quando a porta for aberta apenas uma vez (botão pressionado), o alarme é travado: o LED Vermelho e o LED Amarelo começam a **piscar de forma alternada** sem parar.
    3.  Mesmo que a porta seja fechada (botão solto), os LEDs devem continuar piscando!
    4.  **Reset de Segurança:** Para resetar o alarme e desligar os LEDs, o operador deve manter o botão pressionado continuamente por **3 segundos**. Apenas após esse tempo o alarme desarma.

### ❓ Reflexão Técnica
1.  **O que aconteceria se esquecêssemos de definir o pino como `INPUT_PULLUP` no `setup()`?** Se declarássemos apenas `INPUT` e não conectássemos resistores físicos externos, qual comportamento de leitura aleatória seria observado no pino 2 (*Floating State*)?
2.  **O que é o fenômeno do Bouncing (Ruído Mecânico)?** Por que botões físicos geram dezenas de falsos sinais de liga/desliga nos microssegundos iniciais de toque e como a nossa instrução `delay(50)` no loop ajuda a mitigar isso (Debounce por Software)?

---

## 📂 Solução de Referência e Recursos
O professor disponibilizou uma pasta chamada [**`solucao_referencia/`**](./solucao_referencia/) neste laboratório. Ela contém o circuito e o código consolidados em pleno funcionamento, além da solução modular completa para os Desafios Técnicos propostos. Use-a para autoavaliação após finalizar sua própria tentativa!

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link do Simulador]
*   **Log:** Captura de tela do Serial Monitor demonstrando os logs de detecção da porta.

---
*UC S122 - Internet das Coisas*

