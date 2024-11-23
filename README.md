# Hand Gesture-Based Home Appliances Control System USING ARDUINO AND OPENCV

## Project Overview

This project develops a **hand gesture-based control system** for home appliances using **OpenCV** and **Arduino**. The system utilizes a computer vision approach to recognize gestures captured by a camera and processes them in real-time to control devices wirelessly. It enhances user convenience and accessibility, especially for individuals with mobility constraints, by eliminating the need for physical contact with switches. The system demonstrates the seamless integration of hardware and software, providing a hands-on learning experience in **embedded systems** and **computer vision**.

---

## Features

- **Gesture Recognition**: Real-time detection and interpretation of hand gestures using OpenCV.
- **Wireless Control**: Utilizes Arduino and NodeMCU for controlling appliances without physical connections.
- **Energy Efficiency**: Promotes efficient appliance management to save power.
- **Accessible**: Designed to assist elderly and disabled individuals with non-contact operation.
- **Customizable**: Supports additional gestures and appliances for future scalability.

---

## System Architecture

The system comprises:

1. **Gesture Recognition Module**: Processes video input using OpenCV to detect specific gestures.
2. **Communication Module**: Transfers recognized commands to appliances via MQTT protocol using NodeMCU.
3. **Control Module**: Switches appliances on or off using relays controlled by Arduino.
4. **Hardware Components**:
   - NodeMCU (ESP8266)
   - Relays
   - 12V DC Fan
   - Lamps
   - Camera for gesture detection
   - Power Supply

---

## Installation Guide

### Hardware Setup

1. **Connect Hardware**:
   - Attach relays to NodeMCU for controlling appliances.
   - Set up a camera compatible with OpenCV for gesture recognition.
   - Ensure a stable power supply for the components.

2. **Circuit Connections**:
   - Connect NodeMCU GPIO pins to the relay control terminals.
   - Attach appliances (fan, lamp, etc.) to the relays.
   - Follow the pin mappings for accurate setup.

### Software Installation

1. **Install Python and Required Libraries**:
   ```
   pip install opencv-python mediapipe paho-mqtt
   ```
2. **Set Up Arduino IDE**:
   - Install the Arduino IDE from [Arduino Official Site](https://www.arduino.cc/en/software).
   - Add the ESP8266 board via **Boards Manager**.
   - Install the required libraries: **PubSubClient**, **SoftwareSerial**.

3. **Clone Repository**:
   ```
   git clone https://github.com/SRamya24/HAND-GESTURE-BASED-HOME-APPLIANCES-USING-OPENCV.git
   ```
4. **Upload Arduino Code**:
   - Open the `NodeMCU_code.ino` file in Arduino IDE.
   - Select the correct board and port, then upload the code.

5. **Run Python Script**:
   ```
   python proj.py
   ```

---

## How It Works

1. **Gesture Detection**:
   - The camera detects hand gestures in real-time.
   - OpenCV processes the captured gestures and determines commands.

2. **Command Communication**:
   - Recognized gestures are translated into MQTT messages.
   - NodeMCU receives messages and activates relays.

3. **Appliance Control**:
   - Relays control the connected appliances based on received commands.
   - Notifications about appliance status are sent via SMS using GSM modules.

---

## Demonstration

- **Gesture 1**: Turns on Lamp 1.
- **Gesture 2**: Turns on Fan.
- **Gesture 3**: Activates Motor.
- **Gesture 5**: Turns off Lamp 1.
- **Gesture 6**: Turns off Fan.
- **Gesture 7**: Deactivates Motor.
- **Gesture 9**: Turns off all appliances.

---

## Future Enhancements

- Add **AI/ML-based gesture recognition** for improved accuracy.
- Integrate with IoT platforms for remote monitoring and control.
- Support more gestures for additional appliances.
