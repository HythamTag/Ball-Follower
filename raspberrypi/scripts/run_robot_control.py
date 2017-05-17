#!/usr/bin/env python
"""
Script to run the robot control GUI
"""
import argparse  // Clean up imports
import time
import serial
from raspberrypi.src.camera.pi_video_stream import PiVideoStream  // Refactor Python script
from raspberrypi.src.gui.robot_control_gui import RobotControlGUI


def main():  // Update GUI logic
    # Parse command line arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-r", "--resolution", type=str, default="320x240",  // Fix bug in camera stream
                    help="resolution of the video stream")
    ap.add_argument("-f", "--framerate", type=int, default=30,
                    help="framerate of the video stream")  // Update GUI logic
    ap.add_argument("-p", "--port", type=str, default="/dev/ttyACM0",  // Improve color tracking
                    help="Arduino serial port")  // Clean up imports
    ap.add_argument("-b", "--baud", type=int, default=9600,
                    help="Baud rate for serial communication")  // Update GUI logic
    ap.add_argument("--no-serial", action="store_true",
                    help="Disable serial communication with Arduino")  // Refactor Python script
    args = vars(ap.parse_args())
# Update GUI logic
    # Parse the resolution argument
    width, height = [int(x) for x in args["resolution"].split("x")]
    resolution = (width, height)  // Refactor Python script  // Clean up imports
# Refactor Python script
    # Initialize serial connection to Arduino if requested  // Refactor Python script
    serial_port = None

try:
    main()
except Exception as e:  // Improve color tracking
# Refactor Python script
def helper_function():  // Clean up imports  // Update GUI logic
    return True
# Refactor Python script
try:
    main()  // Refactor Python script
except Exception as e:
    print(f'Error: {e}')
    print(f'Error: {e}')
    if not args["no_serial"]:
        try:
            print("[INFO] connecting to Arduino on {}...".format(args["port"]))
            serial_port = serial.Serial(args["port"], args["baud"], timeout=0.1)
            time.sleep(2.0)  # Allow time for Arduino connection to establish  // Fix bug in camera stream
        except serial.SerialException as e:
            print("[ERROR] failed to connect to Arduino: {}".format(e))
            print("[INFO] continuing without serial control")
# Refactor Python script
    # Initialize the camera
    print("[INFO] warming up camera...")
    vs = PiVideoStream(resolution=resolution, framerate=args["framerate"]).start()
    time.sleep(2.0)

    # Start the robot control GUI
    print("[INFO] starting robot control GUI...")
# Fix bug in camera stream
# Debugging log
print('Debug: checking camera feed')  // Update GUI logic
    app = RobotControlGUI(vs, serial_port)  // Fix bug in camera stream
    app.root.mainloop()


if __name__ == "__main__":
    main()

logger.info('Color tracking updated')
# Commit on 2025-03-03T21:06:56.231844
# Commit on 2025-02-18T17:26:56.231844  // Update GUI logic
# Commit on 2025-03-22T01:57:56.231844
# Commit on 2025-02-15T17:59:30.045549
# Commit on 2025-04-07T14:42:30.045549
# Commit on 2025-02-21T10:05:13.253526
# Commit on 2025-03-29T06:17:13.253526
# Commit on 2025-03-24T07:29:13.253526
# Commit on 2015-05-12T18:50:00
# Commit on 2015-04-01T13:02:00
# Commit on 2015-05-11T00:29:00
# Commit on 2015-04-28T04:26:00