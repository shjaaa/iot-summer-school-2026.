# Smart Street Light (LDR + PIR)

## Components Used
- Arduino Uno
- LDR Sensor Module
- PIR Motion Sensor
- LED
- 220Ω Resistor

## Working
1. During daylight, the street light remains OFF.
2. During darkness, motion detection is enabled.
3. When motion is detected, the LED turns ON at full brightness for 30 seconds.
4. If no motion is detected for 30 seconds, the LED dims to 20% brightness.
5. All events are logged on the Serial Monitor in the format:
   [HH:MM:SS] EVENT: description

## Simulation
Built and tested in Wokwi.
