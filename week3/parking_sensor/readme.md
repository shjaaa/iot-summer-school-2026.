# Ultrasonic Parking Sensor

Features:
- Distance > 50 cm: SAFE message, no alert.
- Distance 20–50 cm: Yellow LED ON, buzzer beeps every 500 ms.
- Distance 10–20 cm: Red LED ON, buzzer beeps every 200 ms.
- Distance < 10 cm: All LEDs flash rapidly, buzzer continuous.
- Distance calculated using:
  distance = (duration * 0.034) / 2
- Uses millis() for non-blocking timing.
