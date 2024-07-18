#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int senzor_1 = A0;
const int relay_1 = 2; 
const int relay_2 = 3; 

void setup() {
  pinMode(senzor_1, INPUT); 
  pinMode(relay_1, OUTPUT); 
  pinMode(relay_2, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  int senzor_1_data = analogRead(senzor_1);
  int moisture_percentage_1 = map(senzor_1_data, 0, 1023, 100, 0);

  Serial.print("Moisture1: ");
  Serial.print(moisture_percentage_1);
  Serial.println("%");
  Serial.print(senzor_1_data);
  
  if (moisture_percentage_1 < 81) 
  {
    digitalWrite(relay_1, LOW); 
    digitalWrite(relay_2, LOW);
  } 
  else if (moisture_percentage_1 >= 81)
  {
    digitalWrite(relay_1, HIGH);
    digitalWrite(relay_2, HIGH);
  }

  delay(1000); 
  digitalWrite(relay_1, HIGH); 
  delay(1000);
}
