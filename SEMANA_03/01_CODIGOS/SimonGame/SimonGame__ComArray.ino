#include <Arduino.h>

// Define os pinos dos LEDs e botões
const int ledPins[] = {2, 4, 16, 17};  // Pinos dos LEDs
const int buttonPins[] = {18, 19, 21, 22};  // Pinos dos botões
const int resetButtonPin = 23;  // Pino do botão de reset

// Define os tempos de iluminação dos LEDs e pausas
const int ledOnTime = 1000;  // Tempo em milissegundos para os LEDs ficarem acesos
const int ledOffTime = 500;  // Tempo em milissegundos para os LEDs ficarem apagados
const int sequenceDelay = 1000; // Tempo em milissegundos entre cada passo da sequência

// Arrays para armazenar a sequência de cores
int sequence[4];
int playerSequence[4];
int level = 0;
bool gameStarted = false;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(resetButtonPin, INPUT_PULLUP);

  // Inicializa a semente para gerar sequências aleatórias
  randomSeed(analogRead(0));

  // Define uma função de tratamento para o botão de reset
  attachInterrupt(digitalPinToInterrupt(resetButtonPin), startGame, FALLING);
}

void loop() {
  if (gameStarted) {
    if (level == 0) {
      generateSequence();
    }

    playSequence();
    waitForPlayer();
    checkPlayerInput();
  }
}

void startGame() {
  level = 0;
  gameStarted = true;
  delay(500);  // Pequeno atraso para evitar acionamentos acidentais do botão
}

void generateSequence() {
  for (int i = 0; i < 4; i++) {
    sequence[i] = random(4);  // Gera uma cor aleatória (0-3)
  }
}

void playSequence() {
  for (int i = 0; i <= level; i++) {
    int color = sequence[i];

    digitalWrite(ledPins[color], HIGH);
    delay(ledOnTime);
    digitalWrite(ledPins[color], LOW);

    delay(ledOffTime);  // Pequena pausa entre as cores
  }

  delay(sequenceDelay);  // Pausa maior antes de esperar a entrada do jogador
}

void waitForPlayer() {
  for (int i = 0; i <= level; i++) {
    playerSequence[i] = -1; // Reinicializa a sequência do jogador
  }
}

void checkPlayerInput() {
  int playerInput = digitalRead(resetButtonPin);

  if (playerInput == LOW) {
    delay(500);  // Pequeno atraso para evitar acionamentos acidentais do botão
    return;
  }

  for (int i = 0; i <= level; i++) {
    while (playerInput == HIGH) {
      playerInput = digitalRead(resetButtonPin);
    }

    playerInput = digitalRead(resetButtonPin);

    if (playerInput == LOW) {
      int color = checkButtonPress();
      playerSequence[i] = color;

      digitalWrite(ledPins[color], HIGH);
      delay(ledOnTime);
      digitalWrite(ledPins[color], LOW);

      delay(ledOffTime);
    }
  }

  if (checkSequences()) {
    level++;
  } else {
    Serial.println("Você errou! Tente novamente.");
    gameStarted = false;
  }
}

int checkButtonPress() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      return i;
    }
  }
  return -1;
}

bool checkSequences() {
  for (int i = 0; i <= level; i++) {
    if (sequence[i] != playerSequence[i]) {
      return false;
    }
  }
  return true;
}
