int distPin = A0;
int dist;
int distThreshold = 200;

int mountInterval = 1000;
int mountError = 2;
const int mountArrLength = 5;
int mountArr[mountArrLength];
int mountArrIndex = 0;
long mountTimer = 0;
int mountCount = 0;
bool mounting = false;
bool mountCountStarted;

void setup() {
  Serial.begin(9600);

}

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total

void getDist() {
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

void loop() {



}


void mountChecker(){
  Serial.println(mountArrIndex);

  if (mountArrIndex == mountArrLength) {
    for (int i = 0; i = mountArrLength; i++) {
      mountCount += mountArr[i];
    }
    Serial.println(mountCount);
    if (mountCount > 3) {
      mounting = true;
      Serial.println("mounting");
    }
    mountCount = 0;
    mountCountStarted = false;
    mountArrIndex = 0;
  }

  if (!mounting) {

    if (dist < distThreshold) {
      if (!mountCountStarted) {
        mountArr[mountArrIndex] = 1;
        mountArrIndex++;
        mountTimer = millis();
        mountCountStarted = true;
      }
    }

    if (mountCountStarted) {
      if (millis() - mountTimer > mountInterval) {
        getDist();
        if (dist < distThreshold) {
          mountArr[mountArrIndex] = 1;
          mountArrIndex++;
          mountTimer = millis();
        } else {
          mountArr[mountArrIndex] = 0;
          mountArrIndex++;
          mountTimer = millis();
        }
//        for (int i = 0; i < 5; i++) {
//          Serial.println(mountArr[i]);
//        }
      }
    }

  }
}
