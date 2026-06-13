/**
 * LAB 04: Entradas e Saídas Digitais
 * (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo contém o código completo consolidado das
 * etapas do laboratório e a solução dos desafios.
 */

// =========================================================
// DEFINIÇÕES E CONSTANTES
// =========================================================
const int pinoLED = 12;      // LED Vermelho (Alerta)
const int pinoBotao = 2;     // Botão (Sensor de Porta)
const int pinoLEDAlert = 14; // LED Amarelo (Desafio 2)

// Variáveis para Lógica dos Desafios
bool modoDesafioAtivo = false; // true para testar desafios
bool alarmeTravado = false;     // Trava do alarme
unsigned long tempoBotaoPressionado = 0; // Para reset

void setup() {
  Serial.begin(115200); // Velocidade recomendada ESP32
  Serial.println("\n=== S122 - SOLUCAO INICIADA ===");
  
  // Configuração dos Pinos
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoLEDAlert, OUTPUT);
  
  // Configurado como INPUT devido ao resistor de Pull-Up
  // físico de 10k externo no circuito.
  pinMode(pinoBotao, INPUT);
}

void loop() {
  if (!modoDesafioAtivo) {
    // -----------------------------------------------------
    // SOLUÇÃO DO LABORATÓRIO (PASSO 3 - CONSOLIDADO)
    // -----------------------------------------------------
    
    // Leitura digital direta do pino
    bool estadoBotao = digitalRead(pinoBotao);
    
    // O botão conecta ao GND. Ao pressionar, lê LOW.
    if (estadoBotao == LOW) { 
      digitalWrite(pinoLED, HIGH);
      Serial.println("[LOG] Porta ABERTA! LED ligado.");
    } else {
      digitalWrite(pinoLED, LOW);
    }
    
    delay(50); // Estabilização de leitura
    
  } else {
    // -----------------------------------------------------
    // SOLUÇÃO DOS DESAFIOS AVANÇADOS
    // -----------------------------------------------------
    
    bool estadoBotao = digitalRead(pinoBotao);
    
    // --- DESAFIO 2: TRAVA COM RESET TEMPORAL ---
    if (estadoBotao == LOW) {
      if (!alarmeTravado) {
        alarmeTravado = true;
        Serial.println("[ALERTA] Invasao! Alarme TRAVADO.");
      }
      
      // Monitora o tempo pressionado para RESET
      if (tempoBotaoPressionado == 0) {
        tempoBotaoPressionado = millis();
      } else if (millis() - tempoBotaoPressionado >= 3000) {
        // Reset após 3 segundos continuamente
        alarmeTravado = false;
        tempoBotaoPressionado = 0;
        digitalWrite(pinoLED, LOW);
        digitalWrite(pinoLEDAlert, LOW);
        Serial.println("[SISTEMA] Alarme RESETADO.");
        delay(1000); // Evita reativação imediata
      }
    } else {
      tempoBotaoPressionado = 0; // Reseta se soltar botão
    }
    
    // --- DESAFIO 1: BLINK CONDICIONAL DE ALERTA ---
    if (alarmeTravado) {
      // Pisca alternadamente enquanto travado
      digitalWrite(pinoLED, HIGH);
      digitalWrite(pinoLEDAlert, LOW);
      delay(200);
      digitalWrite(pinoLED, LOW);
      digitalWrite(pinoLEDAlert, HIGH);
      delay(200);
    } else {
      // LEDs apagados em estado seguro
      digitalWrite(pinoLED, LOW);
      digitalWrite(pinoLEDAlert, LOW);
    }
  }
}
