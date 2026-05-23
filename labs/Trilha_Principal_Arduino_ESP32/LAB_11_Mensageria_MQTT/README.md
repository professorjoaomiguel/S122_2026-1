# LAB 11: Mensageria IoT (Protocolo MQTT)

Neste laboratório, abandonamos o modelo de requisição (HTTP) e adotamos o padrão industrial de IoT: **Publicação e Assinatura (Pub/Sub)** via protocolo **MQTT**. É aqui que o dado da sua estufa realmente ganha escala global de forma gratuita.

---

## 🎯 Objetivos Técnicos
*   Configurar a biblioteca `PubSubClient` no ESP32.
*   Publicar dados de telemetria em um Broker Público (HiveMQ).
*   Validar o recebimento das mensagens via **HiveMQ Web Client**.

---

## 🧱 Setup de Hardware
*   **Hardware:** ESP32 DevKit v4 conectado ao WiFi `Wokwi-GUEST`.
*   **Broker:** `broker.hivemq.com` (Porta 1883).

---

## ⚙️ Workflow Passo a Passo

### Nível 1: Conexão ao Broker
1.  Importe a biblioteca `PubSubClient`.
2.  Implemente a função `reconnect()` para garantir que o ESP32 sempre tente se reconectar ao broker se a rede cair.

### Nível 2: Publicação (Telemetria)
1.  Defina um tópico único (ex: `s122/SEU_NOME/estufa/temp`).
2.  Envie um valor fixo a cada 5 segundos e verifique no [Web Client do HiveMQ](http://www.hivemq.com/demos/websocket-client/).

### Nível 3: Integração Real
1.  Substitua o valor fixo pela leitura real de um sensor simulado (conforme LAB 05).

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = "broker.hivemq.com";
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin("Wokwi-GUEST");
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) { /* logica de reconexao */ }
  client.loop();
  client.publish("s122/teste/estufa", "25.5");
  delay(5000);
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este laboratório representa a **Telemetria de Campo**:
- O dado agora não fica preso no hardware; ele é "lançado" na nuvem. O Dashboard (LAB 12) estará apenas esperando para "agarrar" esse dado e mostrá-lo.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de TI de Pelotas/Santa Maria**, como o protocolo MQTT permite que milhares de sensores de fazendas inteligentes enviem dados para uma central sem sobrecarregar a rede?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Crie um segundo tópico de **Comando** (ex: `.../estufa/comando`). Faça o ESP32 **assinar** (subscribe) este tópico e ligar um LED quando receber a mensagem "ON".
2.  Por que o MQTT é considerado mais "leve" que o HTTP para dispositivos movidos a bateria?

---

## 🛣️ Bifurcação: Hora de Versionar seu Código!
Este código já possui uma complexidade considerável. Você já pensou em salvá-lo no seu GitHub pessoal?
👉 [**Acesse o Guia Profissional de VS Code + Git aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Print:** Screenshot do HiveMQ Web Client mostrando as mensagens recebidas.

---
*UC S122 - Internet das Coisas*
