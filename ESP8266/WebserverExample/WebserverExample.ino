#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(13, 12, A2, A3, A4, A5); 
SoftwareSerial esp8266(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(115200);
  esp8266.begin(115200); // your esp's baud rate might be different
  Serial.println("started");
  lcd.print("Server Started");
  
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  
  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
  
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
  lcd.setCursor(0, 1);
  sendData("AT+RST\r\n",2000,false); // reset module
  lcd.print("AT+RST");
  delay(2000);  
  Serial.println("Re-started ESPMODULE");
  lcd.print("Re-started ESPMODULE");
  sendData("AT+CWMODE=1\r\n",1000,true); // configure as access point
  delay(1000);
 // sendData("AT+CIPSTA_CUR=\"192.168.1.101\",\"255.255.255.0\",\"192.168.1.254\"\r\n",1000,true); // set ip address 
 // delay(2000);
  sendData("AT+CWJAP_CUR=\"SINGTEL-C107\",\"0016761095\"\r\n",2000,true); // get ip address   AT+CWJAP_CUR="SINGTEL-C107","0016761095"
  delay(5000);
  sendData("AT+CIPMUX=1\r\n",1000,true); // configure for multiple connections
  delay(2000);
  //sendData("AT+CIPMUX=1\r\n",1000,true); // configure for multiple connections
  //delay(2000);
  sendData("AT+CIPSERVER=1,80\r\n",1000,true); // turn on server on port 80
  delay(2000);
  sendData("AT+CIFSR\r\n",1000,true); // get ip address
  delay(2000);
 // sendData("AT+CIPSTA?\r\n",1000,true); // get ip address
 // delay(1000);

 Serial.println("server Ready for taking request.....");
  lcd.print("server Ready for taking request.....");
}
 
void loop()
{


    

  
  if(esp8266.available()) // check if the esp is sending a message 
  {
     Serial.println("esp8266 data available");
     lcd.print("esp8266 data available");
     int connectionId = 0;
     int pinNumber= 0;
     if(esp8266.find("+IPD,"))
       {
        delay(2000); // wait for the serial buffer to fill up (read all the serial data)
        // get the connection id so that we can then disconnect
        connectionId = esp8266.read()-48; // subtract 48 because the read() function returns  // the ASCII decimal value and 0 (the first decimal number) starts at 48
        Serial.print("With data connectionId : "); Serial.println(connectionId);
        lcd.print("With data connectionId : ");
        lcd.print(connectionId);
        if(esp8266.find("pin="))
          { 
            delay(1000);
           // advance cursor to "pin="
           pinNumber = (esp8266.read()-48)*10; // get first number i.e. if the pin 13 then the 1st number is 1, then multiply to get 10
            delay(1000);
           pinNumber += (esp8266.read()-48); // get second number, i.e. if the pin number is 13 then the 2nd number is 3, then add to the first number
           Serial.print("pinNumber : "); Serial.println(pinNumber);

           switchLight(pinNumber);
       
           
          }
       }else{
        delay(2000);
        connectionId = esp8266.read()-48; 
        Serial.print("Without data connectionId : "); Serial.println(connectionId);
       }
     delay(1000); 


     // generate web page
     String webpage = String(pinNumber);
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend +=webpage.length();
     cipSend +="\r\n";
     sendData(cipSend,500,true);
     delay(200);
     sendData(webpage,500,true);

     

      Serial.println("----------------CIPCLOSE-------------------");
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId; // append connection id
     closeCommand+="\r\n";
     sendData(closeCommand,1000,true); // close connection
     delay(2000);
     Serial.println("----------------CIPCLOSE-------------------");


//String response = "";
//int connectionId = 0;
//  while(esp8266.available())
//      {
//        
//        // The esp has data so display its output to the serial window 
//        char c = esp8266.read(); // read the next character.
//        response+=c;
//      }  
//     Serial.println("----------------RESPONSE-------------------");
//     Serial.println(response);
//     Serial.println("----------------RESPONSE-------------------\n\n\n");



    
  }
}
 
/*
* Name: sendData
* Description: Function used to send data to ESP8266.
* Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
* Returns: The response from the esp8266 (if there is a reponse)
*/
String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266.print(command); // send the read character to the esp8266
    Serial.print(command);
    long int time = millis();
    
   // while( (time+timeout) > millis())

   unsigned long t=millis()+500; // give the esp 500 mS to send the entire string
   while( t > millis() ) //- See more at: http://www.esp8266.com/viewtopic.php?f=8&t=3111#sthash.8czkKvmv.dpuf
    {
      while(esp8266.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}


void switchLight(int pinNumber){
    switch (pinNumber) {
    case 10:
      digitalWrite(7,HIGH);
      break;
    case 11:
      digitalWrite(8,HIGH);
      break;
    case 12:
      digitalWrite(9,HIGH);
      break;
    case 13:
      digitalWrite(10,HIGH);
      break;
    case 14:
      digitalWrite(11,HIGH);
      break;
    case 15:
      digitalWrite(12,HIGH);
      break;
    case 16:
      digitalWrite(13,HIGH);
      break;
    case 99:
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      break;
    default: 
      
    break;
  }
   
  
}





