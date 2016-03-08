#include <Servo.h>

Servo pizzaServo1;
Servo pizzaServo2;
Servo boxServo;

int distPin = A0;
int dist;

// these need calibration
//long startCountTime = 0;
int mountTime = 5000;
int dismountTime = 5000;
int distThreshold = 200;
//int distMin = ;
//int distMax = ;

int pizzaServo1up = 60;
int pizzaServo2up = pizzaServo1up - 20;
int pizzaServo1down = 110;
int pizzaServo2down = pizzaServo1down - 20;
int boxServoDown = 50;
int boxServoUp = 150;

bool boxIsOpen = false;

int mountInterval = 1000;
int mountError = 2;
int mountArrLength = 5;
int mountArr[5];
int mountArrIndex = 0;
long mountTimer = 0;
int mountCount = 0;
bool mounting = false;
bool mountCountStarted;

int dismountInterval = 1000;
int dismountError = 2;
int dismountArrLength = 5;
int dismountArr[5];
int dismountArrIndex = 0;
long dismountTimer = 0;
int dismountCount = 0;
bool dismounting = false;
bool dismountCountStarted;

void setup() {
  Serial.begin(9600);

  pizzaServo1.attach(5);
  pizzaServo2.attach(6);
  boxServo.attach(10);
  
  pizzaServo1.write(pizzaServo1down);
  pizzaServo2.write(pizzaServo2down);
  boxServo.write(boxServoDown);
}

void loop() {

  if (!boxIsOpen){
    mountChecker();
    if (mounting){
      openBox();
    }
  } else {
    dismountChecker();
    getRipped();
    if (dismounting){
      closeBox();
    } 
  } 
  
}

void openBox(){
  if (!boxIsOpen){
    boxServo.write(boxServoUp);
    delay(1000);
    boxIsOpen = true;
    mounting = false;
  }
}

void closeBox(){
  if (boxIsOpen){
    boxIsOpen = false;
    dismounting = false;
    boxServo.write(boxServoDown);
    delay(15);
  }
}

void getRipped(){
  pizzaServo1.write(pizzaServo1up);
  pizzaServo2.write(pizzaServo2up);
  delay(750);
  pizzaServo1.write(pizzaServo1down);
  pizzaServo2.write(pizzaServo2down);
  delay(750);
}

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
//int average = 0;                // the average

void getDist(){
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(distPin);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  dist = total / numReadings;
//  Serial.println(dist);
  delay(1);
}



void mountChecker(){
  
  if (mountArrIndex == mountArrLength){
    for (int i = 0; i = mountArrLength; i++){
      mountCount += mountArr[i];
    }
    if (mountCount > mountArrLength - mountError){
      mounting = true;
    }
    mountCount = 0;
    mountCountStarted = false;
    mountArrIndex = 0;
  }

  if (!mounting){

    if (dist < distThreshold){
      if (!mountCountStarted){
        mountArr[mountArrIndex] = 1;
        mountArrIndex++;
        mountTimer = millis();
        mountCountStarted = true;
      }
    }
  
    if (mountCountStarted){
      if (millis() - mountTimer > mountInterval){
        getDist();
        if (dist < distThreshold){
          mountArr[mountArrIndex] = 1;
          mountArrIndex++;
          mountTimer = millis();
        } else {
          mountArr[mountArrIndex] = 0;
          mountArrIndex++;
          mountTimer = millis();
        }
      }
    }
    
  }
  
}

void dismountChecker(){
  
  if (dismountArrIndex == dismountArrLength){
    for (int i = 0; i = dismountArrLength; i++){
      dismountCount += dismountArr[i];
    }
    if (dismountCount > dismountArrLength - dismountError){
      dismounting = true;
    }
    dismountCount = 0;
    dismountCountStarted = false;
    dismountArrIndex = 0;
  }

  if (!dismounting){

    if (dist < distThreshold){
      if (!dismountCountStarted){
        dismountArr[dismountArrIndex] = 1;
        dismountArrIndex++;
        dismountTimer = millis();
        dismountCountStarted = true;
      }
    }
  
    if (dismountCountStarted){
      if (millis() - dismountTimer > dismountInterval){
        getDist();
        if (dist < distThreshold){
          dismountArr[dismountArrIndex] = 1;
          dismountArrIndex++;
          dismountTimer = millis();
        } else {
          dismountArr[dismountArrIndex] = 0;
          dismountArrIndex++;
          dismountTimer = millis();
        }
      }
    }
    
  }
  
}
