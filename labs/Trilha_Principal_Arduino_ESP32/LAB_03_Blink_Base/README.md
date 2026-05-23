# LAB 03: O Primeiro Sinal (Blink Base)

---

## 🚀 Como Iniciar?
Se você está no navegador, siga o [**Guia de Início Rápido**](../../../guias_e_roteiros_tecnicos/Guia_Wokwi_Inicio_Rapido.md) para configurar seu hardware e documentação em segundos.

---

Todo projeto de hardware começa com um sinal de vida. O "Blink" é o teste universal para garantir que o processador está alimentado, o código foi gravado e o clock está funcionando.

---

## 🎯 Objetivos Técnicos
*   Validar o ambiente de desenvolvimento e simulação.
*   Compreender a estrutura mínima de um programa Arduino (`setup` e `loop`).
*   Controlar o LED interno da placa (Built-in LED).

---

## ⚙️ Workflow Passo a Passo

### Nível 1: Estrutura Base
1.  Abra um 🚀 [**Projeto Vazio: Arduino Uno**](https://wokwi.com/projects/new/arduino-uno).
2.  Identifique as funções `void setup()` e `void loop()`.

### Nível 2: Saída Digital
1.  Utilize o pino **13** (ligado ao LED "L" da placa).
2.  Configure o pino como `OUTPUT`.

### Nível 3: O Ciclo de Blink
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

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Altere o código para que o LED pisque mais rápido (ex: 5 vezes por segundo). Qual parâmetro você deve mudar?
2.  O que acontece se colocarmos o comando `pinMode` dentro do `loop()` em vez do `setup()`?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja sair do navegador e começar a usar as ferramentas profissionais (VS Code + Git)? 
👉 [**Acesse o Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Print:** Screenshot do LED "L" aceso durante a simulação.

---
*UC S122 - Internet das Coisas*
