int LED1pin = 43;
int LED2pin = 44;
int LED3pin = 45;
int LED4pin = 46;

int button1pin = 40; 
int button2pin = 41; 

bool systemOn = false;
int mode = 1;

int previousButton1 = HIGH;
int previousButton2 = HIGH;

void setup() {

  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);

  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);

  allLEDsOff();
}

void loop() {

  checkButtons();

  if (!systemOn) {
    allLEDsOff();
    return;
  }

  if (mode == 1) {
    mode1();
  }

  else if (mode == 2) {
    mode2();
  }

  else if (mode == 3) {
    mode3();
  }
}

void checkButtons() {

  int button1State = digitalRead(button1pin);
  int button2State = digitalRead(button2pin);

  
  if (button1State == LOW && previousButton1 == HIGH) {

    systemOn = !systemOn;

    delay(150);
  }

 
  if (button2State == LOW && previousButton2 == HIGH) {

    mode++;

    if (mode > 3) {
      mode = 1;
    }

    delay(150);
  }

  previousButton1 = button1State;
  previousButton2 = button2State;
}

void allLEDsOff() {

  digitalWrite(LED1pin, LOW);
  digitalWrite(LED2pin, LOW);
  digitalWrite(LED3pin, LOW);
  digitalWrite(LED4pin, LOW);
}

void mode1() {

  digitalWrite(LED1pin, HIGH);
  digitalWrite(LED2pin, HIGH);
  digitalWrite(LED3pin, HIGH);
  digitalWrite(LED4pin, HIGH);

  waitWithButtonCheck(1000);

  allLEDsOff();

  waitWithButtonCheck(1000);
}

void mode2() {

  allLEDsOff();

  digitalWrite(LED1pin, HIGH);
  waitWithButtonCheck(1000);

  digitalWrite(LED2pin, HIGH);
  waitWithButtonCheck(1000);

  digitalWrite(LED3pin, HIGH);
  waitWithButtonCheck(1000);

  digitalWrite(LED4pin, HIGH);
  waitWithButtonCheck(1000);

  allLEDsOff();
}

void mode3() {

  allLEDsOff();

  digitalWrite(LED4pin, HIGH);
  waitWithButtonCheck(1000);

  digitalWrite(LED3pin, HIGH);
  waitWithButtonCheck(1000);

  digitalWrite(LED2pin, HIGH);
  waitWithButtonCheck(1000);

  digitalWrite(LED1pin, HIGH);
  waitWithButtonCheck(1000);

  allLEDsOff();
}

void waitWithButtonCheck(int timeMs) {

  int stepTime = 50;

  for (int i = 0; i < timeMs / stepTime; i++) {

    checkButtons();

    if (!systemOn) {
      allLEDsOff();
      return;
    }

    delay(stepTime);
  }
}
