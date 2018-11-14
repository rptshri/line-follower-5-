
#include <Encoder.h>

Encoder myEnc(2, 3);   
const int pwm_1 = 9;
long oldPosition  = -999;
volatile int count=0;
void motor_control()
{
  analogWrite(pwm_1, 215);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW );
}

void interr ()
{
count+=count;
Serial.println(count)
}



void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
  pinMode(pwm_1, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  delay(500);
}

void loop() {
  motor_control();
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
}
