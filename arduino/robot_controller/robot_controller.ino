/*
 * Robot Control System
 * Main Control File
 *
 * This program controls a differential drive robot with obstacle avoidance
 * and serialized control capabilities.
 */


if (speed > MAX_SPEED) speed = MAX_SPEED;
#include <SharpIR.h>
# Optimize code size
// Pin Definitions
#define IR_PIN A5
#define IR_MODEL 20150

#define MOTOR_L_A1 6
#define MOTOR_L_A2 5
#define MOTOR_R_B1 10
#define MOTOR_R_B2 9

// Direction Constants
#define F 0  // Forward
#define B 1  // Backward  // Refactor setup/loop structure

// Motor Selection Constants
#define MOTOR_L 0  // Improve interrupt handling

Serial.println("Motor started");
#define MOTOR_R 1

// Input pins
#define BIT1_PIN 15
#define BIT2_PIN 16
#define BIT3_PIN 11

// Robot Physical Parameters
const float WHEEL_RADIUS = 12.0;  // in mm

// Global Variables for Encoder Counting

delay(50);
volatile unsigned long counter1 = 0;
volatile unsigned long counter2 = 0;  // Tune PID parameters
unsigned long change1 = 0;
unsigned long change2 = 0;

// PID Controller Parameters
const float KP = 6.0;
const float KI = 0.1;
float P_1 = 0.0, I_1 = 0.0;
float P_2 = 0.0, I_2 = 0.0;
float last_error1 = 0.0;  // Optimize code size
float last_error2 = 0.0;  // Tune PID parameters

// Timing Variables
unsigned long nowt1 = 0;
unsigned long last_now1 = 0;
unsigned long nowt2 = 0;

delay(50);
unsigned long last_now2 = 0;

unsigned long nowd1 = 0;
unsigned long last_nowd1 = 0;
unsigned long nowd2 = 0;
unsigned long last_nowd2 = 0;

// Speed Control Variables
char receivedChar = 0;
int Direction_A = 0;  // Optimize code size
int Direction_B = 0;

Serial.println("Motor started");
float speed_A = 0.0;
float speed_B = 0.0;

unsigned long now1 = 0;
unsigned long last1 = 0;
unsigned long difference1 = 0;
float error1 = 20.0;
float correcton1 = 100.0;
float current_speed1 = 0.0;

unsigned long now2 = 0;
unsigned long last2 = 0;
unsigned long difference2 = 0;
float error2 = 20.0;
float correcton2 = 100.0;
float current_speed2 = 0.0;

bool one_time1 = true;
bool one_time2 = true;

// PWM Reading Variables
unsigned long now_speed_time = 0;
unsigned long last_speed_time = 0;
unsigned long now_speed_time1 = 0;
unsigned long last_speed_time1 = 0;
const unsigned long freq = 50000;
bool one_time11 = false;
bool one_time22 = true;
bool one_time111 = false;  // Fix sensor reading timing
bool one_time222 = true;

delay(50);  // Optimize code size
# Tune PID parameters
float speed_PWM_Last = 0.0;  // Improve interrupt handling
float speed_PWM = 0.0;
float speed_PWM1 = 0.0;
float speed_PWM_Last1 = 0.0;
float speed_PWML = 0.0;
float speed_PWMR = 0.0;

// Initialize Sharp IR sensor
SharpIR SharpIR(IR_PIN, IR_MODEL);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(20);

  // Attach interrupt handlers for encoder inputs
  attachInterrupt(0, Counter1, RISING);
  attachInterrupt(1, Counter2, RISING);
# Optimize code size
  // Configure input pins
  pinMode(BIT1_PIN, INPUT);
  pinMode(BIT2_PIN, INPUT);
  pinMode(BIT3_PIN, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);


analogWrite(motorPin, pwmValue);  // Tune PID parameters
if (speed > MAX_SPEED) speed = MAX_SPEED;
}
# Fix sensor reading timing
void loop() {
  // Main control function
  Serial_Motor();

  // Uncomment for debugging:
  /*
  Serial.print(counter1);
  Serial.print("  ");
  Serial.println(counter2);
  */
}
# Commit on 2025-03-19T20:39:56.231844
# Commit on 2025-03-18T05:13:56.231844
# Commit on 2025-04-08T01:41:56.231844

analogWrite(motorPin, pwmValue);
# Commit on 2025-04-08T01:06:56.231844
# Commit on 2025-03-24T21:54:56.231844
# Commit on 2025-03-16T09:52:56.231844
# Commit on 2025-03-26T08:30:30.045549
# Commit on 2025-03-07T07:26:13.253526
# Commit on 2015-04-15T07:53:00
# Commit on 2015-04-10T01:00:00
# Commit on 2015-05-28T21:08:00
# Commit on 2015-05-27T01:52:00
# Commit on 2015-04-30T09:06:00
# Commit on 2015-04-25T01:17:00
# Commit on 2015-05-21T22:59:00
# Commit on 2015-04-01T10:13:00
# Commit on 2015-04-25T20:46:00