/**
 * LAB 06A: Interface LCD (Barramento I2C) - GABARITO Monolítico
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 */

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estufa IoT Monol");
  delay(1500);
}

void loop() {
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();
  int luzRaw = analogRead(LDRPIN);
  
  int luzPerc = map(luzRaw, 0, 4095, 0, 100);

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro ao ler dados dos sensores!");
    return;
  }

  Serial.printf(
    "T: %.1f C | U: %.1f %% | Luz: %d%%\n", 
    temp, umid, luzPerc
  );

  lcd.clear();
  
  // Desafio: Alerta Visual Direto
  if (temp > 32.0) {
    lcd.setCursor(0, 0);
    lcd.print("ALERTA: QUENTE!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp, 1);
    lcd.print(" C");
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umid, 1);
  lcd.print(" %");

  delay(2000);
}
