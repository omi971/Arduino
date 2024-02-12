const int potPin_left = A1;    // Analog input pin for the potentiometer
const int RPWMPin_left =11;    // IBT-2 RPWM pin
const int LPWMPin_left = 10;    // IBT-2 LPWM pin

const int potPin_right = A0;    // Analog input pin for the potentiometer
const int RPWMPin_right = 5;    // IBT-2 RPWM pin
const int LPWMPin_right = 6;    // IBT-2 LPWM pin

int motor_speed = 0;
int max_motor_speed = 200;

int left_stable = 110;
int left_high = 30;
int left_down = 190;

int right_stable = 192;
int right_high = 45;
int right_down = 178;

bool motorRotate_left(int t_val) {
  int currentPosition = analogRead(potPin_left);
  int d_value = map(currentPosition, 0, 675, 0, 270);
  Serial.println(d_value);
  int diff = abs(t_val - d_value);
  motor_speed = 0 + diff * 1;

  if (d_value >= t_val - 5 && d_value <= t_val + 5) {
    analogWrite(RPWMPin_left, 0); // Stop motor
    analogWrite(LPWMPin_left, 0); // Stop motor
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
  int d_value = map(currentPosition, 0, 675, 0, 270);
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


void setup() {
  // put your setup code here, to run once:
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

  while (1) {
    Serial.println("1evel e dukse");
    if (motorRotate_right(right_stable)) {
      break;
    }
  }
}

void loop() {

  //forward

  while (1) {
    Serial.println("frd e dukse");
    if (motorRotate_left(left_high)) {
      break;
    }
  }

  while (1) {
    Serial.println("frd e dukse");
    if (motorRotate_right(right_high)) {
      break;
    }
  }

  //  back


  while (1) {
    Serial.println("down e dukse");
    if (motorRotate_left(left_down)) {
      break;
    }
  }

  while (1) {
    Serial.println("down e dukse");
    if (motorRotate_right(right_down)) {
      break;
    }
  }
  //  stable
  while (1) {
    Serial.println("stable e dukse");
    if (motorRotate_left(left_stable)) {
      break;
    }
  }

  while (1) {
    Serial.println("stable e dukse");
    if (motorRotate_right(right_stable)) {
      break;
    }
  }
  //  right
  while (1) {
    Serial.println("right e dukse");
    if (motorRotate_left(left_high)) {
      break;
    }
  }

  while (1) {
    Serial.println("right e dukse");
    if (motorRotate_right(right_down)) {
      break;
    }
  }

  //  stable
  while (1) {
    Serial.println("stable e dukse");
    if (motorRotate_left(left_stable)) {
      break;
    }
  }

  while (1) {
    Serial.println("stable e dukse");
    if (motorRotate_right(right_stable)) {
      break;
    }
  }

  //  left
  while (1) {
    Serial.println("left e dukse");
    if (motorRotate_left(left_down)) {
      break;
    }
  }

  while (1) {
    Serial.println("left e dukse");
    if (motorRotate_right(right_high)) {
      break;
    }
  }

  //  stable
  while (1) {
    Serial.println("stable e dukse");
    if (motorRotate_left(left_stable)) {
      break;
    }
  }

  while (1) {
    Serial.println("stable e dukse");
    if (motorRotate_right(right_stable)) {
      break;
    }
  }
  delay(2000);
}
