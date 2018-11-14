
const int pwm_1 = 9;

void motor_control()
{
 

  digitalWrite(pwm_1, LOW);
  analogWrite(6,200 );
  analogWrite(5,50 );

}
void setup() {
  Serial.begin(9600);
  pinMode(pwm_1, OUTPUT);
//  pinMode(pwm_2, OUTPUT);
//  pinMode(4, OUTPUT);
//  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  delay(500);
}

void loop() {
  motor_control();
}
