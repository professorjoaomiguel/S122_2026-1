# 🎨 Canvas M3F: Modelagem de Solução IoT baseada em Problemas (PBL)
**Unidade Curricular:** S122 - Internet das Coisas  
**Faculdade de Tecnologia SENAI Porto Alegre**  

---

> [!IMPORTANT]
> **Instruções para o Estudante:**
> Este Canvas é a sua bússola de projeto. Ele deve ser preenchido por completo pelo grupo **antes** de iniciarem a programação no Wokwi ou a compra de componentes físicos. Ele segue a **Metodologia das Três Fases (M3F)** publicada no IEEE.

---

## 👥 Identificação do Grupo e Cenário
*   **Grupo (G1-G4):** [Preencha aqui]
*   **Integrantes:** [Nome 1, Nome 2, Nome 3...]
*   **Cenário Real / APL Escolhido:** [Ex: Vitivinicultura (Serra Gaúcha), Metal-Mecânico (Canoas), etc.]
*   **ODS da ONU Focado:** [Ex: ODS 9 - Indústria, Inovação e Infraestrutura, ODS 12 - Consumo e Produção Responsáveis]

---

## 1️⃣ FASE 1: O Negócio e o Cenário (*Understanding the Business*)
*Esta fase define o PORQUÊ do projeto. Nenhuma escolha tecnológica deve ser feita aqui.*

### A. A Dor / O Problema Real
*Descreva qual é a necessidade real da empresa, fábrica ou produtor rural que a sua solução de IoT vai resolver.*
> **Resposta do Grupo:**
> [Digite o texto aqui]

### B. O Especialista
*Quem é a pessoa especialista no negócio? Quais parâmetros técnicos essa pessoa diz que são críticos? (Ex: O agrônomo diz que o solo não pode ficar com umidade abaixo de 30%).*
> **Resposta do Grupo:**
> [Digite o parâmetro técnico crítico aqui]

### C. As Coisas (*Things*)
*Quais variáveis físicas reais precisam ser medidas ou controladas no ambiente?*
> **Resposta do Grupo:**
> *   **Variável a Medir:** [Ex: Temperatura da Adega]
> *   **Ação a Executar:** [Ex: Ligar exaustor/ventoinha]

### D. As Regras de Negócio
*Quais perguntas o negócio faz para tomar decisões? E qual a lógica básica a seguir?*
*   **Pergunta do Negócio:** [Ex: Está ocorrendo perda de grãos por umidade?]
*   **Regra Lógica:** [Ex: SE a umidade > 65% por mais de 10 minutos, ENVIAR alerta e LIGAR o aquecedor.]

---

## 2️⃣ FASE 2: Especificação de Requisitos (*Top-Down*)
*Agora mapeamos a arquitetura de dados e comunicação, de cima para baixo (do painel visual ao sensor físico).*

| Nível de Referência | Função no Projeto | Tecnologia Conceitual | Temporização / Amostragem |
| :--- | :--- | :--- | :--- |
| **Nível 6 - Exibição** | Exibição final para tomada de decisão. | [Ex: Dashboard Web com gráficos históricos] | [Ex: Atualização a cada 10s / Alertas imediatos] |
| **Nível 5 - Abstração** | Conversão de dados brutos em alertas e inteligência. | [Ex: Algoritmo de Histerese / Alerta de temperatura alta] | [Ex: Executado na nuvem ou no gateway a cada 5s] |
| **Nível 4 - Armazenamento** | Onde os dados serão salvos historicamente. | [Ex: InfluxDB / PostgreSQL] | [Ex: Gravação histórica a cada 1 minuto] |
| **Nível 3 - Borda (Gateway)** | Gateway que filtra dados locais e gerencia a internet. | [Ex: Raspberry Pi rodando Docker com Mosquitto] | [Ex: Buffer local de 24h caso a internet caia] |
| **Nível 2 - Conectividade** | Transporte físico do dado entre o sensor e a borda. | [Ex: Rede WiFi local / Protocolo MQTT] | [Ex: Envio a cada 5 segundos] |
| **Nível 1 - Sensor/Atuador** | Dispositivo que faz a leitura física e a atuação local. | [Ex: ESP32 + DHT22 + Relé de controle da válvula] | [Ex: Leitura física a cada 2 segundos] |

---

## 3️⃣ FASE 3: Implementação e Testes (*Bottom-Up*)
*Esta fase descreve a ordem em que o grupo vai testar e construir a solução, de baixo para cima.*

### 🛠️ Cronograma E2E (Sensor à Nuvem)
1.  **Validação do Nível 1:** *Como testaremos as leituras locais e a atuação autônoma no ESP32 antes de ligar a rede?*
    > [Descreva o teste local, ex: Exibir dados de temperatura no LCD e acionar o Relé via Serial]
2.  **Validação do Nível 2:** *Como validaremos a transmissão sem fio dos dados?*
    > [Descreva o teste, ex: Verificar IP obtido via WiFi.begin e mensagens publicadas no HiveMQ Web Client]
3.  **Validação do Nível 3 & 4:** *Como testaremos o processamento local no gateway e a gravação de banco?*
    > [Descreva o teste, ex: Verificar se o Node-RED captura o MQTT e grava com sucesso no InfluxDB local]
4.  **Validação do Nível 5 & 6:** *Como validaremos o dashboard e os alertas do produtor?*
    > [Descreva o teste, ex: Testar a exibição dos gráficos históricos no Grafana/TagoIO e o envio de notificação por e-mail]

---
*Versão de Conformidade Metodológica S122 - Prof. João Miguel*
