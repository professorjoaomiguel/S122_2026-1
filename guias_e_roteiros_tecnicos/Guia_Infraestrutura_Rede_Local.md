# Infraestrutura de Rede Local (LAN) - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Isolar o tráfego IoT dos experimentos da rede institucional, garantindo estabilidade e IP fixo para os Gateway e Dispositivos.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Conexão via cabo Ethernet (Host) e Wi-Fi (ESP32).
- **Saída (Output):** Conectividade IP entre as camadas M3F, acesso à Internet (via Bridge/NAT).

## 3. Instalação e Configuração

### ⚙️ Hardware (Roteador de Bancada)
1.  **Configuração do SSID:** Defina um nome de rede (ex: `SENAI_IOT_BANCADA_01`).
2.  **Modo de Operação:** Access Point com servidor DHCP ativo.
3.  **Endereçamento:** Faixa sugerida `192.168.0.x`.

### 💻 No VirtualBox (Gateway)
1.  **Procedimento:** Alterar adaptador para **Placa em Modo Bridge**.
2.  **Verificação:** Execute `ip a` no terminal do Raspbian para ver o IP recebido.

## 4. Integração (Ecossistema S122)
- **Conecta com:** Todos os dispositivos físicos (ESP32) e virtuais (Docker).
- **Depende de:** [./Checklist_Hardware_Infraestrutura.md](./Checklist_Hardware_Infraestrutura.md) para montagem física.

**Links Relacionados (CORE):**
- Checklist Hardware: [./Checklist_Hardware_Infraestrutura.md](./Checklist_Hardware_Infraestrutura.md)
- Guia Virtualização: [./Guia_Virtualizacao_Raspbian.md](./Guia_Virtualizacao_Raspbian.md)

## 5. Referências e Repositórios
- **O que é Rede Bridge?** https://www.virtualbox.org/manual/ch06.html#network_bridged

## 6. Solução de Problemas (Troubleshooting)
- **VM sem IP:** Verifique se o cabo Ethernet está conectado e se o computador físico pegou IP do roteador.
- **ESP32 não conecta:** Verifique a senha do Wi-Fi e se o roteador atingiu o limite de dispositivos.

## 7. Fontes de Consulta (AI & Web)
- Networking in VirtualBox: https://www.virtualbox.org/manual/ch06.html
- Tutorial Redes Privadas: (Baseado em melhores práticas de Lab de Redes).

---
*Documento em constante atualização. Versão: 2026/1*
