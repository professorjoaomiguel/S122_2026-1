# Guia de Apoio ao Pitch Técnico - S122 IoT

## 1. Visão Geral (O Básico)
**Para que serve:** Orientar os alunos na construção de uma apresentação impactante que conecte a solução técnica desenvolvida (Estufa/IoT) com uma dor real de um **Arranjo Produtivo Local (APL)** do Rio Grande do Sul.
**Contexto M3F:** [ ] Percepção (Edge) | [ ] Transporte (Fog) | [X] Aplicação (Cloud/Negócio)

## 2. Estrutura do Pitch (O Roteiro)
Um bom pitch técnico de IoT deve seguir a jornada do dado até a geração de valor:

1.  **O Cenário (Onde estamos?):** Apresente a região do RS e o setor industrial (Ex: APL Calçadista no Vale do Sinos).
2.  **A Dor (Qual o problema?):** Identifique o gargalo (Ex: "Hoje, 15% das solas de sapato são perdidas por erro na temperatura de secagem").
3.  **A Solução IoT (Como resolvemos?):** Apresente sua arquitetura baseada na Estufa Inteligente adaptada.
4.  **A Jornada do Dado (A Técnica):** Explique como o dado sai do sensor (Edge) via MQTT (Fog) até o Dashboard (Cloud).
5.  **A Tomada de Decisão (O Valor):** Mostre o Dashboard e como o empresário usará isso para lucrar ou economizar.

## 3. Os 7 Pilares da Arquitetura (Obrigatório)
Sua apresentação deve deixar claro cada um destes pontos conforme o plano da disciplina:
- **Coisa:** O que está sendo monitorado?
- **Sensor:** Qual componente do Wokwi você usou (DHT22, LDR, etc)?
- **Conexão:** Wi-Fi (Wokwi-GUEST) + MQTT.
- **Energia:** Como o sensor seria alimentado no mundo real (Bateria, PoE, Rede Elétrica)?
- **Informação:** O que o dado processado diz? (Ex: "Está quente demais!").
- **Dashboard:** Mostre seu fluxo do Node-RED.
- **Usuário:** Quem aperta o botão ou olha o gráfico?

## 4. Dicas de Argumentação por Região (RS)
Para convencer o "investidor" ou "gestor", use ganchos regionais:
- **Serra (Vitivinicultura):** "Nossa solução evita a perda de safras por geadas imprevistas monitorando o microclima 24h por dia".
- **Metropolitana (Polímeros):** "Reduzimos o tempo de parada de máquina em 20% com alertas preditivos via MQTT".
- **Noroeste (Agro):** "Garantimos a qualidade do grão armazenado monitorando a umidade do silo em tempo real".

## 5. Integração com Laboratórios
Utilize os resultados dos seus laboratórios como prova de conceito:
- **LAB 05:** Print do Serial Monitor com dados reais.
- **LAB 11:** Foto do HiveMQ recebendo mensagens do Wokwi.
- **LAB 12:** Print do Gauge/Gráfico do Node-RED funcionando.

## 6. Referências e Materiais
- **Template de Slides:** Consulte na pasta `FacSENAI_S122_2026-1/06_MATERIAIS_REFERENCIA`.
- **Canvas IoT:** Use o modelo de Canvas disponível para estruturar sua ideia antes de criar os slides.

---
*Documento em constante atualização. Versão: 2026/1*
