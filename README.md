# TFmini-S Interface with ESP32

This project demonstrates how to interface the **Benewake TFmini-S LiDAR sensor** with an **ESP32** using UART communication.

## 🔧 Features

- Receives accurate distance measurements from TFmini-S
- Displays signal strength and internal temperature
- Validates data with checksum before use
- Clean, efficient, and well-structured code

---

## 🛠️ Hardware Used

| Device       | Model/Spec             |
|--------------|------------------------|
| Microcontroller | ESP32 (Any variant with Serial2) |
| LiDAR Sensor | Benewake TFmini-S (UART version) |
| Power        | 5V regulated (TFmini needs 5V) |

---

## 🔌 Wiring Diagram

| TFmini-S Pin | ESP32 GPIO | Notes                                |
|--------------|------------|--------------------------------------|
| **VCC**      | 5V         | Use regulated 5V                     |
| **GND**      | GND        | Common ground with ESP32             |
| **TX**       | GPIO16     | Connect to ESP32 RX2 (UART2)         |
| **RX**       | GPIO17     | Use voltage divider (3.3V for ESP32) |

---

## 📦 Data Packet Format (TFmini UART)

TFmini sends **9 bytes** per data frame:

| Byte | Description      |
|------|------------------|
| 0    | 0x59 (Header)    |
| 1    | 0x59 (Header)    |
| 2-3  | Distance (Low + High byte) |
| 4-5  | Strength (Low + High byte) |
| 6-7  | Temperature (Low + High byte) |
| 8    | Checksum (sum of bytes 0–7 % 256) |

---

## 🧪 Sample Output

```text
Distance: 132 cm	Strength: 1280	Temperature: 24.75 °C
