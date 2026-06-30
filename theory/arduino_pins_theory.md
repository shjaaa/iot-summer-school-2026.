| Pin Type           | Explanation                                                                                   | Example Pin(s)           | Real IoT Use Case                                                                 |
| ------------------ | --------------------------------------------------------------------------------------------- | ------------------------ | --------------------------------------------------------------------------------- |
| **Digital Input**  | Reads only two states: HIGH (1) or LOW (0). Used to detect button presses or sensor states.   | D2–D13                   | Reading a **motion sensor (PIR)** in a smart security system.                     |
| **Digital Output** | Sends HIGH or LOW signals to control external devices.                                        | D2–D13                   | Turning an **LED or relay ON/OFF** in a smart home.                               |
| **Analog Input**   | Reads varying voltage levels (0–5 V) and converts them into digital values (0–1023).          | A0–A5                    | Reading a **temperature or light sensor** in a weather monitoring system.         |
| **PWM Output**     | Generates a pulse-width-modulated signal to simulate analog output.                           | D3, D5, D6, D9, D10, D11 | Controlling the **speed of a fan** or **brightness of an LED** in smart lighting. |
| **I2C Pins**       | Two-wire communication protocol using SDA and SCL lines to communicate with multiple devices. | A4 (SDA), A5 (SCL)       | Connecting an **OLED display or temperature sensor** in an IoT dashboard.         |
| **SPI Pins**       | High-speed serial communication protocol using MOSI, MISO, SCK, and SS pins.                  | D10, D11, D12, D13       | Communicating with an **SD card module** for data logging in an IoT system.       |

Examples
Digital Input: Push button controlling a smart doorbell.
Digital Output: Relay controlling a home appliance.
Analog Input: Soil moisture sensor in smart agriculture.
PWM Output: LED brightness control in smart street lighting.
I2C: OLED display showing sensor readings.
SPI: Data logging to an SD card in an environmental monitoring station.
