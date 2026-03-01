# Grafana - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Plataforma líder para monitoramento e visualização de dados métricos através de Dashboards dinâmicos.
**Contexto M3F:** [ ] Percepção (Edge) | [ ] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Queries Flux/SQL de bancos de dados (InfluxDB), parâmetros de variáveis de dashboard.
- **Saída (Output):** Painéis visuais (gráficos, tabelas, alertas), relatórios em PDF (quando configurado).

## 3. Instalação e Configuração

### 🐧 Linux (Via Docker - Recomendado)
1.  **Comando de Execução:**
    ```bash
    docker run -d -p 3000:3000 --name grafana grafana/grafana
    ```
2.  **Configuração:** Acesse http://localhost:3000 (User: admin / Pass: admin).
3.  **Verificação:** Verifique se a tela de login aparece no navegador.

## 4. Integração (Ecossistema S122)
- **Conecta com:** InfluxDB como Data Source principal para a disciplina.
- **Utiliza:** [./Guia_InfluxDB.md](./Guia_InfluxDB.md) para buscar as métricas geradas pelos ESP32.

**Links Relacionados (CORE):**
- Guia InfluxDB: [./Guia_InfluxDB.md](./Guia_InfluxDB.md)
- Guia de Docker: [./Guia_Docker_e_Containers.md](./Guia_Docker_e_Containers.md)

## 5. Referências e Repositórios
- **Documentação Oficial:** https://grafana.com/docs/
- **Playground (Exemplos):** https://play.grafana.org/
- **GitHub Grafana:** https://github.com/grafana/grafana

## 6. Solução de Problemas (Troubleshooting)
- **Erro: "Data Source not found":** Verifique a URL do InfluxDB dentro do Grafana (geralmente `http://influxdb:8086`).
- **Erro de Login:** Se esqueceu a senha, reinicie o container ou use comandos de reset via `grafana-cli`.

## 7. Fontes de Consulta (AI & Web)
- Grafana Tutorials: https://grafana.com/tutorials/
- Dashboards Públicos: https://grafana.com/grafana/dashboards/

---
*Documento em constante atualização. Versão: 2026/1*
