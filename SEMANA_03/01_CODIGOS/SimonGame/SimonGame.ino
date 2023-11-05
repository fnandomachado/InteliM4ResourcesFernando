//Entradas dos botões
#define botaoAmarelo 19
#define botaoAzul 18
#define botaoVerde 23
#define botaoVermelho 16

//Entradas dos LED's
#define LedAmarelo 26
#define LedAzul 25
#define LedVerde 32
#define LedVermelho 33

//Botão de Reset/Início
#define reset 22

//Delays pré-definidos
int delayFase = 250;
int delayInicio = 800;

int fase = 1; 
int sit = 0; 

void setup() {
  //Definições iniciais do projeto
  Serial.begin(9600);

  // LED's como OUTPUTS
  pinMode(LedAzul, OUTPUT); 
  pinMode(LedVerde, OUTPUT);
  pinMode(LedAmarelo, OUTPUT);
  pinMode(LedVermelho, OUTPUT);  

// Botões como INPUTS
  pinMode(reset, INPUT_PULLUP);
  pinMode(botaoAzul, INPUT_PULLUP);
  pinMode(botaoVerde, INPUT_PULLUP);
  pinMode(botaoAmarelo, INPUT_PULLUP);
  pinMode(botaoVermelho, INPUT_PULLUP);

  // Desliga todos os LED's
  digitalWrite(LedAzul, LOW); 
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedVermelho, LOW);
}

void loop() {
  // inicia o primeiro nível se o botão for pressionado e a fase for 1
  // acende e apaga o led vermelho
  if (digitalRead(reset) == LOW && fase == 1) {
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    delay(delayFase);
    sit = 1;
    Serial.println(sit);
  }


  // IF para checar se o botão pressionado foi o correto de acordo com a fase
  if (digitalRead(botaoAzul) == LOW && fase == 1 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 2;
  }

  // Caso algum botão foi apertado errado, reiniciar desde a primeira fase
  if ((digitalRead(botaoVerde) == LOW || digitalRead(botaoAmarelo) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 1 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }


  // Assim, se inicia a segunda fase

  if(fase == 2 && sit == 0) {
    delay(1500);
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    delay(delayFase);
    digitalWrite(LedVerde, HIGH);
    delay(delayFase);
    digitalWrite(LedVerde, LOW);
    sit = 1;
  }

  // Checa se o botão foi pressionado corretamente

  if(digitalRead(botaoAzul) == LOW && fase == 2 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    sit = 2;
  }

    // Se o botão pressionado for o incorreto, reiniciar o jogo

  if ((digitalRead(botaoVerde) == LOW || digitalRead(botaoAmarelo) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 2 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }

  //Checa de o botão foi pressionado corretamente

  if(digitalRead(botaoVerde) == LOW && fase == 2 && sit == 2) {
    digitalWrite(LedVerde, HIGH);
    delay(delayFase);
    digitalWrite(LedVerde, LOW);
    sit = 0;
    fase = 3;
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
  }


    // Se o botão pressionado for o incorreto, reiniciar o jogo desde a primeira fase

  if ((digitalRead(botaoAzul) == LOW || digitalRead(botaoAmarelo) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 2 && sit == 2) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }

  // Aqui, se inicia a 3a fase
  if(fase == 3 && sit == 0) {
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    delay(delayFase);
    digitalWrite(LedVerde, HIGH);
    delay(delayFase);
    digitalWrite(LedVerde, LOW);
    delay(delayFase);
    digitalWrite(LedAmarelo, HIGH);
    delay(delayFase);
    digitalWrite(LedAmarelo, LOW);
    sit = 1;
  }
    // Checa se o botão foi pressionado como deveria

  if(digitalRead(botaoAzul) == LOW && fase == 3 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    sit = 2;
  }

  // Se o botão pressionado for o incorreto, reiniciar o jogo

    if ((digitalRead(botaoVerde) == LOW || digitalRead(botaoAmarelo) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 3 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }
  // Checa se o botão foi pressionado como deveria

  if(digitalRead(botaoVerde) == LOW && fase == 3 && sit == 2) {
    digitalWrite(LedVerde, HIGH);
    delay(delayFase);
    digitalWrite(LedVerde, LOW);
    sit = 3;
  }
    // Se o botão pressionado for o incorreto, reiniciar o jogo desde a primeira fase

    if ((digitalRead(botaoAzul) == LOW || digitalRead(botaoAmarelo) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 3 && sit == 2) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }

  // Checa se o botão foi pressionado como deveria

  if(digitalRead(botaoAmarelo) == LOW && fase == 3 && sit == 3) {
    digitalWrite(LedAmarelo, HIGH);
    delay(delayFase);
    digitalWrite(LedAmarelo, LOW);
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    fase = 4;
    sit = 4;
  }

    // Se o botão pressionado estiver errado, reiniciar o jogo desde a primeira fase

    if ((digitalRead(botaoAzul) == LOW || digitalRead(botaoVerde) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 3 && sit == 3) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }
 // fase 4

// IF para iniciar a fase 4
if (fase == 4 && sit == 4) {
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    delay(delayFase);
    digitalWrite(LedVerde, HIGH);
    delay(delayFase);
    digitalWrite(LedVerde, LOW);
    delay(delayFase);
    digitalWrite(LedAmarelo, HIGH);
    delay(delayFase);
    digitalWrite(LedAmarelo, LOW);
    delay(delayFase);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedVermelho, LOW);
  sit = 1;
}
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(botaoAzul) == LOW && fase == 4 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    sit = 2;
  }


  // Se o botão pressionado for o incorreto, reiniciar o jogo

    if ((digitalRead(botaoAmarelo) == LOW || digitalRead(botaoVerde) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 4 && sit == 1) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(botaoVerde) == LOW && fase == 4 && sit == 2) {
    digitalWrite(LedVerde, HIGH);
    delay(delayFase);
    digitalWrite(LedVerde, LOW);
    sit = 3;
    Serial.println(sit);
  }


  // Se o botão pressionado for o incorreto, reiniciar o jogo

    if ((digitalRead(botaoAmarelo) == LOW || digitalRead(botaoAzul) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 4 && sit == 2) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(botaoAmarelo) == LOW && fase == 4 && sit == 3) {
    digitalWrite(LedAmarelo, HIGH);
    delay(delayFase);
    digitalWrite(LedAmarelo, LOW);
    sit = 7;
  }


  // Se o botão pressionado for o incorreto, reiniciar o jogo

    if ((digitalRead(botaoVerde) == LOW || digitalRead(botaoAzul) == LOW || digitalRead(botaoVermelho) == LOW) && fase == 4 && sit == 3) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(botaoVermelho) == LOW && fase == 4 && sit == 7) {
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedVermelho, LOW);
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    delay(delayInicio);
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    Serial.println("Acabou");
    sit = 5;
  }


  // Se o botão pressionado for o incorreto, reiniciar o jogo

    if ((digitalRead(botaoVerde) == LOW || digitalRead(botaoAzul) == LOW || digitalRead(botaoAmarelo) == LOW) && fase == 4 && sit == 7) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedVermelho, HIGH);
    delay(delayFase);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedVermelho, LOW);
    sit = 0;
    fase = 1;
  }

// If para permitir o reinício do jogo a quaisquer momento
  if(digitalRead(reset) == LOW && fase !=1) {
    fase = 1;
    sit = 0;
  }

}