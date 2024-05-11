#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Define sensor pin
int sensor_pin = A0;

// Define moisture thresholds
const int dry_threshold = 950;
const int wet_threshold = 400;

// Initialize LCD object with I2C address and dimensions
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize sensor pin
  pinMode(sensor_pin, INPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Print initial text to LCD
  lcd.setCursor(0, 0);
  lcd.print("Sensor data:");
}

void loop() {
  // Read sensor data
  int sensor_data = analogRead(sensor_pin);

  // Display sensor data on serial monitor
  Serial.print("Sensor data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");

  // Display sensor data on LCD
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(sensor_data);

  // Determine moisture level and display corresponding message
  if (sensor_data > dry_threshold) {
    Serial.println("No moisture, Soil is dry"); 
    lcd.setCursor(0, 0);
    lcd.print("No moisture   ");
  } else if (sensor_data >= wet_threshold && sensor_data <= dry_threshold) {
    Serial.println("There is some moisture"); 
    lcd.setCursor(0, 0);
    lcd.print("Some moisture ");
  } else if (sensor_data < wet_threshold) {
    Serial.println("Soil is wet"); 
    lcd.setCursor(0, 0);
    lcd.print("Soil is wet   ");
  }

  delay(1000); // Adjust delay as needed
}
