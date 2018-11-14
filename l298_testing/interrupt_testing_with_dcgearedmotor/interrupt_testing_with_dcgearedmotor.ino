volatile long time1, time2, dt;
int pin_2 = 2;
volatile int h;
void isr1() {

  if (h == 0) {
    time1 = micros();
    h = 1;
  } else {
    time2 = micros();
    h = 0;
  }
  dt = abs(time1 - time2);
}

void motor_control()
{
  digitalWrite(6, HIGH);
 analogWrite(9, 255);
}
void setup() {
  pinMode(pin_2, INPUT_PULLUP);
 pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  attachInterrupt(0, isr1, RISING);
  Serial.begin(115200);
}
int  pret;
long rpm, x;
void loop() {
  motor_control();
  x = dt;
  if (pret != x) {
//    Serial.prin t("................");
//    Serial.println(x / 14);
    rpm = (60000.0 / x)*14;
    Serial.println(rpm);
    pret = x;
  }
}
