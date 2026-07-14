# Q16 - Serial Command Interface (Arduino)

## Objective
Create an Arduino program that receives commands through the Serial Monitor and controls the built-in LED.

## Components Required
- Arduino Uno
- USB Cable
- Arduino IDE / Wokwi Simulator

## Commands

| Command | Function |
|----------|----------|
| LED_ON | Turn the built-in LED ON |
| LED_OFF | Turn the built-in LED OFF |
| BLINK_X | Blink the LED X times (X = 1–9) |
| STATUS | Display LED state and blink counter |
| RESET | Reset the blink counter |
| Any other command | Print `ERROR: Unknown command` |

## Circuit
No external components are required.

Uses the Arduino Uno built-in LED connected to **Pin 13**.

## Working

### LED_ON
Turns ON the built-in LED.

Example:
```
LED_ON
```

Output:
```
LED is ON
```

---

### LED_OFF

Turns OFF the built-in LED.

Example:
```
LED_OFF
```

Output:
```
LED is OFF
```

---

### BLINK_X

Blinks the LED X times.

Examples:

```
BLINK_3
```

```
BLINK_7
```

Output:
```
Blinking 3 times...
Done.
```

---

### STATUS

Displays current LED state and total blink count.

Example:
```
STATUS
```

Output:
```
LED State : ON
Blink Count : 5
```

---

### RESET

Resets the blink counter.

Example:
```
RESET
```

Output:
```
Blink counter reset.
```

---

### Invalid Command

Example:
```
HELLO
```

Output:
```
ERROR: Unknown command
```

---

## Algorithm

1. Initialize Serial communication.
2. Configure built-in LED as OUTPUT.
3. Wait for user input from Serial Monitor.
4. Read the complete command.
5. Compare the command with valid commands.
6. Execute the corresponding action.
7. Print status or error message.
8. Repeat continuously.

---

## Sample Output

```
Enter Command:

LED_ON
LED is ON

STATUS
LED State : ON
Blink Count : 0

BLINK_5
Blinking 5 times...
Done.

STATUS
LED State : ON
Blink Count : 5

RESET
Blink counter reset.

STATUS
LED State : ON
Blink Count : 0

HELLO
ERROR: Unknown command
```

---

## Features

- Serial command interface
- Built-in LED control
- Blink LED 1–9 times
- Displays LED status
- Blink counter
- Reset functionality
- Input validation
- Error handling for invalid commands

## Platform

- Arduino Uno
- Arduino IDE
- Wokwi Simulator

## Author

Name: Shobhit

Course: Internet of Things (IoT)
