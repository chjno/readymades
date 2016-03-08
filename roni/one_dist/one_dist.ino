#include <Servo.h>

int distPin = A0;
int dist;
int distThreshold = 200;

bool mounted = false;
bool dismounting = false;
bool intercept = false;

bool boxIsOpen = false;

void setup() {
  Serial.begin(9600);

  boxServoSetup();
  pizzaServoSetup();
}

void loop() {

  mountChecker();
    
  if (mounted) {
    if (!boxIsOpen){
      openBox();
    }
    getRipped();
  } else {
    if (boxIsOpen){
      sitDown();
      closeBox();
    }
  }

}
