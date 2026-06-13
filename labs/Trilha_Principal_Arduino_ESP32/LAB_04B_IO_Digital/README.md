# LAB 04: Entradas e Saídas Digitais

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Chaves e Alertas de I/O)

```mermaid
graph TD
    C[Nuvem / Cloud API] <-->|Protocolo MQTT| F[Fog Server / Gateway Local]
    F <-->|Protocolo HTTP/MQTT| E[Edge Node / ESP32]
    subgraph Camada Edge (Percepção Local)
        E --- Btn[Sensor de Porta / Botao]
        E --- Led[Alerta Visual / LED]
    end
    style E fill:#f9f,stroke:#333,stroke-width:2px
```

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

> [!IMPORTANT]
> **Substituição de Código**: Ao realizar cada passo, substitua todo o código anterior (ou a função correspondente) por esta nova versão para evitar erros de funções duplicadas no compilador do Wokwi.

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

> [!IMPORTANT]
> **Substituição de Código**: Substitua todo o conteúdo do seu arquivo pelo código de teste a seguir. Note a inicialização de boas-vindas na Serial para continuidade lógica.

```cpp
// [TAG] DEFINICOES
const int pinoBotao = 2;

void setup() {
  Serial.begin(115200);
  Serial.println("S122 - Sistema de Seguranca Iniciado!");
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

    ```mermaid
    graph LR
        VCC[3.3V / VCC] --- R1[Resistor 10k]
        R1 --- Pino2[GPIO 2 / Sinal]
        Pino2 --- Button[Botao / Chave]
        Button --- GND[GND]
    ```

2.  **Lógica do Código:** Mantenha o setup idêntico ao anterior (com a inicialização da Serial e a mensagem de boas-vindas). Substitua a função `loop()` antiga por esta nova versão que implementa a decisão:

```cpp
void loop() {
  // --- Etapa 3: Decisao com Pull-Up Externo ---
  // Se o botao for pressionado (aterrado)
  if (digitalRead(pinoBotao) == LOW) {
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
2.  **Ativação via Software:** Substitua a função `setup()` por esta nova versão para ativar o pull-up interno e manter a mensagem de boas-vindas da Serial:

```cpp
void setup() {
  Serial.begin(115200);
  Serial.println("S122 - Sistema de Seguranca Iniciado!");
  pinMode(pinoLED, OUTPUT);
  // [TAG] SETUP_PINOS
  // Aciona pull-up interno do ESP32 (~45k Ohms)
  pinMode(pinoBotao, INPUT_PULLUP);
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
  Serial.begin(115200); // Inicializa a comunicacao Serial
  Serial.println("S122 - Sistema de Seguranca Iniciado!");
  
  // [TAG] SETUP_PINOS
  pinMode(pinoLED, OUTPUT);
  // Habilita o resistor interno de pull-up do ESP32
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // [TAG] LOGICA_CONTROLE
  // Le o estado logico do botao
  bool estado = digitalRead(pinoBotao);
  
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

### ❓ Reflexão Técnica (Obrigatória para Entrega)
1.  **Por que nem sempre podemos depender do Pull-Up Interno?**
    *   *Resposta para estudo:* Os resistores integrados no silício possuem alta tolerância física e resistência muito elevada (em torno de $30\text{ k}\Omega$ a $50\text{ k}\Omega$ no ESP32). Em ambientes industriais com alto ruído eletromagnético (próximo a contatores e motores), essa alta resistência pode permitir o acoplamento de interferências eletromagnéticas. Nesses cenários, os engenheiros usam resistores físicos de Pull-Up externos menores (ex: $1\text{ k}\Omega$ ou $4.7\text{ k}\Omega$) para garantir a estabilidade do sinal. Além disso, chips legados ou pinos exclusivamente analógicos não possuem essa opção interna.
2.  **O que aconteceria se o pino ficasse em estado flutuante (Floating State)?** Explique o papel físico do resistor de Pull-Up (tanto interno quanto externo) para evitar leituras espúrias.
3.  **O que é o fenômeno do Bouncing (Ruído Mecânico)?** Por que chaves mecânicas geram dezenas de falsos contatos de liga/desliga nos microssegundos iniciais do toque e como o `delay(50)` (Debounce por Software) ajuda a mitigar isso?

---

## 🛠️ Resolução de Problemas (Serial Monitor)

Se o Monitor Serial do ESP32 não estiver aparecendo ou exibindo dados no Wokwi, verifique este checklist:

1.  **Velocidade do Baud Rate (115200)**:
    Certifique-se de que seu código inicializa a comunicação com `Serial.begin(115200);`. O uso de velocidades como `9600` pode causar lentidão ou exibir caracteres corrompidos no ESP32.
2.  **Configuração de Exibição no `diagram.json`**:
    Para forçar a abertura imediata da aba Serial quando a simulação começar, adicione a configuração do monitor no seu [diagram.json](./diagram.json):
    ```json
    "serialMonitor": {
      "display": "always",
      "newline": "lf"
    }
    ```
3.  **Adicionar o Componente Físico (Alternativo)**:
    Se o terminal não abrir sozinho em alguns navegadores, você pode declarar o componente visual na seção `"parts"` do seu [diagram.json](./diagram.json):
    ```json
    {
      "type": "wokwi-serial-monitor",
      "id": "serial1",
      "top": 0,
      "left": 0
    }
    ```
4.  **Travamento do Loop (`setup` ou `loop`)**:
    Se o monitor serial parou de responder, verifique se seu código não está congelado em algum loop infinito (como um `while (!sensor.begin())`) antes de chegar nos comandos `Serial.println()`.

---

## 📂 Solução de Referência e Recursos
O professor disponibilizou uma pasta chamada [**`solucao_referencia/`**](./solucao_referencia/) neste laboratório. Ela contém o circuito e o código consolidados em pleno funcionamento, além da solução modular completa para os Desafios Técnicos propostos. Use-a para autoavaliação após finalizar sua própria tentativa!

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
Abra o **Documento de Entrega** anexado à sua atividade no Classroom e preencha os seguintes requisitos:
- [ ] **Link Wokwi:** Seu código deve conter o **Desafio 1 (Blink Condicional)** resolvido. O Desafio 2 (Latch) é bônus.
- [ ] **Log:** Captura de tela do Serial Monitor demonstrando a leitura de porta.
- [ ] **Respostas (Reflexão):** Responda as perguntas 2 e 3 da seção Reflexão Técnica diretamente no documento da atividade (a primeira pergunta já está respondida no roteiro).

---
*UC S122 - Internet das Coisas*

