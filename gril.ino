#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <max6675.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int thermoSCK = 52;
const int thermoCS = 51;
const int thermoSO = 50;

MAX6675 thermo(thermoSCK, thermoCS, thermoSO);

const int in1 = 9;
const int in2 = 8;
const int enA = 4;

const int in3 = 7;
const int in4 = 6;
const int enB = 5;

const int tlacitka[] = {11, 10, 13, 12};
int stisk = 0;
int idealni_teplota = 25;

int fanSpeed = 0;
const int maxSpeed = 255;
const int increment = 10;
const int delayTime = 1000;

const int mezera = 10;

unsigned long lastCheckTime = 0;
const unsigned long checkInterval = 5000; // 5 sekund

// Pro debouncing
unsigned long lastButtonPress[4] = {0, 0, 0, 0}; // Časy posledního stisknutí pro každé tlačítko
const unsigned long debounceDelay = 800; // 400 ms pro debounce (zdvojnásobeno)

void setup() {
  Serial.begin(9600);  
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Idealni t.: ");
  lcd.print(idealni_teplota);

  lcd.setCursor(0, 1);
  lcd.print("Realna t.: ");

  for(int x = 0; x < 4; x++) {
    pinMode(tlacitka[x], INPUT_PULLUP);
  }
  
  Serial.print("Idealni teplota: ");
  Serial.println(idealni_teplota);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastCheckTime >= checkInterval) {
    lastCheckTime = currentMillis;

    double realna_teplota = thermo.readCelsius();
    
    lcd.setCursor(11, 1);
    lcd.print("      ");
    lcd.setCursor(11, 1);
    lcd.print(realna_teplota);
    lcd.print(" C");

    int adjustSpeed = calculateSpeed(realna_teplota);
    analogWrite(enA, adjustSpeed);
    analogWrite(enB, adjustSpeed);
  }

  for (int x = 0; x < 4; x++) {
    stisk = digitalRead(tlacitka[x]);

    // Debouncing: Kontrola, zda uběhl debounceDelay od posledního stisknutí
    if (stisk == LOW && (currentMillis - lastButtonPress[x] > debounceDelay)) {
      lastButtonPress[x] = currentMillis; // Aktualizace času posledního stisknutí

      switch (x) {
        case 0:
          idealni_teplota += 5;  // Tlačítko 0 přidá 5 stupňů
          break;
        case 1:
          idealni_teplota -= 5;  // Tlačítko 1 odebere 5 stupňů
          break;
        case 2:
          idealni_teplota += 15; // Tlačítko 2 přidá 15 stupňů
          break;
        case 3:
          idealni_teplota -= 15; // Tlačítko 3 odebere 15 stupňů
          break;
      }

      // Aktualizace na LCD displeji
      lcd.setCursor(11, 0);
      lcd.print("      ");
      lcd.setCursor(11, 0);
      lcd.print(idealni_teplota);
    }
  }
}

int calculateSpeed(double currentTemp) {
  if (idealni_teplota - currentTemp >= mezera && idealni_teplota - currentTemp < mezera *2) {
    return maxSpeed * 0.5;
  } 
  else if (idealni_teplota - currentTemp >= mezera * 2 && idealni_teplota - currentTemp < mezera *3) {
    return maxSpeed * 0.6;
  }
  else if (idealni_teplota - currentTemp >= mezera * 3 && idealni_teplota - currentTemp < mezera *4) {
    return maxSpeed * 0.7;
  }
  else if (idealni_teplota - currentTemp >= mezera * 4 && idealni_teplota - currentTemp < mezera *5) {
    return maxSpeed * 0.8;
  }
  else if (idealni_teplota - currentTemp >= mezera * 5 && idealni_teplota - currentTemp < mezera *6) {
    return maxSpeed * 0.9;
  }
  else if (idealni_teplota - currentTemp >= mezera * 6) {
    return maxSpeed;
  }
  else {
    return 0;
  }
}
