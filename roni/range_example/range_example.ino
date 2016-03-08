const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;

int trig = 9;
int echo = 10;

void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  getRange();
//  getDist();
}

int getRange(){
  long duration;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);

  Serial.println(duration);
  delay(100);
  return duration;
}

int getDist() {
  total = total - readings[readIndex];
  readings[readIndex] = getRange();
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  int dist = total / numReadings;
  return dist;
  Serial.println(dist);
  delay(1);
}
