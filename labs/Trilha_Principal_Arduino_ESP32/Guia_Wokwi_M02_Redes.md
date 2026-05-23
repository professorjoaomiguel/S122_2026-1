# Guia Wokwi Módulo 02 - Redes e Arquitetura M3F (IoT S122)

Este módulo é o divisor de águas entre eletrônica básica e Internet das Coisas. Vamos entender como o Wokwi simula o transporte de dados, o primeiro passo para a nossa arquitetura **M3F (Multilayer Fog/Cloud Framework)**.

---

## 🌐 1. Virtualização de Rede Wi-Fi
O ESP32 possui uma interface de rádio interna que, no Wokwi, é virtualizada via software.
*   **A Rede `Wokwi-GUEST`:** É uma rede aberta fictícia que o simulador fornece.
*   **SSID e Senha:** No seu código, você deve usar `SSID = "Wokwi-GUEST"` e `PASSWORD = ""`.
*   **Conectividade Real:** O ESP32 simulado pode enviar dados para servidores reais na internet (como o Broker MQTT da HiveMQ ou o Firebase da Google).

---

## 🌉 2. O Wokwi Gateway e a Camada Fog
Diferente da simulação padrão, onde o ESP32 é um "cliente", para que o seu computador acesse o ESP32 (ex: via WebServer local), você precisa de um túnel.
*   **O Problema:** O seu browser no Windows está em uma rede `192.168.x.x` e o Wokwi está em uma rede virtual `10.10.x.x`. Eles não se vêem.
*   **A Solução (Manual):** Use o link dinâmico gerado no Serial Monitor do Wokwi que começa com `https://wokwi.com/v/bridge/...`.
*   **A Solução (Profissional):** Instalar o executável `wokwigw` (Wokwi Gateway) localmente, que cria uma ponte real entre as redes.

---

## 📶 3. Protocolos Suportados na S122
Para validar a arquitetura M3F, usaremos:
1.  **HTTP/HTTPS:** Para WebServers de borda (Edge Control).
2.  **MQTT:** O protocolo mestre da IoT. O Wokwi permite conectar a qualquer broker público via porta `1883`.
3.  **NTP:** Para sincronização de relógio mundial simulada.

### 🛑 Limitações de Rede
*   O Wokwi não suporta **Multicast (mDNS)** nativamente. Ou seja, você não pode chamar `esp32.local` no browser simulado. Use sempre o IP fixo fornecido.

---

## 🧩 4. Integração M3F: O Salto Técnico
Na arquitetura M3F, o Wokwi valida:
*   **Camada Edge (Percepção):** O código roda e lê os sensores.
*   **Camada Fog Bridge (Transporte):** O dado sai do ESP32 via Wi-Fi simulado e atinge o Gateway.
*   **Validação Cloud:** O dado chega em um Dashboard externo (ex: Adafruit IO ou Ubidots) vindo do simulador.

---

## 🛠️ Solução de Problemas (Troubleshooting M02)
*   **WiFi não conecta (Loop infinito)?** Verifique se o Serial Monitor está aberto. O processo de conexão Wi-Fi só ocorre enquanto a simulação está ativa e visível.
*   **MQTT falha (Connection Refused)?** Use brokers públicos na porta `1883`. Evite portas com SSL (`8883`) no início, pois a gestão de certificados no ESP32 simulado é pesada.
*   **Dados não chegam no Cloud?** Verifique se o seu computador tem acesso livre à internet (firewalls de empresas podem bloquear o tráfego do simulador).

---
### 🔗 Navegação do Ecossistema Wokwi S122
- **[🏠 Índice Mestre](./Wokwi_Master_Index.md)**
- **[📖 Manual de Laboratório (Práticas)](./Wokwi_Lab_Manual_S122.md)**
- **[🟢 Módulo 01: Fundamentos](./Guia_Wokwi_M01_Fundamentos.md)**
- **[🔵 Módulo 02: Redes e M3F](./Guia_Wokwi_M02_Redes.md)**
- **[🔴 Módulo 03: Workflow Profissional](./Guia_Wokwi_M03_Profissional.md)**

---
*Versão 2026/1 - Prof. João Miguel*
