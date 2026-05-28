# 🏛️ Template de Código Modularizado: Arquitetura M3F / TPM
**S122 - Internet das Coisas (IoT)**  
**Faculdade de Tecnologia SENAI Porto Alegre**  

---

## 🧭 Apresentação
Este template serve para que você aprenda a programar o firmware do seu nó de borda (**ESP32**) seguindo de forma rigorosa as **camadas do modelo M3F**. Em vez de criarmos códigos monolíticos gigantescos (tudo em um único arquivo `.ino`), dividimos a lógica técnica em abas/arquivos baseados no modelo de camadas de rede. 

Isso garante **alta reusabilidade de código**, **organização profissional** e **fácil depuração de problemas**.

---

## 📂 Estrutura das Abas de Código

```text
├── 00_TEMPLATE_M3F_CODIGO.ino   <-- Orquestrador principal. Contém apenas setup() e loop() gerais.
├── _1_Phy.ino                    <-- Camada Física (Edge). Leitura de sensores locais e atuação imediata.
├── _2_Mac.ino                    <-- Camada MAC. Gerência da conectividade física local (Rede WiFi).
├── _3_Net.ino                    <-- Camada de Rede. (Opcional, resolvida por IP ou tabelas de roteamento).
├── _4_Transp.ino                 <-- Camada de Transporte. Configuração e reconexão não-bloqueante do MQTT.
├── _5_App.ino                    <-- Camada de Aplicação. Formatação de payloads em JSON e callbacks de comando.
└── Bibliotecas.h                 <-- Cabeçalho Global. Contém todos os pinos, includes e variáveis externs.
```

---

## 🛠️ Como utilizar no Wokwi ou VS Code?

### No Wokwi (Navegador):
1.  Abra seu simulador Wokwi.
2.  Crie uma aba para cada um dos arquivos listados acima.
3.  Copie o respectivo conteúdo para cada aba.
4.  Execute a simulação!

### No VS Code / PlatformIO:
1.  Adicione as bibliotecas `PubSubClient`, `DHT sensor library` e `LiquidCrystal_I2C` ao seu arquivo `platformio.ini`.
2.  Coloque todos os arquivos na pasta `src/` do seu projeto.
3.  Compile e faça o upload!

---

## 💡 Princípios Técnicos do M3F neste Código:

### 1. Independência de Temporização
O microcontrolador lê os sensores físicos a cada **2 segundos** (`loopEdge()` em `_1_Phy.ino`), exibindo-os na tela do LCD de forma imediata. Contudo, os dados são enviados para a rede apenas a cada **5 segundos** (`publicarDados()` em `_5_App.ino`). Isso economiza processamento e evita spam no broker.

### 2. Controle Autônomo e Segurança Borda-Nuvem
Se a conexão WiFi ou o Broker MQTT caírem, a estufa **não para de funcionar**! O loop em `_1_Phy.ino` executa a automação de emergência (Histerese para ligar e desligar a ventoinha/relé) de forma 100% autônoma, garantindo a proteção da plantação (regras do especialista).

### 3. Reconexão Não-Bloqueante
A reconexão com o Broker MQTT (`_4_Transp.ino`) é feita sem o uso de `delay()` ou loops infinitos de travamento. O ESP32 tenta se reconectar a cada 5 segundos apenas se perder a conexão, permitindo que a CPU continue controlando a temperatura e atualizando o LCD local normalmente.

---
*Faculdade de Tecnologia SENAI Porto Alegre - Prof. João Miguel*
