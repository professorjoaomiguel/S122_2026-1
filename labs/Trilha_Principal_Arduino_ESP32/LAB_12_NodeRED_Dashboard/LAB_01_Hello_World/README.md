# Experimento 01: Fundamentos do Node-RED e Fluxo de Dados

## 1. Visão Geral e M3F
- **Objetivo:** Compreender a anatomia de uma mensagem no Node-RED e a interface do editor.
- **Camada M3F:** Aplicação (Cloud)

## 2. Nível 1: Observação (Olá, SENAI!)
1. **Importação:**
   - No GitHub, abra o arquivo `fluxo_desafio.json`.
   - Clique no botão **Copy raw content**.
   - No seu Node-RED, vá em **Menu -> Import**, cole o JSON e clique em **Import**.
2. **Tarefa:** Observe que os nós `inject` e `debug` apareceram em uma nova aba, mas estão desconectados.
3. **Execução:** Conecte-os, clique em **Deploy** e acione o botão do `inject`.
4. **Reflexão:** Observe na aba Debug que a mensagem é um objeto. O que acontece se você mudar o nome do tópico no nó `inject`?

## 3. Nível 2: Modificação (Formatando a Saída)
1. **Tarefa:** Adicione um nó `change` entre o `inject` e o `debug`.
2. **Configuração:** Configure o nó `change` para alterar o `msg.payload` adicionando o texto " - IoT 2026".
3. **Validação:** Ao clicar no `inject`, o debug deve mostrar a frase completa modificada.

## 4. Nível 3: Expansão (Múltiplas Saídas)
1. **Tarefa:** Adicione um segundo nó `debug` e conecte-o à saída original do `inject`.
2. **Desafio:** Crie uma lógica onde um debug mostre a mensagem em maiúsculas e o outro em minúsculas (pode usar um segundo nó `change`).
3. **Conferência:** Se tiver dúvidas, consulte o arquivo `fluxo_solucao.json` para ver uma forma de implementar.
4. **Reflexão Técnica:** Como o Node-RED lida com uma única mensagem sendo enviada para dois caminhos diferentes?

## 5. Conexão com a Indústria (APL/RS) 🏭
*Este desafio faz parte da sua jornada de construção de uma solução real. Reflita:*

- Como esta tecnologia (sensor, protocolo ou dashboard) seria aplicada em um **Arranjo Produtivo Local (APL)** do Rio Grande do Sul?
- Qual "dor" industrial ou de processo você identificou que poderia ser resolvida com o que você aprendeu hoje?

## 6. Relatório e Checklist de Entrega (Google Classroom) 📤
Para validar sua atividade, você deve postar no Classroom:

1.  **O JSON do seu Fluxo:** Exportado do Node-RED (**Menu -> Export -> Download JSON**).
2.  **Prints Comprobatórios:** Screenshot da tela inteira mostrando seu fluxo e a aba Debug com a mensagem "Olá, SENAI! - IoT 2026".
3.  **Reflexão Técnica (Respostas):**
    - Qual a diferença entre o nó `inject` e o nó `debug` em termos de fluxo de dados (quem é input e quem é output)?
    - Descreva o que aconteceu com a mensagem ao passar pelo nó `change`.
    - Por que é importante usar o `Deploy` antes de testar?

---

## 7. Referências
- [Padrão de Entrega Classroom](../../guias_e_roteiros_tecnicos/PADRAO_DE_ENTREGA_CLASSROOM.md)
- [Guia_NodeRED_e_Dashboards.md](../../guias_e_roteiros_tecnicos/Guia_NodeRED_e_Dashboards.md)
- **Gabarito de Referência:** `fluxo_solucao.json`
