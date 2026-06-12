/**
 * LAB 04: Entradas e Saídas Digitais
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo é o ponto de partida (Template)
 * para o laboratório. Siga as instruções
 * passo a passo no README.md para completar
 * o circuito e a lógica.
 */

// =========================================================
// [TAG] DEFINICOES: declare as variáveis e
// constantes de pinos aqui
// =========================================================
const int pinoLED = 12;   // LED Externo no pino 12
const int pinoBotao = 2;  // Pushbutton no pino 2

void setup() {
  // Inicializa o Monitor Serial para logs
  Serial.begin(115200);
  Serial.println("S122 - Seguranca Iniciado!");
  
  // =======================================================
  // [TAG] SETUP_PINOS: configure o comportamento
  // de entrada/saída
  // =======================================================
  pinMode(pinoLED, OUTPUT);
  
  // Como o circuito possui resistor de Pull-Up
  // de 10k externo, configuramos como INPUT!
  pinMode(pinoBotao, INPUT);
}

void loop() {
  // =======================================================
  // [TAG] LOGICA_CONTROLE: lógica de leitura e ação
  // =======================================================
  
  // PASSO 1: Forçar o LED ligado para teste físico.
  // digitalWrite(pinoLED, HIGH);
  
  // PASSO 2: Leia o botão e exiba no Monitor.
  // bool estado = digitalRead(pinoBotao);
  // Serial.print("Botao: "); 
  // Serial.println(estado);
  // delay(100);
  
  // PASSO 3: Decisão (if/else).
  // Se pressionado (LOW), liga o LED (HIGH).
  // Se não, desliga o LED (LOW).
  
  // --- Escreva sua lógica aqui ---
  
  delay(50); // Atraso de amostragem
}