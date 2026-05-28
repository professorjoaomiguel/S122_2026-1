/*
 * =====================================================================
 * S122 - Internet das Coisas | Faculdade de Tecnologia SENAI
 * 00_TEMPLATE_M3F_CODIGO.ino - Orquestrador Principal (Loop/Setup)
 * =====================================================================
 */

#include "Bibliotecas.h"

// --- INSTANCIAÇÃO DAS CONFIGURAÇÕES DE REDE ---
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

// --- INSTANCIAÇÃO DOS TÓPICOS MQTT ---
const char* TOPIC_TELEMETRIA = "s122/estufa/dados";   // PUBLISH
const char* TOPIC_COMANDO = "s122/estufa/comando";     // SUBSCRIBE

// --- INSTANCIAÇÃO DOS OBJETOS ---
WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- INSTANCIAÇÃO DAS VARIÁVEIS ---
float temperatura = 0.0;
float umidade = 0.0;
int luminosidade = 0;
bool estadoRele = false;
unsigned long lastSendTime = 0;
const unsigned long sendInterval = 5000; // Envio a cada 5 segundos

// --- DECLARAÇÃO DE FUNÇÕES DOS NÍVEIS ---
void setupEdge();
void loopEdge();
void setupConectividade();
void monitorarConectividade();
void setupMensageria();
void processarMensageria();

void setup() {
  Serial.begin(115200);
  Serial.println("\n--- [M3F] Inicializando Sistema IoT ---");
  
  // 1. Inicializa o Edge (Nível 1 - Sensores e Atuadores)
  setupEdge();
  
  // 2. Inicializa a Rede WiFi (Nível 2 - Conectividade)
  setupConectividade();
  
  // 3. Inicializa o MQTT (Nível 3/4 - Mensageria)
  setupMensageria();
  
  Serial.println("--- Sistema IoT Pronto! ---");
}

void loop() {
  // 1. Executa a leitura local e controle autônomo (Nível 1)
  loopEdge();
  
  // 2. Garante a saúde da conexão WiFi (Nível 2)
  monitorarConectividade();
  
  // 3. Mantém a conexão com o broker MQTT (Nível 3/4)
  processarMensageria();
}
