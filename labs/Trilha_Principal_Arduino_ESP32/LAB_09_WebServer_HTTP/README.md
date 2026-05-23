# LAB 09: Controle Web Embarcado (HTTP Server)

Nesta etapa, transformamos o ESP32 em um **Servidor de Páginas Web**. Isso permite que qualquer dispositivo conectado à mesma rede (Smartphone ou PC) acesse um painel de controle direto no hardware, sem depender de nuvens externas.

---

## 🎯 Objetivos Técnicos
*   Implementar um Servidor HTTP no ESP32 (`WiFiServer`).
*   Interagir com o hardware via requisições do tipo **GET**.
*   Controlar um **Relé** para acionamento de cargas de alta potência.

---

## 🧱 Setup de Hardware
*   **Relé (Relay):** Conectado ao pino **13**.
*   **Lâmpada (Bulb):** Ligada nos contatos do relé (simulação de carga).

---

## ⚙️ Workflow Passo a Passo

### Nível 1: Hello Web
1.  Inicie o servidor na porta 80.
2.  Faça o ESP32 responder "Bem-vindo ao IoT S122" para qualquer navegador que acessar seu IP.

### Nível 2: HTML com Ação
1.  Crie dois links HTML na página: "LIGAR" e "DESLIGAR".
2.  Associe esses links às rotas `/H` e `/L`.

### Nível 3: Interpretação de Comandos
1.  Implemente a lógica que lê a URL solicitada pelo navegador.
2.  Se a URL terminar em `GET /H`, ligue o Relé. Se for `GET /L`, desligue.

```cpp
#include <WiFi.h>
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
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
            client.println("HTTP/1.1 200 OK\nContent-type:text/html\n\n<h1>Controle</h1><a href=\"/H\">Ligar</a> | <a href=\"/L\">Desligar</a>");
            break;
          } else linha = "";
        } else if (c != '\r') linha += c;

        if (linha.endsWith("GET /H")) digitalWrite(13, HIGH);
        if (linha.endsWith("GET /L")) digitalWrite(13, LOW);
      }
    }
    client.stop();
  }
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este laboratório representa o **Modo de Manutenção Local**:
- Imagine que a internet global caiu. O produtor ainda pode se aproximar da estufa e, via rede local, forçar o acionamento dos ventiladores através desta página de emergência no celular.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL Metal-Mecânico da Serra Gaúcha**, como um técnico poderia usar o smartphone para acessar o status de uma máquina sem precisar abrir o painel elétrico?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Adicione um campo na página HTML que mostre o **Estado Atual** do relé (LIGADO ou DESLIGADO).
2.  O que acontece se dois navegadores tentarem acessar o ESP32 ao mesmo tempo?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Screenshot:** Print da página web aberta no seu navegador.

---
*UC S122 - Internet das Coisas*
