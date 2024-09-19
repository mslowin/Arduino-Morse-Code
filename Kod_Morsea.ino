#include <LiquidCrystal.h>

const int resetPin = A0;
const int ledPin = 7;
const int buzzerPin = 13;
const int nextCharacterButtonPin = 8;
const int repeatButtonPin = A5;
const int previousCharacterButtonPin = A4;
const int longSignalTime = 900;   // Duration of a long signal in milliseconds
const int shortSignalTime = 400;  // Duration of a short signal in milliseconds
const int pauseTime = 250;   // Duration of a pause in milliseconds

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int characterNumber = 1; 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Zagatka z kodem");
  lcd.setCursor(0, 1);
  lcd.print("Morse'a");

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(nextCharacterButtonPin, INPUT_PULLUP);
  pinMode(repeatButtonPin, INPUT_PULLUP);
  pinMode(previousCharacterButtonPin, INPUT_PULLUP);
}

void loop() {
  int nextCharacterButtonState = digitalRead(nextCharacterButtonPin);
  int repeatButtonState = digitalRead(repeatButtonPin);
  int previousCharacterButtonState = digitalRead(previousCharacterButtonPin);

  bool wasRepeatOrPreviousButtonPressed = false;

  if (repeatButtonState == LOW)
  {
    // when repeat button is pressed
    characterNumber = GoBackOneLetter(characterNumber);
    LcdWriteCharacterNumber(characterNumber);
    wasRepeatOrPreviousButtonPressed = true;
    delay(200);
  }
  
  if (previousCharacterButtonState == LOW)
  {
    // when previous button is pressed
    characterNumber = GoBackOneLetter(characterNumber);
    characterNumber = GoBackOneLetter(characterNumber);
    LcdWriteCharacterNumber(characterNumber);
    wasRepeatOrPreviousButtonPressed = true;
    delay(200);
  }
  
  if (nextCharacterButtonState == HIGH)
  {
    if (wasRepeatOrPreviousButtonPressed == false) {
      // when button is not pressed do nothing
      return;
    }
    else {
      wasRepeatOrPreviousButtonPressed = true;
    }
  }

  // When button is pressed then:
  if (characterNumber == 1) {
    LcdWriteCharacterNumber(characterNumber);
    E_letter();
    characterNumber++;
  }
  else if (characterNumber == 2) {
    LcdWriteCharacterNumber(characterNumber);
    I_letter();
    characterNumber++;
  }
  else if (characterNumber == 3) {
    LcdWriteCharacterNumber(characterNumber);
    C_letter();
    characterNumber++;
  }
  else if (characterNumber == 4) {
    LcdWriteCharacterNumber(characterNumber);
    M_letter();
    characterNumber++;
  }
  else if (characterNumber == 5) {
    LcdWriteCharacterNumber(characterNumber);
    A_letter();
    characterNumber++;
  }
  else if (characterNumber == 6) {
    LcdWriteCharacterNumber(characterNumber);
    H_letter();
    characterNumber++;
  }
  else if (characterNumber == 7) {
    LcdWriteCharacterNumber(characterNumber);
    C_letter();
    characterNumber++;
  }
  else if (characterNumber == 8) {
    LcdWriteCharacterNumber(characterNumber);
    O_letter();
    characterNumber++;
  }
  else if (characterNumber == 9) {
    LcdWriteCharacterNumber(characterNumber);
    K_letter();
    characterNumber++;
  }
  else if (characterNumber == 10) {
    LcdWriteCharacterNumber(characterNumber);
    O_letter();
    characterNumber++;
  }
  else if (characterNumber == 11) {
    LcdWriteCharacterNumber(characterNumber);
    D_letter();
    characterNumber++;
  }
  else if (characterNumber == 12) {
    LcdWriteCharacterNumber(characterNumber);
    T_letter();
    characterNumber++;
  }
  else if (characterNumber == 13) {
    LcdWriteCharacterNumber(characterNumber);
    Y_letter();
    characterNumber++;
  }
  else if (characterNumber == 14) {
    LcdWriteCharacterNumber(characterNumber);
    L_letter();
    characterNumber++;
  }
  else if (characterNumber == 15) {
    LcdWriteCharacterNumber(characterNumber);
    U_letter();
    characterNumber++;
  }
  else if (characterNumber == 16) {
    characterNumber = 0;
  }

  delay(50); // Small delay to debounce the button
}

void LcdWriteCharacterNumber(int number)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Litera nr:");
  lcd.setCursor(0, 1);
  lcd.print(number);
}

int GoBackOneLetter(int characterNumber)
{
  if (characterNumber == 1){
    return characterNumber;
  }
  else{
    characterNumber--;  
  }

  return characterNumber;
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

void A_letter()
{
  shortSignal();
  longSignal();
}

void B_letter()
{
  longSignal();
  shortSignal();
  shortSignal();
  shortSignal();
}

void C_letter()
{
  longSignal();
  shortSignal();
  longSignal();
  shortSignal();
}

void D_letter()
{
  longSignal();
  shortSignal();
  shortSignal();
}

void E_letter()
{
  shortSignal();
}

void F_letter()
{
  shortSignal();
  shortSignal();
  longSignal();
  shortSignal();
}

void G_letter()
{
  longSignal();
  longSignal();
  shortSignal();
}

void H_letter()
{
  shortSignal();
  shortSignal();
  shortSignal();
  shortSignal();
}

void I_letter()
{
  shortSignal();
  shortSignal();
}

void J_letter()
{
  shortSignal();
  longSignal();
  longSignal();
  longSignal();
}

void K_letter()
{
  longSignal();
  shortSignal();
  longSignal();
}

void L_letter()
{
  shortSignal();
  longSignal();
  shortSignal();
  shortSignal();
}

void M_letter()
{
  longSignal();
  longSignal();
}

void N_letter()
{
  longSignal();
  shortSignal();
}

void O_letter()
{
  longSignal();
  longSignal();
  longSignal();
}

void P_letter()
{
  shortSignal();
  longSignal();
  longSignal();
  shortSignal();
}

void Q_letter()
{
  longSignal();
  longSignal();
  shortSignal();
  longSignal();
}

void R_letter()
{
  longSignal();
  shortSignal();
  longSignal();
}

void S_letter()
{
  shortSignal();
  shortSignal();
  shortSignal();
}

void T_letter()
{
  longSignal();
}

void U_letter()
{
  shortSignal();
  shortSignal();
  longSignal();
}

void V_letter()
{
  shortSignal();
  shortSignal();
  shortSignal();
  longSignal();
}

void W_letter()
{
  shortSignal();
  longSignal();
  longSignal();
}

void X_letter()
{
  longSignal();
  shortSignal();
  shortSignal();
  longSignal();
}

void Y_letter()
{
  longSignal();
  shortSignal();
  longSignal();
  longSignal();
}

void Z_letter()
{
  longSignal();
  longSignal();
  shortSignal();
  shortSignal();
}
