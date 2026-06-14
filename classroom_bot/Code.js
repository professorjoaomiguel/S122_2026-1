/**
 * @fileoverview API REST invisível para integração do Google Classroom com o Terminal do Agente.
 * Pode ser reutilizada em outras disciplinas alterando o bloco de configurações.
 * @version 2.5.0
 * 
 * =====================================================================
 * ENDPOINTS DA API
 * =====================================================================
 * 
 * 1. GET /exec
 *    - Descrição: Retorna dados da turma.
 *    - Parâmetros (Querystring):
 *      - courseId (opcional): Sobrescreve o ID padrão da turma.
 *      - action (opcional): 
 *        - "list_assignments" (padrão): Lista as atividades.
 *        - "list_announcements": Lista as mensagens do mural.
 *        - "list_students": Lista os alunos e e-mails matriculados.
 *        - "get_course": Retorna detalhes da turma (código de inscrição, etc).
 * 
 * 2. POST /exec
 *    - Descrição: Cria novos recursos dinamicamente.
 *    - Body JSON (Atividades): { "action": "create_assignments", ... }
 *    - Body JSON (Mural): { "action": "create_announcements", "announcements": [{ "text": "Olá turma!" }] }
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
  var action = (e && e.parameter && e.parameter.action) ? e.parameter.action : 'list_assignments';
  
  try {
    if (action === 'list_announcements') {
      return buildJsonResponse({ status: 'success', data: listAnnouncements(courseId) });
    } else if (action === 'list_students') {
      return buildJsonResponse({ status: 'success', data: listStudents(courseId) });
    } else if (action === 'get_course') {
      return buildJsonResponse({ status: 'success', data: getCourseDetails(courseId) });
    }
    
    // Fallback: list_assignments
    return buildJsonResponse({ status: 'success', data: listAssignments(courseId) });
      
  } catch (err) {
    return buildJsonResponse({ status: 'error', message: err.message });
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
      return buildJsonResponse(createAssignments(courseId, payload));
    } else if (payload.action === 'create_announcements') {
      return buildJsonResponse(createAnnouncements(courseId, payload));
    }
    
    throw new Error("Ação não reconhecida: " + payload.action);
    
  } catch (err) {
    return buildJsonResponse({ status: 'error', message: err.message });
  }
}

// =====================================================================
// MOTORES DE EXECUÇÃO (Serviços)
// =====================================================================

/**
 * Motor de listagem de Atividades (Publicadas e Rascunhos).
 */
function listAssignments(courseId) {
  var response = Classroom.Courses.CourseWork.list(courseId, { courseWorkStates: ["PUBLISHED", "DRAFT"] });
  var assignments = response.courseWork || [];
  
  return assignments.map(function(atv) {
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
}

/**
 * Motor de criação dinâmica de atividades e templates orientado a dados.
 */
function createAssignments(courseId, payloadData) {
  var results = [];
  var templateId = null;
  
  if (payloadData.includeTemplate) {
    var doc = DocumentApp.create(CONFIG.TEMPLATE_TITLE);
    doc.getBody().insertParagraph(0, CONFIG.TEMPLATE_CONTENT);
    doc.saveAndClose();
    templateId = doc.getId();
    results.push("Template Base gerado automaticamente com ID: " + templateId);
  }
  
  var assignments = payloadData.assignments || [];
  
  assignments.forEach(function(lab) {
    var courseWork = {
      title: lab.title,
      description: lab.description || "",
      state: lab.state || CONFIG.DEFAULT_STATE,
      workType: "ASSIGNMENT",
      maxPoints: CONFIG.ASSIGNMENT_MAX_POINTS,
      materials: []
    };
    
    if (lab.githubUrl) {
      courseWork.materials.push({ link: { url: lab.githubUrl } });
    }
    
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
 * Motor de listagem do Mural.
 */
function listAnnouncements(courseId) {
  var response = Classroom.Courses.Announcements.list(courseId);
  var announcements = response.announcements || [];
  
  return announcements.map(function(aviso) {
    return {
      id: aviso.id,
      text: aviso.text,
      state: aviso.state,
      creationTime: aviso.creationTime,
      materials: aviso.materials || []
    };
  });
}

/**
 * Motor de criação de anúncios no Mural.
 */
function createAnnouncements(courseId, payloadData) {
  var results = [];
  var announcements = payloadData.announcements || [];
  
  announcements.forEach(function(aviso) {
    var announcement = {
      text: aviso.text,
      state: aviso.state || "PUBLISHED"
    };
    
    var result = Classroom.Courses.Announcements.create(announcement, courseId);
    results.push("Aviso publicado [" + result.state + "] ID: " + result.id);
  });
  
  return { status: 'success', created: results };
}

/**
 * Motor de listagem de alunos da turma.
 */
function listStudents(courseId) {
  var response = Classroom.Courses.Students.list(courseId);
  var students = response.students || [];
  
  return students.map(function(estudante) {
    return {
      id: estudante.userId,
      name: estudante.profile ? estudante.profile.name.fullName : 'Desconhecido',
      email: estudante.profile ? estudante.profile.emailAddress : 'Sem email'
    };
  });
}

/**
 * Motor de busca de detalhes da turma.
 */
function getCourseDetails(courseId) {
  var course = Classroom.Courses.get(courseId);
  return {
    id: course.id,
    name: course.name,
    section: course.section || '',
    description: course.descriptionHeading || course.description || '',
    enrollmentCode: course.enrollmentCode || 'Não disponível',
    status: course.courseState,
    url: course.alternateLink
  };
}

/**
 * Utilitário padrão para envelopamento de respostas HTTP em JSON.
 */
function buildJsonResponse(objeto) {
  return ContentService.createTextOutput(JSON.stringify(objeto))
    .setMimeType(ContentService.MimeType.JSON);
}
