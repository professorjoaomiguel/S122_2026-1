# Projeto S122 - Internet das Coisas (2026/1)

Este repositório contém o material de apoio, guias técnicos e roteiros da Unidade Curricular **S122 - Internet das Coisas** do SENAI Porto Alegre, sob coordenação do Prof. João Miguel Lac Roehe.

## 📂 Visão Geral do Diretório

Este é um **projeto de documentação e educação** (Non-Code Project). Não contém o código principal da aplicação em si, mas sim a base de conhecimento necessária para configurar o ecossistema de IoT planejado para a disciplina.

O projeto segue o modelo **M3F** de arquitetura IoT:
- **Edge (Percepção):** ESP32, MicroPython, Sensores.
- **Fog (Transporte/Processamento Local):** Raspberry Pi, Gateway, Docker, InfluxDB.
- **Cloud (Aplicação/Dashboard):** Grafana, Node-RED, Dashboards.

## 📄 Arquivos e Pastas Principais

- **`README.md`**: Introdução básica à UC e identificação do professor.
- **`guias_e_roteiros_tecnicos/`**: Pasta central contendo guias passo a passo para ferramentas e tecnologias.
  - **`00_TEMPLATE_GUIA_TECNICO.md`**: Template padrão para novos guias, garantindo consistência técnica (Visão Geral, I/O, Instalação, Integração, Troubleshooting).
  - **`Guia_ESP32_MicroPython.md`**: Configuração do hardware na ponta (Edge).
  - **`Guia_Gemini_CLI.md`**: Instruções para uso da IA Gemini no terminal como suporte ao desenvolvimento.
  - **`Guia_NodeRED_e_Dashboards.md`**: Orquestração de dados e visualização.
- **`slides/`**: (Em construção) Reservado para apresentações de aula.

## 🛠️ Convenções e Uso

1.  **Padronização**: Todos os guias técnicos devem seguir o template `00_TEMPLATE_GUIA_TECNICO.md`.
2.  **Linguagem**: Documentação em Português (Brasil), exceto para termos técnicos e comandos universais.
3.  **Fluxo de Trabalho**:
    - Consultar guias específicos para configuração de ferramentas.
    - Utilizar o Gemini CLI para resolver problemas de configuração e scripts (conforme `Guia_Gemini_CLI.md`).
    - Seguir as orientações de infraestrutura em `Guia_Infraestrutura_Rede_Local.md`.

## 💡 Informações de Contexto para IA

- **Tecnologias Foco**: MicroPython, MQTT, Docker, InfluxDB v2, Grafana, Node-RED, Linux (Debian/Raspbian).
- **Ambiente de Simulação**: Wokwi integrado ao VSCode.
- **Perfil**: Ambiente educacional técnico voltado para automação e IoT.
