#include <Servo.h>

Servo pizzaServo1;
Servo pizzaServo2;
Servo boxServo2;
Servo boxServo1;

int distPin = A0;
int dist;

bool start = false;
int pizzaServo1up = 60;
int pizzaServo2up = pizzaServo1up - 20;
int pizzaServo1down = 110;
int pizzaServo2down = pizzaServo1down - 20;
int boxServo2down = 50;
int boxServo2up = 150;

int count = 0;

void setup() {
  Serial.begin(9600);
  pizzaServo1.attach(5);  // attaches the servo on pin 9 to the servo object
  pizzaServo2.attach(6);
  boxServo2.attach(10);
  
  pizzaServo1.write(pizzaServo1down);
  pizzaServo2.write(pizzaServo2down);
  boxServo2.write(boxServo2down);
}

void loop(){


  
  if (Serial.available()){
    Serial.read();
    start = !start;
  }

  if (start){
//    pizzaServo1.write(pizzaServo1up);
//    pizzaServo2.write(pizzaServo2up);

    dist = analogRead(distPin);
//    Serial.println(dist);

    if (dist > 300){
      dist = map(dist,100,300,110,60);
      pizzaServo1.write(pizzaServo1up);
      pizzaServo2.write(pizzaServo2up);

//    for (int i = 0; i < 50; i++){
//      count++;
//      pizzaServo1.write(pizzaServo1down - count);
//      pizzaServo2.write(pizzaServo2down - count);
//      delay(50);
//    }
//    count = 0;

      delay(750);
      pizzaServo1.write(pizzaServo1down);
      pizzaServo2.write(pizzaServo2down);
      delay(750);
    }
  
  }
}

