# LAB 03B: Conheça o Arduino Uno — Do Circuito ao Microcontrolador

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Anatomia da Placa e Primeiro Programa)

---

### 🔌 Hardware Requerido
*   **Placa:** **Arduino Uno Rev3**
*   **Finalidade:** Apresentação da placa, pinagem e primeiro programa embarcado

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/arduino-uno.svg" alt="Arduino Uno Rev3" width="220">
</p>

---

## 🚀 Como Iniciar?
1. Abra um projeto vazio para Arduino Uno no simulador: 🚀 [**Projeto Vazio: Arduino Uno**](https://wokwi.com/projects/new/arduino-uno).
2. Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware em segundos.

---

## 🎯 Por que saímos do circuito passivo e fomos para o microcontrolador?

Nos Labs 01 e 02, toda a "inteligência" do sistema dependia de **você**: você escolhia quais chaves abrir, você calculava as resistências, você entendia manualmente qual porta lógica estava operando.

O problema é que **circuitos puramente passivos não tomam decisões sozinhos**. Eles não sentem a temperatura do ambiente e abrem uma válvula. Eles não detectam um invasor e disparam um alarme. Eles não enviam dados para a nuvem quando o solo está seco.

Para isso, precisamos de um componente capaz de **executar instruções programadas**: o **microcontrolador**. E o primeiro da nossa jornada é o **Arduino Uno**.

---

## 🔍 Anatomia do Arduino Uno Rev3

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/arduino-uno.svg" alt="Diagrama do Arduino Uno" width="320">
</p>

| Região | O que é? | Para que serve? |
| :--- | :--- | :--- |
| **Microcontrolador ATmega328P** | O "cérebro" da placa — é o chip preto grande no centro | Executa as instruções do seu código linha por linha |
| **Pinos Digitais (0–13)** | Fileira de 14 pinos na parte superior | Recebem (INPUT) ou enviam (OUTPUT) sinais `HIGH`/`LOW` (0 ou 5V) |
| **Pinos Analógicos (A0–A5)** | Fileira de 6 pinos na parte inferior | Leem tensões entre 0–5V e convertem para valor 0–1023 (ADC) |
| **GND e 5V/3.3V** | Pinos de alimentação | Fornecem referência de terra e tensão para os componentes externos |
| **Pino 13 (LED "L")** | Pino especial ligado ao LED embutido "L" | Permite testes sem nenhum componente externo |
| **USB (Tipo B)** | Conector quadrado lateral | Carrega o programa e fornece comunicação serial com o computador |
| **Conector de Alimentação** | Conector P4 | Alimentação externa por fonte de 7–12V (sem o PC) |

> [!TIP]
> **No Wokwi**, o Arduino Uno virtual tem exatamente o mesmo comportamento elétrico do físico. O LED amarelo `"L"` na placa corresponde ao pino digital **13**. É ele que vamos piscar primeiro!

---

## 🌐 O que é o "Blink"? — O Hello World dos Sistemas Embarcados

Em programação de computadores, o primeiro programa ensinado é o famoso **"Hello, World!"** — um código mínimo que exibe uma mensagem na tela, confirmando que o ambiente de desenvolvimento funciona do início ao fim.

Em **sistemas embarcados**, não temos (necessariamente) uma tela. Mas temos LEDs. Por isso, o equivalente do "Hello, World!" em hardware é o **Blink**: um LED que pisca sozinho.

O Blink confirma:
-   ✅ O microcontrolador está recebendo energia (alimentado).
-   ✅ O código foi compilado sem erros e gravado corretamente na memória flash.
-   ✅ O clock interno está oscilando (o "coração" do chip está batendo).
-   ✅ O pino de saída responde aos comandos do código.

> [!IMPORTANT]
> Sempre que você receber uma placa nova, um projeto novo ou tiver dúvidas se o hardware está funcionando, **execute um Blink primeiro**. É o diagnóstico número 1 de qualquer desenvolvedor embarcado.

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: Reconheça o ambiente Wokwi
1.  Abra o [**Projeto Vazio: Arduino Uno**](https://wokwi.com/projects/new/arduino-uno).
2.  Observe o painel esquerdo: é o **editor de código** (arquivo `.ino`).
3.  Observe o painel direito: é o **simulador de hardware** (diagrama interativo).
4.  Identifique o LED amarelo `"L"` na placa simulada — ele está ao lado do pino **13**.

### 🚀 Passo 2: Entenda a estrutura mínima de um programa Arduino

Todo programa Arduino tem exatamente **duas funções obrigatórias**:

```cpp
void setup() {
  // Executada UMA ÚNICA VEZ ao ligar/resetar a placa.
  // Use para configurações iniciais: definir pinos, iniciar comunicação serial, etc.
}

void loop() {
  // Executada em LAÇO INFINITO enquanto a placa tiver energia.
  // Aqui fica a lógica principal do seu programa.
}
```

> [!NOTE]
> **Por que `setup()` e `loop()`?** Diferente de um programa de computador que termina, um microcontrolador embarcado **nunca pode parar**. Ele deve monitorar sensores, reagir a eventos e controlar atuadores indefinidamente enquanto estiver ligado. O `loop()` garante isso.

### 🚀 Passo 3: O Primeiro Blink — Piscar o LED interno

Digite (não copie — digitar ajuda na memorização) o código abaixo no editor:

```cpp
void setup() {
  // Pino 13 está conectado ao LED "L" da placa.
  // OUTPUT significa que o pino vai ENVIAR sinal (acionar algo).
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH); // Liga o LED (envia 5V no pino 13)
  delay(1000);            // Aguarda 1000 milissegundos (1 segundo)
  digitalWrite(13, LOW);  // Desliga o LED (envia 0V no pino 13)
  delay(1000);            // Aguarda mais 1 segundo
}
```

4.  Clique no botão ▶️ **Play** do Wokwi para iniciar a simulação.
5.  Observe o LED amarelo `"L"` piscando a cada 1 segundo.

**Parabéns! Você acabou de executar o Hello World do hardware embarcado.**

### 🚀 Passo 4: Experimente alterar o tempo

Mude o valor de `delay(1000)` para `delay(200)` e clique em ▶️ novamente.

-   O que aconteceu com a frequência de piscada?
-   O que aconteceria se você colocasse `delay(0)` ou removesse o `delay`?

### 🚀 Passo 5: Use a constante `LED_BUILTIN`

O Arduino define uma constante especial chamada `LED_BUILTIN` que aponta para o pino do LED interno (pino 13 no Uno). É uma boa prática usá-la no lugar do número fixo:

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Mais legível e portável entre placas!
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
```

> [!TIP]
> Se você usar esse código em um **ESP32** futuramente, a constante `LED_BUILTIN` apontará automaticamente para o pino correto daquela placa. Seu código fica **portável** entre hardware diferente sem precisar alterar os números manualmente!

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este LED representa o **Sinal Vital (Heartbeat)** do sistema. Operadores de campo sabem que se o LED parar de piscar, algo travou no microcontrolador e é hora de investigar.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL Moveleiro de Bento Gonçalves**, as máquinas CNC possuem CLPs (Controladores Lógicos Programáveis) que, assim como o Arduino, executam instruções em laço contínuo. Por que é crítico ter um sinal de "heartbeat" (Watchdog Timer) em máquinas industriais?

---

## 🧠 Desafio e Reflexão Técnica

### 🚨 Desafio: A Marcação de Compasso

1.  **Compasso 4/4 a 60 BPM (batidas por minuto):** Calcule o intervalo entre cada batida e programe o LED para piscar exatamente nessa frequência.
2.  **Compasso 4/4 a 120 BPM:** Dobre a velocidade. Quantas linhas você precisa alterar?
3.  **(Avançado)** Refatore o código para que você possa mudar o BPM alterando **uma única variável** no topo do código. Dica: `int bpm = 60;` e então calcule o `delay` a partir disso.

### ❓ Reflexão Técnica (Obrigatória para Entrega)
1.  O que acontece se você colocar `pinMode()` dentro do `loop()` em vez do `setup()`? O LED continuará piscando? Por que isso é ineficiente?
2.  `digitalWrite(13, HIGH)` envia 5V no pino. Qual é a corrente máxima que o pino digital do Arduino Uno suporta? Por que isso importa ao conectar um LED externo sem resistor limitador?
3.  Qual seria o comportamento do seu programa se o `delay()` não existisse? O LED chegaria a apagar visualmente?

---

## 📤 Entrega (Classroom)
Abra o **Documento de Entrega** anexado à sua atividade no Classroom e preencha os seguintes requisitos:
- [ ] **Link Wokwi:** O código deve conter a alteração pedida no **Desafio do Metrônomo (120 BPM)**.
- [ ] **Print:** Screenshot do simulador com o LED "L" aceso ou piscando.
- [ ] **Respostas (Reflexão):** Responda as 3 perguntas da seção Reflexão Técnica diretamente no documento da atividade .

---

## 🛣️ Próximo Passo
Após dominar o Blink, avance para o [**LAB 03B — O Primeiro Sinal (SOS Blink Avançado)**](../LAB_03B_Blink_Base/), onde você aplicará esse conhecimento em um desafio real de código Morse!

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link do Simulador]
*   **Print:** Screenshot do simulador com o LED "L" piscando.
*   **Resposta:** Calcule e informe o `delay` correto para 120 BPM.

---
*UC S122 - Internet das Coisas*
