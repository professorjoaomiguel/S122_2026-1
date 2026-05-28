# LAB 00: Introdução ao Wokwi e Componentes Básicos

---

### 🏛️ Mapeamento M3F (Multilayer Fog/Cloud)
*   **Camada Macro:** 🎛️ Camada 0: Fundamentos (Sem Código)
*   **Nível de Referência:** 📍 Nível 1: Sensor/Atuador (Conceitual / Eletricidade Básica)

---

## 🚀 Como Iniciar?
Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Este laboratório inicial serve para familiarização com a interface do Wokwi, manipulação de componentes e compreensão do fluxo de corrente em circuitos simples.

---

## 🎯 Objetivos Técnicos
*   Navegar na interface do Wokwi e utilizar o repositório de componentes (`+`).
*   Identificar componentes básicos: VCC, GND, Resistor, LED e Chaves.
*   Aprender a customizar componentes (cores e valores) e inspecionar o `diagram.json`.

---

## 🧱 Setup de Hardware
| Componente | Função | Quantidade |
| :--- | :--- | :--- |
| **VCC / GND** | Fonte de Energia e Referência. | 02/02 |
| **Resistor** | Limitador de corrente (Proteção). | 02 |
| **LED** | Saída Visual (Atuador simples). | 02 |
| **Pushbutton** | Entrada momentânea (Pulso). | 01 |
| **Slide Switch** | Entrada com retenção (Estado). | 01 |

---

## ⚙️ Workflow Passo a Passo

### 🚀 Passo 1: Circuito Manual (Pushbutton)
1.  Conecte o VCC -> Pushbutton -> Resistor -> LED -> GND.
2.  Inicie a simulação e pressione o botão. O LED deve acender apenas enquanto você pressiona.

### 🚀 Passo 2: Circuito com Retenção (Slide Switch)
1.  Monte um segundo circuito usando o **Slide Switch**.
2.  Observe que o LED permanece aceso ou apagado após o clique, simulando uma chave liga/desliga.

### 🚀 Passo 3: Inspeção JSON
1.  Clique na aba **diagram.json**.
2.  Localize o atributo `"attrs": { "color": "red" }` do LED e mude para `"green"`. Veja a mudança no editor.

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, este laboratório representa o teste de **Continuidade Elétrica**. Antes de programar, precisamos saber se os componentes físicos (como botões de emergência ou chaves de ignição) estão funcionando eletricamente.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- Em um **APL Metal-Mecânico**, como o comportamento de um **Pushbutton** se assemelha a um botão de parada de emergência de uma prensa?
- Por que a padronização de cores de fios (Vermelho para positivo, Preto para negativo) é vital para a manutenção em fábricas de **Canoas ou São Leopoldo**?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Adicione um terceiro LED ao circuito, mas faça com que ele brilhe **menos** que os outros. Qual propriedade do Resistor você deve alterar?
2.  O que acontece se você inverter a polaridade do LED (conectar o GND no Anodo)? Ele funciona?

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Reflexão:** Responda às perguntas da seção acima no seu relatório.

---
*UC S122 - Internet das Coisas*
