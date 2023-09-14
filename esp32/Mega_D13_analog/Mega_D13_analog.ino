#define led 13

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

    if(Serial.available() != 'x'){
      if(Serial.read() == '1'){
        Serial.println("Valve is On");
        digitalWrite(led, LOW);
        delay(1000);
        digitalWrite(led, HIGH);
        }
      }
    delay(1000);
}
