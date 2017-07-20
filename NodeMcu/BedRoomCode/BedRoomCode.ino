#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "Aashritha 2.4GHz";
const char* password = "04112014AA";

ESP8266WebServer server(80);
 int pin1 = 5;
 int pin2 = 4;
 int sw1 = 0;
 int sw2 = 0;

void setup(void){

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  Serial.begin(9600);   // send message to nodeMCU
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
  String msg = "";
  server.send(200, "text/html", msg);
}

void handleNotFound(){

  String responseToNodeMCU = "";
  String pinno = server.arg("pinno");
  String value = server.arg("value"); 
  
  
 // for (uint8_t i=0; i<server.args(); i++){
    // message += " " + server.argName(i) + ": " + server.arg(i) + "\n";

      if(pinno == "pin1" && value == "ON"){
         digitalWrite(pin1,HIGH);
         sw1 = 1;
      }
      if(pinno== "pin1" && value == "OFF"){
         digitalWrite(pin1,LOW);
         sw1 = 0;
      }

      if(pinno == "pin2" && value == "ON"){
         digitalWrite(pin2,HIGH);
         sw2 = 1;
      }
      if(pinno== "pin2" && value == "OFF"){
         digitalWrite(pin2,LOW);
         sw2 = 0;
      }


  responseToNodeMCU = responseToNodeMCU+"{";
  responseToNodeMCU = responseToNodeMCU+"\"S1\":"+"\""+sw1+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S2\":"+"\""+sw2+"\"";
  responseToNodeMCU = responseToNodeMCU+"}";
  
      
 // }
  server.send(200, "text/html", responseToNodeMCU);
}


void loop(void){
  server.handleClient();
}





