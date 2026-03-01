# InfluxDB - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Banco de dados de alto desempenho otimizado para séries temporais (Time Series).
**Contexto M3F:** [ ] Percepção (Edge) | [ ] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Dados métricos via protocolo de linha (Line Protocol), Queries Flux via API ou interface web.
- **Saída (Output):** Dados estruturados para o Grafana, visualização em gráficos internos, alertas de sistema.

## 3. Instalação e Configuração

### 🐧 Linux (Via Docker - Recomendado)
1.  **Comando de Execução:**
    ```bash
    docker run -d -p 8086:8086 --name influxdb influxdb:latest
    ```
2.  **Configuração:** Acesse http://localhost:8086 para o setup inicial (Org, Bucket e Token).
3.  **Verificação:** `docker exec -it influxdb influx ping`

## 4. Integração (Ecossistema S122)
- **Conecta com:** Node-RED (para escrita de dados) e Grafana (para leitura e visualização).
- **Depende de:** [./Guia_Docker_e_Containers.md](./Guia_Docker_e_Containers.md).

**Links Relacionados (CORE):**
- Guia Node-RED: [./Guia_NodeRED_e_Dashboards.md](./Guia_NodeRED_e_Dashboards.md)
- Guia Grafana: [./Guia_Grafana.md](./Guia_Grafana.md)

## 5. Referências e Repositórios
- **Documentação Oficial:** https://docs.influxdata.com/influxdb/v2/
- **Linguagem Flux:** https://docs.influxdata.com/flux/v0.x/
- **GitHub InfluxDB:** https://github.com/influxdata/influxdb

## 6. Solução de Problemas (Troubleshooting)
- **Erro: Token Inválido:** Gere um novo Token em "Load Data > API Tokens" com permissões totais.
- **Erro: Bucket não encontrado:** Verifique se o nome digitado no Node-RED é idêntico ao criado na interface.

## 7. Fontes de Consulta (AI & Web)
- InfluxDB Documentation: https://docs.influxdata.com/influxdb/v2/
- Influx University (Treinamentos Free): https://university.influxdata.com/

---
*Documento em constante atualização. Versão: 2026/1*
