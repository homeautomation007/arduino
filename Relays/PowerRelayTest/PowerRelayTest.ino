
int pin1 = 7;
int pin2 = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  digitalWrite(pin1,HIGH);
  delay(1000);
}
