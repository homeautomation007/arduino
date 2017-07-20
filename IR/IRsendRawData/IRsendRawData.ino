/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define POWER         0xE0E040BF            //from IRrecvDemo, Ken Shirriff
#define SAMSUNG_BITS  32 

IRsend irsend;

void setup()
{
  pinMode (3, OUTPUT);  //output as used in library
}

void loop() {

  irsend.sendSAMSUNG(POWER, SAMSUNG_BITS); 

  delay (5000);

}//end of loop

