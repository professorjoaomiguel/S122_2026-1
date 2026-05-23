# Raspberry Pi Pico (MicroPython) - Guia Técnico S122
`#MicroPython` `#PiPico` `#Hardware` `#Edge`

## 1. Visão Geral (O Básico)
**Para que serve:** A Raspberry Pi Pico é uma placa microcontroladora baseada no chip RP2040 (desenvolvido pela própria Raspberry Pi Foundation). Diferente do Arduino Uno clássico, ela possui processador Dual-Core, mais memória e suporte nativo para MicroPython, tornando-se excelente para aprendizado de lógica e IoT sem a complexidade de rede inicial do ESP32.
**Contexto M3F:** [X] Percepção (Edge) | [ ] Transporte (Fog) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
Para entender como esta ferramenta se comunica no ecossistema:
- **Entrada (Input):** Código Python via cabo USB (Serial/REPL), sensores analógicos e digitais.
- **Saída (Output):** Sinais elétricos para atuadores (LEDs, Motores), mensagens impressas no terminal Serial (REPL).

## 3. Instalação e Configuração (Flash do Firmware)

Para programar em MicroPython, a placa precisa do "sistema operacional" (Firmware) instalado.

### 🔌 Procedimento de Flash (Windows e Linux)
1.  **Download do Firmware:** Baixe o arquivo `.uf2` mais recente para a Pi Pico oficial no site: https://micropython.org/download/rp2-pico/
2.  **Modo Bootloader:** 
    * Pressione e **segure** o botão `BOOTSEL` na placa.
    * Conecte o cabo USB no computador.
    * Solte o botão `BOOTSEL`. A placa deve aparecer como um pen drive (drive USB) chamado `RPI-RP2`.
3.  **Instalação:** Arraste e solte o arquivo `.uf2` que você baixou para dentro desse "pen drive".
4.  **Conclusão:** A placa irá reiniciar automaticamente. O pen drive sumirá e ela estará pronta para uso via IDE (Thonny).

## 4. Ambiente de Desenvolvimento (IDE)
Nós utilizaremos a IDE **Thonny** para interagir com a Pi Pico, pois ela possui o ambiente REPL (Read-Eval-Print Loop) integrado.

- **Conecta com:** [Guia do Thonny e MicroPython](./Guia_Thonny_MicroPython.md) para escrever e enviar o código.
- **Dica:** O código que você quer que execute sozinho quando ligar na tomada (sem o PC) deve se chamar `main.py` e ser salvo **dentro** da memória da placa.

## 5. Exemplo de Código (Blink Local)
Diferente do C++, o Python não exige as funções `setup()` e `loop()`. Tudo é executado linearmente.

```python
from machine import Pin
import time

# Configura o LED onboard (Pino 25) como Saída
led = Pin(25, Pin.OUT)

while True: # Equivalente ao loop() do Arduino
    led.toggle() # Inverte o estado do LED
    print("Piscou!")
    time.sleep(1) # Espera 1 segundo
```

## 6. Referências e Repositórios
- **Documentação Oficial Pi Pico:** https://www.raspberrypi.com/documentation/microcontrollers/
- **Documentação MicroPython RP2:** https://docs.micropython.org/en/latest/rp2/quickref.html

## 7. Solução de Problemas (Troubleshooting)
- **Erro: "Device is busy" no Thonny:** Pare a execução do script atual (botão Stop/Vermelho) antes de tentar salvar um novo arquivo.
- **A placa não aparece como Pen Drive:** Certifique-se de usar um cabo USB que transmita **dados** (muitos cabos de celular antigos só transmitem energia). Tente pressionar o `BOOTSEL` com mais firmeza *antes* de plugar.

---
**⬅️ [Voltar ao Índice](./WIKI_INDEX.md) | ➡️ Próximo: [Thonny IDE](./Guia_Thonny_MicroPython.md) | 📤 [Padrão de Entrega](./PADRAO_DE_ENTREGA_CLASSROOM.md)**

*Documento em constante atualização. Versão: 2026/1*
