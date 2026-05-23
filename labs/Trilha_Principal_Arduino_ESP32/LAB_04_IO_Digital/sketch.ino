void setup() {
  // Inicializa a comunicação serial com velocidade de 115200 bits por segundo
  Serial.begin(115200);
  
  // Define o pino do LED interno como saída
  pinMode(2, OUTPUT);
  
  // Mensagem inicial de Boas Vindas
  Serial.println("S122 - Sistema Iniciado!");
}

void loop() {
  // Liga o LED
  digitalWrite(2, HIGH);
  Serial.println("LED LIGADO 🔵");
  delay(1000); // Espera 1 segundo
  
  // Desliga o LED
  digitalWrite(2, LOW);
  Serial.println("LED DESLIGADO ⚪");
  delay(1000); // Espera 1 segundo
}