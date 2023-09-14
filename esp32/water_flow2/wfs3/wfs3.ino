int sensorPin = 2;
volatile long pulse;
float volume;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
}

void loop() {
  if (Serial.available() != 0){
    if (Serial.read() == 'x'){
      volume = 0;
      pulse = 0;
      Serial.println("Reset");
      }
    }
  volume = 2.663 * pulse;
  Serial.print(volume);
  Serial.println(" mL");
  
  delay(50);
}
void increase() {
  pulse++;
}
