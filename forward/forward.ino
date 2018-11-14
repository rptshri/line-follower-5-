const int a=4;
const int b=5;
const int c=6;
const int d=7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(a,HIGH);
   digitalWrite(d,LOW); 
   digitalWrite(c,LOW);
   digitalWrite(b,HIGH);
}
