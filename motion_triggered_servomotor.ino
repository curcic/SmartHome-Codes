#include <Servo.h>
const int MOTION_SENSOR_PIN = 7;
const int SERVO_PIN = 9;

Servo servo_object;
int angle = 0;
int last_state;
int current_state;

void setup() {
  Serial.begin(9600);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  servo_object.attach(SERVO_PIN);
  servo_object.write(angle);
  current_state = digitalRead(MOTION_SENSOR_PIN);
}

void loop() {
  last_state = current_state;
  current_state = digitalRead(MOTION_SENSOR_PIN);
  if (current_state == LOW && last_state == HIGH) {
    Serial.println("Motion not detected!");
    servo_object.write(0);
  }
  else if (current_state == HIGH && last_state == LOW) {
    Serial.println("Motion detected!");
    servo_object.write(90);
  }
}