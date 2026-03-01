# Node-RED - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Ferramenta de programação baseada em fluxo para conectar dispositivos de hardware, APIs e serviços online de forma visual.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Mensagens MQTT, requisições HTTP, dados JSON de sensores, entrada via Dashboard.
- **Saída (Output):** Escrita no InfluxDB, comandos MQTT para atuadores, visualização em tempo real, disparos de e-mail/IA.

## 3. Instalação e Configuração

### 🐧 Linux (Via Docker - Recomendado)
1.  **Comando de Execução:**
    ```bash
    docker run -it -p 1880:1880 --name mynodered nodered/node-red
    ```
2.  **Configuração:** Acesse pelo navegador em http://localhost:1880.
3.  **Verificação:** Verifique se o editor visual carrega no browser.

## 4. Integração (Ecossistema S122)
- **Conecta com:** Mosquitto (MQTT) para receber dados da borda e InfluxDB para armazenamento.
- **Depende de:** [./Guia_Docker_e_Containers.md](./Guia_Docker_e_Containers.md) para execução do container.

**Links Relacionados (CORE):**
- Guia Docker: [./Guia_Docker_e_Containers.md](./Guia_Docker_e_Containers.md)
- Guia InfluxDB: [./Guia_InfluxDB.md](./Guia_InfluxDB.md)

## 5. Referências e Repositórios
- **Documentação Oficial:** https://nodered.org/docs/
- **Biblioteca de Flows:** https://flows.nodered.org/
- **GitHub Node-RED:** https://github.com/node-red/node-red

## 6. Solução de Problemas (Troubleshooting)
- **Erro: Porta 1880 ocupada:** Pare outros containers ou instâncias do Node-RED rodando.
- **Erro de Memória:** Aumente o limite de RAM do container Docker se usar muitos fluxos.

## 7. Fontes de Consulta (AI & Web)
- Node-RED Getting Started: https://nodered.org/docs/getting-started/
- Opto22 Developer (Tutoriais IoT): https://developer.opto22.com/nodered/

---
*Documento em constante atualização. Versão: 2026/1*
