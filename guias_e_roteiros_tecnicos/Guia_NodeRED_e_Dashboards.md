# Node-RED - Guia Técnico S122
`#Fluxos` `#Interface` `#Integração` `#LowCode` `#Docker` `#Windows`

## 1. Visão Geral (O Básico)
**Para que serve:** Ferramenta de programação baseada em fluxo para conectar dispositivos de hardware, APIs e serviços online de forma visual.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Mensagens MQTT, requisições HTTP, dados JSON de sensores, entrada via Dashboard.
- **Saída (Output):** Escrita no InfluxDB, comandos MQTT para atuadores, visualização em tempo real, disparos de e-mail/IA.

## 3. Instalação e Configuração

### 🪟 Windows (Via npx - Recomendado para Laboratório)
Este método não requer instalação global e é ideal para computadores compartilhados ou uso via Pendrive.
1.  **Pré-requisito:** Ter o [Node.js](https://nodejs.org/) instalado.
2.  **Comando de Execução:**
    ```powershell
    # Execute apontando para sua pasta de trabalho (ex: Pendrive ou Desktop)
    npx node-red --userDir "C:\Caminho\Para\Sua\Pasta"
    ```
3.  **Configuração:** Acesse pelo navegador em [http://127.0.0.1:1880](http://127.0.0.1:1880).
4.  **Dica de Portabilidade:** No arquivo `settings.js` criado na sua pasta, defina `credentialSecret: "senai"` para poder levar seu projeto para outros PCs.

### 🐧 Linux (Via Docker - Recomendado para Servidores/Fog)
1.  **Comando de Execução:**
    ```bash
    docker run -it -p 1880:1880 --name mynodered nodered/node-red
    ```
2.  **Configuração:** Acesse pelo navegador em http://localhost:1880.
3.  **Verificação:** Verifique se o editor visual carrega no browser.

## 4. Integração (Ecossistema S122)
- **Conecta com:** Mosquitto (MQTT) para receber dados da borda e InfluxDB para armazenamento.
- **Depende de:** [./Guia_Docker_e_Containers.md](./Guia_Docker_e_Containers.md) (se usar Docker) ou Node.js (se usar npx).

**Links Relacionados (CORE):**
- Guia Docker: [./Guia_Docker_e_Containers.md](./Guia_Docker_e_Containers.md)
- Guia InfluxDB: [./Guia_InfluxDB.md](./Guia_InfluxDB.md)

## 5. Referências e Repositórios
- **Documentação Oficial:** https://nodered.org/docs/
- **Biblioteca de Flows:** https://flows.nodered.org/
- **GitHub Node-RED:** https://github.com/node-red/node-red

## 6. Solução de Problemas (Troubleshooting)
- **Erro: Porta 1880 ocupada:** Use o parâmetro `--port 1881` para mudar a porta de execução.
- **Erro de Credenciais:** Se mudar de PC e as senhas sumirem, verifique se o `credentialSecret` no `settings.js` é o mesmo.

## 7. Fontes de Consulta (AI & Web)
- Node-RED Getting Started: https://nodered.org/docs/getting-started/
- Opto22 Developer (Tutoriais IoT): https://developer.opto22.com/nodered/

---
**⬅️ [Voltar ao Índice](./WIKI_INDEX.md) | ➡️ Próximo: [InfluxDB](./Guia_InfluxDB.md) | 📤 [Padrão de Entrega](./PADRAO_DE_ENTREGA_CLASSROOM.md)**

*Documento em constante atualização. Versão: 2026/1*
