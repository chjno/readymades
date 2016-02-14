int started = 0;
bool on0 = false;
bool on1 = false;
bool on2 = false;
bool on3 = false;
bool on4 = false;
bool on5 = false;
bool on6 = false;
bool on7 = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    Serial.read();
    started = 1;
  };
  
  if (started) {
    int s0 = digitalRead(13);
    int s1 = analogRead(A1);
    int s2 = analogRead(A2);
    int s3 = analogRead(A3);
    int s4 = analogRead(A4);
    int s5 = analogRead(A5);
    int s6 = analogRead(A6);
    int s7 = analogRead(A7);

//    Serial.println(s1);

    if (!s0) {
      if (on0) {
        Serial.print('0');
        Serial.print(' ');
        Serial.println('0');
        on0 = false;
      }
    } else {
      if (!on0) {
        Serial.print('0');
        Serial.print(' ');
        Serial.println('1');
        on0 = true;
      }
    };
    if (s1 < 100) {
      if (on1) {
        Serial.print('1');
        Serial.print(' ');
        Serial.println('0');
        on1 = false;
      }
    } else {
      if (!on1) {
        Serial.print('1');
        Serial.print(' ');
        Serial.println('1');
        on1 = true;
      }
    };
    if (s2 < 100) {
      if (on2) {
        Serial.print('2');
        Serial.print(' ');
        Serial.println('0');
        on2 = false;
      }
    } else {
      if (!on2) {
        Serial.print('2');
        Serial.print(' ');
        Serial.println('1');
        on2 = true;
      }
    };
    if (s3 < 100) {
      if (on3) {
        Serial.print('3');
        Serial.print(' ');
        Serial.println('0');
        on3 = false;
      }
    } else {
      if (!on3) {
        Serial.print('3');
        Serial.print(' ');
        Serial.println('1');
        on3 = true;
      }
    };
    if (s4 < 100) {
      if (on4) {
        Serial.print('4');
        Serial.print(' ');
        Serial.println('0');
        on4 = false;
      }
    } else {
      if (!on4) {
        Serial.print('4');
        Serial.print(' ');
        Serial.println('1');
        on4 = true;
      }
    };
    if (s5 < 100) {
      if (on5) {
        Serial.print('5');
        Serial.print(' ');
        Serial.println('0');
        on5 = false;
      }
    } else {
      if (!on5) {
        Serial.print('5');
        Serial.print(' ');
        Serial.println('1');
        on5 = true;
      }
    };
    if (s6 < 100) {
      if (on6) {
        Serial.print('6');
        Serial.print(' ');
        Serial.println('0');
        on6 = false;
      }
    } else {
      if (!on6) {
        Serial.print('6');
        Serial.print(' ');
        Serial.println('1');
        on6 = true;
      }
    };
    if (s7 < 100) {
      if (on7) {
        Serial.print('7');
        Serial.print(' ');
        Serial.println('0');
        on7 = false;
      }
    } else {
      if (!on7) {
      Serial.print('7');
      Serial.print(' ');
      Serial.println('1');
      on7 = true;
      }
    };
  }
}
