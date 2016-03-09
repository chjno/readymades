Servo boxServo;

const int boxServoPin = 9;

int boxServoDown = 30;
int boxServoUp = 120;



void boxServoSetup(){
  boxServo.attach(boxServoPin);
  boxServo.write(boxServoDown);
}

void openBox(){
  if (!boxIsOpen){
    boxServo.write(boxServoUp);
    Serial.println("box is open");
    boxIsOpen = true;
    mounting = false;
    delay(1000);
  }
}

void closeBox(){
  if (boxIsOpen){
    delay(1000);
    boxIsOpen = false;
    dismounting = false;
    boxServo.write(boxServoDown);
    delay(15);
    Serial.println("box is closed");
  }
}
