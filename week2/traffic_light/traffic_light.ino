const int RED = 10;
const int YELLOW = 9;
const int GREEN = 8;
const int BUTTON = 7;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT);

  Serial.begin(9600);
}

void loop() {

  // Pedestrian button pressed
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    Serial.print(millis());
    Serial.println(" ms : Pedestrian Crossing - RED");

    delay(8000);
    return;
  }

  // RED for 5 seconds
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : RED");

  delay(5000);

  // Check button again
  if (digitalRead(BUTTON) == HIGH) return;

  // YELLOW for 2 seconds
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : YELLOW");

  delay(2000);

  if (digitalRead(BUTTON) == HIGH) return;

  // GREEN for 4 seconds
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);

  Serial.print(millis());
  Serial.println(" ms : GREEN");

  delay(4000);
}
