/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman


  
*/







// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(2, HIGH);  
  delay(1000); 
  digitalWrite(3, HIGH);  
  delay(1000); 
  digitalWrite(4, HIGH);  
  delay(1000); 
  digitalWrite(5, HIGH);  
  delay(1000); 
  digitalWrite(6, HIGH);  
  delay(1000); 
  digitalWrite(7, HIGH);  
  delay(1000); 
  digitalWrite(8, HIGH);  
  delay(1000); 
  digitalWrite(9, HIGH);  
  delay(1000); 
  digitalWrite(2, LOW);  
  delay(1000); 
  digitalWrite(3, LOW);  
  delay(1000); 
  digitalWrite(4, LOW);  
  delay(1000); 
  digitalWrite(5, LOW);  
  delay(1000); 
  digitalWrite(6, LOW);  
  delay(1000); 
  digitalWrite(7, LOW);  
  delay(1000); 
  digitalWrite(8, LOW);  
  delay(1000); 
  digitalWrite(9, LOW);  
  delay(1000);                     // wait for a second
}
