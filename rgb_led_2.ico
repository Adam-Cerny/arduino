const int redPin = 11;   // číslo pinu červené barvy
const int greenPin = 10; // číslo pinu zelené barvy
const int bluePin = 9;   // číslo pinu modré barvy

void setup() {
  pinMode(redPin, OUTPUT);   // nastavení pinu redPin jako výstupu
  pinMode(greenPin, OUTPUT); // nastavení pinu greenPin jako výstupu
  pinMode(bluePin, OUTPUT);  // nastavení pinu bluePin jako výstupu
}

void loop() {
  // počáteční a koncové hodnoty RGB
  int startRed = 255, startGreen = 179, startBlue = 255;
  int endRed = 0, endGreen = 0, endBlue = 0; 

  // počet mezistupňů
  int steps = 20;

  for (int i = 0; i <= steps; i++) {
    // vypočítání mezistupňů
    int red = startRed + i * (endRed - startRed) / steps;
    int green = startGreen + i * (endGreen - startGreen) / steps;
    int blue = startBlue + i * (endBlue - startBlue) / steps;

    color(red, green, blue); // nastavení barvy
    delay(1000); // počkat 1s
  }
}

// generace barvy
void color (unsigned char red, unsigned char green, unsigned char blue) {
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
}
