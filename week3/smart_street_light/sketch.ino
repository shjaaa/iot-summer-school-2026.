#define LDR_PIN A0
#define PIR_PIN 2
#define LED_PIN 9

const int LDR_THRESHOLD = 500;

bool nightMode = false;
bool motionDetected = false;
unsigned long lastMotionTime = 0;

void printEvent(String msg) {
  unsigned long seconds = millis() / 1000;

  int hh = (seconds / 3600) % 24;
  int mm = (seconds % 3600) / 60;
  int ss = seconds % 60;

  Serial.print("[");
  if (hh < 10) Serial.print("0");
  Serial.print(hh);
  Serial.print(":");
  if (mm < 10) Serial.print("0");
  Serial.print(mm);
  Serial.print(":");
  if (ss < 10) Serial.print("0");
  Serial.print(ss);
  Serial.print("] EVENT: ");
  Serial.println(msg);
}

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  printEvent("System Started");
}

void loop() {
  int lightValue = analogRead(LDR_PIN);

  // DAY MODE
  if (lightValue > LDR_THRESHOLD) {
    analogWrite(LED_PIN, 0);

    if (nightMode) {
      nightMode = false;
      motionDetected = false;
      printEvent("Daylight detected, street light OFF");
    }
  }

  // NIGHT MODE
  else {
    if (!nightMode) {
      nightMode = true;
      printEvent("Dark detected, motion detection enabled");
    }

    int motion = digitalRead(PIR_PIN);

    // Motion detected
    if (motion == HIGH) {
      analogWrite(LED_PIN, 255);

      if (!motionDetected) {
        printEvent("Motion detected, LED ON at full brightness");
      }

      motionDetected = true;
      lastMotionTime = millis();
    }

    // No motion for 30 seconds
    if (motionDetected && millis() - lastMotionTime >= 30000) {
      analogWrite(LED_PIN, 51);  // 20% brightness
      motionDetected = false;
      printEvent("No motion for 30 seconds, LED dimmed to 20%");
    }
  }
}
