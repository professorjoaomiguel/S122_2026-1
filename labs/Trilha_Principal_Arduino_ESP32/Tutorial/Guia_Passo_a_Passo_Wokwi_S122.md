# Guia Definitivo: Monitoramento IoT Progressivo com Arduino e Wokwi

Este guia foi desenvolvido para a Unidade Curricular **S122 - Internet das Coisas** da Faculdade de Tecnologia SENAI Porto Alegre. O objetivo é levar você do zero absoluto até a criação de um sistema de monitoramento inteligente, utilizando a metodologia **PBL (Problem-Based Learning)**.

---

## **Nível -1: Conhecendo o Simulador Wokwi**

Antes de começar a programar, você precisa entender como operar o laboratório virtual.

1.  **Criando o Projeto:**
    *   Acesse [wokwi.com](https://wokwi.com).
    *   Escolha **Arduino Uno**.
2.  **A Interface:**
    *   **Lado Esquerdo:** Editor de Código (`sketch.ino`).
    *   **Lado Direito:** Área de Simulação (Hardware).
    *   **Botão Azul (+):** Adiciona novos componentes.
    *   **Botão Play (Verde):** Inicia a simulação.
3.  **Como Conectar Fios:**
    *   Clique em um terminal de um componente e arraste até o pino desejado no Arduino.
    *   Para mudar a cor do fio, clique nele após a conexão e escolha uma opção no menu superior.
    *   **Dica Profissional:** Utilize sempre **Preto** para GND e **Vermelho** para 5V/VCC. Essa padronização evita confusões em circuitos complexos.

---

## **Nível 0: Sinal Vital (Blink LED Interno)**

**Objetivo:** Validar o fluxo de transferência (*upload*) do seu código para o hardware simulado.

### **1. Montagem Física**
Neste nível, utilizaremos o LED integrado à placa do Arduino (marcado com a letra **L**). Ele está conectado internamente ao **Pino 13**.

### **2. O Código**
Apague o código padrão e digite (evite apenas copiar para fixar a sintaxe):

```cpp
void setup() {
  pinMode(13, OUTPUT); // Configura o pino 13 como SAÍDA
}

void loop() {
  digitalWrite(13, HIGH); // Liga o LED (Nível Lógico ALTO)
  delay(100);             // Aguarda 100ms (Pulso rápido)
  digitalWrite(13, LOW);  // Desliga o LED (Nível Lógico BAIXO)
  delay(900);             // Aguarda 900ms
}
```

---

## **Nível 1: Sinalização Semafórica (Digital Out)**

**Objetivo:** Controlar múltiplos componentes e gerenciar o tempo de forma sequencial.

### **1. Novos Componentes**
*   3 LEDs (Verde, Amarelo e Vermelho).
*   3 Resistores de 220 Ω.

### **2. Montagem Passo a Passo (Atenção aos Terminais!)**
1.  Adicione 3 LEDs. Clique em cada um para configurar as cores correspondentes.
2.  **Identificação dos Terminais:**
    *   **Cátodo (Perna Reta/Curta):** Lado Negativo. Conecte ao resistor e este ao **GND**.
    *   **Ânodo (Perna Torta/Longa):** Lado Positivo. Conecte aos pinos digitais.
3.  **Pinagem:** Verde no **10**, Amarelo no **11** e Vermelho no **12**.

### **3. O Código**
```cpp
const int VERDE = 10;
const int AMARELO = 11;
const int VERMELHO = 12;

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERMELHO, OUTPUT);
}

void loop() {
  // Verde ligado por 3 segundos
  digitalWrite(VERDE, HIGH); delay(3000); digitalWrite(VERDE, LOW);
  
  // Amarelo ligado por 1 segundo
  digitalWrite(AMARELO, HIGH); delay(1000); digitalWrite(AMARELO, LOW);
  
  // Vermelho ligado por 3 segundos
  digitalWrite(VERMELHO, HIGH); delay(3000); digitalWrite(VERMELHO, LOW);
}
```

---

## **Nível 2: O Gatilho (Digital In - Pushbutton)**

**Objetivo:** Interromper o fluxo do código por meio de um evento externo.

### **1. Montagem**
*   Adicione um **Pushbutton**. Conecte um terminal ao **Pino 2** e o terminal oposto ao **GND**.

### **2. O Código (Entendendo o PULLUP)**
Utilizaremos a configuração `INPUT_PULLUP`. Isso significa que, em estado de repouso, o pino lerá **HIGH (1)**. Quando o botão for pressionado, o pino será conectado ao terra e lerá **LOW (0)**.

```cpp
const int BOTAO = 2;

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERMELHO, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BOTAO) == LOW) { // O botão foi pressionado!
    // Insira aqui a lógica do semáforo do Nível 1
    digitalWrite(VERDE, HIGH); delay(1000); digitalWrite(VERDE, LOW);
    digitalWrite(AMARELO, HIGH); delay(500); digitalWrite(AMARELO, LOW);
    digitalWrite(VERMELHO, HIGH); delay(1000); digitalWrite(VERMELHO, LOW);
  }
}
```

---

## **Nível 3: Variabilidade Analógica (ADC - Potenciômetro)**

**Objetivo:** Ler valores variáveis de sensores analógicos e convertê-los em dados úteis.

### **1. Montagem**
*   Conecte as extremidades do potenciômetro ao **5V** e ao **GND**. O terminal central (cursor) deve ser conectado ao pino **A0** (Analógico).

### **2. O Código (Mapeamento de Dados)**
```cpp
void setup() {
  Serial.begin(9600); // Inicia a Comunicação Serial
}

void loop() {
  int leitura = analogRead(A0); // Valor bruto de 0 a 1023
  int porcentagem = map(leitura, 0, 1023, 0, 100); // Converte para escala de 0-100%
  
  Serial.print("Nivel: "); 
  Serial.print(porcentagem); 
  Serial.println("%");
  delay(100);
}
```

---

## **Nível 4: Interface Homem-Máquina (LCD I2C)**

**Objetivo:** Exibir informações localmente, eliminando a dependência do computador.

### **1. Montagem**
*   **GND** -> GND | **VCC** -> 5V | **SDA** -> **A4** | **SCL** -> **A5**.

### **2. ⚠️ CONFIGURAÇÃO OBRIGATÓRIA (LEIA ATENTAMENTE!)**
O código **NÃO FUNCIONARÁ** se a biblioteca não for instalada corretamente:
1.  Clique no ícone de **Biblioteca** (*Library Manager*) no menu lateral esquerdo.
2.  Clique no botão **(+)** para adicionar uma nova biblioteca.
3.  Pesquise por **`LiquidCrystal I2C`** (desenvolvida por Frank de Brabander) e selecione-a para instalação.

---

## **Nível 5: Sensoriamento IoT (DHT22)**

**Objetivo:** Manipular protocolos digitais e tratar dados de precisão (Temperatura e Umidade).

### **1. Montagem e Biblioteca**
*   **VCC** -> 5V | **GND** -> GND | **SDA (Data)** -> **Pino 4**.
*   **Instalação:** Adicione a biblioteca **`DHT sensor library`** (da Adafruit) por meio do menu lateral.

### **2. Nota de Desempenho (Dica Acadêmica)**
O sensor DHT22 possui um tempo de resposta lento. É necessário um intervalo de, no mínimo, **2 segundos** entre as leituras. Se o sistema parecer não responder, certifique-se de que o tempo de espera está sendo respeitado no código.

```cpp
#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void loop() {
  float t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp: "); 
  lcd.print(t); 
  lcd.print("C  ");
  delay(2000); // Intervalo técnico mandatório para o sensor
}
```

---

## **Nível 6: Sistema Final e Arquitetura M3F**

**Objetivo:** Integrar todos os periféricos em um sistema de decisão autônomo (atuação na camada de *Edge Device*).

### **Lógica de Automação:**
*   **Temperatura < 25°C:** Ativa LED Verde | LCD exibe: "Status: OK".
*   **Temperatura entre 25°C e 30°C:** Ativa LED Amarelo | LCD exibe: "Status: Atencao".
*   **Temperatura > 30°C:** Ativa LED Vermelho | LCD exibe: "ALERTA CRITICO".

---

## **🚀 Próximos Passos: Rumo à Nuvem (M3F)**

Parabéns! Você concluiu a **Camada de Percepção** (Sensores/Atuadores) e o **Processamento Local** (*Edge*). Dentro da arquitetura **M3F (Multilayer Fog/Cloud)**, os próximos desafios envolvem a **Camada de Transporte**:

1.  **Conectividade:** Como transmitir estes dados do LCD para um Broker MQTT?
2.  **Persistência:** Como armazenar o histórico de telemetria em um banco de dados InfluxDB?
3.  **Visualização Remota:** Como construir um dashboard profissional no Grafana a partir destes dados?

---

## **Dados Institucionais**

**Instituição:** Faculdade SENAI Porto Alegre  
**Professor:** João Miguel Lac Roehe  
**Unidade Curricular:** S122 - Internet das Coisas  
**Contato para Suporte:** [t.me/professorjoaomiguel](http://t.me/professorjoaomiguel)
