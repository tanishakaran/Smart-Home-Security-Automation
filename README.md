# 🏠 Smart Home Security & Automation System

An Arduino-based multi-sensor system that combines security monitoring and basic home automation using an ultrasonic sensor, LDR, temperature sensor, buzzer, LEDs, and servo motor.

## 🎯 Objective

To build a smart home system that can detect nearby objects, monitor light and temperature conditions, and automatically control security and home devices.

## 🧩 Components

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- LDR
- 10kΩ Resistor
- TMP36 Temperature Sensor
- Micro Servo Motor
- Buzzer
- 3 LEDs
- 3 × 220Ω Resistors
- Breadboard
- Jumper Wires

## 🔌 Circuit Connections

| Component | Arduino |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D7 |
| HC-SR04 ECHO | D6 |
| Buzzer (+) | D8 |
| Buzzer (-) | GND |
| Servo Signal | D9 |
| Servo VCC | 5V |
| Servo GND | GND |
| LDR Output | A0 |
| TMP36 Vout | A1 |
| Light LED | D12 through 220Ω |
| Temperature LED | D13 through 220Ω |
| Security LED | D11 through 220Ω |

## ⚙️ Working

The system monitors three different conditions:

### 🔐 Security Detection
- Distance < 10 cm → Security LED ON + Buzzer ON + Servo moves to 90°
- Distance ≥ 10 cm → Security LED OFF + Buzzer OFF + Servo returns to 0°

### 🌙 Light Monitoring
- Low light → Light LED ON
- Bright light → Light LED OFF

### 🌡️ Temperature Monitoring
- Temperature > 30°C → Temperature LED ON
- Temperature ≤ 30°C → Temperature LED OFF

## 🔄 System Flow

**Sensors → Arduino → Decision Making → LEDs / Buzzer / Servo**

## 📸 Circuit

![Smart Home Security & Automation System](circuit.png)

## 🛠️ Simulation

The project was designed and tested using **Tinkercad Circuits**.

## 💻 Technologies

- Arduino Uno
- C/C++ (Arduino)
- HC-SR04
- LDR
- TMP36
- Servo Motor
- Tinkercad Circuits

## 🧠 Concepts Learned

- Multiple sensor integration
- Analog sensor reading
- Ultrasonic distance measurement
- Servo motor control
- Conditional logic
- Digital input/output
- Sensor-based automation
- Multi-device control

## 🚀 Future Improvements

- Add PIR motion detection
- Add LCD/OLED display
- Add ESP32 Wi-Fi connectivity
- Send alerts to a mobile/web application
- Add cloud-based monitoring

---

### 👩‍💻 Author

**Tanisha Karan**  
B.Tech CSE (IoT) Student
