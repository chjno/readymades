int mountInterval = 5000;
int mountError = 2;
const int mountArrLength = 5;
int mountArr[mountArrLength];
int mountArrIndex = 0;
long mountTimer = 0;
int mountCount = 0;
//bool mounted = false;
bool mountCountStarted = false;

int revvingUp = 0;

void mountChecker() {

  //  Serial.println("checking mount");


  if (revvingUp >= 3) {
    mounted = true;
//    Serial.println("mounted");
  }

  if (millis() - mountTimer > mountInterval) {
    if (revvingUp < 3){
      mounted = false;
      Serial.println("unmounted");
    }
    revvingUp = 0;
    intercept = false;
    mountCountStarted = false;
    mountTimer = millis();
//    Serial.println("resetting mount checker");
  }

  dist = getDist();
  if (!intercept) {
    if (dist > distThreshold) {
      intercept = true;
//      Serial.println("up");
      revvingUp++;

      if (!mountCountStarted) {
        mountTimer = millis();
        mountCountStarted = true;
      }
    }
  } else {
    if (dist < distThreshold) {
      intercept = false;
//      Serial.println("down");
    }
  }


}
