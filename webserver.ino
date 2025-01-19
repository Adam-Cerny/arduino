#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "Cerny";
const char* password = "";

// Create an instance of the web server on port 80
WebServer server(80);

// Define the LED pin
const int ledPin = 1;  // LED on pin 1

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print the IP address once connected
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define route to handle root requests
  server.on("/", HTTP_GET, []() {
    String html = "<h1>ESP32 Web Server</h1>";
    html += "<p>Click the button to toggle the LED on pin 1:</p>";
    html += "<form action=\"/toggle\" method=\"GET\">";
    html += "<button type=\"submit\">Toggle LED</button>";
    html += "</form>";
    server.send(200, "text/html", html);
  });

  // Define route to handle LED toggle requests
  server.on("/toggle", HTTP_GET, []() {
    // Toggle the LED
    digitalWrite(ledPin, !digitalRead(ledPin));

    // Redirect back to the root page
    server.sendHeader("Location", "/");
    server.send(303);  // 303 is the status code for redirect
  });

  // Start the server
  server.begin();
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}

