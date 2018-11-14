#define debug

const int pwm_1 = 9;
const int pwm_2 = 10;
const int dir1PinA = 2;
const int dir2PinA = 3;
const int dir1PinB = 4;
const int dir2PinB = 5;

float Kp = 5, Ki = 5, Kd = 5;
float error = 0, prev_error = 0;
float I = 0, P = 0, D = 0;
float prev_I = 0, PID_value = 0;
int sensors[5] = { 0, 0, 0, 0, 0};
int initial_speed = 150;

void sensor_read()
{
  const int s1 = A0;
  const int s2 = A1;
  const int s3 = A2;
  const int s4 = A3;
  const int s5 = A4;
  sensors[0] = analogRead(s1);
  sensors[1] = analogRead(s2);
  sensors[2] = analogRead(s3);
  sensors[3] = analogRead(s4);
  sensors[4] = analogRead(s5);
  

  if ((sensors[0] == 0) && (sensors[1] == 0) && (sensors[2] == 0) && (sensors[3] == 0) && (sensors[4] == 1))
  {
    error = 4;
  }
  else if ((sensors[0] == 0) && (sensors[1] == 0) && (sensors[2] == 0) && (sensors[3] == 1) && (sensors[4] == 1))
    error = 3;
  else if ((sensors[0] == 0) && (sensors[1] == 0) && (sensors[2] == 0) && (sensors[3] == 1) && (sensors[4] == 0))
    error = 2;
  else if ((sensors[0] == 0) && (sensors[1] == 0) && (sensors[2] == 1) && (sensors[3] == 1) && (sensors[4] == 0))
    error = 1;
  else if ((sensors[0] == 0) && (sensors[1] == 0) && (sensors[2] == 1) && (sensors[3] == 0) && (sensors[4] == 0))
    error = 0;
  else if ((sensors[0] == 0) && (sensors[1] == 1) && (sensors[2] == 1) && (sensors[3] == 0) && (sensors[4] == 0))
    error = -1;
  else if ((sensors[0] == 0) && (sensors[1] == 1) && (sensors[2] == 0) && (sensors[3] == 0) && (sensors[4] == 0))
    error = -2;
  else if ((sensors[0] == 1) && (sensors[1] == 1) && (sensors[2] == 0) && (sensors[3] == 0) && (sensors[4] == 0))
    error = -3;
  else if ((sensors[0] == 1) && (sensors[1] == 0) && (sensors[2] == 0) && (sensors[3] == 0) && (sensors[4] == 0))
    error = -4;
  else if ((sensors[0] == 0) && (sensors[1] == 0) && (sensors[2] == 0) && (sensors[3] == 0) && (sensors[4] == 0))
  {
    if (error == -4)
    {
      error = -5;
    }
    else error = 5;
  }
}

void calc_PID()
{
  P = error;
  I = I + prev_I;
  D = error - prev_error;
  PID_value = (Kp * P) + (Ki * I) + (Kd * D);
  prev_I = I;
  prev_error = error;

}
void motor_control()
{
  int left_speed = initial_speed - PID_value;
  int right_speed = initial_speed + PID_value;

  constrain(left_speed, 0, 255);
  constrain(right_speed, 0, 255);

  analogWrite(pwm_1, left_speed);
  analogWrite(pwm_2, right_speed);

 digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH );
  digitalWrite(5, LOW);
}
int val1, val2, val3, val4, val5;
void serialprint()
{
  Serial.print("val1::  ");
  Serial.println(sensors[0]);
  Serial.print("val2::  ");
  Serial.println(sensors[1]);
  Serial.print("val3::  ");
  Serial.println(sensors[2]);
  Serial.print("val4::  ");
  Serial.println(sensors[3]);
  Serial.print("val5::  ");
  Serial.println(sensors[4]);
  /* Serial.print("avg :: ");
    Serial.println(avg);*/
  Serial.println("_______________________");
  delay (400);
}



void setup() {
  Serial.begin(9600);
  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  delay(500);

}

void loop() {
  #ifdef debug
  serialprint();
#endif
  motor_control();
  sensor_read();
  calc_PID();
}
