# VirtualBox e Raspbian OS - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Criar um ambiente isolado (Máquina Virtual) para rodar o Gateway IoT (Raspberry Pi OS) sem afetar o sistema operacional principal do computador.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Imagem ISO/IMG do sistema operacional, comandos via teclado/mouse ou SSH.
- **Saída (Output):** Ambiente Linux funcional, serviços Docker rodando (MQTT, InfluxDB), acesso via rede local.

## 3. Instalação e Configuração

### 🪟 Windows
1.  **Download VirtualBox:** https://www.virtualbox.org/wiki/Downloads
2.  **Download Raspbian:** https://www.raspberrypi.com/software/operating-systems/
3.  **Procedimento:** Instale o VirtualBox, crie uma nova VM (Linux/Debian 64-bit), anexe a imagem do Raspbian e siga a instalação.
4.  **Verificação:** Verifique se a VM inicia e atinge a tela de login.

### 🐧 Linux (Host)
1.  **Comando de Instalação:** `sudo apt install virtualbox`
2.  **Verificação:** `vboxmanage --version`

## 4. Integração (Ecossistema S122)
- **Conecta com:** VS Code (via SSH) para desenvolvimento e MobaXterm para terminal.
- **Depende de:** [./Guia_Infraestrutura_Rede_Local.md](./Guia_Infraestrutura_Rede_Local.md) para configuração do Modo Bridge.

**Links Relacionados (CORE):**
- Guia de Rede: [./Guia_Infraestrutura_Rede_Local.md](./Guia_Infraestrutura_Rede_Local.md)
- Guia de Ferramentas: [./Guia_Ferramentas_e_Software.md](./Guia_Ferramentas_e_Software.md)

## 5. Referências e Repositórios
- **Documentação Oficial VirtualBox:** https://www.virtualbox.org/wiki/Documentation
- **Documentação Raspberry Pi OS:** https://www.raspberrypi.com/documentation/

## 6. Solução de Problemas (Troubleshooting)
- **Erro: VT-x/AMD-V não habilitado:** É necessário habilitar a virtualização na BIOS do computador.
- **Erro: Sem Internet na VM:** Verifique se o adaptador está em NAT ou se o Modo Bridge está configurado corretamente no roteador.

## 7. Fontes de Consulta (AI & Web)
- Documentação Oracle VirtualBox: https://www.virtualbox.org/manual/ch01.html
- Raspberry Pi Documentation: https://www.raspberrypi.com/documentation/computers/getting-started.html
- Debian Wiki (Base do Raspbian): https://wiki.debian.org/

---
*Documento em constante atualização. Versão: 2026/1*
