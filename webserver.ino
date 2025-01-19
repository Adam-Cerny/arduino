#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "Cerny";
const char* password = "";

// Create an instance of the web server on port 80
WebServer server(80);

void setup() {
  // Start serial communication
  Serial.begin(115200);

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
    server.send(200, "text/html", "<h1>ESP32 Web Server</h1><p>Welcome to your ESP32 Web Server!</p>");
  });

  // Start the server
  server.begin();
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}
