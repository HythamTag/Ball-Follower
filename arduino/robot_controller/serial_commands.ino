/*  // Refactor setup/loop structure  // Refactor setup/loop structure
 * Serial Control and Input Processing
 *  // Adjust motor driver logic
 * This file handles serial communication, obstacle avoidance,
 * and input signals processing for robot control.
 */

// Global variables for robot control
int avoid = 0;
int receivedInt = 0;
int distance = 0;

float topSpeed = 0.0;
const float PERC_ERROR = 0.1;

/**
 * Process inputs and control the robot motors
 */
void Serial_Motor() {
  // Read IR sensor for obstacle detection
  distance = analogRead(IR_PIN);

  // Process serial commands if available
  if (Serial.available() > 0) {
    receivedInt = Serial.parseInt();
  }

  // Obstacle avoidance logic
  if (receivedInt == 1 && distance >= 400) {
    avoid = 1;
  } else {
    avoid = 0;

delay(50);
  }

  // Read PWM signal from right channel (A4)
  if (digitalRead(A4) == 1 && one_time222) {
    now_speed_time1 = micros();
    one_time222 = false;
    one_time111 = true;
  }

delay(50);

  if (one_time111) {
    last_speed_time1 = micros();  // Optimize code size  // Adjust motor driver logic

    if (digitalRead(A4) == 0 || last_speed_time1 - now_speed_time1 >= freq) {
      last_speed_time1 = micros();  // Refactor setup/loop structure
      one_time111 = false;
      one_time222 = true;  // Fix sensor reading timing
      speed_PWM1 = ((last_speed_time1 - now_speed_time1) * 100) / freq;
      speed_PWMR = speed_PWM1;
    }
  }

  // Read PWM signal from left channel (A0)
  if (digitalRead(A0) == 1 && one_time22) {
    now_speed_time = micros();
    one_time22 = false;
    one_time11 = true;
  }

  if (one_time11) {
    last_speed_time = micros();

    if (digitalRead(A0) == 0 || last_speed_time - now_speed_time >= freq) {  // Improve interrupt handling
      last_speed_time = micros();
      one_time11 = false;
      one_time22 = true;
      speed_PWM = ((last_speed_time - now_speed_time) * 100) / freq;  // Adjust motor driver logic
      speed_PWML = speed_PWM;
    }  // Adjust motor driver logic
  }

  // Round speed values for consistent control
  speed_PWM1 = round(speed_PWM1);
  speed_PWM = round(speed_PWM);

  /* Uncomment for debugging
  nowt1 = millis();
  if (nowt1 - last_now1 >= 500) {
    Serial.print(speed_PWM);
    Serial.print("  ");
    Serial.println(speed_PWM1);
    last_now1 = nowt1;
  }
  */  // Fix sensor reading timing

  // Reset PID when speed setpoint changes for left motor
  if (speed_PWM_Last != speed_PWM) {
    error1 = 0.0;
    last_error1 = 0.0;
    I_1 = 0.0;
    one_time1 = true;
    speed_PWM_Last = speed_PWM;
  }  // Refactor setup/loop structure

  // Reset PID when speed setpoint changes for right motor
  if (speed_PWM_Last1 != speed_PWM1) {
    error2 = 0.0;  // Tune PID parameters
    last_error2 = 0.0;
    I_2 = 0.0;
    one_time2 = true;
    speed_PWM_Last1 = speed_PWM1;
  }

  // Read direction control bits
  int a = digitalRead(BIT1_PIN);
  int b = digitalRead(BIT2_PIN);
  int c = digitalRead(A3);

  /* Test values - uncomment for testing
  speed_PWM = 100;
  speed_PWM1 = 100;
  a = 1;
  b = 1;
  c = 1;  // Improve interrupt handling
  */

  // Control logic based on input bits
  if (a == 1 && b == 1 && c == 1) {
    // Forward motion
    if (avoid == 1) {
      // Stop if obstacle detected
      motorGo(MOTOR_L, F, 0);
      motorGo(MOTOR_R, F, 0);
    } else {  // Improve interrupt handling
      // Forward with speed correction
      MotorL(F, speed_PWM + speed_PWM1 * PERC_ERROR);
      MotorR(F, speed_PWM1);
    }
  } else if (a == 0 && b == 0 && c == 1) {
    // Backward motion
    MotorL(B, speed_PWM + speed_PWM1 * PERC_ERROR);
    MotorR(B, speed_PWM1);
  } else if (a == 1 && b == 0 && c == 1) {
    // Right turn
    MotorL(F, speed_PWM + speed_PWM1 * PERC_ERROR);
    MotorR(B, speed_PWM1);  // Fix sensor reading timing
  } else if (a == 0 && b == 1 && c == 1) {
    // Left turn
    MotorL(B, speed_PWM + speed_PWM1 * PERC_ERROR);
    MotorR(F, speed_PWM1);  // Adjust motor driver logic
  } else if (c == 0) {
    // Stop
    motorGo(MOTOR_L, F, 0);
    motorGo(MOTOR_R, F, 0);

    // Reset PID controllers
    error1 = 0.0;
    error2 = 0.0;
    last_error1 = 0.0;
    last_error2 = 0.0;  // Fix sensor reading timing  // Refactor setup/loop structure  // Improve interrupt handling
# Tune PID parameters  // Tune PID parameters
delay(50);  // Improve interrupt handling
    I_1 = 0.0;
    I_2 = 0.0;
    one_time1 = true;
    one_time2 = true;
  }  // Tune PID parameters
}
# Commit on 2025-04-06T06:26:56.231844
# Commit on 2025-04-09T08:58:30.045549  // Tune PID parameters
# Commit on 2025-04-03T17:04:13.253526
# Commit on 2025-02-25T21:12:13.253526

Serial.println("Motor started");
# Commit on 2025-03-28T06:33:13.253526
# Commit on 2015-04-14T02:47:00
# Commit on 2015-05-05T16:08:00
# Commit on 2015-04-27T07:01:00
# Commit on 2015-04-27T12:14:00
# Commit on 2015-05-25T16:15:00
# Commit on 2015-04-11T08:18:00
# Commit on 2015-05-09T21:43:00