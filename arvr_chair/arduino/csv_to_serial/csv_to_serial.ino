void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    String dataReceived = Serial.readStringUntil('\n'); // Read the data until a newline character is encountered

    // Parse the received data
    int commaIndex = dataReceived.indexOf(',');
    if (commaIndex != -1) { // Check if comma exists in the received data
      String x_val_str = dataReceived.substring(0, commaIndex); // Extract the first value before comma
      String y_val_str = dataReceived.substring(commaIndex + 1); // Extract the second value after comma

      int x_val = x_val_str.toInt(); // Convert string to integer
      int y_val = y_val_str.toInt(); // Convert string to integer

      // Echo back the received values
      Serial.print("X:");
      Serial.print(x_val);
      Serial.print(", Y:");
      Serial.println(y_val);
    }
  }
}
