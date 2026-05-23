# LAB 08: Conectividade WiFi e Tempo (NTP)

O sistema sai do isolamento. Nesta etapa, conectamos o cérebro da nossa solução à rede global, permitindo que ele saiba "quem ele é" (IP) e "que horas são" (NTP).

---

## 🎯 Objetivos Técnicos
*   Configurar o ESP32 como Cliente Wi-Fi na rede `Wokwi-GUEST`.
*   Obter um endereço IP via DHCP.
*   Sincronizar o relógio interno via protocolo **NTP (Network Time Protocol)**.

---

## 🧱 Setup de Hardware
*   **Processador:** ESP32 DevKit v4.
*   **Rede:** WiFi Virtual do Wokwi (Sem senha).

---

## ⚙️ Workflow Passo a Passo

### Nível 1: O Handshake de Rede
1.  Abra um 🚀 [**Projeto Vazio: ESP32**](https://wokwi.com/projects/new/esp32).
2.  Utilize a biblioteca `WiFi.h`.
2.  Inicie a conexão e faça o código "travar" com um loop `while` até que o status seja `WL_CONNECTED`.

### Nível 2: Identificação (IP)
1.  Imprima no Serial Monitor o endereço IP que o simulador atribuiu ao seu ESP32.

### Nível 3: Sincronização de Tempo
1.  Utilize o servidor `pool.ntp.org`.
2.  Formate a saída para exibir Data e Hora legíveis (ex: DD/MM/AAAA HH:MM:SS).

```cpp
#include <WiFi.h>
#include "time.h"

const char* ssid = "Wokwi-GUEST";
const char* ntpServer = "pool.ntp.org";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nWiFi Conectado!");
  configTime(0, 0, ntpServer);
}

void loop() {
  struct tm timeinfo;
  if(getLocalTime(&timeinfo)){
    Serial.println(&timeinfo, "%d/%m/%Y %H:%M:%S");
  }
  delay(10000);
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este é o nascimento do **Gateway de Borda**:
- **Conectividade:** Permite que a estufa envie alertas para o produtor em qualquer lugar do mundo.
- **Timestamp:** O dado de temperatura agora terá um "carimbo de tempo" real, permitindo saber exatamente quando um evento ocorreu.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de Automação e Controle em Porto Alegre/Canoas**, como a sincronização NTP é usada para garantir que todos os equipamentos de uma fábrica tenham o mesmo horário em seus logs de erro?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Como você ajustaria o código para o fuso horário de **Brasília (GMT -3)**? Pesquise sobre o parâmetro `gmtOffset_sec`.
2.  O que acontece se o roteador WiFi for desligado após o ESP32 já estar conectado? O código continua funcionando?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Print do Serial:** Mostre o IP recebido e a hora sincronizada.

---
*UC S122 - Internet das Coisas*
