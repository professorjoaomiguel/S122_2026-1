#include <WiFi.h>
#include "time.h"

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* ntpServer = "pool.ntp.org";

void setup() {
  Serial.begin(115200);
  
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Configura sincronização de hora
  configTime(0, 0, ntpServer);
}

void loop() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Erro ao obter hora!");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  delay(5000);
}