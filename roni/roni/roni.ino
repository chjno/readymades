#include <Servo.h>

int distPin = A0;
int dist;
int distThreshold = 200;

bool mounting = false;
bool dismounting = false;

bool boxIsOpen = false;

void setup() {
  Serial.begin(9600);

  boxServoSetup();
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
