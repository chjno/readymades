Servo boxServo;

const int boxServoPin = 3;

int boxServoDown = 50;
int boxServoUp = 150;



void boxServoSetup(){
  boxServo.attach(boxServoPin);
  boxServo.write(boxServoDown);
}

void openBox(){
  if (!boxIsOpen){
    boxServo.write(boxServoUp);
    Serial.println("box is open");
    boxIsOpen = true;
    mounted = false;
    delay(1000);
  }
}

void closeBox(){
  if (boxIsOpen){
    delay(1000);
    boxIsOpen = false;
    mounted = false;
    boxServo.write(boxServoDown);
    delay(15);
    Serial.println("box is closed");
  }
}
