/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define POWER  0xE0E040BF            //from IRrecvDemo, Ken Shirriff
#define VOLUP  0xE0E0E01F // VOL UP
#define VOLDN  0xE0E0D02F // VOL DN
#define CHLUO  0xE0E048B7 // CHL UP
#define CHLDN  0xE0E008F7 // CHL DN
#define MUTE   0xE0E0F00F // MUTE
#define ONE    0xE0E020DF // 1
#define TWO    0xE0E0A05F // 2
#define THREE  0xE0E0609F // 3
#define FOURE  0xE0E010EF // 4
#define FIVE   0xE0E0906F // 5
#define SIX    0xE0E050AF // 6
#define SEVEN  0xE0E030CF // 7
#define BTEHT  0xE0E0B04F // 8
#define NINE   0xE0E0708F // 9
#define TEN    0xE0E08877 // 0
#define SORCE  0xE0E0807F // SORCE
#define ENTER  0xE0E016E9 // ENTER
#define RIGHT  0xE0E046B9 // RIGHT
#define LEFT   0xE0E0A659 // LEFT
#define DOWN   0xE0E08679 // DOWN
#define UP .   0xE0E006F9 // UP
#define RETURN 0xE0E01AE5 // RERURN
#define EXIT   0xE0E0B44B // EXIT
#define SAMSUNG_BITS  32 


IRsend irsend;

void setup()
{
  pinMode (3, OUTPUT);  //output as used in library
}

void loop() {
  irsend.sendSAMSUNG(VOLDN, SAMSUNG_BITS); 
  delay (500);
  irsend.sendSAMSUNG(VOLDN, SAMSUNG_BITS); 
  delay (500);
  irsend.sendSAMSUNG(VOLDN, SAMSUNG_BITS); 
  delay (500);
  irsend.sendSAMSUNG(VOLDN, SAMSUNG_BITS); 
  delay (500);

  irsend.sendSAMSUNG(VOLUP, SAMSUNG_BITS); 
  delay (500);
  irsend.sendSAMSUNG(VOLUP, SAMSUNG_BITS); 
  delay (500);
  irsend.sendSAMSUNG(VOLUP, SAMSUNG_BITS); 
  delay (500);
  irsend.sendSAMSUNG(VOLUP, SAMSUNG_BITS); 
  delay (5000);

}//end of loop

