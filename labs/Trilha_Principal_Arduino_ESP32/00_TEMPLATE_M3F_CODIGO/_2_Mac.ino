/*
 * =====================================================================
 * S122 - Internet das Coisas | Faculdade de Tecnologia SENAI
 * _2_Mac.ino - Camada MAC / Conectividade (Rede WiFi)
 * =====================================================================
 */

#include "Bibliotecas.h"

void setupConectividade() {
  Serial.print("[Nível 2 - Conectividade] Conectando ao WiFi: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  // Aguarda conexão
  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED && tentativas < 15) {
    delay(500);
    Serial.print(".");
    tentativas++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n[Nível 2] Conectado com sucesso!");
    Serial.print("[Nível 2] Endereço IP local: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n[Nível 2 - ALERTA] Não foi possível conectar ao WiFi de forma síncrona. O sistema tentará em segundo plano.");
  }
}

void monitorarConectividade() {
  // Se o WiFi cair, monitora e aguarda o loop automático do ESP32 tentar a reconexão
  if (WiFi.status() != WL_CONNECTED) {
    static unsigned long lastCheck = 0;
    unsigned long now = millis();
    
    if (now - lastCheck >= 10000) { // Loga o status de desconexão a cada 10s
      lastCheck = now;
      Serial.println("[Nível 2 - ALERTA] WiFi desconectado! Tentando reconexão automática...");
    }
  }
}
