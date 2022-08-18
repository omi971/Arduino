// Dim an LED using a PWM pin
int PWMpin = 10;  // LED in series with 470 ohm resistor on pin 10
int i = 0;
//int d = 250;
void led_loop(int d){
    for (i = 12; i > 7; i--) {
    digitalWrite(i, HIGH);
    delay(d);
    digitalWrite(i, LOW);
//    Serial.println(i);
    
  }
  for (i = 9; i < 12; i++) {
    digitalWrite(i, HIGH);
    delay(d);
    digitalWrite(i, LOW);
//    Serial.println(i);
    }
}

void setup() {
  Serial.begin(9600);
  for(int j = 12; j >= 8; j--){
    pinMode(j, OUTPUT);
    }
}

void loop() {
  for (int x = 500; x >= 100; x = x-50){
    led_loop(x);
    Serial.println(x);
    }
//  led_loop(x);
}
