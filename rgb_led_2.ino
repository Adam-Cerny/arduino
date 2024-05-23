const int redPin = 11;   // číslo pinu červené barvy
const int greenPin = 10; // číslo pinu zelené barvy
const int bluePin = 9;   // číslo pinu modré barvy

void setup() {
  pinMode(redPin, OUTPUT);   // nastavení pinu redPin jako výstupu
  pinMode(greenPin, OUTPUT); // nastavení pinu greenPin jako výstupu
  pinMode(bluePin, OUTPUT);  // nastavení pinu bluePin jako výstupu
}

void loop() {
  int steps = 20;
  
  // Červená
  for (int i = 0; i <= steps; i++) {
    int red = i * (255 / steps);
    color(red, 0, 0);
    delay(1000);
  }
  
  // Zelená
  for (int i = 0; i <= steps; i++) {
    int green = i * (255 / steps);
    color(0, green, 0);
    delay(1000);
  }
  
  // Modrá
  for (int i = 0; i <= steps; i++) {
    int blue = i * (255 / steps);
    color(0, 0, blue);
    delay(1000);
  }
}

// generace barvy
void color (unsigned char red, unsigned char green, unsigned char blue) {
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
}
