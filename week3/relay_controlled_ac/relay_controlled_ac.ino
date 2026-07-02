#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RELAY_LED 13
#define BUTTON_PIN 3

DHT dht(DHTPIN, DHTTYPE);

bool relayState = false;
bool manualMode = false;
bool lastButton = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  dht.begin();

  Serial.println("Relay Controlled AC Simulation Started");
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read DHT sensor!");
    delay(2000);
    return;
  }

  bool button = digitalRead(BUTTON_PIN);

  // Manual override button
  if (button == LOW && lastButton == HIGH) {
    manualMode = !manualMode;
    relayState = !relayState;

    Serial.print("MANUAL OVERRIDE -> Relay ");
    Serial.println(relayState ? "ON" : "OFF");

    delay(200); // debounce
  }
  lastButton = button;

  // Automatic mode with hysteresis
  if (!manualMode) {
    if (temp > 32 && !relayState) {
      relayState = true;
      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.println(" C -> Relay ON");
    }
    else if (temp < 28 && relayState) {
      relayState = false;
      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.println(" C -> Relay OFF");
    }
  }

  digitalWrite(RELAY_LED, relayState);

  Serial.print("Current Temp: ");
  Serial.print(temp);
  Serial.print(" C | Relay: ");
  Serial.print(relayState ? "ON" : "OFF");
  Serial.print(" | Mode: ");
  Serial.println(manualMode ? "MANUAL" : "AUTO");

  delay(2000);
}
