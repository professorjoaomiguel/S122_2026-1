# Classroom Bot (API Invisível)

Este diretório contém a API customizada (Google Apps Script) para integração autônoma entre automações locais (Terminal/IA) e o ecossistema do Google Classroom.

## Arquitetura Data-Driven
O arquivo `Code.js` foi desenhado para ser **totalmente reaproveitável**. Para utilizá-lo em outra disciplina ou semestre, basta editar as propriedades da variável de controle `CONFIG` no topo do script. O motor interno de requisições se adapta automaticamente.

---

## Endpoints da API (v2.6.0)

A API possui um único ponto de entrada universal (URL do Web App) que se ramifica de acordo com o método HTTP (GET ou POST) e o parâmetro `action`.

### 1. GET `/exec` (Rotas de Leitura)
Utilizado para extrair informações do Classroom de forma invisível.

**Parâmetros de Querystring:**
- `courseId` (Opcional): O ID da turma. Se omitido, a API usa o valor de `CONFIG.DEFAULT_COURSE_ID`.
- `action` (Opcional): Determina a ação da leitura.
  - **`list_assignments`** *(padrão)*: Retorna o array de Atividades (Status: Publicado e Rascunho).
  - **`list_announcements`**: Retorna os avisos/postagens do Mural da turma.
  - **`list_students`**: Retorna a lista completa de alunos matriculados (IDs, Nomes e E-mails).
  - **`get_course`**: Retorna os detalhes estruturais da turma (Nome, Descrição, Código de Inscrição e Link).
  - **`list_submissions`**: Retorna o status de entrega dos alunos. Exige o parâmetro `courseWorkId`.

---

### 2. POST `/exec` (Rotas de Criação)
Utilizado para injetar dados na turma. O *Body* da requisição deve ser obrigatoriamente um JSON.

#### A) Criação de Atividades Lote (`create_assignments`)
Permite criar múltiplas atividades ao mesmo tempo. Pode opcionalmente gerar e anexar o "Template de Entrega" automaticamente.

**Payload JSON de Exemplo:**
```json
{
  "action": "create_assignments",
  "courseId": "856497169680",
  "includeTemplate": true,
  "assignments": [
    {
      "title": "LAB 08: Automação WiFi",
      "description": "Siga o roteiro do repositório.",
      "state": "DRAFT",
      "githubUrl": "https://github.com/..."
    }
  ]
}
```

#### B) Postagem no Mural (`create_announcements`)
Permite publicar recados e avisos no mural da turma (Stream).

**Payload JSON de Exemplo:**
```json
{
  "action": "create_announcements",
  "courseId": "856497169680",
  "announcements": [
    {
      "text": "Olá turma! O prazo do laboratório foi prorrogado.",
      "state": "PUBLISHED"
    }
  ]
}
```

---

## Gerenciamento e Deploy
Sempre que o código em `Code.js` for atualizado localmente, utilize o CLASP para subir a nova versão:
1. Sincronizar código local com a nuvem: `clasp push`
2. Publicar uma nova release oficial do Web App: `clasp deploy -d "Nome_Da_Atualizacao"`

---

## Roadmap de Possibilidades (Classroom Advanced Service)
O bot atual implementa um subconjunto seguro da API. A lista abaixo serve como cardápio das famílias de funções disponíveis para o nosso bot explorar nas próximas fases evolutivas:

### 1. Gestão da Turma (Courses)
Namespace: `Classroom.Courses.*`
- `.get()`, `.list()`: Ler detalhes de uma ou várias turmas.
- `.create()`, `.update()`, `.patch()`: Criar novas turmas (sim, podemos criar turmas do zero!) ou alterar o nome, sala, descrição.
- `.remove()`: Arquivar ou deletar turmas.

### 2. Atividades e Materiais (CourseWork & Materials)
Namespace: `Classroom.Courses.CourseWork.*`
- `.list()`, `.get()`: Ler as atividades.
- `.create()`, `.patch()`, `.remove()`: Criar, editar ou deletar Atividades e Perguntas.
- `Classroom.Courses.CourseWorkMaterials.*`: O mesmo de cima, mas exclusivo para a aba "Materiais" (aquelas postagens sem nota).

### 3. Entregas e Notas (StudentSubmissions)
Namespace: `Classroom.Courses.CourseWork.StudentSubmissions.*`
- `.list()`, `.get()`: Buscar as devoluções (trabalhos entregues) de uma atividade.
- `.patch()`: Dar ou alterar a nota do aluno (`assignedGrade` / `draftGrade`).
- `.return()`: Devolver o trabalho oficialmente com a nota (fecha o ciclo).
- `.reclaim()`: O aluno "pegar de volta" (desfazer a entrega).
- `.modifyAttachments()`: O professor (bot) anexar um arquivo de correção no trabalho do aluno.

### 4. Pessoas (Roster)
Namespace: `Classroom.Courses.Students.*` e `Classroom.Courses.Teachers.*`
- `.list()`, `.get()`: Listar alunos e co-professores.
- `.create()`, `.remove()`: Matricular ou remover alunos/professores da turma.
- `Classroom.Invitations.*`: Enviar e gerenciar convites por e-mail para a turma.

### 5. Mural (Announcements)
Namespace: `Classroom.Courses.Announcements.*`
- `.list()`, `.get()`: Ler postagens do mural.
- `.create()`, `.patch()`, `.remove()`: Publicar, editar ou apagar postagens.

### 6. Tópicos (Topics)
Namespace: `Classroom.Courses.Topics.*`
- `.create()`, `.list()`, `.patch()`: Criar e gerenciar aquelas pastas organizacionais da aba "Atividades" (ex: criar o tópico "Unidade 2 - WebServers").

### 7. Responsáveis / Pais (Guardians) - *Apenas contas Workspace for Education*
Namespace: `Classroom.UserProfiles.Guardians.*`
- `.list()`, `.create()`: Convidar pais/responsáveis para receberem resumos de notas e pendências dos alunos.
