
#include<LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27,16,2);

int sensor_pin = A0;
int relay_pin = 7;


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setBacklight(HIGH);
  
  pinMode(sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  
}

void loop()
{
  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");

  if(sensor_data > 500)
  {
    Serial.println("No moisture, Soil is dry"); 
    digitalWrite(relay_pin, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Soil Dry");
    lcd.setCursor(0,1);
    lcd.print("Motor ON");
  }
  if(sensor_data <= 500)
  {
    Serial.println("Soil is wet"); 
    digitalWrite(relay_pin, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Soil Wet");
    lcd.setCursor(0,1);
    lcd.print("Motor OFF");
  }

  delay(100);
}
