# LAB 01: Lógica Digital com Chaves e LEDs

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

Neste laboratório, aplicamos os conceitos de lógica digital (Portas AND, OR e NOT) utilizando apenas componentes físicos passivos. É o primeiro passo para entender como o hardware "toma decisões" antes mesmo de inserirmos um microprocessador.

---

## 🎯 Objetivos Técnicos
*   Implementar a função **AND** usando chaves em série.
*   Implementar a função **OR** usando chaves em paralelo.
*   Implementar a função **NOT** (Inversão lógica).
*   Associar estados físicos (ligado/desligado) a estados lógicos (Verdadeiro/Falso).

---

## 🧱 Setup de Hardware
| Componente | Função Lógica Representada |
| :--- | :--- |
| **Switches em Série** | Função AND (E) |
| **Switches em Paralelo** | Função OR (OU) |
| **Circuito Inversor** | Função NOT (NÃO) |
| **LED Vermelho** | Resultado da Expressão Lógica (Output) |

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: A Lógica "E" (AND)
1.  Conecte duas chaves em série entre o VCC and o LED.
2.  Verifique: O LED só acende quando a Chave A **E** a Chave B estão ligadas?

### 🚀 Passo 2: A Lógica "OU" (OR)
1.  Conecte duas chaves em paralelo.
2.  Verifique: O LED acende se a Chave A **OU** a Chave B estiver ligada?

### 🚀 Passo 3: A Lógica "NÃO" (NOT)
1.  Monte um circuito onde o LED permanece aceso por padrão e apaga quando a chave é pressionada.

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, a lógica digital é usada para segurança redundante:
- **AND:** O sistema de irrigação só liga se houver "Nível de Água OK" **E** "Solo Seco".
- **OR:** O Alarme deve tocar se a "Temperatura estiver Alta" **OU** a "Umidade estiver Baixa".

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- Como a lógica **AND** é aplicada em sistemas de segurança de máquinas (bimano) no **APL Moveleiro de Bento Gonçalves**?
- Por que é importante que uma máquina só opere se dois botões forem pressionados simultaneamente?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Como você faria para criar uma função **NAND** (NOT AND) usando apenas chaves e LEDs?
2.  Na função **AND**, o que acontece se apenas uma das chaves estiver ligada? Explique fisicamente o que acontece com a corrente.

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Relatório:** Preencha a Tabela Verdade observada para cada nível.

---
*UC S122 - Internet das Coisas*
