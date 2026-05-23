# 🌿 Projeto Integrador: Estufa Inteligente S122

Este guia apresenta o cenário central da disciplina S122. A **Estufa Inteligente** é o fio condutor que une todas as tecnologias do modelo M3F, partindo do sensor físico no **Edge** até a visualização analítica na **Cloud**.

---

## 📖 O Cenário (O Problema)
Produtores de mudas sensíveis precisam manter condições climáticas rígidas para garantir a produtividade. O desafio é monitorar e controlar:
1. **Temperatura:** Evitar o superaquecimento.
2. **Umidade do Solo:** Garantir a hidratação sem desperdício.
3. **Luminosidade:** Suplementar luz em dias nublados.
4. **Segurança:** Detectar a abertura de portas ou presença não autorizada.

---

## 🏭 Conexão com a Realidade: APLs do Rio Grande do Sul
A **Estufa Inteligente** é o nosso modelo didático, mas o verdadeiro desafio da disciplina é aplicar esta mesma **Jornada do Dado (Sensor à Nuvem)** para resolver uma "dor" real da indústria gaúcha.

Cada grupo deverá identificar um **Arranjo Produtivo Local (APL)** do RS e adaptar os conceitos da estufa para esse cenário.

### Exemplos de "Ganchos" para Adaptação:
*   **🍇 Vitivinicultura (Serra Gaúcha):** Como monitorar a temperatura e umidade da adega para garantir a maturação do vinho?
*   **⚙️ Metal-Mecânico (Caxias/Canoas):** Como detectar vibração ou aquecimento excessivo em um torno CNC usando sensores IoT?
*   **👟 Coureiro-Calçadista (Vale do Sinos):** Como monitorar os gases e a umidade no processo de colagem e secagem de calçados?
*   **🌾 Agronegócio (Região Central/Sul):** Como o monitoramento de silos de grãos pode evitar perdas por umidade?

---

## 🗺️ A Jornada Vertical (Sensor à Nuvem)

Nossa jornada é dividida em **etapas incrementais**, onde cada laboratório adiciona um "tijolo" na construção deste ecossistema.

### 🏗️ Fase 1: Percepção e Controle Local (Edge)
*Foco: Hardware e Lógica de Programação (Arduino Uno / ESP32).*
- **Nível 1:** Sinal de presença (Pushbutton + LED).
- **Nível 2:** Monitoramento de Clima (Leitura de DHT22 e LDR).
- **Nível 3:** Interface de Usuário Local (Exibição em LCD I2C).
- **Nível 4:** Atuação Local (Relé/Ventoinha ativado por temperatura).

### 🏗️ Fase 2: Conectividade e Mensageria (Transporte)
*Foco: Redes e Protocolos (ESP32 + WiFi + MQTT).*
- **Nível 5:** Conectar a Estufa à rede WiFi virtual do Wokwi.
- **Nível 6:** Publicar os dados da estufa em um **Broker MQTT** (Telemetria).
- **Nível 7:** Assinar tópicos de comando para controle remoto (Comando).

### 🏗️ Fase 3: Orquestração e Dashboards (Cloud/Fog)
*Foco: Processamento e Interface (Node-RED + Grafana).*
- **Nível 8:** Instalação do Node-RED via `npx`.
- **Nível 9:** Criação do **Dashboard de Monitoramento** (Gauges e Gráficos).
- **Nível 10:** Controle de Atuadores via Switch Web.

---

## 🛠️ Arquitetura Técnica Proposta

| Camada | Tecnologia | Função no Projeto |
| :--- | :--- | :--- |
| **Edge** | ESP32 / Arduino | Coleta de dados e atuação física. |
| **Protocolo** | MQTT | "Correio" que leva o dado do sensor ao dashboard. |
| **Fog** | Node-RED (Local) | Cérebro que decide o que fazer com o dado. |
| **Cloud** | TagoIO / Grafana | Visão histórica e analítica para o produtor. |

---

## 🚀 Como usar este guia
Este não é um guia de "passo a passo" único, mas sim o **contexto** para todos os seus laboratórios. Sempre que estiver fazendo um código no Wokwi ou um fluxo no Node-RED, lembre-se: **você está construindo uma parte da Estufa Inteligente.**

---
*Faculdade de Tecnologia SENAI Porto Alegre - Prof. João Miguel*
