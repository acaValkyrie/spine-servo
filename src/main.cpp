#include <Arduino.h>
#include <Servo.h>

const int servo_num = 4;
Servo servos[servo_num];

void all_servo_write(int angle) {
  for(int i = 0; i < servo_num; i++) {
    servos[i].write(angle);
  }
}

void setup() {
  const int servo_pins[servo_num] = {2, 3, 4, 5};
  
  for(int i = 0; i < servo_num; i++) {
    servos[i].attach(servo_pins[i], 500, 2400);
  }
  
  all_servo_write(0);
  delay(1000);
}


void loop() {
  const unsigned long delay_time_ms = 0.05 * 1000UL;
  const int angle_min = 0;
  const int angle_max = 180;
  const int delta_angle = 10;

  for (int angle = angle_min; angle <= angle_max; angle+=delta_angle) {
    all_servo_write(angle);
    delay(delay_time_ms);
  }
}
