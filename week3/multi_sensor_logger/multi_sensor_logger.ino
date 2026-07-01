#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define LDR_PIN A0
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {

  // DHT11
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // LDR
  int ldrRaw = analogRead(LDR_PIN);
  int lightPercent = map(ldrRaw, 0, 1023, 0, 100);

  String lightStatus;
  if (lightPercent > 70)
    lightStatus = "Bright";
  else if (lightPercent > 30)
    lightStatus = "Moderate";
  else
    lightStatus = "Dark";

  // HC-SR04
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  // Output
  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print(" C | Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  Serial.print("Light : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(lightStatus);
  Serial.println(")");

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("==================");
  Serial.println();

  delay(5000);
}
