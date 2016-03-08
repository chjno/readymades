const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;

int getDist() {
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(distPin);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  int dist = total / numReadings;
  return dist;
  delay(1);
}
