
# SARBot - Surveillance and Rescue Bot

## 🚀 Project Overview

Currently in simulation phase

SARBot is a low-cost surveillance and rescue robot designed for **flooded, earthquake-prone, and disaster-prone areas**, capable of:

- Obstacle detection and avoidance
- Edge detection for avoiding falls
- Environmental monitoring (temperature and humidity)
- Alert mechanisms (buzzer and LED)
- Camera streaming 

This project uses **ESP32-CAM, ultrasonic sensor, IR sensor, DHT11, buzzer, and LED** to enable autonomous navigation in complex environments during rescue operations.

---

## 📦 Components Used

- ESP32-CAM module
- HC-SR04 Ultrasonic Sensor
- IR Sensor
- DHT11 Temperature & Humidity Sensor
- L298N Motor Driver (in hardware)
- BO Motors + Wheels
- Li-ion Battery with Voltage Regulator
- Buzzer and LED for alerts
- Jumper Wires, Breadboard
- Chassis for mounting

---


## How to Simulate and Test in Wokwi

### 1. Open the Project
- Import your `.ino` and `diagram.json` files into [Wokwi](https://wokwi.com).

### 2. Simulate Obstacle Detection
- Click the **Ultrasonic Sensor** in Wokwi.
- In the **Properties Panel (right side)**, change the **Distance** value to `15 cm`.
- SARBot will:
  - Stop motors
  - Trigger buzzer + LED alert
  - Turn right to avoid the obstacle

### 3. Simulate Edge Detection
- Click the **IR Sensor** in Wokwi.
- Press the **Button** on the IR module to simulate LOW state.
- SARBot will:
  - Stop motors immediately
  - Trigger buzzer + LED alert

### 4. Environmental Monitoring
- Click the **DHT11 Sensor**.
- Set **Temperature** and **Humidity** values in the Properties Panel.
- Observe these values printed in the Serial Monitor every 5 seconds.

### 5. Normal Forward Movement
- When:
  - Distance > 20 cm
  - IR sensor HIGH
- SARBot will move forward continuously.

---

## ⚡ Testing Checklist

✅ Moves forward by default when clear  
✅ Detects obstacles (< 20 cm), stops, alerts, and turns to avoid  
✅ Detects edges, stops, and alerts  
✅ Reads and prints temperature and humidity values  
✅ Buzzer and LED function for alerts  
✅ Serial monitor provides clean status updates

