/*
 * =====================================================================
 * S122 - Internet das Coisas | Faculdade de Tecnologia SENAI
 * _4_Transp.ino - Camada de Transporte (Conexão MQTT e Soquetes)
 * =====================================================================
 */

#include "Bibliotecas.h"

// Callback de recebimento de comandos do broker (será definido na camada de Aplicação)
void callbackApp(char* topic, byte* payload, unsigned int length);

void setupMensageria() {
  Serial.print("[Nível 4 - Transporte] Configurando Servidor MQTT: ");
  Serial.println(mqtt_server);
  
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callbackApp);
}

void reconectarMQTT() {
  // Loop até conectar com limite de tentativas por iteração
  static unsigned long lastReconnectAttempt = 0;
  unsigned long now = millis();
  
  if (!client.connected()) {
    if (now - lastReconnectAttempt >= 5000 || lastReconnectAttempt == 0) { // Tenta conectar a cada 5s sem travar o loop
      lastReconnectAttempt = now;
      
      if (WiFi.status() == WL_CONNECTED) {
        Serial.print("[Nível 4] Tentando se conectar ao Broker MQTT...");
        
        // Cria um ID de cliente único usando o endereço MAC do ESP32
        String clientID = "S122-EstufaClient-" + String((uint32_t)ESP.getEfuseMac(), HEX);
        
        if (client.connect(clientID.c_str())) {
          Serial.println(" Conectado!");
          
          // Assina o tópico de comandos locais assim que conecta
          client.subscribe(TOPIC_COMANDO);
          Serial.print("[Nível 4] Tópico assinado: ");
          Serial.println(TOPIC_COMANDO);
        } else {
          Serial.print(" Falhou. Erro = ");
          Serial.print(client.state());
          Serial.println(" (Tentará novamente em 5 segundos)");
        }
      }
    }
  }
}

void processarMensageria() {
  // Se perder a conexão com o broker MQTT, executa a rotina de reconexão não-bloqueante
  if (!client.connected()) {
    reconectarMQTT();
  }
  
  // Mantém o keep-alive do MQTT ativo e processa novos pacotes recebidos
  client.loop();
}
