#include <SoftwareSerial.h>
#include <TFT_HX8357.h>


TFT_HX8357 tft = TFT_HX8357();       // Invoke custom library
#define TFT_GREY 0x5AEB // New colour

int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6;
int pin6 = 7;
int pin7 = 8;
int pin8 = 9;


int sw1 = 0;
int sw2 = 0;
int sw3 = 0;
int sw4 = 0;
int sw5 = 0;
int sw6 = 0;
int sw7 = 0;
int sw8 = 0;
int sw9 = 0;
int sw10 = 0;
int sw11= 0;
int sw12= 0;
int sw13= 0;
int sw14= 0;
int sw15= 0;
int sw16= 0;
int sw17= 0;
int sw18= 0;
int sw19= 0;
int sw20= 0;
int sw21= 0;
int sw22= 0;
int sw23= 0;
int sw24= 0;
int sw25= 0;
int sw26= 0;
int sw27= 0;
int sw28= 0;
int sw29= 0;
int sw30= 0;





// status of home


void setup()
{
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(0x0000);

  int w = tft.width();
  int h = tft.height();
  tft.fillRect(0,0,w,h,TFT_GREEN); 
  tft.fillRect(4,4,w-8,h-8,0x0000); 

   
  tft.fillRect(6,6,w/2,h-12,TFT_GREEN); 
  tft.fillRect(8,8,(w/2)-4,h-16,0x0000); 
  tft.drawLine(8,45,(w/2)+3,45,TFT_GREEN);
  tft.setCursor(12, 10, 2);
  tft.setTextSize(2);
  tft.setTextColor(0xFBE0,0x0000);
  tft.print("Light : ");
  tft.drawLine(8,90,(w/2)+3,90,TFT_GREEN);
  tft.drawLine(8,135,(w/2)+3,135,TFT_GREEN);
  tft.drawLine(8,180,(w/2)+3,180,TFT_GREEN);
  tft.drawLine(8,225,(w/2)+3,225,TFT_GREEN);
  tft.drawLine(8,270,(w/2)+3,270,TFT_GREEN);
  
  tft.fillRect((w/2)+8,6,(w/2)-14,h-12,TFT_GREEN); 
  tft.fillRect((w/2)+10,8,(w/2)-18,h-16,0x0000); 
  tft.setCursor(255, 10, 2);
  tft.setTextSize(1);
  tft.print("Room Temp ");
  tft.setCursor(280, 30, 2);
  tft.setTextSize(6);
  tft.print("32");
  tft.setCursor(375, 30, 2);
  tft.setTextSize(2);
  tft.print("o");
  tft.setCursor(405, 30, 2);
  tft.setTextSize(6);
  tft.print("C");
  tft.drawLine((w/2)+10,135,w-9,135,TFT_GREEN);
  tft.drawLine((w/2)+10,180,w-9,180,TFT_GREEN);
  tft.drawLine((w/2)+10,225,w-9,225,TFT_GREEN);
  tft.drawLine((w/2)+10,270,w-9,270,TFT_GREEN);
  tft.drawCircle(10, 10, 10, TFT_GREEN);

 pinMode(pin1,OUTPUT);
 pinMode(pin2,OUTPUT);
 pinMode(pin3,OUTPUT);
 pinMode(pin4,OUTPUT);
 pinMode(pin5,OUTPUT);
 pinMode(pin6,OUTPUT);
 pinMode(pin7,OUTPUT);
 pinMode(pin8,OUTPUT);

 digitalWrite(pin1,HIGH);
 digitalWrite(pin2,HIGH);
 digitalWrite(pin3,HIGH);
 digitalWrite(pin4,HIGH);
 digitalWrite(pin5,HIGH);
 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,HIGH);
 digitalWrite(pin8,HIGH);
  
  Serial.begin(115200);
  Serial1.begin(9600);
  //nodeMCU.begin(115200); // your esp's baud rate might be different
  //Serial.println("Arduino Ready for taking request.....");
}
 
