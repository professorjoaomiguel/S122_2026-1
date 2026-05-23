#include <WiFi.h>
#include <DHT.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

WiFiServer server(80);
const int relayPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
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
            float h = dht.readHumidity();
            float t = dht.readTemperature();
            
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("<h1>Dashboard IoT S122</h1>");
            client.print("<p><b>Temp:</b> " + String(t) + " C</p>");
            client.print("<p><b>Umid:</b> " + String(h) + " %</p>");
            client.print("<p><a href=\"/H\">Ligar Relé</a> | <a href=\"/L\">Desligar Relé</a></p>");
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