#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

char array1[] = " text1 ";  // první řádek displeje (26 znaků!)
char array2[] = " text2 ";      // druhý řádek displeje (26 znaků!)

// inicializace knihovny displeje 
LiquidCrystal_I2C lcd(0x27,16,2);            // nastavit adresu displeje na 0x27 pro 1602 displej 

void setup() {
  lcd.init();                                   // inicializace lcd
  lcd.backlight();                              // zapnout podsvícení 
  lcd.setCursor(0, 0);                          // nastavení kurzoru na počátek prvního řádku
  lcd.print(array1);                            // výpis textu na displej
  lcd.setCursor(0, 1);                          // nastavení kurzoru na počátek druhého řádku
  lcd.print(array2);                            // výpis textu na displej
}

void loop() {

}
