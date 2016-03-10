#include <Servo.h>

//int distPin = A0;
int dist;
int distThreshold = 10;

int sitDist;
int sitDistThreshold = 150;

bool mounting = false;
bool dismounting = false;

bool boxIsOpen = false;

void setup() {
  Serial.begin(9600);

  boxServoSetup();
  pizzaServoSetup();
}

void loop() {

  if (!boxIsOpen) {
    mountChecker();
    if (mounting) {
      openBox();
    }
  } else {
    dismountChecker();
    if (dismounting) {
      sitDown();
      closeBox();
    } else {
      getRipped();
    }
  }

}