void loop()
{

 String responseToNodeMCU = "";
  
  tft.setCursor(2, 2, 2);
  tft.setTextSize(2);
  //tft.setTextColor(0xFBE0,0xBDF7); 
  
  
  if(Serial.available()) // check if the esp is sending a message 
  {
     Serial.println("--");
     String response = "";
     while(Serial.available()){
        response = Serial.readString(); // read the next character.
      }  
     tft.println(response);
     Serial.println(response);
     if(response == "1ON"){
        digitalWrite(pin1,LOW);
        sw1 = 1;
//        responseToNodeMCU = response;
     }

     if(response == "1OFF"){
        digitalWrite(pin1,HIGH);
        sw1 = 0;
     }

     if(response == "2ON"){
        digitalWrite(pin2,LOW);
        sw2 = 1;
     }

     if(response == "2OFF"){
        digitalWrite(pin2,HIGH);
        sw2 = 0;
     }

     if(response == "3ON"){
        digitalWrite(pin3,LOW);
        sw3 = 1;
     }

     if(response == "3OFF"){
        digitalWrite(pin3,HIGH);
        sw3 = 0;
     }

    if(response == "4ON"){
        digitalWrite(pin4,LOW);
        sw4 = 1;
     }

     if(response == "4OFF"){
        digitalWrite(pin4,HIGH);
        sw4 = 0;
     }

     if(response == "5ON"){
        digitalWrite(pin5,LOW);
        sw5 = 1;
     }

     if(response == "5OFF"){
        digitalWrite(pin5,HIGH);
        sw5 = 0;
     }

     if(response == "6ON"){
        digitalWrite(pin6,LOW);
        sw6 = 1;
     }

     if(response == "6OFF"){
        digitalWrite(pin6,HIGH);
        sw6 = 0;
     }

     if(response == "7ON"){
        digitalWrite(pin7,LOW);
        sw7 = 1;
     }

     if(response == "7OFF"){
        digitalWrite(pin7,HIGH);
        sw7 = 0;
     }
     if(response == "8ON"){
        digitalWrite(pin8,LOW);
        sw8 = 1;
     }

     if(response == "8OFF"){
        digitalWrite(pin8,HIGH);
        sw8 = 0;
     }

     if(response == "ALLOFF"){
        digitalWrite(pin1,HIGH);
        sw1 = 0;
        digitalWrite(pin2,HIGH);
        sw2 = 0;
        digitalWrite(pin3,HIGH);
        sw3 = 0;
        digitalWrite(pin4,HIGH);
        sw4 = 0;
        digitalWrite(pin5,HIGH);
        sw5 = 0;
        digitalWrite(pin6,HIGH);
        sw6 = 0;
        digitalWrite(pin7,HIGH);
        sw7 = 0;
        digitalWrite(pin8,HIGH);
        sw8 = 0;
     }

  responseToNodeMCU = responseToNodeMCU+"{";
  responseToNodeMCU = responseToNodeMCU+"\"S1\":"+"\""+sw1+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S2\":"+"\""+sw2+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S3\":"+"\""+sw3+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S4\":"+"\""+sw4+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S5\":"+"\""+sw5+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S6\":"+"\""+sw6+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S7\":"+"\""+sw7+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S8\":"+"\""+sw8+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S9\":"+"\""+sw9+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S10\":"+"\""+sw10+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S11\":"+"\""+sw11+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S12\":"+"\""+sw12+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S13\":"+"\""+sw13+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S14\":"+"\""+sw14+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S15\":"+"\""+sw15+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S16\":"+"\""+sw16+"\",";
  responseToNodeMCU = responseToNodeMCU+"\"S17\":"+"\""+sw17+"\"";
  responseToNodeMCU = responseToNodeMCU+"}";
  
  Serial.print(responseToNodeMCU);
  Serial1.print(responseToNodeMCU);
     
  }
  
  
}


//void ptintText(int x, int y, int p, String text,color565  color){
  
//}








