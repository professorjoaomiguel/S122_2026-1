# Raspberry Pi OS (Raspbian) e Debian - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** O Debian é um sistema operacional Linux robusto e estável ("O SO Universal"). O Raspberry Pi OS (antigo Raspbian) é a versão otimizada para a arquitetura ARM, sendo a base do nosso Gateway IoT.
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Comandos via terminal (CLI), arquivos de configuração (`.conf`, `.yaml`), pacotes via repositórios oficiais.
- **Saída (Output):** Execução de serviços (daemons), logs de sistema em `/var/log`, gerenciamento de hardware e rede.

## 3. Instalação e Configuração

### 🐧 No contexto da VM (VirtualBox)
1.  **Download da Imagem:** https://www.raspberrypi.com/software/operating-systems/ (Recomendado: Raspberry Pi OS Lite 64-bit para uso como servidor).
2.  **Procedimento:** Siga o `Guia_Virtualizacao_Raspbian.md` para criar a VM e anexar a imagem.
3.  **Configuração Inicial:** 
    - Use `sudo raspi-config` para configurar localização, rede e habilitar o SSH.
    - Atualize o sistema: `sudo apt update && sudo apt upgrade -y`.
4.  **Verificação:** `cat /etc/os-release` para confirmar a versão do Debian/Raspbian.

## 4. Integração (Ecossistema S122)
- **Conecta com:** Docker (instalação via script shell no Debian).
- **Depende de:** Guia_Virtualizacao_Raspbian.md para existir como Máquina Virtual.

**Links Relacionados (CORE):**
- Guia de Virtualização: Guia_Virtualizacao_Raspbian.md
- Guia de Docker: Guia_Docker_e_Containers.md

## 5. Referências e Repositórios
- **Debian Handbook:** https://debian-handbook.info/browse/stable/
- **Raspberry Pi OS Documentation:** https://www.raspberrypi.com/documentation/computers/os.html
- **Repositórios Oficiais Debian:** https://www.debian.org/distrib/packages

## 6. Solução de Problemas (Troubleshooting)
- **Erro: "E: Could not get lock /var/lib/dpkg/lock":** O gerenciador de pacotes está sendo usado por outro processo. Aguarde ou reinicie.
- **Erro: Comando não encontrado:** Verifique se o pacote está instalado ou se o comando exige privilégios de `sudo`.
- **Falta de Espaço:** Use `sudo apt clean` para limpar o cache de pacotes baixados.

## 7. Fontes de Consulta (AI & Web)
- Debian Project: https://www.debian.org/
- Raspberry Pi Foundation: https://www.raspberrypi.com/
- Linux Journey (Tutorial de Terminal): https://linuxjourney.com/

---
*Documento em constante atualização. Versão: 2026/1*
