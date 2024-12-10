# 8-Channel IR Line Follower Robot

A high-speed line-following robot using an 8-channel IR sensor array for precise line detection and smooth tracking capabilities.

## Features

- 8-channel IR sensor array for high-precision line detection
- PID control implementation for smooth navigation
- High-speed operation with optimal performance
- Adjustable sensor sensitivity
- Multiple operation modes including racing and debugging
- Configurable speed control

---

## Hardware Requirements

### Components
- **8-Channel IR Sensor Array**  
- **Microcontroller (Arduino/STM32)**  
- **L298N Motor Driver**  
- **DC Motors (2x)**  
- **Chassis**  
- **Wheels (2x drive wheels + 1x castor wheel)**  
- **7.4V or 11.1V LiPo Battery**  
- **Power Switch**  
- **Jumper Wires**  
- **Mounting Hardware**  

---

## Pin Configuration

| Component      | Pin    |
|----------------|--------|
| IR1            | A0     |
| IR2            | A1     |
| IR3            | A2     |
| IR4            | A3     |
| IR5            | A4     |
| IR6            | A5     |
| IR7            | A6     |
| IR8            | A7     |
| Motor1 PWM     | D5     |
| Motor1 DIR1    | D4     |
| Motor1 DIR2    | D3     |
| Motor2 PWM     | D6     |
| Motor2 DIR1    | D7     |
| Motor2 DIR2    | D8     |

---

## Software Setup

### Dependencies
- **Arduino IDE**
- **PID Library**

### Installation

```bash
git clone https://github.com/username/Line_Follower_IR_8CH.git


```

---

## Usage

```bash
cd Line_Follower_IR_8CH
```     

```bash
arduino --upload Line_Follower_IR_8CH.ino
``` 

---     

## License




