#include <NewPing.h>

//#define ULTRASONIC_SENSOR_TRIG 11
//#define ULTRASONIC_SENSOR_ECHO 12
//const int Trigger = 11;
//const int Echo = 12;
//long time;
//int dist;
#define ULTRASONIC_SENSOR_TRI 11 // Trigger pin for the ultrasonic sensor
#define ULTRASONIC_SENSOR_ECHO 12    // Echo pin for the ultrasonic sensor
#define MAX_DISTANCE 40 // Maximum distance to measure in centimeters

NewPing sonar(ULTRASONIC_SENSOR_TRI, ULTRASONIC_SENSOR_ECHO, MAX_DISTANCE);

#define MIN_DISTANCE 10
#define MAX_DISTANCE 30

#define IR_SENSOR_RIGHT 2
#define IR_SENSOR_LEFT 3

//Right motor

int rightMotorPin2=7;
int rightMotorPin1=8;

//Left motor
int leftMotorPin2=9;
int leftMotorPin=10;

//NewPing mySensor(ULTRASONIC_SENSOR_TRIG, ULTRASONIC_SENSOR_ECHO, 400);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(ULTRASONIC_SENSOR_TRI,OUTPUT);
  pinMode(ULTRASONIC_SENSOR_ECHO,INPUT); 

  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  rotateMotor(0,0);   
}


void loop()
{
  int distance = sonar.ping_cm();
  
  
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  //NOTE: If IR sensor detects the hand then its value will be LOW else the value will be HIGH
  
  if (distance > 4 && distance < 20)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);  
    rotateMotor(0, 1);
  }
      
  
  //If right sensor detects hand, then turn right. We increase left motor speed and decrease the right motor speed to turn towards right
  if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH )
  {
      rotateMotor(0, 1 ); 
  }
  //If left sensor detects hand, then turn left. We increase right motor speed and decrease the left motor speed to turn towards left
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW )
  {
      rotateMotor(1, 0); 
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == LOW )
  {
      rotateMotor(1, 1); 
  }
  //If distance is between min and max then go straight
  
  //stop the motors
  else 
  {
      rotateMotor(0, 0);
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }   
}

//long read_cm()
//{
//
//  digitalWrite(Trigger, LOW);
//
//  delayMicroseconds(2);
//
//  digitalWrite(Trigger, HIGH);
//
//  delayMicroseconds(10);
//
//  time = pulseIn (Echo, HIGH);
//  
//  dist = .034*(time/2);
//  return dist;
//
//}
