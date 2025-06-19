# Raspberry Pi Robot Control

This repository contains code for controlling a robot using Arduino for low-level motor control and Raspberry Pi for higher-level functions like computer vision and user interface.

## Video Demonstration

<div align="center">
  <a href="https://www.youtube.com/watch?v=VFjSAhqr8Qg&list=PL40MEc9AciPCvp9i2mXNj35zSrlaTzCnk&index=13">
    <img src="http://img.youtube.com/vi/VFjSAhqr8Qg/0.jpg" alt="Raspberry Pi Robot Demo" />
  </a>
</div>

## Project Structure

```
raspberry-robot-control/
├── arduino/
│   ├── robot_controller/
│   │   ├── robot_controller.ino
│   │   ├── motor.ino
│   │   ├── pid.ino
│   │   ├── pid_speed.ino
│   │   ├── serial_commands.ino
│   │   └── encoder_interrupts.ino
├── raspberrypi/
│   ├── src/
│   │   ├── camera/
│   │   │   ├── __init__.py
│   │   │   └── pi_video_stream.py
│   │   ├── vision/
│   │   │   ├── __init__.py
│   │   │   └── color_tracker.py
│   │   ├── gui/
│   │   │   ├── __init__.py
│   │   │   ├── photo_booth_app.py
│   │   │   └── robot_control_gui.py
│   │   └── __init__.py
│   ├── scripts/
│   │   ├── run_photo_booth.py
│   │   ├── run_hsv_tuner.py
│   │   └── run_robot_control.py
```

## Features

- Motor control with PWM and directional control
- PID speed regulation for consistent movement
- Encoder-based speed feedback
- Computer vision with HSV color tracking
- Multiple user interfaces for robot control
- Photo booth application with camera integration

## Installation

### Arduino Setup

1. Open the `robot_controller.ino` file in the Arduino IDE
2. Connect your Arduino board
3. Upload the code to your Arduino

### Raspberry Pi Setup

1. Clone this repository:
   ```bash
   git clone https://github.com/username/raspberry-robot-control.git
   ```
2. Install required packages:
   ```bash
   cd raspberry-robot-control/raspberrypi
   pip install -r requirements.txt
   ```
3. Run the desired application:
   ```bash
   python scripts/run_robot_control.py
   ```

## Hardware Requirements

- Arduino board (Uno/Mega compatible)
- Raspberry Pi (3B+ or newer recommended)
- DC motors with encoders
- Motor driver (H-bridge)
- Pi Camera
- Optional: Distance sensors for obstacle avoidance
