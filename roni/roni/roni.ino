#include <Servo.h>

Servo pizzaServo1;
Servo pizzaServo2;
Servo boxServo1;
Servo boxServo2;

int distPin = A0;
int pizzaServo1Pin = 5;
int pizzaServo2Pin = 6;
int boxServo1Pin = 9;
int boxServo2Pin = 10;

int dist;

// these need calibration
//long startCountTime = 0;
int mountTime = 5000;
int dismountTime = 5000;
int distThreshold = 200;
//int distMin = ;
//int distMax = ;

int pizzaDownVal = ;
int pizzaUpVal = ;

int boxOpenVal = ;
int boxClosedVal = ;

bool boxIsOpen = false;

void setup() {
  Serial.begin(9600);

  pizzaServo1.write(pizzaDownVal);
  pizzaServo2.write(pizzaDownVal);
  boxServo1.write(boxClosedVal);
  boxServo2.write(boxClosedVal);
}

void loop() {

  if (!boxIsOpen){
    mountChecker();
    if (mounting){
      openBox();
    }
  } else {
    dismountChecker();
    sitUpandDown();
    if (dismounting){
      closeBox();
    } 
  } 
  
}

void openBox(){
  if (!boxIsOpen){
    boxServo1.write(boxOpenVal);
    boxServo2.write(boxOpenVal);
    delay(15);
    boxIsOpen = true;
    mounting = false;
  }
}

void closeBox(){
  if (boxIsOpen){
    boxIsOpen = false;
    dismounting = false;
    boxServo1.write(boxClosedVal);
    boxServo2.write(boxClosedVal);
    delay(15);
  }
}

void sitUpandDown(){
  pizzaServo1.write(pizzaUpVal);
  pizzaServo2.write(pizzaUpVal);
  delay(500);
  pizzaServo1.write(pizzaDownVal);
  pizzaServo2.write(pizzaDownVal);
  delay(500);
}

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
  Serial.println(dist);
  delay(1);
}

int mountInterval = 1000;
int mountError = 2;
int mountArrLength = 5
int mountArr[mountArrLength];
int mountArrIndex = 0;
long mountTimer = 0;
int mountCount = 0;
bool mounting = false;

void mountChecker(){
  
  if (mountArrIndex == mountArrLength){
    for (var i = 0; i = mountArrLength; i++){
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

int dismountInterval = 1000;
int dismountError = 2;
int dismountArrLength = 5
int dismountArr[dismountArrLength];
int dismountArrIndex = 0;
long dismountTimer = 0;
int dismountCount = 0;
bool dismounting = false;

void dismountChecker(){
  
  if (dismountArrIndex == dismountArrLength){
    for (var i = 0; i = dismountArrLength; i++){
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
