#include <Servo.h>

Servo pizzaServo1;

void setup() {
  Serial.begin(9600);
  pizzaServo1.attach(9);
  pizzaServo1.write(50);
}

void loop() {
  if (Serial.available()){
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 180){
      pizzaServo1.write(speed);
      delay(15);
    }
  }

}
