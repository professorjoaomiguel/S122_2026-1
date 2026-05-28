/*
 * =====================================================================
 * S122 - Internet das Coisas | Faculdade de Tecnologia SENAI
 * _1_Phy.ino - Camada Física / Edge (Sensores, Atuadores e LCD)
 * =====================================================================
 */

#include "Bibliotecas.h"

void setupEdge() {
  Serial.println("[Nível 1 - Edge] Inicializando Periféricos...");
  
  pinMode(RELEPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(RELEPIN, LOW);
  digitalWrite(LEDPIN, LOW);
  
  dht.begin();
  
  // Inicialização do LCD I2C
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estufa IoT M3F");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  
  delay(1000);
}

void loopEdge() {
  static unsigned long lastReading = 0;
  unsigned long now = millis();
  
  // Lê sensores a cada 2 segundos (independente do tempo de envio de rede)
  if (now - lastReading >= 2000 || lastReading == 0) {
    lastReading = now;
    
    // Leitura física
    temperatura = dht.readTemperature();
    umidade = dht.readHumidity();
    luminosidade = analogRead(LDRPIN);
    
    // Tratamento básico de erro de leitura
    if (isnan(temperatura) || isnan(umidade)) {
      Serial.println("[Nível 1 - ALERTA] Falha de leitura no DHT22!");
      return;
    }
    
    // Controle Autônomo Local por Histerese (Segurança do Negócio)
    // Se a temperatura passar de 30°C, liga a ventoinha (Relé). Desliga abaixo de 28°C.
    if (temperatura >= 30.0) {
      estadoRele = true;
      digitalWrite(RELEPIN, HIGH);
      digitalWrite(LEDPIN, HIGH);
    } else if (temperatura <= 28.0) {
      estadoRele = false;
      digitalWrite(RELEPIN, LOW);
      digitalWrite(LEDPIN, LOW);
    }
    
    // Exibição local imediata no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatura, 1);
    lcd.print(" C");
    
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidade, 1);
    lcd.print("% ");
    lcd.print(estadoRele ? "[ON]" : "[OFF]");
    
    // Exibe no Serial Monitor local
    Serial.print("[Edge] Temp: ");
    Serial.print(temperatura, 1);
    Serial.print("C | Umid: ");
    Serial.print(umidade, 1);
    Serial.print("% | LDR: ");
    Serial.print(luminosidade);
    Serial.print(" | Relé: ");
    Serial.println(estadoRele ? "LIGADO" : "DESLIGADO");
  }
}
