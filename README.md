# Automatic Headlight Control System Using Arduino

## Overview
This project implements an **Automatic Headlight Control System** using Arduino Uno R4 WiFi. It automates vehicle headlight operation to improve safety and convenience during night driving by intelligently switching between high beam and low beam based on ambient light and proximity of other vehicles.

## Features
- **Ambient Light-Based Automatic Headlight Control:** Utilizes an LDR sensor to detect day/night conditions and automatically turn headlights ON or OFF.  
- **Adaptive Headlight Dimming in Well-Lit Areas:** Automatically switches to low beam in street-lit areas to reduce glare and save energy.  
- **Automatic Glare Reduction:** Switches from high beam to low beam when an oncoming vehicle is detected, using IR and ultrasonic sensors to enhance road safety.

## Components
| Component             | Purpose                                      |
|-----------------------|----------------------------------------------|
| Arduino Uno R4 WiFi   | Main microcontroller                         |
| LDR Sensor            | Ambient light sensing for auto ON/OFF       |
| IR Sensors (Left & Right) | Vehicle detection for beam switching    |
| Ultrasonic Sensor (HC-SR04) | Distance measurement for obstacle detection|
| LEDs (High & Low Beam) | Simulate vehicle headlights                 |
| Resistors, Breadboard, Wires | Circuit prototyping                      |


## How It Works
1. The LDR sensor reads ambient light levels to determine day or night.  
2. The system switches headlights ON or OFF automatically based on light levels.  
3. When driving in well-lit areas at night, headlights dim to low beam to reduce glare.  
4. IR and ultrasonic sensors detect nearby vehicles, switching from high beam to low beam when oncoming traffic is detected to avoid dazzling other drivers.

## Installation and Setup
1. Connect the LDR sensor to analog pin A0.  
2. Connect IR sensors to digital pins 2 and 3.  
3. Connect the ultrasonic sensor trigger and echo to pins 9 and 10.  
4. Connect LEDs for high and low beams to pins 6 and 8 with suitable current-limiting resistors.  
5. Upload the Arduino sketch using Arduino IDE to the Arduino Uno R4 WiFi.  
6. Open the serial monitor for debugging and sensor data visualization.

## Usage
- The system runs fully autonomously after setup.  
- Observe the serial monitor to understand sensor readings and headlight states in real-time.  
- Modify threshold values in the code as needed to calibrate for different sensor sensitivities or lighting environments.

## Future Enhancements
- Integrate computer vision for robust object recognition to improve reliability.  
- Implement PWM-based dimming for smoother beam transitions.  
- Add wireless monitoring and remote override using Arduino R4 WiFi connectivity.

## Video Demonstration
[Click here for Demonstration Video](https://www.linkedin.com/posts/kartik-verma-2969a71ab_arduino-embeddedsystems-automotiveelectronics-activity-7370885652445540352-4Ppw?utm_source=share&utm_medium=member_desktop&rcm=ACoAADEXNtIBY58IUKipPE6HyE3g9RW9TH1jyWc)

---

## Author
Kartik Verma
[LinkedIn](www.linkedin.com/in/kartik-verma-2969a71ab)

---

## Support
If you find this project helpful, please give it a ⭐️!

