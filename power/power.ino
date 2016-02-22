int started = 0;
bool power = false;
bool on1 = false;
bool on2 = false;
bool on3 = false;
bool on4 = false;
bool on5 = false;
bool on6 = false;
bool on7 = false;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}

void loop() {
  if(Serial.available()) {
    Serial.read();
    started = 1;
  };
  
  if (started) {
    int s0 = digitalRead(13);
    int s1 = analogRead(A1); // 15
    int s2 = analogRead(A2); // 10
    int s3 = analogRead(A3); // 20
    int s4 = analogRead(A4); // 10
    int s5 = analogRead(A5); // 15
    int s6 = analogRead(A6); // 15
    int s7 = analogRead(A7); // 20

//    Serial.println(s6);

    if (!s0) {
      if (power) {
        Serial.print('0');
        Serial.print(' ');
        Serial.println('0');
        digitalWrite(12, LOW);
        power = false;
      }
    } else {
      if (!power) {
        Serial.print('1');
        Serial.print(' ');
        Serial.println('0');
        digitalWrite(12, HIGH);
        power = true;
      }
    };

    if (power) {
      if (on1) {
        if (s1 < 100) {
          Serial.print('0');
          Serial.print(' ');
          Serial.println('1');
          delay(10);
          on1 = false;
        }
      } else {
        if (s1 > 100) {
          Serial.print('1');
          Serial.print(' ');
          Serial.println('1');
          delay(10);
          on1 = true;
        }
      };
      if (on2) {  
        if (s2 < 100) {
          Serial.print('0');
          Serial.print(' ');
          Serial.println('2');
          delay(10);
          on2 = false;
        }
      } else {
        if (s2 > 100) {
          Serial.print('1');
          Serial.print(' ');
          Serial.println('2');
          delay(10);
          on2 = true;
        }
      };
      if (on3) {
        if (s3 < 100) {
          Serial.print('0');
          Serial.print(' ');
          Serial.println('3');
          delay(10);
          on3 = false;
        }
      } else {
        if (s3 > 100) {
          Serial.print('1');
          Serial.print(' ');
          Serial.println('3');
          delay(10);
          on3 = true;
        }
      };
      if (on4) {
        if (s4 < 100) {
          Serial.print('0');
          Serial.print(' ');
          Serial.println('4');
          delay(10);
          on4 = false;
        }
      } else {
        if (s4 > 100) {
          Serial.print('1');
          Serial.print(' ');
          Serial.println('4');
          delay(10);
          on4 = true;
        }
      };
      if (on5) {
        if (s5 < 100) {
          Serial.print('0');
          Serial.print(' ');
          Serial.println('5');
          delay(10);
          on5 = false;
        }
      } else {
        if (s5 > 100) {
          Serial.print('1');
          Serial.print(' ');
          Serial.println('5');
          delay(10);
          on5 = true;
        }
      };
      if (on6) {
        if (s6 < 50) {
          Serial.print('0');
          Serial.print(' ');
          Serial.println('6');
          delay(10);
          on6 = false;
        }
      } else {
        if (s6 > 50) {
          Serial.print('1');
          Serial.print(' ');
          Serial.println('6');
          delay(10);
          on6 = true;
        }
      };
      if (on7) {
        if (s7 < 100) {
          Serial.print('0');
          Serial.print(' ');
          Serial.println('7');
          delay(10);
          on7 = false;
        }
      } else {
        if (s7 > 100) {
          Serial.print('1');
          Serial.print(' ');
          Serial.println('7');
          delay(10);
          on7 = true;
        }
      };
    };
  };
}
