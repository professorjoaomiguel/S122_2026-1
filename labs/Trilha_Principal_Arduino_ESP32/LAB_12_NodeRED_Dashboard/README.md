# LAB 12: Orquestração e Dashboards (Node-RED)

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** ☁️ Camada 3: Cloud (Aplicação e Analytics)
*   **Nível de Referência:** 📍 Nível 6: Exibição (Orquestração e Dashboards no Node-RED)

---

Bem-vindo à camada de **Aplicação**. Aqui, transformamos dados brutos em interfaces visuais. O Node-RED é nossa ferramenta "Low-Code" para unir o hardware à nuvem usando os famosos "fiozinhos" lógicos.

---

## 🎯 Objetivos Técnicos
*   Utilizar o Node-RED para assinar tópicos MQTT externos.
*   Tratar payloads de texto/JSON e converter para formatos visuais.
*   Desenvolver um Dashboard profissional com Gauges e Gráficos históricos.

---

## 🏗️ Arquitetura da Prática
`[ESP32 no Wokwi]` ➡️ `[Broker: hivemq.com]` ⬅️ `[Node-RED Local]` ➡️ `[Dashboard Web]`

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: A Escuta (MQTT In)
1.  Inicie o Node-RED (`npx node-red`).
2.  Arraste o nó **mqtt in**. Configure o servidor `broker.hivemq.com`.
3.  Assine o tópico usado no **LAB 11**. Conecte a um nó **debug** e verifique se os dados estão chegando na aba lateral.

### 🚀 Passo 2: O Visual (Dashboard)
1.  Instale a paleta `node-red-dashboard` via "Manage Palette".
2.  Arraste um nó **gauge** e um nó **chart**.
3.  Conecte a saída do MQTT In em ambos.

### 🚀 Passo 3: Formatação
1.  Configure as unidades (C, %) e as cores dos níveis (Verde = Ideal, Vermelho = Crítico) no nó de Gauge.

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este é o **Centro de Controle do Produtor**. Aqui ele monitora a saúde das plantas de qualquer lugar do mundo, visualizando o histórico de temperatura das últimas horas para tomar decisões de manejo.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL de TI e Eletrônica de Canoas**, como o Node-RED agiliza a criação de protótipos de dashboards para gestores que precisam de dados de produção em tempo real?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Adicione um nó de **Notificação (Toast)** que exiba um alerta na tela do dashboard sempre que a temperatura recebida for maior que 30°C.
2.  Qual a vantagem de ter o Dashboard rodando fora do ESP32 (em um servidor Node-RED)?

---

## 🛣️ Bifurcação: Versionando Fluxos
Sabia que você pode exportar seu fluxo do Node-RED como um arquivo JSON e salvá-lo no Git? Isso é o que chamamos de "Infrastructure as Code".
👉 [**Acesse o Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Print do Fluxo:** Screenshot dos nós conectados.
*   **Print do Dashboard:** Foto da interface exibindo os dados em tempo real.

---
*UC S122 - Internet das Coisas*
