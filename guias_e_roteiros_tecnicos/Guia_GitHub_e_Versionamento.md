# Guia Técnico: GitHub e Controle de Versão - S122

O GitHub será utilizado para hospedar o código dos projetos, documentação e diários de bordo, garantindo a colaboração entre os membros do grupo.

## 1. Configuração Inicial
1.  Crie uma conta em: https://github.com
2.  Instale o Git no seu computador: https://git-scm.com
3.  Configure seu usuário no terminal:
    ```bash
    git config --global user.name "Seu Nome"
    git config --global user.email "seu.email@exemplo.com"
    ```

## 2. Fluxo de Trabalho Recomendado
Para a disciplina de IoT, utilizaremos o seguinte fluxo:
1.  **Criar Repositório:** Um membro do grupo cria o repositório no GitHub.
2.  **Convidar Colaboradores:** Adicione os colegas e o professor em *Settings > Collaborators*.
3.  **Clonar:** `git clone https://github.com/usuario/projeto-iot.git`
4.  **Ciclo de Entrega:**
    - `git add .` (Prepara os arquivos).
    - `git commit -m "Sua mensagem descritiva"` (Grava a versão).
    - `git push` (Sobe para o GitHub).

## 3. O arquivo README.md
O README é o "cartão de visitas" do seu projeto. Ele deve conter:
- Título do Projeto e ODS Alvo.
- Integrantes do Grupo.
- Arquitetura M3F (Esquema de ligação).
- Instruções de como rodar o Docker Compose.

## 4. GitHub Student Developer Pack
Como aluno do SENAI, você tem direito a benefícios gratuitos (Copilot, créditos em nuvem, etc).
- **Inscreva-se em:** https://education.github.com/pack
