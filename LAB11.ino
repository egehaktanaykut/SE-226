#include <LiquidCrystal.h>

// LCD initialization (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(36, 37, 26, 27, 28, 29);

// 7-segment segment pins
int aPin = 2;
int bPin = 3;
int cPin = 4;
int dPin = 5;
int ePin = 6;
int fPin = 7;
int gPin = 8;
int dP   = 9;

// Digit/GND pins
int GND1 = 10; // rightmost digit
int GND2 = 11;
int GND3 = 12;
int GND4 = 13; // leftmost digit

int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

unsigned long lastCountTime = 0;

// Segment ON/OFF durumları
// Eğer sayılar ters/yanlış çıkarsa HIGH-LOW yer değiştir.
int SEG_ON = HIGH;
int SEG_OFF = LOW;

int DIGIT_ON = HIGH;
int DIGIT_OFF = LOW;

void setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dP, OUTPUT);

  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);

  digitalWrite(GND1, DIGIT_OFF);
  digitalWrite(GND2, DIGIT_OFF);
  digitalWrite(GND3, DIGIT_OFF);
  digitalWrite(GND4, DIGIT_OFF);

  lcd.begin(16, 2);
  lcd.print("Counter:");
}

void loop() {
  // 1 saniyede bir sayı artır
  if (millis() - lastCountTime >= 1000) {
    lastCountTime = millis();
    incrementCounter();
    updateLCD();
  }

  // 7 segment sürekli hızlı yenilenmeli
  display4Digits();
}

void incrementCounter() {
  dig1++;

  if (dig1 >= 10) {
    dig1 = 0;
    dig2++;
  }

  if (dig2 >= 10) {
    dig2 = 0;
    dig3++;
  }

  if (dig3 >= 10) {
    dig3 = 0;
    dig4++;
  }

  if (dig4 >= 10) {
    dig4 = 0;
  }
}

void display4Digits() {
  showDigit(dig1, GND1);
  showDigit(dig2, GND2);
  showDigit(dig3, GND3);
  showDigit(dig4, GND4);
}

void showDigit(int number, int digitPin) {
  turnOffDigits();
  displayNumber(number);

  digitalWrite(digitPin, DIGIT_ON);
  delay(4);
  digitalWrite(digitPin, DIGIT_OFF);
}

void turnOffDigits() {
  digitalWrite(GND1, DIGIT_OFF);
  digitalWrite(GND2, DIGIT_OFF);
  digitalWrite(GND3, DIGIT_OFF);
  digitalWrite(GND4, DIGIT_OFF);
}

void displayNumber(int number) {
  digitalWrite(dP, SEG_OFF);

  switch (number) {
    case 0:
      setSegments(1,1,1,1,1,1,0);
      break;
    case 1:
      setSegments(0,1,1,0,0,0,0);
      break;
    case 2:
      setSegments(1,1,0,1,1,0,1);
      break;
    case 3:
      setSegments(1,1,1,1,0,0,1);
      break;
    case 4:
      setSegments(0,1,1,0,0,1,1);
      break;
    case 5:
      setSegments(1,0,1,1,0,1,1);
      break;
    case 6:
      setSegments(1,0,1,1,1,1,1);
      break;
    case 7:
      setSegments(1,1,1,0,0,0,0);
      break;
    case 8:
      setSegments(1,1,1,1,1,1,1);
      break;
    case 9:
      setSegments(1,1,1,1,0,1,1);
      break;
  }
}

void setSegments(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(aPin, a ? SEG_ON : SEG_OFF);
  digitalWrite(bPin, b ? SEG_ON : SEG_OFF);
  digitalWrite(cPin, c ? SEG_ON : SEG_OFF);
  digitalWrite(dPin, d ? SEG_ON : SEG_OFF);
  digitalWrite(ePin, e ? SEG_ON : SEG_OFF);
  digitalWrite(fPin, f ? SEG_ON : SEG_OFF);
  digitalWrite(gPin, g ? SEG_ON : SEG_OFF);
}

void updateLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Counter: ");
  lcd.print(dig4);
  lcd.print(dig3);
  lcd.print(dig2);
  lcd.print(dig1);
  lcd.print(" ");
}
