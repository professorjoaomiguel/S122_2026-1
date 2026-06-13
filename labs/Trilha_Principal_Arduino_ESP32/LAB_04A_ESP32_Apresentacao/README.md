# LAB 04B: Conheça o ESP32 — Do Arduino ao Chip de IoT

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Anatomia da Placa ESP32 e Primeiro Programa)

```mermaid
graph TD
    C[Nuvem / Cloud API] <-->|Protocolo MQTT| F[Fog Server / Gateway Local]
    F <-->|Protocolo HTTP/MQTT| E[Edge Node / ESP32]
    subgraph Camada Edge (Percepção Local)
        E --- S[Sensores / Atuadores]
    end
    style E fill:#f9f,stroke:#333,stroke-width:2px
```

---

### 🔌 Hardware Requerido
*   **Placa:** **ESP32 DevKit v4**
*   **Finalidade:** Apresentação da placa, diferenças do Arduino e primeiro programa no ESP32

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/esp32.svg" alt="ESP32 DevKit v4" width="200">
</p>

---

## 🚀 Como Iniciar?
1. Abra um projeto vazio para ESP32 (Arduino C++) no simulador: 🚀 <a href="https://wokwi.com/projects/new/esp32" target="_blank" title="Abrir em uma nova aba">**Projeto Vazio: ESP32 (Arduino)**</a>.
2. Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware em segundos.

---

## 🎯 Por que saímos do Arduino Uno e fomos para o ESP32?

O Arduino Uno foi o nosso ponto de partida — simples, didático, com 5V lógico e o microcontrolador ATmega328P de 8 bits. Ele é perfeito para aprender os fundamentos: pinos, código, lógica.

Mas a **Internet das Coisas** exige muito mais. Precisamos de um dispositivo que:

-   Consiga se **conectar ao Wi-Fi** sem hardware adicional.
-   Execute código **mais complexo e rápido** (algoritmos de sensores, JSON, protocolos de rede).
-   Tenha mais **memória, mais pinos e mais periféricos** integrados.
-   Consuma menos energia por ciclo de trabalho (modo sleep para baterias).

O **ESP32** foi criado pela Espressif Systems exatamente para isso. Ele não é só um microcontrolador — é um **SoC (System on Chip)** completo para IoT.

---

## 🔍 Anatomia do ESP32 DevKit v4 — Comparação com o Arduino Uno

```mermaid
graph LR
    subgraph Arduino Uno (Fundamentos)
        U_CPU[ATmega328P 8-bit]
        U_FREQ[16 MHz]
        U_RAM[2 KB SRAM]
        U_VOLT[5V Lógico]
        U_CONN[Sem Conectividade]
    end
    subgraph ESP32 DevKit v4 (Projetos IoT)
        E_CPU[Xtensa Dual-Core 32-bit]
        E_FREQ[240 MHz]
        E_RAM[520 KB SRAM]
        E_VOLT[3.3V Lógico]
        E_CONN[WiFi & Bluetooth Embutidos]
    end
```

| Característica | Arduino Uno | ESP32 DevKit v4 |
| :--- | :---: | :---: |
| **CPU** | ATmega328P (8-bit, 16 MHz) | Xtensa LX6 Dual-Core (32-bit, **240 MHz**) |
| **RAM** | 2 KB SRAM | **520 KB** SRAM |
| **Flash (Memória de Programa)** | 32 KB | **4 MB** |
| **Tensão Lógica** | 5V | **3,3V** ⚠️ |
| **Wi-Fi** | ❌ Não tem | ✅ **802.11 b/g/n integrado** |
| **Bluetooth** | ❌ Não tem | ✅ **BLE + Bluetooth Classic** |
| **Pinos Digitais** | 14 | **34+** |
| **Entradas Analógicas (ADC)** | 6 canais (10-bit) | **18 canais (12-bit)** |
| **Protocolos (I2C, SPI, UART)** | Limitado | **Múltiplos, configuráveis em qualquer pino** |
| **Touch Capacitivo** | ❌ | ✅ 10 pinos |
| **Preço aproximado** | ~R$ 50 | ~R$ 40-60 |

