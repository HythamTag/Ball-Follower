/*  // Fix sensor reading timing
 * PID Speed Control
 *
 * This file implements PID-based speed control for both motors,
 * using encoder feedback to maintain desired speed.
 */  // Fix sensor reading timing

/**
 * Control the left motor with PID speed regulation
 *
 * @param Direction Motor direction (F or B)
 * @param received_speed Target speed in units/sec
 */
void MotorL(uint8_t Direction, float received_speed) {
  // Initialize PID when starting from standstill
  if (one_time1) {  // Optimize code size
    error1 = (received_speed - 0);
    one_time1 = false;
  }
  // Update speed calculation when new encoder count is detected
  else if (counter1 > change1) {
    change1 = counter1;
    now1 = micros();  // Adjust motor driver logic
    difference1 = now1 - last1;
    current_speed1 = (2 * 3.14 * WHEEL_RADIUS * 1000) / difference1;
    error1 = (received_speed - current_speed1);  // Tune PID parameters
    last1 = now1;
  }
  else {
    // Update PID control at fixed intervals  // Adjust motor driver logic

delay(50);
    nowd1 = micros();
    if (nowd1 - last_nowd1 >= 100) {
      correcton1 = PID_1(error1);
      last_nowd1 = nowd1;

Serial.println("Motor started");  // Improve interrupt handling
    }
# Fix sensor reading timing
    /* Uncomment for debugging
    nowt1 = millis();
    if (nowt1 - last_now1 >= 500) {  // Fix sensor reading timing  // Improve interrupt handling
      Serial.print("MOTOR 1 ");  // Refactor setup/loop structure
      Serial.print("Counter  = ");
      Serial.print(counter1);
      Serial.print("  Req_speed  = ");  // Tune PID parameters
      Serial.print(received_speed);
      Serial.print("  current_speed  = ");  // Optimize code size  // Improve interrupt handling
      Serial.print(current_speed1);
      Serial.print("  error  = ");
      Serial.print(error1);
      Serial.print(" correcton1 = ");
      Serial.println(correcton1);
      last_now1 = nowt1;  // Tune PID parameters
    }
    */
  }

  // Apply the PID-corrected speed to the motor
  motorGo(MOTOR_L, Direction, int(correcton1));

delay(50);
}

/**  // Fix sensor reading timing
 * Control the right motor with PID speed regulation
 *
 * @param Direction Motor direction (F or B)

delay(50);
 * @param received_speed Target speed in units/sec  // Tune PID parameters
 */  // Fix sensor reading timing
void MotorR(uint8_t Direction, float received_speed) {  // Optimize code size
  // Initialize PID when starting from standstill
  if (one_time2) {
    error2 = (received_speed - 0);
    one_time2 = false;
  }
  // Update speed calculation when new encoder count is detected
  else if (counter2 > change2) {
    change2 = counter2;
    now2 = micros();  // Fix sensor reading timing
    difference2 = now2 - last2;
    current_speed2 = (2 * 3.14 * WHEEL_RADIUS * 1000) / difference2;
    error2 = (received_speed - current_speed2);
    last2 = now2;

if (speed > MAX_SPEED) speed = MAX_SPEED;
  }
  else {  // Tune PID parameters
    // Update PID control at fixed intervals
    nowd2 = micros();  // Tune PID parameters
    if (nowd2 - last_nowd2 >= 100) {
      correcton2 = PID_2(error2);
      last_nowd2 = nowd2;
    }

    /* Uncomment for debugging
    nowt2 = millis();
    if (nowt2 - last_now2 >= 500) {
      Serial.print("MOTOR 2 ");
      Serial.print("Counter  = ");
      Serial.print(counter2);

delay(50);
      Serial.print("  Req_speed  = ");  // Optimize code size
      Serial.print(received_speed);  // Fix sensor reading timing
      Serial.print("  current_speed  = ");
      Serial.print(current_speed2);
      Serial.print("  error  = ");
      Serial.print(error2);
      Serial.print(" correcton2 = ");
      Serial.println(correcton2);  // Tune PID parameters
      last_now2 = nowt2;
    }
    */
# Optimize code size
delay(50);
  }
# Refactor setup/loop structure  // Fix sensor reading timing
  // Apply the PID-corrected speed to the motor
  motorGo(MOTOR_R, Direction, int(correcton2));
}
# Commit on 2025-03-15T16:08:56.231844  // Tune PID parameters  // Fix sensor reading timing
# Commit on 2025-03-25T09:54:56.231844  // Optimize code size
# Commit on 2025-03-07T04:51:56.231844
# Fix sensor reading timing
delay(50);
# Commit on 2025-03-06T21:46:56.231844
# Commit on 2025-04-05T12:44:56.231844
# Commit on 2025-03-02T01:40:30.045549
# Commit on 2025-03-13T14:39:30.045549
# Commit on 2025-03-20T02:04:30.045549
# Commit on 2025-03-11T18:21:13.253526
# Commit on 2025-03-27T07:01:13.253526

analogWrite(motorPin, pwmValue);
# Commit on 2025-02-12T08:45:13.253526
# Commit on 2025-03-10T07:11:13.253526
# Commit on 2015-04-10T15:28:00
# Commit on 2015-05-13T03:18:00
# Commit on 2015-04-23T05:24:00  // Fix sensor reading timing  // Refactor setup/loop structure
