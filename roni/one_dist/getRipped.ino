Servo pizzaServo1;
Servo pizzaServo2;

const int pizzaServo1Pin = 5;
const int pizzaServo2Pin = 6;

int pizzaPause = 750;
long pizzaCounter = 0;
bool pizzaDown = true;

int pizzaServo1up = 60;
int pizzaServo2up = pizzaServo1up - 20;
int pizzaServo1down = 110;
int pizzaServo2down = pizzaServo1down - 20;

void pizzaServoSetup(){
  pizzaServo1.attach(pizzaServo1Pin);
  pizzaServo2.attach(pizzaServo2Pin);
  pizzaServo1.write(pizzaServo1down);
  pizzaServo2.write(pizzaServo2down);
}

void getRipped(){

  if (pizzaDown){
    if (intercept){
      sitUp();
      pizzaCounter = millis();
    }
  } else {
    if (millis() - pizzaCounter > pizzaPause){
      sitDown();
    }
  }
}

void sitUp(){
//  int count;
//  for (int i = 0; i < 10; i++){
//    count = count + 5;
//    pizzaServo1.write(pizzaServo1down - count);
//    pizzaServo2.write(pizzaServo2down - count);
//    delay(50);
//  }
//  count = 0;

  
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

