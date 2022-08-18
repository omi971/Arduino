int Led1 = 12;
int Led2 = 11;
int Led3 = 10;
int Led4 = 9;
int Led5 = 8;
int d = 250;
//int i;
char s[] = "Pin Number: ";

void Five_led(){
  digitalWrite(Led1, HIGH);
  delay(d);
  digitalWrite(Led1, LOW);
  delay(d);
}

void led_loop(){
  for(int i = 12; i < 7; i--){
    Serial.println(i)
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Five_led();
  led_loop();
  
}
