# LAB 02: Desafio Cromático (Lógica com LED RGB)

---

## 🚀 Como Iniciar?
Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

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

### Nível 1: Identificação RGB
1.  Conecte o Catodo (GND) do LED RGB ao terra.
2.  Ligue o VCC em cada pino (R, G, B) e identifique as cores puras.

### Nível 2: O Sinal de Clock
1.  Ligue o **Clock Generator** (frequência 1Hz) no pino **Red (R)**.
2.  Observe o LED piscando sozinho. Isso é automação pura via hardware!

### Nível 3: Lógica de Habilitação (AND)
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

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Como você faria para o LED RGB brilhar na cor **Branca** de forma constante usando os componentes disponíveis?
2.  Qual a diferença prática entre um LED RGB de **Anodo Comum** e um de **Catodo Comum** na hora de ligar os fios?

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Reflexão:** Explique a lógica que você usou para misturar as cores no seu circuito.

---
*UC S122 - Internet das Coisas*
