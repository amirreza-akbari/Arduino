# 🌡️ Smart Temperature Controlled Relay (Arduino + DHT21)

A simple and practical Arduino project that reads temperature using a DHT21 sensor and controls a relay based on defined temperature thresholds. This project can be used as a basic thermostat system for cooling or heating applications.

---

## 📌 Features

- Reads real-time temperature using DHT21 sensor
- Controls a relay based on temperature conditions
- Uses hysteresis to prevent relay flickering
- Stable reading interval (2 seconds)
- Serial Monitor output for debugging

---

## ⚙️ Components Used

- Arduino UNO (or compatible board)
- DHT21 Temperature & Humidity Sensor
- Relay Module (5V)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Wiring Diagram

| Component | Arduino Pin |
|----------|------------|
| DHT21 VCC | 5V |
| DHT21 GND | GND |
| DHT21 DATA | D7 |
| Relay IN | D8 |
| Relay VCC | 5V |
| Relay GND | GND |

---

## 🧠 How It Works

1. The DHT21 sensor reads ambient temperature every 2 seconds.
2. If temperature rises above **30.5°C**, the relay turns ON.
3. If temperature drops below **30.1°C**, the relay turns OFF.
4. Hysteresis prevents rapid switching between ON/OFF states.
5. All readings are printed to the Serial Monitor.

---

## 💻 Code Logic

- Uses `millis()` instead of `delay()` for non-blocking timing
- Implements temperature thresholds (ON/OFF)
- Stores relay state to avoid unnecessary switching

---

## 🚀 Getting Started

1. Install Arduino IDE
2. Install **DHT sensor library** from Library Manager
3. Connect components according to wiring table
4. Upload the code to Arduino UNO
5. Open Serial Monitor (9600 baud)

