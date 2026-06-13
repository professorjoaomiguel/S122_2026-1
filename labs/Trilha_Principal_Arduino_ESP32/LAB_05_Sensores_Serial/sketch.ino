/**
 * LAB 05: Sensores e Comunicação Serial
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo serve como ponto de partida (Template).
 * Siga as instrucoes do README para completar o circuito.
 */

// ========================================================
// [TAG] DEFINICOES: bibliotecas, pinos e objetos
// ========================================================
// PASSO 3: Insira a biblioteca do DHT e declare seu objeto de controle
// Dica: Pino 15 para o DHT22

// LDR no pino analogico 34 (ADC1)
#define LDRPIN 34

void setup() {
  // Inicializa o Monitor Serial para logs
  Serial.begin(115200);
  Serial.println(
    "S122 - Estufa IoT: Monitoramento Iniciado!"
  );

  // ======================================================
  // [TAG] SETUP_INICIAL: configuracoes de hardware
  // ======================================================
  // PASSO 3: Inicialize o sensor DHT
}

void loop() {
  // ======================================================
  // [TAG] PROCESSAMENTO: leituras e conversoes
  // ======================================================
  
  // PASSO 1: Faça a leitura bruta do LDR
  int luzRaw = analogRead(LDRPIN);
  
  // PASSO 2: Converta a leitura em porcentagem (0-100%)
  // O ADC do ESP32 tem resolucao de 12 bits (0 a 4095)!
  // int luzPerc = map(..., ..., ..., ..., ...);
  
  // PASSO 3: Faça a leitura de temperatura do sensor DHT22
  // float temp = ...
  
  // ======================================================
  // [TAG] SAIDA_SERIAL: exiba os dados formatados
  // ======================================================
  
  // Impressao dos resultados na Serial
  Serial.print("Luz Bruta: "); 
  Serial.print(luzRaw);
  // Serial.print(" | Luz: "); 
  // Serial.print(luzPerc); Serial.print("%");
  // Serial.print(" | Temp: "); 
  // Serial.print(temp); Serial.println("C");
  Serial.println();

  delay(2000); // Intervalo minimo do DHT22
}