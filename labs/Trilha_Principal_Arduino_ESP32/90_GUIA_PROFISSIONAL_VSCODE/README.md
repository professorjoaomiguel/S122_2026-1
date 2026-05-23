# 🚀 Guia Profissional: Workflow VS Code + Wokwi + Git

Este guia é a sua **Bifurcação de Carreira**. Enquanto a interface Web do Wokwi é excelente para prototipagem rápida, o mercado de trabalho utiliza Ambientes de Desenvolvimento Integrados (IDEs) e Controle de Versão (Git).

---

## 🛣️ Por que sair do Navegador?
Ao migrar para o VS Code, você habilita:
1.  **Versionamento Profissional:** Salvar cada mudança no seu GitHub.
2.  **IntelliSense:** O editor te avisa erros de código antes mesmo de você rodar.
3.  **Gestão de Bibliotecas:** Controle total sobre quais versões de código externo você usa.
4.  **Multi-arquivos:** Organizar seu projeto em vários arquivos `.h` e `.cpp`.

---

## 🛠️ Passo 1: O Setup (Caminho de Entrada)
1.  **Instale o VS Code:** [code.visualstudio.com](https://code.visualstudio.com/)
2.  **Extensão Wokwi:** Procure por "Wokwi Simulator" no Marketplace do VS Code e instale.
3.  **Licenciamento:** No VS Code, pressione `F1`, digite `Wokwi: Request License` e siga o link para ativar (gratuito para uso educacional).

---

## 📁 Passo 2: Estrutura do Projeto Local
Diferente do site, no seu PC o projeto precisa de 3 arquivos básicos na mesma pasta:
- `sketch.ino`: Seu código.
- `diagram.json`: O hardware (copiado do site).
- `wokwi.toml`: O arquivo de "cola" que avisa o VS Code como rodar o simulador.

### Exemplo de `wokwi.toml`:
```toml
[wokwi]
version = 1
firmware = "sketch.ino"
elf = ".wokwi/build/sketch.elf"
```

---

## 🔄 Passo 3: O Fluxo de Trabalho (Daily Dev)
1.  Escreva o código no VS Code.
2.  Pressione `F1` e escolha `Wokwi: Start Simulator`.
3.  O simulador abrirá em uma aba lateral, processando o código direto do seu disco.
4.  **Git Bonus:** Use `git add .` e `git commit -m "feat: adiciona sensor dht22"` para versionar.

---

## 🔗 Pontos de Conexão
Você pode cair neste guia a qualquer momento durante os laboratórios:
- **No LAB 03:** Para aprender a "codar" profissionalmente.
- **No LAB 11:** Para integrar com o Git antes de subir para a nuvem.

---
*Faculdade de Tecnologia SENAI Porto Alegre - Prof. João Miguel*
