/**
 * LAB 06: Comunicação I2C e Fatiamento M3F (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo: _1_Phy.ino (Camada Física e Controle de Percepção/Edge Local)
 */

#include "Bibliotecas.h"

// Instanciação física das variáveis globais locais
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temp = 0.0;
float umid = 0.0;
int luzPerc = 0;

// Inicialização dos dispositivos físicos locais
void setupEdge() {
  dht.begin();
  
  // Inicializa o LCD I2C
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estufa Sliced!");
  
  // Configuração do LED de Alerta do Desafio
  pinMode(PINO_LED_ALERTA, OUTPUT);
  digitalWrite(PINO_LED_ALERTA, LOW);
  
  delay(1500);
}

// Loop de execução local de I/O
void loopEdge() {
  // Leitura dos sensores
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  
  int luzRaw = analogRead(LDRPIN);
  luzPerc = map(luzRaw, 0, 4095, 0, 100);

  if (isnan(temp) || isnan(umid)) {
    Serial.println("[ERRO] Falha ao ler sensores!");
    return;
  }

  // --- SOLUÇÃO DO DESAFIO ---
  // Controle local do LED vermelho
  if (temp > 32.0) {
    digitalWrite(PINO_LED_ALERTA, HIGH);
  } else {
    digitalWrite(PINO_LED_ALERTA, LOW);
  }

  // Atualização da visualização local no display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umid, 1);
  lcd.print(" %");
}