> [!IMPORTANT]
> **A diferença de tensão lógica é crítica!**
> O Arduino Uno opera com 5V. O ESP32 opera com **3,3V**. Conectar um sinal de 5V diretamente em um pino do ESP32 pode **queimar o chip permanentemente**. No Wokwi isso está protegido, mas na bancada física, sempre verifique os níveis de tensão!

---

## 🗺️ Mapa de Pinos do ESP32 DevKit v4

Diferente do Arduino Uno, onde os pinos são numerados sequencialmente (0 a 13), o ESP32 usa a **numeração GPIO** (General Purpose Input/Output):

| Região da Placa | Pinos | Observação |
| :--- | :--- | :--- |
| **GPIOs Digitais** | GPIO 0–39 | Entrada e saída digital |
| **ADC (Analógico)** | GPIO 32–39 (ADC1), GPIO 0, 2, 4, 12-15, 25-27 (ADC2) | ADC2 não funciona com Wi-Fi ativo! |
| **DAC (Saída Analógica Real)** | GPIO 25, 26 | Converte digital para tensão analógica |
| **Touch Capacitivo** | GPIO 0, 2, 4, 12–15, 27, 32, 33 | Detecta toque sem botão mecânico |
| **LED Interno** | **GPIO 2** | O LED azul embutido no DevKit v4 |
| **UART0** | TX=GPIO1, RX=GPIO3 | Serial padrão (Serial Monitor) |
| **I2C Padrão** | SDA=GPIO21, SCL=GPIO22 | Para displays, sensores I2C |
| **SPI Padrão** | MOSI=23, MISO=19, SCK=18, CS=5 | Para cartões SD, displays SPI |

> [!WARNING]
> **Pinos especiais a evitar como saída:** GPIO 0, 2 e 12 têm funções de boot. No momento em que a placa liga, esses pinos devem estar em estados específicos. Se um componente os mantiver no nível errado, o ESP32 pode **não inicializar** corretamente. Use-os como entrada ou saída somente depois do boot concluído.

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: O ambiente ESP32 no Wokwi

1.  Abra o <a href="https://wokwi.com/projects/new/esp32" target="_blank" title="Abrir em uma nova aba">**Projeto Vazio: ESP32 (Arduino)**</a>.
2.  Observe que o código gerado é quase idêntico ao do Arduino Uno!
3.  Identifique o LED azul pequeno na placa — ele está no **GPIO 2**.

### 🚀 Passo 2: Blink no ESP32 — Mesma lógica, nova placa

O Blink no ESP32 usa a **mesma estrutura** do Arduino, referenciando o pino **2** diretamente (que corresponde ao LED azul integrado da placa):

```cpp
// No ESP32 DevKit v4, o LED azul está no GPIO 2
void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH); // Liga o LED azul
  delay(500);
  digitalWrite(2, LOW);  // Desliga o LED azul
  delay(500);
}
```

4.  Clique em ▶️ **Play** e observe o LED **azul** piscando (diferente do amarelo no Uno!).

> [!NOTE]
> **Perceba a compatibilidade!** O mesmo código que piscava o LED no Arduino Uno roda no ESP32 sem nenhuma modificação. A plataforma Arduino abstraiu as diferenças de hardware. Isso é a força do ecossistema Arduino — você aprende uma vez e migra facilmente.

### 🚀 Passo 3: Usando o Serial Monitor no ESP32

O ESP32 tem a mesma comunicação serial. Mas atenção: a velocidade padrão recomendada é **115200 baud** (não 9600):

```cpp
void setup() {
  Serial.begin(115200); // ESP32 usa 115200 por padrão
  Serial.println("ESP32 iniciado! Ola, mundo IoT!");
  pinMode(2, OUTPUT);
}

void loop() {
  Serial.println("LED ligado!");
  digitalWrite(2, HIGH);
  delay(1000);

  Serial.println("LED desligado!");
  digitalWrite(2, LOW);
  delay(1000);
}
```

