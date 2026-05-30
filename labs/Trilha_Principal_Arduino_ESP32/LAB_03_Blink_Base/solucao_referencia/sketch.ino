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

// Unidade básica de tempo do Código Morse (em milissegundos)
const int tempoPonto = 200;      // T = 200ms

// Tempos proporcionais calculados a partir da unidade básica
const int tempoTraco = tempoPonto * 3;          // 3T = 600ms
const int tempoEspacoPartes = tempoPonto;       // T  = 200ms (entre pontos/traços da mesma letra)
const int tempoEspacoLetras = tempoPonto * 3;   // 3T = 600ms (entre as letras S e O)
const int tempoEspacoPalavras = tempoPonto * 7; // 7T = 1400ms (entre repetições do SOS)

// Chaveador para testar a solução:
// false = Lógica Hardcoded (Valores manuais repetidos)
// true  = Lógica Parametrizada (Usa as constantes calculadas acima)
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
    // -------------------------------------------------------------
    // ETAPA 2: SOLUÇÃO PARAMETRIZADA (RECOMENDADA)
    // -------------------------------------------------------------
    
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
    
    // Espaço longo antes de iniciar a próxima transmissão do SOS completo
    delay(tempoEspacoPalavras);
    Serial.println("[LOG] SOS Parametrizado enviado!");
    
  } else {
    // -------------------------------------------------------------
    // ETAPA 1: SOLUÇÃO HARDCODED (VALORES RÍGIDOS)
    // -------------------------------------------------------------
    
    // Letra S (· · ·)
    digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW);
    
    delay(600); // Espaço entre S e O
    
    // Letra O (- - -)
    digitalWrite(13, HIGH); delay(600); digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(600); digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(600); digitalWrite(13, LOW);
    
    delay(600); // Espaço entre O e S
    
    // Letra S (· · ·)
    digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW); delay(200);
    digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW);
    
    delay(1400); // Espaço entre repetições do SOS
    Serial.println("[LOG] SOS Hardcoded enviado!");
  }
}

// Funções que tornam o loop infinitamente mais limpo e legível!
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
