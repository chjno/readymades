int inByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    
    inByte = Serial.read();
    if (inByte == '1'){
      digitalWrite(13, HIGH);
//      tone(13, 750);
      Serial.println('1');
    } else {
      digitalWrite(13, LOW);
//      noTone(13);
      Serial.println('0');
    }
//    Serial.println(inByte);
  }
}
