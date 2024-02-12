
////Left Motor
const int potPin_left = A1;    // Analog input pin for the potentiometer
const int RPWMPin = 10;    // IBT-2 RPWM pin
const int LPWMPin = 11;    // IBT-2 LPWM pin

////Right Motor
const int potPin_right = A0;    // Analog input pin for the potentiometer
//const int RPWMPin = 5;    // IBT-2 RPWM pin
//const int LPWMPin = 6;    // IBT-2 LPWM pin
int motor_speed = 0;
int max_motor_speed = 100;

bool fwrd = false;
bool back = false;
bool stop_ = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Set motor driver pins as outputs
  pinMode(RPWMPin, OUTPUT);
  pinMode(LPWMPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {

    char key = Serial.read();


    if (key == 'w') {
      fwrd = true;
      back = false;
      stop_  = false;
    }
    if (key == 's') {
      fwrd = false;
      back = true;
      stop_  = false;
    }
    if (key == 'x') {
      fwrd = false;
      back = false;
      stop_  = true;
    }
  }

  if (fwrd) {
    analogWrite(RPWMPin, max_motor_speed);
    analogWrite(LPWMPin, 0);
//    delay(3000);
  }
  if (back) {
    analogWrite(RPWMPin, 0);
    analogWrite(LPWMPin, max_motor_speed);
  }

  if (stop_) {
    analogWrite(RPWMPin, 0);
    analogWrite(LPWMPin, 0);
  }

  int currentPosition_left = analogRead(potPin_left);
  int d_value_left = map(currentPosition_left, 0, 1023, 0, 270);
  Serial.print("Left ");
  Serial.print(d_value_left);
//  Serial.print('');
//  delay(1000);

  int currentPosition_right = analogRead(potPin_right);
  int d_value_right = map(currentPosition_right, 0, 1023, 0, 270);
  Serial.print("   Right ");
  Serial.print(d_value_right);
  Serial.println();
//  delay(1000);
}
