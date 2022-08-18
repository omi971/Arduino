int Led1 = 13;
int Led2 = 12;
int Led3 = 11;
int Led4 = 10;
int d = 1000;
int i;
char s[] = "Pin Number: ";

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 13; i < 9; i--){
//    Serial.println(s, i);
    digitalWrite(i, HIGH);
    delay(d);
    digitalWrite(i, LOW);
    }
}
