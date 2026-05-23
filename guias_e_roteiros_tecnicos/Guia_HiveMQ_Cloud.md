# HiveMQ (Cloud MQTT) - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Broker MQTT público na nuvem utilizado para interconexão instantânea de dispositivos IoT sem necessidade de infraestrutura local.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog/Cloud) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
Para entender como esta ferramenta se comunica no ecossistema:
- **Entrada (Input):** Mensagens MQTT publicadas por dispositivos Edge (ESP32/Wokwi) ou Aplicações (Node-RED).
- **Saída (Output):** Encaminhamento de mensagens para clientes inscritos (Subscribers).

## 3. Instalação e Configuração

### ☁️ Cloud (Sem Instalação)
1.  **Endereço do Broker:** `broker.hivemq.com`
2.  **Portas Suportadas:**
    - `1883`: MQTT padrão (Não criptografado).
    - `8883`: MQTT sobre TLS/SSL (Seguro).
    - `8000`: WebSockets (Para dashboards web).
3.  **Verificação:** Acesse o [HiveMQ Web Client](https://www.hivemq.com/demos/websocket-client/) para testar a publicação/assinatura diretamente no navegador.

## 4. Integração (Ecossistema S122)
Esta ferramenta se relaciona com outros guias da seguinte forma:
- **Conecta com:** [Wokwi] para receber dados simulados.
- **Conecta com:** [Node-RED] para visualização e lógica de dashboard.

**Links Relacionados (CORE):**
- Guia de Ferramentas: Guia_Ferramentas_e_Software.md
- Guia Wokwi: Guia_Wokwi_Simulacao.md

## 5. Referências e Repositórios
- **Página Oficial:** [https://www.hivemq.com/public-mqtt-broker/](https://www.hivemq.com/public-mqtt-broker/)
- **Documentação:** [https://www.hivemq.com/docs/](https://www.hivemq.com/docs/)

## 6. Solução de Problemas (Troubleshooting)
- **Erro Comum:** Conexão recusada na porta 1883 em redes corporativas/acadêmicas.
- **Solução:** Tente utilizar a porta 8883 ou WebSockets (porta 8000).

## 7. Fontes de Consulta (AI & Web)
- Documentação Wokwi MQTT.
- HiveMQ Blog: "MQTT Essentials".

---
*Documento em constante atualização. Versão: 2026/1*
