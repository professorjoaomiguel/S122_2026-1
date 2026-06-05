/**
 * LAB 07: Lógica de Controle e Atuadores (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo: _1_Phy.ino (Camada Física e Lógica de Automação no Edge)
 */

#include "Bibliotecas.h"

// Variável local para manter o estado da ventoinha (usada na lógica de Histerese)
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
  // Implementação da histerese para proteger o relé/motor da ventoinha contra oscilações rápidas:
  // - Liga a ventoinha se a temperatura subir acima de 30.0°C.
  // - Mantém ligada até que a temperatura caia abaixo de 28.0°C (margem de 2 graus).
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
  // Se a temperatura passar do limite crítico industrial (40°C), dispara o buzzer de forma ativa.
  if (temp > 40.0) {
    tone(PINO_BUZZER, 1000); // Emite tom de 1000Hz
  } else {
    noTone(PINO_BUZZER);     // Silencia o buzzer
  }

  // -------------------------------------------------------------
  // ATUALIZAÇÃO DO DISPLAY LCD COM STATUS DA VENTOINHA (DESAFIO)
  // -------------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("T:%.1fC U:%.1f%%", temp, umid);
  
  // Exibição do estado da ventoinha na segunda linha do display
  lcd.setCursor(0, 1);
  if (ventoinhaLigada) {
    lcd.print("FAN: LIGADA (ON) ");
  } else {
    lcd.print("FAN: DESLIG. (OFF)");
  }
}
