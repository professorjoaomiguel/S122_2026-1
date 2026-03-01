# Docker e Orquestração - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Empacotar e rodar serviços (MQTT, Bancos, Dashboards) de forma isolada e portável dentro do Gateway IoT.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Arquivos de configuração (`docker-compose.yml`), imagens do Docker Hub, conexões de rede (portas).
- **Saída (Output):** Serviços em execução (Containers), persistência de dados em volumes, logs de sistema.

## 3. Instalação e Configuração

### 🪟 Windows (Docker Desktop)
1.  **Download:** https://www.docker.com/products/docker-desktop/
2.  **Procedimento:** Instale e habilite o WSL2 (Windows Subsystem for Linux).
3.  **Verificação:** `docker --version` e `docker-compose --version`

### 🐧 Linux (Raspbian/Ubuntu)
1.  **Comando de Instalação:**
    ```bash
    curl -sSL https://get.docker.com | sh
    sudo usermod -aG docker $USER
    ```
2.  **Configuração:** Reinicie a sessão para as permissões de grupo surtirem efeito.
3.  **Verificação:** `docker ps`

## 4. Integração (Ecossistema S122)
- **Conecta com:** [./Guia_InfluxDB.md](./Guia_InfluxDB.md) e [./Guia_Grafana.md](./Guia_Grafana.md) para subir os serviços de dados.
- **Depende de:** [./Guia_Virtualizacao_Raspbian.md](./Guia_Virtualizacao_Raspbian.md) (pois o Docker roda dentro da VM).

**Links Relacionados (CORE):**
- Guia InfluxDB: [./Guia_InfluxDB.md](./Guia_InfluxDB.md)
- Guia Grafana: [./Guia_Grafana.md](./Guia_Grafana.md)

## 5. Referências e Repositórios
- **Documentação Oficial:** https://docs.docker.com
- **Docker Hub (Imagens):** https://hub.docker.com

## 6. Solução de Problemas (Troubleshooting)
- **Erro: Permission Denied:** Certifique-se de que adicionou o usuário ao grupo `docker` ou use `sudo`.
- **Erro: Porta já em uso:** Verifique se outro serviço está ocupando a porta (ex: 1883 para MQTT) com `sudo lsof -i :1883`.

## 7. Fontes de Consulta (AI & Web)
- Docker Get Started: https://docs.docker.com/get-started/
- Docker Compose Specification: https://docs.docker.com/compose/compose-file/
- Eclipse Mosquitto Docker Hub: https://hub.docker.com/_/eclipse-mosquitto

---
*Documento em constante atualização. Versão: 2026/1*
