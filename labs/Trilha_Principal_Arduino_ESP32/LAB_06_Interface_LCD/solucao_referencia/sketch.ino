/**
 * LAB 06: Comunicação I2C e Fatiamento M3F (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo Principal: Coordenador Geral do Firmware Sliced
 */

#include "Bibliotecas.h"

// Declaração de escopo das funções implementadas na aba _1_Phy.ino
void setupEdge();
void loopEdge();

void setup() {
  Serial.begin(115200);
  Serial.println(
    "\n=== [M3F] Inicializando Sistema Sliced ==="
  );
  
  setupEdge(); // Inicializa os pinos, sensores e LCD
}

void loop() {
  loopEdge(); // Executa leitura física local
  
  // Mensagem de log na Serial para monitoramento
  Serial.printf(
    "[Debug] T: %.1fC | U: %.1f%% | Luz: %d%%\n",
    temp, umid, luzPerc
  );
  
  delay(2000); // Intervalo exigido pelo DHT22
}
