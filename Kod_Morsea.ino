#include <LiquidCrystal.h>

const int ledPin = 7;
const int buzzerPin = 13;
const int buttonPin = 8;
const int longSignalTime = 500;   // Duration of a long signal in milliseconds
const int shortSignalTime = 200;  // Duration of a short signal in milliseconds
const int pauseTime = 100;   // Duration of a pause in milliseconds

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int characterNumber = 0; 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Zagatka z kodem");
  lcd.setCursor(0, 1);
  lcd.print("Morse'a");
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    // when button is not pressed do nothing
    return;
  }

  // When button is pressed then:
  
  if (characterNumber == 0) {
    // First letter: S (three short signals)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Litera nr:");
    lcd.setCursor(0, 1);
    lcd.print("1");
    shortSignal();
    shortSignal();
    shortSignal();
    characterNumber++;
  }
  else if (characterNumber == 1) {
    // Second letter: O (three long signals)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Litera nr:");
    lcd.setCursor(0, 1);
    lcd.print("2");
    longSignal();
    longSignal();
    longSignal();
    characterNumber++;
  }
  else if (characterNumber == 2) {
    // third letter: S (three short signals)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Litera nr:");
    lcd.setCursor(0, 1);
    lcd.print("1");
    shortSignal();
    shortSignal();
    shortSignal();
    characterNumber++;
  }
  else if (characterNumber == 3) {
    characterNumber = 0;
  }
  
  // Small delay to debounce the button
  delay(50);
}

void longSignal()
{
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(longSignalTime);
  przerywnik();
}

void shortSignal()
{
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(shortSignalTime);
  przerywnik();
}

void przerywnik()
{
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
  delay(pauseTime);
}
