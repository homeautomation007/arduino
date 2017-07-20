
#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
IRsend irsend;
decode_results results;      // create instance of 'decode_results'


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED8,OUTPUT);
  Serial.println("IR Receiver Button Decode 22"); 
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    
    translateIR(); 
    Serial.println(results.value,HEX); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  //

  switch(results.value)

  {

 
  case 0xFFA25D: Serial.println(" POWER");  
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
    digitalWrite(LED7,LOW);
    digitalWrite(LED8,LOW);
  break;
  case 0xFF629D: Serial.println(" MODE");    break;
  case 0xFFE21D: Serial.println(" MUTE");    break;
  case 0xFF22DD: Serial.println(" PLAY/PAUSE");   break;
  case 0xFF02FD: Serial.println(" <<"); break;
  case 0xFFC23D: Serial.println(" >>"); break;
  case 0xFFE01F: Serial.println(" EQ"); break;
  case 0xFFA857: Serial.println(" -"); break;
  case 0xFF906F: Serial.println(" +"); break;
  case 0xFFB04F: Serial.println(" U/SD");  break;
  case 0xFF30CF: Serial.println(" 1");  digitalWrite(LED1,HIGH);  break;
  case 0xFF18E7: Serial.println(" 2");  digitalWrite(LED2,HIGH);  break;
  case 0xFF7A85: Serial.println(" 3");  digitalWrite(LED3,HIGH);  break;
  case 0xFF10EF: Serial.println(" 4");  digitalWrite(LED4,HIGH);  break;
  case 0xFF38C7: Serial.println(" 5");  digitalWrite(LED5,HIGH);  break;
  case 0xFF5AA5: Serial.println(" 6");  digitalWrite(LED6,HIGH);  break;
  case 0xFF42BD : Serial.println(" 7"); digitalWrite(LED7,HIGH);   break;
  case 0xFF4AB5: Serial.println(" 8");  digitalWrite(LED8,HIGH);  break;
  case 0xFF52AD: Serial.println(" 9");    break;
  case 0xFF6897: Serial.println(" 0");    break;
  case 0xFF9867: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} 
