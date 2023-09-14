#define channel_1 A0 //     forward # backward
#define channel_2 A1 //     left # right
#define channel_5 A4 //     #speed Control
//#define channel_4 A2
//#define channel_5 A1
//#define channel_6 3
//#define RELAY   2
//int buttonState = 0;

//Motor

///MotorA
#define motorA_LPWM 5
#define motorA_L_EN 4
#define motorA_RPWM 6
#define motorA_R_EN 7
int motor_A;

//MotorB
#define motorB_LPWM 9
#define motorB_L_EN 8
#define motorB_RPWM 10
#define motorB_R_EN 11
int motor_B;

// Speed

int spd;

// DeadZone

#define deadzone 29



/// read_rc variable;
int channel_read_1;
int channel_read_2;
int channel_read_5;
//int channel_read_4;
//int channel_read_5;
//int channel_read_6;

void setup() {
  Serial.begin(9600);
  pinMode(channel_read_1, INPUT);
  pinMode(channel_read_2, INPUT);
  pinMode(channel_read_5, INPUT);
  //pinMode(channel_read_4, INPUT);
  //pinMode(channel_read_5, INPUT);
  //pinMode(channel_read_6, INPUT);
  // initialize the LED pin as an output:
  //pinMode(RELAY, OUTPUT);

}

void loop() {
  read_rc();
  int  X = pulseToPWM(channel_read_2); // left # right
  int  Y = pulseToPWM(channel_read_1); // forward # backward
  spd = channel_read_5;
  motor_A = Y + X;
  motor_B = Y - X;
  //  Serial.print(spd);
  //  Serial.print("  ");
  //  Serial.print(motor_A);
  //  Serial.print("\t");
  //  Serial.println(motor_B);
  spd = map(channel_read_5, 980, 1990, 0, 255);
  //Serial.print("Speed: ");
  //Serial.println(spd);
  //Serial.print("   ");
  //drive(motor_A,motor_B);


  //  if (channel_read_6 >1500) {
  //    // turn LED on:
  //    buttonState = HIGH;
  //  } else if (channel_read_6 < 1500) {
  //    // turn LED off:
  //    buttonState = LOW;
  //  }


  //  // check if the pushbutton is pressed.
  //  if (buttonState == HIGH) {
  //    // turn LED on:
  //    digitalWrite(RELAY, HIGH);
  //  } else {
  //    // turn LED off:
  //    digitalWrite(RELAY, LOW);
  //  }



  drive(motor_A, motor_B);
  delay(300);
}



void read_rc()
{
  channel_read_1 = pulseIn(channel_1, HIGH);
  Serial.print("1 : ");
  Serial.println(channel_read_1);
  channel_read_2 = pulseIn(channel_2, HIGH);
  Serial.print("2 : ");
  Serial.println(channel_read_2);
  channel_read_5 = pulseIn(channel_5, HIGH);
  Serial.print("3 : ");
  Serial.println(channel_read_5);
  //channel_read_4 = pulseIn(channel_4, HIGH);
  //Serial.print("4 : ");
  //Serial.println(channel_read_4);
  //channel_read_5 = pulseIn(channel_5, HIGH);
  //Serial.print("5 : ");
  //Serial.println(channel_read_5);
  //channel_read_6 = pulseIn(channel_6, HIGH);
  //  Serial.print("6 : ");
  //  Serial.println(channel_read_6);

}

int pulseToPWM(int pulse) {

  // If we're receiving numbers, convert them to motor PWM
  if ( pulse > 980 ) {
    pulse = map(pulse, 990, 1985, -255, 255);

  } else {
    pulse = 0;
  }

  // Anything in deadzone should stop the motor
  if ( abs(pulse) <= deadzone ) {
    pulse = 0;
  }

  return pulse;
}

void drive(int motor_a, int motor_b)
{
  motor_a = constrain(motor_a, -(spd), spd);
  motor_b = constrain(motor_b, -(spd), spd) ;
  //  Serial.print(motor_a);
  //  Serial.print("    ");
  //  Serial.println(motor_b);

  // Forward

  // Enabling the Driver

  if ((motor_a) > 0 && (motor_b) > 0) {
    analogWrite(motorA_LPWM, abs(motor_a));
    analogWrite(motorB_LPWM, abs(motor_b));
    analogWrite(motorA_RPWM,   0);
    analogWrite(motorB_RPWM,   0);
    Serial.print("Ford");
    Serial.print('\t');
    Serial.print(motor_a);
    Serial.print('\t');
    Serial.println(motor_b);
  }
  // Backward

  else if ((motor_a) < 0 && (motor_b) < 0) {
    // Control pin
    analogWrite(motorA_RPWM, abs(motor_a));
    analogWrite(motorB_RPWM, abs(motor_b));
    analogWrite(motorA_LPWM,   0);
    analogWrite(motorB_LPWM,   0);
    Serial.print("Back");
    Serial.print('\t');
    Serial.print(motor_a);
    Serial.print('\t');
    Serial.println(motor_b);

  }
  // Left

  else if ((motor_a) < 0 && (motor_b) > 0)
  {
    // Control pin
    analogWrite(motorA_RPWM, abs(motor_a) );
    analogWrite(motorB_LPWM, abs(motor_b));
    analogWrite(motorA_LPWM, 0);
    analogWrite(motorB_RPWM, 0);
    Serial.print("Left");
    Serial.print('\t');
    Serial.print(motor_a);
    Serial.print('\t');
    Serial.println(motor_b);

  }




  // Right
  else if ((motor_a) > 0 && (motor_b) < 0) {
    // Control pin
    analogWrite(motorA_LPWM, abs(motor_a));
    analogWrite(motorB_RPWM, abs(motor_b));
    analogWrite(motorA_RPWM,   0);
    analogWrite(motorB_LPWM,   0);
    Serial.print("Right");
    Serial.print('\t');
    Serial.print(motor_a);
    Serial.print('\t');
    Serial.println(motor_b);

  }
  else {
    analogWrite(motorA_LPWM,   0);
    analogWrite(motorB_RPWM,   0);
    analogWrite(motorA_RPWM,   0);
    analogWrite(motorB_LPWM,   0);
    Serial.print("Stop");
    Serial.print('\t');
    Serial.print(motor_a);
    Serial.print('\t');
    Serial.println(motor_b);


  }

  digitalWrite(motorA_L_EN, HIGH);
  digitalWrite(motorB_L_EN, HIGH);
  digitalWrite(motorA_R_EN, HIGH);
  digitalWrite(motorB_R_EN, HIGH);
}
