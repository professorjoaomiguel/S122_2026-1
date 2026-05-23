# 🎬 Storyboard Mestre de Laboratórios Wokwi - UC S122 (IoT)

Este documento define a estratégia pedagógica de alto nível. Cada módulo agora possui uma trilha de **3 atividades incrementais**.

---

## 🧭 Visão Geral da Jornada PBL

| ID | Título da Atividade | 🎯 Objetivo Central | 📦 Entregáveis (AVA/Classroom) |
| :--- | :--- | :--- | :--- |
| **LAB 1.1** | Eletrônica de Borda | Validar montagem física e interatividade. | Link + Print do LED. |
| **LAB 1.2** | Hello World & Serial | Dominar fluxo de compilação e depuração. | Link + Print Serial Monitor. |
| **LAB 1.3** | Sensores & I2C | Integrar protocolos I2C e leitura de sensores. | Link + Print LCD com dados. |
| **---** | **---** | **---** | **---** |
| **LAB 2.1** | Conectividade WiFi | Validar conexão e obtenção de IP/NTP. | Link + Print do IP no Serial. |
| **LAB 2.2** | Controle Web (Relé) | Criar Web Server para atuação remota. | Link + Print do Browser controlando Relé. |
| **LAB 2.3** | Dashboard de Borda | Telemetria + Controle em página única. | Link + Print Dashboard completo. |
| **---** | **---** | **---** | **---** |
| **LAB 3.1** | VS Code Setup | Configurar extensão e infra de arquivos. | .zip (TOML/JSON) + Print VS Code. |
| **LAB 3.2** | Bibliotecas & Periféricos | Gestão de bibliotecas externas localmente. | .zip + Print LCD rodando via VS Code. |
| **LAB 3.3** | Projeto & Git | Estruturação de código e versionamento. | Link do Repositório GitHub + .gitignore. |

---

## 🧩 Detalhamento dos Módulos Expandidos

### Módulo 2: O Salto para a Rede (Fog Bridge)
1.  **LAB 2.1 - Conexão:** Foco em `WiFi.begin()` e sincronização de tempo via NTP.
2.  **LAB 2.2 - Atuação (Expande 2.1):** Adiciona o `WiFiServer` e controle de carga (Relé).
3.  **LAB 2.3 - Telemetria (Expande 2.2):** Adiciona leitura de sensores (DHT22) enviando dados para a página Web.

### Módulo 3: Workflow Industrial
1.  **LAB 3.1 - Infra:** Criação dos arquivos `diagram.json` e `wokwi.toml`.
2.  **LAB 3.2 - Dependências (Expande 3.1):** Uso de `libraries.txt` e integração de hardware complexo.
3.  **LAB 3.3 - Engenharia (Expande 3.2):** Modularização de código (Header files) e preparação para o GitHub.

---
*Versão 2026/1 - Metodologia Incremental*
