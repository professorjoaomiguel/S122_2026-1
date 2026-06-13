/**
 * LAB 03: O Primeiro Sinal (Blink Base)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo serve como o ponto de partida (Template) para a prática.
 * Siga as instruções do README.md para entender o funcionamento do LED L.
 */

void setup() {
  // Configura o pino 13 (conectado ao LED "L" embutido na placa) como saída
  pinMode(13, OUTPUT);
}

void loop() {
  // Liga o LED (HIGH envia 5V para o pino)
  digitalWrite(13, HIGH);
  delay(1000); // Aguarda 1 segundo (1000 milissegundos)
  
  // Desliga o LED (LOW envia 0V/GND para o pino)
  digitalWrite(13, LOW);
  delay(1000); // Aguarda mais 1 segundo
}
