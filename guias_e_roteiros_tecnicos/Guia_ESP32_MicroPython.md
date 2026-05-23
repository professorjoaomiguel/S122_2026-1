# ESP32 (MicroPython) - Guia Técnico S122
`#MicroPython` `#ESP32` `#Hardware` `#Edge` `#ParallelTrack`

## 1. Visão Geral (O Básico)
**Para que serve:** O ESP32 é um microcontrolador robusto com WiFi e Bluetooth integrados. Nesta trilha paralela, exploramos como rodar MicroPython nele, permitindo que você aplique os conhecimentos da Pi Pico em uma placa com conectividade nativa.
**Contexto M3F:** [X] Percepção (Edge) | [X] Transporte (Fog) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Sensores analógicos/digitais, comandos via REPL, mensagens MQTT.
- **Saída (Output):** Atuadores, requisições HTTP, publicação de dados em nuvem.

## 3. Instalação e Configuração (Flash do Firmware)
Diferente da Pi Pico, o ESP32 exige uma ferramenta de flash específica (`esptool`).

1. **Firmware:** Baixe o arquivo `.bin` para o seu modelo de ESP32 em: [micropython.org/download/esp32](https://micropython.org/download/esp32/).
2. **Ferramenta de Flash:** Utilize o **Thonny IDE** (recomendado para iniciantes):
   * Vá em `Tools` -> `Options` -> `Interpreter`.
   * Selecione `MicroPython (ESP32)`.
   * Clique em `Install or update MicroPython` e siga as instruções.
3. **Verificação:** O terminal do Thonny deve exibir a mensagem `MicroPython v... on ...; ESP32 module with ESP32`.

## 4. Integração (Ecossistema S122)
- **Continuidade:** Este guia faz parte da **Trilha Paralela**. Utilize-o após dominar os fundamentos na Pi Pico.
- **Diferencial:** O foco aqui é o uso da biblioteca `network` para conectar a estufa à internet usando Python.

**Links Relacionados (CORE):**
- Guia Pi Pico: [./Guia_PiPico_MicroPython.md](./Guia_PiPico_MicroPython.md)
- Guia Thonny: [./Guia_Thonny_MicroPython.md](./Guia_Thonny_MicroPython.md)

## 5. Referências e Repositórios
- **Documentação MicroPython ESP32:** https://docs.micropython.org/en/latest/esp32/quickref.html
- **Repositório de Firmware:** https://micropython.org/download/esp32/

## 6. Solução de Problemas (Troubleshooting)
- **Erro: Device not found:** Verifique se o cabo USB é de dados e se os drivers CP210x/CH340 estão instalados.
- **Boot Loop:** Às vezes é necessário pressionar o botão `BOOT` no ESP32 no momento do flash.

---
**⬅️ [Voltar ao Índice](./WIKI_INDEX.md) | ➡️ Próximo: [Thonny IDE](./Guia_Thonny_MicroPython.md) | 📤 [Padrão de Entrega](./PADRAO_DE_ENTREGA_CLASSROOM.md)**

*Documento em constante atualização. Versão: 2026/1*
