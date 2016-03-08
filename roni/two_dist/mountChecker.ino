int mountInterval = 1000;
int mountError = 2;
const int mountArrLength = 5;
int mountArr[mountArrLength];
int mountArrIndex = 0;
long mountTimer = 0;
int mountCount = 0;
//bool mounting = false;
bool mountCountStarted = false;

void mountChecker() {

//  Serial.println("checking mount");

  if (mountArrIndex == mountArrLength) {
    for (int i = 0; i < mountArrLength; i++) {
      mountCount += mountArr[i];
    }
    if (mountCount > 3) {
      mounting = true;
      Serial.println("mounting");
    }
    mountCount = 0;
    mountCountStarted = false;
    mountArrIndex = 0;
  }

  if (!mounting) {
    dist = getDist();
    if (dist > distThreshold && !mountCountStarted) {
      mountTimer = millis();
      mountCountStarted = true;
    }

    if (mountCountStarted) {
      if (millis() - mountTimer > mountInterval) {
        dist = getDist();
        Serial.println(dist);
        if (dist > distThreshold) {
          mountArr[mountArrIndex] = 1;
        } else {
          mountArr[mountArrIndex] = 0;
        }
        mountArrIndex++;
        mountTimer = millis();
      }
    }

  }
}
