#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Estufa IoT - Inicializando Sensores...");
}

void loop() {
  // Leitura dos dados do sensor
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  int luminosidade = analogRead(LDRPIN);

  // Validação
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler DHT22!");
    delay(2000);
    return;
  }

  // Exibição dos dados no Monitor Serial
  Serial.print("Temp: ");
  Serial.print(temperatura, 1);
  Serial.print(" C | Umid: ");
  Serial.print(umidade, 1);
  Serial.print(" % | Luz (LDR): ");
  Serial.println(luminosidade);

  delay(2000); // O DHT22 precisa de pelo menos 2s entre leituras
}