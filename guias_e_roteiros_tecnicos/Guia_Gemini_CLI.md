# Gemini CLI - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Interface de linha de comando para interagir com o modelo Gemini (Google), facilitando a automação e ajuda no terminal Linux.
**Contexto M3F:** [X] Gestão | [X] Produtividade | [X] Documentação

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Prompts de texto, conteúdo via Pipe (`stdin`), comandos CLI.
- **Saída (Output):** Respostas técnicas da IA, sugestões de código, explicações de logs.

## 3. Instalação e Configuração

### 🐧 Linux (Raspbian/Ubuntu)
1.  **Comando de Instalação:**
    ```bash
    npm install -g @google/gemini-cli
    ```
2.  **Configuração da Chave:** 
    - Gere a chave em: https://aistudio.google.com/
    - Adicione ao ambiente: `export GEMINI_API_KEY='sua_chave'`
3.  **Verificação:** `gemini "Qual o comando para listar diretórios no Linux?"`

## 4. Integração (Ecossistema S122)
- **Conecta com:** [./Guia_Gemini_CLI_Extensoes.md](./Guia_Gemini_CLI_Extensoes.md) para ampliar capacidades.
- **Utiliza:** [./Guia_Linux_Python_Ferramentas.md](./Guia_Linux_Python_Ferramentas.md) para scripts complementares.

**Links Relacionados (CORE):**
- Extensões: [./Guia_Gemini_CLI_Extensoes.md](./Guia_Gemini_CLI_Extensoes.md)
- Guia Python: [./Guia_Linux_Python_Ferramentas.md](./Guia_Linux_Python_Ferramentas.md)

## 5. Referências e Repositórios
- **Repositório GitHub:** https://github.com/google/gemini-cli
- **Google AI Studio:** https://aistudio.google.com/

## 6. Solução de Problemas (Troubleshooting)
- **Erro: "npm not found":** Instale o Node.js e NPM primeiro.
- **Erro de Cota (429):** Aguarde alguns segundos entre as requisições (limite da versão gratuita).

## 7. Fontes de Consulta (AI & Web)
- Google Generative AI Documentation: https://ai.google.dev/docs
- Gemini CLI GitHub: https://github.com/google/gemini-cli

---
*Documento em constante atualização. Versão: 2026/1*
