# Q15 - Digital Piano using Buzzer

## Objective
Design a 4-key digital piano using an Arduino Uno, push buttons, and a passive buzzer. Each button plays a musical note. A fifth button toggles between Major and Minor scales. If two note buttons are pressed simultaneously, the buzzer plays **Sol (392 Hz)** as a chord substitute.

---

## Components Required

- Arduino Uno
- Passive Buzzer
- 5 Push Buttons
- 5 × 10kΩ Resistors (or use `INPUT_PULLUP`)
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Button 1 (Do) | D2 |
| Button 2 (Re) | D3 |
| Button 3 (Mi) | D4 |
| Button 4 (Fa) | D5 |
| Mode Button | D6 |
| Passive Buzzer | D8 |

---

## Features

### 1. Four Musical Notes

Each button plays one musical note.

| Button | Major Scale | Frequency |
|---------|-------------|-----------|
| 1 | Do | 262 Hz |
| 2 | Re | 294 Hz |
| 3 | Mi | 330 Hz |
| 4 | Fa | 349 Hz |

---

### 2. Button Release

When the pressed button is released, the buzzer immediately stops playing.

---

### 3. Chord Substitute

If two or more note buttons are pressed together, the buzzer plays:

**Sol (392 Hz)**

instead of multiple notes.

---

### 4. Major / Minor Mode

The fifth push button switches between:

- Major Scale
- Minor Scale

Example Minor Frequencies:

| Button | Minor Scale | Frequency |
|---------|-------------|-----------|
| 1 | Do | 262 Hz |
| 2 | Re | 294 Hz |
| 3 | Me♭ | 311 Hz |
| 4 | Fa | 349 Hz |

The current mode is displayed on the Serial Monitor.

---

## Circuit Diagram

- Connect one terminal of each push button to the Arduino input pin.
- Connect the other terminal to GND.
- Configure the input pins using `INPUT_PULLUP`.
- Connect the positive terminal of the passive buzzer to D8.
- Connect the negative terminal of the buzzer to GND.

---

## Algorithm

1. Initialize Serial communication.
2. Configure all button pins as `INPUT_PULLUP`.
3. Configure buzzer pin as OUTPUT.
4. Continuously read the state of all buttons.
5. If the mode button is pressed, toggle between Major and Minor scales.
6. Count how many note buttons are pressed.
7. If:
   - No button pressed → Stop the buzzer.
   - One button pressed → Play the corresponding note.
   - Two or more buttons pressed → Play Sol (392 Hz).
8. Repeat continuously.

---

## Sample Output

```
Mode : Major

Button 1 Pressed
Playing Do (262 Hz)

Button Released
Sound Stopped

Button 2 + Button 3 Pressed
Playing Sol (392 Hz)

Mode Changed
Minor Scale Enabled

Button 3 Pressed
Playing Me♭ (311 Hz)
```

---

## Working

- Press Button 1 → Do
- Press Button 2 → Re
- Press Button 3 → Mi (Major) / Me♭ (Minor)
- Press Button 4 → Fa
- Release button → Sound stops
- Press any two note buttons → Sol plays
- Press Mode button → Toggle between Major and Minor scales

---

## Git Commit History

Suggested commits:

```
Initial Arduino project setup
Added 4 piano note buttons
Implemented passive buzzer output
Added button release to stop sound
Implemented Sol chord substitute
Added Major/Minor scale toggle
Updated Serial Monitor messages
Final testing and documentation
```

---

## Expected Output

| Condition | Output |
|----------|--------|
| Button 1 | Do (262 Hz) |
| Button 2 | Re (294 Hz) |
| Button 3 (Major) | Mi (330 Hz) |
| Button 3 (Minor) | Me♭ (311 Hz) |
| Button 4 | Fa (349 Hz) |
| Button Released | No Sound |
| Two Buttons Pressed | Sol (392 Hz) |
| Mode Button | Toggle Major ↔ Minor |

---

## Platform

- Arduino Uno
- Arduino IDE
- Tinkercad Simulator

---

## Author

**Name:** Shobhit Singh
Link:-https://www.tinkercad.com/things/5TWjuk4fiCD-digital-piano-using-buzzer/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=r2szKQ7rV2bNBS3PNKAVgprvrUvQmkEXWDTPu3Zm-H4

**Course:** Internet of Things (IoT)
