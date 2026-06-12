// LAB 04B - Solucao de Referencia
// Demonstra: Blink + Serial Monitor + informacoes do chip ESP32

#include "esp_system.h" // Necessario para getCpuFrequencyMhz() e ESP.getFreeHeap()

void setup() {
  Serial.begin(115200);
  delay(1000); // Aguarda a Serial estabilizar

  Serial.println("========================================");
  Serial.println("  LAB 04B - Apresentacao do ESP32");
  Serial.println("========================================");

  // Informacoes do chip
  Serial.print("Nucleo em execucao: ");
  Serial.println(xPortGetCoreID()); // Core 0 ou Core 1

  Serial.print("Frequencia do CPU: ");
  Serial.print(getCpuFrequencyMhz());
  Serial.println(" MHz");

  Serial.print("Memoria Heap livre: ");
  Serial.print(ESP.getFreeHeap());
  Serial.println(" bytes");

  Serial.print("Tamanho da Flash: ");
  Serial.print(ESP.getFlashChipSize() / 1024 / 1024);
  Serial.println(" MB");

  Serial.println("========================================");
  Serial.println("Iniciando Blink no GPIO 2 (LED azul)...");
  Serial.println("========================================");

  pinMode(2, OUTPUT); // Pino 2 como saida (LED azul)
}

void loop() {
  Serial.println("LED ligado!");
  digitalWrite(2, HIGH);
  delay(1000);

  Serial.println("LED desligado!");
  digitalWrite(2, LOW);
  delay(1000);
}
