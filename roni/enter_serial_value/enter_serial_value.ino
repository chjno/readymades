void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()){
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 180){
      pizzaServo1.write(speed + 20);
      pizzaServo2.write(speed);
      delay(15);
    }
  }

}
