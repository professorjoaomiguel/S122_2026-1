/**
 * LAB 06: Comunicação I2C e Fatiamento M3F (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo: _1_Phy.ino (Camada Física e Controle de Percepção/Edge Local)
 */

#include "Bibliotecas.h"

// Inicialização dos dispositivos físicos locais
void setupEdge() {
  dht.begin();
  
  // Inicializa o LCD I2C
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estufa Sliced!");
  
  // Configuração dos pinos dos atuadores locais (LED de Alerta do Desafio)
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
    Serial.println("[ERRO] Falha ao ler sensores locais!");
    return;
  }

  // --- SOLUÇÃO DO DESAFIO ---
  // Controle local autônomo do LED vermelho de temperatura crítica
  if (temp > 32.0) {
    digitalWrite(PINO_LED_ALERTA, HIGH);
  } else {
    digitalWrite(PINO_LED_ALERTA, LOW);
  }

  // Atualização da visualização local no display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("Temp: %.1f C", temp);
  lcd.setCursor(0, 1);
  lcd.printf("Umid: %.1f %%", umid);
}
