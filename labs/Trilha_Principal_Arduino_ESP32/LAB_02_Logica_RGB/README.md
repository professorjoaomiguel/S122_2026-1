# LAB 02: Desafio Cromático (Lógica com LED RGB)

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🎛️ Camada 0: Fundamentos (Sem Código)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Conceitual / Lógica Digital)

---

### 🔌 Hardware Requerido
*   **Placa:** **Wokwi Blank (Sem microcontrolador)**
*   **Finalidade:** Lógica pura e circuitos digitais passivos

<p align="center">
  <img src="https://wokwi.com/images/boards-photos/blank.svg" alt="Wokwi Blank" width="150">
</p>

---

## 🚀 Como Iniciar?
1. Abra um projeto em branco no simulador: 🚀 [**Wokwi Blank (Sem placa)**](https://wokwi.com/projects/new/blank).
2. Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Neste laboratório, subimos o nível da lógica digital. Em vez de apenas ligar e desligar LEDs simples, vamos usar **Portas Lógicas** integradas e um **Gerador de Clock** para criar uma mistura automática de cores em um LED RGB.

---

## 🎯 Objetivos Técnicos
*   Utilizar o componente **LED RGB** (Ânodo ou Cátodo Comum).
*   Integrar chips de **Portas Lógicas** (AND, OR) no Wokwi.
*   Trabalhar com o **Clock Generator** para automação de estados (Blink sem código).
*   Compreender a síntese aditiva de cores (RGB).

---

## 🧱 Setup de Hardware
| Componente | Função |
| :--- | :--- |
| **LED RGB** | Saída de tripla cor (Red, Green, Blue). |
| **Gate AND / OR** | Chips lógicos (74HCxx). |
| **Clock Generator** | Pulso automático (Onda Quadrada). |
| **Slide Switch** | Habilitação manual. |

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: Identificação RGB
1.  Conecte o Catodo (GND) do LED RGB ao terra.
2.  Ligue o VCC em cada pino (R, G, B) e identifique as cores puras.

### 🚀 Passo 2: O Sinal de Clock
1.  Ligue o **Clock Generator** (frequência 1Hz) no pino **Red (R)**.
2.  Observe o LED piscando sozinho. Isso é automação pura via hardware!

### 🚀 Passo 3: Lógica de Habilitação (AND)
1.  Insira uma **Porta AND**.
2.  Entrada 1: Clock Generator.
3.  Entrada 2: Slide Switch.
4.  Saída: Pino **Green (G)**.
5.  **Verifique:** O Verde só deve piscar se a Chave estiver ligada.

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, o LED RGB atua como um **Indicador de Status Multinível**:
- **Vermelho Piscante:** Alarme Crítico (Porta aberta ou Sensor falhando).
- **Amarelo (R+G):** Sistema em transição ou aquecimento.
- **Ciano (G+B):** Modo de Irrigação Ativo.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- Em um **APL Calçadista de Novo Hamburgo/Sapiranga**, como uma torre de sinalização colorida (Sinaleira Industrial) ajuda o operador a saber se a máquina está produzindo, parada ou em erro?

---

### ❓ Reflexão Técnica (Obrigatória para Entrega)
1.  **Desafio:** Como você faria para o LED RGB brilhar na cor **Branca** de forma constante usando os componentes disponíveis?
2.  Qual a diferença prática entre um LED RGB de **Anodo Comum** e um de **Catodo Comum** na hora de ligar os fios?

---

## 📤 Entrega (Classroom)
Abra o **Documento de Entrega** anexado à sua atividade no Classroom e preencha os seguintes requisitos:
- [ ] **Link Wokwi:** O seu circuito deve mostrar a cor Branca (resolução do Desafio 1) sendo gerada ou as portas lógicas testadas.
- [ ] **Respostas (Reflexão):** Responda as 2 perguntas da seção Reflexão Técnica diretamente no documento da atividade (explicando a lógica das cores e a diferença de Anodo/Catodo).

---
*UC S122 - Internet das Coisas*
