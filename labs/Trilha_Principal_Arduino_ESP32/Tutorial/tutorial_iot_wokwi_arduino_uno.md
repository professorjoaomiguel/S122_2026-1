# **Tutorial Incremental: Introdução ao IoT com Wokwi e Arduino Uno**

Este roteiro guia o estudante do nível básico ao monitoramento de sensores com lógica de controle.

## **Nível 0: Hello World (Blink)**

### **Objetivo Pedagógico**

Compreender a estrutura básica do firmware (setup e loop) e o controle de uma saída digital simples.

### **Componentes**

* **Arduino Uno** (LED interno no Pino 13).

### **Diagrama (diagram.json)**

{  
  "version": 1,  
  "author": "Professor João Miguel",  
  "editor": "wokwi",  
  "parts": \[ { "type": "wokwi-arduino-uno", "id": "uno", "top": 0, "left": 0 } \],  
  "connections": \[\]  
}

### **Código-Fonte**

// Nivel 0: Blink LED Interno  
void setup() {  
  pinMode(13, OUTPUT); // Define pino 13 como saida  
}

void loop() {  
  digitalWrite(13, HIGH); // Liga o LED  
  delay(1000);           // Aguarda 1 segundo  
  digitalWrite(13, LOW);  // Desliga o LED  
  delay(1000);           // Aguarda 1 segundo  
}

### **Comandos-Chave**

