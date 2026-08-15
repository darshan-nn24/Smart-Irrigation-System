# 🌱 Smart Irrigation System

### IoT-Based Automatic Irrigation for Smarter Water Management

A simple ESP32-based smart irrigation system that monitors soil moisture and environmental conditions and automatically controls a water pump.

## 🎯 Problem

Manual and fixed-schedule irrigation can cause water wastage, over-irrigation, and under-irrigation.

## 💡 Solution

The ESP32 reads soil moisture continuously. When the soil becomes dry, the pump turns ON. When the target moisture level is reached, the pump turns OFF.

```text
Soil Moisture Sensor
        ↓
      ESP32
        ↓
 Moisture Analysis
        ↓
   Soil Too Dry?
      ↙     ↘
    YES      NO
     ↓        ↓
 Pump ON   Keep State
     ↓
Moisture Reaches Target
     ↓
 Pump OFF
```

## ✨ Features

- 🌱 Automatic soil-moisture monitoring
- 💧 Automatic pump control
- 🌡️ Temperature monitoring
- 💨 Humidity monitoring
- ⚡ ESP32 controller
- 🔄 Hysteresis-based pump control
- 📟 Serial Monitor output
- 💦 Water-conservation focused design

## 🛠️ Hardware

| Component | Purpose |
|---|---|
| ESP32 | Main controller |
| Soil Moisture Sensor | Soil moisture measurement |
| DHT11 | Temperature and humidity |
| Relay Module | Pump switching |
| Water Pump | Irrigation |
| External Power Supply | Pump power |

> Do not power a pump directly from an ESP32 GPIO pin. Use a suitable relay/MOSFET driver and external pump supply.

## 🔌 Example Wiring

| Component | ESP32 |
|---|---|
| Soil Moisture AO | GPIO 34 |
| DHT11 DATA | GPIO 4 |
| Relay IN | GPIO 26 |
| GND | GND |

Adjust pins for your hardware.

## 💻 Software

- Arduino IDE
- ESP32 Arduino Core
- C/C++
- DHT Sensor Library by Adafruit
- Adafruit Unified Sensor

## ⚙️ Calibration

In `Smart-Irrigation.ino`, adjust:

```cpp
const int DRY_THRESHOLD = 35;
const int STOP_THRESHOLD = 55;

const int SOIL_RAW_DRY = 3200;
const int SOIL_RAW_WET = 1200;
```

These values are examples. Calibrate the sensor using your actual soil and sensor module.

## 🚀 Run

1. Install Arduino IDE.
2. Install ESP32 board support.
3. Install the DHT Sensor Library and Adafruit Unified Sensor.
4. Open `Smart-Irrigation.ino`.
5. Select your ESP32 board and COM port.
6. Upload.
7. Open Serial Monitor at `115200` baud.

## 📊 Example Output

```text
========== SMART IRRIGATION ==========
Soil Moisture : 28%
Temperature   : 27.4 C
Humidity      : 61.0%
Pump          : ON
======================================
```

## 🧠 Hysteresis

Two thresholds reduce rapid relay switching:

```text
Below 35%   → Pump ON
55% or more → Pump OFF
```

## 🚀 Future Improvements

- 📱 Mobile monitoring
- ☁️ Cloud IoT dashboard
- 📊 Historical analytics
- 🌦️ Weather-based irrigation
- 🤖 ML-based irrigation prediction
- 🔔 Alerts and notifications
- 📍 Multi-zone irrigation
- 🔋 Solar-powered operation

## 👨‍💻 Author

**Darshan Nagaraj Naik**

Information Science & Engineering Student  
AI & Machine Learning Enthusiast

GitHub: https://github.com/darshan-nn24  
LinkedIn: https://www.linkedin.com/in/darshan-nagaraj-naik-7b004a299/

## 📄 License

MIT License
