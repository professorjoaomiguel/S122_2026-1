/**
 * LAB 05: Sensores e Comunicação Serial (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo contém o código completo consolidado das etapas do laboratório e
 * a resolução do desafio proposto.
 */

// ====================================================================
// DEFINIÇÕES E CONSTANTES
// ====================================================================
#include <DHT.h>

#define DHTPIN 15       // Pino de dados do DHT22
#define DHTTYPE DHT22   // Tipo do sensor
#define LDRPIN 34       // Pino analógico de entrada do LDR

DHT dht(DHTPIN, DHTTYPE); // Instanciação do objeto DHT

void setup() {
  Serial.begin(115200); // Inicializa a comunicação Serial
  dht.begin();          // Inicializa o sensor de temperatura/umidade
  Serial.println("\n=== [S122] LAB 05 - SOLUCAO INICIADA ===");
}

void loop() {
  // -------------------------------------------------------------
  // LEITURA DOS SENSORES
  // -------------------------------------------------------------
  
  // Leitura analógica do LDR (0 a 4095)
  int luzRaw = analogRead(LDRPIN);
  
  // Leitura digital de temperatura e umidade
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  // Validação das leituras digitais
  if (isnan(temp) || isnan(umid)) {
    Serial.println("[ERRO] Falha de comunicação com o sensor DHT22!");
    delay(2000);
    return;
  }

  // -------------------------------------------------------------
  // PROCESSAMENTO DE DADOS (NORMALIZAÇÃO)
  // -------------------------------------------------------------
  
  // O ADC do ESP32 tem resolução de 12 bits, gerando valores de 0 a 4095.
  // Mapeamos essa escala para porcentagem de luminosidade (0 a 100%).
  int luzPerc = map(luzRaw, 0, 4095, 0, 100);

  // --- SOLUÇÃO DO DESAFIO ---
  // Verifica se a temperatura ultrapassou o limite crítico de segurança
  bool alertaAtivo = false;
  if (temp > 35.0) {
    alertaAtivo = true;
  }

  // -------------------------------------------------------------
  // EXIBIÇÃO DOS DADOS (SAÍDA SERIAL)
  // -------------------------------------------------------------
  Serial.print("Luz Bruta (ADC): "); Serial.print(luzRaw);
  Serial.print(" | Luminosidade: "); Serial.print(luzPerc); Serial.print("%");
  Serial.print(" | Temp: "); Serial.print(temp, 1); Serial.print(" C");
  Serial.print(" | Umid: "); Serial.print(umid, 1); Serial.print(" %");
  
  if (alertaAtivo) {
    Serial.print(" | [ALERTA DE SUPERAQUECIMENTO!] 🚨");
  }
  
  Serial.println();

  delay(2000); // O DHT22 necessita de um intervalo mínimo de 2 segundos entre leituras
}
