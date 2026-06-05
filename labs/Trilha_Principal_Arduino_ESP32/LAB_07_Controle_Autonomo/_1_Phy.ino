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
  
  // ====================================================================
  // [TAG] SETUP_PINOS: configure os pinos dos atuadores como saída
  // ====================================================================
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

  // ====================================================================
  // [TAG] LOGICA_CONTROLE: implemente a lógica condicional de controle
  // ====================================================================
  
  // PASSO 1: Lógica de controle liga/desliga simples para a ventoinha (PINO_VENTOINHA)
  // Se temp > 30.0 liga; caso contrário desliga.
  
  // PASSO 2: Adicione o alarme crítico sonoro com o Buzzer (PINO_BUZZER)
  // Se temp > 40.0, emita um tom de 1000Hz; caso contrário silencie.
  
  // PASSO 3: Refine o controle da ventoinha aplicando Histerese!
  // Evite ligar/desligar rápido demais na borda (ex: liga se temp > 30.0, desliga se temp < 28.0)
  
  // ====================================================================
  // [TAG] DISPLAY_LOCAL: exiba os dados e status dos atuadores no LCD
  // ====================================================================
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("Temp: %.1f C", temp);
  lcd.setCursor(0, 1);
  lcd.printf("Umid: %.1f %%", umid);
}
