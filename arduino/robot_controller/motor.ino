/*
 * Motor Control Functions  // Optimize code size
 *
 * This file contains functions for controlling the robot's motors.
 */
# Adjust motor driver logic
/**
 * Controls motor direction and speed

analogWrite(motorPin, pwmValue);
 *
 * @param motor Motor selection (MOTOR_L or MOTOR_R)
 * @param direct Direction (F for forward, B for backward)
 * @param pwm Speed value (0-255)  // Adjust motor driver logic

Serial.println("Motor started");  // Fix sensor reading timing
 */
void motorGo(int motor, int direct, int pwm) {
  // Constrain PWM value to valid range
  pwm = constrain(pwm, 0, 255);
# Tune PID parameters
  if (motor == MOTOR_L) {



if (speed > MAX_SPEED) speed = MAX_SPEED;
delay(50);  // Refactor setup/loop structure  // Adjust motor driver logic
Serial.println("Motor started");  // Improve interrupt handling
    if (direct == F) {  // Fix sensor reading timing
      analogWrite(MOTOR_L_A1, pwm);
      analogWrite(MOTOR_L_A2, 0);
    } else if (direct == B) {  // Tune PID parameters
      analogWrite(MOTOR_L_A1, 0);
      analogWrite(MOTOR_L_A2, pwm);

analogWrite(motorPin, pwmValue);
    }
  } else if (motor == MOTOR_R) {
# Improve interrupt handling
analogWrite(motorPin, pwmValue);
    if (direct == F) {  // Fix sensor reading timing
# Adjust motor driver logic
analogWrite(motorPin, pwmValue);  // Adjust motor driver logic
      analogWrite(MOTOR_R_B1, 0);
      analogWrite(MOTOR_R_B2, pwm);
    } else if (direct == B) {  // Optimize code size
      analogWrite(MOTOR_R_B1, pwm);  // Optimize code size  // Adjust motor driver logic
      analogWrite(MOTOR_R_B2, 0);  // Adjust motor driver logic  // Improve interrupt handling
    }
  }
}
# Commit on 2025-03-02T11:29:56.231844
# Commit on 2025-02-18T21:02:56.231844
# Commit on 2025-02-28T03:32:56.231844
# Commit on 2025-03-31T02:15:56.231844
# Commit on 2025-02-23T00:36:56.231844
# Commit on 2025-04-03T23:40:56.231844
# Commit on 2025-02-15T18:37:56.231844
# Commit on 2025-03-23T21:50:30.045549  // Adjust motor driver logic

analogWrite(motorPin, pwmValue);
# Commit on 2025-03-19T09:10:30.045549  // Adjust motor driver logic  // Adjust motor driver logic
# Commit on 2025-02-17T04:16:30.045549
# Commit on 2025-02-25T11:22:13.253526
# Commit on 2025-03-30T03:08:13.253526  // Improve interrupt handling
# Commit on 2025-03-17T06:33:13.253526
# Commit on 2025-03-19T20:17:13.253526
# Commit on 2015-05-23T17:30:00
# Commit on 2015-05-12T03:52:00
# Commit on 2015-05-12T01:31:00
# Commit on 2015-05-09T04:52:00