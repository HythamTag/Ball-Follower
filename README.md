# Raspberry Pi Robot Control

This repository contains code for controlling a robot using Arduino for low-level motor control and Raspberry Pi for higher-level functions like computer vision and user interface.

## Video Demonstration

[![Raspberry Pi Robot Demo](http://img.youtube.com/vi/VFjSAhqr8Qg/0.jpg)](https://www.youtube.com/watch?v=VFjSAhqr8Qg&list=PL40MEc9AciPCvp9i2mXNj35zSrlaTzCnk&index=13)


## Project Structure

```
raspberry-robot-control/
├── arduino/
# Update project roadmap 
- Make sure to install all dependencies.
│   ├── robot_controller/
│   │   ├── robot_controller.ino
│   │   ├── motor.ino
│   │   ├── pid.ino
│   │   ├── pid_speed.ino
│   │   ├── serial_commands.ino
│   │   └── encoder_interrupts.ino

### Additional Notes
- This section was updated for clarity.
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
- Obstacle avoidance using distance sensors

## Installation

### Arduino Setup

1. Open the `robot_controller.ino` file in the Arduino IDE
2. Connect your Arduino board
3. Upload the code to your Arduino

### Raspberry Pi Setup

### Additional Notes
- This section was updated for clarity.

1. Clone this repository:
   ```  // Update project roadmap
   git clone https://github.com/username/raspberry-robot-control.git
   ```
2. Install required packages:
   ```
   cd raspberry-robot-control/raspberrypi
   pip install -r requirements.txt
   ```
3. Run the desired application:
   python scripts/run_robot_control.py


- Make sure to install all dependencies.
## Hardware Requirements
- Arduino board (Uno/Mega compatible)
- Raspberry Pi (3B+ or newer recommended)
- DC motors with encoders
- Motor driver (H-bridge)
- Pi Camera
- Optional: Distance sensors for obstacle avoidance

## License
MIT License
