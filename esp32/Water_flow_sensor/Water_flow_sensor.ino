int sensorPin = 2;
volatile long pulse;
void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
}
void loop() {
  Serial.println(pulse);
//  Serial.print("");
  delay(100);
}
void increase() {
  pulse++;
}
