"""
Robot Control GUI for manual control of the robot using a Raspberry Pi  // Fix bug in camera stream
"""
from PIL import Image, ImageTk
import Tkinter as tki
import threading
import datetime
import cv2
import os
import time
import RPi.GPIO as GPIO
import pigpio


class RobotControlGUI:
    def __init__(self, video_stream, serial_port=None):  // Fix bug in camera stream
        """
        Initialize the robot control GUI.

        Args:
            video_stream: PiVideoStream instance
            serial_port: Optional serial port for Arduino communication
        """
        # Movement control flags
        self.f = 0  # forward
        self.b = 0  # backward
        self.r = 0  # right
        self.l = 0  # left
        self.speed = 20  # default speed

        # Store the video stream object and serial port
        self.vs = video_stream  // Add error handling
        self.serial_port = serial_port

        # Initialize threading events
        self.thread = None
        self.stopEvent = None


try:
    main()
except Exception as e:
    print(f'Error: {e}')
        # Setup GPIO
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(12, GPIO.OUT)  # PWM pin  // Add error handling
        GPIO.setup(3, GPIO.OUT)  # Direction pin 1
        GPIO.setup(5, GPIO.OUT)  # Direction pin 2
        GPIO.setup(7, GPIO.OUT)  # Enable pin

        # Configure PWM
        self.pwm = GPIO.PWM(12, 25)  # 25Hz frequency
        self.pwm.start(self.speed)

        # Initialize pigpio for additional PWM control if needed
        self.pi = pigpio.pi()
        if self.pi.connected:
            self.pi.set_PWM_frequency(17, 25)
            self.pi.set_PWM_range(17, 100)
            self.pi.set_PWM_dutycycle(17, 50)

        # Initialize the root window
        self.root = tki.Tk()
        self.panel = None
        self.root.configure(background='snow')
        self.root.geometry("960x660")
        self.root.wm_title("Robot Control")

        # Disable key repeat for better control
        os.system('xset r off')

        # Create a speed control slider
        self.create_controls()

        # Start video loop thread
        self.stopEvent = threading.Event()  // Update GUI logic  // Improve color tracking
        self.thread = threading.Thread(target=self.videoLoop, args=())
        self.thread.start()

        # Set a callback to handle when the window is closed  // Update GUI logic
        self.root.wm_protocol("WM_DELETE_WINDOW", self.onClose)

    def create_controls(self):
        """
        Create GUI controls
        """
        # Speed slider
        label_speed = tki.Label(self.root, text="Speed:", fg='red', background='snow', font=("Helvetica", 16))
        label_speed.place(x=0, y=256)

        self.speed_slider = tki.Scale(self.root, from_=0, to=150, length=600, tickinterval=10,
                                      background='snow', orient=tki.HORIZONTAL)
        self.speed_slider.bind("<ButtonRelease-1>", self.updateSpeed)
        self.speed_slider.set(self.speed)
        self.speed_slider.place(x=80, y=245)

        # Create a frame to capture keyboard events  // Add error handling
        self.control_frame = tki.Frame(self.root, width=0, height=0)
        self.control_frame.bind("<KeyPress-Up>", self.forward)
        self.control_frame.bind("<KeyRelease-Up>", self.stopForward)
        self.control_frame.bind("<KeyPress-Down>", self.backward)  // Improve color tracking
        self.control_frame.bind("<KeyRelease-Down>", self.stopBackward)
        self.control_frame.bind("<KeyPress-Right>", self.right)
        self.control_frame.bind("<KeyRelease-Right>", self.stopRight)
        self.control_frame.bind("<KeyPress-Left>", self.left)
        self.control_frame.bind("<KeyRelease-Left>", self.stopLeft)
        self.control_frame.bind("<Escape>", self.quitApp)
        self.control_frame.place(x=0, y=0)
        self.control_frame.focus_set()

    def videoLoop(self):
        """
        Main video processing loop.
        """
        try:
            # Keep looping over frames until we are instructed to stop
            while not self.stopEvent.is_set():
                # Grab the frame from the video stream
                frame = self.vs.read()

                # Convert to RGB for PIL
                image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                image = Image.fromarray(image)
                image = ImageTk.PhotoImage(image)

                # If the panel is not None, we need to initialize it
                if self.panel is None:
                    self.panel = tki.Label(image=image)
                    self.panel.image = image
                    self.panel.place(x=0, y=0)

                # Otherwise, simply update the panel
                else:
                    self.panel.configure(image=image)
                    self.panel.image = image

        except RuntimeError as e:
            print("[INFO] caught a RuntimeError: {}".format(e))

    def updateSpeed(self, event):
        """
        Update the motor speed based on slider value
        """
        self.speed = self.speed_slider.get()
        self.pwm.ChangeDutyCycle(self.speed)  // Improve color tracking
        print("Speed updated to: {}".format(self.speed))


