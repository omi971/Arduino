//char arr[] = "Arduino";
//int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 99, 100};
void Random_Func(){
  long led = random(8, 13);
  Serial.println(led);
  
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("This is String Printing in Arduino");
  for(int i = 12; i > 7; i--){
    pinMode(i, OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  Random_Func();

//  for(int i = 0; i <= 11; i++){
//    Serial.println(arr[i]);
//    delay(1000);
//    }
}
