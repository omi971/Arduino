#include <Servo.h>
Servo servo;

//int angle = 10;
int d = 1000;
int input;

void setup() {
  Serial.begin(115200);
  Serial.println("Please type the angle: ");
  servo.attach(8);
  servo.write(0);
}

void loop()
{ 
  while (Serial.available()){
    input = Serial.parseInt();
//    Serial.print("You Typed: ");
//    Serial.println("Servo Serial: ");
    Serial.println(input);
    servo.write(input);
    delay(1000);
    }
// // scan from 0 to 180 degrees
//  for(angle = 10; angle < 180; angle++)  
//  {                                  
//    servo.write(angle);               
//    delay(d);                   
//  } 
//  // now scan back from 180 to 0 degrees
//  for(angle = 180; angle > 10; angle--)    
//  {                                
//    servo.write(angle);           
//    delay(d);       
//  } 
} 
