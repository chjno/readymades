int dismountInterval = 1000;
int dismountError = 2;
const int dismountArrLength = 5;
int dismountArr[dismountArrLength];
int dismountArrIndex = 0;
long dismountTimer = 0;
int dismountCount = 0;
//bool dismounting = false;
bool dismountCountStarted = false;

void dismountChecker() {

//  Serial.println("checking dismount");

  if (dismountArrIndex == dismountArrLength) {
    for (int i = 0; i < dismountArrLength; i++) {
      dismountCount += dismountArr[i];
    }
    if (dismountCount > 3) {
      dismounting = true;
      Serial.println("dismounting");
    }
    dismountCount = 0;
    dismountCountStarted = false;
    dismountArrIndex = 0;
  }

  if (!dismounting) {
    dist = getDist();
    if (dist < distThreshold && !dismountCountStarted) {
      dismountTimer = millis();
      dismountCountStarted = true;
    }

    if (dismountCountStarted) {
      if (millis() - dismountTimer > dismountInterval) {
        dist = getDist();
        Serial.println(dist);
        if (dist < distThreshold) {
          dismountArr[dismountArrIndex] = 1;
        } else {
          dismountArr[dismountArrIndex] = 0;
        }
        dismountArrIndex++;
        dismountTimer = millis();
      }
    }

  }
}
