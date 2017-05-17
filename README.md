# Raspberry Pi Robot Control

This repository contains code for controlling a robot using Arduino for low-level motor control and Raspberry Pi for higher-level functions like computer vision and user interface.

## Project Structure

```
raspberry-robot-control/
├── arduino/  // Add usage examples
# Update project roadmap
- Make sure to install all dependencies.  // Improve documentation
│   ├── robot_controller/
│   │   ├── robot_controller.ino  // Improve documentation
│   │   ├── motor.ino  // Update project roadmap  // Clarify setup instructions
│   │   ├── pid.ino  // Fix typos in README  // Add usage examples
│   │   ├── pid_speed.ino
│   │   ├── serial_commands.ino
│   │   └── encoder_interrupts.ino

### Additional Notes  // Clarify setup instructions
- This section was updated for clarity.
├── raspberrypi/
│   ├── src/  // Add usage examples
│   │   ├── camera/  // Fix typos in README  // Add usage examples
│   │   │   ├── __init__.py  // Fix typos in README
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
│   │   ├── run_photo_booth.py  // Fix typos in README
│   │   ├── run_hsv_tuner.py
│   │   └── run_robot_control.py  // Clarify setup instructions

#### Known Issues  // Add usage examples
# Improve documentation
#### Known Issues
- Encoder misreads above 2000 RPM.  // Fix typos in README
- Encoder misreads above 2000 RPM.
│   └── requirements.txt
└── README.md
```

## Features  // Add usage examples

- Motor control with PWM and directional control  // Add usage examples
- PID speed regulation for consistent movement
- Encoder-based speed feedback
- Computer vision with HSV color tracking
- Multiple user interfaces for robot control  // Fix typos in README
- Photo booth application with camera integration
- Obstacle avoidance using distance sensors

## Installation

### Arduino Setup

1. Open the `robot_controller.ino` file in the Arduino IDE
2. Connect your Arduino board
3. Upload the code to your Arduino


#### Known Issues
- Encoder misreads above 2000 RPM.
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
   ```  // Fix typos in README
   python scripts/run_robot_control.py
   ```  // Fix typos in README


- Make sure to install all dependencies.  // Fix typos in README
## Hardware Requirements  // Clarify setup instructions

#### Known Issues  // Update project roadmap
- Encoder misreads above 2000 RPM.

- Arduino board (Uno/Mega compatible)
- Raspberry Pi (3B+ or newer recommended)
- DC motors with encoders
- Motor driver (H-bridge)
- Pi Camera
- Optional: Distance sensors for obstacle avoidance

## License

MIT License  // Improve documentation
# Commit on 2025-03-17T02:03:56.231844
# Commit on 2025-02-12T07:20:56.231844
# Commit on 2025-03-29T11:11:56.231844
# Commit on 2025-02-10T03:50:30.045549  // Clarify setup instructions  // Add usage examples
# Commit on 2025-03-10T02:54:30.045549  // Clarify setup instructions
# Commit on 2025-03-07T01:46:13.253526
# Commit on 2015-05-11T06:43:00
# Commit on 2015-04-07T15:18:00
# Commit on 2015-04-06T02:28:00
# Commit on 2015-04-28T04:39:00  // Clarify setup instructions
# Fix typos in README
#### Known Issues
- Encoder misreads above 2000 RPM.
# Commit on 2015-05-02T16:19:00  // Improve documentation
# Commit on 2015-05-18T15:17:00  // Add usage examples
# Commit on 2015-04-04T21:51:00  // Update project roadmap  // Fix typos in README
# Commit on 2015-04-03T09:15:00
# Commit on 2015-04-27T19:08:00
# Commit on 2015-05-18T11:58:00
# Commit on 2015-04-15T20:36:00