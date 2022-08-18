int Led1 = 13;
int Led2 = 12;
//int Led3 = 11;
//int Led4 = 10;

int d = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
//  pinMode(Led3, OUTPUT);
//  pinMode(Led4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Led1, HIGH);
  delay(d);
  digitalWrite(Led1, LOW);
  delay(d);
}
