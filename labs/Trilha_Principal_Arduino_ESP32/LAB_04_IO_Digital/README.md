# LAB 04: Entradas e Saídas Digitais

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Chaves e Alertas de I/O)

---

### 🔌 Hardware Requerido
*   **Placa:** **ESP32 DevKit v4**
*   **Finalidade:** Processamento em borda (Edge), I/O avançado e IoT

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/esp32.svg" alt="ESP32 DevKit v4" width="160">
</p>

---

## 🚀 Como Iniciar?
1. Abra um projeto vazio para ESP32 (Arduino C++) no simulador: 🚀 <a href="https://wokwi.com/projects/new/esp32" target="_blank" title="Abrir em uma nova aba">**Projeto Vazio: ESP32 (Arduino)**</a>.
2. Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Nesta prática, exploramos a interação básica entre o mundo físico e o digital: como o código lê um sinal externo (botão) e como aciona um atuador (LED).

---

## 🎯 Objetivos Técnicos
*   Configurar pinos como entrada digital (`INPUT`) e saída (`OUTPUT`).
*   Compreender e montar o circuito elétrico de **resistor de Pull-Up externo**.
*   Implementar estruturas de decisão (`if/else`).
*   Monitorar estados internos via **Serial Monitor**.

---

## 🧱 Setup de Hardware
Monte o circuito completo para todos os níveis:
*   **LED Externo + Resistor:** Pino 12 (resistor limitador de 220Ω).
*   **Pushbutton:** Pino 2 (conectado ao GND e ao pino 3.3V através de um resistor físico de Pull-Up de 10kΩ).

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

### 🚀 Passo 2: O Fenômeno do Pino Flutuante (Floating State)
Antes de estabilizarmos o circuito, vamos experimentar na prática o que acontece se o hardware não tiver uma referência elétrica clara.

1.  **Montagem direta (Sem resistor):** Mantenha o botão conectado entre o **Pino 2** e o **GND** no Wokwi, mas remova/delete temporariamente o resistor de $10\text{ k}\Omega$ e as conexões dele com o 3.3V.
2.  **Código de Teste:** Configure o pino como entrada comum (modo `INPUT` sem pull-up):
```cpp
// [TAG] DEFINICOES
const int pinoBotao = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLED, OUTPUT);
  // [TAG] SETUP_PINOS
  pinMode(pinoBotao, INPUT); // Entrada comum
}

void loop() {
  // --- Etapa 2: Escuta ---
  bool estado = digitalRead(pinoBotao);
  Serial.print("Estado do Botao: "); Serial.println(estado);
  delay(50);
}
```
3.  **A Simulação e os Glitchs:** Inicie a simulação e abra o Serial Monitor.
    *   *O que acontece?* Mesmo sem pressionar o botão, o valor exibido na Serial fica oscilando aleatoriamente entre `0` e `1` (ou travado em um estado falso). Isso ocorre porque o pino está em **estado flutuante (Floating State / Alta Impedância)**, agindo como uma antena que capta o menor ruído eletrostático do ambiente.

---

### 🚀 Passo 3: Estabilizando com Pull-Up Externo (Circuito)
Para dar uma referência de tensão fixa ao pino quando o botão estiver aberto, usaremos um resistor de pull-up externo de hardware.

1.  **Conexão do Resistor de Pull-Up:** Reconecte o resistor de **$10\text{ k}\Omega$** no Wokwi:
    *   Um lado do resistor ligado ao **3.3V (VCC)** da placa.
    *   O outro lado do resistor ligado ao pino da chave (conectado ao **Pino 2**).
2.  **Lógica do Código:** Mantenha o código configurado como `INPUT` no setup.
3.  **Comportamento:**
    *   *Botão Solto:* O pino 2 recebe 3.3V diretamente do resistor de Pull-up. A leitura estabiliza em `1` (HIGH) de forma segura.
    *   *Botão Pressionado:* O contato se fecha com o GND. A corrente flui para a terra e o pino cai limpo para `0` (LOW).
```cpp
void loop() {
  // --- Etapa 3: Decisao com Pull-Up Externo ---
  if (digitalRead(pinoBotao) == LOW) { // Botao pressionado (aterrado)
    digitalWrite(pinoLED, HIGH);
    Serial.println("Porta Aberta! LED LIGADO.");
  } else {
    digitalWrite(pinoLED, LOW);
  }
  delay(50);
}
```

---

### 🚀 Passo 4: Evolução para o Pull-Up Interno (Firmware)
Para economizar peças e reduzir o custo físico da placa, os microcontroladores modernos possuem resistores internos que podem ser ativados via software.

1.  **Remoção Física:** Remova/delete novamente o resistor de $10\text{ k}\Omega$ e seus fios do simulador Wokwi.
2.  **Ativação via Software:** Modifique a inicialização do pino no setup de `INPUT` para **`INPUT_PULLUP`**:
```cpp
void setup() {
  Serial.begin(9600);
  pinMode(pinoLED, OUTPUT);
  // [TAG] SETUP_PINOS
  pinMode(pinoBotao, INPUT_PULLUP); // Aciona o resistor interno do ESP32 (aprox. 45k Ohms)
}
```
3.  **Resultado:** O circuito funciona de forma idêntica à etapa anterior (LOW quando pressionado e HIGH quando solto), mas sem a necessidade do resistor externo físico na matriz!

---

### 🚀 Passo 5: Código Consolidado Final (Versão Recomendada com Pull-Up Interno)
Ao final, o seu código estará completo e estruturado da seguinte forma (usando a vantagem do pull-up por firmware):
```cpp
// [TAG] DEFINICOES
const int pinoLED = 12;   // LED Vermelho Externo
const int pinoBotao = 2;  // Pushbutton (Sensor de Porta)

void setup() {
  Serial.begin(9600); // Inicializa a comunicacao Serial
  Serial.println("S122 - Sistema de Seguranca Iniciado!");
  
  // [TAG] SETUP_PINOS
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP); // Habilita o resistor interno de pull-up do ESP32
}

void loop() {
  // [TAG] LOGICA_CONTROLE
  bool estado = digitalRead(pinoBotao); // Le o estado lógico do botao
  
  if (estado == LOW) { // Botao pressionado = LOW
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
1.  **Por que nem sempre podemos depender do Pull-Up Interno?**
    *   *Resposta para estudo:* Os resistores integrados no silício possuem alta tolerância física e resistência muito elevada (em torno de $30\text{ k}\Omega$ a $50\text{ k}\Omega$ no ESP32). Em ambientes industriais com alto ruído eletromagnético (próximo a contatores e motores), essa alta resistência pode permitir o acoplamento de interferências eletromagnéticas. Nesses cenários, os engenheiros usam resistores físicos de Pull-Up externos menores (ex: $1\text{ k}\Omega$ ou $4.7\text{ k}\Omega$) para garantir a estabilidade do sinal. Além disso, chips legados ou pinos exclusivamente analógicos não possuem essa opção interna.
2.  **O que aconteceria se o pino ficasse em estado flutuante (Floating State)?** Explique o papel físico do resistor de Pull-Up (tanto interno quanto externo) para evitar leituras espúrias.
3.  **O que é o fenômeno do Bouncing (Ruído Mecânico)?** Por que chaves mecânicas geram dezenas de falsos contatos de liga/desliga nos microssegundos iniciais do toque e como o `delay(50)` (Debounce por Software) ajuda a mitigar isso?

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

