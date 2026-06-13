// LAB 03B - Solucao de Referencia
// Demonstra: Blink basico + versao com BPM parametrizado

// ============================================================
// ETAPA 1: Blink simples com LED_BUILTIN
// ============================================================

// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);
// }
// void loop() {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(1000);
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(1000);
// }

// ============================================================
// ETAPA 2 (Desafio): Metrônomo parametrizado por BPM
// Para mudar a velocidade, altere APENAS a variável 'bpm'.
// ============================================================

const int bpm = 60;                    // Altere aqui: ex. 60, 120, 240
const int intervalo = 60000 / bpm;    // Converte BPM para milissegundos

void setup() {
  Serial.begin(9600);
  Serial.print("Metronomo iniciado a ");
  Serial.print(bpm);
  Serial.println(" BPM");
  Serial.print("Intervalo por batida: ");
  Serial.print(intervalo);
  Serial.println(" ms");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(intervalo / 2); // Ligado por metade do intervalo

  digitalWrite(LED_BUILTIN, LOW);
  delay(intervalo / 2); // Desligado pela outra metade
}
