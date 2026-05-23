# MQTT Brokers e Conectividade - Guia Técnico S122
`#MQTT` `#Broker` `#Cloud` `#Local` `#WokwiGateway`

## 1. Visão Geral (O Básico)
**Para que serve:** O Broker é o "servidor central" ou "correio" do ecossistema IoT. Ele recebe mensagens de publicadores (sensores) e as entrega para assinantes (dashboards/atuadores).
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Opções de Broker (Nuvem vs Local)

Para a UC S122, trabalhamos com três níveis de maturidade de infraestrutura:

| Tipo | Serviço/Software | Endereço (Host) | Porta | Uso Recomendado |
| :--- | :--- | :--- | :--- | :--- |
| **Cloud (Público)** | **HiveMQ** | `broker.hivemq.com` | 1883 | Testes rápidos, 100% grátis, sem instalação. |
| **Cloud (Alternativo)** | **EMQX** | `broker.emqx.io` | 1883 | Backup caso o HiveMQ esteja instável. |
| **Local (Fog)** | **Mosquitto** | `localhost` ou `IP_LAN` | 1883 | Uso profissional, exige Gateway ou VPN. |

---

## 3. Configuração de Conectividade

### ☁️ Opção A: Cloud (HiveMQ / EMQX)
Esta é a opção padrão para o Wokwi.
1.  **Vantagem:** O simulador faz a ponte automática via internet.
2.  **Web Client:** Utilize o [HiveMQ Web Client](http://www.hivemq.com/demos/websocket-client/) para testar sem instalar nada.

### 🏠 Opção B: Local (Wokwi IoT Gateway)
Se você precisar conectar o Wokwi a um broker rodando na sua própria máquina (`localhost`), você **precisa** do Gateway oficial.
1.  **Download:** [github.com/wokwi/wokwigw](https://github.com/wokwi/wokwigw)
2.  **Uso:** Execute o arquivo `wokwigw.exe` (ou binário Linux) no seu PC.
3.  **No Wokwi:** No arquivo `wokwi.toml`, adicione:
    ```toml
    [wokwi]
    version = 1
    # Habilita o uso do gateway local
    gateway = "local"
    ```

---

## 4. Integração (Ecossistema S122)
- **ESP32:** Usa a biblioteca `PubSubClient` (C++) ou `umqtt.simple` (Python).
- **Node-RED:** Usa o nó nativo `mqtt in` e `mqtt out`.
- **Mosquitto:** Pode ser instalado via Docker (ver [Guia Docker](./Guia_Docker_e_Containers.md)).

## 5. Solução de Problemas (Troubleshooting)
- **Firewall:** Se a porta 1883 estiver bloqueada na faculdade, tente a porta **8883** (SSL) ou mude o Broker para usar **WebSockets** (geralmente porta 8000).
- **Conexão Intermitente:** Brokers públicos podem desconectar clientes com o mesmo `ClientID`. Sempre use um ID único no código (ex: `ESP32_NOME_ALUNO`).

---
**⬅️ [Voltar ao Índice](./WIKI_INDEX.md) | ➡️ Próximo: [Docker e Containers](./Guia_Docker_e_Containers.md)**

*Documento em constante atualização. Versão: 2026/1*
