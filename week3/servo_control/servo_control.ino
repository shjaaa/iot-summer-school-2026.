#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int buttonPin = 2;
const int servoPin = 9;

int angle;

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);

  myServo.attach(servoPin);

  Serial.println("Servo Control Started");
}

void loop() {
  // Read potentiometer and move servo
  int potValue = analogRead(potPin);

  angle = map(potValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.println(" degrees");

  // If button is pressed, do one full sweep
  if (digitalRead(buttonPin) == HIGH) {

    Serial.println("Button Pressed - Sweeping");

    // 0 to 180
    for (int i = 0; i <= 180; i++) {
      myServo.write(i);
      delay(10);
    }

    // 180 to 0
    for (int i = 180; i >= 0; i--) {
      myServo.write(i);
      delay(10);
    }
  }

  delay(100);
}
