#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int rele_1 = 1;
int rele_2 = 2;
int senzor_1 = A1;
int senzor_2 = A2;

void setup() {
  pinMode(rele_1, OUTPUT);
  pinMode(rele_2, OUTPUT);
}

void loop() {
  int s1 = analogRead(senzor_1);
  int s2 = analogRead(senzor_2);

  if (s1 > 500) { 
    digitalWrite(rele_1, LOW);
  } else {
    digitalWrite(rele_1, HIGH);
  }

  if (s2 > 500) { 
    digitalWrite(rele_2, LOW);
  } else {
    digitalWrite(rele_2, HIGH);
  }
}