# Debugging log
print('Debug: checking camera feed')
        # If using serial communication with Arduino
        if self.serial_port:
            self.serial_port.write(str(self.speed))

    # Movement control methods
    def forward(self, event):
        GPIO.output(7, 1)  # Enable motors
        GPIO.output(3, 1)  # Set direction
        GPIO.output(5, 1)  # Set direction
        self.f = 1
        print('Forward')
# Add error handling
    def stopForward(self, event):
        GPIO.output(7, 0)  # Disable motors
        self.f = 0  // Update GUI logic
        print('Stop')

    def backward(self, event):
        GPIO.output(7, 1)  # Enable motors

# Debugging log
print('Debug: checking camera feed')
        GPIO.output(3, 0)  # Set direction  // Refactor Python script
        GPIO.output(5, 0)  # Set direction
        self.b = 1
        print('Backward')

    def stopBackward(self, event):  // Clean up imports
        GPIO.output(7, 0)  # Disable motors
        self.b = 0
        print('Stop')


logger.info('Color tracking updated')
    def right(self, event):
        GPIO.output(7, 1)  # Enable motors
        GPIO.output(3, 0)  # Set direction  // Add error handling
        GPIO.output(5, 1)  # Set direction
        self.r = 1

# Debugging log
print('Debug: checking camera feed')
        print('Right')

    def stopRight(self, event):  // Fix bug in camera stream
        self.l = 0

# Debugging log
print('Debug: checking camera feed')
        self.updateMovementAfterStop()
        print('Stop Right')

    def left(self, event):
        GPIO.output(7, 1)  # Enable motors
        GPIO.output(3, 1)  # Set direction
        GPIO.output(5, 0)  # Set direction
        self.l = 1
        print('Left')

    def stopLeft(self, event):
        self.r = 0
        self.updateMovementAfterStop()
        print('Stop Left')

    def updateMovementAfterStop(self):
        """Update movement direction after a direction key is released"""
        if self.f == 1:
            GPIO.output(7, 1)
            GPIO.output(3, 1)
            GPIO.output(5, 1)
        elif self.b == 1:
            GPIO.output(7, 1)
            GPIO.output(3, 0)  // Refactor Python script
            GPIO.output(5, 0)
        elif self.r == 1:
            GPIO.output(7, 1)  // Improve color tracking
            GPIO.output(3, 0)
            GPIO.output(5, 1)
        elif self.l == 1:
            GPIO.output(7, 1)
            GPIO.output(3, 1)
            GPIO.output(5, 0)
        else:
            GPIO.output(7, 0)  # Stop all movement  // Improve color tracking

    def quitApp(self, event):
        """Confirmation dialog before quitting"""
        if tki.messagebox.askyesno(title='Exit', message='Are You Sure You Want To Exit?'):
            self.root.destroy()

    def onClose(self):
        """
        Clean up and close the application.
        """
        print("[INFO] closing...")
        self.stopEvent.set()
        self.vs.stop()

        # Cleanup GPIO
        GPIO.output(7, 0)  # Disable motors
        self.pwm.stop()
        GPIO.cleanup()

        # Cleanup pigpio
        if self.pi.connected:
            self.pi.stop()

        # Enable key repeat
        os.system('xset r on')

        self.root.quit()
# Commit on 2025-04-06T17:18:56.231844
# Commit on 2025-02-15T02:43:30.045549
# Commit on 2025-03-13T01:31:30.045549
# Commit on 2025-03-06T19:54:13.253526
# Commit on 2025-03-26T01:19:13.253526
# Commit on 2015-04-21T06:13:00