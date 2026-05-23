# LAB 10: Dashboard de Borda (Edge Dashboard)

---

## 🚀 Como Iniciar?
Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Nesta etapa de consolidação do Módulo 02, unimos o **Monitoramento** (Sensores) com o **Controle** (Atuadores) em uma única interface web rica. O ESP32 atua como um verdadeiro **Dashboard de Borda**.

---

## 🎯 Objetivos Técnicos
*   Integrar leitura de sensores digitais (**DHT22**) em uma página HTML dinâmica.
*   Criar uma interface de controle bidirecional (Status + Ação).
*   Consolidar o conceito de **Edge Computing** (Processamento local).

---

## 🧱 Setup de Hardware
*   **Sensor:** DHT22 no pino **15**.
*   **Atuador:** Relé no pino **13**.

---

## ⚙️ Workflow Passo a Passo

### Nível 1: Telemetria HTML
1.  Integre a leitura do DHT22 ao código do servidor.
2.  Exiba os valores de Temperatura e Umidade no corpo da página HTML.

### Nível 2: Interface Amigável
1.  Utilize tags HTML como `<b>` e `<button>` para melhorar o visual.
2.  Crie uma separação visual (`<hr>`) entre os dados e os botões.

### Nível 3: Consolidação Final
1.  Verifique se o sistema responde rapidamente às mudanças de temperatura no simulador e se os botões acionam o relé corretamente.

```cpp
#include <WiFi.h>
#include <DHT.h>
#define DHTPIN 15
DHT dht(DHTPIN, DHT22);
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  dht.begin();
  WiFi.begin("Wokwi-GUEST");
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String linha = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (linha.length() == 0) {
            float t = dht.readTemperature();
            client.println("HTTP/1.1 200 OK\nContent-type:text/html\n\n<h1>Estufa S122</h1>");
            client.print("<p>Temp: " + String(t) + " C</p><hr>");
            client.print("<a href=\"/H\"><button>Ligar</button></a>");
            break;
          } else linha = "";
        } else if (c != '\r') linha += c;
        if (linha.endsWith("GET /H")) digitalWrite(13, HIGH);
      }
    }
    client.stop();
  }
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este é o **Módulo de Operação Local**:
- **Monitoramento:** O produtor vê se o clima está ideal.
- **Intervenção:** Ele pode ligar a ventoinha manualmente através do celular, caso a lógica automática precise de um reforço.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de Alimentos e Bebidas em Porto Alegre**, como um supervisor poderia usar um tablet para monitorar a temperatura de uma câmara fria via Wi-Fi sem precisar de um servidor central?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Como fazer para que a página se atualize sozinha a cada 5 segundos? Pesquise sobre a tag `<meta http-equiv="refresh" content="5">`.
2.  O que acontece com o código se a leitura do DHT22 retornar `NaN` (Not a Number)? Como tratar isso?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Screenshot:** Print do navegador exibindo os dados dos sensores e botões.

---
*UC S122 - Internet das Coisas*
