#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);

#define GREEN_LED 10
#define RED_LED 11
#define BUZZER 12

String correctPin = "1408";
String enteredPin = "";

int wrongAttempts = 0;
bool locked = false;
unsigned long lockStart = 0;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("ENTER PIN:");

  Serial.println("Password Protected Access System");
  Serial.println("Enter PIN:");
}

void loop() {

  // Lock mode
  if (locked) {
    lcd.setCursor(0, 1);
    lcd.print("Wait ");
    lcd.print(10 - (millis() - lockStart) / 1000);
    lcd.print(" sec ");

    if (millis() - lockStart >= 10000) {
      locked = false;
      wrongAttempts = 0;

      lcd.clear();
      lcd.print("ENTER PIN:");

      Serial.println("System Unlocked");
    }
    return;
  }

  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {

      enteredPin += key;

      lcd.setCursor(0, 1);

      for (int i = 0; i < enteredPin.length(); i++) {
        lcd.print("*");
      }

      Serial.print("*");
    }

    if (enteredPin.length() == 4) {

      Serial.println();

      if (enteredPin == correctPin) {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0, 1);
        lcd.print("GRANTED");

        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);

        tone(BUZZER, 1000, 300);

        Serial.println("ACCESS GRANTED");

        delay(10000);

        digitalWrite(GREEN_LED, LOW);

        wrongAttempts = 0;
      }
      else {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0, 1);
        lcd.print("DENIED");

        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);

        tone(BUZZER, 500, 1000);

        Serial.println("ACCESS DENIED");

        delay(10000);

        digitalWrite(RED_LED, LOW);

        wrongAttempts++;

        if (wrongAttempts >= 3) {
          locked = true;
          lockStart = millis();

          lcd.clear();
          lcd.print("SYSTEM LOCKED");

          Serial.println("SYSTEM LOCKED FOR 10 SECONDS");
        }
      }

      enteredPin = "";

      if (!locked) {
        lcd.clear();
        lcd.print("ENTER PIN:");
      }
    }
  }
}
