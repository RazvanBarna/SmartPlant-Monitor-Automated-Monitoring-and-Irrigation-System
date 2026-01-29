---

## 🛠 Technical Details & Logic

### Control Logic
The system is designed with a focus on component longevity and resource management:
* [cite_start]**Threshold-Based Irrigation**: The pump starts automatically when soil moisture is below 30%[cite: 29].
* [cite_start]**Safety Interlock**: A software check prevents the pump from starting if the water level in the reservoir is insufficient[cite: 30, 64].
* [cite_start]**Absorption Delay**: After watering, the system enters a wait state to allow water absorption, preventing repeated/excessive cycles[cite: 31].
* [cite_start]**Sensor Protection**: To minimize corrosion of the resistive sensors, they are only powered during the measurement phase[cite: 22].

### Electrical Design
* [cite_start]**Voltage Isolation**: The 5V control circuit is isolated from the 220V power circuit via a relay[cite: 25].
* [cite_start]**Pump Power**: The submersible pump is externally powered, with the phase wire passing through the relay contacts[cite: 26].
* [cite_start]**Communication**: The LCD uses the I2C protocol to minimize the number of pins used on the Arduino Mega[cite: 27].

---

## 🎹 Hardware Wiring (Pinout)

| Component | Pin | Function |
| :--- | :--- | :--- |
| **Button 1** | Pin 22 | [cite_start]Air Temp & Humidity Display [cite: 33] |
| **Button 2** | Pin 23 | [cite_start]Water Reservoir Level Display [cite: 34] |
| **Button 3** | Pin 24 | [cite_start]Soil Moisture Display [cite: 35] |
| **Button 4** | Pin 25 | [cite_start]Forced Manual Irrigation [cite: 36] |
| **LCD 1602** | I2C Pins | [cite_start]Visual Feedback & Data Display [cite: 23, 27] |
| **Arduino Mega** | - | [cite_start]Main Controller [cite: 21] |

---

## 📸 Project Gallery

### Circuit Overview
![Overview]([link_spre_poza_ta_din_galerie])  
[cite_start]*General view of the completed project circuit[cite: 61].*

### Water Reservoir & Pump
![Reservoir]([link_spre_poza_ta_din_galerie])  
[cite_start]*Detail of the pump and the water level sensor installation[cite: 64].*

### LCD Feedback
![LCD Display]([link_spre_poza_ta_din_galerie])  
[cite_start]*Visual feedback showing "Soil Moisture" and "Water Level"[cite: 69].*

---

## 📚 References
* [cite_start]**Official Documentation**: Arduino Mega 2560[cite: 75].
* [cite_start]**Libraries**: LiquidCrystal I2C by John Rickman [cite: 76][cite_start], DHT by Adafruit[cite: 77, 78].
* **Academic Support**: PMP Course Materials by Conf. dr. ing. [cite_start]Itu Răzvan, UTCN[cite: 79].

---

## 🎓 Academic Info
* [cite_start]**Student**: Barna Răzvan [cite: 6]
* [cite_start]**Institution**: Technical University of Cluj-Napoca (UTCN) [cite: 1]
* [cite_start]**Faculty**: Automation and Computer Science [cite: 3]
* [cite_start]**Project**: PMP (Microprocessor Programming) [cite: 4]
* [cite_start]**Date**: December 2025 [cite: 7]