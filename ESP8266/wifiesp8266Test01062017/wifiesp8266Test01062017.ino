#include <SoftwareSerial.h>
//#include <LiquidCrystal.h>
 
//LiquidCrystal lcd(13, 12, A2, A3, A4, A5); 
SoftwareSerial esp8266(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3
void setup()
{
//  lcd.begin(16, 2);
  Serial.begin(115200);
  esp8266.begin(115200); // your esp's baud rate might be different
  Serial.println("started");
//  lcd.print("Esp8266 Testing");
 
  
  
//  lcd.setCursor(0, 1);
  sendData("AT+RST\r\n",1000,false); // reset module
  delay(2000);  
  sendData("AT+CWMODE=1\r\n",1000,true); // configure as access point
  delay(400);
  sendData("AT+CWJAP_CUR=\"SINGTEL-C107\",\"0016761095\"\r\n",2000,true); // get ip address   AT+CWJAP_CUR="SINGTEL-C107","0016761095"
  delay(5000);
  sendData("AT+CIPMUX=1\r\n",1000,true); // configure for multiple connections
  delay(400);
  sendData("AT+CIPSERVER=1,80\r\n",1000,true); // turn on server on port 80
  delay(400);
  sendData("AT+CIFSR\r\n",1000,true); // get ip address
  delay(400);

 Serial.println("server Ready for taking request.....");

}
 
void loop()
{
  
  if(esp8266.available()) // check if the esp is sending a message 
  {
     Serial.println("esp8266 data available");
     String response = "";
     while(esp8266.available()){
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
     Serial.println("----------------RESPONSE-------------------");
     Serial.println(response);
     Serial.println("----------------RESPONSE-------------------\n\n\n");
  }
}

String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266.print(command); // send the read character to the esp8266
    Serial.print(command);
    long int time = millis();
    while( (time+timeout) > millis()) {
      while(esp8266.available())
      {
       // delay(100);
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.println(response);
    }
    
    return response;
}







