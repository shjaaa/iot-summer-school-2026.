# Q14 - Traffic Light Controller

## Objective

Develop an Arduino-based Traffic Light Controller using three LEDs (Red, Yellow, and Green) and a pedestrian push button.

The traffic light follows the normal sequence:

- **Red ON** for **5 seconds**
- **Yellow ON** for **2 seconds**
- **Green ON** for **4 seconds**

When the pedestrian button (Pin 7) is pressed:

- Immediately switch to **Red**
- Hold the Red light for **8 seconds**
- Resume the normal traffic cycle

The program also prints the current traffic light state along with the system timestamp (`millis()`) to the Serial Monitor.

---

## Components Required

- Arduino Uno
- Red LED
- Yellow LED
- Green LED
- 3 × 220Ω Resistors
- Push Button
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Red LED | D2 |
| Yellow LED | D3 |
| Green LED | D4 |
| Pedestrian Button | D7 |

---

## Circuit Connections

### LEDs

Each LED is connected as follows:

```
Arduino Pin → 220Ω Resistor → LED Anode (+)
LED Cathode (-) → GND
```

### Push Button

```
One terminal → D7
Other terminal → GND
```

Configure the button using:

```cpp
pinMode(7, INPUT_PULLUP);
```

---

## Working

### Normal Traffic Cycle

| Light | Duration |
|--------|----------|
| 🔴 Red | 5 seconds |
| 🟡 Yellow | 2 seconds |
| 🟢 Green | 4 seconds |

The sequence continuously repeats.

---

### Pedestrian Mode

Whenever the pedestrian button is pressed:

1. Current light is interrupted.
2. Red LED turns ON immediately.
3. Red remains ON for **8 seconds**.
4. The normal traffic cycle resumes.

---

## Serial Monitor Output

Every state change is printed with the current timestamp.

Example:

```
[0 ms] RED

[5000 ms] YELLOW

[7000 ms] GREEN

[11000 ms] RED

Pedestrian Button Pressed

[15325 ms] RED (Pedestrian Crossing)

Resuming Normal Traffic...
```

---

## Algorithm

1. Initialize Serial communication.
2. Configure LED pins as OUTPUT.
3. Configure button pin as `INPUT_PULLUP`.
4. Start with Red light.
5. Wait according to the required duration.
6. Before changing states, continuously monitor the pedestrian button.
7. If the button is pressed:
   - Turn ON Red immediately.
   - Hold Red for 8 seconds.
   - Print event to Serial Monitor.
8. Continue the normal sequence.
9. Repeat forever.

---

## Features

- Automatic traffic light sequence
- Pedestrian priority mode
- Immediate emergency Red light
- 8-second pedestrian crossing
- Serial Monitor logging
- Timestamp using `millis()`
- Simple finite-state traffic controller

---

## Expected Output

| Event | Output |
|--------|--------|
| Startup | RED |
| After 5 sec | YELLOW |
| After 2 sec | GREEN |
| After 4 sec | RED |
| Button Press | RED immediately |
| Pedestrian Crossing | Hold RED for 8 sec |
| Resume | Continue normal sequence |

---

## Folder Structure

```
week2/
└── traffic_light/
    ├── traffic_light.ino
    └── README.md
```

The Arduino source file should be saved as:

```
/week2/traffic_light/traffic_light.ino
```

---

## Platform

- Arduino Uno
- Arduino IDE
- Tinkercad Simulator

---

## Author

**Name:** ___Shobbhit Singh__________________
link:-https://www.tinkercad.com/things/gqKU4BJvcNP-vending-machine-state-machine/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=OFhezO77IqSNvJao8d96OT270WjrhbBKn7q3VHYOPVk

**Course:** Internet of Things (IoT)
