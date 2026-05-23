# Aedes (Local MQTT) - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Um broker MQTT "barebone" escrito em Node.js, ideal para ser embutido diretamente em aplicações JavaScript ou rodar de forma ultraleve em ambientes locais.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
Para entender como esta ferramenta se comunica no ecossistema:
- **Entrada (Input):** Conexões de rede via TCP/IP na porta configurada (Padrão 1883).
- **Saída (Output):** Encaminhamento de pacotes MQTT para dispositivos locais.

## 3. Instalação e Configuração

### 🪟 Windows / 🐧 Linux
1.  **Pré-requisito:** Ter o [Node.js](https://nodejs.org/) instalado.
2.  **Instalação via NPM:**
    ```bash
    npm install aedes net
    ```
3.  **Código de Inicialização Rápida (broker.js):**
    ```javascript
    const aedes = require('aedes')()
    const server = require('net').createServer(aedes.handle)
    const port = 1883

    server.listen(port, function () {
      console.log('Broker Aedes rodando na porta:', port)
    })
    ```
4.  **Verificação:** `node broker.js`

## 4. Integração (Ecossistema S122)
Esta ferramenta se relaciona com outros guias da seguinte forma:
- **Conecta com:** [Node-RED] para criar um servidor de mensagens local dentro do Fog Computing.
- **Depende de:** [Node.js] para execução.

**Links Relacionados (CORE):**
- Guia de Ferramentas: Guia_Ferramentas_e_Software.md
- Guia Node.js: Guia_Nodejs_Basico.md

## 5. Referências e Repositórios
- **Documentação Oficial:** [https://github.com/moscajs/aedes](https://github.com/moscajs/aedes)
- **Wiki de Exemplos:** [https://github.com/moscajs/aedes/tree/master/examples](https://github.com/moscajs/aedes/tree/master/examples)

## 6. Solução de Problemas (Troubleshooting)
- **Erro Comum:** `EADDRINUSE` (Porta 1883 já está sendo usada por outro broker como Mosquitto).
- **Solução:** Encerre o processo conflitante ou mude a variável `port` no script.

## 7. Fontes de Consulta (AI & Web)
- MoscaJS Community Documentation.
- NPMJS Package Repository.

---
*Documento em constante atualização. Versão: 2026/1*
