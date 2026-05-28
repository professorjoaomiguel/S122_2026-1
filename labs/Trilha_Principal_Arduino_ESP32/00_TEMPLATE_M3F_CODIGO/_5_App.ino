/*
 * =====================================================================
 * S122 - Internet das Coisas | Faculdade de Tecnologia SENAI
 * _5_App.ino - Camada de Aplicação (Payload JSON, Publicação e Comandos)
 * =====================================================================
 */

#include "Bibliotecas.h"

// --- ENVIO DE DADOS (TELEMETRIA) ---
void publicarDados() {
  unsigned long now = millis();
  
  if (now - lastSendTime >= sendInterval || lastSendTime == 0) {
    lastSendTime = now;
    
    if (client.connected()) {
      // Cria o payload em formato JSON puro para fácil leitura no Node-RED
      String payload = "{";
      payload += "\"temperatura\":" + String(temperatura, 1) + ",";
      payload += "\"umidade\":" + String(umidade, 1) + ",";
      payload += "\"luminosidade\":" + String(luminosidade) + ",";
      payload += "\"rele\":" + String(estadoRele ? "true" : "false");
      payload += "}";
      
      Serial.print("[Nível 5 - Aplicação] Publicando telemetria: ");
      Serial.println(payload);
      
      client.publish(TOPIC_TELEMETRIA, payload.c_str());
    } else {
      Serial.println("[Nível 5 - ALERTA] Não foi possível publicar: Broker desconectado.");
    }
  }
}

// --- RECEBIMENTO DE COMANDOS (SUBSCRIBE CALLBACK) ---
void callbackApp(char* topic, byte* payload, unsigned int length) {
  Serial.print("[Nível 5 - Aplicação] Mensagem recebida no tópico [");
  Serial.print(topic);
  Serial.print("]: ");
  
  String mensagem = "";
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }
  Serial.println(mensagem);
  
  // Trata o comando recebido para atuar na borda
  if (String(topic) == TOPIC_COMANDO) {
    mensagem.trim();
    if (mensagem == "ON" || mensagem == "1") {
      Serial.println("[Nível 5] COMANDO RECEBIDO: Ligar Ventoinha (Relé)");
      estadoRele = true;
      digitalWrite(RELEPIN, HIGH);
      digitalWrite(LEDPIN, HIGH);
      
      // Atualiza o LCD local com aviso de comando remoto
      lcd.setCursor(11, 1);
      lcd.print("[REM]");
    } else if (mensagem == "OFF" || mensagem == "0") {
      Serial.println("[Nível 5] COMANDO RECEBIDO: Desligar Ventoinha (Relé)");
      estadoRele = false;
      digitalWrite(RELEPIN, LOW);
      digitalWrite(LEDPIN, LOW);
      
      // Atualiza o LCD local
      lcd.setCursor(11, 1);
      lcd.print("[AUT]");
    }
  }
}
