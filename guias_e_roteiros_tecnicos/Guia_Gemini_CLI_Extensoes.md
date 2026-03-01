# Gemini CLI Extensões - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Conjunto de extensões que adicionam habilidades específicas ao Gemini CLI, como planejamento (`blueprint`) e revisão de código (`code-review`).
**Contexto M3F:** [X] Gestão | [X] Produtividade | [X] Qualidade de Software

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Comandos específicos da extensão (ex: `/blueprint:plan`), arquivos do projeto.
- **Saída (Output):** Arquivos de plano (`PLAN.md`), tarefas (`TODO.md`), relatórios de revisão.

## 3. Instalação e Configuração

### 🐧 Linux / 🪟 Windows
1.  **Instalação do Blueprint:** `gemini extension install blueprint`
2.  **Instalação do Code Review:** `gemini extension install code-review`
3.  **Verificação:** `gemini extension list`

## 4. Integração (Ecossistema S122)
- **Conecta com:** Guia_Gemini_CLI.md (é pré-requisito).
- **Utiliza:** Guia_Git_Windows_e_Linux.md para salvar os planos gerados pela IA.

**Links Relacionados (CORE):**
- Guia Principal Gemini: Guia_Gemini_CLI.md
- Guia Git: Guia_Git_Windows_e_Linux.md

## 5. Referências e Repositórios
- **Extensões Oficiais:** https://github.com/google/gemini-cli-extensions

## 6. Solução de Problemas (Troubleshooting)
- **Erro: "Extension not found":** Verifique a ortografia do nome da extensão.
- **Erro ao Executar Comando:** Certifique-se de usar a barra inicial (ex: `/blueprint`).

## 7. Fontes de Consulta (AI & Web)
- Gemini CLI Extensions Repo: https://github.com/google/gemini-cli-extensions
- AI-Driven Development (PBL): (Artigos Sugeridos)

---
*Documento em constante atualização. Versão: 2026/1*
