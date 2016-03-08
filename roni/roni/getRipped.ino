Servo pizzaServo1;
Servo pizzaServo2;

int pizzaPause = 750;
long pizzaCounter = 0;
bool pizzaDown = true;

int pizzaServo1up = 60;
int pizzaServo2up = pizzaServo1up - 20;
int pizzaServo1down = 110;
int pizzaServo2down = pizzaServo1down - 20;

void getRipped(){

  if (millis() - pizzaCounter > pizzaPause){
    if (pizzaDown){
      sitUp();
    } else {
      sitDown();
    }
    pizzaCounter = millis();
  }

}

void sitUp(){
  pizzaServo1.write(pizzaServo1up);
  pizzaServo2.write(pizzaServo2up);
  pizzaDown = false;
  Serial.println("sitting up");
}

void sitDown(){
  pizzaServo1.write(pizzaServo1down);
  pizzaServo2.write(pizzaServo2down);
  pizzaDown = true;
  Serial.println("sitting down");
}


//void getRipped(){
//  pizzaServo1.write(pizzaServo1up);
//  pizzaServo2.write(pizzaServo2up);
////  Serial.println("pizza up");
//  delay(750);
//  pizzaServo1.write(pizzaServo1down);
//  pizzaServo2.write(pizzaServo2down);
////  Serial.println("pizza down");
//  delay(750);
//}

