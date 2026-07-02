#define ENA 9
#define IN1 8
#define IN2 7

#define POT_PIN A0
#define DIR_BTN 2
#define START_BTN 3

bool direction = true;      // true = Forward
bool motorRunning = true;

bool lastDirState = HIGH;
bool lastStartState = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(DIR_BTN, INPUT_PULLUP);
  pinMode(START_BTN, INPUT_PULLUP);

  Serial.println("DC Motor Controller Started");
}

void loop() {

  // Read potentiometer
  int potValue = analogRead(POT_PIN);

  int pwmValue = map(potValue, 0, 1023, 0, 255);
  int speedPercent = map(pwmValue, 0, 255, 0, 100);

  // Direction button
  bool dirState = digitalRead(DIR_BTN);

  if (dirState == LOW && lastDirState == HIGH) {
    direction = !direction;
    delay(200);   // debounce
  }
  lastDirState = dirState;

  // Start/Stop button
  bool startState = digitalRead(START_BTN);

  if (startState == LOW && lastStartState == HIGH) {
    motorRunning = !motorRunning;
    delay(200);   // debounce
  }
  lastStartState = startState;

  // Motor control
  if (motorRunning) {

    analogWrite(ENA, pwmValue);

    if (direction) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
  }
  else {
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  // Serial Monitor
  Serial.print("Direction: ");
  if (direction)
    Serial.print("Forward");
  else
    Serial.print("Reverse");

  Serial.print(" | Speed: ");
  Serial.print(speedPercent);
  Serial.print("%");

  Serial.print(" | State: ");
  if (motorRunning)
    Serial.println("Running");
  else
    Serial.println("Stopped");

  delay(300);
}
