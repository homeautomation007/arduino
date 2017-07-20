#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SoftwareSerial.h>

//const char* ssid = "Nagaraju's iPhone";
//const char* password = "asdfghjkl";

//const char* ssid = "MSI-ABT";
//const char* password = "H@mp$h1ReABT206!";

const char* ssid = "SINGTEL-C107";
const char* password = "0016761095";

SoftwareSerial espSerial(12,14); // make RX Arduino line is pin 12, make TX Arduino line is pin 14.




ESP8266WebServer server(80);

void setup(void){
  
  Serial.begin(115200);   // send message to nodeMCU
  espSerial.begin(9600);    // read messages from nodeMCU
  
  WiFi.begin(ssid, password);
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
     Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
  
}






void handleRoot() {
 // digitalWrite(led, HIGH);  // can use for server response LED
 String msg = "";
  server.send(200, "text/html", msg);
 // Serial.println(server.args());
  // digitalWrite(led, LOW);
}

void handleNotFound(){
 // String message = "";
 // message += "URI: ";
 // message += server.uri();
 // message += "\nMethod: ";
 // message += (server.method() == HTTP_GET)?"GET":"POST";
 // message += "\nArguments: ";
 // message += server.args();
 // message += "\n";
 
  String arduinoResponse = "";
  String nodeMCUResponse = "";
  String pinno = server.arg("pinno");
  String value = server.arg("value"); 
  
  
 // for (uint8_t i=0; i<server.args(); i++){
    // message += " " + server.argName(i) + ": " + server.arg(i) + "\n";

      if(pinno == "pin1" && value == "ON"){
         nodeMCUResponse = "1ON";
      }
      if(pinno== "pin1" && value == "OFF"){
         nodeMCUResponse = "1OFF";
      }

      if(pinno == "pin2" && value == "ON"){
         nodeMCUResponse = "2ON";
      }
      if(pinno== "pin2" && value == "OFF"){
         nodeMCUResponse = "2OFF";
      }

      if(pinno == "pin3" && value == "ON"){
         nodeMCUResponse = "3ON";
      }
      if(pinno== "pin3" && value == "OFF"){
         nodeMCUResponse = "3OFF";
      }

      if(pinno == "pin4" && value == "ON"){
         nodeMCUResponse = "4ON";
      }
      if(pinno== "pin4" && value == "OFF"){
         nodeMCUResponse = "4OFF";
      }

      if(pinno == "pin5" && value == "ON"){
         nodeMCUResponse = "5ON";
      }
      if(pinno== "pin5" && value == "OFF"){
         nodeMCUResponse = "5OFF";
      }
      if(pinno == "pin6" && value == "ON"){
         nodeMCUResponse = "6ON";
      }
      if(pinno== "pin6" && value == "OFF"){
         nodeMCUResponse = "6OFF";
      }

      if(pinno == "pin7" && value == "ON"){
         nodeMCUResponse = "7ON";
      }
      if(pinno== "pin7" && value == "OFF"){
         nodeMCUResponse = "7OFF";
      }

      if(pinno == "pin8" && value == "ON"){
         nodeMCUResponse = "8ON";
      }
      if(pinno== "pin8" && value == "OFF"){
         nodeMCUResponse = "8OFF";
      }

      if(pinno== "pin99" && value == "OFF"){
         nodeMCUResponse = "ALLOFF";
      }

      Serial.print(nodeMCUResponse);
      delay(400);
      // reading responce from
      while(espSerial.available()){
        arduinoResponse = espSerial.readString(); // read the next character.
      }  
      
 // }
  Serial.println("------------------------");
  Serial.println(arduinoResponse);
  server.send(200, "text/html", arduinoResponse);
}


void loop(void){
  server.handleClient();
}





