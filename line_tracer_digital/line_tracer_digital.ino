//#define debug

const int mod1 = 7;
const int mod2 = 6;
const int mod3 = 5;
const int mod4 = 4;
const int mod5 = 3;
const int pwm_1 = 9;
const int pwm_2 = 10;
const int dir1PinA = 8;
const int dir1PinB = 11;

const int dir2PinA = 12;
const int dir2PinB = 13;

int curstate = 0;
int prevstate = 0;

int sum1[] = {0, 0, 0, 0, 0, 0, 0, 0};
int sum2[] = {0, 0, 0, 0, 0, 0, 0, 0};
int sum3[] = {0, 0, 0, 0, 0, 0, 0, 0};
int sum4[] = {0, 0, 0, 0, 0, 0, 0, 0};
int sum5[] = {0, 0, 0, 0, 0, 0, 0, 0};

int val1, val2, val3, val4, val5;
//int avg;
void serialprint()
{
  Serial.print("val1::  ");
  Serial.println(val1);
  Serial.print("val2::  ");
  Serial.println(val2);
  Serial.print("val3::  ");
  Serial.println(val3);
  Serial.print("val4::  ");
  Serial.println(val4);
  Serial.print("val5::  ");
  Serial.println(val5);
  /* Serial.print("avg :: ");
    Serial.println(avg);*/
  Serial.println("_______________________");
  delay (400);
}


void backward()
{ digitalWrite(6, HIGH);
  digitalWrite(7, LOW );
  digitalWrite(4, LOW );
  digitalWrite(5, HIGH);
}


void forward()
{
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH );
  digitalWrite(5, LOW);
}

void leftBack()
{
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(4, HIGH );
  digitalWrite(5, LOW);
}

void rightBack()
{
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(4, LOW );
  digitalWrite(5, HIGH);
}

////////////////////////////////////////////
void a()
{
  analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  forward();
}

void b()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 205);
  forward();
}
void c()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void d()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void e()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void f()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 205);
  forward();
}
void g()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 205);
  forward();
}
void h()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void i1()
{
  analogWrite(pwm_1, 255)  ;
  analogWrite(pwm_2, 255);
  leftBack();
}
void j()
{
  analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 205);
  forward();
}
void k()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void l()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void m()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 205);
  forward();
}
void n()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void o()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void p()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  forward();
}
void q1()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  backward();
}

/////////////////////////////////////////////
int ch = 0;
void setup() {

  Serial.begin(9600);

  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);

  delay(3000);
}

void loop() {
#ifdef debug
  serialprint();
#endif
  val1 = analogRead(mod1);
  val2 = analogRead(mod2);
  val3 = analogRead(mod3);
  val4 = analogRead(mod4);
  val5 = analogRead(mod5);
  // avg=(val1+val2-val4-val5);

  for (int i = 0, i <= 7; i++)
  {
    sum1[i] = val1;
  }
  for (int i = 0, i <= 7; i++)
  {
    sum2[i] = val2;
  }
  for (int i = 0, i <= 7; i++)
  {
    sum3[i] = val3;
  }
  for (int i = 0, i <= 7; i++)
  {
    sum4[i] = val4;
  }
  for (int i = 0, i <= 7; i++)
  {
    sum5[i] = val5;
  }

  avg1 = (sum1[1] + sum1[2] + sum1[3] + sum1[4] + sum1[5] + sum1[6] + sum1[7] + sum1[8]) / 5;
  avg2 = (sum2[1] + sum2[2] + sum2[3] + sum2[4] + sum2[5] + sum2[6] + sum2[7] + sum2[8]) / 5;
  avg3 = (sum3[1] + sum3[2] + sum3[3] + sum3[4] + sum3[5] + sum3[6] + sum3[7] + sum3[8]) / 5;
  avg4 = (sum4[1] + sum4[2] + sum4[3] + sum4[4] + sum4[5] + sum4[6] + sum4[7] + sum4[8]) / 5;
  avg5 = (sum5[1] + sum5[2] + sum5[3] + sum5[4] + sum5[5] + sum5[6] + sum5[7] + sum5[8]) / 5;

  unsigned long int val = 0b00000000;
  //////////////////
  if (avg1 > 512)
  {
    bitSet(avg1, 0);
  }
  else if (avg1 < 512)
  {
    bitClear(va1, 0);
  }
  ///////////////////
  else if (avg2 > 512)
  {
    bitSet(avg2, 1);
  }
  else if (avg2 < 512)
  {
    bitClear(avg2, 1)
  }
  ///////////////////
  else if (avg3 > 512)
  {
    bitSet(avg3, 2);
  }
  else if (avg3 < 512)
  {
    bitClear(avg3, 2)
  }
  ///////////////////
  else if (avg4 > 512)
  {
    bitSet(avg4, 3);
  }
  else if (avg4 < 512)
  {
    bitClear(avg4, 3)
  }
  ///////////////////
  else if (avg5 > 512)
  {
    bitSet(avg5, 4);
  }
  else if (avg5 < 512)
  {
    bitClear(avg5, 4)
  }
  ///////////////////


  if (val == 0b00010001)
  {
    ch = 1;
  }
  else if (val == 0b00010011)
  {
    ch = 2;
  }
  else if (val == 0b00001001)
  {
    ch = 3;
  }
  else if (val == 0b00000011)
  {
    ch = 5;
  }
  else if (val == 0b00010011)
  {
    ch = 6;
  }
  else if (val == 0b00000111)
  {
    ch = 7;
  }
  else if (val == 0b00001111)
  {
    ch = 8;
  }
  else if (val == 0b00000001)
  {
    ch = 9;
  }
  else if (val == 0b00011001)
  {
    ch = 10;
  }
  else if (val == 0b00011000)
  {
    ch = 11;
  }
  else if (val == 0b00010010)
  {
    ch = 12;
  }
  else if (val == 0b00011100)
  {
    ch = 13;
  }
  else if (val == 0b00011110)
  {
    ch = 14;
  }
  else if (val == 0b00010000)
  {
    ch = 15;
  }
  else if (val == 0b00000000)
  {
    ch = 16;
  }
  else if (val == 0b00011111)
  {
    ch = 17;
  }

  switch (ch)
  {
    case 1 : a();
      break;
    case 2  : b();
      break;
    case 3  : c();
      break;
    //    case 4  : d();
    //      break;
    case 5  : e();
      break;
    case 6  : f();
      break;
    case 7  : g();
      break;
    case 8 : h();
      break;
    case 9 : i1();
      break;
    case 10 : j();
      break;
    case 11  : k();
      break;
    case 12  : l();
      break;
    case 13 : m();
      break;
    case 14 : n();
      break;
    case 15 : o();
      break;
    case 16 : p();
      break;
    default: 17 : q1();
  }

#ifdef SERIAL_DEBUG
  Serial.print("current state :::   ");
  Serial.println(curstate);
#endif
  delay(0);
}
