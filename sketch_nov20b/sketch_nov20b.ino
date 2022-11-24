//code for motor driver dual L298N
//  mbmishu
//18101008
  #define direction_Leftmotor1_F 12 //for motor 1 forward
  #define direction_Leftmotor1_B 4 //for motor 1  backward
  #define direction_Rightmotor2_F 2  //for motor 2  forward
  #define direction_Rightmotor2_B 3//for motor 2  backward
 
  #define enableA 11 //speed control for left motor1
  #define enableB 10 //speed control for right motor2

  char bt = 'S';
  int motor_speed = 150 ;
  void setup()
  {
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  
  pinMode(direction_Leftmotor1_F, OUTPUT);
  pinMode(direction_Leftmotor1_B, OUTPUT);
  pinMode(direction_Rightmotor2_F, OUTPUT);
  pinMode(direction_Rightmotor2_B, OUTPUT);

  }
  void loop(){

//    int leftmotor1_speed = motor_speed;
//    int rightmotor2_speed = motor_speed;
//   
//    digitalWrite(direction_Leftmotor1_F, HIGH);
//    digitalWrite(direction_Leftmotor1_B, LOW);
//   
//    digitalWrite(direction_Rightmotor2_F, HIGH);
//    digitalWrite(direction_Rightmotor2_B, LOW);
//    
//    analogWrite(enableA, leftmotor1_speed);
//    
//    analogWrite(enableB, rightmotor2_speed);
  
  bt = Serial.read();
  if(bt=='F')
  {
  forward(); 
  }
  
  if(bt=='B')
  {
  backward(); 
  }
  
  if(bt=='L')
  {
  left(); 
  }
  
  if(bt=='R')
  {
  right(); 
  }
 
  
  if(bt=='S')
  {
  Stop(); 
  }
  if(bt=='0')
  {
  motor_speed = 0;
  }
  if(bt=='1')
  {
  motor_speed = 130;
  }
  if(bt=='2')
  {
  motor_speed = 140;
  }
  if(bt=='3')
  {
  motor_speed = 150;
  }
  if(bt=='4')
  {
  motor_speed = 165;
  }
  if(bt=='5')
  {
  motor_speed = 180;
  }
  if(bt=='6')
  {
  motor_speed = 190;
  }
  if(bt=='7')
  {
  motor_speed = 204;
  }
  if(bt=='8')
  {
  motor_speed = 216;
  }
  if(bt=='9')
  {
  motor_speed = 230;
  }
  if(bt=='q')
  {
  motor_speed = 240;
  }  
  }
  void forward()
  {
    int leftmotor1_speed = motor_speed;
    int rightmotor2_speed = motor_speed;
   
    digitalWrite(direction_Leftmotor1_F, HIGH);
    digitalWrite(direction_Leftmotor1_B, LOW);
   
    digitalWrite(direction_Rightmotor2_F, HIGH);
    digitalWrite(direction_Rightmotor2_B, LOW);
    
    analogWrite(enableA, leftmotor1_speed);
    
    analogWrite(enableB, rightmotor2_speed);
   
    
  }
  void backward()
  {
    int leftmotor1_speed = motor_speed;
    int rightmotor2_speed = motor_speed;
   
    digitalWrite(direction_Leftmotor1_F, LOW);
    digitalWrite(direction_Leftmotor1_B, HIGH);
  
    digitalWrite(direction_Rightmotor2_F, LOW);
    digitalWrite(direction_Rightmotor2_B, HIGH);
  
    analogWrite(enableA, leftmotor1_speed);
   
    analogWrite(enableB, rightmotor2_speed);
    
  }
  void right()
  {
    int leftmotor1_speed = motor_speed;
    int rightmotor2_speed = motor_speed;
   
    digitalWrite(direction_Leftmotor1_F, HIGH);
    digitalWrite(direction_Leftmotor1_B, LOW);
  
    digitalWrite(direction_Rightmotor2_F, LOW);
    digitalWrite(direction_Rightmotor2_B, HIGH);
  
    analogWrite(enableA, leftmotor1_speed);
    
    analogWrite(enableB, rightmotor2_speed);
   
  }
  void left()
  {
    int leftmotor1_speed = motor_speed;
    int rightmotor2_speed = motor_speed;
   
    digitalWrite(direction_Leftmotor1_F, LOW);
    digitalWrite(direction_Leftmotor1_B, HIGH);
    
    digitalWrite(direction_Rightmotor2_F, HIGH);
    digitalWrite(direction_Rightmotor2_B, LOW);
  
    analogWrite(enableA, leftmotor1_speed);
   
    analogWrite(enableB, rightmotor2_speed);
    
  }
 
 
 
 
  void Stop(){
    int leftmotor1_speed = 0;
    int rightmotor2_speed = 0;
    int leftmotor3_speed = 0;
    int rightmotor4_speed = 0;
    digitalWrite(direction_Leftmotor1_F, HIGH);
    digitalWrite(direction_Leftmotor1_B, LOW);
   
    digitalWrite(direction_Rightmotor2_F, HIGH);
    digitalWrite(direction_Rightmotor2_B, LOW);
    
   
    analogWrite(enableA, leftmotor1_speed);
  
    analogWrite(enableB, rightmotor2_speed);
   
  }
