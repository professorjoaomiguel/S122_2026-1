/**
 * LAB 04: Entradas e Saídas Digitais
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo é o ponto de partida (Template) para o laboratório.
 * Siga as instruções passo a passo no README.md para completar o circuito e a lógica.
 */

// ====================================================================
// [TAG] DEFINICOES: declare as variáveis e constantes de pinos aqui
// ====================================================================
const int pinoLED = 12;   // LED Externo conectado ao pino 12
const int pinoBotao = 2;  // Pushbutton conectado ao pino 2 (e ao GND)

void setup() {
  // Inicializa o Monitor Serial para visualização de logs
  Serial.begin(9600);
  Serial.println("S122 - Sistema de Segurança Iniciado!");
  
  // ====================================================================
  // [TAG] SETUP_PINOS: configure o comportamento de entrada/saída
  // ====================================================================
  pinMode(pinoLED, OUTPUT);
  
  // ATENÇÃO: Qual modo usar no pino do botão para evitar resistores externos?
  // Dica: Use INPUT_PULLUP para acionar a resistência interna de Pull-up.
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // ====================================================================
  // [TAG] LOGICA_CONTROLE: implemente a lógica de leitura e decisão
  // ====================================================================
  
  // PASSO 1: Comece forçando o LED ligado para testar a parte física.
  // digitalWrite(pinoLED, HIGH);
  
  // PASSO 2: Leia o botão e exiba no Serial Monitor.
  // bool estado = digitalRead(pinoBotao);
  // Serial.print("Estado do Botao: "); Serial.println(estado);
  // delay(100);
  
  // PASSO 3: Una leitura e ação através de uma estrutura de decisão (if/else).
  // Se o botão for pressionado (LOW), liga o LED (HIGH) e envia log.
  // Se não, desliga o LED (LOW).
  
  // --- Escreva sua lógica aqui ---
  
  delay(50); // Atraso de amostragem
}