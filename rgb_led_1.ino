const int redPin = 11;   // číslo pinu červené barvy
const int greenPin = 10; // číslo pinu zelené barvy
const int bluePin = 9;   // číslo pinu modré barvy

void setup() {
  pinMode(redPin, OUTPUT);   // nastavení pinu redPin jako výstupu
  pinMode(greenPin, OUTPUT); // nastavení pinu greenPin jako výstupu
  pinMode(bluePin, OUTPUT);  // nastavení pinu bluePin jako výstupu
}

void loop() {
  color(0,0,0); // vypnuti
  delay(1000);
  color(255,0,0); // cervena
  delay(1000);
  color(0,255,0); // zelena
  delay(1000);
  color(0,0,255); // modra
  delay(1000);
}

// generace barvy
void color (unsigned char red, unsigned char green, unsigned char blue) {
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
}
