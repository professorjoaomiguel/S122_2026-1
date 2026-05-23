# **Roteiro de Atividades IoT: Do Blink ao Monitoramento Inteligente**

## **Introdução**

Este guia define os requisitos técnicos e as tarefas de evolução para cada nível de complexidade no simulador **Wokwi**.

## **Nível 0: Hello World (Blink)**

**Objetivo:** Validar o ambiente e o fluxo de upload de firmware.

* **Código Base:** Piscar o **LED\_BUILTIN**.  
* **Entregável:** Link do projeto salvo no Wokwi.  
* **Registro Visual:** Printscreen da tela inteira do simulador com o LED aceso.  
* **Desafio de Modificação:** Altere o código para que o LED pisque de forma assimétrica: **500ms ligado** e **2000ms desligado**.

## **Nível 1: Sinalização Semafórica (Digital Out)**

**Objetivo:** Controle sequencial de saídas digitais múltiplas.

* **Hardware:** LEDs nos pinos **10 (Verde)**, **11 (Amarelo)** e **12 (Vermelho)**.  
* **Entregável:** Código-fonte e link do projeto.  
* **Registro Visual:** Printscreen do diagrama de conexões (Wires).  
* **Desafio de Modificação:** Crie um "Modo de Atenção". Se uma variável bool modoAlerta for verdadeira, apenas o **LED Amarelo** deve piscar a cada 500ms, ignorando a sequência normal.

## **Nível 2: O Gatilho (Digital In)**

**Objetivo:** Interrupção de fluxo por entrada digital.

* **Hardware:** Adição de **Pushbutton** no pino **2**.  
* **Entregável:** Relatório curto descrevendo o comportamento do pino ao usar INPUT\_PULLUP.  
* **Registro Visual:** Printscreen do console serial exibindo "Botao Pressionado" quando o evento ocorrer.  
* **Desafio de Modificação:** Implemente um contador. O semáforo deve completar **3 ciclos** completos e então parar, aguardando um novo clique no botão para reiniciar.

## **Nível 3: Variabilidade Analógica (ADC)**

**Objetivo:** Leitura de sensores analógicos e mapeamento de dados.

* **Hardware:** Adição de **Potenciômetro** no pino **A0**.  
* **Entregável:** Tabela comparativa entre o valor bruto (0-1023) e o valor convertido (0-5V).  
* **Registro Visual:** Gráfico do **Serial Plotter** do Wokwi mostrando a variação da leitura.  
* **Desafio de Modificação:** Inverta a lógica de controle. Quando o potenciômetro estiver no **valor máximo**, o tempo de espera entre os LEDs do semáforo deve ser o **mínimo (100ms)**.

## **Nível 4: Interface Homem-Máquina (I2C)**

**Objetivo:** Comunicação por barramento e bibliotecas de terceiros.

* **Hardware:** **LCD 16x2 I2C** nos pinos **A4 (SDA)** e **A5 (SCL)**.  
* **Entregável:** Foto da tela do LCD exibindo o seu Nome e Sobrenome.  
* **Registro Visual:** Printscreen do arquivo diagram.json evidenciando as conexões I2C.  
* **Desafio de Modificação:** Crie uma barra de progresso simples no LCD (usando caracteres como \>) que aumente ou diminua conforme a posição do potenciômetro.

## **Nível 5: Sensoriamento IoT (DHT22)**

**Objetivo:** Protocolos de comunicação de via única e precisão digital.

* **Hardware:** **Sensor DHT22** no pino **4**.  
* **Entregável:** Arquivo de log (texto) com 10 leituras de temperatura e umidade.  
* **Registro Visual:** Printscreen do LCD mostrando os dados do DHT22 e do Potenciômetro simultaneamente.  
* **Desafio de Modificação:** Adicione uma função que converta a temperatura de **Celsius para Fahrenheit** e alterne a exibição no LCD a cada 5 segundos.

## **Nível 6: Monitoramento com Alerta (Lógica Final)**

**Objetivo:** Integração total e automação baseada em condições.

* **Hardware:** Circuito Completo (LEDs, Botão, Potenciômetro, LCD, DHT22).  
* **Entregável:** Vídeo curto (captura de tela) demonstrando a mudança de cor dos LEDs ao alterar manualmente a temperatura no sensor DHT22.  
* **Registro Visual:** Diagrama final completo e organizado.  
* **Desafio de Modificação:** Implemente uma "Trava de Segurança". Se a temperatura ultrapassar **40°C**, o **LED Vermelho** deve piscar rapidamente e o sistema deve ignorar o **Pushbutton** até que a temperatura caia para menos de **35°C**.

### **Diagrama Final de Conexões (diagram.json)**

Utilize este JSON para montar o circuito completo de uma só vez ou validar suas conexões.