* [pinMode()](https://www.google.com/search?q=https://www.arduino.cc/reference/pt/language/functions/digital-io/pinmode/)  
* [digitalWrite()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalwrite/)

## **Nível 1: Sinalização Semafórica (Digital Out)**

### **Objetivo Pedagógico**

Manipular múltiplos pinos de saída e gerenciar fluxos temporais sequenciais.

### **Componentes**

* **3 LEDs** (Verde, Amarelo, Vermelho).  
* **3 Resistores** (220 Ω).

### **Diagrama (diagram.json)**

{  
  "version": 1,  
  "author": "Professor João Miguel",  
  "editor": "wokwi",  
  "parts": \[  
    { "type": "wokwi-arduino-uno", "id": "uno", "top": 40, "left": 0 },  
    { "type": "wokwi-led", "id": "led-v", "top": \-50, "left": 100, "attrs": { "color": "green" } },  
    { "type": "wokwi-led", "id": "led-a", "top": \-50, "left": 140, "attrs": { "color": "yellow" } },  
    { "type": "wokwi-led", "id": "led-vm", "top": \-50, "left": 180, "attrs": { "color": "red" } },  
    { "type": "wokwi-resistor", "id": "r1", "top": 20, "left": 100, "attrs": { "value": "220" } },  
    { "type": "wokwi-resistor", "id": "r2", "top": 20, "left": 140, "attrs": { "value": "220" } },  
    { "type": "wokwi-resistor", "id": "r3", "top": 20, "left": 180, "attrs": { "value": "220" } }  
  \],  
  "connections": \[  
    \[ "uno:GND.1", "r1:1", "black", \[ "v0" \] \],  
    \[ "uno:GND.1", "r2:1", "black", \[ "v0" \] \],  
    \[ "uno:GND.1", "r3:1", "black", \[ "v0" \] \],  
    \[ "r1:2", "led-v:C", "black", \[ "v0" \] \],  
    \[ "r2:2", "led-a:C", "black", \[ "v0" \] \],  
    \[ "r3:2", "led-vm:C", "black", \[ "v0" \] \],  
    \[ "uno:10", "led-v:A", "green", \[ "v0" \] \],  
    \[ "uno:11", "led-a:A", "yellow", \[ "v0" \] \],  
    \[ "uno:12", "led-vm:A", "red", \[ "v0" \] \]  
  \]  
}

### **Código-Fonte**

// Nivel 1: Semaforo Simples  
const int VERDE \= 10;  
const int AMARELO \= 11;  
const int VERMELHO \= 12;

void setup() {  
  pinMode(VERDE, OUTPUT);  
  pinMode(AMARELO, OUTPUT);  
  pinMode(VERMELHO, OUTPUT);  
}

void loop() {  
  digitalWrite(VERDE, HIGH); delay(3000); digitalWrite(VERDE, LOW);  
  digitalWrite(AMARELO, HIGH); delay(1000); digitalWrite(AMARELO, LOW);  
  digitalWrite(VERMELHO, HIGH); delay(3000); digitalWrite(VERMELHO, LOW);  
}

## **Nível 2: O Gatilho (Digital In)**

### **Objetivo Pedagógico**

Compreender a leitura de entradas digitais e o uso do resistor interno **INPUT\_PULLUP**.

### **Componentes Adicionais**

* **1 Pushbutton** (Pino 2).

### **Código-Fonte**

// Nivel 2: Gatilho por Botao  
const int BOTAO \= 2;  
bool ativo \= false;

void setup() {  
  pinMode(10, OUTPUT); pinMode(11, OUTPUT); pinMode(12, OUTPUT);  
  pinMode(BOTAO, INPUT\_PULLUP); // Botao em nivel baixo quando pressionado  
}

void loop() {  
  if (digitalRead(BOTAO) \== LOW) { // Botao pressionado  
    digitalWrite(10, HIGH); delay(1000); digitalWrite(10, LOW);  
    digitalWrite(11, HIGH); delay(500);  digitalWrite(11, LOW);  
    digitalWrite(12, HIGH); delay(1000); digitalWrite(12, LOW);  
  }  
}

### **Comandos-Chave**

* [digitalRead()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalread/)

## **Nível 3: Variabilidade Analógica (ADC)**

### **Objetivo Pedagógico**

Trabalhar com conversão analógico-digital e mapeamento de faixas de valores.

### **Componentes Adicionais**

* **1 Potenciômetro** (Pino A0).

### **Código-Fonte**

// Nivel 3: Controle Analógico  
void setup() {  
  Serial.begin(9600);  
  pinMode(11, OUTPUT); // LED Amarelo para PWM  
}

void loop() {  
  int valorPot \= analogRead(A0); // Leitura 0 a 1023  
  int brilho \= map(valorPot, 0, 1023, 0, 255); // Converte para PWM (0-255)  
    
  analogWrite(11, brilho); // Altera o brilho do LED  
  Serial.print("Potenciometro: ");  
  Serial.println(valorPot);  
  delay(50);  
}

### **Comandos-Chave**

* [analogRead()](https://www.google.com/search?q=https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/)  
* [map()](https://www.arduino.cc/reference/pt/language/functions/math/map/)

## **Nível 4: Interface Homem-Máquina (I2C)**

### **Objetivo Pedagógico**

Integrar displays através do protocolo **I2C** e utilizar bibliotecas externas.

### **Componentes Adicionais**

* **Display LCD 16x2 I2C** (SDA: A4, SCL: A5).

### **Código-Fonte**

\#include \<Wire.h\>  
\#include \<LiquidCrystal\_I2C.h\>

LiquidCrystal\_I2C lcd(0x27, 16, 2);

void setup() {  
  lcd.init();  
  lcd.backlight();  
}

void loop() {  
  int valor \= analogRead(A0);  
  int perc \= map(valor, 0, 1023, 0, 100);  
    
  lcd.setCursor(0, 0);  
  lcd.print("Nivel Potenc.: ");  
  lcd.setCursor(0, 1);  
  lcd.print(perc);  
  lcd.print("%    "); // Espacos para limpar caracteres antigos  
  delay(200);  
}

## **Nível 5: Sensoriamento IoT (DHT22)**

### **Objetivo Pedagógico**

Trabalhar com sensores digitais complexos e tratamento de variáveis de ponto flutuante (float).

### **Componentes Adicionais**

* **Sensor DHT22** (Pino 4).

### **Código-Fonte**

\#include \<DHT.h\>  
\#include \<LiquidCrystal\_I2C.h\>

\#define DHTPIN 4  
\#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);  
LiquidCrystal\_I2C lcd(0x27, 16, 2);

void setup() {  
  dht.begin();  
  lcd.init();  
  lcd.backlight();  
}

void loop() {  
  float t \= dht.readTemperature();  
  float h \= dht.readHumidity();

  lcd.setCursor(0, 0);  
  lcd.print("Temp: "); lcd.print(t); lcd.print(" C");  
  lcd.setCursor(0, 1);  
  lcd.print("Umid: "); lcd.print(h); lcd.print(" %");  
  delay(2000);  
}

## **Nível 6: Sistema de Monitoramento com Alerta**

### **Objetivo Pedagógico**

Integrar todos os periféricos em uma lógica de decisão para automação de alertas.

### **Resultado Esperado**

O sistema monitora a temperatura e sinaliza visualmente o status no LCD e nos LEDs.

### **Código-Fonte**

\#include \<DHT.h\>  
\#include \<LiquidCrystal\_I2C.h\>

\#define DHTPIN 4  
\#define DHTTYPE DHT22  
const int VERDE \= 10, AMARELO \= 11, VERMELHO \= 12;

DHT dht(DHTPIN, DHTTYPE);  
LiquidCrystal\_I2C lcd(0x27, 16, 2);

void setup() {  
  pinMode(VERDE, OUTPUT); pinMode(AMARELO, OUTPUT); pinMode(VERMELHO, OUTPUT);  
  dht.begin();  
  lcd.init(); lcd.backlight();  
}

void desligarLeds() {  
  digitalWrite(VERDE, LOW); digitalWrite(AMARELO, LOW); digitalWrite(VERMELHO, LOW);  
}

void loop() {  
  float temp \= dht.readTemperature();  
  desligarLeds();  
  lcd.setCursor(0, 0);  
  lcd.print("Temp: "); lcd.print(temp); lcd.print("C ");

  lcd.setCursor(0, 1);  
  if (temp \< 25.0) {  
    digitalWrite(VERDE, HIGH);  
    lcd.print("Status: OK      ");  
  } else if (temp \>= 25.0 && temp \<= 30.0) {  
    digitalWrite(AMARELO, HIGH);  
    lcd.print("Status: ATENCAO ");  
  } else {  
    digitalWrite(VERMELHO, HIGH);  
    lcd.print("ALERTA CRITICO  ");  
  }  
  delay(2000);  
}

**Instituição:** Faculdade SENAI Porto Alegre

**Nome:** Professor João Miguel

**E-mail:** joao.roehe@senairs.org.br

**Telegram:** http://t.me/professorjoaomiguel

**Instagram:** @professsorjoaomiguel