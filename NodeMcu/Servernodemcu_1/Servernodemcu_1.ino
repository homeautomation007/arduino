#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "SINGTEL-C107";
const char* password = "0016761095";

ESP8266WebServer server(80);

int sw1 = 0;
int sw2 = 1;
int sw3 = 0;
int sw4 = 1;
int sw5 = 0;
int sw6 = 0;
int sw7 = 1;
int sw8 = 0;
int sw9 = 1;

void setup(void){
  
  Serial.begin(115200);   // send message to nodeMCU
  
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

  Serial.println("1-----------");

  String responseToNodeMCU = responseToNodeMCU+"{";
  responseToNodeMCU = responseToNodeMCU+"\"S1\":"+"\""+sw1+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S2\":"+"\""+sw2+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S3\":"+"\""+sw3+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S4\":"+"\""+sw4+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S5\":"+"\""+sw5+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S6\":"+"\""+sw6+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S7\":"+"\""+sw7+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S8\":"+"\""+sw8+"\"";
  responseToNodeMCU = responseToNodeMCU+"}";
  Serial.println("2-----------");
     server.send(200, "text/html", responseToNodeMCU);
  Serial.println("3-----------");
     
}


void loop(void){
  server.handleClient();
}





