const int potPin = A0;    // Analog input pin for the potentiometer
const int RPWMPin = 5;    // IBT-2 RPWM pin
const int LPWMPin = 6;    // IBT-2 LPWM pin
int motor_speed = 0;
int max_motor_speed = 50;

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

  int currentPosition = analogRead(potPin);
  int d_value = map(currentPosition, 0, 1023, 0, 270);
  Serial.println(d_value);

}
