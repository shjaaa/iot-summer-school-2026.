/*
STATE TRANSITION DIAGRAM

IDLE
   |
Insert Coin
   v
COIN_INSERTED ----Cancel----> IDLE
   |
Select Item
   v
ITEM_SELECTED ----Cancel----> IDLE
   |
Dispense
   v
DISPENSING
   |
Done
   v
IDLE
*/

const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

const int idleLED = 8;
const int coinLED = 9;
const int dispenseLED = 10;

enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void setup() {
  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(idleLED, OUTPUT);
  pinMode(coinLED, OUTPUT);
  pinMode(dispenseLED, OUTPUT);

  Serial.begin(9600);

  updateLEDs();
  Serial.println("Machine Started");
  Serial.println("State: IDLE");
}

void loop() {

  switch (currentState) {

    case IDLE:
      if (digitalRead(coinBtn) == LOW) {
        currentState = COIN_INSERTED;
        Serial.println("IDLE -> COIN_INSERTED");
        updateLEDs();
        delay(300);
      }
      break;

    case COIN_INSERTED:

      if (digitalRead(cancelBtn) == LOW) {
        currentState = IDLE;
        Serial.println("COIN_INSERTED -> IDLE");
        updateLEDs();
        delay(300);
      }

      else if (digitalRead(selectBtn) == LOW) {
        currentState = ITEM_SELECTED;
        Serial.println("COIN_INSERTED -> ITEM_SELECTED");
        updateLEDs();
        delay(300);
      }
      break;

    case ITEM_SELECTED:
      Serial.println("ITEM_SELECTED -> DISPENSING");
      currentState = DISPENSING;
      updateLEDs();
      delay(2000);
      break;

    case DISPENSING:
      Serial.println("DISPENSING -> IDLE");
      currentState = IDLE;
      updateLEDs();
      delay(1000);
      break;
  }
}

void updateLEDs() {

  digitalWrite(idleLED, LOW);
  digitalWrite(coinLED, LOW);
  digitalWrite(dispenseLED, LOW);

  switch (currentState) {

    case IDLE:
      digitalWrite(idleLED, HIGH);
      break;

    case COIN_INSERTED:
      digitalWrite(coinLED, HIGH);
      break;

    case ITEM_SELECTED:
      digitalWrite(coinLED, HIGH);
      break;

    case DISPENSING:
      digitalWrite(dispenseLED, HIGH);
      break;
  }
}
