/**
 * LAB 07: Lógica de Controle e Atuadores (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo: _1_Phy.ino (Camada Física e Lógica de Automação no Edge)
 */

#include "Bibliotecas.h"

// Variavel local do estado da ventoinha (Histerese)
bool ventoinhaLigada = false;

// Inicialização dos dispositivos físicos locais
void setupEdge() {
  dht.begin();
  
  // Inicialização do LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Controle IoT!");
  
  // Configuração dos pinos dos atuadores
  pinMode(PINO_VENTOINHA, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
  
  // Garante atuadores desligados na partida
  digitalWrite(PINO_VENTOINHA, LOW);
  noTone(PINO_BUZZER);
  
  delay(1500);
}

// Loop de execução local de I/O e regras de automação
void loopEdge() {
  // Leituras físicas
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  
  int luzRaw = analogRead(LDRPIN);
  luzPerc = map(luzRaw, 0, 4095, 0, 100);

  if (isnan(temp) || isnan(umid)) {
    Serial.println("[ERRO] Falha ao ler sensores!");
    return;
  }

  // -------------------------------------------------------------
  // REGRA DE ATUAÇÃO E HISTERESE (PASSO 1 E 3)
  // -------------------------------------------------------------
  // Histerese para proteger contra oscilacoes:
  // - Liga a ventoinha se a temp > 30.0 C.
  // - Mantem ligada ate temp cair abaixo de 28.0 C.
  if (temp > 30.0) {
    ventoinhaLigada = true;
    digitalWrite(PINO_VENTOINHA, HIGH);
  } 
  else if (temp < 28.0) {
    ventoinhaLigada = false;
    digitalWrite(PINO_VENTOINHA, LOW);
  }

  // -------------------------------------------------------------
  // REGRA DE ALARME CRÍTICO (PASSO 2)
  // -------------------------------------------------------------
  // Se a temperatura passar do limite critico
  // dispara o alarme.
  if (temp > 40.0) {
    tone(PINO_BUZZER, 1000); // Emite tom de 1000Hz
  } else {
    noTone(PINO_BUZZER);     // Silencia o buzzer
  }

  // ---------------------------------------------------
  // ATUALIZACAO DO LCD COM STATUS DA VENTOINHA
  // ---------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temp, 1);
  lcd.print("C U:"); lcd.print(umid, 1); lcd.print("%");
  
  // Status da ventoinha na segunda linha do display
  lcd.setCursor(0, 1);
  if (ventoinhaLigada) {
    lcd.print("FAN: LIGADA (ON) ");
  } else {
    lcd.print("FAN: DESLIG. (OFF)");
  }
}
