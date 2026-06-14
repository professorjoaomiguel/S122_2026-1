/**
 * @fileoverview API REST invisível para integração do Google Classroom com o Terminal do Agente.
 * Pode ser reutilizada em outras disciplinas alterando o bloco de configurações.
 * @version 2.1.0
 * 
 * =====================================================================
 * ENDPOINTS DA API
 * =====================================================================
 * 
 * 1. GET /exec
 *    - Descrição: Retorna a lista de atividades (PUBLISHED e DRAFT).
 *    - Parâmetros (Querystring):
 *      - courseId (opcional): Sobrescreve o ID padrão da turma configurado abaixo.
 * 
 * 2. POST /exec
 *    - Descrição: Cria novas atividades dinamicamente.
 *    - Body (JSON):
 *      {
 *        "courseId": "856497169680",
 *        "action": "create_assignments",
 *        "includeTemplate": true,
 *        "assignments": [
 *          { "title": "Nome do LAB", "description": "Instruções", "state": "DRAFT", "githubUrl": "https://..." }
 *        ]
 *      }
 * =====================================================================
 */

// =====================================================================
// CONFIGURAÇÕES GLOBAIS DA DISCIPLINA (Variavéis Data-Driven)
// Mude os valores abaixo para adaptar esta API para outra turma/disciplina
// =====================================================================
var CONFIG = {
  // 1. Configuração do Classroom
  DEFAULT_COURSE_ID: '856497169680', // ID da turma (ex: S122 - Internet das Coisas)
  
  // 2. Comportamento Padrão das Atividades
  ASSIGNMENT_MAX_POINTS: 100,        // Pontuação máxima padrão para os trabalhos
  DEFAULT_STATE: 'DRAFT',            // Status de criação padrão ('DRAFT' ou 'PUBLISHED')
  
  // 3. Estrutura do Template de Entrega (Google Docs dinâmico)
  TEMPLATE_TITLE: '[Relatório de Entrega] Laboratório',
  TEMPLATE_CONTENT: 
    "Membros da Equipe:\n" +
    "Data da Prática:\n\n" +
    "=========================================\n" +
    "📋 CHECKLIST DE REQUISITOS OBRIGATÓRIOS\n" +
    "=========================================\n" +
    "[ ] (Insira os prints/links exigidos pelo Roteiro do GitHub aqui)\n\n\n" +
    "=========================================\n" +
    "🧠 REFLEXÃO TÉCNICA (OBRIGATÓRIO)\n" +
    "=========================================\n" +
    "(Cole aqui as perguntas do GitHub e responda com as suas palavras)\n"
};
// =====================================================================


/**
 * Roteador de requisições HTTP GET (Leitura)
 */
function doGet(e) {
  var courseId = (e && e.parameter && e.parameter.courseId) ? e.parameter.courseId : CONFIG.DEFAULT_COURSE_ID;
  
  try {
    var resposta = Classroom.Courses.CourseWork.list(courseId, { courseWorkStates: ["PUBLISHED", "DRAFT"] });
    var atividades = resposta.courseWork || [];
    
    // Mapeamento limpo dos dados essenciais para tráfego em rede
    var output = atividades.map(function(atv) {
      return {
        id: atv.id,
        title: atv.title,
        state: atv.state,
        creationTime: atv.creationTime,
        workType: atv.workType,
        description: atv.description || '',
        materials: atv.materials || []
      };
    });
    
    return criarRespostaJSON({ status: 'success', data: output });
      
  } catch (err) {
    return criarRespostaJSON({ status: 'error', message: err.message });
  }
}

/**
 * Roteador de requisições HTTP POST (Escrita/Criação Dinâmica)
 */
function doPost(e) {
  try {
    if (!e || !e.postData || !e.postData.contents) {
      throw new Error("Payload JSON vazio ou inválido.");
    }
    
    var payload = JSON.parse(e.postData.contents);
    var courseId = payload.courseId || CONFIG.DEFAULT_COURSE_ID;
    
    if (payload.action === 'create_assignments') {
      return criarRespostaJSON(criarAtividadesDinamicamente(courseId, payload));
    }
    
    throw new Error("Ação não reconhecida: " + payload.action);
    
  } catch (err) {
    return criarRespostaJSON({ status: 'error', message: err.message });
  }
}

/**
 * Motor de criação dinâmica de atividades e templates orientado a dados.
 */
function criarAtividadesDinamicamente(courseId, payloadData) {
  var results = [];
  var templateId = null;
  
  // Se a requisição pediu, gera o Template Base do Google Docs em tempo real baseado no CONFIG
  if (payloadData.includeTemplate) {
    var doc = DocumentApp.create(CONFIG.TEMPLATE_TITLE);
    doc.getBody().insertParagraph(0, CONFIG.TEMPLATE_CONTENT);
    doc.saveAndClose();
    templateId = doc.getId();
    results.push("Template Base gerado automaticamente com ID: " + templateId);
  }
  
  var assignments = payloadData.assignments || [];
  
  // Iteração de criação das atividades baseadas no JSON e no CONFIG
  assignments.forEach(function(lab) {
    var courseWork = {
      title: lab.title,
      description: lab.description || "",
      state: lab.state || CONFIG.DEFAULT_STATE,
      workType: "ASSIGNMENT",
      maxPoints: CONFIG.ASSIGNMENT_MAX_POINTS,
      materials: []
    };
    
    // Adiciona o link do GitHub se fornecido no Payload
    if (lab.githubUrl) {
      courseWork.materials.push({ link: { url: lab.githubUrl } });
    }
    
    // Anexa o Documento Template com Cópia Individual se o template foi gerado
    if (templateId) {
      courseWork.materials.push({
        driveFile: {
          driveFile: { id: templateId },
          shareMode: "STUDENT_COPY"
        }
      });
    }
    
    var result = Classroom.Courses.CourseWork.create(courseWork, courseId);
    results.push("Criado [" + result.state + "]: " + result.title + " (ID: " + result.id + ")");
  });
  
  return { status: 'success', created: results };
}

/**
 * Utilitário padrão para envelopamento de respostas HTTP em JSON.
 */
function criarRespostaJSON(objeto) {
  return ContentService.createTextOutput(JSON.stringify(objeto))
    .setMimeType(ContentService.MimeType.JSON);
}
