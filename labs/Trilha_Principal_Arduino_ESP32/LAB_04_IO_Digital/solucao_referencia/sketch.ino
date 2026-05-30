/**
 * LAB 04: Entradas e Saídas Digitais (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo contém o código completo consolidado das etapas do laboratório e
 * a solução dos desafios propostos.
 */

// ==========================================
// DEFINIÇÕES E CONSTANTES
// ==========================================
const int pinoLED = 12;      // LED Vermelho Externo (Alerta)
const int pinoBotao = 2;     // Pushbutton (Sensor de Porta)
const int pinoLEDAlert = 14; // LED de Alerta Secundário (Opcional para o Desafio 2)

// Variáveis para Lógica dos Desafios
bool modoDesafioAtivo = false;  // Altere para 'true' para testar a solução dos Desafios!
bool alarmeTravado = false;      // Estado de trava do alarme (Desafio 2)
unsigned long tempoBotaoPressionado = 0; // Temporização para reset (Desafio 2)

void setup() {
  Serial.begin(115200); // Uso recomendado de velocidade alta em ESP32
  Serial.println("\n=== [S122] LAB 04 - SOLUCAO INICIADA ===");
  
  // Configuração dos Pinos
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoLEDAlert, OUTPUT);
  
  // O modo INPUT_PULLUP aciona o resistor interno de pull-up do ESP32 (aprox. 47k Ohms).
  // Isso mantém a porta em nível ALTO (HIGH) por padrão e vai a BAIXO (LOW) quando o botão é pressionado.
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // Seletor para testar a lógica normal do lab ou os desafios avançados
  if (!modoDesafioAtivo) {
    // -------------------------------------------------------------
    // SOLUÇÃO DO LABORATÓRIO (PASSO 3 - CONSOLIDADO)
    // -------------------------------------------------------------
    
    // Leitura digital direta do pino
    bool estadoBotao = digitalRead(pinoBotao);
    
    // O botão conecta ao GND. Logo, quando pressionado, lê LOW.
    if (estadoBotao == LOW) { 
      digitalWrite(pinoLED, HIGH);
      Serial.println("[LOG] Porta ABERTA! Sensor Ativo (LOW) -> LED LIGADO.");
    } else {
      digitalWrite(pinoLED, LOW);
    }
    
    delay(50); // Delay suave para estabilização de leitura
    
  } else {
    // -------------------------------------------------------------
    // SOLUÇÃO DOS DESAFIOS AVANÇADOS
    // -------------------------------------------------------------
    
    bool estadoBotao = digitalRead(pinoBotao);
    
    // --- LÓGICA DO DESAFIO 2: TRAVA DE SEGURANÇA COM RESET TEMPORAL ---
    if (estadoBotao == LOW) {
      if (!alarmeTravado) {
        alarmeTravado = true;
        Serial.println("[ALERTA] Invasao detectada! Alarme TRAVADO.");
      }
      
      // Monitora o tempo que o botão está pressionado para realizar o RESET
      if (tempoBotaoPressionado == 0) {
        tempoBotaoPressionado = millis();
      } else if (millis() - tempoBotaoPressionado >= 3000) {
        // Se mantiver pressionado por mais de 3 segundos, desliga o alarme
        alarmeTravado = false;
        tempoBotaoPressionado = 0;
        digitalWrite(pinoLED, LOW);
        digitalWrite(pinoLEDAlert, LOW);
        Serial.println("[SISTEMA] Alarme RESETADO pelo operador local.");
        delay(1000); // Evita reativação imediata
      }
    } else {
      tempoBotaoPressionado = 0; // Reseta contador se soltar o botão
    }
    
    // --- LÓGICA DO DESAFIO 1: BLINK CONDICIONAL DE ALERTA ---
    if (alarmeTravado) {
      // Pisca os LEDs alternadamente enquanto estiver travado
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
