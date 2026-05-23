#include <WiFi.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WiFiServer server(80);
const int relayPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }

  Serial.println("\nWiFi conectado!");
  Serial.print("IP: "); Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("<h1>Controle de Luz S122</h1>");
            client.print("<p><a href=\"/H\">Ligar Lâmpada</a></p>");
            client.print("<p><a href=\"/L\">Desligar Lâmpada</a></p>");
            client.println();
            break;
          } else { currentLine = ""; }
        } else if (c != '\r') { currentLine += c; }

        if (currentLine.endsWith("GET /H")) digitalWrite(relayPin, HIGH);
        if (currentLine.endsWith("GET /L")) digitalWrite(relayPin, LOW);
      }
    }
    client.stop();
  }
}