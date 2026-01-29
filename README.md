# SmartPlant-Monitor: Automated Monitoring and Irrigation System

## 📝 Project Overview
[cite_start]**SmartPlant-Monitor** is an automated system designed to monitor environmental conditions for plants and manage irrigation efficiently[cite: 5, 14]. [cite_start]Built with an **Arduino Mega 2560**, the project ensures plants receive water based on soil moisture levels while protecting the hardware from common failures like "dry-running" the pump[cite: 17, 18, 21].

[cite_start]This project was developed at the **Technical University of Cluj-Napoca**, Faculty of Automation and Computer Science[cite: 2, 3].

---

## 🚀 Key Features
* [cite_start]**Automated Irrigation**: The pump triggers automatically when soil moisture drops below **30%**[cite: 29].
* [cite_start]**Dry-Run Protection**: A software safety interlock prevents the pump from starting if the water reservoir is empty[cite: 30].
* [cite_start]**Sensor Longevity**: Resistive sensors are only powered during readings to minimize corrosion[cite: 22].
* [cite_start]**Safety Isolation**: The 5V control circuit is isolated from the 220V power circuit via a relay[cite: 25].
* [cite_start]**Absorption Delay**: Includes a wait-time after watering to allow the soil to absorb moisture, preventing over-watering[cite: 31].

---

## 🛠 Hardware Specifications


### Components
* [cite_start]**Microcontroller**: Arduino Mega 2560 [cite: 21]
* [cite_start]**Sensors**: Soil moisture, water level, and DHT (Air Temp/Humidity) [cite: 21]
* [cite_start]**Actuators**: Submersible pump and Relay [cite: 21, 25]
* [cite_start]**Interface**: 1602 LCD with I2C module and 4 physical buttons [cite: 23, 27]

### Pin Configuration
| Component | Pin | Function |
| :--- | :--- | :--- |
| **Button 1** | Pin 22 | [cite_start]Display Air Temp & Humidity [cite: 33] |
| **Button 2** | Pin 23 | [cite_start]Display Water Reservoir Level [cite: 34] |
| **Button 3** | Pin 24 | [cite_start]Display Soil Moisture [cite: 35] |
| **Button 4** | Pin 25 | [cite_start]Trigger Forced Manual Irrigation [cite: 36] |

---

## 🔮 Future Enhancements
* [cite_start]**IoT Connectivity**: Integration of ESP8266/ESP32 for cloud monitoring (Blynk/Home Assistant)[cite: 42, 44].
* [cite_start]**Data Logging**: Adding a MicroSD card module for historical data analysis[cite: 47].
* [cite_start]**Solar Autonomy**: Implementation of photovoltaic panels for outdoor use[cite: 51].
* [cite_start]**Smart Scheduling**: Using a Real-Time Clock (RTC) to water only at night or early morning[cite: 54].

---

## 📸 Gallery
* [cite_start]**System Overview**: General view of the circuit and plant[cite: 61, 73].
* [cite_start]**Reservoir System**: Detail of the pump and level sensor setup[cite: 64].
* [cite_start]**LCD Interface**: Visual feedback for moisture and water levels[cite: 69].

---

## 📚 References
* [cite_start]**Official Arduino Mega 2560 Documentation** [cite: 75]
* [cite_start]**LiquidCrystal I2C Library** (John Rickman) [cite: 76]
* [cite_start]**DHT Library** (Adafruit) [cite: 77, 78]
* **PMP Course Support**: Conf. dr. ing. [cite_start]Itu Răzvan [cite: 79]

---
[cite_start]**Author:** Barna Răzvan [cite: 6]  
[cite_start]**Date:** December 2025 [cite: 7]