# LAB 03: O Primeiro Sinal (Blink Base)

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🌿 Camada 1: Edge (Percepção Local)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (LED Embutido / Sinal Vital)

---

### 🔌 Hardware Requerido
*   **Placa:** **Arduino Uno Rev3**
*   **Finalidade:** Fundamentos de microcontroladores e programação em C++

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/arduino-uno.svg" alt="Arduino Uno Rev3" width="180">
</p>

---

## 🚀 Como Iniciar?
1. Abra um projeto vazio para Arduino Uno no simulador: 🚀 [**Projeto Vazio: Arduino Uno**](https://wokwi.com/projects/new/arduino-uno).
2. Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Todo projeto de hardware começa com um sinal de vida. O "Blink" é o teste universal para garantir que o processador está alimentado, o código foi gravado e o clock está funcionando.

---

## 🎯 Objetivos Técnicos
*   Validar o ambiente de desenvolvimento e simulação.
*   Compreender a estrutura mínima de um programa Arduino (`setup` e `loop`).
*   Controlar o LED interno da placa (Built-in LED).

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: Estrutura Base
1.  Abra um 🚀 [**Projeto Vazio: Arduino Uno**](https://wokwi.com/projects/new/arduino-uno).
2.  Identifique as funções `void setup()` e `void loop()`.

### 🚀 Passo 2: Saída Digital
1.  Utilize o pino **13** (ligado ao LED "L" da placa).
2.  Configure o pino como `OUTPUT`.

### 🚀 Passo 3: O Ciclo de Blink
1.  Escreva o código para ligar o LED, esperar 1 segundo, desligar e esperar mais 1 segundo.

```cpp
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este LED representa o **Sinal Vital** (Heartbeat) do sistema, indicando para o operador que o monitoramento está ativo e o processador não travou.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- No **APL Calçadista do Vale do Sinos**, por que é crítico saber se o sensor de uma máquina está "vivo" e enviando pulsos antes de iniciar a operação?

---

## 🧠 Atividade de Desafio Prático e Reflexão
Agora que seu LED já está piscando, vamos elevar o nível técnico e aplicar uma lógica com finalidade real!

### 🚨 O Desafio: Sinalizador de Emergência SOS (Código Morse)
*   **Contexto:** Em sistemas de sinalização marítima ou de resgate em montanhas, o sinal luminoso universal de socorro é o **SOS** em Código Morse.
*   **A Estrutura do SOS:**
    *   Letra **S**: Três sinais curtos (pontos: `· · ·`)
    *   Letra **O**: Três sinais longos (traços: `- - -`)
    *   Letra **S**: Três sinais curtos (pontos: `· · ·`)

*   **Padrão de Temporização Oficial do Morse:**
    *   **Ponto (·):** Tem a duração básica de $1$ unidade de tempo (vamos definir $T = 200\text{ ms}$).
    *   **Traço (-):** Tem a duração de $3$ unidades de tempo ($3T = 600\text{ ms}$).
    *   **Espaço interno (entre pontos e traços de uma mesma letra):** $1$ unidade de tempo ($T = 200\text{ ms}$) com LED apagado.
    *   **Espaço entre letras (entre o S e o O):** $3$ unidades de tempo ($3T = 600\text{ ms}$) com LED apagado.
    *   **Espaço entre palavras (entre repetições do SOS completo):** $7$ unidades de tempo ($7T = 1400\text{ ms}$) com LED apagado.

---

### 📈 Desenvolvimento Incremental

#### 🚀 Etapa 1: A Abordagem Rígida (Hardcoded)
Desenvolva a sequência completa do SOS acionando o pino 13 com valores de tempo fixos diretamente nos comandos de delay.
*   **Exemplo:** `digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW); delay(200);` para os pontos, `delay(600)` para os traços, etc.
*   **O Problema:** Após rodar seu código, observe como ele fica longo, repetitivo e difícil de ler. 
*   **Provocação:** *E se o resgate estiver muito longe e você precisar acelerar a transmissão do SOS para economizar bateria da placa, mudando $T$ para $100\text{ ms}$? Quantas linhas de código você teria que alterar manualmente?*

#### 🚀 Etapa 2: A Abordagem Inteligente (Parametrizada)
Refatore o seu código para utilizar **constantes ou variáveis** no topo do programa para definir os tempos!
1.  Declare a unidade básica de tempo no topo: `const int tempoPonto = 200;`
2.  Declare as outras constantes calculadas com base na primeira (ex: `const int tempoTraco = tempoPonto * 3;`).
3.  Utilize estas variáveis nos seus blocos de controle e delays.
4.  *(Dica de Ouro)*: Se quiser deixar seu código ainda mais limpo e elegante, crie funções auxiliares como `void emitirPonto()` e `void emitirTraco()` para eliminar a repetição das estruturas de escrita digital!
5.  **Validação:** Mude o valor de `tempoPonto` para `100` e veja todo o sinal de SOS acelerar de forma automática, com uma única mudança!

---

### ❓ Reflexão Técnica (Obrigatória para Entrega)
1.  **O que acontece se colocarmos o comando `pinMode` dentro do `loop()` em vez do `setup()`?** O circuito continuará funcionando? Por que isso consome ciclos de processamento desnecessários da CPU?
2.  **Qual a grande vantagem pedagógica e de manutenção do princípio DRY (Don't Repeat Yourself)** que experimentamos ao migrar da Etapa 1 para a Etapa 2?

---

## 📂 Solução de Referência e Recursos
O professor disponibilizou uma pasta chamada [**`solucao_referencia/`**](./solucao_referencia/) neste laboratório. Ela contém o circuito e o código consolidados em pleno funcionamento, demonstrando didaticamente a diferença prática entre o código Hardcoded e o Parametrizado com funções auxiliares. Use-a para validar sua lógica depois de tentar resolver sozinho!

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja sair do navegador e começar a usar as ferramentas profissionais (VS Code + Git)? 
👉 [**Acesse o Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link do Simulador]
*   **Print:** Screenshot do simulador exibindo o LED "L" piscando ou logs de atividade.

---
*UC S122 - Internet das Coisas*
