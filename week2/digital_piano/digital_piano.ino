/*
Author: Shobhit Singh
Date: 30-06-2026
Description: Digital Piano using passive buzzer
*/
// Play Sol when two or more keys are pressed

const int buzzer = 8;

const int doBtn = 2;
const int reBtn = 3;
const int miBtn = 4;
const int faBtn = 5;
const int modeBtn = 6;

bool minorMode = false;
bool lastModeState = HIGH;

void setup() {
  pinMode(doBtn, INPUT_PULLUP);
  pinMode(reBtn, INPUT_PULLUP);
  pinMode(miBtn, INPUT_PULLUP);
  pinMode(faBtn, INPUT_PULLUP);
  pinMode(modeBtn, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Digital Piano Started");
}

void loop() {

  // Mode button
  bool currentMode = digitalRead(modeBtn);

  if (currentMode == LOW && lastModeState == HIGH) {
    minorMode = !minorMode;

    if (minorMode)
      Serial.println("Minor Mode");
    else
      Serial.println("Major Mode");

    delay(300);
  }

  lastModeState = currentMode;

  // Read note buttons
  bool doPressed = digitalRead(doBtn) == LOW;
  bool rePressed = digitalRead(reBtn) == LOW;
  bool miPressed = digitalRead(miBtn) == LOW;
  bool faPressed = digitalRead(faBtn) == LOW;

  int count =
      doPressed + rePressed +
      miPressed + faPressed;

  // Two or more buttons together
  if (count >= 2) {
    tone(buzzer, 392);
    Serial.println("Sol (392 Hz)");
  }
  else if (doPressed) {
    tone(buzzer, minorMode ? 262 : 262);
    Serial.println("Do (262 Hz)");
  }
  else if (rePressed) {
    tone(buzzer, minorMode ? 277 : 294);
    Serial.println(minorMode ?
                   "Re Minor (277 Hz)" :
                   "Re (294 Hz)");
  }
  else if (miPressed) {
    tone(buzzer, minorMode ? 311 : 330);
    Serial.println(minorMode ?
                   "Mi Minor (311 Hz)" :
                   "Mi (330 Hz)");
  }
  else if (faPressed) {
    tone(buzzer, minorMode ? 330 : 349);
    Serial.println(minorMode ?
                   "Fa Minor (330 Hz)" :
                   "Fa (349 Hz)");
  }
  else {
    noTone(buzzer);
  }

  delay(50);
}
