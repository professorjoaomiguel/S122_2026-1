/**
 * LAB 06: Comunicação I2C e Fatiamento M3F (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo Principal: Coordenador Geral do Firmware Sliced
 */

#include "Bibliotecas.h"

// Instanciação física das variáveis globais declaradas como extern em Bibliotecas.h
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temp = 0.0;
float umid = 0.0;
int luzPerc = 0;

// Declaração de escopo das funções implementadas na aba _1_Phy.ino
void setupEdge();
void loopEdge();

void setup() {
  Serial.begin(115200);
  Serial.println("\n=== [M3F] Inicializando Sistema Sliced (LAB 06) ===");
  
  setupEdge(); // Inicializa os pinos, sensores e LCD
}

void loop() {
  loopEdge(); // Executa a lógica de leitura física e controle de I/O local
  
  // Mensagem de log na Serial para monitoramento remoto / debug
  Serial.printf("[Debug] T: %.1fC | U: %.1f%% | Luz: %d%%\n", temp, umid, luzPerc);
  
  delay(2000); // Intervalo exigido pelo DHT22
}
