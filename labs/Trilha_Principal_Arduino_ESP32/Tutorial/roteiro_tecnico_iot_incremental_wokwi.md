# **Roteiro Técnico: Monitoramento IoT Progressivo (Arduino Uno)**

Este guia detalha a execução de sete níveis de aprendizado em IoT. A montagem é **cumulativa**: componentes adicionados em fases anteriores devem ser mantidos no circuito.

## **Nível 0: Configuração de Ambiente e Sinal Vital (Blink)**

**Objetivo:** Validar a comunicação entre firmware e hardware simulado.

**Instruções de Execução:**

1. Acesse o **Wokwi** e crie um novo projeto **Arduino Uno**.  
2. No editor de código, identifique as funções obrigatórias: setup() (configuração inicial) e loop() (execução cíclica).  
3. Utilize o **Pino 13**, que possui um LED interno (L) para diagnóstico.  
4. **Comando:** Use pinMode(13, OUTPUT) e alterne o estado com digitalWrite.

**Entregáveis:**

* **Link:** URL do projeto salvo.  
* **Mídia:** Printscreen da aba de código lateral ao lado do simulador em execução.  
* **Atividade:** Modifique o tempo para um pulso rápido (100ms ligado / 900ms desligado).

## **Nível 1: Sinalização por Múltiplas Saídas (Semaforo)**

**Objetivo:** Gerenciar estados lógicos em múltiplos pinos digitais.

**Instruções de Montagem:**

1. Insira **3 LEDs** (Verde, Amarelo, Vermelho).  
2. Conecte o **Cátodo** (terminal reto) de cada LED ao **GND** através de um resistor de **220 ohms**.  
3. Conecte os **Ânodos** aos pinos **10, 11 e 12**.  
4. **Dica:** Utilize fios com cores correspondentes aos LEDs para facilitar a depuração.

**Entregáveis:**

* **Diagrama:** Printscreen da fiação organizada na protoboard virtual.  
* **Atividade:** Implementar o código base de alternância temporal (3s Verde, 1s Amarelo, 3s Vermelho).

## **Nível 2: Gestão de Entradas Digitais (Pushbutton)**

**Objetivo:** Interromper fluxos lógicos através de eventos externos.

**Instruções de Montagem:**

1. Conecte um terminal do **Pushbutton** ao **Pino 2** e o outro ao **GND**.  
2. No código, utilize INPUT\_PULLUP no pinMode. Isso ativa o resistor interno do Arduino, evitando leituras flutuantes.  
3. O pino lerá HIGH quando em repouso e LOW quando pressionado.

**Entregáveis:**

* **Código:** Bloco if (digitalRead(2) \== LOW) para iniciar a sequência do Nível 1\.  
* **Atividade:** O sistema só deve iniciar o ciclo se o botão for pressionado.

## **Nível 3: Aquisição de Dados Analógicos (ADC)**

**Objetivo:** Compreender a conversão de grandezas físicas (tensão) em valores digitais.

**Instruções de Montagem:**

1. Posicione o **Potenciômetro**. Terminais das extremidades em **5V** e **GND**.  
2. Terminal central (cursor) conectado ao pino **A0**.  
3. Utilize analogRead(A0) para obter valores entre **0 e 1023**.

**Entregáveis:**

* **Gráfico:** Printscreen do **Serial Plotter** demonstrando a variação da leitura.  
* **Atividade:** Use a função map() para converter a leitura do potenciômetro em tempo de delay para os LEDs.

## **Nível 4: Interface de Visualização Local (LCD I2C)**

**Objetivo:** Implementar barramento de comunicação serial **I2C**.

**Instruções de Montagem:**

1. Adicione o **LCD 16x2 (I2C)**.  
2. Conecte **SDA** ao pino **A4** e **SCL** ao pino **A5**.  
3. No menu lateral "Library Manager", adicione a biblioteca LiquidCrystal I2C.  
4. Endereço padrão comum: 0x27.

**Entregáveis:**

* **Visual:** Printscreen do LCD exibindo: "POT: \[valor\] %".  
* **Atividade:** Exibir o estado atual do sistema (Ex: "Aguardando Botao" ou "Semaforo Ativo").

## **Nível 5: Sensoriamento de Ambiente (DHT22)**

**Objetivo:** Manipular protocolos digitais de via única e dados tipo float.

**Instruções de Montagem:**

1. Conecte o pino de dados do **DHT22** ao pino digital **4**.  
2. Adicione a biblioteca DHT sensor library.  
3. **Atenção:** O DHT22 tem uma taxa de amostragem lenta; realize leituras com intervalos de no mínimo 2 segundos.

**Entregáveis:**

* **Log:** Captura de texto do Serial Monitor com 5 leituras consecutivas.  
* **Atividade:** Exibir Temperatura e Umidade no LCD de forma alternada.

## **Nível 6: Automação e Lógica de Controle (Sistema Final)**

**Objetivo:** Integrar todos os componentes em um sistema de decisão autônomo.

**Instruções de Execução:**

1. Implemente a lógica de thresholds (limites):  
   * **Temp \< 25°C:** LED Verde \+ LCD "Status: OK".  
   * **Temp 25-30°C:** LED Amarelo \+ LCD "Status: Atencao".  
   * **Temp \> 30°C:** LED Vermelho \+ LCD "ALERTA CRITICO".  
2. Organize o código em funções separadas para facilitar a leitura.

**Entregáveis:**

* **Vídeo:** Gravação de tela (até 60s) demonstrando a mudança de cor dos LEDs ao interagir com o sensor DHT22.  
* **Projeto Final:** Link do Wokwi com o circuito completo e organizado.

### **Dados Institucionais**

**Instituição:** Faculdade SENAI Porto Alegre

**Nome:** Professor João Miguel

**E-mail:** joao.roehe@senairs.org.br

**Telegram:** http://t.me/professorjoaomiguel

**Instagram:** @professsorjoaomiguel