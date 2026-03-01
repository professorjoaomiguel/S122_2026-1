# ESP32 e MicroPython - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Desenvolvimento de sistemas de borda (Edge) que coletam dados de sensores e controlam atuadores em tempo real.
**Contexto M3F:** [X] Percepção (Edge) | [ ] Transporte (Fog) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Sinais analógicos/digitais de sensores, mensagens via Wi-Fi (MQTT/ESP-NOW), código via Serial.
- **Saída (Output):** Atuadores (LEDs, Motores, Relés), dados para o Gateway via Wi-Fi.

## 3. Instalação e Configuração

### 🪟 Windows / 🐧 Linux
1.  **Download MicroPython Firmware:** https://micropython.org/download/esp32/
2.  **Procedimento de Flash:** Use o Thonny IDE ou a ferramenta `esptool.py` para gravar o firmware na placa.
3.  **Verificação:** Acesse o REPL (Terminal) e execute `import esp32; print("Conectado")`.

## 4. Integração (Ecossistema S122)
- **Conecta com:** [./Guia_Thonny_MicroPython.md](./Guia_Thonny_MicroPython.md) para programação e [./Guia_Wokwi_VSCode_Integracao.md](./Guia_Wokwi_VSCode_Integracao.md) para simulação.
- **Depende de:** Roteador da rede local para enviar dados ao Broker MQTT na VM.

**Links Relacionados (CORE):**
- Guia Thonny: [./Guia_Thonny_MicroPython.md](./Guia_Thonny_MicroPython.md)
- Guia Wokwi: [./Guia_Wokwi_VSCode_Integracao.md](./Guia_Wokwi_VSCode_Integracao.md)

## 5. Referências e Repositórios
- **Documentação MicroPython:** https://docs.micropython.org
- **Repositório ESP32 MicroPython:** https://github.com/micropython/micropython

## 6. Solução de Problemas (Troubleshooting)
- **Erro: Device not found:** Verifique se o cabo USB é de dados (alguns são apenas carga) e se os drivers CP210x ou CH340 estão instalados.
- **Erro: MemoryError:** Evite carregar scripts muito grandes; tente otimizar o uso de variáveis e imports.

## 7. Fontes de Consulta (AI & Web)
- MicroPython Documentation for ESP32: https://docs.micropython.org/en/latest/esp32/quickref.html
- Wokwi Documentation: https://docs.wokwi.com/
- Espressif ESP32 Technical Reference: https://www.espressif.com/en/support/documents/technical-documents

---
*Documento em constante atualização. Versão: 2026/1*
