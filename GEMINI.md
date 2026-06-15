# Projeto S122 - Internet das Coisas (2026/1)

## Fonte Unica para Agentes

Este arquivo e auxiliar. A fonte unica de instrucoes para agentes de IA neste repositorio e:

- `AGENTS.md`

Em caso de conflito de orientacoes, `AGENTS.md` prevalece.

Este repositório contém o material de apoio, guias técnicos e roteiros da Unidade Curricular **S122 - Internet das Coisas** do SENAI Porto Alegre, sob coordenação do Prof. João Miguel Lac Roehe.

## 📂 Visão Geral do Diretório

Este é um **projeto de documentação e educação** (Non-Code Project). Não contém o código principal da aplicação em si, mas sim a base de conhecimento necessária para configurar o ecossistema de IoT planejado para a disciplina.

O projeto segue o modelo **M3F** de arquitetura IoT, organizado em duas trilhas didáticas:
- **Trilha Principal (Arduino/ESP32):** Foco em C++ (.ino), cobrindo desde fundamentos até integração Cloud.
- **Trilha Paralela (Raspberry Pi Pico):** Alternativa self-paced focada em MicroPython (.py) para quem deseja explorar uma pilha tecnológica diferente.

## 🎓 Filosofia de Ensino e Papel da IA

Este repositório adota a **Filosofia de Aprendizado Ativo**, inspirada no modelo `lab_se`. O objetivo é que o aluno seja o protagonista da construção do conhecimento, utilizando a IA como um **Tutor** e não como um substituto para o raciocínio.

### 🤖 O Papel do Gemini CLI (Tutor)
Ao interagir com este repositório, o Gemini CLI deve:
1.  **Não dar respostas prontas:** Se um aluno pedir a solução de um laboratório, a IA deve fornecer pistas, explicar conceitos e apontar para a documentação, mas nunca entregar o código completo de imediato.
2.  **Estimular a Reflexão:** Sempre que ajudar em um trecho de código, a IA deve perguntar "Por que você acha que isso funciona desta forma?" ou "O que aconteceria se mudássemos o parâmetro X?".
3.  **Validar o Raciocínio:** Verificar se o aluno entendeu os conceitos de I/O, protocolos (MQTT, HTTP) e a arquitetura M3F antes de avançar.

### 🧪 Estrutura de Laboratórios e Desafios
Como este repositório foca em **ecossistemas de IoT e integração de ferramentas**, os laboratórios serão estruturados por tecnologia (ex: Wokwi, Node-RED, Docker).
O padrão em `labs/` será:
-   **`README.md`**: Contexto, cenário do desafio, requisitos e **Reflexão Técnica**.
-   **`arquivos de suporte`**: Ao invés de código Python, os laboratórios podem fornecer arquivos de configuração incompletos (ex: um `fluxo_base.json` para Node-RED, um `diagram.json` para Wokwi, ou um `docker-compose.yml` base).
-   **`solucao_referencia/`**: Pasta contendo os arquivos completos ou capturas de tela mostrando como a ferramenta deve ficar configurada (para o professor ou para conferência posterior).

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
- **Ambiente de Simulação**: Wokwi integrado ao VSCode e validação de esquemas via **Wokwi CLI (`lint`)**.
- **Referências MicroPython**: 
  - Início rápido: [wokwi.com/micropython](https://wokwi.com/micropython)
  - Documentação oficial (Pi Pico): [docs.wokwi.com/guides/micropython](https://docs.wokwi.com/guides/micropython).
  - Exemplo Blink (Pi Pico): [wokwi.com/projects/300504213470839309](https://wokwi.com/projects/300504213470839309)
  - Exemplo Blink (ESP32): [wokwi.com/projects/359801682833812481](https://wokwi.com/projects/359801682833812481)
- **Links para Novos Projetos (Wokwi)**:
  - Raiz de novos projetos: [wokwi.com/projects/new](https://wokwi.com/projects/new)
  - **ESP32 Family**: [ESP32](https://wokwi.com/projects/new/esp32), [S2](https://wokwi.com/projects/new/esp32-s2), [S3](https://wokwi.com/projects/new/esp32-s3), [C3](https://wokwi.com/projects/new/esp32-c3), [C6](https://wokwi.com/projects/new/esp32-c6), [H2](https://wokwi.com/projects/new/esp32-h2), [P4](https://wokwi.com/projects/new/esp32-p4)
  - **Arduino**: [Uno Rev3](https://wokwi.com/projects/new/arduino-uno), [Mega](https://wokwi.com/projects/new/arduino-mega), [Nano](https://wokwi.com/projects/new/arduino-nano), [ATtiny85](https://wokwi.com/projects/new/attiny85)
  - **Raspberry Pi**: [Pi Pico](https://wokwi.com/projects/new/pi-pico), [Pi Pico W](https://wokwi.com/projects/new/pi-pico-w)
  - **Outros**: [STM32 Nucleo](https://wokwi.com/projects/new/st-nucleo-c031c6), [Franzininho WiFi](https://wokwi.com/projects/new/franzininho-wifi), [M5Stack Core S3](https://wokwi.com/projects/402847860051798017)
  - Templates ESP32: [wokwi.com/esp32](https://wokwi.com/esp32)
- **Padrões de Projeto (Wokwi)**: Todos os esquemas de circuitos no Wokwi (`diagram.json`) devem utilizar nomes de componentes existentes na biblioteca oficial do Wokwi.
 Deve-se priorizar o uso de componentes "documentados" para evitar avisos de "undocumented type" no `wokwi-cli lint`.
- **Perfil**: Ambiente educacional técnico voltado para automação e IoT.
