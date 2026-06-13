/**
 * LAB 05: Sensores e Serial (GABARITO / SOLUCAO)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo contem o codigo completo consolidado
 * das etapas do laboratorio e o desafio proposto.
 */

// ========================================================
// DEFINICOES E CONSTANTES
// ========================================================
#include <DHT.h>

#define DHTPIN 15       // Pino de dados do DHT22
#define DHTTYPE DHT22   // Tipo do sensor
#define LDRPIN 34       // Pino analógico de entrada do LDR

DHT dht(DHTPIN, DHTTYPE); // Instanciação do objeto DHT

void setup() {
  Serial.begin(115200); // Inicia comunicacao Serial
  dht.begin();          // Inicializa o DHT
  Serial.println("\n=== [S122] LAB 05 - INICIADO ===");
}

void loop() {
  // ------------------------------------------------------
  // LEITURA DOS SENSORES
  // ------------------------------------------------------
  
  // Leitura analógica do LDR (0 a 4095)
  int luzRaw = analogRead(LDRPIN);
  
  // Leitura digital de temperatura e umidade
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  // Validacao das leituras digitais
  if (isnan(temp) || isnan(umid)) {
    Serial.println("[ERRO] Falha no sensor DHT22!");
    delay(2000);
    return;
  }

  // ------------------------------------------------------
  // PROCESSAMENTO DE DADOS (NORMALIZACAO)
  // ------------------------------------------------------
  
  // O ADC do ESP32 tem resolucao de 12 bits (0 a 4095).
  // Mapeamos para luminosidade em % (0 a 100%).
  int luzPerc = map(luzRaw, 0, 4095, 0, 100);

  // --- SOLUCAO DO DESAFIO ---
  // Verifica se temperatura passou do limite critico
  bool alertaAtivo = false;
  if (temp > 35.0) {
    alertaAtivo = true;
  }

  // ------------------------------------------------------
  // EXIBICAO DOS DADOS (SAIDA SERIAL)
  // ------------------------------------------------------
  Serial.print("Luz: "); Serial.print(luzRaw);
  Serial.print(" | "); Serial.print(luzPerc); 
  Serial.print("%");
  
  Serial.print(" | T: "); Serial.print(temp, 1);
  Serial.print("C | U: "); Serial.print(umid, 1);
  Serial.print("%");
  
  if (alertaAtivo) {
    Serial.print(" | [ALERTA DE AQUECIMENTO!]");
  }
  
  Serial.println();

  // O DHT necessita de 2 segs minimos entre leituras
  delay(2000); 
}
