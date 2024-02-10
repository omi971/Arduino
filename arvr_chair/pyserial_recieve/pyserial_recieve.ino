void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED pin as output
}

void loop() {
  if (Serial.available() > 0) { // Check if there's data available to read
    char command = Serial.read(); // Read the incoming byte/command

    // Process the received command
    switch (command) {
      case 'S': // Start command
        digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
        Serial.println("LED turned ON");
        break;
      case 'P': // Pause command
        // Additional code for pausing (if needed)
        Serial.println("Pause command received");
        break;
      case 'X': // Stop command
        digitalWrite(LED_BUILTIN, LOW); // Turn off LED
        Serial.println("LED turned OFF");
        break;
      default:
        // Handle unrecognized command
        Serial.println("Unrecognized command");
        break;
    }
  }
  delay(1000);
}
