/*
Author: Shobhit Singh
Date: 30-06-2026
Description: PWM Fading Night Light
*/

const int ledPin = 9;
const int buttonPin = 2;

int mode = 0;
bool lastButton = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void loop() {

  bool currentButton = digitalRead(buttonPin);

  if (lastButton == HIGH && currentButton == LOW) {
    mode++;
    if (mode > 2) mode = 0;

    if (mode == 0)
      Serial.println("Mode 1: Slow Breathing");
    else if (mode == 1)
      Serial.println("Mode 2: Fast Pulse");
    else
      Serial.println("Mode 3: SOS");

    delay(250);
  }

  lastButton = currentButton;

  if (mode == 0)
    slowBreathing();
  else if (mode == 1)
    fastPulse();
  else
    sosPattern();
}

void slowBreathing() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(6);
    if (digitalRead(buttonPin) == LOW) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(6);
    if (digitalRead(buttonPin) == LOW) return;
  }
}

void fastPulse() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(1);
    if (digitalRead(buttonPin) == LOW) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(1);
    if (digitalRead(buttonPin) == LOW) return;
  }
}

void sosPattern() {
  // ...

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    if (digitalRead(buttonPin) == LOW) return;
  }

  // ---

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(600);
    digitalWrite(ledPin, LOW);
    delay(200);
    if (digitalRead(buttonPin) == LOW) return;
  }

  // ...

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    if (digitalRead(buttonPin) == LOW) return;
  }

  delay(1000);
}
