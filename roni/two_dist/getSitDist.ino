int sitDistPin = A1;

const int numSitReadings = 10;
int sitReadings[numSitReadings];
int sitReadIndex = 0;
int sitTotal = 0;

int getSitDist() {
  sitTotal = sitTotal - sitReadings[sitReadIndex];
  sitReadings[sitReadIndex] = analogRead(sitDistPin);
  sitTotal = sitTotal + sitReadings[sitReadIndex];
  sitReadIndex = sitReadIndex + 1;

  if (sitReadIndex >= numSitReadings) {
    sitReadIndex = 0;
  }

  int sitDist = sitTotal / numSitReadings;
  return sitDist;
  delay(1);
}


//int getSitDist() {
//  for (int i = 0; i < numSitReadings; i++){
//    sitTotal = analogRead(sitDistPin);
//  }
//  int sitDist = sitTotal / numSitReadings;
//  return sitDist;
//}
