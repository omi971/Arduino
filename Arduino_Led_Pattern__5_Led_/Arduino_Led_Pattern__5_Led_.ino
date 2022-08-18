/* 
 *  This program will Blink 5 Led with a forward and Backward Pattern
 *  Led is connected to GND via 330 ohm Resistor
 *  Led's are connected to Arduino Pin From D8 to D12 
 */
 

int i = 0;

// This function will Forward and then Backward 5 Led
void led_loop(int d){
  // Forwarding a Led
    for (i = 12; i > 7; i--) {
    digitalWrite(i, HIGH);
    delay(d);
    digitalWrite(i, LOW);
//    Serial.println(i);
    
  }
  // Backwarding a Led
  for (i = 9; i < 12; i++) {
    digitalWrite(i, HIGH);
    delay(d);
    digitalWrite(i, LOW);
//    Serial.println(i);
    }
}

void setup() {
  // Starting the serial monitor with 9600 baud rate
  Serial.begin(9600);

  // initializing the Pins in OUTPUT Mode
  for(int j = 12; j >= 8; j--){
    pinMode(j, OUTPUT);
    }
}

void loop() {
  // Pattern speed control
  for (int x = 250; x >= 1; x = x-50){
    led_loop(x);
    Serial.println(x);
    }
}