5.  Clique em ▶️ e abra o **Serial Monitor** (ícone de monitor na parte inferior do Wokwi).
6.  Configure a velocidade do monitor para **115200 baud**.
7.  Observe as mensagens aparecendo em tempo real sincronizadas com o LED!

### 🚀 Passo 4: Compare os números

Modifique o código para imprimir a frequência do clock da CPU — uma informação que o ESP32 conhece sobre si mesmo:

```cpp
void setup() {
  Serial.begin(115200);
  Serial.print("Frequencia do CPU: ");
  // Metodo padronizado da classe ESP
  Serial.print(ESP.getCpuFreqMHz());  
  Serial.println(" MHz");
  
  Serial.print("Memoria Heap livre: ");
  // Memoria RAM livre em bytes
  Serial.print(ESP.getFreeHeap());    
  Serial.println(" bytes");
}

void loop() {
  // Nada aqui por enquanto
}
```

8.  Rode e compare os resultados com o que você conhece do Arduino Uno (16 MHz / 2 KB RAM).

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, o ESP32 é o **nó de borda** (edge node): ele lê os sensores, processa os dados localmente e, nos próximos módulos, enviará os dados via Wi-Fi para o Fog Server. O Arduino Uno não teria como fazer isso sem hardware adicional.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL Coureiro-Calçadista do Vale do Sinos**, sensores industriais de rastreamento de produção precisam enviar dados em tempo real para sistemas ERP. Por que um microcontrolador com Wi-Fi integrado (como o ESP32) reduz o custo e a complexidade do projeto em relação a usar um Arduino + módulo Wi-Fi separado?

---

## 🧠 Desafio e Reflexão Técnica

### 🚨 Desafio: Explore os Recursos do ESP32

1.  **Dual-Core:** O ESP32 tem **dois núcleos** de processamento. Pesquise e imprima no Serial Monitor o número do núcleo em que o seu `loop()` está rodando usando `xPortGetCoreID()`. Em qual núcleo o código Arduino roda por padrão?

2.  **Frequência variável:** O ESP32 pode reduzir sua frequência de clock para economizar energia. Teste as funções `setCpuFrequencyMhz(80)` e `setCpuFrequencyMhz(240)` e observe se os tempos de `delay()` são afetados.

3.  **(Avançado)** O que é o **Watchdog Timer (WDT)** do ESP32 e por que sistemas embarcados precisam dele? Pesquise e escreva 3 linhas explicando em português.

### ❓ Reflexão Técnica (Obrigatória para Entrega)
1.  **Por que os pinos do ESP32 são de 3,3V e não de 5V** como no Arduino Uno? Qual o impacto disso ao conectar sensores e módulos que foram projetados para 5V?
2.  O ADC do Arduino Uno tem **10 bits de resolução** (valores de 0 a 1023). O ESP32 tem **12 bits** (0 a 4095). Em que situação prática essa diferença de resolução faz diferença para um sensor de temperatura?
3.  O ESP32 tem **dois núcleos** de processamento. O Arduino Uno tem **um**. Por que sistemas IoT com comunicação de rede se beneficiam de múltiplos núcleos?

---

## 📤 Entrega (Classroom)
Abra o **Documento de Entrega** anexado à sua atividade no Classroom e preencha os seguintes requisitos:
- [ ] **Link Wokwi:** Código com o teste de detecção do Dual-Core (Desafio) implementado.
- [ ] **Print:** Captura do Serial Monitor mostrando a frequência, memória e o ID do Core em que o loop está rodando.
- [ ] **Respostas (Reflexão):** Responda as 3 perguntas da seção Reflexão Técnica diretamente no documento da atividade .

---

## 🛣️ Próximo Passo
Agora que você conhece o ESP32, avance para o [**LAB 04B — Entradas e Saídas Digitais**](../LAB_04B_IO_Digital/), onde você vai conectar botões e LEDs externos ao ESP32 e aprender sobre resistores de Pull-Up!

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link do Simulador]
*   **Print:** Screenshot do Serial Monitor mostrando a frequência e memória do ESP32.
*   **Resposta:** Escreva a diferença entre GPIO 2 no ESP32 e pino 13 no Arduino Uno.

---
*UC S122 - Internet das Coisas*
