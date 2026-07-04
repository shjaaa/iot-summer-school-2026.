#define TRIG_PIN 9
#define ECHO_PIN 10

#define YELLOW_LED 3
#define RED_LED 4
#define GREEN_LED 5
#define BUZZER 6

unsigned long previousBeep = 0;
unsigned long previousFlash = 0;
bool buzzerState = false;
bool flashState = false;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo duration
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  float distance = (duration * 0.034) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  // Turn everything OFF first
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW);

  // SAFE ZONE (>50 cm)
  if (distance > 50) {
    Serial.println("SAFE");
  }

  // WARNING ZONE (20–50 cm)
  else if (distance > 20 && distance <= 50) {
    digitalWrite(YELLOW_LED, HIGH);

    if (currentMillis - previousBeep >= 500) {
      previousBeep = currentMillis;
      buzzerState = !buzzerState;
    }
    digitalWrite(BUZZER, buzzerState);
  }

  // DANGER ZONE (10–20 cm)
  else if (distance > 10 && distance <= 20) {
    digitalWrite(RED_LED, HIGH);

    if (currentMillis - previousBeep >= 200) {
      previousBeep = currentMillis;
      buzzerState = !buzzerState;
    }
    digitalWrite(BUZZER, buzzerState);
  }

  // VERY CLOSE (<10 cm)
  else {
    digitalWrite(BUZZER, HIGH);

    if (currentMillis - previousFlash >= 100) {
      previousFlash = currentMillis;
      flashState = !flashState;
    }

    digitalWrite(YELLOW_LED, flashState);
    digitalWrite(RED_LED, flashState);
    digitalWrite(GREEN_LED, flashState);
  }
}
