
#include <IRremote.h>

#define RECV_PIN 11

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

// Dumps out the decode_results raw data.
// Call this after IRrecv::decode()
void dump(decode_results *results)
{
  Serial.print("0x");
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(results->rawlen, DEC);
  Serial.print("):");
  for (int i=0; i < results->rawlen; ++i)
  {
    Serial.print(" ");
    if ((i % 2) == 0)
    {
      // Mark gaps (spaces) as negative numbers in the output
      Serial.print("-");
    }
    // Display mark/space lengths in microseconds
    Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
  }
  Serial.println("");
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    dump(&results);
    irrecv.resume(); // Receive the next value
  }
}
