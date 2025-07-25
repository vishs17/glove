# 🧤 Gesture-Controlled Smart Glove for Communication

## 🔍 Project Overview

This Arduino-based smart glove is designed to assist individuals with speech or mobility impairments. By detecting finger movements using flex sensors, the glove interprets hand gestures and sends corresponding messages over Bluetooth. It can communicate messages like “Washroom,” “Please Help,” and more—making it especially useful in emergency or caregiving scenarios.

---

## 🛠️ Hardware Components

- Arduino Uno
- 4 × Flex Sensors
- HC-05 Bluetooth Module
- Jumper Wires
- Breadboard or Glove Integration
- Power Supply (USB or Battery)

---

## 🧠 How It Works

- Each flex sensor is attached to a finger.
- When a finger bends, the sensor changes its resistance, which the Arduino reads via analog pins.
- Depending on the combination of bent fingers (based on sensor values), the Arduino sends specific messages to a paired device via Bluetooth.

---

## 💬 Predefined Messages

| Gesture Combination                              | Output Message      |
|--------------------------------------------------|---------------------|
| All fingers bent                                 | `Washroom`          |
| Only middle finger bent                          | `Please Help`       |
| Index and middle fingers straight, others bent   | `Gloves is at rest` |
| Index and middle bent, others straight           | `HELP`              |
| Last two fingers bent, others straight           | `Help`              |
| First and last bent, others straight             | `Take Me Out`       |
| No finger bent (default condition)               | `No sensors are bent.` |

---

## 🧾 Arduino Code Summary

- Uses `analogRead()` to read values from A0–A3.
- Sends corresponding messages using `Serial.println()` and `bluetooth.println()`.
- SoftwareSerial is used to communicate with the HC-05 module.

---

## 🔌 Pin Connections

| Component          | Arduino Pin |
|-------------------|-------------|
| Flex Sensor 1      | A0          |
| Flex Sensor 2      | A1          |
| Flex Sensor 3      | A2          |
| Flex Sensor 4      | A3          |
| HC-05 TX           | Pin 2 (RX)  |
| HC-05 RX           | Pin 3 (TX)  |

*Note: Use a voltage divider or logic level shifter for HC-05 RX.*

---

## 🔧 Getting Started

1. Connect the flex sensors and HC-05 as per the pin configuration.
2. Upload the provided Arduino code (`smart_glove.ino`) using the Arduino IDE.
3. Pair your HC-05 Bluetooth module with a Bluetooth terminal app on your phone.
4. Make hand gestures and view messages on the terminal.

---

## 🖼️ Optional Enhancements

- Add voice output using a text-to-speech module.
- Integrate an emergency SMS trigger with a GSM module.
- Use an OLED screen to show messages visually.

