// Bluetooth module HM-10 pins
#define RX 11
#define TX 10
#define relayPin 7 // Pin connected to the relay

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(TX, RX); // Initialize SoftwareSerial for Bluetooth

void setup() {
  bluetooth.begin(9600); // Start Bluetooth communication at 9600 baud
  Serial.begin(9600);    // Start serial communication at 9600 baud
  pinMode(relayPin, OUTPUT); // Set relay pin as output
  digitalWrite(relayPin, HIGH); // Ensure relay is off by default (for active-low relay)
}

void loop() {
  if (bluetooth.available() > 0) {  // Check if there's incoming Bluetooth data
    char BluetoothData = bluetooth.read(); // Read the incoming byte

    if (BluetoothData == '0') {
      digitalWrite(relayPin, HIGH);     // Turn relay off (active-low)
      bluetooth.println("Relay OFF");   // Send confirmation back
    } else if (BluetoothData == '1') {
      digitalWrite(relayPin, LOW);      // Turn relay on (active-low)
      bluetooth.println("Relay ON");    // Send confirmation back
    } else {
      bluetooth.println("Unknown Command"); // Handle any unknown commands
    }
  }
  delay(100); // Short delay to avoid overwhelming the Bluetooth communication
}
