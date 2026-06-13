/**
 * LAB 07: Lógica de Controle e Atuadores
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo: _1_Phy.ino (Camada Física e Controle de Automação no Edge)
 */

#include "Bibliotecas.h"

// Inicialização dos dispositivos físicos locais e pinos de atuação
void setupEdge() {
  dht.begin();
  
  // Inicialização do LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Controle IoT!");
  
  // ======================================================
  // [TAG] SETUP_PINOS: configure atuadores como saida
  // ======================================================
  // PASSO 1: Configure o pino da ventoinha
  
  // PASSO 2: Configure o pino do buzzer (caso necessário)
  
  delay(1500);
}

// Loop de leitura física, processamento e lógica de atuação
void loopEdge() {
  // Leituras físicas
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  
  int luzRaw = analogRead(LDRPIN);
  luzPerc = map(luzRaw, 0, 4095, 0, 100);

  if (isnan(temp) || isnan(umid)) {
    Serial.println("[ERRO] Falha na leitura dos sensores!");
    return;
  }

  // ======================================================
  // [TAG] LOGICA_CONTROLE: implemente regras de atuacao
  // ======================================================
  
  // PASSO 1: Controle liga/desliga simples da ventoinha
  // Se temp > 30.0 liga; senao desliga.
  
  // PASSO 2: Alarme sonoro critico com Buzzer
  // Se temp > 40.0 emite tom 1000Hz; senao silencie.
  
  // PASSO 3: Refine o controle aplicando Histerese!
  // Evite repiques (liga se > 30.0, desliga se < 28.0)
  
  // ======================================================
  // [TAG] DISPLAY_LOCAL: status dos atuadores no LCD
  // ======================================================
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: "); lcd.print(temp, 1); lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Umid: "); lcd.print(umid, 1); lcd.print(" %");
}
