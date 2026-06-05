/**
 * LAB 05: Sensores e Comunicação Serial
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo serve como o ponto de partida (Template) para a prática.
 * Siga as instruções do README.md para completar o circuito e o firmware.
 */

// ====================================================================
// [TAG] DEFINICOES: declare as bibliotecas, pinos e objetos aqui
// ====================================================================
// PASSO 3: Insira a biblioteca do DHT e declare seu objeto de controle
// Dica: Pino 15 para o DHT22

#define LDRPIN 34 // Sensor de Luz LDR no pino analógico 34 (ADC1)

void setup() {
  // Inicializa o Monitor Serial para visualização de logs
  Serial.begin(115200);
  Serial.println("S122 - Estufa IoT: Monitoramento de Sensores Iniciado!");

  // ====================================================================
  // [TAG] SETUP_INICIAL: inicializações necessárias de hardware
  // ====================================================================
  // PASSO 3: Inicialize o sensor DHT
}

void loop() {
  // ====================================================================
  // [TAG] PROCESSAMENTO: realize as leituras e conversões de escala
  // ====================================================================
  
  // PASSO 1: Faça a leitura bruta do LDR
  int luzRaw = analogRead(LDRPIN);
  
  // PASSO 2: Converta a leitura analógica bruta em porcentagem (0 a 100%)
  // Dica: O conversor analógico-digital (ADC) do ESP32 tem resolução de 12 bits (0 a 4095)!
  // int luzPerc = map(..., ..., ..., ..., ...);
  
  // PASSO 3: Faça a leitura de temperatura do sensor DHT22
  // float temp = ...
  
  // ====================================================================
  // [TAG] SAIDA_SERIAL: exiba os dados formatados no Monitor Serial
  // ====================================================================
  
  // Impressão dos resultados na Serial
  Serial.print("Luz Bruta: "); Serial.print(luzRaw);
  // Serial.print(" | Luz: "); Serial.print(luzPerc); Serial.print("%");
  // Serial.print(" | Temp: "); Serial.print(temp); Serial.println("C");
  Serial.println();

  delay(2000); // Aguarda 2 segundos (intervalo mínimo exigido pelo DHT22)
}