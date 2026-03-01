# Ferramentas Linux e Python - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** O Python é a linguagem "cola" da nossa arquitetura. Este guia cobre o gerenciamento de bibliotecas (pip), isolamento de projetos (venv) e comunicação com APIs (requests).
**Contexto M3F:** [ ] Percepção (Edge) | [X] Transporte (Fog) | [X] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Scripts `.py`, comandos via terminal, dados de APIs externas (JSON).
- **Saída (Output):** Execução de lógica de integração, requisições HTTP para serviços cloud, logs de automação.

## 3. Instalação e Configuração

### 🐧 Linux (Raspbian/Ubuntu) - Recomendado
1.  **Instalação do Python e Pip:**
    ```bash
    sudo apt update
    sudo apt install python3 python3-pip python3-venv -y
    ```
2.  **Ambientes Virtuais (venv):** Sempre use venv para evitar corromper o Python do sistema.
    - **Criar:** `python3 -m venv venv`
    - **Ativar:** `source venv/bin/activate`
3.  **Gerenciamento de Pacotes (pip):**
    - **Instalar bibliotecas:** `pip install requests google-generativeai`

### 🪟 Windows
1.  **Download Python:** https://www.python.org/downloads/
2.  **Procedimento:** Durante a instalação, marque a caixa **"Add Python to PATH"**.
3.  **Ativando venv no Windows:** `.\venv\Scripts\activate`

## 4. Integração (Ecossistema S122)
- **Conecta com:** Guia_Gemini_CLI.md (necessita de Python e venv).
- **Utiliza:** Biblioteca `requests` para enviar dados do Gateway para APIs de Terceiros.

**Links Relacionados (CORE):**
- Guia Gemini CLI: Guia_Gemini_CLI.md
- Scripts Técnicos: ../S122_2026-1_Execucao/S122_2026-1_Scripts_e_Configuracoes.md

## 5. Referências e Repositórios
- **Documentação Oficial Python:** https://docs.python.org/3/
- **Guia da Biblioteca Requests:** https://requests.readthedocs.io
- **Python Package Index (PyPI):** https://pypi.org

## 6. Solução de Problemas (Troubleshooting)
- **Erro: "pip: command not found":** Certifique-se de instalar o `python3-pip`.
- **Erro: Permissão negada no pip:** Nunca use `sudo pip install`. Use sempre ambientes virtuais (`venv`).
- **Erro de Certificado SSL:** Verifique se a data/hora da sua VM está correta.

## 7. Fontes de Consulta (AI & Web)
- Python Venv Module: https://docs.python.org/3/library/venv.html
- Pip User Guide: https://pip.pypa.io/en/stable/user_guide/
- Requests Library: https://requests.readthedocs.io/en/latest/

---
*Documento em constante atualização. Versão: 2026/1*
