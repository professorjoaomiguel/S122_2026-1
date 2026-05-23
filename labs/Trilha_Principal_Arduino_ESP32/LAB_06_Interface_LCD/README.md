# LAB 06: Comunicação I2C e Displays

Exploramos o barramento serial industrial I2C para criar interfaces visuais locais. O foco aqui é o **acoplamento** de saída de dados (LCD) em um código que já possui entrada (Sensores).

---

## 🎯 Objetivos Técnicos
*   Compreender o endereçamento de dispositivos I2C.
*   Manipular a biblioteca `LiquidCrystal_I2C`.
*   Gerenciar o layout de informações em matrizes 16x2.

---

## 🧱 Setup de Hardware
Monte a base completa. Ela preserva os sensores do lab anterior:
*   **LCD 16x2 (I2C):** Pinos A4 (SDA) e A5 (SCL).
*   **Sensores (Base LAB 05):** DHT22 (Pino 4) e LDR (Pino A0).

---

## ⚙️ Workflow Passo a Passo

### Nível 1: Estrutura da IHM
Crie os ganchos para o display no código base do LAB 05.

```cpp
// [TAG] DEFINICOES
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  // [TAG] SETUP_LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  // [TAG] LEITURA_DADOS
  // [TAG] LOGICA_CONTROLE
  // [TAG] DISPLAY_LOCAL
  
  delay(1000);
}
```

### Nível 2: Moldura Estática (Máscara)
Defina a "carcaça" visual do LCD. Isso deve ocorrer apenas uma vez no `setup` ou ser fixo no `loop`.

```cpp
  // Insira em [TAG] SETUP_LCD:
  lcd.setCursor(0, 0); lcd.print("Temp:      C");
  lcd.setCursor(0, 1); lcd.print("Luz:       %");
```

### Nível 3: Acoplamento de Variáveis
Agora, encaixe as variáveis do **LAB 05** nas coordenadas livres da máscara.

```cpp
  // Insira em [TAG] DISPLAY_LOCAL:
  float t = 25.5; // Valor do DHT
  int l = 80;    // Valor do LDR
  
  lcd.setCursor(6, 0); lcd.print(t, 1); 
  lcd.setCursor(6, 1); lcd.print(l);
```

---

## 🌿 Conexão com o Projeto (Opcional)
Na **Estufa Inteligente**, o LCD é o **Painel Local**. Ele permite ao operador checar o clima sem precisar de internet ou do Serial Monitor.

---

## 🏭 Conexão com a Indústria (APL/RS)
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*
- Por que o barramento **I2C** melhora a modularidade do seu hardware ao permitir adicionar mais componentes usando os mesmos 2 fios?

---

## 🧠 Desafio e Reflexão Técnica
1.  **Desafio:** Use a tag `[TAG] LOGICA_CONTROLE` para fazer o LCD piscar o backlight se a temperatura passar de 40°C.
2.  Observe como as tags permitem que você separe "onde o dado nasce" (LEITURA) de "onde ele aparece" (DISPLAY). Qual a vantagem disso?

---

## 🛣️ Bifurcação: Quer se tornar Pro?
Deseja versionar este código no seu GitHub? Siga o [**Guia Profissional de VS Code aqui.**](../90_GUIA_PROFISSIONAL_VSCODE/)

---

## 📤 Entrega (Classroom)
*   **Link Wokwi:** [Seu Link]
*   **Foto/Screenshot:** Foto do LCD exibindo dados reais.

---
*UC S122 - Internet das Coisas*
