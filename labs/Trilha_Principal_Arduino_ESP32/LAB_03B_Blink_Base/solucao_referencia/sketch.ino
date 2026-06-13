/**
 * LAB 03: O Primeiro Sinal (SOS Morse - SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Este arquivo contém o gabarito detalhado do Desafio SOS em Código Morse.
 * O código demonstra a diferença entre a lógica "Hardcoded" e a "Parametrizada".
 */

// ==========================================
// CONFIGURAÇÃO DOS PARÂMETROS DE TEMPO (Morse)
// ==========================================
const int pinoLED = 13;          // LED "L" embutido na placa Arduino Uno

// Unidade basica de tempo (milissegundos)
const int tempoPonto = 200;      // T = 200ms

// Tempos calculados a partir da unidade
const int tempoTraco = tempoPonto * 3;
// Espaco na mesma letra
const int tempoEspacoPartes = tempoPonto;
// Espaco entre as letras
const int tempoEspacoLetras = tempoPonto * 3;
// Espaco entre as palavras (repeticoes)
const int tempoEspacoPalavras = tempoPonto * 7;

// Chaveador para testar a solucao:
// false = Logica Hardcoded (Valores manuais)
// true  = Logica Parametrizada (Usa constantes)
const bool usarLogicaParametrizada = true;

void setup() {
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
  Serial.println("\n=== [S122] LAB 03 - SOS INICIADO ===");
}

// Protótipos das funções auxiliares para manter o código limpo
void emitirPonto();
void emitirTraco();

void loop() {
  if (usarLogicaParametrizada) {
    // ----------------------------------------------------
    // ETAPA 2: SOLUCAO PARAMETRIZADA (RECOMENDADA)
    // ----------------------------------------------------
    
    // --- Letra S (· · ·) ---
    emitirPonto();
    delay(tempoEspacoPartes);
    emitirPonto();
    delay(tempoEspacoPartes);
    emitirPonto();
    
    delay(tempoEspacoLetras); // Espaço entre S e O
    
    // --- Letra O (- - -) ---
    emitirTraco();
    delay(tempoEspacoPartes);
    emitirTraco();
    delay(tempoEspacoPartes);
    emitirTraco();
    
    delay(tempoEspacoLetras); // Espaço entre O e S
    
    // --- Letra S (· · ·) ---
    emitirPonto();
    delay(tempoEspacoPartes);
    emitirPonto();
    delay(tempoEspacoPartes);
    emitirPonto();
    
    // Espaco antes de reiniciar a transmissao
    delay(tempoEspacoPalavras);
    Serial.println("[LOG] SOS Parametrizado!");
    
  } else {
    // ----------------------------------------------------
    // ETAPA 1: SOLUCAO HARDCODED (VALORES RIGIDOS)
    // ----------------------------------------------------
    
    // Letra S (. . .)
    digitalWrite(13, HIGH); delay(200); 
    digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); 
    digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); 
    digitalWrite(13, LOW);
    
    delay(600); // Espaco entre S e O
    
    // Letra O (- - -)
    digitalWrite(13, HIGH); delay(600); 
    digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(600); 
    digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(600); 
    digitalWrite(13, LOW);
    
    delay(600); // Espaco entre O e S
    
    // Letra S (. . .)
    digitalWrite(13, HIGH); delay(200); 
    digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); 
    digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); 
    digitalWrite(13, LOW);
    
    delay(1400); // Espaco repeticoes SOS
    Serial.println("[LOG] SOS Hardcoded!");
  }
}

// Funcoes para deixar o loop legivel
void emitirPonto() {
  digitalWrite(pinoLED, HIGH);
  delay(tempoPonto);
  digitalWrite(pinoLED, LOW);
}

void emitirTraco() {
  digitalWrite(pinoLED, HIGH);
  delay(tempoTraco);
  digitalWrite(pinoLED, LOW);
}
