const int potPin_left = A1;    // Analog input pin for the potentiometer
const int RPWMPin_left = 11;   // IBT-2 RPWM pin
const int LPWMPin_left = 10;    // IBT-2 LPWM pin

const int potPin_right = A0;    // Analog input pin for the potentiometer
const int RPWMPin_right = 5;    // IBT-2 RPWM pin
const int LPWMPin_right = 6;    // IBT-2 LPWM pin

int threshold_ = 30;
int motor_speed = 0;
int max_motor_speed = 140;

int left_stable = 133;
int left_high = left_stable - threshold_;
int left_down = left_stable + threshold_;

int right_stable = 178;
int right_high = right_stable - threshold_;
int right_down = right_stable + threshold_;

int x = right_stable;
int y = left_stable;
int thresh_ = 2;



void motorRotate(int t_val_left, int t_val_right) {
  int currentPosition_left = analogRead(potPin_left);
  int d_value_left = map(currentPosition_left, 0, 1023, 0, 270);

  int currentPosition_right = analogRead(potPin_right);
  int d_value_right = map(currentPosition_right, 0, 1023, 0, 270);

  if ((d_value_left >= t_val_left - thresh_ && d_value_left <= t_val_left + thresh_)) {
    // Stop motor
    analogWrite(RPWMPin_left, 0); // Stop motor
    analogWrite(LPWMPin_left, 0); // Stop motor
    analogWrite(RPWMPin_right, 0);
    analogWrite(LPWMPin_right, 0);
  } else if (d_value_left < t_val_left) {
//    Up jabe
    analogWrite(RPWMPin_left, max_motor_speed);
    analogWrite(LPWMPin_left, 0);
  } else if (d_value_left > t_val_left) {
    // down jabe
    analogWrite(RPWMPin_left, 0);
    analogWrite(LPWMPin_left, max_motor_speed);
  } else if ((d_value_left > left_down) || (d_value_left < left_high)) {
    analogWrite(RPWMPin_left, 0);
    analogWrite(LPWMPin_left, 0);
  }


//  else if (d_value < t_val) {
//    analogWrite(RPWMPin_left, max_motor_speed);
//    analogWrite(LPWMPin_left, 0);
//  } else if (d_value > t_val) {
//    analogWrite(RPWMPin_left, 0);
//    analogWrite(LPWMPin_left, max_motor_speed);
//  }

  if (d_value_right >= t_val_right - thresh_ && d_value_right <= t_val_right + thresh_) {
    analogWrite(RPWMPin_right, 0); // Stop motor
    analogWrite(LPWMPin_right, 0); // Stop motor
  } else if (d_value_right < t_val_right) {
    // down jabe
    analogWrite(RPWMPin_right, max_motor_speed);
    analogWrite(LPWMPin_right, 0);
  } else if (d_value_right > t_val_right) {

    // up jabe
    analogWrite(RPWMPin_right, 0);
    analogWrite(LPWMPin_right, max_motor_speed);
  } else if ((d_value_right > right_down) || (d_value_right < right_high)) {
    analogWrite(RPWMPin_right, 0);
    analogWrite(LPWMPin_right, 0);
  }
}


void setup() {
  Serial.begin(9600);

  // Set motor driver pins as outputs
  pinMode(RPWMPin_left, OUTPUT);
  pinMode(LPWMPin_left, OUTPUT);

  pinMode(RPWMPin_right, OUTPUT);
  pinMode(LPWMPin_right, OUTPUT);

  Serial.println("start hbe");
  delay(5000);

  while (1) {
    Serial.println("1evel e dukse");
    if (motorRotate_left(left_stable)) {
      break;
    }
    
  }
  delay(1000);

  while (1) {
    Serial.println("1evel e dukse");
    if (motorRotate_right(right_stable)) {
      break;
    }
  }
  delay(1000);
//
//  while (1) {
//    Serial.println("1evel e dukse");
//    if (motorRotate_right(right_down)) {
//      break;
//    }
//  }
//  delay(1000);
//  
//  while (1) {
//    Serial.println("1evel e dukse");
//    if (motorRotate_right(right_high)) {
//      break;
//    }
//  }
//  while (1) {
//    Serial.println("1evel e dukse");
//    if (motorRotate_right(right_stable)) {
//      break;
//    }
//  }
//  delay(1000);
////  delay(1000);
//  while (1) {
//    Serial.println("1evel e dukse");
//    if (motorRotate_left(left_down)) {
//      break;
//    }
//  }
//  delay(1000);
//  
//  while (1) {
//    Serial.println("1evel e dukse");
//    if (motorRotate_left(left_high)) {
//      break;
//    }
//  }
//  delay(1000);
//
//  while (1) {
//    Serial.println("1evel e dukse");
//    if (motorRotate_left(left_stable)) {
//      break;
//    }
//  }
//  delay(1000);
}

bool motorRotate_left(int t_val) {
  int currentPosition = analogRead(potPin_left);
  int d_value = map(currentPosition, 0, 1023, 0, 270);
  Serial.println(d_value);
  int diff = abs(t_val - d_value);
  motor_speed = 0 + diff * 1;

  if (d_value >= t_val - 5 && d_value <= t_val + 5) {
    analogWrite(RPWMPin_left, 0); // Stop motor
    analogWrite(LPWMPin_left, 0); // Stop motor
    analogWrite(RPWMPin_right, 0);
    analogWrite(LPWMPin_right, 0);
    return true;
  } else if (d_value < t_val) {
    analogWrite(RPWMPin_left, max_motor_speed);
    analogWrite(LPWMPin_left, 0);
  } else if (d_value > t_val) {
    analogWrite(RPWMPin_left, 0);
    analogWrite(LPWMPin_left, max_motor_speed);
  }
  return false;
}

bool motorRotate_right(int t_val) {
  int currentPosition = analogRead(potPin_right);
  int d_value = map(currentPosition, 0, 1023, 0, 270);
  Serial.println(d_value);
  int diff = abs(t_val - d_value);
  motor_speed = 0 + diff * 1;

  if (d_value >= t_val - 5 && d_value <= t_val + 5) {
    analogWrite(RPWMPin_right, 0); // Stop motor
    analogWrite(LPWMPin_right, 0); // Stop motor
    return true;
  } else if (d_value < t_val) {
    analogWrite(RPWMPin_right, max_motor_speed);
    analogWrite(LPWMPin_right, 0);
  } else if (d_value > t_val) {
    analogWrite(RPWMPin_right, 0);
    analogWrite(LPWMPin_right, max_motor_speed);
  }
  return false;
}


void loop() {

  if (Serial.available() > 0) { // Check if data is available to read
    String data = Serial.readStringUntil('\n'); // Read the data until newline character

    // Split the received string by comma
    int commaIndex = data.indexOf(',');
    if (commaIndex != -1) {
      String x_str = data.substring(0, commaIndex);
      String y_str = data.substring(commaIndex + 1);

      // Convert strings to integers
      int x_value = x_str.toInt();
      int y_value = y_str.toInt();

      // Print the received values to the Serial Monitor
      Serial.print("Received x value: ");
      Serial.println(x_value);
      Serial.print("Received y value: ");
      Serial.println(y_value);

      x = map(x_value, -40, 40, left_high, left_down);
      y = map(y_value, -40, 40, right_high, right_down);

      motorRotate(x, y);
    }
  }
}
