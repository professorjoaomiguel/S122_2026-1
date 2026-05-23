#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço I2C comum é 0x27

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("S122 - Estufa");
  delay(2000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Erro ao ler DHT!");
    return;
  }

  // Monitor Serial para Debug
  Serial.printf("T: %.1f C | U: %.1f %%\n", t, h);

  // Display LCD para o Usuário
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("Temp: %.1f C", t);
  lcd.setCursor(0, 1);
  lcd.printf("Umid: %.1f %%", h);

  delay(2000); // Espera 2 segundos (tempo de resposta do DHT22)
}