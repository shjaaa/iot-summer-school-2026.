/*
Author: Shobhit Singh
Date: 30-06-2026
Description: Serial Command Interface
*/

const int ledPin = LED_BUILTIN;
int blinkCounter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Serial Command Interface Ready");
  Serial.println("Commands: LED_ON, LED_OFF, BLINK_X, STATUS, RESET");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    // LED ON
    if (cmd == "LED_ON") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    }

    // LED OFF
    else if (cmd == "LED_OFF") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    }

    // BLINK_X
    else if (cmd.startsWith("BLINK_")) {
      String numStr = cmd.substring(6);
      int x = numStr.toInt();

      if (x >= 1 && x <= 9) {
        Serial.print("Blinking ");
        Serial.print(x);
        Serial.println(" times");

        for (int i = 0; i < x; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          blinkCounter++;
        }
      }
      else {
        Serial.println("ERROR: Invalid blink count");
      }
    }

    // STATUS
    else if (cmd == "STATUS") {
      Serial.print("LED State: ");

      if (digitalRead(ledPin))
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Counter: ");
      Serial.println(blinkCounter);
    }

    // RESET
    else if (cmd == "RESET") {
      blinkCounter = 0;
      Serial.println("Blink counter reset");
    }

    // Unknown command
    else {
      Serial.println("ERROR: Unknown command");
    }
  }
}
